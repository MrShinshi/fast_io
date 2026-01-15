	.def	"@feat.00";
	.scl	3;
	.type	0;
	.endef
	.globl	"@feat.00"
"@feat.00" = 0
	.file	"erase_fast_io.cc"
	.def	_Z9erase_u16RN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorItLb0EEES9_;
	.scl	2;
	.type	32;
	.endef
	.text
	.globl	_Z9erase_u16RN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorItLb0EEES9_ // -- Begin function _Z9erase_u16RN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorItLb0EEES9_
	.p2align	2
_Z9erase_u16RN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorItLb0EEES9_: // @_Z9erase_u16RN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorItLb0EEES9_
.seh_proc _Z9erase_u16RN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorItLb0EEES9_
// %bb.0:
	sub	sp, sp, #112
	.seh_stackalloc	112
	str	x30, [sp, #96]                  // 8-byte Spill
	.seh_save_reg	x30, 96
	.seh_endprologue
	ldr	x8, [x1, #16]
	ldr	q0, [x1]
	add	x1, sp, #64
	ldr	q1, [x2]
	ldr	x9, [x2, #16]
	add	x2, sp, #32
	str	x8, [sp, #80]
	add	x8, sp, #8
	str	q0, [sp, #64]
	str	q1, [sp, #32]
	str	x9, [sp, #48]
	bl	_ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_
	.seh_startepilogue
	ldr	x30, [sp, #96]                  // 8-byte Reload
	.seh_save_reg	x30, 96
	add	sp, sp, #112
	.seh_stackalloc	112
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_,"xr",discard,_ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_
	.globl	_ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_ // -- Begin function _ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_
	.p2align	2
_ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_: // @_ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_
.seh_proc _ZN7fast_io10containers5dequeItNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorItLb1EEES8_
// %bb.0:
	sub	sp, sp, #160
	.seh_stackalloc	160
	stp	x19, x20, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x19, 64
	stp	x21, x22, [sp, #80]             // 16-byte Folded Spill
	.seh_save_regp	x21, 80
	stp	x23, x24, [sp, #96]             // 16-byte Folded Spill
	.seh_save_regp	x23, 96
	stp	x25, x26, [sp, #112]            // 16-byte Folded Spill
	.seh_save_regp	x25, 112
	stp	x27, x28, [sp, #128]            // 16-byte Folded Spill
	.seh_save_regp	x27, 128
	str	x30, [sp, #144]                 // 8-byte Spill
	.seh_save_reg	x30, 144
	.seh_endprologue
	ldp	x27, x16, [x0, #32]
	ldr	x17, [x1, #16]
	ldp	x10, x15, [x0, #48]
	ldr	x24, [x2, #8]
	ldp	x3, x21, [x1]
	mov	x9, x16
	mov	x11, x27
	cmp	x16, x15
	str	x10, [sp, #32]                  // 8-byte Spill
	b.eq	.LBB1_40
.LBB1_1:
	cmp	x21, x24
	b.eq	.LBB1_15
// %bb.2:
	ldp	x12, x4, [x0]
	sub	x13, x21, x3
	ldr	x26, [x2, #16]
	ldr	x23, [x2]
	sub	x9, x9, x11
	ldr	x2, [x0, #16]
	stp	x0, x8, [sp, #16]               // 16-byte Folded Spill
	sub	x12, x12, x4
	sub	x10, x10, x26
	sub	x14, x23, x24
	asr	x12, x12, #1
	lsl	x10, x10, #8
	add	x12, x12, x13, asr #1
	add	x10, x10, x14, asr #1
	sub	x13, x17, x2
	add	x11, x12, x13, lsl #8
	add	x9, x10, x9, asr #1
	cmp	x11, x9
	b.hs	.LBB1_16
// %bb.3:
	cmp	x4, x21
	mov	x19, x24
	mov	x9, x26
	str	x23, [sp, #8]                   // 8-byte Spill
	b.eq	.LBB1_32
// %bb.4:
	ldr	x23, [sp, #8]                   // 8-byte Reload
	mov	x19, x24
	str	x16, [sp]                       // 8-byte Spill
	str	x26, [sp, #152]                 // 8-byte Spill
	stp	x4, x2, [sp, #40]               // 16-byte Folded Spill
	b	.LBB1_8
.LBB1_5:                                //   in Loop: Header=BB1_8 Depth=1
	ldp	x2, x17, [sp, #48]              // 16-byte Folded Reload
	add	x19, x19, x22
	cmp	x2, x17
	b.eq	.LBB1_31
// %bb.6:                               //   in Loop: Header=BB1_8 Depth=1
	ldr	x4, [sp, #40]                   // 8-byte Reload
	add	x26, x26, #8
.LBB1_7:                                //   in Loop: Header=BB1_8 Depth=1
	ldr	x3, [x17, #-8]!
	add	x21, x3, #1, lsl #12            // =4096
.LBB1_8:                                // =>This Loop Header: Depth=1
                                        //     Child Loop BB1_10 Depth 2
	cmp	x2, x17
	sub	x26, x26, #8
	str	x17, [sp, #56]                  // 8-byte Spill
	csel	x20, x4, x3, eq
	sub	x28, x21, x20
	sub	x25, x19, x23
	cmp	x28, x25
	csel	x2, x28, x25, lo
	neg	x22, x2
	cbz	x2, .LBB1_10
.LBB1_9:                                //   in Loop: Header=BB1_8 Depth=1
	add	x0, x19, x22
	add	x1, x21, x22
	bl	memmove
.LBB1_10:                               //   Parent Loop BB1_8 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	cmp	x28, x25
	b.ls	.LBB1_12
// %bb.11:                              //   in Loop: Header=BB1_10 Depth=2
	ldr	x23, [x26], #-8
	add	x21, x21, x22
	add	x19, x23, #1, lsl #12           // =4096
	sub	x28, x21, x20
	sub	x25, x19, x23
	cmp	x28, x25
	csel	x2, x28, x25, lo
	neg	x22, x2
	cbnz	x2, .LBB1_9
	b	.LBB1_10
.LBB1_12:                               //   in Loop: Header=BB1_8 Depth=1
	b.ne	.LBB1_5
// %bb.13:                              //   in Loop: Header=BB1_8 Depth=1
	ldp	x2, x17, [sp, #48]              // 16-byte Folded Reload
	ldr	x4, [sp, #40]                   // 8-byte Reload
	cmp	x2, x17
	b.eq	.LBB1_30
// %bb.14:                              //   in Loop: Header=BB1_8 Depth=1
	ldr	x23, [x26]
	add	x19, x23, #1, lsl #12           // =4096
	b	.LBB1_7
.LBB1_15:
	mov	x11, x3
	mov	x24, x21
	mov	x26, x17
	b	.LBB1_39
.LBB1_16:
	cmp	x16, x15
	b.eq	.LBB1_42
// %bb.17:
	ldr	x19, [sp, #32]                  // 8-byte Reload
.LBB1_18:
	cmp	x24, x16
	b.eq	.LBB1_29
// %bb.19:
	mov	x9, x17
	mov	x22, x21
	mov	x27, x3
	stp	x3, x17, [sp, #48]              // 16-byte Folded Spill
	str	x19, [sp, #40]                  // 8-byte Spill
.LBB1_20:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB1_22 Depth 2
	add	x8, x23, #1, lsl #12            // =4096
	cmp	x26, x19
	str	x26, [sp, #152]                 // 8-byte Spill
	mov	x25, x16
	csel	x26, x16, x8, eq
	add	x9, x9, #8
	sub	x8, x27, x22
	sub	x20, x26, x24
	add	x28, x8, #1, lsl #12            // =4096
	cmp	x20, x28
	csel	x23, x20, x28, lo
	cbz	x23, .LBB1_22
.LBB1_21:                               //   in Loop: Header=BB1_20 Depth=1
	mov	x0, x22
	mov	x1, x24
	mov	x2, x23
	mov	x19, x9
	bl	memmove
	mov	x9, x19
.LBB1_22:                               //   Parent Loop BB1_20 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	cmp	x20, x28
	b.ls	.LBB1_24
// %bb.23:                              //   in Loop: Header=BB1_22 Depth=2
	ldr	x22, [x9], #8
	add	x24, x24, x23
	mov	x27, x22
	sub	x8, x22, x22
	sub	x20, x26, x24
	add	x28, x8, #1, lsl #12            // =4096
	cmp	x20, x28
	csel	x23, x20, x28, lo
	cbnz	x23, .LBB1_21
	b	.LBB1_22
.LBB1_24:                               //   in Loop: Header=BB1_20 Depth=1
	cmp	x20, x28
	b.hs	.LBB1_26
// %bb.25:                              //   in Loop: Header=BB1_20 Depth=1
	sub	x9, x9, #8
	add	x22, x22, x20
	ldr	x26, [sp, #152]                 // 8-byte Reload
	ldr	x19, [sp, #40]                  // 8-byte Reload
	mov	x16, x25
	cmp	x26, x19
	b.ne	.LBB1_27
	b	.LBB1_28
.LBB1_26:                               //   in Loop: Header=BB1_20 Depth=1
	ldr	x27, [x9]
	mov	x22, x27
	ldr	x26, [sp, #152]                 // 8-byte Reload
	ldr	x19, [sp, #40]                  // 8-byte Reload
	mov	x16, x25
	cmp	x26, x19
	b.eq	.LBB1_28
.LBB1_27:                               //   in Loop: Header=BB1_20 Depth=1
	ldr	x24, [x26, #8]!
	mov	x23, x24
	b	.LBB1_20
.LBB1_28:
	ldr	x25, [sp, #16]                  // 8-byte Reload
	ldp	x11, x26, [sp, #48]             // 16-byte Folded Reload
	str	x9, [sp, #32]                   // 8-byte Spill
	mov	x24, x21
	mov	x16, x22
	ldr	x9, [x25, #16]
	b	.LBB1_33
.LBB1_29:
	ldr	x25, [sp, #16]                  // 8-byte Reload
	mov	x9, x2
	mov	x11, x3
	mov	x24, x21
	mov	x26, x17
	str	x17, [sp, #32]                  // 8-byte Spill
	mov	x16, x21
	mov	x27, x3
	b	.LBB1_33
.LBB1_30:
	mov	x19, x23
.LBB1_31:
	add	x9, x26, #8
	ldr	x16, [sp]                       // 8-byte Reload
	ldr	x26, [sp, #152]                 // 8-byte Reload
.LBB1_32:
	ldp	x11, x25, [sp, #8]              // 16-byte Folded Reload
	stp	x23, x19, [x25]
	str	x9, [x25, #16]
.LBB1_33:
	ldr	x8, [sp, #24]                   // 8-byte Reload
	cmp	x27, x16
	b.ne	.LBB1_37
// %bb.34:
	ldr	x10, [sp, #32]                  // 8-byte Reload
	cmp	x9, x10
	mov	x9, x10
	b.eq	.LBB1_36
// %bb.35:
	ldr	x27, [x9, #-8]!
	add	x16, x27, #1, lsl #12           // =4096
.LBB1_36:
	mov	x10, x9
	b	.LBB1_38
.LBB1_37:
	ldr	x10, [sp, #32]                  // 8-byte Reload
.LBB1_38:
	add	x9, x27, #1, lsl #12            // =4096
	stp	x27, x16, [x25, #32]
	stp	x10, x9, [x25, #48]
.LBB1_39:
	stp	x11, x24, [x8]
	str	x26, [x8, #16]
	.seh_startepilogue
	ldr	x30, [sp, #144]                 // 8-byte Reload
	.seh_save_reg	x30, 144
	ldp	x27, x28, [sp, #128]            // 16-byte Folded Reload
	.seh_save_regp	x27, 128
	ldp	x25, x26, [sp, #112]            // 16-byte Folded Reload
	.seh_save_regp	x25, 112
	ldp	x23, x24, [sp, #96]             // 16-byte Folded Reload
	.seh_save_regp	x23, 96
	ldp	x21, x22, [sp, #80]             // 16-byte Folded Reload
	.seh_save_regp	x21, 80
	ldp	x19, x20, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x19, 64
	add	sp, sp, #160
	.seh_stackalloc	160
	.seh_endepilogue
	ret
.LBB1_40:
	ldr	x10, [sp, #32]                  // 8-byte Reload
	cbz	x10, .LBB1_44
// %bb.41:
	ldr	x9, [x10, #8]!
	mov	x11, x9
	b	.LBB1_1
.LBB1_42:
	ldr	x19, [sp, #32]                  // 8-byte Reload
	cbz	x19, .LBB1_18
// %bb.43:
	ldr	x16, [x19, #8]!
	b	.LBB1_18
.LBB1_44:
	mov	x9, x16
	mov	x11, x27
	b	.LBB1_1
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_Z9erase_u32RN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIjLb0EEES9_;
	.scl	2;
	.type	32;
	.endef
	.text
	.globl	_Z9erase_u32RN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIjLb0EEES9_ // -- Begin function _Z9erase_u32RN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIjLb0EEES9_
	.p2align	2
_Z9erase_u32RN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIjLb0EEES9_: // @_Z9erase_u32RN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIjLb0EEES9_
.seh_proc _Z9erase_u32RN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIjLb0EEES9_
// %bb.0:
	sub	sp, sp, #112
	.seh_stackalloc	112
	str	x30, [sp, #96]                  // 8-byte Spill
	.seh_save_reg	x30, 96
	.seh_endprologue
	ldr	x8, [x1, #16]
	ldr	q0, [x1]
	add	x1, sp, #64
	ldr	q1, [x2]
	ldr	x9, [x2, #16]
	add	x2, sp, #32
	str	x8, [sp, #80]
	add	x8, sp, #8
	str	q0, [sp, #64]
	str	q1, [sp, #32]
	str	x9, [sp, #48]
	bl	_ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_
	.seh_startepilogue
	ldr	x30, [sp, #96]                  // 8-byte Reload
	.seh_save_reg	x30, 96
	add	sp, sp, #112
	.seh_stackalloc	112
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_,"xr",discard,_ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_
	.globl	_ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_ // -- Begin function _ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_
	.p2align	2
_ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_: // @_ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_
.seh_proc _ZN7fast_io10containers5dequeIjNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIjLb1EEES8_
// %bb.0:
	sub	sp, sp, #160
	.seh_stackalloc	160
	stp	x19, x20, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x19, 64
	stp	x21, x22, [sp, #80]             // 16-byte Folded Spill
	.seh_save_regp	x21, 80
	stp	x23, x24, [sp, #96]             // 16-byte Folded Spill
	.seh_save_regp	x23, 96
	stp	x25, x26, [sp, #112]            // 16-byte Folded Spill
	.seh_save_regp	x25, 112
	stp	x27, x28, [sp, #128]            // 16-byte Folded Spill
	.seh_save_regp	x27, 128
	str	x30, [sp, #144]                 // 8-byte Spill
	.seh_save_reg	x30, 144
	.seh_endprologue
	ldp	x27, x16, [x0, #32]
	ldr	x17, [x1, #16]
	ldp	x10, x15, [x0, #48]
	ldr	x24, [x2, #8]
	ldp	x3, x21, [x1]
	mov	x9, x16
	mov	x11, x27
	cmp	x16, x15
	str	x10, [sp, #32]                  // 8-byte Spill
	b.eq	.LBB3_40
.LBB3_1:
	cmp	x21, x24
	b.eq	.LBB3_15
// %bb.2:
	ldp	x12, x4, [x0]
	sub	x13, x21, x3
	ldr	x26, [x2, #16]
	ldr	x23, [x2]
	sub	x9, x9, x11
	ldr	x2, [x0, #16]
	stp	x0, x8, [sp, #16]               // 16-byte Folded Spill
	sub	x12, x12, x4
	sub	x10, x10, x26
	sub	x14, x23, x24
	asr	x12, x12, #2
	lsl	x10, x10, #7
	add	x12, x12, x13, asr #2
	add	x10, x10, x14, asr #2
	sub	x13, x17, x2
	add	x11, x12, x13, lsl #7
	add	x9, x10, x9, asr #2
	cmp	x11, x9
	b.hs	.LBB3_16
// %bb.3:
	cmp	x4, x21
	mov	x19, x24
	mov	x9, x26
	str	x23, [sp, #8]                   // 8-byte Spill
	b.eq	.LBB3_32
// %bb.4:
	ldr	x23, [sp, #8]                   // 8-byte Reload
	mov	x19, x24
	str	x16, [sp]                       // 8-byte Spill
	str	x26, [sp, #152]                 // 8-byte Spill
	stp	x4, x2, [sp, #40]               // 16-byte Folded Spill
	b	.LBB3_8
.LBB3_5:                                //   in Loop: Header=BB3_8 Depth=1
	ldp	x2, x17, [sp, #48]              // 16-byte Folded Reload
	add	x19, x19, x22
	cmp	x2, x17
	b.eq	.LBB3_31
// %bb.6:                               //   in Loop: Header=BB3_8 Depth=1
	ldr	x4, [sp, #40]                   // 8-byte Reload
	add	x26, x26, #8
.LBB3_7:                                //   in Loop: Header=BB3_8 Depth=1
	ldr	x3, [x17, #-8]!
	add	x21, x3, #1, lsl #12            // =4096
.LBB3_8:                                // =>This Loop Header: Depth=1
                                        //     Child Loop BB3_10 Depth 2
	cmp	x2, x17
	sub	x26, x26, #8
	str	x17, [sp, #56]                  // 8-byte Spill
	csel	x20, x4, x3, eq
	sub	x28, x21, x20
	sub	x25, x19, x23
	cmp	x28, x25
	csel	x2, x28, x25, lo
	neg	x22, x2
	cbz	x2, .LBB3_10
.LBB3_9:                                //   in Loop: Header=BB3_8 Depth=1
	add	x0, x19, x22
	add	x1, x21, x22
	bl	memmove
.LBB3_10:                               //   Parent Loop BB3_8 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	cmp	x28, x25
	b.ls	.LBB3_12
// %bb.11:                              //   in Loop: Header=BB3_10 Depth=2
	ldr	x23, [x26], #-8
	add	x21, x21, x22
	add	x19, x23, #1, lsl #12           // =4096
	sub	x28, x21, x20
	sub	x25, x19, x23
	cmp	x28, x25
	csel	x2, x28, x25, lo
	neg	x22, x2
	cbnz	x2, .LBB3_9
	b	.LBB3_10
.LBB3_12:                               //   in Loop: Header=BB3_8 Depth=1
	b.ne	.LBB3_5
// %bb.13:                              //   in Loop: Header=BB3_8 Depth=1
	ldp	x2, x17, [sp, #48]              // 16-byte Folded Reload
	ldr	x4, [sp, #40]                   // 8-byte Reload
	cmp	x2, x17
	b.eq	.LBB3_30
// %bb.14:                              //   in Loop: Header=BB3_8 Depth=1
	ldr	x23, [x26]
	add	x19, x23, #1, lsl #12           // =4096
	b	.LBB3_7
.LBB3_15:
	mov	x11, x3
	mov	x24, x21
	mov	x26, x17
	b	.LBB3_39
.LBB3_16:
	cmp	x16, x15
	b.eq	.LBB3_42
// %bb.17:
	ldr	x19, [sp, #32]                  // 8-byte Reload
.LBB3_18:
	cmp	x24, x16
	b.eq	.LBB3_29
// %bb.19:
	mov	x9, x17
	mov	x22, x21
	mov	x27, x3
	stp	x3, x17, [sp, #48]              // 16-byte Folded Spill
	str	x19, [sp, #40]                  // 8-byte Spill
.LBB3_20:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB3_22 Depth 2
	add	x8, x23, #1, lsl #12            // =4096
	cmp	x26, x19
	str	x26, [sp, #152]                 // 8-byte Spill
	mov	x25, x16
	csel	x26, x16, x8, eq
	add	x9, x9, #8
	sub	x8, x27, x22
	sub	x20, x26, x24
	add	x28, x8, #1, lsl #12            // =4096
	cmp	x20, x28
	csel	x23, x20, x28, lo
	cbz	x23, .LBB3_22
.LBB3_21:                               //   in Loop: Header=BB3_20 Depth=1
	mov	x0, x22
	mov	x1, x24
	mov	x2, x23
	mov	x19, x9
	bl	memmove
	mov	x9, x19
.LBB3_22:                               //   Parent Loop BB3_20 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	cmp	x20, x28
	b.ls	.LBB3_24
// %bb.23:                              //   in Loop: Header=BB3_22 Depth=2
	ldr	x22, [x9], #8
	add	x24, x24, x23
	mov	x27, x22
	sub	x8, x22, x22
	sub	x20, x26, x24
	add	x28, x8, #1, lsl #12            // =4096
	cmp	x20, x28
	csel	x23, x20, x28, lo
	cbnz	x23, .LBB3_21
	b	.LBB3_22
.LBB3_24:                               //   in Loop: Header=BB3_20 Depth=1
	cmp	x20, x28
	b.hs	.LBB3_26
// %bb.25:                              //   in Loop: Header=BB3_20 Depth=1
	sub	x9, x9, #8
	add	x22, x22, x20
	ldr	x26, [sp, #152]                 // 8-byte Reload
	ldr	x19, [sp, #40]                  // 8-byte Reload
	mov	x16, x25
	cmp	x26, x19
	b.ne	.LBB3_27
	b	.LBB3_28
.LBB3_26:                               //   in Loop: Header=BB3_20 Depth=1
	ldr	x27, [x9]
	mov	x22, x27
	ldr	x26, [sp, #152]                 // 8-byte Reload
	ldr	x19, [sp, #40]                  // 8-byte Reload
	mov	x16, x25
	cmp	x26, x19
	b.eq	.LBB3_28
.LBB3_27:                               //   in Loop: Header=BB3_20 Depth=1
	ldr	x24, [x26, #8]!
	mov	x23, x24
	b	.LBB3_20
.LBB3_28:
	ldr	x25, [sp, #16]                  // 8-byte Reload
	ldp	x11, x26, [sp, #48]             // 16-byte Folded Reload
	str	x9, [sp, #32]                   // 8-byte Spill
	mov	x24, x21
	mov	x16, x22
	ldr	x9, [x25, #16]
	b	.LBB3_33
.LBB3_29:
	ldr	x25, [sp, #16]                  // 8-byte Reload
	mov	x9, x2
	mov	x11, x3
	mov	x24, x21
	mov	x26, x17
	str	x17, [sp, #32]                  // 8-byte Spill
	mov	x16, x21
	mov	x27, x3
	b	.LBB3_33
.LBB3_30:
	mov	x19, x23
.LBB3_31:
	add	x9, x26, #8
	ldr	x16, [sp]                       // 8-byte Reload
	ldr	x26, [sp, #152]                 // 8-byte Reload
.LBB3_32:
	ldp	x11, x25, [sp, #8]              // 16-byte Folded Reload
	stp	x23, x19, [x25]
	str	x9, [x25, #16]
.LBB3_33:
	ldr	x8, [sp, #24]                   // 8-byte Reload
	cmp	x27, x16
	b.ne	.LBB3_37
// %bb.34:
	ldr	x10, [sp, #32]                  // 8-byte Reload
	cmp	x9, x10
	mov	x9, x10
	b.eq	.LBB3_36
// %bb.35:
	ldr	x27, [x9, #-8]!
	add	x16, x27, #1, lsl #12           // =4096
.LBB3_36:
	mov	x10, x9
	b	.LBB3_38
.LBB3_37:
	ldr	x10, [sp, #32]                  // 8-byte Reload
.LBB3_38:
	add	x9, x27, #1, lsl #12            // =4096
	stp	x27, x16, [x25, #32]
	stp	x10, x9, [x25, #48]
.LBB3_39:
	stp	x11, x24, [x8]
	str	x26, [x8, #16]
	.seh_startepilogue
	ldr	x30, [sp, #144]                 // 8-byte Reload
	.seh_save_reg	x30, 144
	ldp	x27, x28, [sp, #128]            // 16-byte Folded Reload
	.seh_save_regp	x27, 128
	ldp	x25, x26, [sp, #112]            // 16-byte Folded Reload
	.seh_save_regp	x25, 112
	ldp	x23, x24, [sp, #96]             // 16-byte Folded Reload
	.seh_save_regp	x23, 96
	ldp	x21, x22, [sp, #80]             // 16-byte Folded Reload
	.seh_save_regp	x21, 80
	ldp	x19, x20, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x19, 64
	add	sp, sp, #160
	.seh_stackalloc	160
	.seh_endepilogue
	ret
.LBB3_40:
	ldr	x10, [sp, #32]                  // 8-byte Reload
	cbz	x10, .LBB3_44
// %bb.41:
	ldr	x9, [x10, #8]!
	mov	x11, x9
	b	.LBB3_1
.LBB3_42:
	ldr	x19, [sp, #32]                  // 8-byte Reload
	cbz	x19, .LBB3_18
// %bb.43:
	ldr	x16, [x19, #8]!
	b	.LBB3_18
.LBB3_44:
	mov	x9, x16
	mov	x11, x27
	b	.LBB3_1
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_Z9erase_u64RN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIyLb0EEES9_;
	.scl	2;
	.type	32;
	.endef
	.text
	.globl	_Z9erase_u64RN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIyLb0EEES9_ // -- Begin function _Z9erase_u64RN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIyLb0EEES9_
	.p2align	2
_Z9erase_u64RN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIyLb0EEES9_: // @_Z9erase_u64RN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIyLb0EEES9_
.seh_proc _Z9erase_u64RN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEEENS0_7details14deque_iteratorIyLb0EEES9_
// %bb.0:
	sub	sp, sp, #112
	.seh_stackalloc	112
	str	x30, [sp, #96]                  // 8-byte Spill
	.seh_save_reg	x30, 96
	.seh_endprologue
	ldr	x8, [x1, #16]
	ldr	q0, [x1]
	add	x1, sp, #64
	ldr	q1, [x2]
	ldr	x9, [x2, #16]
	add	x2, sp, #32
	str	x8, [sp, #80]
	add	x8, sp, #8
	str	q0, [sp, #64]
	str	q1, [sp, #32]
	str	x9, [sp, #48]
	bl	_ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_
	.seh_startepilogue
	ldr	x30, [sp, #96]                  // 8-byte Reload
	.seh_save_reg	x30, 96
	add	sp, sp, #112
	.seh_stackalloc	112
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_,"xr",discard,_ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_
	.globl	_ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_ // -- Begin function _ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_
	.p2align	2
_ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_: // @_ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_
.seh_proc _ZN7fast_io10containers5dequeIyNS_25generic_allocator_adapterINS_28nt_rtlallocateheap_allocatorEEEE5eraseENS0_7details14deque_iteratorIyLb1EEES8_
// %bb.0:
	sub	sp, sp, #160
	.seh_stackalloc	160
	stp	x19, x20, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x19, 64
	stp	x21, x22, [sp, #80]             // 16-byte Folded Spill
	.seh_save_regp	x21, 80
	stp	x23, x24, [sp, #96]             // 16-byte Folded Spill
	.seh_save_regp	x23, 96
	stp	x25, x26, [sp, #112]            // 16-byte Folded Spill
	.seh_save_regp	x25, 112
	stp	x27, x28, [sp, #128]            // 16-byte Folded Spill
	.seh_save_regp	x27, 128
	str	x30, [sp, #144]                 // 8-byte Spill
	.seh_save_reg	x30, 144
	.seh_endprologue
	ldp	x27, x16, [x0, #32]
	ldr	x17, [x1, #16]
	ldp	x10, x15, [x0, #48]
	ldr	x24, [x2, #8]
	ldp	x3, x21, [x1]
	mov	x9, x16
	mov	x11, x27
	cmp	x16, x15
	str	x10, [sp, #32]                  // 8-byte Spill
	b.eq	.LBB5_40
.LBB5_1:
	cmp	x21, x24
	b.eq	.LBB5_15
// %bb.2:
	ldp	x12, x4, [x0]
	sub	x13, x21, x3
	ldr	x26, [x2, #16]
	ldr	x23, [x2]
	sub	x9, x9, x11
	ldr	x2, [x0, #16]
	stp	x0, x8, [sp, #16]               // 16-byte Folded Spill
	sub	x12, x12, x4
	sub	x10, x10, x26
	sub	x14, x23, x24
	asr	x12, x12, #3
	lsl	x10, x10, #6
	add	x12, x12, x13, asr #3
	add	x10, x10, x14, asr #3
	sub	x13, x17, x2
	add	x11, x12, x13, lsl #6
	add	x9, x10, x9, asr #3
	cmp	x11, x9
	b.hs	.LBB5_16
// %bb.3:
	cmp	x4, x21
	mov	x19, x24
	mov	x9, x26
	str	x23, [sp, #8]                   // 8-byte Spill
	b.eq	.LBB5_32
// %bb.4:
	ldr	x23, [sp, #8]                   // 8-byte Reload
	mov	x19, x24
	str	x16, [sp]                       // 8-byte Spill
	str	x26, [sp, #152]                 // 8-byte Spill
	stp	x4, x2, [sp, #40]               // 16-byte Folded Spill
	b	.LBB5_8
.LBB5_5:                                //   in Loop: Header=BB5_8 Depth=1
	ldp	x2, x17, [sp, #48]              // 16-byte Folded Reload
	add	x19, x19, x22
	cmp	x2, x17
	b.eq	.LBB5_31
// %bb.6:                               //   in Loop: Header=BB5_8 Depth=1
	ldr	x4, [sp, #40]                   // 8-byte Reload
	add	x26, x26, #8
.LBB5_7:                                //   in Loop: Header=BB5_8 Depth=1
	ldr	x3, [x17, #-8]!
	add	x21, x3, #1, lsl #12            // =4096
.LBB5_8:                                // =>This Loop Header: Depth=1
                                        //     Child Loop BB5_10 Depth 2
	cmp	x2, x17
	sub	x26, x26, #8
	str	x17, [sp, #56]                  // 8-byte Spill
	csel	x20, x4, x3, eq
	sub	x28, x21, x20
	sub	x25, x19, x23
	cmp	x28, x25
	csel	x2, x28, x25, lo
	neg	x22, x2
	cbz	x2, .LBB5_10
.LBB5_9:                                //   in Loop: Header=BB5_8 Depth=1
	add	x0, x19, x22
	add	x1, x21, x22
	bl	memmove
.LBB5_10:                               //   Parent Loop BB5_8 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	cmp	x28, x25
	b.ls	.LBB5_12
// %bb.11:                              //   in Loop: Header=BB5_10 Depth=2
	ldr	x23, [x26], #-8
	add	x21, x21, x22
	add	x19, x23, #1, lsl #12           // =4096
	sub	x28, x21, x20
	sub	x25, x19, x23
	cmp	x28, x25
	csel	x2, x28, x25, lo
	neg	x22, x2
	cbnz	x2, .LBB5_9
	b	.LBB5_10
.LBB5_12:                               //   in Loop: Header=BB5_8 Depth=1
	b.ne	.LBB5_5
// %bb.13:                              //   in Loop: Header=BB5_8 Depth=1
	ldp	x2, x17, [sp, #48]              // 16-byte Folded Reload
	ldr	x4, [sp, #40]                   // 8-byte Reload
	cmp	x2, x17
	b.eq	.LBB5_30
// %bb.14:                              //   in Loop: Header=BB5_8 Depth=1
	ldr	x23, [x26]
	add	x19, x23, #1, lsl #12           // =4096
	b	.LBB5_7
.LBB5_15:
	mov	x11, x3
	mov	x24, x21
	mov	x26, x17
	b	.LBB5_39
.LBB5_16:
	cmp	x16, x15
	b.eq	.LBB5_42
// %bb.17:
	ldr	x19, [sp, #32]                  // 8-byte Reload
.LBB5_18:
	cmp	x24, x16
	b.eq	.LBB5_29
// %bb.19:
	mov	x9, x17
	mov	x22, x21
	mov	x27, x3
	stp	x3, x17, [sp, #48]              // 16-byte Folded Spill
	str	x19, [sp, #40]                  // 8-byte Spill
.LBB5_20:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB5_22 Depth 2
	add	x8, x23, #1, lsl #12            // =4096
	cmp	x26, x19
	str	x26, [sp, #152]                 // 8-byte Spill
	mov	x25, x16
	csel	x26, x16, x8, eq
	add	x9, x9, #8
	sub	x8, x27, x22
	sub	x20, x26, x24
	add	x28, x8, #1, lsl #12            // =4096
	cmp	x20, x28
	csel	x23, x20, x28, lo
	cbz	x23, .LBB5_22
.LBB5_21:                               //   in Loop: Header=BB5_20 Depth=1
	mov	x0, x22
	mov	x1, x24
	mov	x2, x23
	mov	x19, x9
	bl	memmove
	mov	x9, x19
.LBB5_22:                               //   Parent Loop BB5_20 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	cmp	x20, x28
	b.ls	.LBB5_24
// %bb.23:                              //   in Loop: Header=BB5_22 Depth=2
	ldr	x22, [x9], #8
	add	x24, x24, x23
	mov	x27, x22
	sub	x8, x22, x22
	sub	x20, x26, x24
	add	x28, x8, #1, lsl #12            // =4096
	cmp	x20, x28
	csel	x23, x20, x28, lo
	cbnz	x23, .LBB5_21
	b	.LBB5_22
.LBB5_24:                               //   in Loop: Header=BB5_20 Depth=1
	cmp	x20, x28
	b.hs	.LBB5_26
// %bb.25:                              //   in Loop: Header=BB5_20 Depth=1
	sub	x9, x9, #8
	add	x22, x22, x20
	ldr	x26, [sp, #152]                 // 8-byte Reload
	ldr	x19, [sp, #40]                  // 8-byte Reload
	mov	x16, x25
	cmp	x26, x19
	b.ne	.LBB5_27
	b	.LBB5_28
.LBB5_26:                               //   in Loop: Header=BB5_20 Depth=1
	ldr	x27, [x9]
	mov	x22, x27
	ldr	x26, [sp, #152]                 // 8-byte Reload
	ldr	x19, [sp, #40]                  // 8-byte Reload
	mov	x16, x25
	cmp	x26, x19
	b.eq	.LBB5_28
.LBB5_27:                               //   in Loop: Header=BB5_20 Depth=1
	ldr	x24, [x26, #8]!
	mov	x23, x24
	b	.LBB5_20
.LBB5_28:
	ldr	x25, [sp, #16]                  // 8-byte Reload
	ldp	x11, x26, [sp, #48]             // 16-byte Folded Reload
	str	x9, [sp, #32]                   // 8-byte Spill
	mov	x24, x21
	mov	x16, x22
	ldr	x9, [x25, #16]
	b	.LBB5_33
.LBB5_29:
	ldr	x25, [sp, #16]                  // 8-byte Reload
	mov	x9, x2
	mov	x11, x3
	mov	x24, x21
	mov	x26, x17
	str	x17, [sp, #32]                  // 8-byte Spill
	mov	x16, x21
	mov	x27, x3
	b	.LBB5_33
.LBB5_30:
	mov	x19, x23
.LBB5_31:
	add	x9, x26, #8
	ldr	x16, [sp]                       // 8-byte Reload
	ldr	x26, [sp, #152]                 // 8-byte Reload
.LBB5_32:
	ldp	x11, x25, [sp, #8]              // 16-byte Folded Reload
	stp	x23, x19, [x25]
	str	x9, [x25, #16]
.LBB5_33:
	ldr	x8, [sp, #24]                   // 8-byte Reload
	cmp	x27, x16
	b.ne	.LBB5_37
// %bb.34:
	ldr	x10, [sp, #32]                  // 8-byte Reload
	cmp	x9, x10
	mov	x9, x10
	b.eq	.LBB5_36
// %bb.35:
	ldr	x27, [x9, #-8]!
	add	x16, x27, #1, lsl #12           // =4096
.LBB5_36:
	mov	x10, x9
	b	.LBB5_38
.LBB5_37:
	ldr	x10, [sp, #32]                  // 8-byte Reload
.LBB5_38:
	add	x9, x27, #1, lsl #12            // =4096
	stp	x27, x16, [x25, #32]
	stp	x10, x9, [x25, #48]
.LBB5_39:
	stp	x11, x24, [x8]
	str	x26, [x8, #16]
	.seh_startepilogue
	ldr	x30, [sp, #144]                 // 8-byte Reload
	.seh_save_reg	x30, 144
	ldp	x27, x28, [sp, #128]            // 16-byte Folded Reload
	.seh_save_regp	x27, 128
	ldp	x25, x26, [sp, #112]            // 16-byte Folded Reload
	.seh_save_regp	x25, 112
	ldp	x23, x24, [sp, #96]             // 16-byte Folded Reload
	.seh_save_regp	x23, 96
	ldp	x21, x22, [sp, #80]             // 16-byte Folded Reload
	.seh_save_regp	x21, 80
	ldp	x19, x20, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x19, 64
	add	sp, sp, #160
	.seh_stackalloc	160
	.seh_endepilogue
	ret
.LBB5_40:
	ldr	x10, [sp, #32]                  // 8-byte Reload
	cbz	x10, .LBB5_44
// %bb.41:
	ldr	x9, [x10, #8]!
	mov	x11, x9
	b	.LBB5_1
.LBB5_42:
	ldr	x19, [sp, #32]                  // 8-byte Reload
	cbz	x19, .LBB5_18
// %bb.43:
	ldr	x16, [x19, #8]!
	b	.LBB5_18
.LBB5_44:
	mov	x9, x16
	mov	x11, x27
	b	.LBB5_1
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.section	.debug$S,"dr"
	.p2align	2, 0x0
	.word	4                               // Debug section magic
	.word	241
	.word	.Ltmp1-.Ltmp0                   // Subsection size
.Ltmp0:
	.hword	.Ltmp3-.Ltmp2                   // Record length
.Ltmp2:
	.hword	4353                            // Record kind: S_OBJNAME
	.word	0                               // Signature
	.byte	0                               // Object name
	.p2align	2, 0x0
.Ltmp3:
	.hword	.Ltmp5-.Ltmp4                   // Record length
.Ltmp4:
	.hword	4412                            // Record kind: S_COMPILE3
	.word	16385                           // Flags and language
	.hword	246                             // CPUType
	.hword	22                              // Frontend version
	.hword	0
	.hword	0
	.hword	0
	.hword	22000                           // Backend version
	.hword	0
	.hword	0
	.hword	0
	.asciz	"clang version 22.0.0git (git@github.com:trcrsired/llvm-project.git 1c607433d98b2d1a5f6f38bd64f3b180520e2fe6)" // Null-terminated compiler version string
	.p2align	2, 0x0
.Ltmp5:
.Ltmp1:
	.p2align	2, 0x0
	.addrsig
	.addrsig_sym __gxx_personality_seh0
