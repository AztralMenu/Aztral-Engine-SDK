#pragma once
#include "stdafx.h"

// Thanks to till0sch for the syntax
extern "C" void DoASM();


// assembler opcode defines for inline asm
#define ASM_OPCODE_JMP_REL		0xEB
#define ASM_OPCODE_NOP			0x90
// size of the full assembler instruction in bytes
#define ASM_INSTR_SIZE_JMP_REL	0x2
#define ASM_INSTR_SIZE_PUSH		0x1
#define ASM_INSTR_SIZE_NOP		0x1
// length of your pattern in bytes
#define MARKER_SIZE 14
// the pattern of the marker and its mask
#define MARKER_BYTES "\x9C\x60\x33\xC0\x33\xC0\x33\xDB\x33\xC0\x33\xC0\x61\x9D"
// I know the mask is pretty useless in this case but I like to use a generic findPattern method which can handle every mask
#define MARKER_MASK "xxxxxxxxxxxxxx"

class Detour
{
	public:

	static byte FindPattern(byte *startAddress, unsigned long bytes, byte* pattern, const char* mask, size_t size)
	{
		//FindPattern((byte*)modInfo.lpBaseOfDll + dwMatchOffset, modInfo.SizeOfImage - dwMatchOffset, (byte*)MARKER_BYTES, MARKER_MASK, MARKER_SIZE);
		//FindPattern("\x4C\x8D\x05\x00\x00\x00\x00\x4D\x8B\x08\x4D\x85\xC9\x74\x11", "xxx????xxxxxxxx", reinterpret_cast<const char *>(module.lpBaseOfDll), module.SizeOfImage);
		const byte* address_end = startAddress + size;
		const auto mask_length = static_cast<size_t>(strlen(mask) - 1);

		for (size_t i = 0; startAddress < address_end; startAddress++)
		{
			if (*startAddress == pattern[i] || mask[i] == '?')
			{
				if (mask[i + 1] == '\0')
				{
					return reinterpret_cast<byte>(startAddress) - mask_length;
				}

				i++;
			}
			else
			{
				i = 0;
			}
		}

		return 0;
	}

	static void morphModule()
	{
		// all the vars we need for the GetModuleInformation call
		MODULEINFO modInfo;
		HANDLE hProcess = GetCurrentProcess();
		HMODULE hModule = GetModuleHandleA(NULL);

		if (GetModuleInformation(hProcess, hModule, &modInfo, sizeof(MODULEINFO)))
		{
			// you can log the base of your module here by using modInfo.lpBaseOfDll
			// you can also log the size of your module by using modInfo.SizeOfImage

			if (modInfo.SizeOfImage < MAXDWORD)
			{
				// where the pattern was found last
				byte* pbyLastMatch;
				// the offset from the module base to pbyLastMatch -> used as: module size - dwMatchOffset = range of bytes we still need to scan
				DWORD dwMatchOffset = 0;
				// are we done yet?
				bool bMorphingFinished = false;
				// good to know how many regions we morphed in total
				DWORD dwRegionCount = 0;

				while (!bMorphingFinished)
				{
					// search for the marker we will place in our code later on
					using namespace Memory;
					pbyLastMatch = (byte*)FindPattern((byte*)modInfo.lpBaseOfDll + dwMatchOffset, modInfo.SizeOfImage - dwMatchOffset, (byte*)MARKER_BYTES, MARKER_MASK, MARKER_SIZE);

					// if marker found
					if (pbyLastMatch != NULL)
					{
						// call morphMemory which generates the junk code and writes it to memory
						morphMemory(pbyLastMatch, MARKER_SIZE);
						dwRegionCount++;

						// this should be redundant if you think about it, better save than sorry though
						pbyLastMatch++;
						dwMatchOffset = (DWORD)pbyLastMatch - (DWORD)modInfo.lpBaseOfDll;
					}
					// if we found all markers
					else
					{
						bMorphingFinished = true;
						// here you can log how many regions got morphed by using dwRegionCount
					}
				}
			}
		}
		// log unable to obtain module information

		// clean up
		CloseHandle(hProcess);
	}

	static void morphMemory(byte* pbyDst, byte byLength)
	{
		/*
		what kind of junk code this algorythm can produce (rdm = random opcode, jmp = jump past junk code)
		jmp		or		0x90
		rdm				jmp
		rdm				rdm
		rdm				rdm
		*/

		// nullptr checking would be a good idea at this point
		// init random number generator only once
		static bool bSetSeed = true;
		if (bSetSeed)
		{
			srand((UINT)time(NULL));
			bSetSeed = false;
		}

		// get a place for our brand new random opcodes
		byte* morphedOpcodes = new byte[byLength];
		byte byOpcodeIt = 0;

		// first calculate if we wanna place a 0x90 at the beginning or not
		bool bPlaceNop = (rand() % 2) ? true : false;
		if (bPlaceNop)
		{
			morphedOpcodes[byOpcodeIt] = ASM_OPCODE_NOP;
			byOpcodeIt++;
		}

		// now place the jmp instruction
		morphedOpcodes[byOpcodeIt] = ASM_OPCODE_JMP_REL;
		byOpcodeIt++;

		// adjust the relative jmp based on wether we placed a nop before or not
		// keep in mind: we only want to jump past the junk code not any further
		morphedOpcodes[byOpcodeIt] = byLength - ASM_INSTR_SIZE_JMP_REL - ((bPlaceNop) ? ASM_INSTR_SIZE_NOP : 0);
		byOpcodeIt++;

		// now fill the rest with random opcodes
		for (; byOpcodeIt < byLength; byOpcodeIt++)
			morphedOpcodes[byOpcodeIt] = rand() % MAXBYTE; // 0xFF

		// write the new opcodes to memory
		DWORD dwOldProtect;
		VirtualProtect(pbyDst, byLength, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		memcpy(pbyDst, morphedOpcodes, byLength);
		VirtualProtect(pbyDst, byLength, dwOldProtect, &dwOldProtect);

		// free the used memory again
		delete morphedOpcodes;
	}
};