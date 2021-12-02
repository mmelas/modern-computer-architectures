 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -prefetch -mfinline -mas_g -mas_G -O4 -o a.out"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
 ## Begin max
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
max::
.trace 1
	      ## auto_size == 0
	c0    cmpgt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 19,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L0?3   ## bblock 0, line 19,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 19,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 2
.trace 2
L0?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 20,  t5,  ?2.1?2auto_size(I32),  t4
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.1?2auto_size, 0x0
 ## End max
 ## Begin min
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
min::
.trace 1
	      ## auto_size == 0
	c0    cmplt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 25,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L1?3   ## bblock 0, line 25,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 25,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 2
.trace 2
L1?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 26,  t5,  ?2.2?2auto_size(I32),  t4
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.2?2auto_size, 0x0
 ## End min
 ## Begin NOP
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
NOP::
.trace 1
	      ## auto_size == 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 46,  t1,  ?2.3?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
 ## End NOP
.equ _?1TEMPLATEPACKET.5, 0x0
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
main::
.trace 11
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 64,  raddr(NOP)(P32)
	c0    stw 0x14[$r0.1] = $r0.57  ## spill ## t132
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t128
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t593,  (~0xfff)(I32)
	c0    mov $r0.3 = (conv7_result + 0)   ## bblock 1, line 0,  t592,  addr(conv7_result?1.0)(P32)
;;								## 2
.trace 3
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 89,  t1022(I1),  t593,  0(SI32)
	c0    pft 128[$r0.3]   ## [spec] bblock 35, line 90,  t592,  128(I32)
	c0    add $r0.2 = $r0.2, 32   ## [spec] bblock 35, line 0,  t593,  t593,  32(I32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 89,  t1022(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 35, line 90, t592, 0(SI32)
	c0    stw 4[$r0.3] = $r0.0   ## bblock 35, line 90-1, t592, 0(SI32)
	c0    stw 8[$r0.3] = $r0.0   ## bblock 35, line 90-2, t592, 0(SI32)
	c0    stw 12[$r0.3] = $r0.0   ## bblock 35, line 90-3, t592, 0(SI32)
	c0    stw 16[$r0.3] = $r0.0   ## bblock 35, line 90-4, t592, 0(SI32)
	c0    stw 20[$r0.3] = $r0.0   ## bblock 35, line 90-5, t592, 0(SI32)
	c0    stw 24[$r0.3] = $r0.0   ## bblock 35, line 90-6, t592, 0(SI32)
	c0    stw 28[$r0.3] = $r0.0   ## bblock 35, line 90-7, t592, 0(SI32)
	c0    stw 32[$r0.3] = $r0.0   ## bblock 35, line 90-8, t592, 0(SI32)
	c0    stw 36[$r0.3] = $r0.0   ## bblock 35, line 90-9, t592, 0(SI32)
	c0    stw 40[$r0.3] = $r0.0   ## bblock 35, line 90-10, t592, 0(SI32)
	c0    stw 44[$r0.3] = $r0.0   ## bblock 35, line 90-11, t592, 0(SI32)
	c0    stw 48[$r0.3] = $r0.0   ## bblock 35, line 90-12, t592, 0(SI32)
	c0    stw 52[$r0.3] = $r0.0   ## bblock 35, line 90-13, t592, 0(SI32)
	c0    stw 56[$r0.3] = $r0.0   ## bblock 35, line 90-14, t592, 0(SI32)
	c0    stw 60[$r0.3] = $r0.0   ## bblock 35, line 90-15, t592, 0(SI32)
	c0    stw 64[$r0.3] = $r0.0   ## bblock 35, line 90-16, t592, 0(SI32)
	c0    stw 68[$r0.3] = $r0.0   ## bblock 35, line 90-17, t592, 0(SI32)
	c0    stw 72[$r0.3] = $r0.0   ## bblock 35, line 90-18, t592, 0(SI32)
	c0    stw 76[$r0.3] = $r0.0   ## bblock 35, line 90-19, t592, 0(SI32)
	c0    stw 80[$r0.3] = $r0.0   ## bblock 35, line 90-20, t592, 0(SI32)
	c0    stw 84[$r0.3] = $r0.0   ## bblock 35, line 90-21, t592, 0(SI32)
	c0    stw 88[$r0.3] = $r0.0   ## bblock 35, line 90-22, t592, 0(SI32)
	c0    stw 92[$r0.3] = $r0.0   ## bblock 35, line 90-23, t592, 0(SI32)
	c0    stw 96[$r0.3] = $r0.0   ## bblock 35, line 90-24, t592, 0(SI32)
	c0    stw 100[$r0.3] = $r0.0   ## bblock 35, line 90-25, t592, 0(SI32)
	c0    stw 104[$r0.3] = $r0.0   ## bblock 35, line 90-26, t592, 0(SI32)
	c0    stw 108[$r0.3] = $r0.0   ## bblock 35, line 90-27, t592, 0(SI32)
	c0    stw 112[$r0.3] = $r0.0   ## bblock 35, line 90-28, t592, 0(SI32)
	c0    stw 116[$r0.3] = $r0.0   ## bblock 35, line 90-29, t592, 0(SI32)
	c0    stw 120[$r0.3] = $r0.0   ## bblock 35, line 90-30, t592, 0(SI32)
	c0    stw 124[$r0.3] = $r0.0   ## bblock 35, line 90-31, t592, 0(SI32)
;;								## 2
	c0    add $r0.3 = $r0.3, 128   ## bblock 35, line 0,  t592,  t592,  128(I32)
	c0    goto L2?3 ## goto
;;								## 3
.trace 10
L3?3:
	c0    mov $r0.8 = $r0.0   ## bblock 3, line 0,  t469,  0(I32)
	c0    mov $r0.3 = $r0.0   ## bblock 3, line 0,  t468,  0(I32)
	c0    mov $r0.57 = ((conv7_result + 0) + 1012)   ## bblock 3, line 0,  t473,  (addr(conv7_result?1.0)(P32) + 0x3f4(I32))(P32)
