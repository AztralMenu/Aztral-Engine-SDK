.CODE
DoASM PROC					  
	pushfq	  
	pushcontext all	  
	xor eax, eax
	xor eax, eax
	xor ebx, ebx
	xor eax, eax
	xor eax, eax
	popcontext all		  
	popfq
	ret
DoASM ENDP
end