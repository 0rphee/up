	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	__Z7Mostrarv                    ; -- Begin function _Z7Mostrarv
	.p2align	2
__Z7Mostrarv:                           ; @_Z7Mostrarv
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	wzr, [sp, #12]
	str	wzr, [sp, #8]
	b	LBB0_1
LBB0_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB0_3 Depth 2
	ldr	w8, [sp, #8]
	subs	w8, w8, #10
	cset	w8, ge
	tbnz	w8, #0, LBB0_8
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	str	wzr, [sp, #4]
	b	LBB0_3
LBB0_3:                                 ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	w8, [sp, #4]
	subs	w8, w8, #10
	cset	w8, ge
	tbnz	w8, #0, LBB0_6
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_3 Depth=2
	adrp	x8, _arr@PAGE
	ldr	x8, [x8, _arr@PAGEOFF]
	ldrsw	x9, [sp, #8]
	ldr	x8, [x8, x9, lsl #3]
	ldrsw	x9, [sp, #4]
	ldr	w9, [x8, x9, lsl #2]
	ldr	w8, [sp, #12]
	add	w8, w8, w9
	str	w8, [sp, #12]
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB0_3
LBB0_6:                                 ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB0_1
LBB0_8:
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__Z8Mostrar2v                   ; -- Begin function _Z8Mostrar2v
	.p2align	2
__Z8Mostrar2v:                          ; @_Z8Mostrar2v
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	wzr, [sp, #12]
	str	wzr, [sp, #8]
	b	LBB1_1
LBB1_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB1_3 Depth 2
	ldr	w8, [sp, #8]
	subs	w8, w8, #10
	cset	w8, ge
	tbnz	w8, #0, LBB1_8
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	str	wzr, [sp, #4]
	b	LBB1_3
LBB1_3:                                 ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	w8, [sp, #4]
	subs	w8, w8, #10
	cset	w8, ge
	tbnz	w8, #0, LBB1_6
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_3 Depth=2
	adrp	x8, _arr@PAGE
	ldr	x8, [x8, _arr@PAGEOFF]
	ldrsw	x9, [sp, #8]
	ldr	x8, [x8, x9, lsl #3]
	ldrsw	x9, [sp, #4]
	ldr	w9, [x8, x9, lsl #2]
	ldr	w8, [sp, #12]
	mul	w8, w8, w9
	str	w8, [sp, #12]
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_3 Depth=2
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB1_3
LBB1_6:                                 ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_7
LBB1_7:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB1_1
LBB1_8:
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	mov	x0, #80
	bl	__Znam
	adrp	x8, _arr@PAGE
	str	x0, [x8, _arr@PAGEOFF]
	str	wzr, [sp, #8]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #8]
	subs	w8, w8, #10
	cset	w8, ge
	tbnz	w8, #0, LBB2_4
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	mov	x0, #40
	bl	__Znam
	adrp	x8, _arr@PAGE
	ldr	x8, [x8, _arr@PAGEOFF]
	ldrsw	x9, [sp, #8]
	str	x0, [x8, x9, lsl #3]
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB2_1
LBB2_4:
	str	wzr, [sp, #4]
	b	LBB2_5
LBB2_5:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB2_7 Depth 2
	ldr	w8, [sp, #4]
	subs	w8, w8, #10
	cset	w8, ge
	tbnz	w8, #0, LBB2_12
	b	LBB2_6
LBB2_6:                                 ;   in Loop: Header=BB2_5 Depth=1
	str	wzr, [sp]
	b	LBB2_7
LBB2_7:                                 ;   Parent Loop BB2_5 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	w8, [sp]
	subs	w8, w8, #10
	cset	w8, ge
	tbnz	w8, #0, LBB2_10
	b	LBB2_8
LBB2_8:                                 ;   in Loop: Header=BB2_7 Depth=2
	ldr	w8, [sp, #4]
	ldr	w9, [sp]
	add	w8, w8, w9
	adrp	x9, _arr@PAGE
	ldr	x9, [x9, _arr@PAGEOFF]
	ldrsw	x10, [sp, #4]
	ldr	x9, [x9, x10, lsl #3]
	ldrsw	x10, [sp]
	str	w8, [x9, x10, lsl #2]
	b	LBB2_9
LBB2_9:                                 ;   in Loop: Header=BB2_7 Depth=2
	ldr	w8, [sp]
	add	w8, w8, #1
	str	w8, [sp]
	b	LBB2_7
LBB2_10:                                ;   in Loop: Header=BB2_5 Depth=1
	b	LBB2_11
LBB2_11:                                ;   in Loop: Header=BB2_5 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB2_5
LBB2_12:
	bl	__Z7Mostrarv
	bl	__Z8Mostrar2v
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_arr                            ; @arr
.zerofill __DATA,__common,_arr,8,3
.subsections_via_symbols
