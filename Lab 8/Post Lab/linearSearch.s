	;; linearSearch.s
	;; creates a linear search of an array to find index of item if it exists in the array.

	global linearSearch

	section .text

linearSearch:
	xor	rax,rax		;zero out return register
	xor	r10,r10		;zero out counter i
	xor	r8,r8			;zero out my r8 container
start:
	cmp	r10,rsi		;compare the counter and the size
	je	non_exist	; if equal, return -1 
	add	r8,[rdi+4*r10]	; add the value to r8
	cmp	r8d, edx	;compare the values, use e8 and edx
	je	found_it	; return index
	inc	r10		; increment my counter
	xor	r8,r8
	jmp	start		; jump back to start
non_exist:
	mov	rax,-1
	ret
found_it:
	mov	rax,r10
	ret
	
