; Declare needed C  functions
	extern	printf		; the C function that need to be called

	section .data		; the variables to be initiliazed
msg:	db "Hello, Holberton", 0; the string that are set to 0
fmt:	db "%s", 10, 0		; print in a new line

	section .text		; sectionof the code

	global main		; adheres to gcc std
main:				; entry point
	push	rbp		; align with set stack frame

	mov	rdi,fmt
	mov	rsi,msg
	mov	rax,0		; adhere to rax xor and/or rax
	call	printf		; Call C function

	pop	rbp		; restore stack

	mov	rax,0		; normal, no error, return value
	ret			; return
