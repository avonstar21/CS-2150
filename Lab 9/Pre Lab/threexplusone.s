	;; threexplusone.s

	global threexplusone
	section .text

threexplusone:
	xor	r8,r8
	cmp	rdi,1
	je	case_one
	test	rdi,1		;more efficient than idiv
	mov	rax,rdi
	jz	case_even
	jnz	case_odd	;
case_one:
	mov	rax,0
	ret
case_even:
	push	r8
	shr	rdi,1		;optimizes better than division
	mov	rax,rdi
	call	threexplusone	;sigsegv invalid address 
	pop	r8
	mov	r8,rax
	inc	r8
	mov	rax,r8
	ret
case_odd:
	push	r8
	lea	rdi,[3*rdi+1]	;using lea instead of imul to reduce #of ops
	mov	rax, rdi
	call	threexplusone	;sigsegv invalid address
	pop	r8
	mov	r8, rax
	inc	r8
	mov	rax, r8
	ret
	
