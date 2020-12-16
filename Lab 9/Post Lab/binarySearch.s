	;; binarySearch.s
	;;  uses binary search to find target in the item in the array and return the index

	global binarySearch

	section .text

binarySearch:
	xor	 r8,r8
	xor	 r9,r9
	cmp	 rsi,rdx
	jle	 case_comp
	jg 	 case_end
case_comp:
	add	r8,rsi
	add	r8,rdx
	shr	r8,1
	mov	r9, [rdi+4*r8]
	cmp	ecx,r9d 
	je	case_equal
	jg	case_greater
	jl	case_lesser
case_greater:	
	mov	rsi, r8
	inc	rsi
	jmp	binarySearch
case_lesser:	
	mov	rdx, r8
	sub	rdx, 1
	jmp	binarySearch
case_equal:	
	mov	rax,r8
	ret
case_end:
	mov	rax,-1
	ret
