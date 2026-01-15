	.def	"@feat.00";
	.scl	3;
	.type	0;
	.endef
	.globl	"@feat.00"
"@feat.00" = 0
	.file	"erase_std.cc"
	.def	_Z9erase_u16RNSt3__15dequeItNS_9allocatorItEEEENS_16__deque_iteratorItPtRtPS6_xLx2048EEES9_;
	.scl	2;
	.type	32;
	.endef
	.text
	.globl	_Z9erase_u16RNSt3__15dequeItNS_9allocatorItEEEENS_16__deque_iteratorItPtRtPS6_xLx2048EEES9_ // -- Begin function _Z9erase_u16RNSt3__15dequeItNS_9allocatorItEEEENS_16__deque_iteratorItPtRtPS6_xLx2048EEES9_
	.p2align	2
_Z9erase_u16RNSt3__15dequeItNS_9allocatorItEEEENS_16__deque_iteratorItPtRtPS6_xLx2048EEES9_: // @_Z9erase_u16RNSt3__15dequeItNS_9allocatorItEEEENS_16__deque_iteratorItPtRtPS6_xLx2048EEES9_
// %bb.0:
	b	_ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_
                                        // -- End function
	.def	_ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_,"xr",discard,_ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_
	.globl	_ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_ // -- Begin function _ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_
	.p2align	2
_ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_: // @_ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_
.seh_proc _ZNSt3__15dequeItNS_9allocatorItEEE5eraseENS_16__deque_iteratorItPKtRS5_PKS6_xLx2048EEESA_
// %bb.0:
	sub	sp, sp, #64
	.seh_stackalloc	64
	stp	x19, x20, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x19, 16
	stp	x21, x22, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x21, 32
	str	x30, [sp, #48]                  // 8-byte Spill
	.seh_save_reg	x30, 48
	.seh_endprologue
	mov	x8, x1
	cmp	x4, x2
	mov	x19, x0
	b.eq	.LBB1_6
// %bb.1:
	ldr	x9, [x3]
	sub	x10, x3, x8
	ldr	x11, [x8]
	sub	x9, x4, x9
	asr	x9, x9, #1
	add	x9, x9, x10, lsl #8
	sub	x10, x2, x11
	sub	x22, x9, x10, asr #1
	ldr	x10, [x19, #32]
	ldp	x9, x11, [x19, #8]
	lsr	x12, x10, #11
	cmp	x9, x11
	add	x0, x9, x12, lsl #3
	b.eq	.LBB1_7
.LBB1_2:
	ldr	x12, [x0]
	and	x13, x10, #0x7ff
	add	x1, x12, x13, lsl #1
	cmp	x2, x1
	b.eq	.LBB1_8
.LBB1_3:
	ldr	x12, [x8]
	sub	x8, x8, x0
	ldr	x13, [x0]
	sub	x12, x2, x12
	asr	x12, x12, #1
	add	x8, x12, x8, lsl #8
	sub	x12, x1, x13
	subs	x20, x8, x12, asr #1
	b.eq	.LBB1_9
// %bb.4:
	cmp	x8, #1
	b.lt	.LBB1_10
// %bb.5:
	lsr	x12, x8, #11
	add	x2, x0, x12, lsl #3
	b	.LBB1_11
.LBB1_6:
	mov	x22, xzr
	ldr	x10, [x19, #32]
	ldp	x9, x11, [x19, #8]
	lsr	x12, x10, #11
	cmp	x9, x11
	add	x0, x9, x12, lsl #3
	b.ne	.LBB1_2
.LBB1_7:
	mov	x1, xzr
	cmp	x2, xzr
	b.ne	.LBB1_3
.LBB1_8:
	mov	x20, xzr
.LBB1_9:
	mov	w21, #1                         // =0x1
	mov	x3, x1
	mov	x2, x0
	cmp	x22, #1
	b.ge	.LBB1_12
	b	.LBB1_26
.LBB1_10:
	mov	w12, #2047                      // =0x7ff
	sub	x8, x12, x8
	lsr	x12, x8, #11
	mvn	w8, w8
	sub	x2, x0, x12, lsl #3
.LBB1_11:
	ldr	x12, [x2]
	and	x8, x8, #0x7ff
	mov	w21, wzr
	add	x3, x12, x8, lsl #1
	cmp	x22, #1
	b.lt	.LBB1_26
.LBB1_12:
	ldr	x12, [x2]
	ldr	x8, [x19, #40]
	sub	x12, x3, x12
	sub	x13, x8, x22
	add	x12, x22, x12, asr #1
	cmp	x20, x13, lsr #1
	b.ls	.LBB1_15
// %bb.13:
	cmp	x12, #1
	b.lt	.LBB1_17
// %bb.14:
	lsr	x13, x12, #11
	add	x0, x2, x13, lsl #3
	b	.LBB1_18
.LBB1_15:
	cmp	x12, #1
	b.lt	.LBB1_20
// %bb.16:
	lsr	x8, x12, #11
	and	x10, x12, #0x7ff
	add	x8, x2, x8, lsl #3
	ldr	x9, [x8]
	add	x9, x9, x10, lsl #1
	b	.LBB1_21
.LBB1_17:
	mov	w13, #2047                      // =0x7ff
	sub	x12, x13, x12
	lsr	x13, x12, #11
	mvn	w12, w12
	sub	x0, x2, x13, lsl #3
.LBB1_18:
	add	x10, x8, x10
	ldr	x13, [x0]
	and	x12, x12, #0x7ff
	lsr	x8, x10, #11
	cmp	x9, x11
	add	x1, x13, x12, lsl #1
	add	x8, x9, x8, lsl #3
	b.eq	.LBB1_23
// %bb.19:
	ldr	x9, [x8]
	and	x10, x10, #0x7ff
	add	x9, x9, x10, lsl #1
	b	.LBB1_24
.LBB1_20:
	mov	w8, #2047                       // =0x7ff
	sub	x9, x8, x12
	lsr	x8, x9, #11
	mvn	w9, w9
	and	x9, x9, #0x7ff
	sub	x8, x2, x8, lsl #3
	ldr	x10, [x8]
	add	x9, x10, x9, lsl #1
.LBB1_21:
	mov	x4, sp
	stp	x8, x9, [sp]
	bl	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	ldp	x9, x8, [x19, #32]
	sub	x8, x8, x22
	add	x10, x9, x22
	ldr	x9, [x19, #8]
	cmp	x10, #1, lsl #12                // =4096
	stp	x10, x8, [x19, #32]
	b.lo	.LBB1_26
.LBB1_22:                               // =>This Inner Loop Header: Depth=1
	ldr	x0, [x9]
	bl	_ZdlPv
	ldr	x10, [x19, #32]
	ldr	x8, [x19, #8]
	sub	x10, x10, #2048
	add	x9, x8, #8
	cmp	x10, #1, lsl #12                // =4096
	str	x9, [x19, #8]
	str	x10, [x19, #32]
	b.hs	.LBB1_22
	b	.LBB1_26
.LBB1_23:
	mov	x9, xzr
.LBB1_24:
	stp	x2, x3, [sp]
	mov	x4, sp
	mov	x2, x8
	mov	x3, x9
	bl	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	ldp	x9, x8, [x19, #8]
	subs	x10, x8, x9
	lsl	x11, x10, #8
	ldp	x10, x12, [x19, #32]
	cmp	x8, x9
	sub	x11, x11, #1
	sub	x12, x12, x22
	csel	x11, xzr, x11, eq
	add	x13, x12, x10
	str	x12, [x19, #40]
	sub	x11, x11, x13
	cmp	x11, #1, lsl #12                // =4096
	b.lo	.LBB1_26
.LBB1_25:                               // =>This Inner Loop Header: Depth=1
	ldur	x0, [x8, #-8]
	bl	_ZdlPv
	ldp	x9, x8, [x19, #8]
	sub	x8, x8, #8
	subs	x10, x8, x9
	str	x8, [x19, #16]
	lsl	x11, x10, #8
	ldp	x10, x12, [x19, #32]
	cmp	x8, x9
	sub	x11, x11, #1
	csel	x11, xzr, x11, eq
	add	x12, x12, x10
	sub	x11, x11, x12
	cmp	x11, #4095
	b.hi	.LBB1_25
.LBB1_26:
	lsr	x8, x10, #11
	ldr	x11, [x19, #16]
	add	x0, x9, x8, lsl #3
	cmp	x9, x11
	b.eq	.LBB1_28
// %bb.27:
	ldr	x8, [x0]
	and	x9, x10, #0x7ff
	add	x1, x8, x9, lsl #1
	tbz	w21, #0, .LBB1_29
	b	.LBB1_33
.LBB1_28:
	mov	x1, xzr
	tbnz	w21, #0, .LBB1_33
.LBB1_29:
	ldr	x8, [x0]
	sub	x8, x1, x8
	add	x8, x20, x8, asr #1
	cmp	x8, #1
	b.lt	.LBB1_31
// %bb.30:
	lsr	x9, x8, #11
	add	x0, x0, x9, lsl #3
	b	.LBB1_32
.LBB1_31:
	mov	w9, #2047                       // =0x7ff
	sub	x8, x9, x8
	lsr	x9, x8, #11
	mvn	w8, w8
	sub	x0, x0, x9, lsl #3
.LBB1_32:
	ldr	x9, [x0]
	and	x8, x8, #0x7ff
	add	x1, x9, x8, lsl #1
.LBB1_33:
	.seh_startepilogue
	ldr	x30, [sp, #48]                  // 8-byte Reload
	.seh_save_reg	x30, 48
	ldp	x21, x22, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x21, 32
	ldp	x19, x20, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x19, 16
	add	sp, sp, #64
	.seh_stackalloc	64
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_Z9erase_u32RNSt3__15dequeIjNS_9allocatorIjEEEENS_16__deque_iteratorIjPjRjPS6_xLx1024EEES9_;
	.scl	2;
	.type	32;
	.endef
	.text
	.globl	_Z9erase_u32RNSt3__15dequeIjNS_9allocatorIjEEEENS_16__deque_iteratorIjPjRjPS6_xLx1024EEES9_ // -- Begin function _Z9erase_u32RNSt3__15dequeIjNS_9allocatorIjEEEENS_16__deque_iteratorIjPjRjPS6_xLx1024EEES9_
	.p2align	2
_Z9erase_u32RNSt3__15dequeIjNS_9allocatorIjEEEENS_16__deque_iteratorIjPjRjPS6_xLx1024EEES9_: // @_Z9erase_u32RNSt3__15dequeIjNS_9allocatorIjEEEENS_16__deque_iteratorIjPjRjPS6_xLx1024EEES9_
// %bb.0:
	b	_ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_
                                        // -- End function
	.def	_ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_,"xr",discard,_ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_
	.globl	_ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_ // -- Begin function _ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_
	.p2align	2
_ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_: // @_ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_
.seh_proc _ZNSt3__15dequeIjNS_9allocatorIjEEE5eraseENS_16__deque_iteratorIjPKjRS5_PKS6_xLx1024EEESA_
// %bb.0:
	sub	sp, sp, #64
	.seh_stackalloc	64
	stp	x19, x20, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x19, 16
	stp	x21, x22, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x21, 32
	str	x30, [sp, #48]                  // 8-byte Spill
	.seh_save_reg	x30, 48
	.seh_endprologue
	mov	x8, x1
	cmp	x4, x2
	mov	x19, x0
	b.eq	.LBB3_6
// %bb.1:
	ldr	x9, [x3]
	sub	x10, x3, x8
	ldr	x11, [x8]
	sub	x9, x4, x9
	asr	x9, x9, #2
	add	x9, x9, x10, lsl #7
	sub	x10, x2, x11
	sub	x22, x9, x10, asr #2
	ldr	x10, [x19, #32]
	ldp	x9, x11, [x19, #8]
	lsr	x12, x10, #10
	cmp	x9, x11
	add	x0, x9, x12, lsl #3
	b.eq	.LBB3_7
.LBB3_2:
	ldr	x12, [x0]
	and	x13, x10, #0x3ff
	add	x1, x12, x13, lsl #2
	cmp	x2, x1
	b.eq	.LBB3_8
.LBB3_3:
	ldr	x12, [x8]
	sub	x8, x8, x0
	ldr	x13, [x0]
	sub	x12, x2, x12
	asr	x12, x12, #2
	add	x8, x12, x8, lsl #7
	sub	x12, x1, x13
	subs	x20, x8, x12, asr #2
	b.eq	.LBB3_9
// %bb.4:
	cmp	x8, #1
	b.lt	.LBB3_10
// %bb.5:
	lsr	x12, x8, #10
	add	x2, x0, x12, lsl #3
	b	.LBB3_11
.LBB3_6:
	mov	x22, xzr
	ldr	x10, [x19, #32]
	ldp	x9, x11, [x19, #8]
	lsr	x12, x10, #10
	cmp	x9, x11
	add	x0, x9, x12, lsl #3
	b.ne	.LBB3_2
.LBB3_7:
	mov	x1, xzr
	cmp	x2, xzr
	b.ne	.LBB3_3
.LBB3_8:
	mov	x20, xzr
.LBB3_9:
	mov	w21, #1                         // =0x1
	mov	x3, x1
	mov	x2, x0
	cmp	x22, #1
	b.ge	.LBB3_12
	b	.LBB3_26
.LBB3_10:
	mov	w12, #1023                      // =0x3ff
	sub	x8, x12, x8
	lsr	x12, x8, #10
	mvn	w8, w8
	sub	x2, x0, x12, lsl #3
.LBB3_11:
	ldr	x12, [x2]
	and	x8, x8, #0x3ff
	mov	w21, wzr
	add	x3, x12, x8, lsl #2
	cmp	x22, #1
	b.lt	.LBB3_26
.LBB3_12:
	ldr	x12, [x2]
	ldr	x8, [x19, #40]
	sub	x12, x3, x12
	sub	x13, x8, x22
	add	x12, x22, x12, asr #2
	cmp	x20, x13, lsr #1
	b.ls	.LBB3_15
// %bb.13:
	cmp	x12, #1
	b.lt	.LBB3_17
// %bb.14:
	lsr	x13, x12, #10
	add	x0, x2, x13, lsl #3
	b	.LBB3_18
.LBB3_15:
	cmp	x12, #1
	b.lt	.LBB3_20
// %bb.16:
	lsr	x8, x12, #10
	and	x10, x12, #0x3ff
	add	x8, x2, x8, lsl #3
	ldr	x9, [x8]
	add	x9, x9, x10, lsl #2
	b	.LBB3_21
.LBB3_17:
	mov	w13, #1023                      // =0x3ff
	sub	x12, x13, x12
	lsr	x13, x12, #10
	mvn	w12, w12
	sub	x0, x2, x13, lsl #3
.LBB3_18:
	add	x10, x8, x10
	ldr	x13, [x0]
	and	x12, x12, #0x3ff
	lsr	x8, x10, #10
	cmp	x9, x11
	add	x1, x13, x12, lsl #2
	add	x8, x9, x8, lsl #3
	b.eq	.LBB3_23
// %bb.19:
	ldr	x9, [x8]
	and	x10, x10, #0x3ff
	add	x9, x9, x10, lsl #2
	b	.LBB3_24
.LBB3_20:
	mov	w8, #1023                       // =0x3ff
	sub	x9, x8, x12
	lsr	x8, x9, #10
	mvn	w9, w9
	and	x9, x9, #0x3ff
	sub	x8, x2, x8, lsl #3
	ldr	x10, [x8]
	add	x9, x10, x9, lsl #2
.LBB3_21:
	mov	x4, sp
	stp	x8, x9, [sp]
	bl	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	ldp	x9, x8, [x19, #32]
	sub	x8, x8, x22
	add	x10, x9, x22
	ldr	x9, [x19, #8]
	cmp	x10, #2048
	stp	x10, x8, [x19, #32]
	b.lo	.LBB3_26
.LBB3_22:                               // =>This Inner Loop Header: Depth=1
	ldr	x0, [x9]
	bl	_ZdlPv
	ldr	x10, [x19, #32]
	ldr	x8, [x19, #8]
	sub	x10, x10, #1024
	add	x9, x8, #8
	cmp	x10, #2048
	str	x9, [x19, #8]
	str	x10, [x19, #32]
	b.hs	.LBB3_22
	b	.LBB3_26
.LBB3_23:
	mov	x9, xzr
.LBB3_24:
	stp	x2, x3, [sp]
	mov	x4, sp
	mov	x2, x8
	mov	x3, x9
	bl	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	ldp	x9, x8, [x19, #8]
	subs	x10, x8, x9
	lsl	x11, x10, #7
	ldp	x10, x12, [x19, #32]
	cmp	x8, x9
	sub	x11, x11, #1
	sub	x12, x12, x22
	csel	x11, xzr, x11, eq
	add	x13, x12, x10
	str	x12, [x19, #40]
	sub	x11, x11, x13
	cmp	x11, #2048
	b.lo	.LBB3_26
.LBB3_25:                               // =>This Inner Loop Header: Depth=1
	ldur	x0, [x8, #-8]
	bl	_ZdlPv
	ldp	x9, x8, [x19, #8]
	sub	x8, x8, #8
	subs	x10, x8, x9
	str	x8, [x19, #16]
	lsl	x11, x10, #7
	ldp	x10, x12, [x19, #32]
	cmp	x8, x9
	sub	x11, x11, #1
	csel	x11, xzr, x11, eq
	add	x12, x12, x10
	sub	x11, x11, x12
	cmp	x11, #2047
	b.hi	.LBB3_25
.LBB3_26:
	lsr	x8, x10, #10
	ldr	x11, [x19, #16]
	add	x0, x9, x8, lsl #3
	cmp	x9, x11
	b.eq	.LBB3_28
// %bb.27:
	ldr	x8, [x0]
	and	x9, x10, #0x3ff
	add	x1, x8, x9, lsl #2
	tbz	w21, #0, .LBB3_29
	b	.LBB3_33
.LBB3_28:
	mov	x1, xzr
	tbnz	w21, #0, .LBB3_33
.LBB3_29:
	ldr	x8, [x0]
	sub	x8, x1, x8
	add	x8, x20, x8, asr #2
	cmp	x8, #1
	b.lt	.LBB3_31
// %bb.30:
	lsr	x9, x8, #10
	add	x0, x0, x9, lsl #3
	b	.LBB3_32
.LBB3_31:
	mov	w9, #1023                       // =0x3ff
	sub	x8, x9, x8
	lsr	x9, x8, #10
	mvn	w8, w8
	sub	x0, x0, x9, lsl #3
.LBB3_32:
	ldr	x9, [x0]
	and	x8, x8, #0x3ff
	add	x1, x9, x8, lsl #2
.LBB3_33:
	.seh_startepilogue
	ldr	x30, [sp, #48]                  // 8-byte Reload
	.seh_save_reg	x30, 48
	ldp	x21, x22, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x21, 32
	ldp	x19, x20, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x19, 16
	add	sp, sp, #64
	.seh_stackalloc	64
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_Z9erase_u64RNSt3__15dequeIyNS_9allocatorIyEEEENS_16__deque_iteratorIyPyRyPS6_xLx512EEES9_;
	.scl	2;
	.type	32;
	.endef
	.text
	.globl	_Z9erase_u64RNSt3__15dequeIyNS_9allocatorIyEEEENS_16__deque_iteratorIyPyRyPS6_xLx512EEES9_ // -- Begin function _Z9erase_u64RNSt3__15dequeIyNS_9allocatorIyEEEENS_16__deque_iteratorIyPyRyPS6_xLx512EEES9_
	.p2align	2
_Z9erase_u64RNSt3__15dequeIyNS_9allocatorIyEEEENS_16__deque_iteratorIyPyRyPS6_xLx512EEES9_: // @_Z9erase_u64RNSt3__15dequeIyNS_9allocatorIyEEEENS_16__deque_iteratorIyPyRyPS6_xLx512EEES9_
// %bb.0:
	b	_ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_
                                        // -- End function
	.def	_ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_,"xr",discard,_ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_
	.globl	_ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_ // -- Begin function _ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_
	.p2align	2
_ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_: // @_ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_
.seh_proc _ZNSt3__15dequeIyNS_9allocatorIyEEE5eraseENS_16__deque_iteratorIyPKyRS5_PKS6_xLx512EEESA_
// %bb.0:
	sub	sp, sp, #64
	.seh_stackalloc	64
	stp	x19, x20, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x19, 16
	stp	x21, x22, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x21, 32
	str	x30, [sp, #48]                  // 8-byte Spill
	.seh_save_reg	x30, 48
	.seh_endprologue
	mov	x8, x1
	cmp	x4, x2
	mov	x19, x0
	b.eq	.LBB5_6
// %bb.1:
	ldr	x9, [x3]
	sub	x10, x3, x8
	ldr	x11, [x8]
	sub	x9, x4, x9
	asr	x9, x9, #3
	add	x9, x9, x10, lsl #6
	sub	x10, x2, x11
	sub	x22, x9, x10, asr #3
	ldr	x10, [x19, #32]
	ldp	x9, x11, [x19, #8]
	lsr	x12, x10, #9
	cmp	x9, x11
	add	x0, x9, x12, lsl #3
	b.eq	.LBB5_7
.LBB5_2:
	ldr	x12, [x0]
	and	x13, x10, #0x1ff
	add	x1, x12, x13, lsl #3
	cmp	x2, x1
	b.eq	.LBB5_8
.LBB5_3:
	ldr	x12, [x8]
	sub	x8, x8, x0
	ldr	x13, [x0]
	sub	x12, x2, x12
	asr	x12, x12, #3
	add	x8, x12, x8, lsl #6
	sub	x12, x1, x13
	subs	x20, x8, x12, asr #3
	b.eq	.LBB5_9
// %bb.4:
	cmp	x8, #1
	b.lt	.LBB5_10
// %bb.5:
	lsr	x12, x8, #9
	add	x2, x0, x12, lsl #3
	b	.LBB5_11
.LBB5_6:
	mov	x22, xzr
	ldr	x10, [x19, #32]
	ldp	x9, x11, [x19, #8]
	lsr	x12, x10, #9
	cmp	x9, x11
	add	x0, x9, x12, lsl #3
	b.ne	.LBB5_2
.LBB5_7:
	mov	x1, xzr
	cmp	x2, xzr
	b.ne	.LBB5_3
.LBB5_8:
	mov	x20, xzr
.LBB5_9:
	mov	w21, #1                         // =0x1
	mov	x3, x1
	mov	x2, x0
	cmp	x22, #1
	b.ge	.LBB5_12
	b	.LBB5_26
.LBB5_10:
	mov	w12, #511                       // =0x1ff
	sub	x8, x12, x8
	lsr	x12, x8, #9
	mvn	w8, w8
	sub	x2, x0, x12, lsl #3
.LBB5_11:
	ldr	x12, [x2]
	and	x8, x8, #0x1ff
	mov	w21, wzr
	add	x3, x12, x8, lsl #3
	cmp	x22, #1
	b.lt	.LBB5_26
.LBB5_12:
	ldr	x12, [x2]
	ldr	x8, [x19, #40]
	sub	x12, x3, x12
	sub	x13, x8, x22
	add	x12, x22, x12, asr #3
	cmp	x20, x13, lsr #1
	b.ls	.LBB5_15
// %bb.13:
	cmp	x12, #1
	b.lt	.LBB5_17
// %bb.14:
	lsr	x13, x12, #9
	add	x0, x2, x13, lsl #3
	b	.LBB5_18
.LBB5_15:
	cmp	x12, #1
	b.lt	.LBB5_20
// %bb.16:
	lsr	x8, x12, #9
	and	x10, x12, #0x1ff
	add	x8, x2, x8, lsl #3
	ldr	x9, [x8]
	add	x9, x9, x10, lsl #3
	b	.LBB5_21
.LBB5_17:
	mov	w13, #511                       // =0x1ff
	sub	x12, x13, x12
	lsr	x13, x12, #9
	mvn	w12, w12
	sub	x0, x2, x13, lsl #3
.LBB5_18:
	add	x10, x8, x10
	ldr	x13, [x0]
	and	x12, x12, #0x1ff
	lsr	x8, x10, #9
	cmp	x9, x11
	add	x1, x13, x12, lsl #3
	add	x8, x9, x8, lsl #3
	b.eq	.LBB5_23
// %bb.19:
	ldr	x9, [x8]
	and	x10, x10, #0x1ff
	add	x9, x9, x10, lsl #3
	b	.LBB5_24
.LBB5_20:
	mov	w8, #511                        // =0x1ff
	sub	x9, x8, x12
	lsr	x8, x9, #9
	mvn	w9, w9
	and	x9, x9, #0x1ff
	sub	x8, x2, x8, lsl #3
	ldr	x10, [x8]
	add	x9, x10, x9, lsl #3
.LBB5_21:
	mov	x4, sp
	stp	x8, x9, [sp]
	bl	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	ldp	x9, x8, [x19, #32]
	sub	x8, x8, x22
	add	x10, x9, x22
	ldr	x9, [x19, #8]
	cmp	x10, #1024
	stp	x10, x8, [x19, #32]
	b.lo	.LBB5_26
.LBB5_22:                               // =>This Inner Loop Header: Depth=1
	ldr	x0, [x9]
	bl	_ZdlPv
	ldr	x10, [x19, #32]
	ldr	x8, [x19, #8]
	sub	x10, x10, #512
	add	x9, x8, #8
	cmp	x10, #1024
	str	x9, [x19, #8]
	str	x10, [x19, #32]
	b.hs	.LBB5_22
	b	.LBB5_26
.LBB5_23:
	mov	x9, xzr
.LBB5_24:
	stp	x2, x3, [sp]
	mov	x4, sp
	mov	x2, x8
	mov	x3, x9
	bl	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	ldp	x9, x8, [x19, #8]
	subs	x10, x8, x9
	lsl	x11, x10, #6
	ldp	x10, x12, [x19, #32]
	cmp	x8, x9
	sub	x11, x11, #1
	sub	x12, x12, x22
	csel	x11, xzr, x11, eq
	add	x13, x12, x10
	str	x12, [x19, #40]
	sub	x11, x11, x13
	cmp	x11, #1024
	b.lo	.LBB5_26
.LBB5_25:                               // =>This Inner Loop Header: Depth=1
	ldur	x0, [x8, #-8]
	bl	_ZdlPv
	ldp	x9, x8, [x19, #8]
	sub	x8, x8, #8
	subs	x10, x8, x9
	str	x8, [x19, #16]
	lsl	x11, x10, #6
	ldp	x10, x12, [x19, #32]
	cmp	x8, x9
	sub	x11, x11, #1
	csel	x11, xzr, x11, eq
	add	x12, x12, x10
	sub	x11, x11, x12
	cmp	x11, #1023
	b.hi	.LBB5_25
.LBB5_26:
	lsr	x8, x10, #9
	ldr	x11, [x19, #16]
	add	x0, x9, x8, lsl #3
	cmp	x9, x11
	b.eq	.LBB5_28
// %bb.27:
	ldr	x8, [x0]
	and	x9, x10, #0x1ff
	add	x1, x8, x9, lsl #3
	tbz	w21, #0, .LBB5_29
	b	.LBB5_33
.LBB5_28:
	mov	x1, xzr
	tbnz	w21, #0, .LBB5_33
.LBB5_29:
	ldr	x8, [x0]
	sub	x8, x1, x8
	add	x8, x20, x8, asr #3
	cmp	x8, #1
	b.lt	.LBB5_31
// %bb.30:
	lsr	x9, x8, #9
	add	x0, x0, x9, lsl #3
	b	.LBB5_32
.LBB5_31:
	mov	w9, #511                        // =0x1ff
	sub	x8, x9, x8
	lsr	x9, x8, #9
	mvn	w8, w8
	sub	x0, x0, x9, lsl #3
.LBB5_32:
	ldr	x9, [x0]
	and	x8, x8, #0x1ff
	add	x1, x9, x8, lsl #3
.LBB5_33:
	.seh_startepilogue
	ldr	x30, [sp, #48]                  // 8-byte Reload
	.seh_save_reg	x30, 48
	ldp	x21, x22, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x21, 32
	ldp	x19, x20, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x19, 16
	add	sp, sp, #64
	.seh_stackalloc	64
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_,"xr",discard,_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.globl	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_ // -- Begin function _ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.p2align	2
_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_: // @_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
.seh_proc _ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
// %bb.0:
	stp	x19, x20, [sp, #-96]!           // 16-byte Folded Spill
	.seh_save_regp_x	x19, 96
	stp	x21, x22, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x21, 16
	stp	x23, x24, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x23, 32
	stp	x25, x26, [sp, #48]             // 16-byte Folded Spill
	.seh_save_regp	x25, 48
	stp	x27, x28, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x27, 64
	str	x30, [sp, #80]                  // 8-byte Spill
	.seh_save_reg	x30, 80
	.seh_endprologue
	ldp	x25, x21, [x4]
	mov	x19, x4
	cmp	x0, x2
	mov	x20, x1
	b.eq	.LBB6_18
// %bb.1:
	ldr	x26, [x2]
	mov	x23, x2
	mov	x22, x0
	cmp	x26, x3
	b.eq	.LBB6_7
// %bb.2:
	ldr	x8, [x25]
	sub	x9, x3, x26
	asr	x9, x9, #1
	sub	x8, x21, x8
	asr	x8, x8, #1
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x2, x8, #1
	sub	x24, x3, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x24
	bl	memmove
	cmp	x26, x24
	b.eq	.LBB6_5
// %bb.3:
	mov	w27, #2048                      // =0x800
.LBB6_4:                                // =>This Inner Loop Header: Depth=1
	sub	x8, x24, x26
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #1
	cmp	x8, #2048
	csel	x8, x8, x27, lt
	lsl	x2, x8, #1
	sub	x8, x9, x2
	sub	x24, x24, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x24
	mov	x0, x21
	bl	memmove
	cmp	x26, x24
	b.ne	.LBB6_4
.LBB6_5:
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB6_7
// %bb.6:
	ldr	x21, [x25, #8]!
.LBB6_7:
	sub	x24, x23, #8
	stp	x25, x21, [x19]
	cmp	x22, x24
	b.eq	.LBB6_14
// %bb.8:
	mov	w26, #2048                      // =0x800
	b	.LBB6_10
.LBB6_9:                                //   in Loop: Header=BB6_10 Depth=1
	sub	x24, x24, #8
	stp	x25, x21, [x19]
	cmp	x22, x24
	b.eq	.LBB6_14
.LBB6_10:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB6_11 Depth 2
	ldr	x8, [x25]
	ldr	x28, [x24]
	sub	x8, x21, x8
	asr	x8, x8, #1
	cmp	x8, #2048
	csel	x8, x8, x26, lt
	lsl	x2, x8, #1
	mov	w8, #4096                       // =0x1000
	sub	x27, x8, x2
	sub	x21, x21, x2
	add	x1, x28, x27
	mov	x0, x21
	add	x23, x28, x27
	bl	memmove
	cbz	x27, .LBB6_12
.LBB6_11:                               //   Parent Loop BB6_10 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x8, x23, x28
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #1
	cmp	x8, #2048
	csel	x8, x8, x26, lt
	lsl	x2, x8, #1
	sub	x8, x9, x2
	sub	x23, x23, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x23
	mov	x0, x21
	bl	memmove
	cmp	x28, x23
	b.ne	.LBB6_11
.LBB6_12:                               //   in Loop: Header=BB6_10 Depth=1
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB6_9
// %bb.13:                              //   in Loop: Header=BB6_10 Depth=1
	ldr	x21, [x25, #8]!
	b	.LBB6_9
.LBB6_14:
	ldr	x8, [x24]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x20, x8
	b.eq	.LBB6_24
// %bb.15:
	ldr	x9, [x25]
	sub	x10, x8, x20
	asr	x10, x10, #1
	sub	x9, x21, x9
	asr	x9, x9, #1
	cmp	x10, x9
	csel	x9, x10, x9, lt
	lsl	x2, x9, #1
	sub	x22, x8, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x22
	bl	memmove
	cmp	x20, x22
	b.eq	.LBB6_22
// %bb.16:
	mov	w23, #2048                      // =0x800
.LBB6_17:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x20
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #1
	cmp	x8, #2048
	csel	x8, x8, x23, lt
	lsl	x2, x8, #1
	sub	x8, x9, x2
	sub	x22, x22, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x22
	mov	x0, x21
	bl	memmove
	cmp	x20, x22
	b.ne	.LBB6_17
	b	.LBB6_22
.LBB6_18:
	cmp	x20, x3
	b.eq	.LBB6_24
// %bb.19:
	ldr	x8, [x25]
	sub	x9, x3, x20
	asr	x9, x9, #1
	sub	x8, x21, x8
	asr	x8, x8, #1
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x2, x8, #1
	sub	x22, x3, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x22
	bl	memmove
	cmp	x20, x22
	b.eq	.LBB6_22
// %bb.20:
	mov	w23, #2048                      // =0x800
.LBB6_21:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x20
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #1
	cmp	x8, #2048
	csel	x8, x8, x23, lt
	lsl	x2, x8, #1
	sub	x8, x9, x2
	sub	x22, x22, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x22
	mov	x0, x21
	bl	memmove
	cmp	x20, x22
	b.ne	.LBB6_21
.LBB6_22:
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB6_24
// %bb.23:
	ldr	x21, [x25, #8]!
.LBB6_24:
	stp	x25, x21, [x19]
	.seh_startepilogue
	ldr	x30, [sp, #80]                  // 8-byte Reload
	.seh_save_reg	x30, 80
	ldp	x27, x28, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x27, 64
	ldp	x25, x26, [sp, #48]             // 16-byte Folded Reload
	.seh_save_regp	x25, 48
	ldp	x23, x24, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x23, 32
	ldp	x21, x22, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x21, 16
	ldp	x19, x20, [sp], #96             // 16-byte Folded Reload
	.seh_save_regp_x	x19, 96
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_,"xr",discard,_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.globl	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_ // -- Begin function _ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.p2align	2
_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_: // @_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
.seh_proc _ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorItPtRtPS2_xLx2048EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
// %bb.0:
	stp	x19, x20, [sp, #-96]!           // 16-byte Folded Spill
	.seh_save_regp_x	x19, 96
	stp	x21, x22, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x21, 16
	stp	x23, x24, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x23, 32
	stp	x25, x26, [sp, #48]             // 16-byte Folded Spill
	.seh_save_regp	x25, 48
	stp	x27, x28, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x27, 64
	str	x30, [sp, #80]                  // 8-byte Spill
	.seh_save_reg	x30, 80
	.seh_endprologue
	mov	x19, x4
	mov	x20, x3
	cmp	x0, x2
	str	x2, [sp, #88]                   // 8-byte Spill
	b.eq	.LBB7_22
// %bb.1:
	ldr	x8, [x0]
	ldp	x26, x21, [x19]
	mov	x23, x0
	add	x22, x8, #1, lsl #12            // =4096
	cmp	x1, x22
	b.eq	.LBB7_7
// %bb.2:
	ldr	x8, [x26]
	sub	x9, x22, x1
	mov	x0, x21
	asr	x9, x9, #1
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #1
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x24, x8, #1
	mov	x2, x24
	add	x25, x1, x24
	bl	memmove
	cmp	x22, x25
	b.eq	.LBB7_5
// %bb.3:
	mov	x1, x25
	mov	w25, #2048                      // =0x800
.LBB7_4:                                // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x1
	ldr	x21, [x26, #8]!
	asr	x8, x8, #1
	mov	x0, x21
	cmp	x8, #2048
	csel	x8, x8, x25, lt
	lsl	x24, x8, #1
	mov	x2, x24
	add	x27, x1, x24
	bl	memmove
	cmp	x22, x27
	mov	x1, x27
	b.ne	.LBB7_4
.LBB7_5:
	ldr	x8, [x26]
	add	x21, x21, x24
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB7_7
// %bb.6:
	ldr	x21, [x26, #8]!
.LBB7_7:
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x23, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.eq	.LBB7_15
// %bb.8:
	mov	w28, #2048                      // =0x800
	mov	w22, #4096                      // =0x1000
	b	.LBB7_11
.LBB7_9:                                //   in Loop: Header=BB7_11 Depth=1
	ldr	x8, [x26]
	add	x21, x21, x24
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.eq	.LBB7_14
// %bb.10:                              //   in Loop: Header=BB7_11 Depth=1
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x27, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.eq	.LBB7_15
.LBB7_11:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB7_12 Depth 2
	ldr	x8, [x26]
	ldr	x23, [x27]
	mov	x0, x21
	sub	x8, x8, x21
	mov	x1, x23
	add	x8, x8, #1, lsl #12             // =4096
	asr	x25, x8, #1
	cmp	x25, #2048
	csel	x8, x25, x28, lt
	lsl	x24, x8, #1
	mov	x2, x24
	bl	memmove
	cmp	x25, #2047
	b.gt	.LBB7_9
.LBB7_12:                               //   Parent Loop BB7_11 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x9, x22, x24
	ldr	x21, [x26, #8]!
	asr	x9, x9, #1
	add	x1, x23, x24
	mov	x0, x21
	cmp	x9, #2048
	csel	x9, x9, x28, lt
	lsl	x25, x9, #1
	mov	x2, x25
	add	x24, x25, x24
	bl	memmove
	cmp	x24, #1, lsl #12                // =4096
	b.ne	.LBB7_12
// %bb.13:                              //   in Loop: Header=BB7_11 Depth=1
	mov	x24, x25
	b	.LBB7_9
.LBB7_14:                               //   in Loop: Header=BB7_11 Depth=1
	ldr	x21, [x26, #8]!
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x27, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.ne	.LBB7_11
.LBB7_15:
	ldr	x1, [x27]
	cmp	x1, x20
	b.eq	.LBB7_21
// %bb.16:
	ldr	x8, [x26]
	sub	x9, x20, x1
	mov	x0, x21
	asr	x9, x9, #1
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #1
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x22, x8, #1
	mov	x2, x22
	add	x23, x1, x22
	bl	memmove
	cmp	x20, x23
	b.eq	.LBB7_19
// %bb.17:
	mov	x1, x23
	mov	w23, #2048                      // =0x800
.LBB7_18:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x20, x1
	ldr	x21, [x26, #8]!
	asr	x8, x8, #1
	mov	x0, x21
	cmp	x8, #2048
	csel	x8, x8, x23, lt
	lsl	x22, x8, #1
	mov	x2, x22
	add	x24, x1, x22
	bl	memmove
	cmp	x20, x24
	mov	x1, x24
	b.ne	.LBB7_18
.LBB7_19:
	ldr	x8, [x26]
	add	x21, x21, x22
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB7_21
// %bb.20:
	ldr	x21, [x26, #8]!
.LBB7_21:
	str	x26, [x19]
	b	.LBB7_29
.LBB7_22:
	ldp	x23, x21, [x19]
	cmp	x1, x20
	b.eq	.LBB7_28
// %bb.23:
	ldr	x8, [x23]
	sub	x9, x20, x1
	mov	x0, x21
	asr	x9, x9, #1
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #1
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x22, x8, #1
	mov	x2, x22
	add	x24, x1, x22
	bl	memmove
	cmp	x20, x24
	b.eq	.LBB7_26
// %bb.24:
	mov	x1, x24
	mov	w24, #2048                      // =0x800
.LBB7_25:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x20, x1
	ldr	x21, [x23, #8]!
	asr	x8, x8, #1
	mov	x0, x21
	cmp	x8, #2048
	csel	x8, x8, x24, lt
	lsl	x22, x8, #1
	mov	x2, x22
	add	x25, x1, x22
	bl	memmove
	cmp	x20, x25
	mov	x1, x25
	b.ne	.LBB7_25
.LBB7_26:
	ldr	x8, [x23]
	add	x21, x21, x22
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB7_28
// %bb.27:
	ldr	x21, [x23, #8]!
.LBB7_28:
	str	x23, [x19]
.LBB7_29:
	str	x21, [x19, #8]
	.seh_startepilogue
	ldr	x30, [sp, #80]                  // 8-byte Reload
	.seh_save_reg	x30, 80
	ldp	x27, x28, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x27, 64
	ldp	x25, x26, [sp, #48]             // 16-byte Folded Reload
	.seh_save_regp	x25, 48
	ldp	x23, x24, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x23, 32
	ldp	x21, x22, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x21, 16
	ldp	x19, x20, [sp], #96             // 16-byte Folded Reload
	.seh_save_regp_x	x19, 96
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_,"xr",discard,_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.globl	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_ // -- Begin function _ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.p2align	2
_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_: // @_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
.seh_proc _ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
// %bb.0:
	stp	x19, x20, [sp, #-96]!           // 16-byte Folded Spill
	.seh_save_regp_x	x19, 96
	stp	x21, x22, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x21, 16
	stp	x23, x24, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x23, 32
	stp	x25, x26, [sp, #48]             // 16-byte Folded Spill
	.seh_save_regp	x25, 48
	stp	x27, x28, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x27, 64
	str	x30, [sp, #80]                  // 8-byte Spill
	.seh_save_reg	x30, 80
	.seh_endprologue
	ldp	x25, x21, [x4]
	mov	x19, x4
	cmp	x0, x2
	mov	x20, x1
	b.eq	.LBB8_18
// %bb.1:
	ldr	x26, [x2]
	mov	x23, x2
	mov	x22, x0
	cmp	x26, x3
	b.eq	.LBB8_7
// %bb.2:
	ldr	x8, [x25]
	sub	x9, x3, x26
	asr	x9, x9, #2
	sub	x8, x21, x8
	asr	x8, x8, #2
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x2, x8, #2
	sub	x24, x3, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x24
	bl	memmove
	cmp	x26, x24
	b.eq	.LBB8_5
// %bb.3:
	mov	w27, #1024                      // =0x400
.LBB8_4:                                // =>This Inner Loop Header: Depth=1
	sub	x8, x24, x26
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #2
	cmp	x8, #1024
	csel	x8, x8, x27, lt
	lsl	x2, x8, #2
	sub	x8, x9, x2
	sub	x24, x24, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x24
	mov	x0, x21
	bl	memmove
	cmp	x26, x24
	b.ne	.LBB8_4
.LBB8_5:
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB8_7
// %bb.6:
	ldr	x21, [x25, #8]!
.LBB8_7:
	sub	x24, x23, #8
	stp	x25, x21, [x19]
	cmp	x22, x24
	b.eq	.LBB8_14
// %bb.8:
	mov	w26, #1024                      // =0x400
	b	.LBB8_10
.LBB8_9:                                //   in Loop: Header=BB8_10 Depth=1
	sub	x24, x24, #8
	stp	x25, x21, [x19]
	cmp	x22, x24
	b.eq	.LBB8_14
.LBB8_10:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB8_11 Depth 2
	ldr	x8, [x25]
	ldr	x28, [x24]
	sub	x8, x21, x8
	asr	x8, x8, #2
	cmp	x8, #1024
	csel	x8, x8, x26, lt
	lsl	x2, x8, #2
	mov	w8, #4096                       // =0x1000
	sub	x27, x8, x2
	sub	x21, x21, x2
	add	x1, x28, x27
	mov	x0, x21
	add	x23, x28, x27
	bl	memmove
	cbz	x27, .LBB8_12
.LBB8_11:                               //   Parent Loop BB8_10 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x8, x23, x28
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #2
	cmp	x8, #1024
	csel	x8, x8, x26, lt
	lsl	x2, x8, #2
	sub	x8, x9, x2
	sub	x23, x23, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x23
	mov	x0, x21
	bl	memmove
	cmp	x28, x23
	b.ne	.LBB8_11
.LBB8_12:                               //   in Loop: Header=BB8_10 Depth=1
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB8_9
// %bb.13:                              //   in Loop: Header=BB8_10 Depth=1
	ldr	x21, [x25, #8]!
	b	.LBB8_9
.LBB8_14:
	ldr	x8, [x24]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x20, x8
	b.eq	.LBB8_24
// %bb.15:
	ldr	x9, [x25]
	sub	x10, x8, x20
	asr	x10, x10, #2
	sub	x9, x21, x9
	asr	x9, x9, #2
	cmp	x10, x9
	csel	x9, x10, x9, lt
	lsl	x2, x9, #2
	sub	x22, x8, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x22
	bl	memmove
	cmp	x20, x22
	b.eq	.LBB8_22
// %bb.16:
	mov	w23, #1024                      // =0x400
.LBB8_17:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x20
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #2
	cmp	x8, #1024
	csel	x8, x8, x23, lt
	lsl	x2, x8, #2
	sub	x8, x9, x2
	sub	x22, x22, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x22
	mov	x0, x21
	bl	memmove
	cmp	x20, x22
	b.ne	.LBB8_17
	b	.LBB8_22
.LBB8_18:
	cmp	x20, x3
	b.eq	.LBB8_24
// %bb.19:
	ldr	x8, [x25]
	sub	x9, x3, x20
	asr	x9, x9, #2
	sub	x8, x21, x8
	asr	x8, x8, #2
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x2, x8, #2
	sub	x22, x3, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x22
	bl	memmove
	cmp	x20, x22
	b.eq	.LBB8_22
// %bb.20:
	mov	w23, #1024                      // =0x400
.LBB8_21:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x20
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #2
	cmp	x8, #1024
	csel	x8, x8, x23, lt
	lsl	x2, x8, #2
	sub	x8, x9, x2
	sub	x22, x22, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x22
	mov	x0, x21
	bl	memmove
	cmp	x20, x22
	b.ne	.LBB8_21
.LBB8_22:
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB8_24
// %bb.23:
	ldr	x21, [x25, #8]!
.LBB8_24:
	stp	x25, x21, [x19]
	.seh_startepilogue
	ldr	x30, [sp, #80]                  // 8-byte Reload
	.seh_save_reg	x30, 80
	ldp	x27, x28, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x27, 64
	ldp	x25, x26, [sp, #48]             // 16-byte Folded Reload
	.seh_save_regp	x25, 48
	ldp	x23, x24, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x23, 32
	ldp	x21, x22, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x21, 16
	ldp	x19, x20, [sp], #96             // 16-byte Folded Reload
	.seh_save_regp_x	x19, 96
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_,"xr",discard,_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.globl	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_ // -- Begin function _ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.p2align	2
_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_: // @_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
.seh_proc _ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIjPjRjPS2_xLx1024EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
// %bb.0:
	stp	x19, x20, [sp, #-96]!           // 16-byte Folded Spill
	.seh_save_regp_x	x19, 96
	stp	x21, x22, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x21, 16
	stp	x23, x24, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x23, 32
	stp	x25, x26, [sp, #48]             // 16-byte Folded Spill
	.seh_save_regp	x25, 48
	stp	x27, x28, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x27, 64
	str	x30, [sp, #80]                  // 8-byte Spill
	.seh_save_reg	x30, 80
	.seh_endprologue
	mov	x19, x4
	mov	x20, x3
	cmp	x0, x2
	str	x2, [sp, #88]                   // 8-byte Spill
	b.eq	.LBB9_22
// %bb.1:
	ldr	x8, [x0]
	ldp	x26, x21, [x19]
	mov	x23, x0
	add	x22, x8, #1, lsl #12            // =4096
	cmp	x1, x22
	b.eq	.LBB9_7
// %bb.2:
	ldr	x8, [x26]
	sub	x9, x22, x1
	mov	x0, x21
	asr	x9, x9, #2
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #2
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x24, x8, #2
	mov	x2, x24
	add	x25, x1, x24
	bl	memmove
	cmp	x22, x25
	b.eq	.LBB9_5
// %bb.3:
	mov	x1, x25
	mov	w25, #1024                      // =0x400
.LBB9_4:                                // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x1
	ldr	x21, [x26, #8]!
	asr	x8, x8, #2
	mov	x0, x21
	cmp	x8, #1024
	csel	x8, x8, x25, lt
	lsl	x24, x8, #2
	mov	x2, x24
	add	x27, x1, x24
	bl	memmove
	cmp	x22, x27
	mov	x1, x27
	b.ne	.LBB9_4
.LBB9_5:
	ldr	x8, [x26]
	add	x21, x21, x24
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB9_7
// %bb.6:
	ldr	x21, [x26, #8]!
.LBB9_7:
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x23, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.eq	.LBB9_15
// %bb.8:
	mov	w28, #1024                      // =0x400
	mov	w22, #4096                      // =0x1000
	b	.LBB9_11
.LBB9_9:                                //   in Loop: Header=BB9_11 Depth=1
	ldr	x8, [x26]
	add	x21, x21, x24
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.eq	.LBB9_14
// %bb.10:                              //   in Loop: Header=BB9_11 Depth=1
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x27, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.eq	.LBB9_15
.LBB9_11:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB9_12 Depth 2
	ldr	x8, [x26]
	ldr	x23, [x27]
	mov	x0, x21
	sub	x8, x8, x21
	mov	x1, x23
	add	x8, x8, #1, lsl #12             // =4096
	asr	x25, x8, #2
	cmp	x25, #1024
	csel	x8, x25, x28, lt
	lsl	x24, x8, #2
	mov	x2, x24
	bl	memmove
	cmp	x25, #1023
	b.gt	.LBB9_9
.LBB9_12:                               //   Parent Loop BB9_11 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x9, x22, x24
	ldr	x21, [x26, #8]!
	asr	x9, x9, #2
	add	x1, x23, x24
	mov	x0, x21
	cmp	x9, #1024
	csel	x9, x9, x28, lt
	lsl	x25, x9, #2
	mov	x2, x25
	add	x24, x25, x24
	bl	memmove
	cmp	x24, #1, lsl #12                // =4096
	b.ne	.LBB9_12
// %bb.13:                              //   in Loop: Header=BB9_11 Depth=1
	mov	x24, x25
	b	.LBB9_9
.LBB9_14:                               //   in Loop: Header=BB9_11 Depth=1
	ldr	x21, [x26, #8]!
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x27, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.ne	.LBB9_11
.LBB9_15:
	ldr	x1, [x27]
	cmp	x1, x20
	b.eq	.LBB9_21
// %bb.16:
	ldr	x8, [x26]
	sub	x9, x20, x1
	mov	x0, x21
	asr	x9, x9, #2
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #2
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x22, x8, #2
	mov	x2, x22
	add	x23, x1, x22
	bl	memmove
	cmp	x20, x23
	b.eq	.LBB9_19
// %bb.17:
	mov	x1, x23
	mov	w23, #1024                      // =0x400
.LBB9_18:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x20, x1
	ldr	x21, [x26, #8]!
	asr	x8, x8, #2
	mov	x0, x21
	cmp	x8, #1024
	csel	x8, x8, x23, lt
	lsl	x22, x8, #2
	mov	x2, x22
	add	x24, x1, x22
	bl	memmove
	cmp	x20, x24
	mov	x1, x24
	b.ne	.LBB9_18
.LBB9_19:
	ldr	x8, [x26]
	add	x21, x21, x22
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB9_21
// %bb.20:
	ldr	x21, [x26, #8]!
.LBB9_21:
	str	x26, [x19]
	b	.LBB9_29
.LBB9_22:
	ldp	x23, x21, [x19]
	cmp	x1, x20
	b.eq	.LBB9_28
// %bb.23:
	ldr	x8, [x23]
	sub	x9, x20, x1
	mov	x0, x21
	asr	x9, x9, #2
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #2
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x22, x8, #2
	mov	x2, x22
	add	x24, x1, x22
	bl	memmove
	cmp	x20, x24
	b.eq	.LBB9_26
// %bb.24:
	mov	x1, x24
	mov	w24, #1024                      // =0x400
.LBB9_25:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x20, x1
	ldr	x21, [x23, #8]!
	asr	x8, x8, #2
	mov	x0, x21
	cmp	x8, #1024
	csel	x8, x8, x24, lt
	lsl	x22, x8, #2
	mov	x2, x22
	add	x25, x1, x22
	bl	memmove
	cmp	x20, x25
	mov	x1, x25
	b.ne	.LBB9_25
.LBB9_26:
	ldr	x8, [x23]
	add	x21, x21, x22
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB9_28
// %bb.27:
	ldr	x21, [x23, #8]!
.LBB9_28:
	str	x23, [x19]
.LBB9_29:
	str	x21, [x19, #8]
	.seh_startepilogue
	ldr	x30, [sp, #80]                  // 8-byte Reload
	.seh_save_reg	x30, 80
	ldp	x27, x28, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x27, 64
	ldp	x25, x26, [sp, #48]             // 16-byte Folded Reload
	.seh_save_regp	x25, 48
	ldp	x23, x24, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x23, 32
	ldp	x21, x22, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x21, 16
	ldp	x19, x20, [sp], #96             // 16-byte Folded Reload
	.seh_save_regp_x	x19, 96
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_,"xr",discard,_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.globl	_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_ // -- Begin function _ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.p2align	2
_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_: // @_ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
.seh_proc _ZNSt3__127__for_each_segment_backwardB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_20__move_backward_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
// %bb.0:
	stp	x19, x20, [sp, #-96]!           // 16-byte Folded Spill
	.seh_save_regp_x	x19, 96
	stp	x21, x22, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x21, 16
	stp	x23, x24, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x23, 32
	stp	x25, x26, [sp, #48]             // 16-byte Folded Spill
	.seh_save_regp	x25, 48
	stp	x27, x28, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x27, 64
	str	x30, [sp, #80]                  // 8-byte Spill
	.seh_save_reg	x30, 80
	.seh_endprologue
	ldp	x25, x21, [x4]
	mov	x19, x4
	cmp	x0, x2
	mov	x20, x1
	b.eq	.LBB10_18
// %bb.1:
	ldr	x26, [x2]
	mov	x23, x2
	mov	x22, x0
	cmp	x26, x3
	b.eq	.LBB10_7
// %bb.2:
	ldr	x8, [x25]
	sub	x9, x3, x26
	asr	x9, x9, #3
	sub	x8, x21, x8
	asr	x8, x8, #3
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x2, x8, #3
	sub	x24, x3, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x24
	bl	memmove
	cmp	x26, x24
	b.eq	.LBB10_5
// %bb.3:
	mov	w27, #512                       // =0x200
.LBB10_4:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x24, x26
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #3
	cmp	x8, #512
	csel	x8, x8, x27, lt
	lsl	x2, x8, #3
	sub	x8, x9, x2
	sub	x24, x24, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x24
	mov	x0, x21
	bl	memmove
	cmp	x26, x24
	b.ne	.LBB10_4
.LBB10_5:
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB10_7
// %bb.6:
	ldr	x21, [x25, #8]!
.LBB10_7:
	sub	x24, x23, #8
	stp	x25, x21, [x19]
	cmp	x22, x24
	b.eq	.LBB10_14
// %bb.8:
	mov	w26, #512                       // =0x200
	b	.LBB10_10
.LBB10_9:                               //   in Loop: Header=BB10_10 Depth=1
	sub	x24, x24, #8
	stp	x25, x21, [x19]
	cmp	x22, x24
	b.eq	.LBB10_14
.LBB10_10:                              // =>This Loop Header: Depth=1
                                        //     Child Loop BB10_11 Depth 2
	ldr	x8, [x25]
	ldr	x28, [x24]
	sub	x8, x21, x8
	asr	x8, x8, #3
	cmp	x8, #512
	csel	x8, x8, x26, lt
	lsl	x2, x8, #3
	mov	w8, #4096                       // =0x1000
	sub	x27, x8, x2
	sub	x21, x21, x2
	add	x1, x28, x27
	mov	x0, x21
	add	x23, x28, x27
	bl	memmove
	cbz	x27, .LBB10_12
.LBB10_11:                              //   Parent Loop BB10_10 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x8, x23, x28
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #3
	cmp	x8, #512
	csel	x8, x8, x26, lt
	lsl	x2, x8, #3
	sub	x8, x9, x2
	sub	x23, x23, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x23
	mov	x0, x21
	bl	memmove
	cmp	x28, x23
	b.ne	.LBB10_11
.LBB10_12:                              //   in Loop: Header=BB10_10 Depth=1
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB10_9
// %bb.13:                              //   in Loop: Header=BB10_10 Depth=1
	ldr	x21, [x25, #8]!
	b	.LBB10_9
.LBB10_14:
	ldr	x8, [x24]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x20, x8
	b.eq	.LBB10_24
// %bb.15:
	ldr	x9, [x25]
	sub	x10, x8, x20
	asr	x10, x10, #3
	sub	x9, x21, x9
	asr	x9, x9, #3
	cmp	x10, x9
	csel	x9, x10, x9, lt
	lsl	x2, x9, #3
	sub	x22, x8, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x22
	bl	memmove
	cmp	x20, x22
	b.eq	.LBB10_22
// %bb.16:
	mov	w23, #512                       // =0x200
.LBB10_17:                              // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x20
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #3
	cmp	x8, #512
	csel	x8, x8, x23, lt
	lsl	x2, x8, #3
	sub	x8, x9, x2
	sub	x22, x22, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x22
	mov	x0, x21
	bl	memmove
	cmp	x20, x22
	b.ne	.LBB10_17
	b	.LBB10_22
.LBB10_18:
	cmp	x20, x3
	b.eq	.LBB10_24
// %bb.19:
	ldr	x8, [x25]
	sub	x9, x3, x20
	asr	x9, x9, #3
	sub	x8, x21, x8
	asr	x8, x8, #3
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x2, x8, #3
	sub	x22, x3, x2
	sub	x21, x21, x2
	mov	x0, x21
	mov	x1, x22
	bl	memmove
	cmp	x20, x22
	b.eq	.LBB10_22
// %bb.20:
	mov	w23, #512                       // =0x200
.LBB10_21:                              // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x20
	ldr	x9, [x25, #-8]!
	asr	x8, x8, #3
	cmp	x8, #512
	csel	x8, x8, x23, lt
	lsl	x2, x8, #3
	sub	x8, x9, x2
	sub	x22, x22, x2
	add	x21, x8, #1, lsl #12            // =4096
	mov	x1, x22
	mov	x0, x21
	bl	memmove
	cmp	x20, x22
	b.ne	.LBB10_21
.LBB10_22:
	ldr	x8, [x25]
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB10_24
// %bb.23:
	ldr	x21, [x25, #8]!
.LBB10_24:
	stp	x25, x21, [x19]
	.seh_startepilogue
	ldr	x30, [sp, #80]                  // 8-byte Reload
	.seh_save_reg	x30, 80
	ldp	x27, x28, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x27, 64
	ldp	x25, x26, [sp, #48]             // 16-byte Folded Reload
	.seh_save_regp	x25, 48
	ldp	x23, x24, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x23, 32
	ldp	x21, x22, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x21, 16
	ldp	x19, x20, [sp], #96             // 16-byte Folded Reload
	.seh_save_regp_x	x19, 96
	.seh_endepilogue
	ret
	.seh_endfunclet
	.seh_endproc
                                        // -- End function
	.def	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_,"xr",discard,_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.globl	_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_ // -- Begin function _ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
	.p2align	2
_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_: // @_ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
.seh_proc _ZNSt3__118__for_each_segmentB9nqe230000INS_16__deque_iteratorIyPyRyPS2_xLx512EEEZNKS_11__move_implINS_17_ClassicAlgPolicyEEclB9nqe230000IS5_S5_TnNS_9enable_ifIX25__is_segmented_iterator_vIT_EEiE4typeELi0EEENS_4pairISB_T0_EESB_SB_SF_EUlS2_S2_E_EEvSB_SB_SF_
// %bb.0:
	stp	x19, x20, [sp, #-96]!           // 16-byte Folded Spill
	.seh_save_regp_x	x19, 96
	stp	x21, x22, [sp, #16]             // 16-byte Folded Spill
	.seh_save_regp	x21, 16
	stp	x23, x24, [sp, #32]             // 16-byte Folded Spill
	.seh_save_regp	x23, 32
	stp	x25, x26, [sp, #48]             // 16-byte Folded Spill
	.seh_save_regp	x25, 48
	stp	x27, x28, [sp, #64]             // 16-byte Folded Spill
	.seh_save_regp	x27, 64
	str	x30, [sp, #80]                  // 8-byte Spill
	.seh_save_reg	x30, 80
	.seh_endprologue
	mov	x19, x4
	mov	x20, x3
	cmp	x0, x2
	str	x2, [sp, #88]                   // 8-byte Spill
	b.eq	.LBB11_22
// %bb.1:
	ldr	x8, [x0]
	ldp	x26, x21, [x19]
	mov	x23, x0
	add	x22, x8, #1, lsl #12            // =4096
	cmp	x1, x22
	b.eq	.LBB11_7
// %bb.2:
	ldr	x8, [x26]
	sub	x9, x22, x1
	mov	x0, x21
	asr	x9, x9, #3
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #3
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x24, x8, #3
	mov	x2, x24
	add	x25, x1, x24
	bl	memmove
	cmp	x22, x25
	b.eq	.LBB11_5
// %bb.3:
	mov	x1, x25
	mov	w25, #512                       // =0x200
.LBB11_4:                               // =>This Inner Loop Header: Depth=1
	sub	x8, x22, x1
	ldr	x21, [x26, #8]!
	asr	x8, x8, #3
	mov	x0, x21
	cmp	x8, #512
	csel	x8, x8, x25, lt
	lsl	x24, x8, #3
	mov	x2, x24
	add	x27, x1, x24
	bl	memmove
	cmp	x22, x27
	mov	x1, x27
	b.ne	.LBB11_4
.LBB11_5:
	ldr	x8, [x26]
	add	x21, x21, x24
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB11_7
// %bb.6:
	ldr	x21, [x26, #8]!
.LBB11_7:
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x23, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.eq	.LBB11_15
// %bb.8:
	mov	w28, #512                       // =0x200
	mov	w22, #4096                      // =0x1000
	b	.LBB11_11
.LBB11_9:                               //   in Loop: Header=BB11_11 Depth=1
	ldr	x8, [x26]
	add	x21, x21, x24
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.eq	.LBB11_14
// %bb.10:                              //   in Loop: Header=BB11_11 Depth=1
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x27, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.eq	.LBB11_15
.LBB11_11:                              // =>This Loop Header: Depth=1
                                        //     Child Loop BB11_12 Depth 2
	ldr	x8, [x26]
	ldr	x23, [x27]
	mov	x0, x21
	sub	x8, x8, x21
	mov	x1, x23
	add	x8, x8, #1, lsl #12             // =4096
	asr	x25, x8, #3
	cmp	x25, #512
	csel	x8, x25, x28, lt
	lsl	x24, x8, #3
	mov	x2, x24
	bl	memmove
	cmp	x25, #511
	b.gt	.LBB11_9
.LBB11_12:                              //   Parent Loop BB11_11 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x9, x22, x24
	ldr	x21, [x26, #8]!
	asr	x9, x9, #3
	add	x1, x23, x24
	mov	x0, x21
	cmp	x9, #512
	csel	x9, x9, x28, lt
	lsl	x25, x9, #3
	mov	x2, x25
	add	x24, x25, x24
	bl	memmove
	cmp	x24, #1, lsl #12                // =4096
	b.ne	.LBB11_12
// %bb.13:                              //   in Loop: Header=BB11_11 Depth=1
	mov	x24, x25
	b	.LBB11_9
.LBB11_14:                              //   in Loop: Header=BB11_11 Depth=1
	ldr	x21, [x26, #8]!
	ldr	x8, [sp, #88]                   // 8-byte Reload
	add	x27, x27, #8
	stp	x26, x21, [x19]
	cmp	x27, x8
	b.ne	.LBB11_11
.LBB11_15:
	ldr	x1, [x27]
	cmp	x1, x20
	b.eq	.LBB11_21
// %bb.16:
	ldr	x8, [x26]
	sub	x9, x20, x1
	mov	x0, x21
	asr	x9, x9, #3
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #3
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x22, x8, #3
	mov	x2, x22
	add	x23, x1, x22
	bl	memmove
	cmp	x20, x23
	b.eq	.LBB11_19
// %bb.17:
	mov	x1, x23
	mov	w23, #512                       // =0x200
.LBB11_18:                              // =>This Inner Loop Header: Depth=1
	sub	x8, x20, x1
	ldr	x21, [x26, #8]!
	asr	x8, x8, #3
	mov	x0, x21
	cmp	x8, #512
	csel	x8, x8, x23, lt
	lsl	x22, x8, #3
	mov	x2, x22
	add	x24, x1, x22
	bl	memmove
	cmp	x20, x24
	mov	x1, x24
	b.ne	.LBB11_18
.LBB11_19:
	ldr	x8, [x26]
	add	x21, x21, x22
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB11_21
// %bb.20:
	ldr	x21, [x26, #8]!
.LBB11_21:
	str	x26, [x19]
	b	.LBB11_29
.LBB11_22:
	ldp	x23, x21, [x19]
	cmp	x1, x20
	b.eq	.LBB11_28
// %bb.23:
	ldr	x8, [x23]
	sub	x9, x20, x1
	mov	x0, x21
	asr	x9, x9, #3
	sub	x8, x8, x21
	add	x8, x8, #1, lsl #12             // =4096
	asr	x8, x8, #3
	cmp	x9, x8
	csel	x8, x9, x8, lt
	lsl	x22, x8, #3
	mov	x2, x22
	add	x24, x1, x22
	bl	memmove
	cmp	x20, x24
	b.eq	.LBB11_26
// %bb.24:
	mov	x1, x24
	mov	w24, #512                       // =0x200
.LBB11_25:                              // =>This Inner Loop Header: Depth=1
	sub	x8, x20, x1
	ldr	x21, [x23, #8]!
	asr	x8, x8, #3
	mov	x0, x21
	cmp	x8, #512
	csel	x8, x8, x24, lt
	lsl	x22, x8, #3
	mov	x2, x22
	add	x25, x1, x22
	bl	memmove
	cmp	x20, x25
	mov	x1, x25
	b.ne	.LBB11_25
.LBB11_26:
	ldr	x8, [x23]
	add	x21, x21, x22
	add	x8, x8, #1, lsl #12             // =4096
	cmp	x21, x8
	b.ne	.LBB11_28
// %bb.27:
	ldr	x21, [x23, #8]!
.LBB11_28:
	str	x23, [x19]
.LBB11_29:
	str	x21, [x19, #8]
	.seh_startepilogue
	ldr	x30, [sp, #80]                  // 8-byte Reload
	.seh_save_reg	x30, 80
	ldp	x27, x28, [sp, #64]             // 16-byte Folded Reload
	.seh_save_regp	x27, 64
	ldp	x25, x26, [sp, #48]             // 16-byte Folded Reload
	.seh_save_regp	x25, 48
	ldp	x23, x24, [sp, #32]             // 16-byte Folded Reload
	.seh_save_regp	x23, 32
	ldp	x21, x22, [sp, #16]             // 16-byte Folded Reload
	.seh_save_regp	x21, 16
	ldp	x19, x20, [sp], #96             // 16-byte Folded Reload
	.seh_save_regp_x	x19, 96
	.seh_endepilogue
	ret
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
