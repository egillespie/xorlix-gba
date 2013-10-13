@ Waits until the specified horizontal sync occurs
@ Pass 160 as a parameter to wait for a vertical sync
@ void WaitForSync(void)

	.ARM
	.ALIGN
	.GLOBL	WaitForSync
	.TYPE	WaitForSync,function

WaitForSync:
	stmfd	sp!, {r1-r2}
	mov	r2, #0x4000000

nsync_wait:
	ldrh	r1, [r2, #6]
	cmp	r0, r1
	bne	nsync_wait

	ldmfd	sp!, {r1-r2}
	bx	lr