;;								## 0
.trace 7
L4?3:
	c0    cmplt $b0.0 = $r0.3, 58   ## bblock 4, line 98,  t1023(I1),  t468,  58(SI32)
	c0    mov $r0.4 = (~0x39)   ## [spec] bblock 7, line 0,  t443,  (~0x39)(I32)
	c0    mov $r0.7 = $r0.0   ## [spec] bblock 7, line 0,  t442,  0(I32)
;;								## 0
	c0    brf $b0.0, L5?3   ## bblock 4, line 98,  t1023(I1)
;;								## 1
.trace 5
L6?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 8, line 100,  t1024(I1),  t443,  0(SI32)
	c0    mov $r0.2 = (~0x6)   ## [spec] bblock 10, line 0,  t429,  (~0x6)(I32)
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 10, line 0,  t427,  0(I32)
	c0    mov $r0.5 = $r0.7   ## [spec] bblock 10, line 0,  t428,  t442
	c0    mov $r0.22 = $r0.0   ## [spec] bblock 10, line 102,  t153,  0(SI32)
	c0    mov $r0.17 = $r0.0   ## [spec] bblock 10, line 102,  t152,  0(SI32)
	c0    mov $r0.23 = $r0.0   ## [spec] bblock 10, line 102,  t151,  0(SI32)
	c0    mov $r0.55 = $r0.4   ## t443
	c0    mov $r0.56 = $r0.7   ## t442
;;								## 0
	c0    brf $b0.0, L7?3   ## bblock 8, line 100,  t1024(I1)
;;								## 1
.trace 1
L8?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 11, line 107,  t1025(I1),  t429,  0(SI32)
	c0    sh2add $r0.10 = $r0.6, (filter7x7 + 0)   ## [spec] bblock 31, line 117,  t1028,  t427,  addr(filter7x7?1.0)(P32)
	c0    add $r0.9 = $r0.5, $r0.8   ## [spec] bblock 31, line 117,  t74,  t428,  t469
	c0    add $r0.18 = $r0.3, 1   ## [spec] bblock 31, line 115-1,  t401,  t468,  1(SI32)
	c0    sh2add $r0.19 = $r0.6, ((filter7x7 + 0) + 4)   ## [spec] bblock 31, line 117-1,  t1044,  t427,  (addr(filter7x7?1.0)(P32) + 0x4(I32))(P32)
	c0    add $r0.11 = $r0.3, 2   ## [spec] bblock 31, line 115-2,  t378,  t468,  2(SI32)
	c0    sh2add $r0.12 = $r0.6, ((filter7x7 + 0) + 8)   ## [spec] bblock 31, line 117-2,  t1060,  t427,  (addr(filter7x7?1.0)(P32) + 0x8(I32))(P32)
	c0    add $r0.13 = $r0.3, 3   ## [spec] bblock 31, line 115-3,  t355,  t468,  3(SI32)
	c0    sh2add $r0.14 = $r0.6, ((filter7x7 + 0) + 12)   ## [spec] bblock 31, line 117-3,  t1076,  t427,  (addr(filter7x7?1.0)(P32) + 0xc(I32))(P32)
	c0    add $r0.20 = $r0.3, 4   ## [spec] bblock 31, line 115-4,  t332,  t468,  4(SI32)
	c0    sh2add $r0.21 = $r0.6, ((filter7x7 + 0) + 16)   ## [spec] bblock 31, line 117-4,  t1092,  t427,  (addr(filter7x7?1.0)(P32) + 0x10(I32))(P32)
	c0    add $r0.15 = $r0.3, 5   ## [spec] bblock 31, line 115-5,  t309,  t468,  5(SI32)
	c0    sh2add $r0.16 = $r0.6, ((filter7x7 + 0) + 20)   ## [spec] bblock 31, line 117-5,  t1108,  t427,  (addr(filter7x7?1.0)(P32) + 0x14(I32))(P32)
	c0    add $r0.4 = $r0.3, 6   ## [spec] bblock 31, line 115-6,  t286,  t468,  6(SI32)
	c0    sh2add $r0.7 = $r0.6, ((filter7x7 + 0) + 24)   ## [spec] bblock 31, line 117-6,  t1124,  t427,  (addr(filter7x7?1.0)(P32) + 0x18(I32))(P32)
	c0    add $r0.2 = $r0.2, 1   ## [spec] bblock 31, line 0,  t429,  t429,  1(I32)
	c0    add $r0.6 = $r0.6, 7   ## [spec] bblock 31, line 0,  t427,  t427,  7(I32)
;;								## 0
	c0    pft 32[$r0.10]   ## [spec] bblock 31, line 117,  t1028,  32(I32)
	c0    ldw.d $r0.24 = 0[$r0.10]   ## [spec] bblock 31, line 117, t70, t1028
	c0    sh2add $r0.9 = $r0.9, (conv7_image + 0)   ## [spec] bblock 31, line 117,  t77,  t74,  addr(conv7_image?1.0)(P32)
	c0    ldw.d $r0.19 = 0[$r0.19]   ## [spec] bblock 31, line 117-1, t403, t1044
	c0    shl $r0.18 = $r0.18, 6   ## [spec] bblock 31, line 117-1,  t404,  t401,  6(I32)
	c0    shl $r0.11 = $r0.11, 6   ## [spec] bblock 31, line 117-2,  t381,  t378,  6(I32)
	c0    ldw.d $r0.12 = 0[$r0.12]   ## [spec] bblock 31, line 117-2, t380, t1060
	c0    shl $r0.13 = $r0.13, 6   ## [spec] bblock 31, line 117-3,  t358,  t355,  6(I32)
	c0    ldw.d $r0.14 = 0[$r0.14]   ## [spec] bblock 31, line 117-3, t357, t1076
	c0    shl $r0.20 = $r0.20, 6   ## [spec] bblock 31, line 117-4,  t335,  t332,  6(I32)
	c0    ldw.d $r0.21 = 0[$r0.21]   ## [spec] bblock 31, line 117-4, t334, t1092
	c0    shl $r0.15 = $r0.15, 6   ## [spec] bblock 31, line 117-5,  t312,  t309,  6(I32)
	c0    ldw.d $r0.16 = 0[$r0.16]   ## [spec] bblock 31, line 117-5, t311, t1108
	c0    shl $r0.4 = $r0.4, 6   ## [spec] bblock 31, line 117-6,  t289,  t286,  6(I32)
	c0    ldw.d $r0.7 = 0[$r0.7]   ## [spec] bblock 31, line 117-6, t288, t1124
	c0    brf $b0.0, L9?3   ## bblock 11, line 107,  t1025(I1)
