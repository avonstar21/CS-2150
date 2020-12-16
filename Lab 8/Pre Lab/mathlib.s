	;; mathlib.s
	;;
	;; Purpose: this file creates 2 subroutines that first return the product and then the exponential result.
	;;
	global product

	section .text

product:
	;; add the number to itself until the counter is 0.
	;; variables are kept in registers

	;; subroutine body:
	xor	rax, rax 	; zero out the the return register
	xor	r10, r10	; zero out the counter
start:
	cmp	r10, rsi	; does i == n
	je	done		; if yes, end the loop
	add	rax, rdi	;add the current value but idk what that is
	inc	r10		; increment the counter
	jmp	start 		; jump to the beginning of the loop
done:
	;; since return value is already in rax, we can just return
	ret	
	;; new function

	global power

	section .text
power:
start_pow:
	cmp	rsi, 0
	je	base_case
	jmp 	recurse_case
recurse_case:
	push	rdi
	;mov	rax,rdi
	;push	rsi
	sub	rsi,1
	push	rsi
	;move	rsi,rdi
	call	power
	;pop	rsi
	pop	rsi
	mov	rcx,rdi
	pop	rdi
	call	product 
	
base_case:
	mov	rax,rdi
	ret
