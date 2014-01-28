	.arch armv5te
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"goto.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"The sum of 100 is %d\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	.fnstart
.LFB0:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	.save {fp, lr}
	.setfp fp, sp, #4
	add	fp, sp, #4
	.pad #8
	sub	sp, sp, #8
	mov	r3, #1
	str	r3, [fp, #-8]
	mov	r3, #0
	str	r3, [fp, #-12]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #100
	bgt	.L3
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-8]
	add	r3, r2, r3
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
	b	.L2
.L3:
	ldr	r3, .L4
	mov	r0, r3
	ldr	r1, [fp, #-12]
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.L5:
	.align	2
.L4:
	.word	.LC0
	.fnend
	.size	main, .-main
	.ident	"GCC: (Sourcery G++ Lite 2010.09-50) 4.5.1"
	.section	.note.GNU-stack,"",%progbits