;;								## 1
	c0    pft 32[$r0.9]   ## bblock 31, line 117,  t77,  32(I32)
	c0    ldw $r0.10 = 0[$r0.9]   ## bblock 31, line 117, t78, t77
	c0    add $r0.18 = $r0.5, $r0.18   ## bblock 31, line 117-1,  t405,  t428,  t404
	c0    add $r0.11 = $r0.5, $r0.11   ## bblock 31, line 117-2,  t382,  t428,  t381
	c0    add $r0.13 = $r0.5, $r0.13   ## bblock 31, line 117-3,  t359,  t428,  t358
	c0    add $r0.20 = $r0.5, $r0.20   ## bblock 31, line 117-4,  t336,  t428,  t335
	c0    add $r0.15 = $r0.5, $r0.15   ## bblock 31, line 117-5,  t313,  t428,  t312
	c0    add $r0.4 = $r0.5, $r0.4   ## bblock 31, line 117-6,  t290,  t428,  t289
	c0    add $r0.5 = $r0.5, 1   ## bblock 31, line 0,  t428,  t428,  1(I32)
;;								## 2
	c0    sh2add $r0.18 = $r0.18, (conv7_image + 0)   ## bblock 31, line 117-1,  t407,  t405,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.11 = $r0.11, (conv7_image + 0)   ## bblock 31, line 117-2,  t384,  t382,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.13 = $r0.13, (conv7_image + 0)   ## bblock 31, line 117-3,  t361,  t359,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.20 = $r0.20, (conv7_image + 0)   ## bblock 31, line 117-4,  t338,  t336,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.15 = $r0.15, (conv7_image + 0)   ## bblock 31, line 117-5,  t315,  t313,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.4 = $r0.4, (conv7_image + 0)   ## bblock 31, line 117-6,  t292,  t290,  addr(conv7_image?1.0)(P32)
;;								## 3
	c0    shru $r0.25 = $r0.10, 16   ## bblock 31, line 117,  t43(I16),  t78,  16(SI32)
	c0    and $r0.10 = $r0.10, 255   ## bblock 31, line 119,  t79,  t78,  255(I32)
	c0    shru $r0.9 = $r0.10, 8   ## bblock 31, line 118,  t61(I24),  t78,  8(SI32)
	c0    ldw $r0.18 = 0[$r0.18]   ## bblock 31, line 117-1, t408, t407
	c0    ldw $r0.11 = 0[$r0.11]   ## bblock 31, line 117-2, t385, t384
	c0    ldw $r0.13 = 0[$r0.13]   ## bblock 31, line 117-3, t362, t361
	c0    ldw $r0.20 = 0[$r0.20]   ## bblock 31, line 117-4, t339, t338
	c0    ldw $r0.15 = 0[$r0.15]   ## bblock 31, line 117-5, t316, t315
	c0    ldw $r0.4 = 0[$r0.4]   ## bblock 31, line 117-6, t293, t292
;;								## 4
	c0    and $r0.25 = $r0.25, 255   ## bblock 31, line 117,  t44,  t43(I16),  255(I32)
	c0    mpylu $r0.26 = $r0.24, $r0.10   ## bblock 31, line 119,  t1031,  t70,  t79
	c0    mpyhs $r0.10 = $r0.24, $r0.10   ## bblock 31, line 119,  t1032,  t70,  t79
	c0    and $r0.9 = $r0.9, 255   ## bblock 31, line 118,  t62,  t61(I24),  255(I32)
;;								## 5
	c0    mpylu $r0.35 = $r0.24, $r0.25   ## bblock 31, line 117,  t1029,  t70,  t44
	c0    mpyhs $r0.24 = $r0.24, $r0.25   ## bblock 31, line 117,  t1030,  t70,  t44
	c0    mpylu $r0.28 = $r0.24, $r0.9   ## bblock 31, line 118,  t1039,  t70,  t62
	c0    mpyhs $r0.9 = $r0.24, $r0.9   ## bblock 31, line 118,  t1040,  t70,  t62
	c0    shru $r0.38 = $r0.18, 16   ## bblock 31, line 117-1,  t409(I16),  t408,  16(SI32)
	c0    and $r0.18 = $r0.18, 255   ## bblock 31, line 119-1,  t412,  t408,  255(I32)
	c0    shru $r0.32 = $r0.18, 8   ## bblock 31, line 118-1,  t416(I24),  t408,  8(SI32)
	c0    shru $r0.25 = $r0.11, 16   ## bblock 31, line 117-2,  t386(I16),  t385,  16(SI32)
	c0    and $r0.11 = $r0.11, 255   ## bblock 31, line 119-2,  t389,  t385,  255(I32)
	c0    shru $r0.29 = $r0.11, 8   ## bblock 31, line 118-2,  t393(I24),  t385,  8(SI32)
	c0    shru $r0.36 = $r0.13, 16   ## bblock 31, line 117-3,  t363(I16),  t362,  16(SI32)
	c0    and $r0.13 = $r0.13, 255   ## bblock 31, line 119-3,  t366,  t362,  255(I32)
	c0    shru $r0.30 = $r0.13, 8   ## bblock 31, line 118-3,  t370(I24),  t362,  8(SI32)
	c0    shru $r0.39 = $r0.20, 16   ## bblock 31, line 117-4,  t340(I16),  t339,  16(SI32)
	c0    and $r0.20 = $r0.20, 255   ## bblock 31, line 119-4,  t343,  t339,  255(I32)
	c0    shru $r0.33 = $r0.20, 8   ## bblock 31, line 118-4,  t347(I24),  t339,  8(SI32)
	c0    shru $r0.37 = $r0.15, 16   ## bblock 31, line 117-5,  t317(I16),  t316,  16(SI32)
	c0    and $r0.15 = $r0.15, 255   ## bblock 31, line 119-5,  t320,  t316,  255(I32)
	c0    shru $r0.31 = $r0.15, 8   ## bblock 31, line 118-5,  t324(I24),  t316,  8(SI32)
	c0    shru $r0.34 = $r0.4, 16   ## bblock 31, line 117-6,  t294(I16),  t293,  16(SI32)
	c0    and $r0.4 = $r0.4, 255   ## bblock 31, line 119-6,  t297,  t293,  255(I32)
	c0    shru $r0.27 = $r0.4, 8   ## bblock 31, line 118-6,  t301(I24),  t293,  8(SI32)
;;								## 6
	c0    add $r0.26 = $r0.26, $r0.10   ## bblock 31, line 119,  t80,  t1031,  t1032
	c0    and $r0.38 = $r0.38, 255   ## bblock 31, line 117-1,  t410,  t409(I16),  255(I32)
	c0    mpylu $r0.43 = $r0.19, $r0.18   ## bblock 31, line 119-1,  t1050,  t403,  t412
	c0    mpyhs $r0.18 = $r0.19, $r0.18   ## bblock 31, line 119-1,  t1051,  t403,  t412
	c0    and $r0.32 = $r0.32, 255   ## bblock 31, line 118-1,  t417,  t416(I24),  255(I32)
	c0    and $r0.25 = $r0.25, 255   ## bblock 31, line 117-2,  t387,  t386(I16),  255(I32)
	c0    and $r0.29 = $r0.29, 255   ## bblock 31, line 118-2,  t394,  t393(I24),  255(I32)
	c0    mpylu $r0.10 = $r0.12, $r0.11   ## bblock 31, line 119-2,  t1066,  t380,  t389
	c0    mpyhs $r0.11 = $r0.12, $r0.11   ## bblock 31, line 119-2,  t1067,  t380,  t389
	c0    and $r0.36 = $r0.36, 255   ## bblock 31, line 117-3,  t364,  t363(I16),  255(I32)
	c0    and $r0.30 = $r0.30, 255   ## bblock 31, line 118-3,  t371,  t370(I24),  255(I32)
	c0    mpylu $r0.41 = $r0.14, $r0.13   ## bblock 31, line 119-3,  t1082,  t357,  t366
	c0    mpyhs $r0.13 = $r0.14, $r0.13   ## bblock 31, line 119-3,  t1083,  t357,  t366
	c0    and $r0.39 = $r0.39, 255   ## bblock 31, line 117-4,  t341,  t340(I16),  255(I32)
	c0    and $r0.33 = $r0.33, 255   ## bblock 31, line 118-4,  t348,  t347(I24),  255(I32)
	c0    mpylu $r0.44 = $r0.21, $r0.20   ## bblock 31, line 119-4,  t1098,  t334,  t343
	c0    mpyhs $r0.20 = $r0.21, $r0.20   ## bblock 31, line 119-4,  t1099,  t334,  t343
	c0    and $r0.37 = $r0.37, 255   ## bblock 31, line 117-5,  t318,  t317(I16),  255(I32)
	c0    and $r0.31 = $r0.31, 255   ## bblock 31, line 118-5,  t325,  t324(I24),  255(I32)
	c0    mpylu $r0.42 = $r0.16, $r0.15   ## bblock 31, line 119-5,  t1114,  t311,  t320
	c0    mpyhs $r0.15 = $r0.16, $r0.15   ## bblock 31, line 119-5,  t1115,  t311,  t320
	c0    and $r0.34 = $r0.34, 255   ## bblock 31, line 117-6,  t295,  t294(I16),  255(I32)
	c0    and $r0.27 = $r0.27, 255   ## bblock 31, line 118-6,  t302,  t301(I24),  255(I32)
	c0    mpylu $r0.40 = $r0.7, $r0.4   ## bblock 31, line 119-6,  t1130,  t288,  t297
	c0    mpyhs $r0.4 = $r0.7, $r0.4   ## bblock 31, line 119-6,  t1131,  t288,  t297
;;								## 7
	c0    add $r0.35 = $r0.35, $r0.24   ## bblock 31, line 117,  t45,  t1029,  t1030
	c0    cmplt $b0.0 = $r0.26, $r0.0   ## bblock 31, line 119,  t1036,  t80,  0(I32)
	c0    add $r0.38 = $r0.26, 255   ## bblock 31, line 119,  t1037,  t80,  255(I32)
	c0    add $r0.28 = $r0.28, $r0.9   ## bblock 31, line 118,  t63,  t1039,  t1040
	c0    mpylu $r0.36 = $r0.19, $r0.38   ## bblock 31, line 117-1,  t1045,  t403,  t410
	c0    mpyhs $r0.19 = $r0.19, $r0.38   ## bblock 31, line 117-1,  t1046,  t403,  t410
	c0    mpylu $r0.48 = $r0.19, $r0.32   ## bblock 31, line 118-1,  t1055,  t403,  t417
	c0    mpyhs $r0.32 = $r0.19, $r0.32   ## bblock 31, line 118-1,  t1056,  t403,  t417
	c0    mpylu $r0.24 = $r0.12, $r0.25   ## bblock 31, line 117-2,  t1061,  t380,  t387
	c0    mpyhs $r0.12 = $r0.12, $r0.25   ## bblock 31, line 117-2,  t1062,  t380,  t387
	c0    mpylu $r0.9 = $r0.12, $r0.29   ## bblock 31, line 118-2,  t1071,  t380,  t394
	c0    mpyhs $r0.29 = $r0.12, $r0.29   ## bblock 31, line 118-2,  t1072,  t380,  t394
	c0    mpylu $r0.25 = $r0.14, $r0.36   ## bblock 31, line 117-3,  t1077,  t357,  t364
	c0    mpyhs $r0.14 = $r0.14, $r0.36   ## bblock 31, line 117-3,  t1078,  t357,  t364
	c0    mpylu $r0.46 = $r0.14, $r0.30   ## bblock 31, line 118-3,  t1087,  t357,  t371
	c0    mpyhs $r0.30 = $r0.14, $r0.30   ## bblock 31, line 118-3,  t1088,  t357,  t371
	c0    mpylu $r0.37 = $r0.21, $r0.39   ## bblock 31, line 117-4,  t1093,  t334,  t341
	c0    mpyhs $r0.21 = $r0.21, $r0.39   ## bblock 31, line 117-4,  t1094,  t334,  t341
	c0    mpylu $r0.49 = $r0.21, $r0.33   ## bblock 31, line 118-4,  t1103,  t334,  t348
	c0    mpyhs $r0.33 = $r0.21, $r0.33   ## bblock 31, line 118-4,  t1104,  t334,  t348
	c0    mpylu $r0.34 = $r0.16, $r0.37   ## bblock 31, line 117-5,  t1109,  t311,  t318
	c0    mpyhs $r0.16 = $r0.16, $r0.37   ## bblock 31, line 117-5,  t1110,  t311,  t318
	c0    mpylu $r0.47 = $r0.16, $r0.31   ## bblock 31, line 118-5,  t1119,  t311,  t325
	c0    mpyhs $r0.31 = $r0.16, $r0.31   ## bblock 31, line 118-5,  t1120,  t311,  t325
	c0    mpylu $r0.50 = $r0.7, $r0.34   ## bblock 31, line 117-6,  t1125,  t288,  t295
	c0    mpyhs $r0.7 = $r0.7, $r0.34   ## bblock 31, line 117-6,  t1126,  t288,  t295
	c0    mpylu $r0.45 = $r0.7, $r0.27   ## bblock 31, line 118-6,  t1135,  t288,  t302
	c0    mpyhs $r0.27 = $r0.7, $r0.27   ## bblock 31, line 118-6,  t1136,  t288,  t302
;;								## 8
	c0    cmplt $b0.2 = $r0.35, $r0.0   ## bblock 31, line 117,  t1033,  t45,  0(I32)
	c0    add $r0.51 = $r0.35, 255   ## bblock 31, line 117,  t1034,  t45,  255(I32)
	c0    slct $r0.38 = $b0.0, $r0.38, $r0.26   ## bblock 31, line 119,  t1038,  t1036,  t1037,  t80
	c0    cmplt $b0.1 = $r0.28, $r0.0   ## bblock 31, line 118,  t1041,  t63,  0(I32)
	c0    add $r0.39 = $r0.28, 255   ## bblock 31, line 118,  t1042,  t63,  255(I32)
	c0    add $r0.43 = $r0.43, $r0.18   ## bblock 31, line 119-1,  t413,  t1050,  t1051
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 31, line 119-2,  t390,  t1066,  t1067
	c0    add $r0.41 = $r0.41, $r0.13   ## bblock 31, line 119-3,  t367,  t1082,  t1083
	c0    add $r0.44 = $r0.44, $r0.20   ## bblock 31, line 119-4,  t344,  t1098,  t1099
	c0    add $r0.42 = $r0.42, $r0.15   ## bblock 31, line 119-5,  t321,  t1114,  t1115
	c0    add $r0.40 = $r0.40, $r0.4   ## bblock 31, line 119-6,  t298,  t1130,  t1131
;;								## 9
	c0    slct $r0.51 = $b0.2, $r0.51, $r0.35   ## bblock 31, line 117,  t1035,  t1033,  t1034,  t45
	c0    shr $r0.38 = $r0.38, 8   ## bblock 31, line 119,  t81,  t1038,  8(I32)
	c0    slct $r0.39 = $b0.1, $r0.39, $r0.28   ## bblock 31, line 118,  t1043,  t1041,  t1042,  t63
	c0    add $r0.36 = $r0.36, $r0.19   ## bblock 31, line 117-1,  t411,  t1045,  t1046
	c0    cmplt $b0.4 = $r0.43, $r0.0   ## bblock 31, line 119-1,  t1052,  t413,  0(I32)
	c0    add $r0.13 = $r0.43, 255   ## bblock 31, line 119-1,  t1053,  t413,  255(I32)
	c0    add $r0.48 = $r0.48, $r0.32   ## bblock 31, line 118-1,  t418,  t1055,  t1056
	c0    add $r0.24 = $r0.24, $r0.12   ## bblock 31, line 117-2,  t388,  t1061,  t1062
	c0    cmplt $b0.1 = $r0.10, $r0.0   ## bblock 31, line 119-2,  t1068,  t390,  0(I32)
	c0    add $r0.7 = $r0.10, 255   ## bblock 31, line 119-2,  t1069,  t390,  255(I32)
	c0    add $r0.9 = $r0.9, $r0.29   ## bblock 31, line 118-2,  t395,  t1071,  t1072
	c0    add $r0.25 = $r0.25, $r0.14   ## bblock 31, line 117-3,  t365,  t1077,  t1078
	c0    cmplt $b0.2 = $r0.41, $r0.0   ## bblock 31, line 119-3,  t1084,  t367,  0(I32)
	c0    add $r0.11 = $r0.41, 255   ## bblock 31, line 119-3,  t1085,  t367,  255(I32)
	c0    add $r0.46 = $r0.46, $r0.30   ## bblock 31, line 118-3,  t372,  t1087,  t1088
	c0    add $r0.37 = $r0.37, $r0.21   ## bblock 31, line 117-4,  t342,  t1093,  t1094
	c0    cmplt $b0.5 = $r0.44, $r0.0   ## bblock 31, line 119-4,  t1100,  t344,  0(I32)
	c0    add $r0.14 = $r0.44, 255   ## bblock 31, line 119-4,  t1101,  t344,  255(I32)
	c0    add $r0.49 = $r0.49, $r0.33   ## bblock 31, line 118-4,  t349,  t1103,  t1104
	c0    add $r0.34 = $r0.34, $r0.16   ## bblock 31, line 117-5,  t319,  t1109,  t1110
	c0    cmplt $b0.3 = $r0.42, $r0.0   ## bblock 31, line 119-5,  t1116,  t321,  0(I32)
	c0    add $r0.12 = $r0.42, 255   ## bblock 31, line 119-5,  t1117,  t321,  255(I32)
	c0    add $r0.47 = $r0.47, $r0.31   ## bblock 31, line 118-5,  t326,  t1119,  t1120
	c0    add $r0.50 = $r0.50, $r0.7   ## bblock 31, line 117-6,  t296,  t1125,  t1126
	c0    cmplt $b0.0 = $r0.40, $r0.0   ## bblock 31, line 119-6,  t1132,  t298,  0(I32)
	c0    add $r0.4 = $r0.40, 255   ## bblock 31, line 119-6,  t1133,  t298,  255(I32)
	c0    add $r0.45 = $r0.45, $r0.27   ## bblock 31, line 118-6,  t303,  t1135,  t1136
;;								## 10
	c0    shr $r0.51 = $r0.51, 8   ## bblock 31, line 117,  t46,  t1035,  8(I32)
	c0    shr $r0.39 = $r0.39, 8   ## bblock 31, line 118,  t64,  t1043,  8(I32)
	c0    add $r0.53 = $r0.36, 255   ## bblock 31, line 117-1,  t1048,  t411,  255(I32)
	c0    cmplt $b0.3 = $r0.48, $r0.0   ## bblock 31, line 118-1,  t1057,  t418,  0(I32)
	c0    add $r0.27 = $r0.48, 255   ## bblock 31, line 118-1,  t1058,  t418,  255(I32)
	c0    cmplt $b0.0 = $r0.24, $r0.0   ## bblock 31, line 117-2,  t1063,  t388,  0(I32)
	c0    add $r0.33 = $r0.24, 255   ## bblock 31, line 117-2,  t1064,  t388,  255(I32)
	c0    cmplt $b0.7 = $r0.9, $r0.0   ## bblock 31, line 118-2,  t1073,  t395,  0(I32)
	c0    add $r0.16 = $r0.9, 255   ## bblock 31, line 118-2,  t1074,  t395,  255(I32)
	c0    add $r0.35 = $r0.25, 255   ## bblock 31, line 117-3,  t1080,  t365,  255(I32)
	c0    cmplt $b0.5 = $r0.46, $r0.0   ## bblock 31, line 118-3,  t1089,  t372,  0(I32)
	c0    add $r0.19 = $r0.46, 255   ## bblock 31, line 118-3,  t1090,  t372,  255(I32)
	c0    add $r0.54 = $r0.37, 255   ## bblock 31, line 117-4,  t1096,  t342,  255(I32)
	c0    cmplt $b0.2 = $r0.49, $r0.0   ## bblock 31, line 118-4,  t1105,  t349,  0(I32)
	c0    add $r0.29 = $r0.49, 255   ## bblock 31, line 118-4,  t1106,  t349,  255(I32)
	c0    add $r0.52 = $r0.34, 255   ## bblock 31, line 117-5,  t1112,  t319,  255(I32)
	c0    cmplt $b0.4 = $r0.47, $r0.0   ## bblock 31, line 118-5,  t1121,  t326,  0(I32)
	c0    add $r0.21 = $r0.47, 255   ## bblock 31, line 118-5,  t1122,  t326,  255(I32)
	c0    cmplt $b0.1 = $r0.50, $r0.0   ## bblock 31, line 117-6,  t1127,  t296,  0(I32)
	c0    add $r0.31 = $r0.50, 255   ## bblock 31, line 117-6,  t1128,  t296,  255(I32)
	c0    cmplt $b0.6 = $r0.45, $r0.0   ## bblock 31, line 118-6,  t1137,  t303,  0(I32)
	c0    add $r0.15 = $r0.45, 255   ## bblock 31, line 118-6,  t1138,  t303,  255(I32)
	c0    mfb $r0.18 = $b0.5   ## t1100
	c0    mfb $r0.20 = $b0.4   ## t1052
	c0    mfb $r0.26 = $b0.3   ## t1116
	c0    mfb $r0.28 = $b0.2   ## t1084
	c0    mfb $r0.30 = $b0.1   ## t1068
	c0    mfb $r0.32 = $b0.0   ## t1132
;;								## 11
	c0    cmplt $b0.2 = $r0.36, $r0.0   ## bblock 31, line 117-1,  t1047,  t411,  0(I32)
	c0    slct $r0.27 = $b0.3, $r0.27, $r0.48   ## bblock 31, line 118-1,  t1059,  t1057,  t1058,  t418
	c0    slct $r0.33 = $b0.0, $r0.33, $r0.24   ## bblock 31, line 117-2,  t1065,  t1063,  t1064,  t388
	c0    slct $r0.16 = $b0.7, $r0.16, $r0.9   ## bblock 31, line 118-2,  t1075,  t1073,  t1074,  t395
	c0    cmplt $b0.0 = $r0.25, $r0.0   ## bblock 31, line 117-3,  t1079,  t365,  0(I32)
	c0    slct $r0.19 = $b0.5, $r0.19, $r0.46   ## bblock 31, line 118-3,  t1091,  t1089,  t1090,  t372
	c0    cmplt $b0.3 = $r0.37, $r0.0   ## bblock 31, line 117-4,  t1095,  t342,  0(I32)
	c0    slct $r0.29 = $b0.2, $r0.29, $r0.49   ## bblock 31, line 118-4,  t1107,  t1105,  t1106,  t349
	c0    cmplt $b0.1 = $r0.34, $r0.0   ## bblock 31, line 117-5,  t1111,  t319,  0(I32)
	c0    slct $r0.21 = $b0.4, $r0.21, $r0.47   ## bblock 31, line 118-5,  t1123,  t1121,  t1122,  t326
	c0    slct $r0.31 = $b0.1, $r0.31, $r0.50   ## bblock 31, line 117-6,  t1129,  t1127,  t1128,  t296
	c0    slct $r0.15 = $b0.6, $r0.15, $r0.45   ## bblock 31, line 118-6,  t1139,  t1137,  t1138,  t303
	c0    mtb $b0.7 = $r0.26   ## t1116
	c0    mtb $b0.6 = $r0.28   ## t1084
	c0    mtb $b0.5 = $r0.30   ## t1068
	c0    mtb $b0.4 = $r0.32   ## t1132
;;								## 12
	c0    slct $r0.53 = $b0.2, $r0.53, $r0.36   ## bblock 31, line 117-1,  t1049,  t1047,  t1048,  t411
	c0    shr $r0.27 = $r0.27, 8   ## bblock 31, line 118-1,  t419,  t1059,  8(I32)
	c0    shr $r0.33 = $r0.33, 8   ## bblock 31, line 117-2,  t391,  t1065,  8(I32)
	c0    slct $r0.7 = $b0.5, $r0.7, $r0.10   ## bblock 31, line 119-2,  t1070,  t1068,  t1069,  t390
	c0    shr $r0.16 = $r0.16, 8   ## bblock 31, line 118-2,  t396,  t1075,  8(I32)
	c0    slct $r0.35 = $b0.0, $r0.35, $r0.25   ## bblock 31, line 117-3,  t1081,  t1079,  t1080,  t365
	c0    slct $r0.11 = $b0.6, $r0.11, $r0.41   ## bblock 31, line 119-3,  t1086,  t1084,  t1085,  t367
	c0    shr $r0.19 = $r0.19, 8   ## bblock 31, line 118-3,  t373,  t1091,  8(I32)
	c0    slct $r0.54 = $b0.3, $r0.54, $r0.37   ## bblock 31, line 117-4,  t1097,  t1095,  t1096,  t342
	c0    shr $r0.29 = $r0.29, 8   ## bblock 31, line 118-4,  t350,  t1107,  8(I32)
	c0    slct $r0.52 = $b0.1, $r0.52, $r0.34   ## bblock 31, line 117-5,  t1113,  t1111,  t1112,  t319
	c0    slct $r0.12 = $b0.7, $r0.12, $r0.42   ## bblock 31, line 119-5,  t1118,  t1116,  t1117,  t321
	c0    shr $r0.21 = $r0.21, 8   ## bblock 31, line 118-5,  t327,  t1123,  8(I32)
	c0    shr $r0.31 = $r0.31, 8   ## bblock 31, line 117-6,  t299,  t1129,  8(I32)
	c0    slct $r0.4 = $b0.4, $r0.4, $r0.40   ## bblock 31, line 119-6,  t1134,  t1132,  t1133,  t298
	c0    shr $r0.15 = $r0.15, 8   ## bblock 31, line 118-6,  t304,  t1139,  8(I32)
	c0    mtb $b0.1 = $r0.18   ## t1100
	c0    mtb $b0.0 = $r0.20   ## t1052
;;								## 13
	c0    shr $r0.53 = $r0.53, 8   ## bblock 31, line 117-1,  t414,  t1049,  8(I32)
	c0    slct $r0.13 = $b0.0, $r0.13, $r0.43   ## bblock 31, line 119-1,  t1054,  t1052,  t1053,  t413
	c0    shr $r0.7 = $r0.7, 8   ## bblock 31, line 119-2,  t392,  t1070,  8(I32)
	c0    shr $r0.35 = $r0.35, 8   ## bblock 31, line 117-3,  t368,  t1081,  8(I32)
	c0    shr $r0.11 = $r0.11, 8   ## bblock 31, line 119-3,  t369,  t1086,  8(I32)
	c0    shr $r0.54 = $r0.54, 8   ## bblock 31, line 117-4,  t345,  t1097,  8(I32)
	c0    slct $r0.14 = $b0.1, $r0.14, $r0.44   ## bblock 31, line 119-4,  t1102,  t1100,  t1101,  t344
	c0    shr $r0.52 = $r0.52, 8   ## bblock 31, line 117-5,  t322,  t1113,  8(I32)
	c0    shr $r0.12 = $r0.12, 8   ## bblock 31, line 119-5,  t323,  t1118,  8(I32)
	c0    shr $r0.4 = $r0.4, 8   ## bblock 31, line 119-6,  t300,  t1134,  8(I32)
	c0    add $r0.39 = $r0.39, $r0.15   ## bblock 31, line 118-6,  t1140,  t64,  t304
	c0    add $r0.17 = $r0.17, $r0.21   ## bblock 31, line 118-6,  t1141,  t152,  t327
	c0    add $r0.27 = $r0.27, $r0.29   ## bblock 31, line 118-6,  t1142,  t419,  t350
	c0    add $r0.16 = $r0.16, $r0.19   ## bblock 31, line 118-6,  t1143,  t396,  t373
	c0    add $r0.51 = $r0.51, $r0.31   ## bblock 31, line 117-6,  t1152,  t46,  t299
;;								## 14
	c0    shr $r0.13 = $r0.13, 8   ## bblock 31, line 119-1,  t415,  t1054,  8(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 31, line 119-4,  t346,  t1102,  8(I32)
	c0    add $r0.39 = $r0.39, $r0.16   ## bblock 31, line 118-6,  t1144,  t1140,  t1143
	c0    add $r0.17 = $r0.17, $r0.27   ## bblock 31, line 118-6,  t1145,  t1141,  t1142
	c0    add $r0.38 = $r0.38, $r0.4   ## bblock 31, line 119-6,  t1146,  t81,  t300
	c0    add $r0.23 = $r0.23, $r0.12   ## bblock 31, line 119-6,  t1147,  t151,  t323
	c0    add $r0.7 = $r0.7, $r0.11   ## bblock 31, line 119-6,  t1149,  t392,  t369
	c0    add $r0.22 = $r0.22, $r0.52   ## bblock 31, line 117-6,  t1153,  t153,  t322
	c0    add $r0.53 = $r0.53, $r0.54   ## bblock 31, line 117-6,  t1154,  t414,  t345
	c0    add $r0.33 = $r0.33, $r0.35   ## bblock 31, line 117-6,  t1155,  t391,  t368
;;								## 15
	c0    add $r0.17 = $r0.39, $r0.17   ## bblock 31, line 118-6,  t152,  t1144,  t1145
	c0    add $r0.13 = $r0.13, $r0.14   ## bblock 31, line 119-6,  t1148,  t415,  t346
	c0    add $r0.38 = $r0.38, $r0.7   ## bblock 31, line 119-6,  t1150,  t1146,  t1149
	c0    add $r0.51 = $r0.51, $r0.33   ## bblock 31, line 117-6,  t1156,  t1152,  t1155
	c0    add $r0.22 = $r0.22, $r0.53   ## bblock 31, line 117-6,  t1157,  t1153,  t1154
;;								## 16
	c0    add $r0.23 = $r0.23, $r0.13   ## bblock 31, line 119-6,  t1151,  t1147,  t1148
	c0    add $r0.22 = $r0.51, $r0.22   ## bblock 31, line 117-6,  t153,  t1156,  t1157
;;								## 17
	c0    add $r0.23 = $r0.38, $r0.23   ## bblock 31, line 119-6,  t151,  t1150,  t1151
	c0    goto L8?3 ## goto
;;								## 18
.trace 6
L9?3:
	c0    max $r0.23 = $r0.23, $r0.0   ## bblock 29, line 163,  t173,  t151,  0(SI32)
	c0    max $r0.17 = $r0.17, $r0.0   ## bblock 29, line 162,  t179,  t152,  0(SI32)
	c0    max $r0.22 = $r0.22, $r0.0   ## bblock 29, line 161,  t185,  t153,  0(SI32)
	c0    sh2add $r0.2 = $r0.55, $r0.57   ## bblock 29, line 161,  t1027,  t443,  t473
	c0    add $r0.4 = $r0.55, 1   ## bblock 29, line 0,  t443,  t443,  1(I32)
;;								## 0
	c0    min $r0.23 = $r0.23, 255   ## bblock 29, line 163,  t83,  t173,  255(SI32)
	c0    min $r0.17 = $r0.17, 255   ## bblock 29, line 162,  t86,  t179,  255(SI32)
	c0    min $r0.22 = $r0.22, 255   ## bblock 29, line 161,  t90,  t185,  255(SI32)
	c0    pft 32[$r0.2]   ## bblock 29, line 161,  t1027,  32(I32)
	c0    add $r0.7 = $r0.56, 1   ## bblock 29, line 0,  t442,  t442,  1(I32)
;;								## 1
	c0    shl $r0.17 = $r0.17, 8   ## bblock 29, line 163,  t89,  t86,  8(SI32)
	c0    shl $r0.22 = $r0.22, 16   ## bblock 29, line 162,  t93,  t90,  16(SI32)
;;								## 2
	c0    or $r0.23 = $r0.23, $r0.22   ## bblock 29, line 163,  t1026,  t83,  t93
;;								## 3
	c0    or $r0.23 = $r0.23, $r0.17   ## bblock 29, line 163,  t94,  t1026,  t89
;;								## 4
	c0    stw 0[$r0.2] = $r0.23   ## bblock 29, line 161, t1027, t94
	c0    goto L6?3 ## goto
;;								## 5
.trace 8
L7?3:
	c0    add $r0.3 = $r0.3, 1   ## bblock 9, line 0,  t468,  t468,  1(I32)
	c0    add $r0.8 = $r0.8, 64   ## bblock 9, line 0,  t469,  t469,  64(I32)
	c0    add $r0.57 = $r0.57, 256   ## bblock 9, line 0,  t473,  t473,  256(I32)
	c0    goto L4?3 ## goto
;;								## 0
.trace 9
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 171,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t128
	      xnop 1
;;								## 2
	c0    ldw $r0.57 = 0x14[$r0.1]  ## restore ## t132
;;								## 3
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 6, line 173,  t129,  ?2.4?2auto_size(I32),  t128
;;								## 4
.endp
.section .bss
.section .data
_?1STRINGPACKET.1:
    .data1 67
    .data1 111
    .data1 110
    .data1 118
    .data1 111
    .data1 108
    .data1 117
    .data1 116
    .data1 105
    .data1 111
    .data1 110
    .data1 32
    .data1 55
    .data1 120
    .data1 55
    .data1 58
    .data1 32
    .data1 115
    .data1 117
    .data1 99
    .data1 99
    .data1 101
    .data1 115
    .data1 115
    .data1 10
    .data1 0
.equ ?2.4?2scratch.0, 0x0
.equ ?2.4?2ras_p, 0x10
.equ ?2.4?2spill_p, 0x14
.section .data
.section .text
.equ ?2.4?2auto_size, 0x20
 ## End main
.section .bss
.section .data
.skip 2
filter7x7::
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
    .data4 32
.section .data
.comm strbuf, 0xc, 4
.comm conv7_result, 0x4000, 4
.comm conv7_image, 0x4000, 4
.section .text
.import NOP
.type NOP,@function
.import puts
.type puts,@function
