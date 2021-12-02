 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -prefetch -mfinline -mas_g -mas_G -O3 -o a.out"
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
.entry caller, sp=$r0.1, rl=$l0.0, asize=-128, arg()
main::
.trace 8
	c0    add $r0.1 = $r0.1, (-0x80)
;;								## 0
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 64,  raddr(NOP)(P32)
	c0    stw 0x60[$r0.1] = $r0.57  ## spill ## t132
	c0    stw 0x64[$r0.1] = $r0.58  ## spill ## t133
	c0    stw 0x68[$r0.1] = $r0.59  ## spill ## t134
	c0    stw 0x6c[$r0.1] = $r0.60  ## spill ## t135
	c0    stw 0x70[$r0.1] = $r0.61  ## spill ## t136
	c0    stw 0x74[$r0.1] = $r0.62  ## spill ## t137
	c0    stw 0x78[$r0.1] = $r0.63  ## spill ## t138
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t128
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t1593,  (~0xfff)(I32)
	c0    mov $r0.3 = (conv7_result + 0)   ## bblock 1, line 0,  t1592,  addr(conv7_result?1.0)(P32)
;;								## 2
.trace 3
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 89,  t2064(I1),  t1593,  0(SI32)
	c0    pft 128[$r0.3]   ## [spec] bblock 35, line 90,  t1592,  128(I32)
	c0    add $r0.2 = $r0.2, 32   ## [spec] bblock 35, line 0,  t1593,  t1593,  32(I32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 89,  t2064(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 35, line 90, t1592, 0(SI32)
	c0    stw 4[$r0.3] = $r0.0   ## bblock 35, line 90-1, t1592, 0(SI32)
	c0    stw 8[$r0.3] = $r0.0   ## bblock 35, line 90-2, t1592, 0(SI32)
	c0    stw 12[$r0.3] = $r0.0   ## bblock 35, line 90-3, t1592, 0(SI32)
	c0    stw 16[$r0.3] = $r0.0   ## bblock 35, line 90-4, t1592, 0(SI32)
	c0    stw 20[$r0.3] = $r0.0   ## bblock 35, line 90-5, t1592, 0(SI32)
	c0    stw 24[$r0.3] = $r0.0   ## bblock 35, line 90-6, t1592, 0(SI32)
	c0    stw 28[$r0.3] = $r0.0   ## bblock 35, line 90-7, t1592, 0(SI32)
	c0    stw 32[$r0.3] = $r0.0   ## bblock 35, line 90-8, t1592, 0(SI32)
	c0    stw 36[$r0.3] = $r0.0   ## bblock 35, line 90-9, t1592, 0(SI32)
	c0    stw 40[$r0.3] = $r0.0   ## bblock 35, line 90-10, t1592, 0(SI32)
	c0    stw 44[$r0.3] = $r0.0   ## bblock 35, line 90-11, t1592, 0(SI32)
	c0    stw 48[$r0.3] = $r0.0   ## bblock 35, line 90-12, t1592, 0(SI32)
	c0    stw 52[$r0.3] = $r0.0   ## bblock 35, line 90-13, t1592, 0(SI32)
	c0    stw 56[$r0.3] = $r0.0   ## bblock 35, line 90-14, t1592, 0(SI32)
	c0    stw 60[$r0.3] = $r0.0   ## bblock 35, line 90-15, t1592, 0(SI32)
	c0    stw 64[$r0.3] = $r0.0   ## bblock 35, line 90-16, t1592, 0(SI32)
	c0    stw 68[$r0.3] = $r0.0   ## bblock 35, line 90-17, t1592, 0(SI32)
	c0    stw 72[$r0.3] = $r0.0   ## bblock 35, line 90-18, t1592, 0(SI32)
	c0    stw 76[$r0.3] = $r0.0   ## bblock 35, line 90-19, t1592, 0(SI32)
	c0    stw 80[$r0.3] = $r0.0   ## bblock 35, line 90-20, t1592, 0(SI32)
	c0    stw 84[$r0.3] = $r0.0   ## bblock 35, line 90-21, t1592, 0(SI32)
	c0    stw 88[$r0.3] = $r0.0   ## bblock 35, line 90-22, t1592, 0(SI32)
	c0    stw 92[$r0.3] = $r0.0   ## bblock 35, line 90-23, t1592, 0(SI32)
	c0    stw 96[$r0.3] = $r0.0   ## bblock 35, line 90-24, t1592, 0(SI32)
	c0    stw 100[$r0.3] = $r0.0   ## bblock 35, line 90-25, t1592, 0(SI32)
	c0    stw 104[$r0.3] = $r0.0   ## bblock 35, line 90-26, t1592, 0(SI32)
	c0    stw 108[$r0.3] = $r0.0   ## bblock 35, line 90-27, t1592, 0(SI32)
	c0    stw 112[$r0.3] = $r0.0   ## bblock 35, line 90-28, t1592, 0(SI32)
	c0    stw 116[$r0.3] = $r0.0   ## bblock 35, line 90-29, t1592, 0(SI32)
	c0    stw 120[$r0.3] = $r0.0   ## bblock 35, line 90-30, t1592, 0(SI32)
	c0    stw 124[$r0.3] = $r0.0   ## bblock 35, line 90-31, t1592, 0(SI32)
;;								## 2
	c0    add $r0.3 = $r0.3, 128   ## bblock 35, line 0,  t1592,  t1592,  128(I32)
	c0    goto L2?3 ## goto
;;								## 3
.trace 7
L3?3:
	c0    mov $r0.6 = $r0.0   ## bblock 3, line 0,  t1469,  0(I32)
	c0    mov $r0.2 = $r0.0   ## bblock 3, line 0,  t1468,  0(I32)
	c0    mov $r0.26 = ((conv7_result + 0) + 1012)   ## bblock 3, line 0,  t1473,  (addr(conv7_result?1.0)(P32) + 0x3f4(I32))(P32)
;;								## 0
	c0    stw 0x3c[$r0.1] = $r0.6  ## spill ## t1469
	c0    stw 0x1c[$r0.1] = $r0.26  ## spill ## t1473
	c0    stw 0x14[$r0.1] = $r0.2  ## spill ## t1468
;;								## 1
.trace 4
L4?3:
	c0    cmplt $b0.0 = $r0.2, 58   ## bblock 4, line 97,  t2065(I1),  t1468,  58(SI32)
	c0    mov $r0.25 = (~0x39)   ## [spec] bblock 7, line 0,  t1443,  (~0x39)(I32)
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 7, line 0,  t1442,  0(I32)
;;								## 0
	c0    brf $b0.0, L5?3   ## bblock 4, line 97,  t2065(I1)
;;								## 1
.trace 1
L6?3:
	c0    ldw.d $r0.8 = ((filter7x7 + 0) + 0)[$r0.0]   ## [spec] bblock 10, line 114, t70, 0(I32)
	c0    add $r0.19 = $r0.4, 1   ## [spec] bblock 10, line 111-1,  t2008,  t1442,  1(SI32)
	c0    add $r0.7 = $r0.4, $r0.6   ## [spec] bblock 10, line 114,  t74,  t1442,  t1469
	c0    add $r0.11 = $r0.2, 1   ## [spec] bblock 10, line 112-1,  t457,  t1468,  1(SI32)
	c0    ldw.d $r0.12 = (((filter7x7 + 0) + 4) + 0)[$r0.0]   ## [spec] bblock 10, line 114-1, t407, 0(I32)
	c0    add $r0.15 = $r0.2, 2   ## [spec] bblock 10, line 112-2,  t480,  t1468,  2(SI32)
	c0    ldw.d $r0.16 = (((filter7x7 + 0) + 8) + 0)[$r0.0]   ## [spec] bblock 10, line 114-2, t384, 0(I32)
	c0    add $r0.9 = $r0.2, 3   ## [spec] bblock 10, line 112-3,  t503,  t1468,  3(SI32)
	c0    ldw.d $r0.10 = (((filter7x7 + 0) + 12) + 0)[$r0.0]   ## [spec] bblock 10, line 114-3, t361, 0(I32)
	c0    add $r0.17 = $r0.2, 4   ## [spec] bblock 10, line 112-4,  t526,  t1468,  4(SI32)
	c0    ldw.d $r0.18 = (((filter7x7 + 0) + 16) + 0)[$r0.0]   ## [spec] bblock 10, line 114-4, t338, 0(I32)
	c0    add $r0.13 = $r0.2, 5   ## [spec] bblock 10, line 112-5,  t549,  t1468,  5(SI32)
	c0    ldw.d $r0.14 = (((filter7x7 + 0) + 20) + 0)[$r0.0]   ## [spec] bblock 10, line 114-5, t315, 0(I32)
	c0    add $r0.3 = $r0.2, 6   ## [spec] bblock 10, line 112-6,  t572,  t1468,  6(SI32)
	c0    ldw.d $r0.5 = (((filter7x7 + 0) + 24) + 0)[$r0.0]   ## [spec] bblock 10, line 114-6, t292, 0(I32)
	c0    ldw.d $r0.21 = (((filter7x7 + 0) + 36) + 0)[$r0.0]   ## [spec] bblock 10, line 114-1, t1322, 0(I32)
	c0    ldw.d $r0.22 = (((filter7x7 + 0) + 40) + 0)[$r0.0]   ## [spec] bblock 10, line 114-1, t1345, 0(I32)
	c0    ldw.d $r0.23 = (((filter7x7 + 0) + 48) + 0)[$r0.0]   ## [spec] bblock 10, line 114-1, t1391, 0(I32)
	c0    ldw.d $r0.20 = (((filter7x7 + 0) + 52) + 0)[$r0.0]   ## [spec] bblock 10, line 114-1, t1414, 0(I32)
;;								## 0
	c0    add $r0.27 = $r0.6, $r0.19   ## [spec] bblock 10, line 114-1,  t1278,  t1469,  t2008
	c0    sh2add $r0.7 = $r0.7, (conv7_image + 0)   ## [spec] bblock 10, line 114,  t77,  t74,  addr(conv7_image?1.0)(P32)
	c0    shl $r0.11 = $r0.11, 6   ## [spec] bblock 10, line 114-1,  t460,  t457,  6(I32)
	c0    shl $r0.15 = $r0.15, 6   ## [spec] bblock 10, line 114-2,  t483,  t480,  6(I32)
	c0    add $r0.30 = $r0.4, 2   ## [spec] bblock 10, line 111-2,  t2012,  t1442,  2(SI32)
	c0    shl $r0.9 = $r0.9, 6   ## [spec] bblock 10, line 114-3,  t506,  t503,  6(I32)
	c0    add $r0.38 = $r0.4, 3   ## [spec] bblock 10, line 111-3,  t2016,  t1442,  3(SI32)
	c0    shl $r0.17 = $r0.17, 6   ## [spec] bblock 10, line 114-4,  t529,  t526,  6(I32)
	c0    add $r0.40 = $r0.4, 4   ## [spec] bblock 10, line 111-4,  t2020,  t1442,  4(SI32)
	c0    shl $r0.13 = $r0.13, 6   ## [spec] bblock 10, line 114-5,  t552,  t549,  6(I32)
	c0    shl $r0.3 = $r0.3, 6   ## [spec] bblock 10, line 114-6,  t575,  t572,  6(I32)
;;								## 1
	c0    cmplt $b0.0 = $r0.25, $r0.0   ## bblock 8, line 98,  t2066(I1),  t1443,  0(SI32)
	c0    sh2add $r0.27 = $r0.27, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t1280,  t1278,  addr(conv7_image?1.0)(P32)
	c0    pft 32[$r0.7]   ## [spec] bblock 10, line 114,  t77,  32(I32)
	c0    ldw.d $r0.42 = 0[$r0.7]   ## [spec] bblock 10, line 114, t78, t77
	c0    add $r0.44 = $r0.4, $r0.11   ## [spec] bblock 10, line 114-1,  t409,  t1442,  t460
	c0    add $r0.52 = $r0.11, $r0.19   ## [spec] bblock 10, line 114-1,  t1301,  t460,  t2008
	c0    add $r0.46 = $r0.4, $r0.15   ## [spec] bblock 10, line 114-2,  t386,  t1442,  t483
	c0    add $r0.49 = $r0.15, $r0.19   ## [spec] bblock 10, line 114-1,  t1324,  t483,  t2008
	c0    add $r0.57 = $r0.6, $r0.30   ## [spec] bblock 10, line 114-2,  t1110,  t1469,  t2012
	c0    add $r0.58 = $r0.11, $r0.30   ## [spec] bblock 10, line 114-2,  t1133,  t460,  t2012
	c0    add $r0.54 = $r0.15, $r0.30   ## [spec] bblock 10, line 114-2,  t1156,  t483,  t2012
	c0    add $r0.43 = $r0.4, $r0.9   ## [spec] bblock 10, line 114-3,  t363,  t1442,  t506
	c0    add $r0.50 = $r0.9, $r0.19   ## [spec] bblock 10, line 114-1,  t1347,  t506,  t2008
	c0    add $r0.55 = $r0.9, $r0.30   ## [spec] bblock 10, line 114-2,  t1179,  t506,  t2012
	c0    add $r0.60 = $r0.15, $r0.38   ## [spec] bblock 10, line 114-3,  t988,  t483,  t2016
	c0    add $r0.62 = $r0.9, $r0.38   ## [spec] bblock 10, line 114-3,  t1011,  t506,  t2016
	c0    add $r0.47 = $r0.4, $r0.17   ## [spec] bblock 10, line 114-4,  t340,  t1442,  t529
	c0    add $r0.19 = $r0.17, $r0.19   ## [spec] bblock 10, line 114-1,  t1370,  t529,  t2008
	c0    add $r0.30 = $r0.17, $r0.30   ## [spec] bblock 10, line 114-2,  t1202,  t529,  t2012
	c0    add $r0.45 = $r0.4, $r0.13   ## [spec] bblock 10, line 114-5,  t317,  t1442,  t552
	c0    add $r0.51 = $r0.13, $r0.19   ## [spec] bblock 10, line 114-1,  t1393,  t552,  t2008
	c0    add $r0.56 = $r0.13, $r0.30   ## [spec] bblock 10, line 114-2,  t1225,  t552,  t2012
	c0    add $r0.41 = $r0.4, $r0.3   ## [spec] bblock 10, line 114-6,  t294,  t1442,  t575
	c0    add $r0.48 = $r0.3, $r0.19   ## [spec] bblock 10, line 114-1,  t1416,  t575,  t2008
	c0    add $r0.53 = $r0.3, $r0.30   ## [spec] bblock 10, line 114-2,  t1248,  t575,  t2012
	c0    add $r0.59 = $r0.3, $r0.38   ## [spec] bblock 10, line 114-3,  t1080,  t575,  t2016
;;								## 2
	c0    ldw.d $r0.27 = 0[$r0.27]   ## [spec] bblock 10, line 114-1, t1281, t1280
	c0    sh2add $r0.44 = $r0.44, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t411,  t409,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.52 = $r0.52, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t1303,  t1301,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.46 = $r0.46, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t388,  t386,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.49 = $r0.49, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t1326,  t1324,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.54 = $r0.54, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t1158,  t1156,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.43 = $r0.43, (conv7_image + 0)   ## [spec] bblock 10, line 114-3,  t365,  t363,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.50 = $r0.50, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t1349,  t1347,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.55 = $r0.55, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t1181,  t1179,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.47 = $r0.47, (conv7_image + 0)   ## [spec] bblock 10, line 114-4,  t342,  t340,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.19 = $r0.19, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t1372,  t1370,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.45 = $r0.45, (conv7_image + 0)   ## [spec] bblock 10, line 114-5,  t319,  t317,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.51 = $r0.51, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t1395,  t1393,  addr(conv7_image?1.0)(P32)
	c0    add $r0.7 = $r0.13, $r0.38   ## [spec] bblock 10, line 114-3,  t1057,  t552,  t2016
	c0    sh2add $r0.41 = $r0.41, (conv7_image + 0)   ## [spec] bblock 10, line 114-6,  t296,  t294,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.48 = $r0.48, (conv7_image + 0)   ## [spec] bblock 10, line 114-1,  t1418,  t1416,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.53 = $r0.53, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t1250,  t1248,  addr(conv7_image?1.0)(P32)
;;								## 3
	c0    shru $r0.63 = $r0.42, 16   ## [spec] bblock 10, line 114,  t43(I16),  t78,  16(SI32)
	c0    ldw.d $r0.44 = 0[$r0.44]   ## [spec] bblock 10, line 114-1, t412, t411
	c0    ldw.d $r0.52 = 0[$r0.52]   ## [spec] bblock 10, line 114-1, t1304, t1303
	c0    ldw.d $r0.46 = 0[$r0.46]   ## [spec] bblock 10, line 114-2, t389, t388
	c0    ldw.d $r0.49 = 0[$r0.49]   ## [spec] bblock 10, line 114-1, t1327, t1326
	c0    sh2add $r0.57 = $r0.57, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t1112,  t1110,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.58 = $r0.58, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t1135,  t1133,  addr(conv7_image?1.0)(P32)
	c0    ldw.d $r0.54 = 0[$r0.54]   ## [spec] bblock 10, line 114-2, t1159, t1158
	c0    ldw.d $r0.43 = 0[$r0.43]   ## [spec] bblock 10, line 114-3, t366, t365
	c0    ldw.d $r0.50 = 0[$r0.50]   ## [spec] bblock 10, line 114-1, t1350, t1349
	c0    ldw.d $r0.55 = 0[$r0.55]   ## [spec] bblock 10, line 114-2, t1182, t1181
	c0    sh2add $r0.60 = $r0.60, (conv7_image + 0)   ## [spec] bblock 10, line 114-3,  t990,  t988,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.62 = $r0.62, (conv7_image + 0)   ## [spec] bblock 10, line 114-3,  t1013,  t1011,  addr(conv7_image?1.0)(P32)
	c0    ldw.d $r0.47 = 0[$r0.47]   ## [spec] bblock 10, line 114-4, t343, t342
	c0    ldw.d $r0.19 = 0[$r0.19]   ## [spec] bblock 10, line 114-1, t1373, t1372
	c0    sh2add $r0.30 = $r0.30, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t1204,  t1202,  addr(conv7_image?1.0)(P32)
	c0    ldw.d $r0.45 = 0[$r0.45]   ## [spec] bblock 10, line 114-5, t320, t319
	c0    ldw.d $r0.51 = 0[$r0.51]   ## [spec] bblock 10, line 114-1, t1396, t1395
	c0    sh2add $r0.56 = $r0.56, (conv7_image + 0)   ## [spec] bblock 10, line 114-2,  t1227,  t1225,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.7 = $r0.7, (conv7_image + 0)   ## [spec] bblock 10, line 114-3,  t1059,  t1057,  addr(conv7_image?1.0)(P32)
	c0    ldw.d $r0.41 = 0[$r0.41]   ## [spec] bblock 10, line 114-6, t297, t296
	c0    ldw.d $r0.48 = 0[$r0.48]   ## [spec] bblock 10, line 114-1, t1419, t1418
	c0    ldw.d $r0.53 = 0[$r0.53]   ## [spec] bblock 10, line 114-2, t1251, t1250
	c0    sh2add $r0.59 = $r0.59, (conv7_image + 0)   ## [spec] bblock 10, line 114-3,  t1082,  t1080,  addr(conv7_image?1.0)(P32)
;;								## 4
	c0    shru $r0.61 = $r0.27, 16   ## [spec] bblock 10, line 114-1,  t1282(I16),  t1281,  16(SI32)
	c0    and $r0.63 = $r0.63, 255   ## [spec] bblock 10, line 114,  t44,  t43(I16),  255(I32)
	c0    ldw.d $r0.57 = 0[$r0.57]   ## [spec] bblock 10, line 114-2, t1113, t1112
	c0    ldw.d $r0.58 = 0[$r0.58]   ## [spec] bblock 10, line 114-2, t1136, t1135
	c0    ldw.d $r0.60 = 0[$r0.60]   ## [spec] bblock 10, line 114-3, t991, t990
	c0    ldw.d $r0.62 = 0[$r0.62]   ## [spec] bblock 10, line 114-3, t1014, t1013
	c0    ldw.d $r0.30 = 0[$r0.30]   ## [spec] bblock 10, line 114-2, t1205, t1204
	c0    ldw.d $r0.56 = 0[$r0.56]   ## [spec] bblock 10, line 114-2, t1228, t1227
	c0    ldw.d $r0.7 = 0[$r0.7]   ## [spec] bblock 10, line 114-3, t1060, t1059
	c0    ldw.d $r0.59 = 0[$r0.59]   ## [spec] bblock 10, line 114-3, t1083, t1082
	c0    brf $b0.0, L7?3   ## bblock 8, line 98,  t2066(I1)
;;								## 5
	c0    mpylu $r0.37 = $r0.8, $r0.63   ## bblock 10, line 114,  t2067,  t70,  t44
	c0    mpyhs $r0.63 = $r0.8, $r0.63   ## bblock 10, line 114,  t2068,  t70,  t44
	c0    and $r0.61 = $r0.61, 255   ## bblock 10, line 114-1,  t1283,  t1282(I16),  255(I32)
	c0    shru $r0.36 = $r0.44, 16   ## bblock 10, line 114-1,  t413(I16),  t412,  16(SI32)
	c0    shru $r0.34 = $r0.46, 16   ## bblock 10, line 114-2,  t390(I16),  t389,  16(SI32)
	c0    shru $r0.31 = $r0.49, 16   ## bblock 10, line 114-1,  t1328(I16),  t1327,  16(SI32)
	c0    shru $r0.8 = $r0.43, 16   ## bblock 10, line 114-3,  t367(I16),  t366,  16(SI32)
	c0    shru $r0.29 = $r0.50, 16   ## bblock 10, line 114-1,  t1351(I16),  t1350,  16(SI32)
	c0    shru $r0.33 = $r0.47, 16   ## bblock 10, line 114-4,  t344(I16),  t343,  16(SI32)
	c0    shru $r0.35 = $r0.45, 16   ## bblock 10, line 114-5,  t321(I16),  t320,  16(SI32)
	c0    shru $r0.28 = $r0.51, 16   ## bblock 10, line 114-1,  t1397(I16),  t1396,  16(SI32)
	c0    shru $r0.39 = $r0.41, 16   ## bblock 10, line 114-6,  t298(I16),  t297,  16(SI32)
	c0    shru $r0.32 = $r0.48, 16   ## bblock 10, line 114-1,  t1420(I16),  t1419,  16(SI32)
;;								## 6
	c0    and $r0.36 = $r0.36, 255   ## bblock 10, line 114-1,  t414,  t413(I16),  255(I32)
	c0    and $r0.34 = $r0.34, 255   ## bblock 10, line 114-2,  t391,  t390(I16),  255(I32)
	c0    and $r0.31 = $r0.31, 255   ## bblock 10, line 114-1,  t1329,  t1328(I16),  255(I32)
	c0    and $r0.8 = $r0.8, 255   ## bblock 10, line 114-3,  t368,  t367(I16),  255(I32)
	c0    and $r0.29 = $r0.29, 255   ## bblock 10, line 114-1,  t1352,  t1351(I16),  255(I32)
	c0    and $r0.33 = $r0.33, 255   ## bblock 10, line 114-4,  t345,  t344(I16),  255(I32)
	c0    and $r0.35 = $r0.35, 255   ## bblock 10, line 114-5,  t322,  t321(I16),  255(I32)
	c0    and $r0.28 = $r0.28, 255   ## bblock 10, line 114-1,  t1398,  t1397(I16),  255(I32)
	c0    and $r0.39 = $r0.39, 255   ## bblock 10, line 114-6,  t299,  t298(I16),  255(I32)
	c0    and $r0.32 = $r0.32, 255   ## bblock 10, line 114-1,  t1421,  t1420(I16),  255(I32)
;;								## 7
	c0    add $r0.37 = $r0.37, $r0.63   ## bblock 10, line 114,  t45,  t2067,  t2068
	c0    mpylu $r0.63 = $r0.10, $r0.8   ## bblock 10, line 114-3,  t2112,  t361,  t368
	c0    mpyhs $r0.8 = $r0.10, $r0.8   ## bblock 10, line 114-3,  t2113,  t361,  t368
	c0    mpylu $r0.14 = $r0.18, $r0.33   ## bblock 10, line 114-4,  t2127,  t338,  t345
	c0    mpyhs $r0.33 = $r0.18, $r0.33   ## bblock 10, line 114-4,  t2128,  t338,  t345
	c0    mpylu $r0.10 = $r0.14, $r0.35   ## bblock 10, line 114-5,  t2142,  t315,  t322
	c0    mpyhs $r0.35 = $r0.14, $r0.35   ## bblock 10, line 114-5,  t2143,  t315,  t322
	c0    add $r0.5 = $r0.3, $r0.40   ## bblock 10, line 114-4,  t912,  t575,  t2020
	c0    mpylu $r0.24 = $r0.5, $r0.39   ## bblock 10, line 114-6,  t2157,  t292,  t299
	c0    mpyhs $r0.39 = $r0.5, $r0.39   ## bblock 10, line 114-6,  t2158,  t292,  t299
	c0    mpylu $r0.18 = $r0.21, $r0.31   ## bblock 10, line 114-1,  t2217,  t1322,  t1329
	c0    mpyhs $r0.31 = $r0.21, $r0.31   ## bblock 10, line 114-1,  t2218,  t1322,  t1329
	c0    mpylu $r0.21 = $r0.23, $r0.28   ## bblock 10, line 114-1,  t2262,  t1391,  t1398
	c0    mpyhs $r0.28 = $r0.23, $r0.28   ## bblock 10, line 114-1,  t2263,  t1391,  t1398
;;								## 8
	c0    cmplt $b0.0 = $r0.37, $r0.0   ## bblock 10, line 114,  t2071,  t45,  0(I32)
	c0    add $r0.23 = $r0.37, 255   ## bblock 10, line 114,  t2072,  t45,  255(I32)
	c0    sh2add $r0.5 = $r0.5, (conv7_image + 0)   ## bblock 10, line 114-4,  t914,  t912,  addr(conv7_image?1.0)(P32)
;;								## 9
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.37   ## bblock 10, line 114,  t2073,  t2071,  t2072,  t45
	c0    mpylu $r0.8 = $r0.12, $r0.36   ## bblock 10, line 114-1,  t2082,  t407,  t414
	c0    mpyhs $r0.36 = $r0.12, $r0.36   ## bblock 10, line 114-1,  t2083,  t407,  t414
	c0    shru $r0.37 = $r0.52, 16   ## bblock 10, line 114-1,  t1305(I16),  t1304,  16(SI32)
	c0    mpylu $r0.35 = $r0.16, $r0.34   ## bblock 10, line 114-2,  t2097,  t384,  t391
	c0    mpyhs $r0.34 = $r0.16, $r0.34   ## bblock 10, line 114-2,  t2098,  t384,  t391
	c0    add $r0.63 = $r0.63, $r0.8   ## bblock 10, line 114-3,  t369,  t2112,  t2113
	c0    add $r0.16 = $r0.15, $r0.40   ## bblock 10, line 114-4,  t820,  t483,  t2020
	c0    add $r0.2 = $r0.9, $r0.40   ## bblock 10, line 114-4,  t843,  t506,  t2020
	c0    add $r0.14 = $r0.14, $r0.33   ## bblock 10, line 114-4,  t346,  t2127,  t2128
	c0    add $r0.10 = $r0.10, $r0.35   ## bblock 10, line 114-5,  t323,  t2142,  t2143
	c0    ldw $r0.5 = 0[$r0.5]   ## bblock 10, line 114-4, t915, t914
	c0    add $r0.24 = $r0.24, $r0.39   ## bblock 10, line 114-6,  t300,  t2157,  t2158
	c0    add $r0.18 = $r0.18, $r0.31   ## bblock 10, line 114-1,  t1330,  t2217,  t2218
	c0    mpylu $r0.31 = $r0.22, $r0.29   ## bblock 10, line 114-1,  t2232,  t1345,  t1352
	c0    mpyhs $r0.29 = $r0.22, $r0.29   ## bblock 10, line 114-1,  t2233,  t1345,  t1352
	c0    add $r0.21 = $r0.21, $r0.28   ## bblock 10, line 114-1,  t1399,  t2262,  t2263
	c0    mpylu $r0.33 = $r0.20, $r0.32   ## bblock 10, line 114-1,  t2277,  t1414,  t1421
	c0    mpyhs $r0.32 = $r0.20, $r0.32   ## bblock 10, line 114-1,  t2278,  t1414,  t1421
	c0    ldw $r0.39 = (((filter7x7 + 0) + 32) + 0)[$r0.0]   ## bblock 10, line 114-1, t1299, 0(I32)
	c0    ldw $r0.28 = (((filter7x7 + 0) + 28) + 0)[$r0.0]   ## bblock 10, line 114-1, t1276, 0(I32)
	c0    stw 0x18[$r0.1] = $r0.25  ## spill ## t1443
;;								## 10
	c0    shr $r0.23 = $r0.23, 8   ## bblock 10, line 114,  t200,  t2073,  8(I32)
	c0    and $r0.37 = $r0.37, 255   ## bblock 10, line 114-1,  t1306,  t1305(I16),  255(I32)
	c0    cmplt $b0.1 = $r0.63, $r0.0   ## bblock 10, line 114-3,  t2114,  t369,  0(I32)
	c0    add $r0.12 = $r0.63, 255   ## bblock 10, line 114-3,  t2115,  t369,  255(I32)
	c0    sh2add $r0.16 = $r0.16, (conv7_image + 0)   ## bblock 10, line 114-4,  t822,  t820,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.2 = $r0.2, (conv7_image + 0)   ## bblock 10, line 114-4,  t845,  t843,  addr(conv7_image?1.0)(P32)
	c0    cmplt $b0.3 = $r0.14, $r0.0   ## bblock 10, line 114-4,  t2129,  t346,  0(I32)
	c0    cmplt $b0.2 = $r0.10, $r0.0   ## bblock 10, line 114-5,  t2144,  t323,  0(I32)
	c0    cmplt $b0.0 = $r0.24, $r0.0   ## bblock 10, line 114-6,  t2159,  t300,  0(I32)
	c0    add $r0.25 = $r0.24, 255   ## bblock 10, line 114-6,  t2160,  t300,  255(I32)
	c0    cmplt $b0.4 = $r0.18, $r0.0   ## bblock 10, line 114-1,  t2219,  t1330,  0(I32)
	c0    cmplt $b0.5 = $r0.21, $r0.0   ## bblock 10, line 114-1,  t2264,  t1399,  0(I32)
;;								## 11
	c0    add $r0.8 = $r0.8, $r0.36   ## bblock 10, line 114-1,  t415,  t2082,  t2083
	c0    add $r0.35 = $r0.35, $r0.34   ## bblock 10, line 114-2,  t392,  t2097,  t2098
	c0    slct $r0.12 = $b0.1, $r0.12, $r0.63   ## bblock 10, line 114-3,  t2116,  t2114,  t2115,  t369
	c0    ldw $r0.16 = 0[$r0.16]   ## bblock 10, line 114-4, t823, t822
	c0    ldw $r0.2 = 0[$r0.2]   ## bblock 10, line 114-4, t846, t845
	c0    add $r0.34 = $r0.14, 255   ## bblock 10, line 114-4,  t2130,  t346,  255(I32)
	c0    add $r0.28 = $r0.4, 5   ## bblock 10, line 111-5,  t2024,  t1442,  5(SI32)
	c0    add $r0.24 = $r0.10, 255   ## bblock 10, line 114-5,  t2145,  t323,  255(I32)
	c0    slct $r0.25 = $b0.0, $r0.25, $r0.24   ## bblock 10, line 114-6,  t2161,  t2159,  t2160,  t300
	c0    mpylu $r0.36 = $r0.28, $r0.61   ## bblock 10, line 114-1,  t2187,  t1276,  t1283
	c0    mpyhs $r0.61 = $r0.28, $r0.61   ## bblock 10, line 114-1,  t2188,  t1276,  t1283
	c0    mpylu $r0.63 = $r0.39, $r0.37   ## bblock 10, line 114-1,  t2202,  t1299,  t1306
	c0    mpyhs $r0.37 = $r0.39, $r0.37   ## bblock 10, line 114-1,  t2203,  t1299,  t1306
	c0    add $r0.32 = $r0.18, 255   ## bblock 10, line 114-1,  t2220,  t1330,  255(I32)
	c0    add $r0.31 = $r0.31, $r0.29   ## bblock 10, line 114-1,  t1353,  t2232,  t2233
	c0    add $r0.29 = $r0.21, 255   ## bblock 10, line 114-1,  t2265,  t1399,  255(I32)
	c0    add $r0.33 = $r0.33, $r0.32   ## bblock 10, line 114-1,  t1422,  t2277,  t2278
;;								## 12
	c0    cmplt $b0.0 = $r0.8, $r0.0   ## bblock 10, line 114-1,  t2084,  t415,  0(I32)
	c0    add $r0.39 = $r0.8, 255   ## bblock 10, line 114-1,  t2085,  t415,  255(I32)
	c0    cmplt $b0.1 = $r0.35, $r0.0   ## bblock 10, line 114-2,  t2099,  t392,  0(I32)
	c0    add $r0.10 = $r0.35, 255   ## bblock 10, line 114-2,  t2100,  t392,  255(I32)
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-3,  t372,  t2116,  8(I32)
	c0    shru $r0.21 = $r0.19, 16   ## bblock 10, line 114-1,  t1374(I16),  t1373,  16(SI32)
	c0    slct $r0.34 = $b0.3, $r0.34, $r0.14   ## bblock 10, line 114-4,  t2131,  t2129,  t2130,  t346
	c0    slct $r0.24 = $b0.2, $r0.24, $r0.10   ## bblock 10, line 114-5,  t2146,  t2144,  t2145,  t323
	c0    shr $r0.25 = $r0.25, 8   ## bblock 10, line 114-6,  t303,  t2161,  8(I32)
	c0    slct $r0.32 = $b0.4, $r0.32, $r0.18   ## bblock 10, line 114-1,  t2221,  t2219,  t2220,  t1330
	c0    cmplt $b0.3 = $r0.31, $r0.0   ## bblock 10, line 114-1,  t2234,  t1353,  0(I32)
	c0    add $r0.18 = $r0.31, 255   ## bblock 10, line 114-1,  t2235,  t1353,  255(I32)
	c0    slct $r0.29 = $b0.5, $r0.29, $r0.21   ## bblock 10, line 114-1,  t2266,  t2264,  t2265,  t1399
	c0    cmplt $b0.2 = $r0.33, $r0.0   ## bblock 10, line 114-1,  t2279,  t1422,  0(I32)
	c0    add $r0.14 = $r0.33, 255   ## bblock 10, line 114-1,  t2280,  t1422,  255(I32)
;;								## 13
	c0    slct $r0.39 = $b0.0, $r0.39, $r0.8   ## bblock 10, line 114-1,  t2086,  t2084,  t2085,  t415
	c0    shru $r0.26 = $r0.57, 16   ## bblock 10, line 114-2,  t1114(I16),  t1113,  16(SI32)
	c0    shru $r0.35 = $r0.54, 16   ## bblock 10, line 114-2,  t1160(I16),  t1159,  16(SI32)
	c0    slct $r0.10 = $b0.1, $r0.10, $r0.35   ## bblock 10, line 114-2,  t2101,  t2099,  t2100,  t392
	c0    shru $r0.61 = $r0.55, 16   ## bblock 10, line 114-2,  t1183(I16),  t1182,  16(SI32)
	c0    and $r0.21 = $r0.21, 255   ## bblock 10, line 114-1,  t1375,  t1374(I16),  255(I32)
	c0    shr $r0.34 = $r0.34, 8   ## bblock 10, line 114-4,  t349,  t2131,  8(I32)
	c0    shru $r0.20 = $r0.56, 16   ## bblock 10, line 114-2,  t1229(I16),  t1228,  16(SI32)
	c0    shr $r0.24 = $r0.24, 8   ## bblock 10, line 114-5,  t326,  t2146,  8(I32)
	c0    shru $r0.31 = $r0.53, 16   ## bblock 10, line 114-2,  t1252(I16),  t1251,  16(SI32)
	c0    add $r0.23 = $r0.23, $r0.25   ## bblock 10, line 114-6,  t2162,  t200,  t303
	c0    add $r0.36 = $r0.36, $r0.61   ## bblock 10, line 114-1,  t1284,  t2187,  t2188
	c0    add $r0.63 = $r0.63, $r0.37   ## bblock 10, line 114-1,  t1307,  t2202,  t2203
	c0    shr $r0.32 = $r0.32, 8   ## bblock 10, line 114-1,  t1333,  t2221,  8(I32)
	c0    slct $r0.18 = $b0.3, $r0.18, $r0.31   ## bblock 10, line 114-1,  t2236,  t2234,  t2235,  t1353
	c0    shr $r0.29 = $r0.29, 8   ## bblock 10, line 114-1,  t1402,  t2266,  8(I32)
	c0    slct $r0.14 = $b0.2, $r0.14, $r0.33   ## bblock 10, line 114-1,  t2281,  t2279,  t2280,  t1422
	c0    ldw $r0.22 = (((filter7x7 + 0) + 76) + 0)[$r0.0]   ## bblock 10, line 114-2, t1223, 0(I32)
	c0    ldw $r0.25 = (((filter7x7 + 0) + 68) + 0)[$r0.0]   ## bblock 10, line 114-2, t1177, 0(I32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 64) + 0)[$r0.0]   ## bblock 10, line 114-2, t1154, 0(I32)
	c0    ldw $r0.33 = (((filter7x7 + 0) + 80) + 0)[$r0.0]   ## bblock 10, line 114-2, t1246, 0(I32)
	c0    ldw $r0.8 = (((filter7x7 + 0) + 44) + 0)[$r0.0]   ## bblock 10, line 114-1, t1368, 0(I32)
	c0    stw 0x20[$r0.1] = $r0.57  ## spill ## [spec] t1113
;;								## 14
	c0    shr $r0.39 = $r0.39, 8   ## bblock 10, line 114-1,  t418,  t2086,  8(I32)
	c0    and $r0.26 = $r0.26, 255   ## bblock 10, line 114-2,  t1115,  t1114(I16),  255(I32)
	c0    and $r0.35 = $r0.35, 255   ## bblock 10, line 114-2,  t1161,  t1160(I16),  255(I32)
	c0    shr $r0.10 = $r0.10, 8   ## bblock 10, line 114-2,  t395,  t2101,  8(I32)
	c0    and $r0.61 = $r0.61, 255   ## bblock 10, line 114-2,  t1184,  t1183(I16),  255(I32)
	c0    and $r0.20 = $r0.20, 255   ## bblock 10, line 114-2,  t1230,  t1229(I16),  255(I32)
	c0    and $r0.31 = $r0.31, 255   ## bblock 10, line 114-2,  t1253,  t1252(I16),  255(I32)
	c0    add $r0.23 = $r0.23, $r0.12   ## bblock 10, line 114-6,  t2165,  t2162,  t372
	c0    cmplt $b0.0 = $r0.36, $r0.0   ## bblock 10, line 114-1,  t2189,  t1284,  0(I32)
	c0    add $r0.12 = $r0.36, 255   ## bblock 10, line 114-1,  t2190,  t1284,  255(I32)
	c0    cmplt $b0.1 = $r0.63, $r0.0   ## bblock 10, line 114-1,  t2204,  t1307,  0(I32)
	c0    add $r0.57 = $r0.63, 255   ## bblock 10, line 114-1,  t2205,  t1307,  255(I32)
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 114-1,  t1356,  t2236,  8(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 114-1,  t1425,  t2281,  8(I32)
;;								## 15
	c0    add $r0.8 = $r0.15, $r0.28   ## bblock 10, line 114-5,  t652,  t483,  t2024
	c0    add $r0.37 = $r0.3, $r0.28   ## bblock 10, line 114-5,  t744,  t575,  t2024
	c0    add $r0.39 = $r0.39, $r0.24   ## bblock 10, line 114-6,  t2163,  t418,  t326
	c0    add $r0.10 = $r0.10, $r0.34   ## bblock 10, line 114-6,  t2164,  t395,  t349
	c0    slct $r0.12 = $b0.0, $r0.12, $r0.36   ## bblock 10, line 114-1,  t2191,  t2189,  t2190,  t1284
	c0    slct $r0.57 = $b0.1, $r0.57, $r0.63   ## bblock 10, line 114-1,  t2206,  t2204,  t2205,  t1307
	c0    mpylu $r0.18 = $r0.8, $r0.21   ## bblock 10, line 114-1,  t2247,  t1368,  t1375
	c0    mpyhs $r0.21 = $r0.8, $r0.21   ## bblock 10, line 114-1,  t2248,  t1368,  t1375
	c0    add $r0.32 = $r0.32, $r0.18   ## bblock 10, line 114-1,  t2285,  t1333,  t1356
	c0    mpylu $r0.34 = $r0.37, $r0.35   ## bblock 10, line 114-2,  t2340,  t1154,  t1161
	c0    mpyhs $r0.35 = $r0.37, $r0.35   ## bblock 10, line 114-2,  t2341,  t1154,  t1161
	c0    mpylu $r0.36 = $r0.25, $r0.61   ## bblock 10, line 114-2,  t2355,  t1177,  t1184
	c0    mpyhs $r0.61 = $r0.25, $r0.61   ## bblock 10, line 114-2,  t2356,  t1177,  t1184
	c0    mpylu $r0.63 = $r0.22, $r0.20   ## bblock 10, line 114-2,  t2385,  t1223,  t1230
	c0    mpyhs $r0.20 = $r0.22, $r0.20   ## bblock 10, line 114-2,  t2386,  t1223,  t1230
	c0    mpylu $r0.24 = $r0.33, $r0.31   ## bblock 10, line 114-2,  t2400,  t1246,  t1253
	c0    mpyhs $r0.31 = $r0.33, $r0.31   ## bblock 10, line 114-2,  t2401,  t1246,  t1253
	c0    stw 0x24[$r0.1] = $r0.22  ## spill ## t1223
;;								## 16
	c0    shru $r0.22 = $r0.58, 16   ## bblock 10, line 114-2,  t1137(I16),  t1136,  16(SI32)
	c0    sh2add $r0.8 = $r0.8, (conv7_image + 0)   ## bblock 10, line 114-5,  t654,  t652,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.37 = $r0.37, (conv7_image + 0)   ## bblock 10, line 114-5,  t746,  t744,  addr(conv7_image?1.0)(P32)
	c0    add $r0.39 = $r0.39, $r0.10   ## bblock 10, line 114-6,  t2166,  t2163,  t2164
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-1,  t1287,  t2191,  8(I32)
	c0    shr $r0.57 = $r0.57, 8   ## bblock 10, line 114-1,  t1310,  t2206,  8(I32)
	c0    ldw $r0.10 = (((filter7x7 + 0) + 56) + 0)[$r0.0]   ## bblock 10, line 114-2, t1108, 0(I32)
;;								## 17
	c0    and $r0.22 = $r0.22, 255   ## bblock 10, line 114-2,  t1138,  t1137(I16),  255(I32)
	c0    shru $r0.35 = $r0.60, 16   ## bblock 10, line 114-3,  t992(I16),  t991,  16(SI32)
	c0    shru $r0.33 = $r0.62, 16   ## bblock 10, line 114-3,  t1015(I16),  t1014,  16(SI32)
	c0    shru $r0.21 = $r0.30, 16   ## bblock 10, line 114-2,  t1206(I16),  t1205,  16(SI32)
	c0    ldw $r0.8 = 0[$r0.8]   ## bblock 10, line 114-5, t655, t654
	c0    shru $r0.31 = $r0.59, 16   ## bblock 10, line 114-3,  t1084(I16),  t1083,  16(SI32)
	c0    ldw $r0.37 = 0[$r0.37]   ## bblock 10, line 114-5, t747, t746
	c0    add $r0.23 = $r0.23, $r0.39   ## bblock 10, line 114-6,  t2011,  t2165,  t2166
	c0    add $r0.18 = $r0.18, $r0.21   ## bblock 10, line 114-1,  t1376,  t2247,  t2248
	c0    add $r0.12 = $r0.12, $r0.29   ## bblock 10, line 114-1,  t2283,  t1287,  t1402
	c0    add $r0.34 = $r0.34, $r0.35   ## bblock 10, line 114-2,  t1162,  t2340,  t2341
	c0    add $r0.36 = $r0.36, $r0.61   ## bblock 10, line 114-2,  t1185,  t2355,  t2356
	c0    add $r0.63 = $r0.63, $r0.20   ## bblock 10, line 114-2,  t1231,  t2385,  t2386
	c0    add $r0.24 = $r0.24, $r0.31   ## bblock 10, line 114-2,  t1254,  t2400,  t2401
	c0    ldw $r0.39 = (((filter7x7 + 0) + 108) + 0)[$r0.0]   ## bblock 10, line 114-3, t1078, 0(I32)
	c0    ldw $r0.29 = (((filter7x7 + 0) + 72) + 0)[$r0.0]   ## bblock 10, line 114-2, t1200, 0(I32)
	c0    ldw $r0.20 = (((filter7x7 + 0) + 60) + 0)[$r0.0]   ## bblock 10, line 114-2, t1131, 0(I32)
;;								## 18
	c0    and $r0.35 = $r0.35, 255   ## bblock 10, line 114-3,  t993,  t992(I16),  255(I32)
	c0    and $r0.33 = $r0.33, 255   ## bblock 10, line 114-3,  t1016,  t1015(I16),  255(I32)
	c0    and $r0.21 = $r0.21, 255   ## bblock 10, line 114-2,  t1207,  t1206(I16),  255(I32)
	c0    and $r0.31 = $r0.31, 255   ## bblock 10, line 114-3,  t1085,  t1084(I16),  255(I32)
	c0    cmplt $b0.0 = $r0.18, $r0.0   ## bblock 10, line 114-1,  t2249,  t1376,  0(I32)
	c0    add $r0.14 = $r0.18, 255   ## bblock 10, line 114-1,  t2250,  t1376,  255(I32)
	c0    add $r0.23 = $r0.23, $r0.14   ## bblock 10, line 114-1,  t2282,  t2011,  t1425
	c0    mpyhs $r0.25 = $r0.10, $r0.26   ## bblock 10, line 114-2,  t2311,  t1108,  t1115
	c0    cmplt $b0.2 = $r0.34, $r0.0   ## bblock 10, line 114-2,  t2342,  t1162,  0(I32)
	c0    cmplt $b0.3 = $r0.36, $r0.0   ## bblock 10, line 114-2,  t2357,  t1185,  0(I32)
	c0    cmplt $b0.4 = $r0.63, $r0.0   ## bblock 10, line 114-2,  t2387,  t1231,  0(I32)
	c0    cmplt $b0.1 = $r0.24, $r0.0   ## bblock 10, line 114-2,  t2402,  t1254,  0(I32)
;;								## 19
	c0    slct $r0.14 = $b0.0, $r0.14, $r0.18   ## bblock 10, line 114-1,  t2251,  t2249,  t2250,  t1376
	c0    add $r0.23 = $r0.23, $r0.32   ## bblock 10, line 114-1,  t2286,  t2282,  t2285
	c0    mpylu $r0.26 = $r0.10, $r0.26   ## bblock 10, line 114-2,  t2310,  t1108,  t1115
	c0    add $r0.32 = $r0.34, 255   ## bblock 10, line 114-2,  t2343,  t1162,  255(I32)
	c0    mpyhs $r0.10 = $r0.29, $r0.21   ## bblock 10, line 114-2,  t2371,  t1200,  t1207
	c0    add $r0.18 = $r0.24, 255   ## bblock 10, line 114-2,  t2403,  t1254,  255(I32)
	c0    mpyhs $r0.61 = $r0.39, $r0.31   ## bblock 10, line 114-3,  t2524,  t1078,  t1085
;;								## 20
	c0    shru $r0.39 = $r0.37, 16   ## bblock 10, line 114-5,  t748(I16),  t747,  16(SI32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 114-1,  t1379,  t2251,  8(I32)
	c0    slct $r0.32 = $b0.2, $r0.32, $r0.34   ## bblock 10, line 114-2,  t2344,  t2342,  t2343,  t1162
	c0    add $r0.24 = $r0.36, 255   ## bblock 10, line 114-2,  t2358,  t1185,  255(I32)
	c0    mpylu $r0.21 = $r0.29, $r0.21   ## bblock 10, line 114-2,  t2370,  t1200,  t1207
	c0    add $r0.34 = $r0.63, 255   ## bblock 10, line 114-2,  t2388,  t1231,  255(I32)
	c0    slct $r0.18 = $b0.1, $r0.18, $r0.24   ## bblock 10, line 114-2,  t2404,  t2402,  t2403,  t1254
	c0    mpylu $r0.31 = $r0.39, $r0.31   ## bblock 10, line 114-3,  t2523,  t1078,  t1085
	c0    stw 0x28[$r0.1] = $r0.37  ## spill ## t747
;;								## 21
	c0    shru $r0.37 = $r0.7, 16   ## bblock 10, line 114-3,  t1061(I16),  t1060,  16(SI32)
	c0    shru $r0.29 = $r0.5, 16   ## bblock 10, line 114-4,  t916(I16),  t915,  16(SI32)
	c0    and $r0.39 = $r0.39, 255   ## bblock 10, line 114-5,  t749,  t748(I16),  255(I32)
	c0    add $r0.57 = $r0.57, $r0.14   ## bblock 10, line 114-1,  t2284,  t1310,  t1379
	c0    add $r0.26 = $r0.26, $r0.25   ## bblock 10, line 114-2,  t1116,  t2310,  t2311
	c0    mpylu $r0.14 = $r0.20, $r0.22   ## bblock 10, line 114-2,  t2325,  t1131,  t1138
	c0    mpyhs $r0.22 = $r0.20, $r0.22   ## bblock 10, line 114-2,  t2326,  t1131,  t1138
	c0    shr $r0.32 = $r0.32, 8   ## bblock 10, line 114-2,  t1165,  t2344,  8(I32)
	c0    slct $r0.24 = $b0.3, $r0.24, $r0.36   ## bblock 10, line 114-2,  t2359,  t2357,  t2358,  t1185
	c0    slct $r0.34 = $b0.4, $r0.34, $r0.63   ## bblock 10, line 114-2,  t2389,  t2387,  t2388,  t1231
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 114-2,  t1257,  t2404,  8(I32)
	c0    ldw $r0.25 = (((filter7x7 + 0) + 104) + 0)[$r0.0]   ## bblock 10, line 114-3, t1055, 0(I32)
	c0    ldw $r0.63 = (((filter7x7 + 0) + 96) + 0)[$r0.0]   ## bblock 10, line 114-3, t1009, 0(I32)
	c0    ldw $r0.36 = (((filter7x7 + 0) + 92) + 0)[$r0.0]   ## bblock 10, line 114-3, t986, 0(I32)
	c0    stw 0x2c[$r0.1] = $r0.5  ## spill ## t915
;;								## 22
	c0    add $r0.10 = $r0.6, $r0.38   ## bblock 10, line 114-3,  t942,  t1469,  t2016
	c0    add $r0.61 = $r0.11, $r0.38   ## bblock 10, line 114-3,  t965,  t460,  t2016
	c0    add $r0.38 = $r0.17, $r0.38   ## bblock 10, line 114-3,  t1034,  t529,  t2016
	c0    and $r0.37 = $r0.37, 255   ## bblock 10, line 114-3,  t1062,  t1061(I16),  255(I32)
	c0    and $r0.29 = $r0.29, 255   ## bblock 10, line 114-4,  t917,  t916(I16),  255(I32)
	c0    add $r0.12 = $r0.12, $r0.57   ## bblock 10, line 114-1,  t2287,  t2283,  t2284
	c0    cmplt $b0.0 = $r0.26, $r0.0   ## bblock 10, line 114-2,  t2312,  t1116,  0(I32)
	c0    add $r0.5 = $r0.26, 255   ## bblock 10, line 114-2,  t2313,  t1116,  255(I32)
	c0    shr $r0.24 = $r0.24, 8   ## bblock 10, line 114-2,  t1188,  t2359,  8(I32)
	c0    add $r0.21 = $r0.21, $r0.10   ## bblock 10, line 114-2,  t1208,  t2370,  t2371
	c0    shr $r0.34 = $r0.34, 8   ## bblock 10, line 114-2,  t1234,  t2389,  8(I32)
	c0    ldw $r0.57 = (((filter7x7 + 0) + 84) + 0)[$r0.0]   ## bblock 10, line 114-3, t940, 0(I32)
	c0    ldw $r0.20 = (((filter7x7 + 0) + 88) + 0)[$r0.0]   ## bblock 10, line 114-3, t963, 0(I32)
	c0    add $r0.31 = $r0.31, $r0.61   ## bblock 10, line 114-3,  t1086,  t2523,  t2524
;;								## 23
	c0    sh2add $r0.10 = $r0.10, (conv7_image + 0)   ## bblock 10, line 114-3,  t944,  t942,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.61 = $r0.61, (conv7_image + 0)   ## bblock 10, line 114-3,  t967,  t965,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.38 = $r0.38, (conv7_image + 0)   ## bblock 10, line 114-3,  t1036,  t1034,  addr(conv7_image?1.0)(P32)
	c0    add $r0.23 = $r0.23, $r0.12   ## bblock 10, line 114-1,  t2015,  t2286,  t2287
	c0    slct $r0.5 = $b0.0, $r0.5, $r0.26   ## bblock 10, line 114-2,  t2314,  t2312,  t2313,  t1116
	c0    add $r0.14 = $r0.14, $r0.22   ## bblock 10, line 114-2,  t1139,  t2325,  t2326
	c0    cmplt $b0.0 = $r0.21, $r0.0   ## bblock 10, line 114-2,  t2372,  t1208,  0(I32)
	c0    add $r0.12 = $r0.21, 255   ## bblock 10, line 114-2,  t2373,  t1208,  255(I32)
	c0    add $r0.32 = $r0.32, $r0.24   ## bblock 10, line 114-2,  t2408,  t1165,  t1188
	c0    mpylu $r0.24 = $r0.36, $r0.35   ## bblock 10, line 114-3,  t2463,  t986,  t993
	c0    mpyhs $r0.35 = $r0.36, $r0.35   ## bblock 10, line 114-3,  t2464,  t986,  t993
	c0    mpylu $r0.26 = $r0.63, $r0.33   ## bblock 10, line 114-3,  t2478,  t1009,  t1016
	c0    mpyhs $r0.33 = $r0.63, $r0.33   ## bblock 10, line 114-3,  t2479,  t1009,  t1016
	c0    cmplt $b0.1 = $r0.31, $r0.0   ## bblock 10, line 114-3,  t2525,  t1086,  0(I32)
	c0    add $r0.22 = $r0.31, 255   ## bblock 10, line 114-3,  t2526,  t1086,  255(I32)
;;								## 24
	c0    ldw $r0.10 = 0[$r0.10]   ## bblock 10, line 114-3, t945, t944
	c0    ldw $r0.61 = 0[$r0.61]   ## bblock 10, line 114-3, t968, t967
	c0    ldw $r0.38 = 0[$r0.38]   ## bblock 10, line 114-3, t1037, t1036
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 114-2,  t1119,  t2314,  8(I32)
	c0    cmplt $b0.2 = $r0.14, $r0.0   ## bblock 10, line 114-2,  t2327,  t1139,  0(I32)
	c0    add $r0.18 = $r0.14, 255   ## bblock 10, line 114-2,  t2328,  t1139,  255(I32)
	c0    slct $r0.12 = $b0.0, $r0.12, $r0.21   ## bblock 10, line 114-2,  t2374,  t2372,  t2373,  t1208
	c0    add $r0.23 = $r0.23, $r0.18   ## bblock 10, line 114-2,  t2405,  t2015,  t1257
	c0    mpylu $r0.21 = $r0.25, $r0.37   ## bblock 10, line 114-3,  t2508,  t1055,  t1062
	c0    mpyhs $r0.37 = $r0.25, $r0.37   ## bblock 10, line 114-3,  t2509,  t1055,  t1062
	c0    slct $r0.22 = $b0.1, $r0.22, $r0.31   ## bblock 10, line 114-3,  t2527,  t2525,  t2526,  t1086
	c0    ldw $r0.31 = (((filter7x7 + 0) + 100) + 0)[$r0.0]   ## bblock 10, line 114-3, t1032, 0(I32)
;;								## 25
	c0    add $r0.36 = $r0.6, $r0.40   ## bblock 10, line 114-4,  t774,  t1469,  t2020
	c0    shru $r0.32 = $r0.16, 16   ## bblock 10, line 114-4,  t824(I16),  t823,  16(SI32)
	c0    shru $r0.34 = $r0.2, 16   ## bblock 10, line 114-4,  t847(I16),  t846,  16(SI32)
	c0    add $r0.25 = $r0.13, $r0.40   ## bblock 10, line 114-4,  t889,  t552,  t2020
	c0    slct $r0.18 = $b0.2, $r0.18, $r0.14   ## bblock 10, line 114-2,  t2329,  t2327,  t2328,  t1139
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-2,  t1211,  t2374,  8(I32)
	c0    add $r0.5 = $r0.5, $r0.34   ## bblock 10, line 114-2,  t2406,  t1119,  t1234
	c0    add $r0.23 = $r0.23, $r0.32   ## bblock 10, line 114-2,  t2409,  t2405,  t2408
	c0    add $r0.24 = $r0.24, $r0.35   ## bblock 10, line 114-3,  t994,  t2463,  t2464
	c0    add $r0.26 = $r0.26, $r0.33   ## bblock 10, line 114-3,  t1017,  t2478,  t2479
	c0    shr $r0.22 = $r0.22, 8   ## bblock 10, line 114-3,  t1089,  t2527,  8(I32)
	c0    ldw $r0.33 = (((filter7x7 + 0) + 120) + 0)[$r0.0]   ## bblock 10, line 114-4, t818, 0(I32)
	c0    ldw $r0.14 = (((filter7x7 + 0) + 136) + 0)[$r0.0]   ## bblock 10, line 114-4, t910, 0(I32)
;;								## 26
	c0    shru $r0.37 = $r0.10, 16   ## bblock 10, line 114-3,  t946(I16),  t945,  16(SI32)
	c0    sh2add $r0.36 = $r0.36, (conv7_image + 0)   ## bblock 10, line 114-4,  t776,  t774,  addr(conv7_image?1.0)(P32)
	c0    and $r0.32 = $r0.32, 255   ## bblock 10, line 114-4,  t825,  t824(I16),  255(I32)
	c0    and $r0.34 = $r0.34, 255   ## bblock 10, line 114-4,  t848,  t847(I16),  255(I32)
	c0    sh2add $r0.25 = $r0.25, (conv7_image + 0)   ## bblock 10, line 114-4,  t891,  t889,  addr(conv7_image?1.0)(P32)
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 114-2,  t1142,  t2329,  8(I32)
	c0    cmplt $b0.0 = $r0.24, $r0.0   ## bblock 10, line 114-3,  t2465,  t994,  0(I32)
	c0    add $r0.63 = $r0.24, 255   ## bblock 10, line 114-3,  t2466,  t994,  255(I32)
	c0    cmplt $b0.1 = $r0.26, $r0.0   ## bblock 10, line 114-3,  t2480,  t1017,  0(I32)
	c0    add $r0.21 = $r0.21, $r0.37   ## bblock 10, line 114-3,  t1063,  t2508,  t2509
;;								## 27
	c0    and $r0.37 = $r0.37, 255   ## bblock 10, line 114-3,  t947,  t946(I16),  255(I32)
	c0    ldw $r0.36 = 0[$r0.36]   ## bblock 10, line 114-4, t777, t776
	c0    ldw $r0.25 = 0[$r0.25]   ## bblock 10, line 114-4, t892, t891
	c0    add $r0.18 = $r0.18, $r0.12   ## bblock 10, line 114-2,  t2407,  t1142,  t1211
	c0    slct $r0.63 = $b0.0, $r0.63, $r0.24   ## bblock 10, line 114-3,  t2467,  t2465,  t2466,  t994
	c0    add $r0.12 = $r0.26, 255   ## bblock 10, line 114-3,  t2481,  t1017,  255(I32)
	c0    cmplt $b0.0 = $r0.21, $r0.0   ## bblock 10, line 114-3,  t2510,  t1063,  0(I32)
	c0    add $r0.24 = $r0.21, 255   ## bblock 10, line 114-3,  t2511,  t1063,  255(I32)
	c0    mpyhs $r0.35 = $r0.14, $r0.29   ## bblock 10, line 114-4,  t2647,  t910,  t917
;;								## 28
	c0    shru $r0.21 = $r0.61, 16   ## bblock 10, line 114-3,  t969(I16),  t968,  16(SI32)
	c0    shru $r0.26 = $r0.38, 16   ## bblock 10, line 114-3,  t1038(I16),  t1037,  16(SI32)
	c0    shru $r0.14 = $r0.8, 16   ## bblock 10, line 114-5,  t656(I16),  t655,  16(SI32)
	c0    add $r0.5 = $r0.5, $r0.18   ## bblock 10, line 114-2,  t2410,  t2406,  t2407
	c0    mpylu $r0.18 = $r0.57, $r0.37   ## bblock 10, line 114-3,  t2433,  t940,  t947
	c0    mpyhs $r0.37 = $r0.57, $r0.37   ## bblock 10, line 114-3,  t2434,  t940,  t947
	c0    shr $r0.63 = $r0.63, 8   ## bblock 10, line 114-3,  t997,  t2467,  8(I32)
	c0    slct $r0.12 = $b0.1, $r0.12, $r0.26   ## bblock 10, line 114-3,  t2482,  t2480,  t2481,  t1017
	c0    slct $r0.24 = $b0.0, $r0.24, $r0.21   ## bblock 10, line 114-3,  t2512,  t2510,  t2511,  t1063
	c0    mpylu $r0.29 = $r0.14, $r0.29   ## bblock 10, line 114-4,  t2646,  t910,  t917
;;								## 29
	c0    and $r0.21 = $r0.21, 255   ## bblock 10, line 114-3,  t970,  t969(I16),  255(I32)
	c0    and $r0.26 = $r0.26, 255   ## bblock 10, line 114-3,  t1039,  t1038(I16),  255(I32)
	c0    and $r0.14 = $r0.14, 255   ## bblock 10, line 114-5,  t657,  t656(I16),  255(I32)
	c0    add $r0.23 = $r0.23, $r0.5   ## bblock 10, line 114-2,  t2019,  t2409,  t2410
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-3,  t1020,  t2482,  8(I32)
	c0    shr $r0.24 = $r0.24, 8   ## bblock 10, line 114-3,  t1066,  t2512,  8(I32)
	c0    mpylu $r0.5 = $r0.33, $r0.32   ## bblock 10, line 114-4,  t2586,  t818,  t825
	c0    mpyhs $r0.32 = $r0.33, $r0.32   ## bblock 10, line 114-4,  t2587,  t818,  t825
;;								## 30
	c0    shru $r0.37 = $r0.25, 16   ## bblock 10, line 114-4,  t893(I16),  t892,  16(SI32)
	c0    add $r0.20 = $r0.6, $r0.28   ## bblock 10, line 114-5,  t606,  t1469,  t2024
	c0    add $r0.18 = $r0.18, $r0.37   ## bblock 10, line 114-3,  t948,  t2433,  t2434
	c0    mpylu $r0.12 = $r0.20, $r0.21   ## bblock 10, line 114-3,  t2448,  t963,  t970
	c0    mpyhs $r0.21 = $r0.20, $r0.21   ## bblock 10, line 114-3,  t2449,  t963,  t970
	c0    mpylu $r0.22 = $r0.31, $r0.26   ## bblock 10, line 114-3,  t2493,  t1032,  t1039
	c0    mpyhs $r0.26 = $r0.31, $r0.26   ## bblock 10, line 114-3,  t2494,  t1032,  t1039
	c0    add $r0.23 = $r0.23, $r0.22   ## bblock 10, line 114-3,  t2528,  t2019,  t1089
	c0    add $r0.63 = $r0.63, $r0.12   ## bblock 10, line 114-3,  t2531,  t997,  t1020
	c0    add $r0.29 = $r0.29, $r0.35   ## bblock 10, line 114-4,  t918,  t2646,  t2647
	c0    ldw $r0.35 = (((filter7x7 + 0) + 124) + 0)[$r0.0]   ## bblock 10, line 114-4, t841, 0(I32)
;;								## 31
	c0    shru $r0.31 = $r0.36, 16   ## bblock 10, line 114-4,  t778(I16),  t777,  16(SI32)
	c0    add $r0.57 = $r0.11, $r0.40   ## bblock 10, line 114-4,  t797,  t460,  t2020
	c0    add $r0.40 = $r0.17, $r0.40   ## bblock 10, line 114-4,  t866,  t529,  t2020
	c0    and $r0.37 = $r0.37, 255   ## bblock 10, line 114-4,  t894,  t893(I16),  255(I32)
	c0    sh2add $r0.20 = $r0.20, (conv7_image + 0)   ## bblock 10, line 114-5,  t608,  t606,  addr(conv7_image?1.0)(P32)
	c0    cmplt $b0.0 = $r0.18, $r0.0   ## bblock 10, line 114-3,  t2435,  t948,  0(I32)
	c0    add $r0.63 = $r0.18, 255   ## bblock 10, line 114-3,  t2436,  t948,  255(I32)
	c0    add $r0.23 = $r0.23, $r0.63   ## bblock 10, line 114-3,  t2532,  t2528,  t2531
	c0    ldw $r0.33 = (((filter7x7 + 0) + 112) + 0)[$r0.0]   ## bblock 10, line 114-4, t772, 0(I32)
	c0    add $r0.5 = $r0.5, $r0.32   ## bblock 10, line 114-4,  t826,  t2586,  t2587
	c0    cmplt $b0.1 = $r0.29, $r0.0   ## bblock 10, line 114-4,  t2648,  t918,  0(I32)
	c0    ldw $r0.32 = (((filter7x7 + 0) + 132) + 0)[$r0.0]   ## bblock 10, line 114-4, t887, 0(I32)
	c0    stw 0x30[$r0.1] = $r0.8  ## spill ## t655
;;								## 32
	c0    and $r0.31 = $r0.31, 255   ## bblock 10, line 114-4,  t779,  t778(I16),  255(I32)
	c0    sh2add $r0.57 = $r0.57, (conv7_image + 0)   ## bblock 10, line 114-4,  t799,  t797,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.40 = $r0.40, (conv7_image + 0)   ## bblock 10, line 114-4,  t868,  t866,  addr(conv7_image?1.0)(P32)
	c0    ldw $r0.20 = 0[$r0.20]   ## bblock 10, line 114-5, t609, t608
	c0    slct $r0.63 = $b0.0, $r0.63, $r0.18   ## bblock 10, line 114-3,  t2437,  t2435,  t2436,  t948
	c0    add $r0.12 = $r0.12, $r0.21   ## bblock 10, line 114-3,  t971,  t2448,  t2449
	c0    add $r0.22 = $r0.22, $r0.26   ## bblock 10, line 114-3,  t1040,  t2493,  t2494
	c0    ldw $r0.26 = (((filter7x7 + 0) + 116) + 0)[$r0.0]   ## bblock 10, line 114-4, t795, 0(I32)
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 10, line 114-4,  t2588,  t826,  0(I32)
	c0    add $r0.18 = $r0.5, 255   ## bblock 10, line 114-4,  t2589,  t826,  255(I32)
	c0    mpylu $r0.21 = $r0.35, $r0.34   ## bblock 10, line 114-4,  t2601,  t841,  t848
	c0    mpyhs $r0.34 = $r0.35, $r0.34   ## bblock 10, line 114-4,  t2602,  t841,  t848
	c0    add $r0.8 = $r0.29, 255   ## bblock 10, line 114-4,  t2649,  t918,  255(I32)
;;								## 33
	c0    ldw $r0.57 = 0[$r0.57]   ## bblock 10, line 114-4, t800, t799
	c0    ldw $r0.40 = 0[$r0.40]   ## bblock 10, line 114-4, t869, t868
	c0    shr $r0.63 = $r0.63, 8   ## bblock 10, line 114-3,  t951,  t2437,  8(I32)
	c0    cmplt $b0.2 = $r0.12, $r0.0   ## bblock 10, line 114-3,  t2450,  t971,  0(I32)
	c0    add $r0.35 = $r0.12, 255   ## bblock 10, line 114-3,  t2451,  t971,  255(I32)
	c0    cmplt $b0.3 = $r0.22, $r0.0   ## bblock 10, line 114-3,  t2495,  t1040,  0(I32)
	c0    mpylu $r0.29 = $r0.33, $r0.31   ## bblock 10, line 114-4,  t2556,  t772,  t779
	c0    mpyhs $r0.31 = $r0.33, $r0.31   ## bblock 10, line 114-4,  t2557,  t772,  t779
	c0    slct $r0.18 = $b0.0, $r0.18, $r0.5   ## bblock 10, line 114-4,  t2590,  t2588,  t2589,  t826
	c0    mpylu $r0.5 = $r0.32, $r0.37   ## bblock 10, line 114-4,  t2631,  t887,  t894
	c0    mpyhs $r0.37 = $r0.32, $r0.37   ## bblock 10, line 114-4,  t2632,  t887,  t894
	c0    slct $r0.8 = $b0.1, $r0.8, $r0.29   ## bblock 10, line 114-4,  t2650,  t2648,  t2649,  t918
	c0    stw 0x34[$r0.1] = $r0.33  ## spill ## t772
;;								## 34
	c0    add $r0.32 = $r0.9, $r0.28   ## bblock 10, line 114-5,  t675,  t506,  t2024
	c0    slct $r0.35 = $b0.2, $r0.35, $r0.12   ## bblock 10, line 114-3,  t2452,  t2450,  t2451,  t971
	c0    add $r0.12 = $r0.22, 255   ## bblock 10, line 114-3,  t2496,  t1040,  255(I32)
	c0    add $r0.63 = $r0.63, $r0.24   ## bblock 10, line 114-3,  t2529,  t951,  t1066
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 114-4,  t829,  t2590,  8(I32)
	c0    add $r0.21 = $r0.21, $r0.34   ## bblock 10, line 114-4,  t849,  t2601,  t2602
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 114-4,  t921,  t2650,  8(I32)
	c0    ldw $r0.33 = (((filter7x7 + 0) + 164) + 0)[$r0.0]   ## bblock 10, line 114-5, t742, 0(I32)
	c0    ldw $r0.24 = (((filter7x7 + 0) + 128) + 0)[$r0.0]   ## bblock 10, line 114-4, t864, 0(I32)
;;								## 35
	c0    shru $r0.31 = $r0.57, 16   ## bblock 10, line 114-4,  t801(I16),  t800,  16(SI32)
	c0    shru $r0.37 = $r0.40, 16   ## bblock 10, line 114-4,  t870(I16),  t869,  16(SI32)
	c0    sh2add $r0.32 = $r0.32, (conv7_image + 0)   ## bblock 10, line 114-5,  t677,  t675,  addr(conv7_image?1.0)(P32)
	c0    shr $r0.35 = $r0.35, 8   ## bblock 10, line 114-3,  t974,  t2452,  8(I32)
	c0    slct $r0.12 = $b0.3, $r0.12, $r0.22   ## bblock 10, line 114-3,  t2497,  t2495,  t2496,  t1040
	c0    add $r0.29 = $r0.29, $r0.31   ## bblock 10, line 114-4,  t780,  t2556,  t2557
	c0    cmplt $b0.0 = $r0.21, $r0.0   ## bblock 10, line 114-4,  t2603,  t849,  0(I32)
	c0    add $r0.22 = $r0.21, 255   ## bblock 10, line 114-4,  t2604,  t849,  255(I32)
	c0    add $r0.5 = $r0.5, $r0.37   ## bblock 10, line 114-4,  t895,  t2631,  t2632
;;								## 36
	c0    and $r0.31 = $r0.31, 255   ## bblock 10, line 114-4,  t802,  t801(I16),  255(I32)
	c0    and $r0.37 = $r0.37, 255   ## bblock 10, line 114-4,  t871,  t870(I16),  255(I32)
	c0    ldw $r0.32 = 0[$r0.32]   ## bblock 10, line 114-5, t678, t677
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-3,  t1043,  t2497,  8(I32)
	c0    cmplt $b0.1 = $r0.29, $r0.0   ## bblock 10, line 114-4,  t2558,  t780,  0(I32)
	c0    slct $r0.22 = $b0.0, $r0.22, $r0.21   ## bblock 10, line 114-4,  t2605,  t2603,  t2604,  t849
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 10, line 114-4,  t2633,  t895,  0(I32)
	c0    add $r0.21 = $r0.5, 255   ## bblock 10, line 114-4,  t2634,  t895,  255(I32)
	c0    mpylu $r0.34 = $r0.33, $r0.39   ## bblock 10, line 114-5,  t2769,  t742,  t749
	c0    mpyhs $r0.39 = $r0.33, $r0.39   ## bblock 10, line 114-5,  t2770,  t742,  t749
	c0    ldw $r0.33 = (((filter7x7 + 0) + 148) + 0)[$r0.0]   ## bblock 10, line 114-5, t650, 0(I32)
;;								## 37
	c0    add $r0.35 = $r0.35, $r0.12   ## bblock 10, line 114-3,  t2530,  t974,  t1043
	c0    add $r0.5 = $r0.29, 255   ## bblock 10, line 114-4,  t2559,  t780,  255(I32)
	c0    mpylu $r0.12 = $r0.26, $r0.31   ## bblock 10, line 114-4,  t2571,  t795,  t802
	c0    mpyhs $r0.31 = $r0.26, $r0.31   ## bblock 10, line 114-4,  t2572,  t795,  t802
	c0    shr $r0.22 = $r0.22, 8   ## bblock 10, line 114-4,  t852,  t2605,  8(I32)
	c0    slct $r0.21 = $b0.0, $r0.21, $r0.5   ## bblock 10, line 114-4,  t2635,  t2633,  t2634,  t895
	c0    ldw $r0.26 = (((filter7x7 + 0) + 156) + 0)[$r0.0]   ## bblock 10, line 114-5, t696, 0(I32)
;;								## 38
	c0    shru $r0.35 = $r0.32, 16   ## bblock 10, line 114-5,  t679(I16),  t678,  16(SI32)
	c0    add $r0.63 = $r0.63, $r0.35   ## bblock 10, line 114-3,  t2533,  t2529,  t2530
	c0    slct $r0.5 = $b0.1, $r0.5, $r0.29   ## bblock 10, line 114-4,  t2560,  t2558,  t2559,  t780
	c0    mpylu $r0.22 = $r0.24, $r0.37   ## bblock 10, line 114-4,  t2616,  t864,  t871
	c0    mpyhs $r0.37 = $r0.24, $r0.37   ## bblock 10, line 114-4,  t2617,  t864,  t871
	c0    shr $r0.21 = $r0.21, 8   ## bblock 10, line 114-4,  t898,  t2635,  8(I32)
	c0    add $r0.18 = $r0.18, $r0.22   ## bblock 10, line 114-4,  t2654,  t829,  t852
	c0    mpylu $r0.29 = $r0.33, $r0.14   ## bblock 10, line 114-5,  t2709,  t650,  t657
	c0    mpyhs $r0.14 = $r0.33, $r0.14   ## bblock 10, line 114-5,  t2710,  t650,  t657
	c0    ldw $r0.39 = (((filter7x7 + 0) + 152) + 0)[$r0.0]   ## bblock 10, line 114-5, t673, 0(I32)
	c0    add $r0.34 = $r0.34, $r0.39   ## bblock 10, line 114-5,  t750,  t2769,  t2770
	c0    ldw $r0.24 = (((filter7x7 + 0) + 176) + 0)[$r0.0]   ## bblock 10, line 114-6, t482, 0(I32)
	c0    ldw $r0.33 = (((filter7x7 + 0) + 192) + 0)[$r0.0]   ## bblock 10, line 114-6, t574, 0(I32)
;;								## 39
	c0    and $r0.35 = $r0.35, 255   ## bblock 10, line 114-5,  t680,  t679(I16),  255(I32)
	c0    add $r0.63 = $r0.13, $r0.28   ## bblock 10, line 114-5,  t721,  t552,  t2024
	c0    add $r0.23 = $r0.23, $r0.63   ## bblock 10, line 114-3,  t2023,  t2532,  t2533
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 114-4,  t783,  t2560,  8(I32)
	c0    add $r0.12 = $r0.12, $r0.31   ## bblock 10, line 114-4,  t803,  t2571,  t2572
	c0    cmplt $b0.0 = $r0.34, $r0.0   ## bblock 10, line 114-5,  t2771,  t750,  0(I32)
	c0    add $r0.31 = $r0.34, 255   ## bblock 10, line 114-5,  t2772,  t750,  255(I32)
;;								## 40
	c0    shru $r0.34 = $r0.20, 16   ## bblock 10, line 114-5,  t610(I16),  t609,  16(SI32)
	c0    sh2add $r0.63 = $r0.63, (conv7_image + 0)   ## bblock 10, line 114-5,  t723,  t721,  addr(conv7_image?1.0)(P32)
	c0    cmplt $b0.1 = $r0.12, $r0.0   ## bblock 10, line 114-4,  t2573,  t803,  0(I32)
	c0    add $r0.8 = $r0.12, 255   ## bblock 10, line 114-4,  t2574,  t803,  255(I32)
	c0    add $r0.22 = $r0.22, $r0.37   ## bblock 10, line 114-4,  t872,  t2616,  t2617
	c0    add $r0.23 = $r0.23, $r0.8   ## bblock 10, line 114-4,  t2651,  t2023,  t921
	c0    add $r0.5 = $r0.5, $r0.21   ## bblock 10, line 114-4,  t2652,  t783,  t898
	c0    add $r0.29 = $r0.29, $r0.14   ## bblock 10, line 114-5,  t658,  t2709,  t2710
	c0    mpylu $r0.14 = $r0.39, $r0.35   ## bblock 10, line 114-5,  t2724,  t673,  t680
	c0    mpyhs $r0.35 = $r0.39, $r0.35   ## bblock 10, line 114-5,  t2725,  t673,  t680
	c0    slct $r0.31 = $b0.0, $r0.31, $r0.34   ## bblock 10, line 114-5,  t2773,  t2771,  t2772,  t750
	c0    ldw $r0.37 = (((filter7x7 + 0) + 140) + 0)[$r0.0]   ## bblock 10, line 114-5, t604, 0(I32)
	c0    ldw $r0.21 = (((filter7x7 + 0) + 160) + 0)[$r0.0]   ## bblock 10, line 114-5, t719, 0(I32)
;;								## 41
	c0    and $r0.34 = $r0.34, 255   ## bblock 10, line 114-5,  t611,  t610(I16),  255(I32)
	c0    ldw $r0.63 = 0[$r0.63]   ## bblock 10, line 114-5, t724, t723
	c0    add $r0.39 = $r0.4, 6   ## bblock 10, line 111-6,  t2028,  t1442,  6(SI32)
	c0    slct $r0.8 = $b0.1, $r0.8, $r0.12   ## bblock 10, line 114-4,  t2575,  t2573,  t2574,  t803
	c0    cmplt $b0.0 = $r0.22, $r0.0   ## bblock 10, line 114-4,  t2618,  t872,  0(I32)
	c0    add $r0.12 = $r0.22, 255   ## bblock 10, line 114-4,  t2619,  t872,  255(I32)
	c0    add $r0.23 = $r0.23, $r0.18   ## bblock 10, line 114-4,  t2655,  t2651,  t2654
	c0    cmplt $b0.1 = $r0.29, $r0.0   ## bblock 10, line 114-5,  t2711,  t658,  0(I32)
	c0    add $r0.18 = $r0.29, 255   ## bblock 10, line 114-5,  t2712,  t658,  255(I32)
	c0    shr $r0.31 = $r0.31, 8   ## bblock 10, line 114-5,  t753,  t2773,  8(I32)
	c0    add $r0.4 = $r0.4, 1   ## bblock 10, line 0,  t1442,  t1442,  1(I32)
;;								## 42
	c0    add $r0.29 = $r0.11, $r0.28   ## bblock 10, line 114-5,  t629,  t460,  t2024
	c0    add $r0.28 = $r0.17, $r0.28   ## bblock 10, line 114-5,  t698,  t529,  t2024
	c0    add $r0.11 = $r0.11, $r0.39   ## bblock 10, line 114-6,  t461,  t460,  t2028
	c0    add $r0.15 = $r0.15, $r0.39   ## bblock 10, line 114-6,  t484,  t483,  t2028
	c0    add $r0.9 = $r0.9, $r0.39   ## bblock 10, line 114-6,  t507,  t506,  t2028
	c0    add $r0.17 = $r0.17, $r0.39   ## bblock 10, line 114-6,  t530,  t529,  t2028
	c0    add $r0.13 = $r0.13, $r0.39   ## bblock 10, line 114-6,  t553,  t552,  t2028
	c0    add $r0.3 = $r0.3, $r0.39   ## bblock 10, line 114-6,  t576,  t575,  t2028
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 114-4,  t806,  t2575,  8(I32)
	c0    slct $r0.12 = $b0.0, $r0.12, $r0.22   ## bblock 10, line 114-4,  t2620,  t2618,  t2619,  t872
	c0    mpylu $r0.22 = $r0.37, $r0.34   ## bblock 10, line 114-5,  t2679,  t604,  t611
	c0    mpyhs $r0.34 = $r0.37, $r0.34   ## bblock 10, line 114-5,  t2680,  t604,  t611
	c0    ldw $r0.35 = (((filter7x7 + 0) + 144) + 0)[$r0.0]   ## bblock 10, line 114-5, t627, 0(I32)
	c0    slct $r0.18 = $b0.1, $r0.18, $r0.29   ## bblock 10, line 114-5,  t2713,  t2711,  t2712,  t658
	c0    add $r0.14 = $r0.14, $r0.35   ## bblock 10, line 114-5,  t681,  t2724,  t2725
;;								## 43
	c0    sh2add $r0.29 = $r0.29, (conv7_image + 0)   ## bblock 10, line 114-5,  t631,  t629,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.28 = $r0.28, (conv7_image + 0)   ## bblock 10, line 114-5,  t700,  t698,  addr(conv7_image?1.0)(P32)
	c0    add $r0.39 = $r0.6, $r0.39   ## bblock 10, line 114-6,  t438,  t1469,  t2028
	c0    sh2add $r0.11 = $r0.11, (conv7_image + 0)   ## bblock 10, line 114-6,  t463,  t461,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.15 = $r0.15, (conv7_image + 0)   ## bblock 10, line 114-6,  t486,  t484,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.9 = $r0.9, (conv7_image + 0)   ## bblock 10, line 114-6,  t509,  t507,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.17 = $r0.17, (conv7_image + 0)   ## bblock 10, line 114-6,  t532,  t530,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.13 = $r0.13, (conv7_image + 0)   ## bblock 10, line 114-6,  t555,  t553,  addr(conv7_image?1.0)(P32)
	c0    sh2add $r0.3 = $r0.3, (conv7_image + 0)   ## bblock 10, line 114-6,  t578,  t576,  addr(conv7_image?1.0)(P32)
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-4,  t875,  t2620,  8(I32)
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 114-5,  t661,  t2713,  8(I32)
	c0    cmplt $b0.0 = $r0.14, $r0.0   ## bblock 10, line 114-5,  t2726,  t681,  0(I32)
	c0    add $r0.37 = $r0.14, 255   ## bblock 10, line 114-5,  t2727,  t681,  255(I32)
;;								## 44
	c0    ldw $r0.29 = 0[$r0.29]   ## bblock 10, line 114-5, t632, t631
	c0    ldw $r0.28 = 0[$r0.28]   ## bblock 10, line 114-5, t701, t700
	c0    shru $r0.12 = $r0.63, 16   ## bblock 10, line 114-5,  t725(I16),  t724,  16(SI32)
	c0    sh2add $r0.39 = $r0.39, (conv7_image + 0)   ## bblock 10, line 114-6,  t440,  t438,  addr(conv7_image?1.0)(P32)
	c0    ldw $r0.11 = 0[$r0.11]   ## bblock 10, line 114-6, t464, t463
	c0    ldw $r0.15 = 0[$r0.15]   ## bblock 10, line 114-6, t487, t486
	c0    ldw $r0.9 = 0[$r0.9]   ## bblock 10, line 114-6, t510, t509
	c0    ldw $r0.17 = 0[$r0.17]   ## bblock 10, line 114-6, t533, t532
	c0    ldw $r0.13 = 0[$r0.13]   ## bblock 10, line 114-6, t556, t555
	c0    ldw $r0.3 = 0[$r0.3]   ## bblock 10, line 114-6, t579, t578
	c0    add $r0.8 = $r0.8, $r0.12   ## bblock 10, line 114-4,  t2653,  t806,  t875
	c0    add $r0.22 = $r0.22, $r0.34   ## bblock 10, line 114-5,  t612,  t2679,  t2680
	c0    slct $r0.37 = $b0.0, $r0.37, $r0.14   ## bblock 10, line 114-5,  t2728,  t2726,  t2727,  t681
	c0    ldw $r0.14 = (((filter7x7 + 0) + 180) + 0)[$r0.0]   ## bblock 10, line 114-6, t505, 0(I32)
;;								## 45
	c0    and $r0.12 = $r0.12, 255   ## bblock 10, line 114-5,  t726,  t725(I16),  255(I32)
	c0    ldw $r0.39 = 0[$r0.39]   ## bblock 10, line 114-6, t441, t440
	c0    add $r0.5 = $r0.5, $r0.8   ## bblock 10, line 114-4,  t2656,  t2652,  t2653
	c0    cmplt $b0.0 = $r0.22, $r0.0   ## bblock 10, line 114-5,  t2681,  t612,  0(I32)
	c0    add $r0.8 = $r0.22, 255   ## bblock 10, line 114-5,  t2682,  t612,  255(I32)
	c0    shr $r0.37 = $r0.37, 8   ## bblock 10, line 114-5,  t684,  t2728,  8(I32)
;;								## 46
	c0    shru $r0.22 = $r0.29, 16   ## bblock 10, line 114-5,  t633(I16),  t632,  16(SI32)
	c0    shru $r0.37 = $r0.28, 16   ## bblock 10, line 114-5,  t702(I16),  t701,  16(SI32)
	c0    add $r0.23 = $r0.23, $r0.5   ## bblock 10, line 114-4,  t2027,  t2655,  t2656
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.22   ## bblock 10, line 114-5,  t2683,  t2681,  t2682,  t612
	c0    mpylu $r0.5 = $r0.21, $r0.12   ## bblock 10, line 114-5,  t2754,  t719,  t726
	c0    mpyhs $r0.12 = $r0.21, $r0.12   ## bblock 10, line 114-5,  t2755,  t719,  t726
	c0    add $r0.18 = $r0.18, $r0.37   ## bblock 10, line 114-5,  t2777,  t661,  t684
;;								## 47
	c0    and $r0.22 = $r0.22, 255   ## bblock 10, line 114-5,  t634,  t633(I16),  255(I32)
	c0    and $r0.37 = $r0.37, 255   ## bblock 10, line 114-5,  t703,  t702(I16),  255(I32)
	c0    shru $r0.21 = $r0.15, 16   ## bblock 10, line 114-6,  t488(I16),  t487,  16(SI32)
	c0    shru $r0.34 = $r0.9, 16   ## bblock 10, line 114-6,  t511(I16),  t510,  16(SI32)
	c0    shru $r0.31 = $r0.3, 16   ## bblock 10, line 114-6,  t580(I16),  t579,  16(SI32)
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 114-5,  t615,  t2683,  8(I32)
	c0    add $r0.23 = $r0.23, $r0.31   ## bblock 10, line 114-5,  t2774,  t2027,  t753
;;								## 48
	c0    and $r0.21 = $r0.21, 255   ## bblock 10, line 114-6,  t489,  t488(I16),  255(I32)
	c0    and $r0.34 = $r0.34, 255   ## bblock 10, line 114-6,  t512,  t511(I16),  255(I32)
	c0    shru $r0.35 = $r0.13, 16   ## bblock 10, line 114-6,  t557(I16),  t556,  16(SI32)
	c0    and $r0.31 = $r0.31, 255   ## bblock 10, line 114-6,  t581,  t580(I16),  255(I32)
	c0    mpylu $r0.12 = $r0.35, $r0.22   ## bblock 10, line 114-5,  t2694,  t627,  t634
	c0    mpyhs $r0.22 = $r0.35, $r0.22   ## bblock 10, line 114-5,  t2695,  t627,  t634
	c0    mpylu $r0.18 = $r0.26, $r0.37   ## bblock 10, line 114-5,  t2739,  t696,  t703
	c0    mpyhs $r0.37 = $r0.26, $r0.37   ## bblock 10, line 114-5,  t2740,  t696,  t703
	c0    add $r0.5 = $r0.5, $r0.12   ## bblock 10, line 114-5,  t727,  t2754,  t2755
	c0    add $r0.23 = $r0.23, $r0.18   ## bblock 10, line 114-5,  t2778,  t2774,  t2777
;;								## 49
	c0    and $r0.35 = $r0.35, 255   ## bblock 10, line 114-6,  t558,  t557(I16),  255(I32)
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 10, line 114-5,  t2756,  t727,  0(I32)
	c0    add $r0.26 = $r0.5, 255   ## bblock 10, line 114-5,  t2757,  t727,  255(I32)
;;								## 50
	c0    add $r0.12 = $r0.12, $r0.22   ## bblock 10, line 114-5,  t635,  t2694,  t2695
	c0    add $r0.18 = $r0.18, $r0.37   ## bblock 10, line 114-5,  t704,  t2739,  t2740
	c0    slct $r0.26 = $b0.0, $r0.26, $r0.5   ## bblock 10, line 114-5,  t2758,  t2756,  t2757,  t727
	c0    mpylu $r0.22 = $r0.24, $r0.21   ## bblock 10, line 114-6,  t2832,  t482,  t489
	c0    mpyhs $r0.21 = $r0.24, $r0.21   ## bblock 10, line 114-6,  t2833,  t482,  t489
	c0    mpylu $r0.37 = $r0.14, $r0.34   ## bblock 10, line 114-6,  t2847,  t505,  t512
	c0    mpyhs $r0.34 = $r0.14, $r0.34   ## bblock 10, line 114-6,  t2848,  t505,  t512
	c0    mpylu $r0.5 = $r0.33, $r0.31   ## bblock 10, line 114-6,  t2892,  t574,  t581
	c0    mpyhs $r0.31 = $r0.33, $r0.31   ## bblock 10, line 114-6,  t2893,  t574,  t581
;;								## 51
	c0    cmplt $b0.0 = $r0.12, $r0.0   ## bblock 10, line 114-5,  t2696,  t635,  0(I32)
	c0    add $r0.33 = $r0.12, 255   ## bblock 10, line 114-5,  t2697,  t635,  255(I32)
	c0    cmplt $b0.1 = $r0.18, $r0.0   ## bblock 10, line 114-5,  t2741,  t704,  0(I32)
	c0    shr $r0.26 = $r0.26, 8   ## bblock 10, line 114-5,  t730,  t2758,  8(I32)
;;								## 52
	c0    shru $r0.21 = $r0.39, 16   ## bblock 10, line 114-6,  t442(I16),  t441,  16(SI32)
	c0    shru $r0.26 = $r0.11, 16   ## bblock 10, line 114-6,  t465(I16),  t464,  16(SI32)
	c0    shru $r0.14 = $r0.17, 16   ## bblock 10, line 114-6,  t534(I16),  t533,  16(SI32)
	c0    slct $r0.33 = $b0.0, $r0.33, $r0.12   ## bblock 10, line 114-5,  t2698,  t2696,  t2697,  t635
	c0    add $r0.12 = $r0.18, 255   ## bblock 10, line 114-5,  t2742,  t704,  255(I32)
	c0    add $r0.8 = $r0.8, $r0.26   ## bblock 10, line 114-5,  t2775,  t615,  t730
	c0    ldw $r0.31 = (((filter7x7 + 0) + 168) + 0)[$r0.0]   ## bblock 10, line 114-6, t436, 0(I32)
	c0    ldw $r0.24 = (((filter7x7 + 0) + 172) + 0)[$r0.0]   ## bblock 10, line 114-6, t459, 0(I32)
	c0    add $r0.22 = $r0.22, $r0.21   ## bblock 10, line 114-6,  t490,  t2832,  t2833
	c0    add $r0.37 = $r0.37, $r0.34   ## bblock 10, line 114-6,  t513,  t2847,  t2848
	c0    add $r0.5 = $r0.5, $r0.31   ## bblock 10, line 114-6,  t582,  t2892,  t2893
	c0    ldw $r0.34 = (((filter7x7 + 0) + 188) + 0)[$r0.0]   ## bblock 10, line 114-6, t551, 0(I32)
	c0    stw 0x38[$r0.1] = $r0.4  ## spill ## t1442
;;								## 53
	c0    and $r0.21 = $r0.21, 255   ## bblock 10, line 114-6,  t443,  t442(I16),  255(I32)
	c0    and $r0.26 = $r0.26, 255   ## bblock 10, line 114-6,  t466,  t465(I16),  255(I32)
	c0    and $r0.14 = $r0.14, 255   ## bblock 10, line 114-6,  t535,  t534(I16),  255(I32)
	c0    shr $r0.33 = $r0.33, 8   ## bblock 10, line 114-5,  t638,  t2698,  8(I32)
	c0    slct $r0.12 = $b0.1, $r0.12, $r0.18   ## bblock 10, line 114-5,  t2743,  t2741,  t2742,  t704
	c0    cmplt $b0.1 = $r0.22, $r0.0   ## bblock 10, line 114-6,  t2834,  t490,  0(I32)
	c0    add $r0.4 = $r0.22, 255   ## bblock 10, line 114-6,  t2835,  t490,  255(I32)
	c0    cmplt $b0.2 = $r0.37, $r0.0   ## bblock 10, line 114-6,  t2849,  t513,  0(I32)
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 10, line 114-6,  t2894,  t582,  0(I32)
	c0    add $r0.18 = $r0.5, 255   ## bblock 10, line 114-6,  t2895,  t582,  255(I32)
;;								## 54
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-5,  t707,  t2743,  8(I32)
	c0    slct $r0.4 = $b0.1, $r0.4, $r0.22   ## bblock 10, line 114-6,  t2836,  t2834,  t2835,  t490
	c0    add $r0.5 = $r0.37, 255   ## bblock 10, line 114-6,  t2850,  t513,  255(I32)
	c0    ldw $r0.34 = (((filter7x7 + 0) + 184) + 0)[$r0.0]   ## bblock 10, line 114-6, t528, 0(I32)
	c0    mpylu $r0.22 = $r0.34, $r0.35   ## bblock 10, line 114-6,  t2877,  t551,  t558
	c0    mpyhs $r0.35 = $r0.34, $r0.35   ## bblock 10, line 114-6,  t2878,  t551,  t558
	c0    slct $r0.18 = $b0.0, $r0.18, $r0.5   ## bblock 10, line 114-6,  t2896,  t2894,  t2895,  t582
;;								## 55
	c0    add $r0.33 = $r0.33, $r0.12   ## bblock 10, line 114-5,  t2776,  t638,  t707
	c0    mpylu $r0.12 = $r0.31, $r0.21   ## bblock 10, line 114-6,  t2802,  t436,  t443
	c0    mpyhs $r0.21 = $r0.31, $r0.21   ## bblock 10, line 114-6,  t2803,  t436,  t443
	c0    mpylu $r0.37 = $r0.24, $r0.26   ## bblock 10, line 114-6,  t2817,  t459,  t466
	c0    mpyhs $r0.26 = $r0.24, $r0.26   ## bblock 10, line 114-6,  t2818,  t459,  t466
	c0    shr $r0.4 = $r0.4, 8   ## bblock 10, line 114-6,  t493,  t2836,  8(I32)
	c0    slct $r0.5 = $b0.2, $r0.5, $r0.37   ## bblock 10, line 114-6,  t2851,  t2849,  t2850,  t513
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 114-6,  t585,  t2896,  8(I32)
;;								## 56
	c0    and $r0.35 = $r0.41, 255   ## bblock 10, line 116-6,  t301,  t297,  255(I32)
	c0    shru $r0.41 = $r0.41, 8   ## bblock 10, line 115-6,  t305(I24),  t297,  8(SI32)
	c0    add $r0.8 = $r0.8, $r0.33   ## bblock 10, line 114-5,  t2779,  t2775,  t2776
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 114-6,  t516,  t2851,  8(I32)
	c0    mpylu $r0.33 = $r0.34, $r0.14   ## bblock 10, line 114-6,  t2862,  t528,  t535
	c0    mpyhs $r0.14 = $r0.34, $r0.14   ## bblock 10, line 114-6,  t2863,  t528,  t535
	c0    add $r0.22 = $r0.22, $r0.35   ## bblock 10, line 114-6,  t559,  t2877,  t2878
;;								## 57
	c0    and $r0.21 = $r0.42, 255   ## bblock 10, line 116,  t79,  t78,  255(I32)
	c0    shru $r0.42 = $r0.42, 8   ## bblock 10, line 115,  t61(I24),  t78,  8(SI32)
	c0    and $r0.24 = $r0.44, 255   ## bblock 10, line 116-1,  t416,  t412,  255(I32)
	c0    and $r0.31 = $r0.43, 255   ## bblock 10, line 116-3,  t370,  t366,  255(I32)
	c0    shru $r0.43 = $r0.43, 8   ## bblock 10, line 115-3,  t374(I24),  t366,  8(SI32)
	c0    and $r0.41 = $r0.41, 255   ## bblock 10, line 115-6,  t306,  t305(I24),  255(I32)
	c0    add $r0.23 = $r0.23, $r0.8   ## bblock 10, line 114-5,  t2031,  t2778,  t2779
	c0    add $r0.12 = $r0.12, $r0.21   ## bblock 10, line 114-6,  t444,  t2802,  t2803
	c0    add $r0.37 = $r0.37, $r0.26   ## bblock 10, line 114-6,  t467,  t2817,  t2818
	c0    cmplt $b0.0 = $r0.22, $r0.0   ## bblock 10, line 114-6,  t2879,  t559,  0(I32)
	c0    add $r0.5 = $r0.22, 255   ## bblock 10, line 114-6,  t2880,  t559,  255(I32)
	c0    add $r0.4 = $r0.4, $r0.5   ## bblock 10, line 114-6,  t2900,  t493,  t516
	c0    ldw $r0.26 = ((filter7x7 + 0) + 0)[$r0.0]   ## bblock 10, line 114, t70, 0(I32)
	c0    ldw $r0.34 = (((filter7x7 + 0) + 12) + 0)[$r0.0]   ## bblock 10, line 114-3, t361, 0(I32)
	c0    ldw $r0.8 = (((filter7x7 + 0) + 24) + 0)[$r0.0]   ## bblock 10, line 114-6, t292, 0(I32)
	c0    stw 0x40[$r0.1] = $r0.44  ## spill ## [spec] t412
;;								## 58
	c0    and $r0.42 = $r0.42, 255   ## bblock 10, line 115,  t62,  t61(I24),  255(I32)
	c0    and $r0.43 = $r0.43, 255   ## bblock 10, line 115-3,  t375,  t374(I24),  255(I32)
	c0    and $r0.6 = $r0.45, 255   ## bblock 10, line 116-5,  t324,  t320,  255(I32)
	c0    shru $r0.45 = $r0.45, 8   ## bblock 10, line 115-5,  t328(I24),  t320,  8(SI32)
	c0    cmplt $b0.0 = $r0.12, $r0.0   ## bblock 10, line 114-6,  t2804,  t444,  0(I32)
	c0    add $r0.18 = $r0.12, 255   ## bblock 10, line 114-6,  t2805,  t444,  255(I32)
	c0    cmplt $b0.1 = $r0.37, $r0.0   ## bblock 10, line 114-6,  t2819,  t467,  0(I32)
	c0    add $r0.22 = $r0.37, 255   ## bblock 10, line 114-6,  t2820,  t467,  255(I32)
	c0    add $r0.33 = $r0.33, $r0.14   ## bblock 10, line 114-6,  t536,  t2862,  t2863
	c0    slct $r0.5 = $b0.0, $r0.5, $r0.22   ## bblock 10, line 114-6,  t2881,  t2879,  t2880,  t559
	c0    add $r0.23 = $r0.23, $r0.18   ## bblock 10, line 114-6,  t2897,  t2031,  t585
	c0    ldw $r0.44 = (((filter7x7 + 0) + 4) + 0)[$r0.0]   ## bblock 10, line 114-1, t407, 0(I32)
;;								## 59
	c0    mpylu $r0.4 = $r0.26, $r0.21   ## bblock 10, line 116,  t2069,  t70,  t79
	c0    mpyhs $r0.21 = $r0.26, $r0.21   ## bblock 10, line 116,  t2070,  t70,  t79
	c0    and $r0.8 = $r0.46, 255   ## bblock 10, line 116-2,  t393,  t389,  255(I32)
	c0    shru $r0.46 = $r0.46, 8   ## bblock 10, line 115-2,  t397(I24),  t389,  8(SI32)
	c0    and $r0.45 = $r0.45, 255   ## bblock 10, line 115-5,  t329,  t328(I24),  255(I32)
	c0    mpylu $r0.37 = $r0.8, $r0.35   ## bblock 10, line 116-6,  t2167,  t292,  t301
	c0    mpyhs $r0.35 = $r0.8, $r0.35   ## bblock 10, line 116-6,  t2168,  t292,  t301
	c0    slct $r0.18 = $b0.0, $r0.18, $r0.12   ## bblock 10, line 114-6,  t2806,  t2804,  t2805,  t444
	c0    slct $r0.22 = $b0.1, $r0.22, $r0.37   ## bblock 10, line 114-6,  t2821,  t2819,  t2820,  t467
	c0    cmplt $b0.0 = $r0.33, $r0.0   ## bblock 10, line 114-6,  t2864,  t536,  0(I32)
	c0    add $r0.12 = $r0.33, 255   ## bblock 10, line 114-6,  t2865,  t536,  255(I32)
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 114-6,  t562,  t2881,  8(I32)
	c0    add $r0.23 = $r0.23, $r0.4   ## bblock 10, line 114-6,  t2901,  t2897,  t2900
	c0    ldw $r0.26 = (((filter7x7 + 0) + 20) + 0)[$r0.0]   ## bblock 10, line 114-5, t315, 0(I32)
	c0    ldw $r0.14 = (((filter7x7 + 0) + 8) + 0)[$r0.0]   ## bblock 10, line 114-2, t384, 0(I32)
;;								## 60
	c0    and $r0.46 = $r0.46, 255   ## bblock 10, line 115-2,  t398,  t397(I24),  255(I32)
	c0    mpylu $r0.33 = $r0.34, $r0.31   ## bblock 10, line 116-3,  t2117,  t361,  t370
	c0    mpyhs $r0.31 = $r0.34, $r0.31   ## bblock 10, line 116-3,  t2118,  t361,  t370
	c0    and $r0.34 = $r0.47, 255   ## bblock 10, line 116-4,  t347,  t343,  255(I32)
	c0    shru $r0.47 = $r0.47, 8   ## bblock 10, line 115-4,  t351(I24),  t343,  8(SI32)
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 114-6,  t447,  t2806,  8(I32)
	c0    shr $r0.22 = $r0.22, 8   ## bblock 10, line 114-6,  t470,  t2821,  8(I32)
	c0    slct $r0.12 = $b0.0, $r0.12, $r0.33   ## bblock 10, line 114-6,  t2866,  t2864,  t2865,  t536
;;								## 61
	c0    add $r0.4 = $r0.4, $r0.21   ## bblock 10, line 116,  t80,  t2069,  t2070
	c0    mpylu $r0.5 = $r0.44, $r0.24   ## bblock 10, line 116-1,  t2087,  t407,  t416
	c0    mpyhs $r0.24 = $r0.44, $r0.24   ## bblock 10, line 116-1,  t2088,  t407,  t416
	c0    mpylu $r0.35 = $r0.14, $r0.8   ## bblock 10, line 116-2,  t2102,  t384,  t393
	c0    mpyhs $r0.8 = $r0.14, $r0.8   ## bblock 10, line 116-2,  t2103,  t384,  t393
	c0    and $r0.47 = $r0.47, 255   ## bblock 10, line 115-4,  t352,  t351(I24),  255(I32)
	c0    mpylu $r0.21 = $r0.26, $r0.6   ## bblock 10, line 116-5,  t2147,  t315,  t324
	c0    mpyhs $r0.6 = $r0.26, $r0.6   ## bblock 10, line 116-5,  t2148,  t315,  t324
	c0    add $r0.37 = $r0.37, $r0.35   ## bblock 10, line 116-6,  t302,  t2167,  t2168
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 114-6,  t539,  t2866,  8(I32)
	c0    add $r0.18 = $r0.18, $r0.5   ## bblock 10, line 114-6,  t2898,  t447,  t562
;;								## 62
	c0    cmplt $b0.1 = $r0.4, $r0.0   ## bblock 10, line 116,  t2074,  t80,  0(I32)
	c0    add $r0.33 = $r0.33, $r0.31   ## bblock 10, line 116-3,  t371,  t2117,  t2118
	c0    cmplt $b0.0 = $r0.37, $r0.0   ## bblock 10, line 116-6,  t2169,  t302,  0(I32)
	c0    add $r0.12 = $r0.37, 255   ## bblock 10, line 116-6,  t2170,  t302,  255(I32)
	c0    add $r0.22 = $r0.22, $r0.12   ## bblock 10, line 114-6,  t2899,  t470,  t539
	c0    ldw $r0.31 = (((filter7x7 + 0) + 16) + 0)[$r0.0]   ## bblock 10, line 114-4, t338, 0(I32)
;;								## 63
	c0    add $r0.22 = $r0.4, 255   ## bblock 10, line 116,  t2075,  t80,  255(I32)
	c0    add $r0.5 = $r0.5, $r0.24   ## bblock 10, line 116-1,  t417,  t2087,  t2088
	c0    and $r0.44 = $r0.49, 255   ## bblock 10, line 116-1,  t1331,  t1327,  255(I32)
	c0    shru $r0.49 = $r0.49, 8   ## bblock 10, line 115-1,  t1335(I24),  t1327,  8(SI32)
	c0    add $r0.35 = $r0.35, $r0.8   ## bblock 10, line 116-2,  t394,  t2102,  t2103
	c0    and $r0.14 = $r0.50, 255   ## bblock 10, line 116-1,  t1354,  t1350,  255(I32)
	c0    shru $r0.50 = $r0.50, 8   ## bblock 10, line 115-1,  t1358(I24),  t1350,  8(SI32)
	c0    cmplt $b0.0 = $r0.33, $r0.0   ## bblock 10, line 116-3,  t2119,  t371,  0(I32)
	c0    add $r0.37 = $r0.33, 255   ## bblock 10, line 116-3,  t2120,  t371,  255(I32)
	c0    add $r0.21 = $r0.21, $r0.6   ## bblock 10, line 116-5,  t325,  t2147,  t2148
	c0    and $r0.8 = $r0.48, 255   ## bblock 10, line 116-1,  t1423,  t1419,  255(I32)
	c0    shru $r0.48 = $r0.48, 8   ## bblock 10, line 115-1,  t1427(I24),  t1419,  8(SI32)
	c0    slct $r0.12 = $b0.0, $r0.12, $r0.37   ## bblock 10, line 116-6,  t2171,  t2169,  t2170,  t302
	c0    add $r0.18 = $r0.18, $r0.22   ## bblock 10, line 114-6,  t2902,  t2898,  t2899
	c0    ldw $r0.26 = (((filter7x7 + 0) + 36) + 0)[$r0.0]   ## bblock 10, line 114-1, t1322, 0(I32)
	c0    ldw $r0.6 = (((filter7x7 + 0) + 52) + 0)[$r0.0]   ## bblock 10, line 114-1, t1414, 0(I32)
;;								## 64
	c0    slct $r0.22 = $b0.1, $r0.22, $r0.4   ## bblock 10, line 116,  t2076,  t2074,  t2075,  t80
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 10, line 116-1,  t2089,  t417,  0(I32)
	c0    add $r0.18 = $r0.5, 255   ## bblock 10, line 116-1,  t2090,  t417,  255(I32)
	c0    and $r0.49 = $r0.49, 255   ## bblock 10, line 115-1,  t1336,  t1335(I24),  255(I32)
	c0    cmplt $b0.2 = $r0.35, $r0.0   ## bblock 10, line 116-2,  t2104,  t394,  0(I32)
	c0    add $r0.4 = $r0.35, 255   ## bblock 10, line 116-2,  t2105,  t394,  255(I32)
	c0    and $r0.50 = $r0.50, 255   ## bblock 10, line 115-1,  t1359,  t1358(I24),  255(I32)
	c0    slct $r0.37 = $b0.0, $r0.37, $r0.33   ## bblock 10, line 116-3,  t2121,  t2119,  t2120,  t371
	c0    cmplt $b0.1 = $r0.21, $r0.0   ## bblock 10, line 116-5,  t2149,  t325,  0(I32)
	c0    add $r0.33 = $r0.21, 255   ## bblock 10, line 116-5,  t2150,  t325,  255(I32)
	c0    and $r0.48 = $r0.48, 255   ## bblock 10, line 115-1,  t1428,  t1427(I24),  255(I32)
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 116-6,  t304,  t2171,  8(I32)
	c0    add $r0.23 = $r0.23, $r0.18   ## bblock 10, line 114-6,  t430,  t2901,  t2902
;;								## 65
	c0    shr $r0.22 = $r0.22, 8   ## bblock 10, line 116,  t221,  t2076,  8(I32)
	c0    slct $r0.18 = $b0.0, $r0.18, $r0.5   ## bblock 10, line 116-1,  t2091,  t2089,  t2090,  t417
	c0    slct $r0.4 = $b0.2, $r0.4, $r0.35   ## bblock 10, line 116-2,  t2106,  t2104,  t2105,  t394
	c0    shr $r0.37 = $r0.37, 8   ## bblock 10, line 116-3,  t373,  t2121,  8(I32)
	c0    mpylu $r0.5 = $r0.31, $r0.34   ## bblock 10, line 116-4,  t2132,  t338,  t347
	c0    mpyhs $r0.34 = $r0.31, $r0.34   ## bblock 10, line 116-4,  t2133,  t338,  t347
	c0    slct $r0.33 = $b0.1, $r0.33, $r0.21   ## bblock 10, line 116-5,  t2151,  t2149,  t2150,  t325
	c0    mpylu $r0.35 = $r0.26, $r0.44   ## bblock 10, line 116-1,  t2222,  t1322,  t1331
	c0    mpyhs $r0.44 = $r0.26, $r0.44   ## bblock 10, line 116-1,  t2223,  t1322,  t1331
	c0    mpylu $r0.21 = $r0.6, $r0.8   ## bblock 10, line 116-1,  t2288,  t1414,  t1423
	c0    mpyhs $r0.8 = $r0.6, $r0.8   ## bblock 10, line 116-1,  t2289,  t1414,  t1423
	c0    max $r0.23 = $r0.23, $r0.0   ## bblock 10, line 158,  t185,  t430,  0(SI32)
;;								## 66
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 116-1,  t419,  t2091,  8(I32)
	c0    shr $r0.4 = $r0.4, 8   ## bblock 10, line 116-2,  t396,  t2106,  8(I32)
	c0    shr $r0.33 = $r0.33, 8   ## bblock 10, line 116-5,  t327,  t2151,  8(I32)
	c0    add $r0.22 = $r0.22, $r0.12   ## bblock 10, line 116-6,  t2172,  t221,  t304
	c0    min $r0.23 = $r0.23, 255   ## bblock 10, line 158,  t90,  t185,  255(SI32)
;;								## 67
	c0    and $r0.44 = $r0.27, 255   ## bblock 10, line 116-1,  t1285,  t1281,  255(I32)
	c0    shru $r0.27 = $r0.27, 8   ## bblock 10, line 115-1,  t1289(I24),  t1281,  8(SI32)
	c0    and $r0.31 = $r0.52, 255   ## bblock 10, line 116-1,  t1308,  t1304,  255(I32)
	c0    add $r0.5 = $r0.5, $r0.34   ## bblock 10, line 116-4,  t348,  t2132,  t2133
	c0    and $r0.34 = $r0.51, 255   ## bblock 10, line 116-1,  t1400,  t1396,  255(I32)
	c0    shru $r0.51 = $r0.51, 8   ## bblock 10, line 115-1,  t1404(I24),  t1396,  8(SI32)
	c0    add $r0.18 = $r0.18, $r0.33   ## bblock 10, line 116-6,  t2173,  t419,  t327
	c0    add $r0.22 = $r0.22, $r0.37   ## bblock 10, line 116-6,  t2175,  t2172,  t373
	c0    add $r0.35 = $r0.35, $r0.44   ## bblock 10, line 116-1,  t1332,  t2222,  t2223
	c0    add $r0.21 = $r0.21, $r0.8   ## bblock 10, line 116-1,  t1424,  t2288,  t2289
	c0    shl $r0.23 = $r0.23, 16   ## bblock 10, line 159,  t93,  t90,  16(SI32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 48) + 0)[$r0.0]   ## bblock 10, line 114-1, t1391, 0(I32)
	c0    ldw $r0.33 = (((filter7x7 + 0) + 40) + 0)[$r0.0]   ## bblock 10, line 114-1, t1345, 0(I32)
	c0    ldw $r0.6 = (((filter7x7 + 0) + 28) + 0)[$r0.0]   ## bblock 10, line 114-1, t1276, 0(I32)
	c0    stw 0x44[$r0.1] = $r0.52  ## spill ## [spec] t1304
;;								## 68
	c0    and $r0.27 = $r0.27, 255   ## bblock 10, line 115-1,  t1290,  t1289(I24),  255(I32)
	c0    and $r0.8 = $r0.19, 255   ## bblock 10, line 116-1,  t1377,  t1373,  255(I32)
	c0    shru $r0.19 = $r0.19, 8   ## bblock 10, line 115-1,  t1381(I24),  t1373,  8(SI32)
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 10, line 116-4,  t2134,  t348,  0(I32)
	c0    add $r0.52 = $r0.5, 255   ## bblock 10, line 116-4,  t2135,  t348,  255(I32)
	c0    and $r0.51 = $r0.51, 255   ## bblock 10, line 115-1,  t1405,  t1404(I24),  255(I32)
	c0    cmplt $b0.2 = $r0.35, $r0.0   ## bblock 10, line 116-1,  t2224,  t1332,  0(I32)
	c0    cmplt $b0.1 = $r0.21, $r0.0   ## bblock 10, line 116-1,  t2290,  t1424,  0(I32)
	c0    add $r0.26 = $r0.21, 255   ## bblock 10, line 116-1,  t2291,  t1424,  255(I32)
	c0    ldw $r0.12 = (((filter7x7 + 0) + 32) + 0)[$r0.0]   ## bblock 10, line 114-1, t1299, 0(I32)
	c0    ldw $r0.24 = (((filter7x7 + 0) + 44) + 0)[$r0.0]   ## bblock 10, line 114-1, t1368, 0(I32)
;;								## 69
	c0    and $r0.19 = $r0.19, 255   ## bblock 10, line 115-1,  t1382,  t1381(I24),  255(I32)
	c0    slct $r0.52 = $b0.0, $r0.52, $r0.5   ## bblock 10, line 116-4,  t2136,  t2134,  t2135,  t348
	c0    add $r0.5 = $r0.35, 255   ## bblock 10, line 116-1,  t2225,  t1332,  255(I32)
	c0    mpylu $r0.21 = $r0.33, $r0.14   ## bblock 10, line 116-1,  t2237,  t1345,  t1354
	c0    mpyhs $r0.14 = $r0.33, $r0.14   ## bblock 10, line 116-1,  t2238,  t1345,  t1354
	c0    mpyhs $r0.33 = $r0.37, $r0.34   ## bblock 10, line 116-1,  t2268,  t1391,  t1400
	c0    slct $r0.26 = $b0.1, $r0.26, $r0.21   ## bblock 10, line 116-1,  t2292,  t2290,  t2291,  t1424
;;								## 70
	c0    shr $r0.52 = $r0.52, 8   ## bblock 10, line 116-4,  t350,  t2136,  8(I32)
	c0    mpylu $r0.35 = $r0.6, $r0.44   ## bblock 10, line 116-1,  t2192,  t1276,  t1285
	c0    mpyhs $r0.44 = $r0.6, $r0.44   ## bblock 10, line 116-1,  t2193,  t1276,  t1285
	c0    slct $r0.5 = $b0.2, $r0.5, $r0.35   ## bblock 10, line 116-1,  t2226,  t2224,  t2225,  t1332
	c0    mpylu $r0.34 = $r0.37, $r0.34   ## bblock 10, line 116-1,  t2267,  t1391,  t1400
	c0    shr $r0.26 = $r0.26, 8   ## bblock 10, line 116-1,  t1426,  t2292,  8(I32)
	c0    stw 0x48[$r0.1] = $r0.6  ## spill ## t1276
;;								## 71
	c0    and $r0.6 = $r0.53, 255   ## bblock 10, line 116-2,  t1255,  t1251,  255(I32)
	c0    shru $r0.53 = $r0.53, 8   ## bblock 10, line 115-2,  t1259(I24),  t1251,  8(SI32)
	c0    add $r0.4 = $r0.4, $r0.52   ## bblock 10, line 116-6,  t2174,  t396,  t350
	c0    mpylu $r0.14 = $r0.12, $r0.31   ## bblock 10, line 116-1,  t2207,  t1299,  t1308
	c0    mpyhs $r0.31 = $r0.12, $r0.31   ## bblock 10, line 116-1,  t2208,  t1299,  t1308
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 116-1,  t1334,  t2226,  8(I32)
	c0    add $r0.21 = $r0.21, $r0.14   ## bblock 10, line 116-1,  t1355,  t2237,  t2238
	c0    mpylu $r0.52 = $r0.24, $r0.8   ## bblock 10, line 116-1,  t2252,  t1368,  t1377
	c0    mpyhs $r0.8 = $r0.24, $r0.8   ## bblock 10, line 116-1,  t2253,  t1368,  t1377
;;								## 72
	c0    and $r0.53 = $r0.53, 255   ## bblock 10, line 115-2,  t1260,  t1259(I24),  255(I32)
	c0    add $r0.18 = $r0.18, $r0.4   ## bblock 10, line 116-6,  t2176,  t2173,  t2174
	c0    add $r0.35 = $r0.35, $r0.44   ## bblock 10, line 116-1,  t1286,  t2192,  t2193
	c0    cmplt $b0.0 = $r0.21, $r0.0   ## bblock 10, line 116-1,  t2239,  t1355,  0(I32)
	c0    add $r0.4 = $r0.21, 255   ## bblock 10, line 116-1,  t2240,  t1355,  255(I32)
	c0    add $r0.34 = $r0.34, $r0.33   ## bblock 10, line 116-1,  t1401,  t2267,  t2268
;;								## 73
	c0    add $r0.22 = $r0.22, $r0.18   ## bblock 10, line 116-6,  t2009,  t2175,  t2176
	c0    cmplt $b0.1 = $r0.35, $r0.0   ## bblock 10, line 116-1,  t2194,  t1286,  0(I32)
	c0    add $r0.21 = $r0.35, 255   ## bblock 10, line 116-1,  t2195,  t1286,  255(I32)
	c0    add $r0.14 = $r0.14, $r0.31   ## bblock 10, line 116-1,  t1309,  t2207,  t2208
	c0    slct $r0.4 = $b0.0, $r0.4, $r0.21   ## bblock 10, line 116-1,  t2241,  t2239,  t2240,  t1355
	c0    add $r0.52 = $r0.52, $r0.8   ## bblock 10, line 116-1,  t1378,  t2252,  t2253
	c0    cmplt $b0.0 = $r0.34, $r0.0   ## bblock 10, line 116-1,  t2269,  t1401,  0(I32)
	c0    add $r0.18 = $r0.34, 255   ## bblock 10, line 116-1,  t2270,  t1401,  255(I32)
	c0    ldw $r0.31 = (((filter7x7 + 0) + 80) + 0)[$r0.0]   ## bblock 10, line 114-2, t1246, 0(I32)
;;								## 74
	c0    and $r0.26 = $r0.54, 255   ## bblock 10, line 116-2,  t1163,  t1159,  255(I32)
	c0    shru $r0.54 = $r0.54, 8   ## bblock 10, line 115-2,  t1167(I24),  t1159,  8(SI32)
	c0    slct $r0.21 = $b0.1, $r0.21, $r0.35   ## bblock 10, line 116-1,  t2196,  t2194,  t2195,  t1286
	c0    cmplt $b0.0 = $r0.14, $r0.0   ## bblock 10, line 116-1,  t2209,  t1309,  0(I32)
	c0    add $r0.34 = $r0.14, 255   ## bblock 10, line 116-1,  t2210,  t1309,  255(I32)
	c0    shr $r0.4 = $r0.4, 8   ## bblock 10, line 116-1,  t1357,  t2241,  8(I32)
	c0    cmplt $b0.1 = $r0.52, $r0.0   ## bblock 10, line 116-1,  t2254,  t1378,  0(I32)
	c0    add $r0.35 = $r0.52, 255   ## bblock 10, line 116-1,  t2255,  t1378,  255(I32)
	c0    slct $r0.18 = $b0.0, $r0.18, $r0.34   ## bblock 10, line 116-1,  t2271,  t2269,  t2270,  t1401
	c0    add $r0.22 = $r0.22, $r0.26   ## bblock 10, line 116-1,  t2293,  t2009,  t1426
;;								## 75
	c0    and $r0.54 = $r0.54, 255   ## bblock 10, line 115-2,  t1168,  t1167(I24),  255(I32)
	c0    and $r0.4 = $r0.55, 255   ## bblock 10, line 116-2,  t1186,  t1182,  255(I32)
	c0    shru $r0.55 = $r0.55, 8   ## bblock 10, line 115-2,  t1190(I24),  t1182,  8(SI32)
	c0    shr $r0.21 = $r0.21, 8   ## bblock 10, line 116-1,  t1288,  t2196,  8(I32)
	c0    slct $r0.34 = $b0.0, $r0.34, $r0.14   ## bblock 10, line 116-1,  t2211,  t2209,  t2210,  t1309
	c0    slct $r0.35 = $b0.1, $r0.35, $r0.52   ## bblock 10, line 116-1,  t2256,  t2254,  t2255,  t1378
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 116-1,  t1403,  t2271,  8(I32)
	c0    mpyhs $r0.31 = $r0.37, $r0.51   ## bblock 10, line 115-1,  t2273,  t1391,  t1405
	c0    add $r0.5 = $r0.5, $r0.4   ## bblock 10, line 116-1,  t2296,  t1334,  t1357
	c0    mpylu $r0.14 = $r0.31, $r0.6   ## bblock 10, line 116-2,  t2411,  t1246,  t1255
	c0    mpyhs $r0.6 = $r0.31, $r0.6   ## bblock 10, line 116-2,  t2412,  t1246,  t1255
	c0    ldw $r0.52 = (((filter7x7 + 0) + 64) + 0)[$r0.0]   ## bblock 10, line 114-2, t1154, 0(I32)
;;								## 76
	c0    and $r0.33 = $r0.58, 255   ## bblock 10, line 116-2,  t1140,  t1136,  255(I32)
	c0    shru $r0.58 = $r0.58, 8   ## bblock 10, line 115-2,  t1144(I24),  t1136,  8(SI32)
	c0    and $r0.55 = $r0.55, 255   ## bblock 10, line 115-2,  t1191,  t1190(I24),  255(I32)
	c0    and $r0.8 = $r0.30, 255   ## bblock 10, line 116-2,  t1209,  t1205,  255(I32)
	c0    shru $r0.30 = $r0.30, 8   ## bblock 10, line 115-2,  t1213(I24),  t1205,  8(SI32)
	c0    and $r0.24 = $r0.56, 255   ## bblock 10, line 116-2,  t1232,  t1228,  255(I32)
	c0    shru $r0.56 = $r0.56, 8   ## bblock 10, line 115-2,  t1236(I24),  t1228,  8(SI32)
	c0    shr $r0.34 = $r0.34, 8   ## bblock 10, line 116-1,  t1311,  t2211,  8(I32)
	c0    shr $r0.35 = $r0.35, 8   ## bblock 10, line 116-1,  t1380,  t2256,  8(I32)
	c0    add $r0.21 = $r0.21, $r0.18   ## bblock 10, line 116-1,  t2294,  t1288,  t1403
	c0    add $r0.22 = $r0.22, $r0.5   ## bblock 10, line 116-1,  t2297,  t2293,  t2296
	c0    ldw $r0.18 = (((filter7x7 + 0) + 68) + 0)[$r0.0]   ## bblock 10, line 114-2, t1177, 0(I32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 56) + 0)[$r0.0]   ## bblock 10, line 114-2, t1108, 0(I32)
	c0    ldw $r0.44 = (((filter7x7 + 0) + 60) + 0)[$r0.0]   ## bblock 10, line 114-2, t1131, 0(I32)
;;								## 77
	c0    and $r0.58 = $r0.58, 255   ## bblock 10, line 115-2,  t1145,  t1144(I24),  255(I32)
	c0    and $r0.30 = $r0.30, 255   ## bblock 10, line 115-2,  t1214,  t1213(I24),  255(I32)
	c0    and $r0.56 = $r0.56, 255   ## bblock 10, line 115-2,  t1237,  t1236(I24),  255(I32)
	c0    and $r0.5 = $r0.59, 255   ## bblock 10, line 116-3,  t1087,  t1083,  255(I32)
	c0    shru $r0.59 = $r0.59, 8   ## bblock 10, line 115-3,  t1091(I24),  t1083,  8(SI32)
	c0    add $r0.34 = $r0.34, $r0.35   ## bblock 10, line 116-1,  t2295,  t1311,  t1380
	c0    mpylu $r0.35 = $r0.52, $r0.26   ## bblock 10, line 116-2,  t2345,  t1154,  t1163
	c0    mpyhs $r0.26 = $r0.52, $r0.26   ## bblock 10, line 116-2,  t2346,  t1154,  t1163
	c0    add $r0.14 = $r0.14, $r0.6   ## bblock 10, line 116-2,  t1256,  t2411,  t2412
	c0    ldw $r0.6 = 0x24[$r0.1]  ## restore ## t1223
	c0    ldw $r0.12 = (((filter7x7 + 0) + 72) + 0)[$r0.0]   ## bblock 10, line 114-2, t1200, 0(I32)
;;								## 78
	c0    and $r0.59 = $r0.59, 255   ## bblock 10, line 115-3,  t1092,  t1091(I24),  255(I32)
	c0    add $r0.21 = $r0.21, $r0.34   ## bblock 10, line 116-1,  t2298,  t2294,  t2295
	c0    mpylu $r0.52 = $r0.44, $r0.33   ## bblock 10, line 116-2,  t2330,  t1131,  t1140
	c0    mpyhs $r0.33 = $r0.44, $r0.33   ## bblock 10, line 116-2,  t2331,  t1131,  t1140
	c0    cmplt $b0.0 = $r0.14, $r0.0   ## bblock 10, line 116-2,  t2413,  t1256,  0(I32)
	c0    add $r0.34 = $r0.14, 255   ## bblock 10, line 116-2,  t2414,  t1256,  255(I32)
;;								## 79
	c0    and $r0.18 = $r0.60, 255   ## bblock 10, line 116-3,  t995,  t991,  255(I32)
	c0    shru $r0.60 = $r0.60, 8   ## bblock 10, line 115-3,  t999(I24),  t991,  8(SI32)
	c0    add $r0.22 = $r0.22, $r0.21   ## bblock 10, line 116-1,  t2013,  t2297,  t2298
	c0    add $r0.35 = $r0.35, $r0.26   ## bblock 10, line 116-2,  t1164,  t2345,  t2346
	c0    mpylu $r0.14 = $r0.18, $r0.4   ## bblock 10, line 116-2,  t2360,  t1177,  t1186
	c0    mpyhs $r0.4 = $r0.18, $r0.4   ## bblock 10, line 116-2,  t2361,  t1177,  t1186
	c0    mpylu $r0.21 = $r0.6, $r0.24   ## bblock 10, line 116-2,  t2390,  t1223,  t1232
	c0    mpyhs $r0.24 = $r0.6, $r0.24   ## bblock 10, line 116-2,  t2391,  t1223,  t1232
	c0    slct $r0.34 = $b0.0, $r0.34, $r0.14   ## bblock 10, line 116-2,  t2415,  t2413,  t2414,  t1256
	c0    ldw $r0.26 = 0x20[$r0.1]  ## restore ## [spec] t1113
;;								## 80
	c0    and $r0.60 = $r0.60, 255   ## bblock 10, line 115-3,  t1000,  t999(I24),  255(I32)
	c0    add $r0.52 = $r0.52, $r0.33   ## bblock 10, line 116-2,  t1141,  t2330,  t2331
	c0    cmplt $b0.0 = $r0.35, $r0.0   ## bblock 10, line 116-2,  t2347,  t1164,  0(I32)
	c0    add $r0.44 = $r0.35, 255   ## bblock 10, line 116-2,  t2348,  t1164,  255(I32)
	c0    mpylu $r0.33 = $r0.12, $r0.8   ## bblock 10, line 116-2,  t2375,  t1200,  t1209
	c0    mpyhs $r0.8 = $r0.12, $r0.8   ## bblock 10, line 116-2,  t2376,  t1200,  t1209
	c0    shr $r0.34 = $r0.34, 8   ## bblock 10, line 116-2,  t1258,  t2415,  8(I32)
;;								## 81
	c0    and $r0.24 = $r0.26, 255   ## bblock 10, line 116-2,  t1117,  t1113,  255(I32)
	c0    shru $r0.26 = $r0.26, 8   ## bblock 10, line 115-2,  t1121(I24),  t1113,  8(SI32)
	c0    cmplt $b0.0 = $r0.52, $r0.0   ## bblock 10, line 116-2,  t2332,  t1141,  0(I32)
	c0    add $r0.34 = $r0.52, 255   ## bblock 10, line 116-2,  t2333,  t1141,  255(I32)
	c0    slct $r0.44 = $b0.0, $r0.44, $r0.35   ## bblock 10, line 116-2,  t2349,  t2347,  t2348,  t1164
	c0    add $r0.14 = $r0.14, $r0.4   ## bblock 10, line 116-2,  t1187,  t2360,  t2361
	c0    add $r0.21 = $r0.21, $r0.24   ## bblock 10, line 116-2,  t1233,  t2390,  t2391
	c0    add $r0.22 = $r0.22, $r0.34   ## bblock 10, line 116-2,  t2416,  t2013,  t1258
	c0    ldw $r0.35 = (((filter7x7 + 0) + 108) + 0)[$r0.0]   ## bblock 10, line 114-3, t1078, 0(I32)
;;								## 82
	c0    and $r0.26 = $r0.26, 255   ## bblock 10, line 115-2,  t1122,  t1121(I24),  255(I32)
	c0    and $r0.52 = $r0.62, 255   ## bblock 10, line 116-3,  t1018,  t1014,  255(I32)
	c0    shru $r0.62 = $r0.62, 8   ## bblock 10, line 115-3,  t1022(I24),  t1014,  8(SI32)
	c0    slct $r0.34 = $b0.0, $r0.34, $r0.52   ## bblock 10, line 116-2,  t2334,  t2332,  t2333,  t1141
	c0    shr $r0.44 = $r0.44, 8   ## bblock 10, line 116-2,  t1166,  t2349,  8(I32)
	c0    cmplt $b0.1 = $r0.14, $r0.0   ## bblock 10, line 116-2,  t2362,  t1187,  0(I32)
	c0    add $r0.4 = $r0.14, 255   ## bblock 10, line 116-2,  t2363,  t1187,  255(I32)
	c0    add $r0.33 = $r0.33, $r0.8   ## bblock 10, line 116-2,  t1210,  t2375,  t2376
	c0    cmplt $b0.2 = $r0.21, $r0.0   ## bblock 10, line 116-2,  t2392,  t1233,  0(I32)
	c0    add $r0.12 = $r0.21, 255   ## bblock 10, line 116-2,  t2393,  t1233,  255(I32)
	c0    ldw $r0.8 = (((filter7x7 + 0) + 92) + 0)[$r0.0]   ## bblock 10, line 114-3, t986, 0(I32)
;;								## 83
	c0    and $r0.62 = $r0.62, 255   ## bblock 10, line 115-3,  t1023,  t1022(I24),  255(I32)
	c0    mpylu $r0.14 = $r0.37, $r0.24   ## bblock 10, line 116-2,  t2315,  t1108,  t1117
	c0    mpyhs $r0.24 = $r0.37, $r0.24   ## bblock 10, line 116-2,  t2316,  t1108,  t1117
	c0    shr $r0.34 = $r0.34, 8   ## bblock 10, line 116-2,  t1143,  t2334,  8(I32)
	c0    slct $r0.4 = $b0.1, $r0.4, $r0.14   ## bblock 10, line 116-2,  t2364,  t2362,  t2363,  t1187
	c0    cmplt $b0.0 = $r0.33, $r0.0   ## bblock 10, line 116-2,  t2377,  t1210,  0(I32)
	c0    add $r0.21 = $r0.33, 255   ## bblock 10, line 116-2,  t2378,  t1210,  255(I32)
	c0    slct $r0.12 = $b0.2, $r0.12, $r0.21   ## bblock 10, line 116-2,  t2394,  t2392,  t2393,  t1233
	c0    mpyhs $r0.37 = $r0.35, $r0.5   ## bblock 10, line 116-3,  t2535,  t1078,  t1087
;;								## 84
	c0    shr $r0.4 = $r0.4, 8   ## bblock 10, line 116-2,  t1189,  t2364,  8(I32)
	c0    slct $r0.21 = $b0.0, $r0.21, $r0.33   ## bblock 10, line 116-2,  t2379,  t2377,  t2378,  t1210
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 116-2,  t1235,  t2394,  8(I32)
	c0    mpylu $r0.33 = $r0.8, $r0.18   ## bblock 10, line 116-3,  t2468,  t986,  t995
	c0    mpyhs $r0.18 = $r0.8, $r0.18   ## bblock 10, line 116-3,  t2469,  t986,  t995
	c0    mpylu $r0.5 = $r0.35, $r0.5   ## bblock 10, line 116-3,  t2534,  t1078,  t1087
;;								## 85
	c0    add $r0.14 = $r0.14, $r0.24   ## bblock 10, line 116-2,  t1118,  t2315,  t2316
	c0    shr $r0.21 = $r0.21, 8   ## bblock 10, line 116-2,  t1212,  t2379,  8(I32)
	c0    add $r0.44 = $r0.44, $r0.4   ## bblock 10, line 116-2,  t2419,  t1166,  t1189
	c0    ldw $r0.4 = (((filter7x7 + 0) + 96) + 0)[$r0.0]   ## bblock 10, line 114-3, t1009, 0(I32)
;;								## 86
	c0    and $r0.35 = $r0.10, 255   ## bblock 10, line 116-3,  t949,  t945,  255(I32)
	c0    shru $r0.10 = $r0.10, 8   ## bblock 10, line 115-3,  t953(I24),  t945,  8(SI32)
	c0    and $r0.18 = $r0.7, 255   ## bblock 10, line 116-3,  t1064,  t1060,  255(I32)
	c0    shru $r0.7 = $r0.7, 8   ## bblock 10, line 115-3,  t1068(I24),  t1060,  8(SI32)
	c0    cmplt $b0.0 = $r0.14, $r0.0   ## bblock 10, line 116-2,  t2317,  t1118,  0(I32)
	c0    add $r0.44 = $r0.14, 255   ## bblock 10, line 116-2,  t2318,  t1118,  255(I32)
	c0    add $r0.34 = $r0.34, $r0.21   ## bblock 10, line 116-2,  t2418,  t1143,  t1212
	c0    add $r0.22 = $r0.22, $r0.44   ## bblock 10, line 116-2,  t2420,  t2416,  t2419
	c0    add $r0.33 = $r0.33, $r0.18   ## bblock 10, line 116-3,  t996,  t2468,  t2469
	c0    add $r0.5 = $r0.5, $r0.37   ## bblock 10, line 116-3,  t1088,  t2534,  t2535
	c0    ldw $r0.37 = (((filter7x7 + 0) + 104) + 0)[$r0.0]   ## bblock 10, line 114-3, t1055, 0(I32)
	c0    ldw $r0.8 = (((filter7x7 + 0) + 84) + 0)[$r0.0]   ## bblock 10, line 114-3, t940, 0(I32)
;;								## 87
	c0    and $r0.10 = $r0.10, 255   ## bblock 10, line 115-3,  t954,  t953(I24),  255(I32)
	c0    and $r0.7 = $r0.7, 255   ## bblock 10, line 115-3,  t1069,  t1068(I24),  255(I32)
	c0    slct $r0.44 = $b0.0, $r0.44, $r0.14   ## bblock 10, line 116-2,  t2319,  t2317,  t2318,  t1118
	c0    cmplt $b0.1 = $r0.33, $r0.0   ## bblock 10, line 116-3,  t2470,  t996,  0(I32)
	c0    add $r0.21 = $r0.33, 255   ## bblock 10, line 116-3,  t2471,  t996,  255(I32)
	c0    mpyhs $r0.24 = $r0.4, $r0.52   ## bblock 10, line 116-3,  t2484,  t1009,  t1018
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 10, line 116-3,  t2536,  t1088,  0(I32)
	c0    add $r0.14 = $r0.5, 255   ## bblock 10, line 116-3,  t2537,  t1088,  255(I32)
;;								## 88
	c0    shr $r0.44 = $r0.44, 8   ## bblock 10, line 116-2,  t1120,  t2319,  8(I32)
	c0    mpylu $r0.33 = $r0.8, $r0.35   ## bblock 10, line 116-3,  t2438,  t940,  t949
	c0    mpyhs $r0.35 = $r0.8, $r0.35   ## bblock 10, line 116-3,  t2439,  t940,  t949
	c0    slct $r0.21 = $b0.1, $r0.21, $r0.33   ## bblock 10, line 116-3,  t2472,  t2470,  t2471,  t996
	c0    mpylu $r0.52 = $r0.4, $r0.52   ## bblock 10, line 116-3,  t2483,  t1009,  t1018
	c0    mpylu $r0.5 = $r0.37, $r0.18   ## bblock 10, line 116-3,  t2513,  t1055,  t1064
	c0    mpyhs $r0.18 = $r0.37, $r0.18   ## bblock 10, line 116-3,  t2514,  t1055,  t1064
	c0    slct $r0.14 = $b0.0, $r0.14, $r0.5   ## bblock 10, line 116-3,  t2538,  t2536,  t2537,  t1088
;;								## 89
	c0    and $r0.12 = $r0.61, 255   ## bblock 10, line 116-3,  t972,  t968,  255(I32)
	c0    shru $r0.61 = $r0.61, 8   ## bblock 10, line 115-3,  t976(I24),  t968,  8(SI32)
	c0    add $r0.44 = $r0.44, $r0.12   ## bblock 10, line 116-2,  t2417,  t1120,  t1235
	c0    shr $r0.21 = $r0.21, 8   ## bblock 10, line 116-3,  t998,  t2472,  8(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 116-3,  t1090,  t2538,  8(I32)
;;								## 90
	c0    and $r0.61 = $r0.61, 255   ## bblock 10, line 115-3,  t977,  t976(I24),  255(I32)
	c0    and $r0.24 = $r0.38, 255   ## bblock 10, line 116-3,  t1041,  t1037,  255(I32)
	c0    add $r0.44 = $r0.44, $r0.34   ## bblock 10, line 116-2,  t2421,  t2417,  t2418
	c0    add $r0.33 = $r0.33, $r0.35   ## bblock 10, line 116-3,  t950,  t2438,  t2439
	c0    add $r0.52 = $r0.52, $r0.24   ## bblock 10, line 116-3,  t1019,  t2483,  t2484
	c0    add $r0.5 = $r0.5, $r0.18   ## bblock 10, line 116-3,  t1065,  t2513,  t2514
	c0    ldw $r0.18 = (((filter7x7 + 0) + 88) + 0)[$r0.0]   ## bblock 10, line 114-3, t963, 0(I32)
	c0    ldw $r0.8 = (((filter7x7 + 0) + 100) + 0)[$r0.0]   ## bblock 10, line 114-3, t1032, 0(I32)
	c0    stw 0x4c[$r0.1] = $r0.38  ## spill ## t1037
;;								## 91
	c0    and $r0.35 = $r0.16, 255   ## bblock 10, line 116-4,  t827,  t823,  255(I32)
	c0    shru $r0.16 = $r0.16, 8   ## bblock 10, line 115-4,  t831(I24),  t823,  8(SI32)
	c0    add $r0.22 = $r0.22, $r0.44   ## bblock 10, line 116-2,  t2017,  t2420,  t2421
	c0    cmplt $b0.2 = $r0.33, $r0.0   ## bblock 10, line 116-3,  t2440,  t950,  0(I32)
	c0    cmplt $b0.0 = $r0.52, $r0.0   ## bblock 10, line 116-3,  t2485,  t1019,  0(I32)
	c0    add $r0.38 = $r0.52, 255   ## bblock 10, line 116-3,  t2486,  t1019,  255(I32)
	c0    cmplt $b0.1 = $r0.5, $r0.0   ## bblock 10, line 116-3,  t2515,  t1065,  0(I32)
	c0    add $r0.44 = $r0.5, 255   ## bblock 10, line 116-3,  t2516,  t1065,  255(I32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 120) + 0)[$r0.0]   ## bblock 10, line 114-4, t818, 0(I32)
	c0    ldw $r0.34 = (((filter7x7 + 0) + 136) + 0)[$r0.0]   ## bblock 10, line 114-4, t910, 0(I32)
;;								## 92
	c0    and $r0.16 = $r0.16, 255   ## bblock 10, line 115-4,  t832,  t831(I24),  255(I32)
	c0    mpyhs $r0.18 = $r0.6, $r0.56   ## bblock 10, line 115-2,  t2396,  t1223,  t1237
	c0    add $r0.5 = $r0.33, 255   ## bblock 10, line 116-3,  t2441,  t950,  255(I32)
	c0    mpylu $r0.14 = $r0.18, $r0.12   ## bblock 10, line 116-3,  t2453,  t963,  t972
	c0    mpyhs $r0.12 = $r0.18, $r0.12   ## bblock 10, line 116-3,  t2454,  t963,  t972
	c0    slct $r0.38 = $b0.0, $r0.38, $r0.52   ## bblock 10, line 116-3,  t2487,  t2485,  t2486,  t1019
	c0    mpylu $r0.52 = $r0.8, $r0.24   ## bblock 10, line 116-3,  t2498,  t1032,  t1041
	c0    mpyhs $r0.24 = $r0.8, $r0.24   ## bblock 10, line 116-3,  t2499,  t1032,  t1041
	c0    slct $r0.44 = $b0.1, $r0.44, $r0.5   ## bblock 10, line 116-3,  t2517,  t2515,  t2516,  t1065
	c0    add $r0.22 = $r0.22, $r0.14   ## bblock 10, line 116-3,  t2539,  t2017,  t1090
;;								## 93
	c0    mpylu $r0.6 = $r0.6, $r0.56   ## bblock 10, line 115-2,  t2395,  t1223,  t1237
	c0    slct $r0.5 = $b0.2, $r0.5, $r0.33   ## bblock 10, line 116-3,  t2442,  t2440,  t2441,  t950
	c0    shr $r0.38 = $r0.38, 8   ## bblock 10, line 116-3,  t1021,  t2487,  8(I32)
	c0    shr $r0.44 = $r0.44, 8   ## bblock 10, line 116-3,  t1067,  t2517,  8(I32)
	c0    ldw $r0.33 = 0x2c[$r0.1]  ## restore ## t915
	c0    ldw $r0.56 = (((filter7x7 + 0) + 72) + 0)[$r0.0]   ## bblock 10, line 114-2, t1200, 0(I32)
;;								## 94
	c0    and $r0.24 = $r0.2, 255   ## bblock 10, line 116-4,  t850,  t846,  255(I32)
	c0    shru $r0.2 = $r0.2, 8   ## bblock 10, line 115-4,  t854(I24),  t846,  8(SI32)
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 116-3,  t952,  t2442,  8(I32)
	c0    add $r0.14 = $r0.14, $r0.12   ## bblock 10, line 116-3,  t973,  t2453,  t2454
	c0    add $r0.52 = $r0.52, $r0.24   ## bblock 10, line 116-3,  t1042,  t2498,  t2499
	c0    add $r0.21 = $r0.21, $r0.38   ## bblock 10, line 116-3,  t2542,  t998,  t1021
	c0    mpylu $r0.12 = $r0.37, $r0.35   ## bblock 10, line 116-4,  t2591,  t818,  t827
	c0    mpyhs $r0.35 = $r0.37, $r0.35   ## bblock 10, line 116-4,  t2592,  t818,  t827
;;								## 95
	c0    and $r0.2 = $r0.2, 255   ## bblock 10, line 115-4,  t855,  t854(I24),  255(I32)
	c0    mpylu $r0.18 = $r0.56, $r0.30   ## bblock 10, line 115-2,  t2380,  t1200,  t1214
	c0    mpyhs $r0.56 = $r0.56, $r0.30   ## bblock 10, line 115-2,  t2381,  t1200,  t1214
	c0    add $r0.6 = $r0.6, $r0.18   ## bblock 10, line 115-2,  t1238,  t2395,  t2396
	c0    cmplt $b0.0 = $r0.14, $r0.0   ## bblock 10, line 116-3,  t2455,  t973,  0(I32)
	c0    add $r0.21 = $r0.14, 255   ## bblock 10, line 116-3,  t2456,  t973,  255(I32)
	c0    cmplt $b0.1 = $r0.52, $r0.0   ## bblock 10, line 116-3,  t2500,  t1042,  0(I32)
	c0    add $r0.44 = $r0.52, 255   ## bblock 10, line 116-3,  t2501,  t1042,  255(I32)
	c0    add $r0.5 = $r0.5, $r0.44   ## bblock 10, line 116-3,  t2540,  t952,  t1067
	c0    add $r0.22 = $r0.22, $r0.21   ## bblock 10, line 116-3,  t2543,  t2539,  t2542
;;								## 96
	c0    and $r0.30 = $r0.36, 255   ## bblock 10, line 116-4,  t781,  t777,  255(I32)
	c0    shru $r0.36 = $r0.36, 8   ## bblock 10, line 115-4,  t785(I24),  t777,  8(SI32)
	c0    and $r0.8 = $r0.57, 255   ## bblock 10, line 116-4,  t804,  t800,  255(I32)
	c0    shru $r0.57 = $r0.57, 8   ## bblock 10, line 115-4,  t808(I24),  t800,  8(SI32)
	c0    and $r0.52 = $r0.25, 255   ## bblock 10, line 116-4,  t896,  t892,  255(I32)
	c0    shru $r0.25 = $r0.25, 8   ## bblock 10, line 115-4,  t900(I24),  t892,  8(SI32)
	c0    and $r0.14 = $r0.33, 255   ## bblock 10, line 116-4,  t919,  t915,  255(I32)
	c0    shru $r0.33 = $r0.33, 8   ## bblock 10, line 115-4,  t923(I24),  t915,  8(SI32)
	c0    cmplt $b0.0 = $r0.6, $r0.0   ## bblock 10, line 115-2,  t2397,  t1238,  0(I32)
	c0    slct $r0.21 = $b0.0, $r0.21, $r0.14   ## bblock 10, line 116-3,  t2457,  t2455,  t2456,  t973
	c0    slct $r0.44 = $b0.1, $r0.44, $r0.52   ## bblock 10, line 116-3,  t2502,  t2500,  t2501,  t1042
	c0    add $r0.12 = $r0.12, $r0.35   ## bblock 10, line 116-4,  t828,  t2591,  t2592
	c0    ldw $r0.35 = (((filter7x7 + 0) + 124) + 0)[$r0.0]   ## bblock 10, line 114-4, t841, 0(I32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 132) + 0)[$r0.0]   ## bblock 10, line 114-4, t887, 0(I32)
;;								## 97
	c0    and $r0.36 = $r0.36, 255   ## bblock 10, line 115-4,  t786,  t785(I24),  255(I32)
	c0    and $r0.57 = $r0.57, 255   ## bblock 10, line 115-4,  t809,  t808(I24),  255(I32)
	c0    and $r0.25 = $r0.25, 255   ## bblock 10, line 115-4,  t901,  t900(I24),  255(I32)
	c0    and $r0.33 = $r0.33, 255   ## bblock 10, line 115-4,  t924,  t923(I24),  255(I32)
	c0    add $r0.18 = $r0.18, $r0.56   ## bblock 10, line 115-2,  t1215,  t2380,  t2381
	c0    shr $r0.21 = $r0.21, 8   ## bblock 10, line 116-3,  t975,  t2457,  8(I32)
	c0    shr $r0.44 = $r0.44, 8   ## bblock 10, line 116-3,  t1044,  t2502,  8(I32)
	c0    cmplt $b0.1 = $r0.12, $r0.0   ## bblock 10, line 116-4,  t2593,  t828,  0(I32)
	c0    mpylu $r0.4 = $r0.34, $r0.14   ## bblock 10, line 116-4,  t2657,  t910,  t919
	c0    mpyhs $r0.14 = $r0.34, $r0.14   ## bblock 10, line 116-4,  t2658,  t910,  t919
;;								## 98
	c0    and $r0.34 = $r0.40, 255   ## bblock 10, line 116-4,  t873,  t869,  255(I32)
	c0    shru $r0.40 = $r0.40, 8   ## bblock 10, line 115-4,  t877(I24),  t869,  8(SI32)
	c0    cmplt $b0.2 = $r0.18, $r0.0   ## bblock 10, line 115-2,  t2382,  t1215,  0(I32)
	c0    add $r0.21 = $r0.21, $r0.44   ## bblock 10, line 116-3,  t2541,  t975,  t1044
	c0    add $r0.44 = $r0.12, 255   ## bblock 10, line 116-4,  t2594,  t828,  255(I32)
	c0    ldw $r0.56 = (((filter7x7 + 0) + 116) + 0)[$r0.0]   ## bblock 10, line 114-4, t795, 0(I32)
;;								## 99
	c0    and $r0.40 = $r0.40, 255   ## bblock 10, line 115-4,  t878,  t877(I24),  255(I32)
	c0    add $r0.5 = $r0.5, $r0.21   ## bblock 10, line 116-3,  t2544,  t2540,  t2541
	c0    slct $r0.44 = $b0.1, $r0.44, $r0.12   ## bblock 10, line 116-4,  t2595,  t2593,  t2594,  t828
	c0    mpylu $r0.12 = $r0.35, $r0.24   ## bblock 10, line 116-4,  t2606,  t841,  t850
	c0    mpyhs $r0.24 = $r0.35, $r0.24   ## bblock 10, line 116-4,  t2607,  t841,  t850
	c0    mpylu $r0.14 = $r0.37, $r0.52   ## bblock 10, line 116-4,  t2636,  t887,  t896
	c0    mpyhs $r0.52 = $r0.37, $r0.52   ## bblock 10, line 116-4,  t2637,  t887,  t896
	c0    add $r0.4 = $r0.4, $r0.14   ## bblock 10, line 116-4,  t920,  t2657,  t2658
	c0    ldw $r0.21 = 0x34[$r0.1]  ## restore ## t772
	c0    ldw $r0.38 = (((filter7x7 + 0) + 164) + 0)[$r0.0]   ## bblock 10, line 114-5, t742, 0(I32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 128) + 0)[$r0.0]   ## bblock 10, line 114-4, t864, 0(I32)
;;								## 100
	c0    add $r0.22 = $r0.22, $r0.5   ## bblock 10, line 116-3,  t2021,  t2543,  t2544
	c0    mpyhs $r0.35 = $r0.56, $r0.8   ## bblock 10, line 116-4,  t2577,  t795,  t804
	c0    shr $r0.44 = $r0.44, 8   ## bblock 10, line 116-4,  t830,  t2595,  8(I32)
	c0    cmplt $b0.1 = $r0.4, $r0.0   ## bblock 10, line 116-4,  t2659,  t920,  0(I32)
	c0    add $r0.5 = $r0.4, 255   ## bblock 10, line 116-4,  t2660,  t920,  255(I32)
;;								## 101
	c0    mpylu $r0.24 = $r0.21, $r0.30   ## bblock 10, line 116-4,  t2561,  t772,  t781
	c0    mpyhs $r0.30 = $r0.21, $r0.30   ## bblock 10, line 116-4,  t2562,  t772,  t781
	c0    mpylu $r0.8 = $r0.56, $r0.8   ## bblock 10, line 116-4,  t2576,  t795,  t804
	c0    add $r0.12 = $r0.12, $r0.24   ## bblock 10, line 116-4,  t851,  t2606,  t2607
	c0    mpylu $r0.52 = $r0.37, $r0.34   ## bblock 10, line 116-4,  t2621,  t864,  t873
	c0    mpyhs $r0.34 = $r0.37, $r0.34   ## bblock 10, line 116-4,  t2622,  t864,  t873
	c0    add $r0.14 = $r0.14, $r0.52   ## bblock 10, line 116-4,  t897,  t2636,  t2637
	c0    slct $r0.5 = $b0.1, $r0.5, $r0.4   ## bblock 10, line 116-4,  t2661,  t2659,  t2660,  t920
	c0    ldw $r0.4 = 0x28[$r0.1]  ## restore ## t747
;;								## 102
	c0    cmplt $b0.1 = $r0.12, $r0.0   ## bblock 10, line 116-4,  t2608,  t851,  0(I32)
	c0    add $r0.37 = $r0.12, 255   ## bblock 10, line 116-4,  t2609,  t851,  255(I32)
	c0    cmplt $b0.3 = $r0.14, $r0.0   ## bblock 10, line 116-4,  t2638,  t897,  0(I32)
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 116-4,  t922,  t2661,  8(I32)
;;								## 103
	c0    and $r0.12 = $r0.4, 255   ## bblock 10, line 116-5,  t751,  t747,  255(I32)
	c0    shru $r0.4 = $r0.4, 8   ## bblock 10, line 115-5,  t755(I24),  t747,  8(SI32)
	c0    add $r0.24 = $r0.24, $r0.30   ## bblock 10, line 116-4,  t782,  t2561,  t2562
	c0    add $r0.8 = $r0.8, $r0.35   ## bblock 10, line 116-4,  t805,  t2576,  t2577
	c0    slct $r0.37 = $b0.1, $r0.37, $r0.12   ## bblock 10, line 116-4,  t2610,  t2608,  t2609,  t851
	c0    add $r0.52 = $r0.52, $r0.34   ## bblock 10, line 116-4,  t874,  t2621,  t2622
	c0    add $r0.5 = $r0.14, 255   ## bblock 10, line 116-4,  t2639,  t897,  255(I32)
	c0    add $r0.22 = $r0.22, $r0.5   ## bblock 10, line 116-4,  t2662,  t2021,  t922
	c0    ldw $r0.30 = 0x30[$r0.1]  ## restore ## t655
	c0    ldw $r0.56 = (((filter7x7 + 0) + 148) + 0)[$r0.0]   ## bblock 10, line 114-5, t650, 0(I32)
;;								## 104
	c0    and $r0.4 = $r0.4, 255   ## bblock 10, line 115-5,  t756,  t755(I24),  255(I32)
	c0    cmplt $b0.1 = $r0.24, $r0.0   ## bblock 10, line 116-4,  t2563,  t782,  0(I32)
	c0    add $r0.14 = $r0.24, 255   ## bblock 10, line 116-4,  t2564,  t782,  255(I32)
	c0    cmplt $b0.3 = $r0.8, $r0.0   ## bblock 10, line 116-4,  t2578,  t805,  0(I32)
	c0    shr $r0.37 = $r0.37, 8   ## bblock 10, line 116-4,  t853,  t2610,  8(I32)
	c0    cmplt $b0.4 = $r0.52, $r0.0   ## bblock 10, line 116-4,  t2623,  t874,  0(I32)
	c0    slct $r0.5 = $b0.3, $r0.5, $r0.14   ## bblock 10, line 116-4,  t2640,  t2638,  t2639,  t897
	c0    mpyhs $r0.34 = $r0.38, $r0.12   ## bblock 10, line 116-5,  t2781,  t742,  t751
;;								## 105
	c0    slct $r0.14 = $b0.1, $r0.14, $r0.24   ## bblock 10, line 116-4,  t2565,  t2563,  t2564,  t782
	c0    add $r0.24 = $r0.8, 255   ## bblock 10, line 116-4,  t2579,  t805,  255(I32)
	c0    add $r0.37 = $r0.52, 255   ## bblock 10, line 116-4,  t2624,  t874,  255(I32)
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 116-4,  t899,  t2640,  8(I32)
	c0    add $r0.44 = $r0.44, $r0.37   ## bblock 10, line 116-4,  t2665,  t830,  t853
	c0    mpylu $r0.12 = $r0.38, $r0.12   ## bblock 10, line 116-5,  t2780,  t742,  t751
;;								## 106
	c0    and $r0.8 = $r0.30, 255   ## bblock 10, line 116-5,  t659,  t655,  255(I32)
	c0    shru $r0.30 = $r0.30, 8   ## bblock 10, line 115-5,  t663(I24),  t655,  8(SI32)
	c0    and $r0.44 = $r0.32, 255   ## bblock 10, line 116-5,  t682,  t678,  255(I32)
	c0    shru $r0.32 = $r0.32, 8   ## bblock 10, line 115-5,  t686(I24),  t678,  8(SI32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 116-4,  t784,  t2565,  8(I32)
	c0    slct $r0.24 = $b0.3, $r0.24, $r0.8   ## bblock 10, line 116-4,  t2580,  t2578,  t2579,  t805
	c0    slct $r0.37 = $b0.4, $r0.37, $r0.52   ## bblock 10, line 116-4,  t2625,  t2623,  t2624,  t874
	c0    add $r0.22 = $r0.22, $r0.44   ## bblock 10, line 116-4,  t2666,  t2662,  t2665
;;								## 107
	c0    and $r0.52 = $r0.20, 255   ## bblock 10, line 116-5,  t613,  t609,  255(I32)
	c0    and $r0.30 = $r0.30, 255   ## bblock 10, line 115-5,  t664,  t663(I24),  255(I32)
	c0    and $r0.32 = $r0.32, 255   ## bblock 10, line 115-5,  t687,  t686(I24),  255(I32)
	c0    and $r0.56 = $r0.63, 255   ## bblock 10, line 116-5,  t728,  t724,  255(I32)
	c0    shru $r0.63 = $r0.63, 8   ## bblock 10, line 115-5,  t732(I24),  t724,  8(SI32)
	c0    shr $r0.24 = $r0.24, 8   ## bblock 10, line 116-4,  t807,  t2580,  8(I32)
	c0    shr $r0.37 = $r0.37, 8   ## bblock 10, line 116-4,  t876,  t2625,  8(I32)
	c0    add $r0.14 = $r0.14, $r0.5   ## bblock 10, line 116-4,  t2663,  t784,  t899
	c0    mpylu $r0.5 = $r0.56, $r0.8   ## bblock 10, line 116-5,  t2714,  t650,  t659
	c0    mpyhs $r0.8 = $r0.56, $r0.8   ## bblock 10, line 116-5,  t2715,  t650,  t659
	c0    add $r0.12 = $r0.12, $r0.34   ## bblock 10, line 116-5,  t752,  t2780,  t2781
	c0    ldw $r0.34 = (((filter7x7 + 0) + 152) + 0)[$r0.0]   ## bblock 10, line 114-5, t673, 0(I32)
	c0    ldw $r0.35 = (((filter7x7 + 0) + 160) + 0)[$r0.0]   ## bblock 10, line 114-5, t719, 0(I32)
	c0    stw 0x50[$r0.1] = $r0.20  ## spill ## t609
;;								## 108
	c0    and $r0.63 = $r0.63, 255   ## bblock 10, line 115-5,  t733,  t732(I24),  255(I32)
	c0    add $r0.24 = $r0.24, $r0.37   ## bblock 10, line 116-4,  t2664,  t807,  t876
	c0    cmplt $b0.1 = $r0.12, $r0.0   ## bblock 10, line 116-5,  t2782,  t752,  0(I32)
	c0    add $r0.20 = $r0.12, 255   ## bblock 10, line 116-5,  t2783,  t752,  255(I32)
;;								## 109
	c0    add $r0.14 = $r0.14, $r0.24   ## bblock 10, line 116-4,  t2667,  t2663,  t2664
	c0    add $r0.5 = $r0.5, $r0.8   ## bblock 10, line 116-5,  t660,  t2714,  t2715
	c0    mpylu $r0.8 = $r0.34, $r0.44   ## bblock 10, line 116-5,  t2729,  t673,  t682
	c0    mpyhs $r0.44 = $r0.34, $r0.44   ## bblock 10, line 116-5,  t2730,  t673,  t682
	c0    mpylu $r0.12 = $r0.35, $r0.56   ## bblock 10, line 116-5,  t2759,  t719,  t728
	c0    mpyhs $r0.56 = $r0.35, $r0.56   ## bblock 10, line 116-5,  t2760,  t719,  t728
	c0    slct $r0.20 = $b0.1, $r0.20, $r0.12   ## bblock 10, line 116-5,  t2784,  t2782,  t2783,  t752
	c0    ldw $r0.24 = (((filter7x7 + 0) + 140) + 0)[$r0.0]   ## bblock 10, line 114-5, t604, 0(I32)
;;								## 110
	c0    add $r0.22 = $r0.22, $r0.14   ## bblock 10, line 116-4,  t2025,  t2666,  t2667
	c0    cmplt $b0.1 = $r0.5, $r0.0   ## bblock 10, line 116-5,  t2716,  t660,  0(I32)
	c0    add $r0.14 = $r0.5, 255   ## bblock 10, line 116-5,  t2717,  t660,  255(I32)
	c0    shr $r0.20 = $r0.20, 8   ## bblock 10, line 116-5,  t754,  t2784,  8(I32)
;;								## 111
	c0    and $r0.20 = $r0.29, 255   ## bblock 10, line 116-5,  t636,  t632,  255(I32)
	c0    shru $r0.29 = $r0.29, 8   ## bblock 10, line 115-5,  t640(I24),  t632,  8(SI32)
	c0    and $r0.56 = $r0.28, 255   ## bblock 10, line 116-5,  t705,  t701,  255(I32)
	c0    shru $r0.28 = $r0.28, 8   ## bblock 10, line 115-5,  t709(I24),  t701,  8(SI32)
	c0    and $r0.38 = $r0.3, 255   ## bblock 10, line 116-6,  t583,  t579,  255(I32)
	c0    mpylu $r0.5 = $r0.24, $r0.52   ## bblock 10, line 116-5,  t2684,  t604,  t613
	c0    mpyhs $r0.52 = $r0.24, $r0.52   ## bblock 10, line 116-5,  t2685,  t604,  t613
	c0    slct $r0.14 = $b0.1, $r0.14, $r0.5   ## bblock 10, line 116-5,  t2718,  t2716,  t2717,  t660
	c0    add $r0.8 = $r0.8, $r0.44   ## bblock 10, line 116-5,  t683,  t2729,  t2730
	c0    add $r0.12 = $r0.12, $r0.56   ## bblock 10, line 116-5,  t729,  t2759,  t2760
	c0    add $r0.22 = $r0.22, $r0.20   ## bblock 10, line 116-5,  t2785,  t2025,  t754
	c0    ldw $r0.44 = (((filter7x7 + 0) + 144) + 0)[$r0.0]   ## bblock 10, line 114-5, t627, 0(I32)
	c0    ldw $r0.35 = (((filter7x7 + 0) + 156) + 0)[$r0.0]   ## bblock 10, line 114-5, t696, 0(I32)
	c0    stw 0x54[$r0.1] = $r0.3  ## spill ## t579
;;								## 112
	c0    and $r0.29 = $r0.29, 255   ## bblock 10, line 115-5,  t641,  t640(I24),  255(I32)
	c0    and $r0.28 = $r0.28, 255   ## bblock 10, line 115-5,  t710,  t709(I24),  255(I32)
	c0    and $r0.34 = $r0.15, 255   ## bblock 10, line 116-6,  t491,  t487,  255(I32)
	c0    shru $r0.15 = $r0.15, 8   ## bblock 10, line 115-6,  t495(I24),  t487,  8(SI32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 116-5,  t662,  t2718,  8(I32)
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## bblock 10, line 116-5,  t2731,  t683,  0(I32)
	c0    add $r0.3 = $r0.8, 255   ## bblock 10, line 116-5,  t2732,  t683,  255(I32)
	c0    cmplt $b0.3 = $r0.12, $r0.0   ## bblock 10, line 116-5,  t2761,  t729,  0(I32)
	c0    add $r0.24 = $r0.12, 255   ## bblock 10, line 116-5,  t2762,  t729,  255(I32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 192) + 0)[$r0.0]   ## bblock 10, line 114-6, t574, 0(I32)
;;								## 113
	c0    and $r0.15 = $r0.15, 255   ## bblock 10, line 115-6,  t496,  t495(I24),  255(I32)
	c0    and $r0.44 = $r0.9, 255   ## bblock 10, line 116-6,  t514,  t510,  255(I32)
	c0    shru $r0.9 = $r0.9, 8   ## bblock 10, line 115-6,  t518(I24),  t510,  8(SI32)
	c0    add $r0.5 = $r0.5, $r0.52   ## bblock 10, line 116-5,  t614,  t2684,  t2685
	c0    mpylu $r0.8 = $r0.44, $r0.20   ## bblock 10, line 116-5,  t2699,  t627,  t636
	c0    mpyhs $r0.20 = $r0.44, $r0.20   ## bblock 10, line 116-5,  t2700,  t627,  t636
	c0    slct $r0.3 = $b0.1, $r0.3, $r0.8   ## bblock 10, line 116-5,  t2733,  t2731,  t2732,  t683
	c0    mpylu $r0.12 = $r0.35, $r0.56   ## bblock 10, line 116-5,  t2744,  t696,  t705
	c0    mpyhs $r0.56 = $r0.35, $r0.56   ## bblock 10, line 116-5,  t2745,  t696,  t705
	c0    slct $r0.24 = $b0.3, $r0.24, $r0.12   ## bblock 10, line 116-5,  t2763,  t2761,  t2762,  t729
	c0    ldw $r0.52 = (((filter7x7 + 0) + 176) + 0)[$r0.0]   ## bblock 10, line 114-6, t482, 0(I32)
;;								## 114
	c0    and $r0.9 = $r0.9, 255   ## bblock 10, line 115-6,  t519,  t518(I24),  255(I32)
	c0    cmplt $b0.1 = $r0.5, $r0.0   ## bblock 10, line 116-5,  t2686,  t614,  0(I32)
	c0    add $r0.35 = $r0.5, 255   ## bblock 10, line 116-5,  t2687,  t614,  255(I32)
	c0    shr $r0.3 = $r0.3, 8   ## bblock 10, line 116-5,  t685,  t2733,  8(I32)
	c0    shr $r0.24 = $r0.24, 8   ## bblock 10, line 116-5,  t731,  t2763,  8(I32)
;;								## 115
	c0    and $r0.56 = $r0.13, 255   ## bblock 10, line 116-6,  t560,  t556,  255(I32)
	c0    shru $r0.13 = $r0.13, 8   ## bblock 10, line 115-6,  t564(I24),  t556,  8(SI32)
	c0    slct $r0.35 = $b0.1, $r0.35, $r0.5   ## bblock 10, line 116-5,  t2688,  t2686,  t2687,  t614
	c0    add $r0.8 = $r0.8, $r0.20   ## bblock 10, line 116-5,  t637,  t2699,  t2700
	c0    add $r0.12 = $r0.12, $r0.56   ## bblock 10, line 116-5,  t706,  t2744,  t2745
	c0    add $r0.14 = $r0.14, $r0.3   ## bblock 10, line 116-5,  t2788,  t662,  t685
	c0    mpylu $r0.5 = $r0.52, $r0.34   ## bblock 10, line 116-6,  t2837,  t482,  t491
	c0    mpyhs $r0.34 = $r0.52, $r0.34   ## bblock 10, line 116-6,  t2838,  t482,  t491
	c0    mpylu $r0.3 = $r0.37, $r0.38   ## bblock 10, line 116-6,  t2903,  t574,  t583
	c0    mpyhs $r0.38 = $r0.37, $r0.38   ## bblock 10, line 116-6,  t2904,  t574,  t583
	c0    ldw $r0.20 = (((filter7x7 + 0) + 180) + 0)[$r0.0]   ## bblock 10, line 114-6, t505, 0(I32)
;;								## 116
	c0    and $r0.13 = $r0.13, 255   ## bblock 10, line 115-6,  t565,  t564(I24),  255(I32)
	c0    shr $r0.35 = $r0.35, 8   ## bblock 10, line 116-5,  t616,  t2688,  8(I32)
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## bblock 10, line 116-5,  t2701,  t637,  0(I32)
	c0    add $r0.14 = $r0.8, 255   ## bblock 10, line 116-5,  t2702,  t637,  255(I32)
	c0    cmplt $b0.3 = $r0.12, $r0.0   ## bblock 10, line 116-5,  t2746,  t706,  0(I32)
	c0    add $r0.22 = $r0.22, $r0.14   ## bblock 10, line 116-5,  t2789,  t2785,  t2788
;;								## 117
	c0    and $r0.38 = $r0.39, 255   ## bblock 10, line 116-6,  t445,  t441,  255(I32)
	c0    shru $r0.39 = $r0.39, 8   ## bblock 10, line 115-6,  t449(I24),  t441,  8(SI32)
	c0    and $r0.37 = $r0.11, 255   ## bblock 10, line 116-6,  t468,  t464,  255(I32)
	c0    slct $r0.14 = $b0.1, $r0.14, $r0.8   ## bblock 10, line 116-5,  t2703,  t2701,  t2702,  t637
	c0    add $r0.8 = $r0.12, 255   ## bblock 10, line 116-5,  t2747,  t706,  255(I32)
	c0    add $r0.35 = $r0.35, $r0.24   ## bblock 10, line 116-5,  t2786,  t616,  t731
	c0    add $r0.5 = $r0.5, $r0.34   ## bblock 10, line 116-6,  t492,  t2837,  t2838
	c0    mpylu $r0.24 = $r0.20, $r0.44   ## bblock 10, line 116-6,  t2852,  t505,  t514
	c0    mpyhs $r0.44 = $r0.20, $r0.44   ## bblock 10, line 116-6,  t2853,  t505,  t514
	c0    add $r0.3 = $r0.3, $r0.38   ## bblock 10, line 116-6,  t584,  t2903,  t2904
	c0    ldw $r0.52 = (((filter7x7 + 0) + 168) + 0)[$r0.0]   ## bblock 10, line 114-6, t436, 0(I32)
	c0    ldw $r0.20 = (((filter7x7 + 0) + 172) + 0)[$r0.0]   ## bblock 10, line 114-6, t459, 0(I32)
	c0    ldw $r0.34 = (((filter7x7 + 0) + 188) + 0)[$r0.0]   ## bblock 10, line 114-6, t551, 0(I32)
	c0    stw 0x58[$r0.1] = $r0.11  ## spill ## t464
;;								## 118
	c0    and $r0.39 = $r0.39, 255   ## bblock 10, line 115-6,  t450,  t449(I24),  255(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 116-5,  t639,  t2703,  8(I32)
	c0    slct $r0.8 = $b0.3, $r0.8, $r0.12   ## bblock 10, line 116-5,  t2748,  t2746,  t2747,  t706
	c0    cmplt $b0.3 = $r0.5, $r0.0   ## bblock 10, line 116-6,  t2839,  t492,  0(I32)
	c0    add $r0.12 = $r0.5, 255   ## bblock 10, line 116-6,  t2840,  t492,  255(I32)
	c0    cmplt $b0.1 = $r0.3, $r0.0   ## bblock 10, line 116-6,  t2905,  t584,  0(I32)
	c0    add $r0.11 = $r0.3, 255   ## bblock 10, line 116-6,  t2906,  t584,  255(I32)
;;								## 119
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 116-5,  t708,  t2748,  8(I32)
	c0    mpylu $r0.5 = $r0.52, $r0.38   ## bblock 10, line 116-6,  t2807,  t436,  t445
	c0    mpyhs $r0.38 = $r0.52, $r0.38   ## bblock 10, line 116-6,  t2808,  t436,  t445
	c0    mpylu $r0.44 = $r0.20, $r0.37   ## bblock 10, line 116-6,  t2822,  t459,  t468
	c0    mpyhs $r0.37 = $r0.20, $r0.37   ## bblock 10, line 116-6,  t2823,  t459,  t468
	c0    slct $r0.12 = $b0.3, $r0.12, $r0.5   ## bblock 10, line 116-6,  t2841,  t2839,  t2840,  t492
	c0    add $r0.24 = $r0.24, $r0.44   ## bblock 10, line 116-6,  t515,  t2852,  t2853
	c0    mpylu $r0.3 = $r0.34, $r0.56   ## bblock 10, line 116-6,  t2882,  t551,  t560
	c0    mpyhs $r0.56 = $r0.34, $r0.56   ## bblock 10, line 116-6,  t2883,  t551,  t560
	c0    slct $r0.11 = $b0.1, $r0.11, $r0.3   ## bblock 10, line 116-6,  t2907,  t2905,  t2906,  t584
;;								## 120
	c0    add $r0.14 = $r0.14, $r0.8   ## bblock 10, line 116-5,  t2787,  t639,  t708
	c0    shr $r0.12 = $r0.12, 8   ## bblock 10, line 116-6,  t494,  t2841,  8(I32)
	c0    cmplt $b0.1 = $r0.24, $r0.0   ## bblock 10, line 116-6,  t2854,  t515,  0(I32)
	c0    add $r0.8 = $r0.24, 255   ## bblock 10, line 116-6,  t2855,  t515,  255(I32)
	c0    shr $r0.11 = $r0.11, 8   ## bblock 10, line 116-6,  t586,  t2907,  8(I32)
;;								## 121
	c0    and $r0.14 = $r0.17, 255   ## bblock 10, line 116-6,  t537,  t533,  255(I32)
	c0    add $r0.35 = $r0.35, $r0.14   ## bblock 10, line 116-5,  t2790,  t2786,  t2787
	c0    add $r0.5 = $r0.5, $r0.38   ## bblock 10, line 116-6,  t446,  t2807,  t2808
	c0    add $r0.44 = $r0.44, $r0.37   ## bblock 10, line 116-6,  t469,  t2822,  t2823
	c0    slct $r0.8 = $b0.1, $r0.8, $r0.24   ## bblock 10, line 116-6,  t2856,  t2854,  t2855,  t515
	c0    add $r0.3 = $r0.3, $r0.56   ## bblock 10, line 116-6,  t561,  t2882,  t2883
	c0    ldw $r0.52 = ((filter7x7 + 0) + 0)[$r0.0]   ## bblock 10, line 114, t70, 0(I32)
	c0    ldw $r0.37 = (((filter7x7 + 0) + 24) + 0)[$r0.0]   ## bblock 10, line 114-6, t292, 0(I32)
	c0    ldw $r0.20 = (((filter7x7 + 0) + 4) + 0)[$r0.0]   ## bblock 10, line 114-1, t407, 0(I32)
	c0    ldw $r0.56 = (((filter7x7 + 0) + 20) + 0)[$r0.0]   ## bblock 10, line 114-5, t315, 0(I32)
	c0    ldw $r0.38 = (((filter7x7 + 0) + 36) + 0)[$r0.0]   ## bblock 10, line 114-1, t1322, 0(I32)
	c0    ldw $r0.24 = (((filter7x7 + 0) + 184) + 0)[$r0.0]   ## bblock 10, line 114-6, t528, 0(I32)
	c0    ldw $r0.34 = (((filter7x7 + 0) + 12) + 0)[$r0.0]   ## bblock 10, line 114-3, t361, 0(I32)
	c0    stw 0x5c[$r0.1] = $r0.17  ## spill ## t533
;;								## 122
	c0    add $r0.22 = $r0.22, $r0.35   ## bblock 10, line 116-5,  t2029,  t2789,  t2790
	c0    cmplt $b0.3 = $r0.5, $r0.0   ## bblock 10, line 116-6,  t2809,  t446,  0(I32)
	c0    add $r0.35 = $r0.5, 255   ## bblock 10, line 116-6,  t2810,  t446,  255(I32)
	c0    cmplt $b0.4 = $r0.44, $r0.0   ## bblock 10, line 116-6,  t2824,  t469,  0(I32)
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 116-6,  t517,  t2856,  8(I32)
	c0    cmplt $b0.1 = $r0.3, $r0.0   ## bblock 10, line 116-6,  t2884,  t561,  0(I32)
	c0    add $r0.17 = $r0.3, 255   ## bblock 10, line 116-6,  t2885,  t561,  255(I32)
;;								## 123
	c0    mpylu $r0.11 = $r0.52, $r0.42   ## bblock 10, line 115,  t2077,  t70,  t62
	c0    mpyhs $r0.52 = $r0.52, $r0.42   ## bblock 10, line 115,  t2078,  t70,  t62
	c0    mpylu $r0.41 = $r0.34, $r0.43   ## bblock 10, line 115-3,  t2122,  t361,  t375
	c0    mpyhs $r0.34 = $r0.34, $r0.43   ## bblock 10, line 115-3,  t2123,  t361,  t375
	c0    mpylu $r0.43 = $r0.56, $r0.45   ## bblock 10, line 115-5,  t2152,  t315,  t329
	c0    mpyhs $r0.56 = $r0.56, $r0.45   ## bblock 10, line 115-5,  t2153,  t315,  t329
	c0    mpylu $r0.8 = $r0.37, $r0.41   ## bblock 10, line 115-6,  t2177,  t292,  t306
	c0    mpyhs $r0.37 = $r0.37, $r0.41   ## bblock 10, line 115-6,  t2178,  t292,  t306
	c0    slct $r0.35 = $b0.3, $r0.35, $r0.5   ## bblock 10, line 116-6,  t2811,  t2809,  t2810,  t446
	c0    add $r0.3 = $r0.44, 255   ## bblock 10, line 116-6,  t2825,  t469,  255(I32)
	c0    mpylu $r0.5 = $r0.24, $r0.14   ## bblock 10, line 116-6,  t2867,  t528,  t537
	c0    mpyhs $r0.14 = $r0.24, $r0.14   ## bblock 10, line 116-6,  t2868,  t528,  t537
	c0    slct $r0.17 = $b0.1, $r0.17, $r0.3   ## bblock 10, line 116-6,  t2886,  t2884,  t2885,  t561
	c0    add $r0.22 = $r0.22, $r0.11   ## bblock 10, line 116-6,  t2908,  t2029,  t586
	c0    add $r0.12 = $r0.12, $r0.8   ## bblock 10, line 116-6,  t2911,  t494,  t517
	c0    ldw $r0.42 = 0x40[$r0.1]  ## restore ## [spec] t412
;;								## 124
	c0    shr $r0.35 = $r0.35, 8   ## bblock 10, line 116-6,  t448,  t2811,  8(I32)
	c0    slct $r0.3 = $b0.4, $r0.3, $r0.44   ## bblock 10, line 116-6,  t2826,  t2824,  t2825,  t469
	c0    shr $r0.17 = $r0.17, 8   ## bblock 10, line 116-6,  t563,  t2886,  8(I32)
	c0    add $r0.22 = $r0.22, $r0.12   ## bblock 10, line 116-6,  t2912,  t2908,  t2911
	c0    ldw $r0.12 = (((filter7x7 + 0) + 180) + 0)[$r0.0]   ## bblock 10, line 114-6, t505, 0(I32)
;;								## 125
	c0    add $r0.11 = $r0.11, $r0.52   ## bblock 10, line 115,  t63,  t2077,  t2078
	c0    shru $r0.42 = $r0.42, 8   ## bblock 10, line 115-1,  t420(I24),  t412,  8(SI32)
	c0    add $r0.41 = $r0.41, $r0.34   ## bblock 10, line 115-3,  t376,  t2122,  t2123
	c0    add $r0.43 = $r0.43, $r0.56   ## bblock 10, line 115-5,  t330,  t2152,  t2153
	c0    add $r0.8 = $r0.8, $r0.37   ## bblock 10, line 115-6,  t307,  t2177,  t2178
	c0    mpylu $r0.52 = $r0.38, $r0.49   ## bblock 10, line 115-1,  t2227,  t1322,  t1336
	c0    mpyhs $r0.38 = $r0.38, $r0.49   ## bblock 10, line 115-1,  t2228,  t1322,  t1336
	c0    shr $r0.3 = $r0.3, 8   ## bblock 10, line 116-6,  t471,  t2826,  8(I32)
	c0    add $r0.5 = $r0.5, $r0.14   ## bblock 10, line 116-6,  t538,  t2867,  t2868
	c0    add $r0.35 = $r0.35, $r0.17   ## bblock 10, line 116-6,  t2909,  t448,  t563
	c0    ldw $r0.37 = (((filter7x7 + 0) + 52) + 0)[$r0.0]   ## bblock 10, line 114-1, t1414, 0(I32)
	c0    ldw $r0.34 = (((filter7x7 + 0) + 16) + 0)[$r0.0]   ## bblock 10, line 114-4, t338, 0(I32)
	c0    ldw $r0.49 = (((filter7x7 + 0) + 40) + 0)[$r0.0]   ## bblock 10, line 114-1, t1345, 0(I32)
	c0    ldw $r0.45 = (((filter7x7 + 0) + 48) + 0)[$r0.0]   ## bblock 10, line 114-1, t1391, 0(I32)
	c0    ldw $r0.56 = (((filter7x7 + 0) + 56) + 0)[$r0.0]   ## bblock 10, line 114-2, t1108, 0(I32)
	c0    ldw $r0.17 = (((filter7x7 + 0) + 8) + 0)[$r0.0]   ## bblock 10, line 114-2, t384, 0(I32)
;;								## 126
	c0    cmplt $b0.4 = $r0.11, $r0.0   ## bblock 10, line 115,  t2079,  t63,  0(I32)
	c0    and $r0.42 = $r0.42, 255   ## bblock 10, line 115-1,  t421,  t420(I24),  255(I32)
	c0    cmplt $b0.5 = $r0.41, $r0.0   ## bblock 10, line 115-3,  t2124,  t376,  0(I32)
	c0    cmplt $b0.6 = $r0.43, $r0.0   ## bblock 10, line 115-5,  t2154,  t330,  0(I32)
	c0    cmplt $b0.3 = $r0.8, $r0.0   ## bblock 10, line 115-6,  t2179,  t307,  0(I32)
	c0    add $r0.14 = $r0.8, 255   ## bblock 10, line 115-6,  t2180,  t307,  255(I32)
	c0    cmplt $b0.1 = $r0.5, $r0.0   ## bblock 10, line 116-6,  t2869,  t538,  0(I32)
	c0    add $r0.44 = $r0.5, 255   ## bblock 10, line 116-6,  t2870,  t538,  255(I32)
;;								## 127
	c0    add $r0.5 = $r0.11, 255   ## bblock 10, line 115,  t2080,  t63,  255(I32)
	c0    add $r0.8 = $r0.41, 255   ## bblock 10, line 115-3,  t2125,  t376,  255(I32)
	c0    slct $r0.14 = $b0.3, $r0.14, $r0.8   ## bblock 10, line 115-6,  t2181,  t2179,  t2180,  t307
	c0    add $r0.52 = $r0.52, $r0.38   ## bblock 10, line 115-1,  t1337,  t2227,  t2228
	c0    mpylu $r0.38 = $r0.49, $r0.50   ## bblock 10, line 115-1,  t2242,  t1345,  t1359
	c0    mpyhs $r0.49 = $r0.49, $r0.50   ## bblock 10, line 115-1,  t2243,  t1345,  t1359
	c0    mpylu $r0.45 = $r0.45, $r0.51   ## bblock 10, line 115-1,  t2272,  t1391,  t1405
	c0    slct $r0.44 = $b0.1, $r0.44, $r0.5   ## bblock 10, line 116-6,  t2871,  t2869,  t2870,  t538
	c0    ldw $r0.51 = 0x44[$r0.1]  ## restore ## [spec] t1304
	c0    ldw $r0.50 = 0x48[$r0.1]  ## restore ## t1276
;;								## 128
	c0    slct $r0.5 = $b0.4, $r0.5, $r0.11   ## bblock 10, line 115,  t2081,  t2079,  t2080,  t63
	c0    mpylu $r0.11 = $r0.20, $r0.42   ## bblock 10, line 115-1,  t2092,  t407,  t421
	c0    mpyhs $r0.20 = $r0.20, $r0.42   ## bblock 10, line 115-1,  t2093,  t407,  t421
	c0    mpylu $r0.42 = $r0.17, $r0.46   ## bblock 10, line 115-2,  t2107,  t384,  t398
	c0    mpyhs $r0.17 = $r0.17, $r0.46   ## bblock 10, line 115-2,  t2108,  t384,  t398
	c0    slct $r0.8 = $b0.5, $r0.8, $r0.41   ## bblock 10, line 115-3,  t2126,  t2124,  t2125,  t376
	c0    mpylu $r0.46 = $r0.34, $r0.47   ## bblock 10, line 115-4,  t2137,  t338,  t352
	c0    mpyhs $r0.34 = $r0.34, $r0.47   ## bblock 10, line 115-4,  t2138,  t338,  t352
	c0    add $r0.41 = $r0.43, 255   ## bblock 10, line 115-5,  t2155,  t330,  255(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 115-6,  t308,  t2181,  8(I32)
	c0    cmplt $b0.1 = $r0.52, $r0.0   ## bblock 10, line 115-1,  t2229,  t1337,  0(I32)
	c0    add $r0.48 = $r0.52, 255   ## bblock 10, line 115-1,  t2230,  t1337,  255(I32)
	c0    mpylu $r0.47 = $r0.37, $r0.48   ## bblock 10, line 115-1,  t2299,  t1414,  t1428
	c0    mpyhs $r0.37 = $r0.37, $r0.48   ## bblock 10, line 115-1,  t2300,  t1414,  t1428
	c0    shr $r0.44 = $r0.44, 8   ## bblock 10, line 116-6,  t540,  t2871,  8(I32)
;;								## 129
	c0    shr $r0.5 = $r0.5, 8   ## bblock 10, line 115,  t199,  t2081,  8(I32)
	c0    shru $r0.51 = $r0.51, 8   ## bblock 10, line 115-1,  t1312(I24),  t1304,  8(SI32)
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 115-3,  t377,  t2126,  8(I32)
	c0    slct $r0.41 = $b0.6, $r0.41, $r0.43   ## bblock 10, line 115-5,  t2156,  t2154,  t2155,  t330
	c0    mpylu $r0.31 = $r0.50, $r0.27   ## bblock 10, line 115-1,  t2197,  t1276,  t1290
	c0    mpyhs $r0.50 = $r0.50, $r0.27   ## bblock 10, line 115-1,  t2198,  t1276,  t1290
	c0    slct $r0.48 = $b0.1, $r0.48, $r0.52   ## bblock 10, line 115-1,  t2231,  t2229,  t2230,  t1337
	c0    add $r0.38 = $r0.38, $r0.49   ## bblock 10, line 115-1,  t1360,  t2242,  t2243
	c0    add $r0.45 = $r0.45, $r0.31   ## bblock 10, line 115-1,  t1406,  t2272,  t2273
	c0    add $r0.3 = $r0.3, $r0.44   ## bblock 10, line 116-6,  t2910,  t471,  t540
	c0    ldw $r0.52 = (((filter7x7 + 0) + 80) + 0)[$r0.0]   ## bblock 10, line 114-2, t1246, 0(I32)
	c0    ldw $r0.49 = (((filter7x7 + 0) + 44) + 0)[$r0.0]   ## bblock 10, line 114-1, t1368, 0(I32)
	c0    ldw $r0.44 = (((filter7x7 + 0) + 32) + 0)[$r0.0]   ## bblock 10, line 114-1, t1299, 0(I32)
	c0    ldw $r0.43 = (((filter7x7 + 0) + 164) + 0)[$r0.0]   ## bblock 10, line 114-5, t742, 0(I32)
	c0    ldw $r0.27 = (((filter7x7 + 0) + 192) + 0)[$r0.0]   ## bblock 10, line 114-6, t574, 0(I32)
;;								## 130
	c0    add $r0.11 = $r0.11, $r0.20   ## bblock 10, line 115-1,  t422,  t2092,  t2093
	c0    and $r0.51 = $r0.51, 255   ## bblock 10, line 115-1,  t1313,  t1312(I24),  255(I32)
	c0    add $r0.42 = $r0.42, $r0.17   ## bblock 10, line 115-2,  t399,  t2107,  t2108
	c0    add $r0.46 = $r0.46, $r0.34   ## bblock 10, line 115-4,  t353,  t2137,  t2138
	c0    shr $r0.41 = $r0.41, 8   ## bblock 10, line 115-5,  t331,  t2156,  8(I32)
	c0    add $r0.5 = $r0.5, $r0.14   ## bblock 10, line 115-6,  t2182,  t199,  t308
	c0    shr $r0.48 = $r0.48, 8   ## bblock 10, line 115-1,  t1338,  t2231,  8(I32)
	c0    cmplt $b0.1 = $r0.38, $r0.0   ## bblock 10, line 115-1,  t2244,  t1360,  0(I32)
	c0    add $r0.3 = $r0.38, 255   ## bblock 10, line 115-1,  t2245,  t1360,  255(I32)
	c0    cmplt $b0.3 = $r0.45, $r0.0   ## bblock 10, line 115-1,  t2274,  t1406,  0(I32)
	c0    add $r0.14 = $r0.45, 255   ## bblock 10, line 115-1,  t2275,  t1406,  255(I32)
	c0    add $r0.47 = $r0.47, $r0.37   ## bblock 10, line 115-1,  t1429,  t2299,  t2300
	c0    mpylu $r0.37 = $r0.56, $r0.26   ## bblock 10, line 115-2,  t2320,  t1108,  t1122
	c0    mpyhs $r0.56 = $r0.56, $r0.26   ## bblock 10, line 115-2,  t2321,  t1108,  t1122
	c0    add $r0.34 = $r0.6, 255   ## bblock 10, line 115-2,  t2398,  t1238,  255(I32)
	c0    add $r0.35 = $r0.35, $r0.3   ## bblock 10, line 116-6,  t2913,  t2909,  t2910
	c0    ldw $r0.17 = (((filter7x7 + 0) + 64) + 0)[$r0.0]   ## bblock 10, line 114-2, t1154, 0(I32)
	c0    ldw $r0.20 = (((filter7x7 + 0) + 68) + 0)[$r0.0]   ## bblock 10, line 114-2, t1177, 0(I32)
	c0    ldw $r0.26 = (((filter7x7 + 0) + 60) + 0)[$r0.0]   ## bblock 10, line 114-2, t1131, 0(I32)
;;								## 131
	c0    cmplt $b0.4 = $r0.11, $r0.0   ## bblock 10, line 115-1,  t2094,  t422,  0(I32)
	c0    add $r0.8 = $r0.11, 255   ## bblock 10, line 115-1,  t2095,  t422,  255(I32)
	c0    cmplt $b0.5 = $r0.42, $r0.0   ## bblock 10, line 115-2,  t2109,  t399,  0(I32)
	c0    add $r0.35 = $r0.42, 255   ## bblock 10, line 115-2,  t2110,  t399,  255(I32)
	c0    cmplt $b0.6 = $r0.46, $r0.0   ## bblock 10, line 115-4,  t2139,  t353,  0(I32)
	c0    add $r0.5 = $r0.5, $r0.8   ## bblock 10, line 115-6,  t2185,  t2182,  t377
	c0    add $r0.31 = $r0.31, $r0.50   ## bblock 10, line 115-1,  t1291,  t2197,  t2198
	c0    mpylu $r0.38 = $r0.44, $r0.51   ## bblock 10, line 115-1,  t2212,  t1299,  t1313
	c0    mpyhs $r0.44 = $r0.44, $r0.51   ## bblock 10, line 115-1,  t2213,  t1299,  t1313
	c0    slct $r0.3 = $b0.1, $r0.3, $r0.38   ## bblock 10, line 115-1,  t2246,  t2244,  t2245,  t1360
	c0    mpylu $r0.45 = $r0.49, $r0.19   ## bblock 10, line 115-1,  t2257,  t1368,  t1382
	c0    mpyhs $r0.49 = $r0.49, $r0.19   ## bblock 10, line 115-1,  t2258,  t1368,  t1382
	c0    slct $r0.14 = $b0.3, $r0.14, $r0.45   ## bblock 10, line 115-1,  t2276,  t2274,  t2275,  t1406
	c0    cmplt $b0.7 = $r0.47, $r0.0   ## bblock 10, line 115-1,  t2301,  t1429,  0(I32)
	c0    add $r0.50 = $r0.18, 255   ## bblock 10, line 115-2,  t2383,  t1215,  255(I32)
	c0    slct $r0.34 = $b0.0, $r0.34, $r0.6   ## bblock 10, line 115-2,  t2399,  t2397,  t2398,  t1238
	c0    mpylu $r0.19 = $r0.52, $r0.53   ## bblock 10, line 115-2,  t2422,  t1246,  t1260
	c0    mpyhs $r0.52 = $r0.52, $r0.53   ## bblock 10, line 115-2,  t2423,  t1246,  t1260
	c0    add $r0.22 = $r0.22, $r0.35   ## bblock 10, line 116-6,  t428,  t2912,  t2913
	c0    ldw $r0.6 = (((filter7x7 + 0) + 116) + 0)[$r0.0]   ## bblock 10, line 114-4, t795, 0(I32)
	c0    ldw $r0.51 = (((filter7x7 + 0) + 108) + 0)[$r0.0]   ## bblock 10, line 114-3, t1078, 0(I32)
	c0    ldw $r0.53 = (((filter7x7 + 0) + 148) + 0)[$r0.0]   ## bblock 10, line 114-5, t650, 0(I32)
;;								## 132
	c0    slct $r0.8 = $b0.4, $r0.8, $r0.11   ## bblock 10, line 115-1,  t2096,  t2094,  t2095,  t422
	c0    slct $r0.35 = $b0.5, $r0.35, $r0.42   ## bblock 10, line 115-2,  t2111,  t2109,  t2110,  t399
	c0    add $r0.11 = $r0.46, 255   ## bblock 10, line 115-4,  t2140,  t353,  255(I32)
	c0    cmplt $b0.0 = $r0.31, $r0.0   ## bblock 10, line 115-1,  t2199,  t1291,  0(I32)
	c0    shr $r0.3 = $r0.3, 8   ## bblock 10, line 115-1,  t1361,  t2246,  8(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 115-1,  t1407,  t2276,  8(I32)
	c0    add $r0.42 = $r0.47, 255   ## bblock 10, line 115-1,  t2302,  t1429,  255(I32)
	c0    add $r0.37 = $r0.37, $r0.56   ## bblock 10, line 115-2,  t1123,  t2320,  t2321
	c0    mpylu $r0.56 = $r0.26, $r0.58   ## bblock 10, line 115-2,  t2335,  t1131,  t1145
	c0    mpyhs $r0.26 = $r0.26, $r0.58   ## bblock 10, line 115-2,  t2336,  t1131,  t1145
	c0    slct $r0.50 = $b0.2, $r0.50, $r0.18   ## bblock 10, line 115-2,  t2384,  t2382,  t2383,  t1215
	c0    shr $r0.34 = $r0.34, 8   ## bblock 10, line 115-2,  t1239,  t2399,  8(I32)
	c0    max $r0.22 = $r0.22, $r0.0   ## bblock 10, line 160,  t173,  t428,  0(SI32)
	c0    ldw $r0.58 = (((filter7x7 + 0) + 96) + 0)[$r0.0]   ## bblock 10, line 114-3, t1009, 0(I32)
	c0    ldw $r0.18 = (((filter7x7 + 0) + 92) + 0)[$r0.0]   ## bblock 10, line 114-3, t986, 0(I32)
;;								## 133
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 115-1,  t423,  t2096,  8(I32)
	c0    shr $r0.35 = $r0.35, 8   ## bblock 10, line 115-2,  t400,  t2111,  8(I32)
	c0    slct $r0.11 = $b0.6, $r0.11, $r0.46   ## bblock 10, line 115-4,  t2141,  t2139,  t2140,  t353
	c0    add $r0.3 = $r0.31, 255   ## bblock 10, line 115-1,  t2200,  t1291,  255(I32)
	c0    add $r0.38 = $r0.38, $r0.44   ## bblock 10, line 115-1,  t1314,  t2212,  t2213
	c0    add $r0.45 = $r0.45, $r0.49   ## bblock 10, line 115-1,  t1383,  t2257,  t2258
	c0    slct $r0.42 = $b0.7, $r0.42, $r0.47   ## bblock 10, line 115-1,  t2303,  t2301,  t2302,  t1429
	c0    add $r0.48 = $r0.48, $r0.3   ## bblock 10, line 115-1,  t2307,  t1338,  t1361
	c0    cmplt $b0.1 = $r0.37, $r0.0   ## bblock 10, line 115-2,  t2322,  t1123,  0(I32)
	c0    add $r0.47 = $r0.37, 255   ## bblock 10, line 115-2,  t2323,  t1123,  255(I32)
	c0    mpylu $r0.44 = $r0.17, $r0.54   ## bblock 10, line 115-2,  t2350,  t1154,  t1168
	c0    mpyhs $r0.17 = $r0.17, $r0.54   ## bblock 10, line 115-2,  t2351,  t1154,  t1168
	c0    mpylu $r0.46 = $r0.20, $r0.55   ## bblock 10, line 115-2,  t2365,  t1177,  t1191
	c0    mpyhs $r0.20 = $r0.20, $r0.55   ## bblock 10, line 115-2,  t2366,  t1177,  t1191
	c0    shr $r0.50 = $r0.50, 8   ## bblock 10, line 115-2,  t1216,  t2384,  8(I32)
	c0    add $r0.19 = $r0.19, $r0.52   ## bblock 10, line 115-2,  t1261,  t2422,  t2423
	c0    mpylu $r0.49 = $r0.51, $r0.59   ## bblock 10, line 115-3,  t2545,  t1078,  t1092
	c0    mpyhs $r0.51 = $r0.51, $r0.59   ## bblock 10, line 115-3,  t2546,  t1078,  t1092
	c0    min $r0.22 = $r0.22, 255   ## bblock 10, line 160,  t83,  t173,  255(SI32)
	c0    ldw $r0.59 = (((filter7x7 + 0) + 84) + 0)[$r0.0]   ## bblock 10, line 114-3, t940, 0(I32)
	c0    ldw $r0.54 = (((filter7x7 + 0) + 104) + 0)[$r0.0]   ## bblock 10, line 114-3, t1055, 0(I32)
	c0    ldw $r0.52 = (((filter7x7 + 0) + 128) + 0)[$r0.0]   ## bblock 10, line 114-4, t864, 0(I32)
	c0    ldw $r0.55 = (((filter7x7 + 0) + 100) + 0)[$r0.0]   ## bblock 10, line 114-3, t1032, 0(I32)
;;								## 134
	c0    shr $r0.11 = $r0.11, 8   ## bblock 10, line 115-4,  t354,  t2141,  8(I32)
	c0    add $r0.8 = $r0.8, $r0.41   ## bblock 10, line 115-6,  t2183,  t423,  t331
	c0    slct $r0.3 = $b0.0, $r0.3, $r0.31   ## bblock 10, line 115-1,  t2201,  t2199,  t2200,  t1291
	c0    cmplt $b0.0 = $r0.38, $r0.0   ## bblock 10, line 115-1,  t2214,  t1314,  0(I32)
	c0    add $r0.23 = $r0.38, 255   ## bblock 10, line 115-1,  t2215,  t1314,  255(I32)
	c0    cmplt $b0.2 = $r0.45, $r0.0   ## bblock 10, line 115-1,  t2259,  t1383,  0(I32)
	c0    add $r0.31 = $r0.45, 255   ## bblock 10, line 115-1,  t2260,  t1383,  255(I32)
	c0    shr $r0.42 = $r0.42, 8   ## bblock 10, line 115-1,  t1430,  t2303,  8(I32)
	c0    slct $r0.47 = $b0.1, $r0.47, $r0.37   ## bblock 10, line 115-2,  t2324,  t2322,  t2323,  t1123
	c0    add $r0.56 = $r0.56, $r0.26   ## bblock 10, line 115-2,  t1146,  t2335,  t2336
	c0    cmplt $b0.3 = $r0.19, $r0.0   ## bblock 10, line 115-2,  t2424,  t1261,  0(I32)
	c0    add $r0.41 = $r0.19, 255   ## bblock 10, line 115-2,  t2425,  t1261,  255(I32)
	c0    mpylu $r0.37 = $r0.18, $r0.60   ## bblock 10, line 115-3,  t2473,  t986,  t1000
	c0    mpyhs $r0.18 = $r0.18, $r0.60   ## bblock 10, line 115-3,  t2474,  t986,  t1000
	c0    mpylu $r0.60 = $r0.58, $r0.62   ## bblock 10, line 115-3,  t2488,  t1009,  t1023
	c0    mpyhs $r0.58 = $r0.58, $r0.62   ## bblock 10, line 115-3,  t2489,  t1009,  t1023
	c0    or $r0.22 = $r0.22, $r0.23   ## bblock 10, line 160,  t2925,  t83,  t93
	c0    ldw $r0.26 = 0x4c[$r0.1]  ## restore ## t1037
	c0    ldw $r0.62 = (((filter7x7 + 0) + 88) + 0)[$r0.0]   ## bblock 10, line 114-3, t963, 0(I32)
;;								## 135
	c0    add $r0.35 = $r0.35, $r0.11   ## bblock 10, line 115-6,  t2184,  t400,  t354
	c0    shr $r0.3 = $r0.3, 8   ## bblock 10, line 115-1,  t1292,  t2201,  8(I32)
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.38   ## bblock 10, line 115-1,  t2216,  t2214,  t2215,  t1314
	c0    slct $r0.31 = $b0.2, $r0.31, $r0.45   ## bblock 10, line 115-1,  t2261,  t2259,  t2260,  t1383
	c0    shr $r0.47 = $r0.47, 8   ## bblock 10, line 115-2,  t1124,  t2324,  8(I32)
	c0    cmplt $b0.0 = $r0.56, $r0.0   ## bblock 10, line 115-2,  t2337,  t1146,  0(I32)
	c0    add $r0.11 = $r0.56, 255   ## bblock 10, line 115-2,  t2338,  t1146,  255(I32)
	c0    add $r0.44 = $r0.44, $r0.17   ## bblock 10, line 115-2,  t1169,  t2350,  t2351
	c0    add $r0.46 = $r0.46, $r0.20   ## bblock 10, line 115-2,  t1192,  t2365,  t2366
	c0    slct $r0.41 = $b0.3, $r0.41, $r0.19   ## bblock 10, line 115-2,  t2426,  t2424,  t2425,  t1261
	c0    mpylu $r0.7 = $r0.59, $r0.10   ## bblock 10, line 115-3,  t2443,  t940,  t954
	c0    mpyhs $r0.59 = $r0.59, $r0.10   ## bblock 10, line 115-3,  t2444,  t940,  t954
	c0    mpylu $r0.17 = $r0.54, $r0.7   ## bblock 10, line 115-3,  t2518,  t1055,  t1069
	c0    mpyhs $r0.54 = $r0.54, $r0.7   ## bblock 10, line 115-3,  t2519,  t1055,  t1069
	c0    add $r0.49 = $r0.49, $r0.51   ## bblock 10, line 115-3,  t1093,  t2545,  t2546
	c0    mpylu $r0.51 = $r0.21, $r0.36   ## bblock 10, line 115-4,  t2566,  t772,  t786
	c0    mpyhs $r0.21 = $r0.21, $r0.36   ## bblock 10, line 115-4,  t2567,  t772,  t786
	c0    mpylu $r0.36 = $r0.6, $r0.57   ## bblock 10, line 115-4,  t2581,  t795,  t809
	c0    mpyhs $r0.6 = $r0.6, $r0.57   ## bblock 10, line 115-4,  t2582,  t795,  t809
	c0    mpylu $r0.57 = $r0.52, $r0.40   ## bblock 10, line 115-4,  t2626,  t864,  t878
	c0    mpyhs $r0.52 = $r0.52, $r0.40   ## bblock 10, line 115-4,  t2627,  t864,  t878
	c0    mpylu $r0.40 = $r0.43, $r0.4   ## bblock 10, line 115-5,  t2791,  t742,  t756
	c0    ldw $r0.38 = (((filter7x7 + 0) + 120) + 0)[$r0.0]   ## bblock 10, line 114-4, t818, 0(I32)
	c0    ldw $r0.20 = (((filter7x7 + 0) + 136) + 0)[$r0.0]   ## bblock 10, line 114-4, t910, 0(I32)
	c0    ldw $r0.45 = (((filter7x7 + 0) + 124) + 0)[$r0.0]   ## bblock 10, line 114-4, t841, 0(I32)
	c0    ldw $r0.19 = (((filter7x7 + 0) + 132) + 0)[$r0.0]   ## bblock 10, line 114-4, t887, 0(I32)
	c0    ldw $r0.10 = (((filter7x7 + 0) + 188) + 0)[$r0.0]   ## bblock 10, line 114-6, t551, 0(I32)
;;								## 136
	c0    shru $r0.26 = $r0.26, 8   ## bblock 10, line 115-3,  t1045(I24),  t1037,  8(SI32)
	c0    add $r0.8 = $r0.8, $r0.35   ## bblock 10, line 115-6,  t2186,  t2183,  t2184
	c0    shr $r0.23 = $r0.23, 8   ## bblock 10, line 115-1,  t1315,  t2216,  8(I32)
	c0    shr $r0.31 = $r0.31, 8   ## bblock 10, line 115-1,  t1384,  t2261,  8(I32)
	c0    add $r0.3 = $r0.3, $r0.14   ## bblock 10, line 115-1,  t2305,  t1292,  t1407
	c0    slct $r0.11 = $b0.0, $r0.11, $r0.56   ## bblock 10, line 115-2,  t2339,  t2337,  t2338,  t1146
	c0    cmplt $b0.1 = $r0.44, $r0.0   ## bblock 10, line 115-2,  t2352,  t1169,  0(I32)
	c0    add $r0.14 = $r0.44, 255   ## bblock 10, line 115-2,  t2353,  t1169,  255(I32)
	c0    cmplt $b0.2 = $r0.46, $r0.0   ## bblock 10, line 115-2,  t2367,  t1192,  0(I32)
	c0    add $r0.35 = $r0.46, 255   ## bblock 10, line 115-2,  t2368,  t1192,  255(I32)
	c0    shr $r0.41 = $r0.41, 8   ## bblock 10, line 115-2,  t1262,  t2426,  8(I32)
	c0    add $r0.47 = $r0.47, $r0.34   ## bblock 10, line 115-2,  t2428,  t1124,  t1239
	c0    mpylu $r0.18 = $r0.62, $r0.61   ## bblock 10, line 115-3,  t2458,  t963,  t977
	c0    mpyhs $r0.62 = $r0.62, $r0.61   ## bblock 10, line 115-3,  t2459,  t963,  t977
	c0    add $r0.37 = $r0.37, $r0.18   ## bblock 10, line 115-3,  t1001,  t2473,  t2474
	c0    add $r0.60 = $r0.60, $r0.58   ## bblock 10, line 115-3,  t1024,  t2488,  t2489
	c0    cmplt $b0.0 = $r0.49, $r0.0   ## bblock 10, line 115-3,  t2547,  t1093,  0(I32)
	c0    add $r0.34 = $r0.49, 255   ## bblock 10, line 115-3,  t2548,  t1093,  255(I32)
	c0    mpylu $r0.56 = $r0.53, $r0.30   ## bblock 10, line 115-5,  t2719,  t650,  t664
	c0    mpyhs $r0.53 = $r0.53, $r0.30   ## bblock 10, line 115-5,  t2720,  t650,  t664
	c0    mpyhs $r0.43 = $r0.43, $r0.4   ## bblock 10, line 115-5,  t2792,  t742,  t756
	c0    ldw $r0.61 = 0x50[$r0.1]  ## restore ## t609
	c0    ldw $r0.4 = (((filter7x7 + 0) + 140) + 0)[$r0.0]   ## bblock 10, line 114-5, t604, 0(I32)
	c0    ldw $r0.30 = (((filter7x7 + 0) + 152) + 0)[$r0.0]   ## bblock 10, line 114-5, t673, 0(I32)
	c0    ldw $r0.58 = (((filter7x7 + 0) + 160) + 0)[$r0.0]   ## bblock 10, line 114-5, t719, 0(I32)
;;								## 137
	c0    and $r0.26 = $r0.26, 255   ## bblock 10, line 115-3,  t1046,  t1045(I24),  255(I32)
	c0    add $r0.5 = $r0.5, $r0.8   ## bblock 10, line 115-6,  t2010,  t2185,  t2186
	c0    add $r0.23 = $r0.23, $r0.31   ## bblock 10, line 115-1,  t2306,  t1315,  t1384
	c0    shr $r0.11 = $r0.11, 8   ## bblock 10, line 115-2,  t1147,  t2339,  8(I32)
	c0    slct $r0.14 = $b0.1, $r0.14, $r0.44   ## bblock 10, line 115-2,  t2354,  t2352,  t2353,  t1169
	c0    slct $r0.35 = $b0.2, $r0.35, $r0.46   ## bblock 10, line 115-2,  t2369,  t2367,  t2368,  t1192
	c0    add $r0.7 = $r0.7, $r0.59   ## bblock 10, line 115-3,  t955,  t2443,  t2444
	c0    cmplt $b0.0 = $r0.37, $r0.0   ## bblock 10, line 115-3,  t2475,  t1001,  0(I32)
	c0    add $r0.8 = $r0.37, 255   ## bblock 10, line 115-3,  t2476,  t1001,  255(I32)
	c0    cmplt $b0.1 = $r0.60, $r0.0   ## bblock 10, line 115-3,  t2490,  t1024,  0(I32)
	c0    add $r0.31 = $r0.60, 255   ## bblock 10, line 115-3,  t2491,  t1024,  255(I32)
	c0    add $r0.17 = $r0.17, $r0.54   ## bblock 10, line 115-3,  t1070,  t2518,  t2519
	c0    slct $r0.34 = $b0.0, $r0.34, $r0.49   ## bblock 10, line 115-3,  t2549,  t2547,  t2548,  t1093
	c0    add $r0.51 = $r0.51, $r0.21   ## bblock 10, line 115-4,  t787,  t2566,  t2567
	c0    add $r0.36 = $r0.36, $r0.6   ## bblock 10, line 115-4,  t810,  t2581,  t2582
	c0    mpylu $r0.33 = $r0.38, $r0.16   ## bblock 10, line 115-4,  t2596,  t818,  t832
	c0    mpyhs $r0.38 = $r0.38, $r0.16   ## bblock 10, line 115-4,  t2597,  t818,  t832
	c0    mpylu $r0.16 = $r0.45, $r0.2   ## bblock 10, line 115-4,  t2611,  t841,  t855
	c0    mpyhs $r0.45 = $r0.45, $r0.2   ## bblock 10, line 115-4,  t2612,  t841,  t855
	c0    add $r0.57 = $r0.57, $r0.52   ## bblock 10, line 115-4,  t879,  t2626,  t2627
	c0    mpylu $r0.46 = $r0.19, $r0.25   ## bblock 10, line 115-4,  t2641,  t887,  t901
	c0    mpyhs $r0.19 = $r0.19, $r0.25   ## bblock 10, line 115-4,  t2642,  t887,  t901
	c0    mpylu $r0.44 = $r0.20, $r0.33   ## bblock 10, line 115-4,  t2668,  t910,  t924
	c0    mpyhs $r0.20 = $r0.20, $r0.33   ## bblock 10, line 115-4,  t2669,  t910,  t924
	c0    mpylu $r0.59 = $r0.12, $r0.9   ## bblock 10, line 115-6,  t2857,  t505,  t519
	c0    ldw $r0.52 = 0x54[$r0.1]  ## restore ## t579
	c0    ldw $r0.21 = (((filter7x7 + 0) + 144) + 0)[$r0.0]   ## bblock 10, line 114-5, t627, 0(I32)
	c0    ldw $r0.54 = (((filter7x7 + 0) + 168) + 0)[$r0.0]   ## bblock 10, line 114-6, t436, 0(I32)
	c0    ldw $r0.49 = (((filter7x7 + 0) + 156) + 0)[$r0.0]   ## bblock 10, line 114-5, t696, 0(I32)
;;								## 138
	c0    shru $r0.61 = $r0.61, 8   ## bblock 10, line 115-5,  t617(I24),  t609,  8(SI32)
	c0    add $r0.5 = $r0.5, $r0.42   ## bblock 10, line 115-1,  t2304,  t2010,  t1430
	c0    add $r0.3 = $r0.3, $r0.23   ## bblock 10, line 115-1,  t2309,  t2305,  t2306
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 115-2,  t1170,  t2354,  8(I32)
	c0    shr $r0.35 = $r0.35, 8   ## bblock 10, line 115-2,  t1193,  t2369,  8(I32)
	c0    add $r0.11 = $r0.11, $r0.50   ## bblock 10, line 115-2,  t2429,  t1147,  t1216
	c0    cmplt $b0.1 = $r0.7, $r0.0   ## bblock 10, line 115-3,  t2445,  t955,  0(I32)
	c0    add $r0.37 = $r0.7, 255   ## bblock 10, line 115-3,  t2446,  t955,  255(I32)
	c0    add $r0.18 = $r0.18, $r0.62   ## bblock 10, line 115-3,  t978,  t2458,  t2459
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.37   ## bblock 10, line 115-3,  t2477,  t2475,  t2476,  t1001
	c0    slct $r0.31 = $b0.1, $r0.31, $r0.60   ## bblock 10, line 115-3,  t2492,  t2490,  t2491,  t1024
	c0    mpylu $r0.42 = $r0.55, $r0.26   ## bblock 10, line 115-3,  t2503,  t1032,  t1046
	c0    mpyhs $r0.55 = $r0.55, $r0.26   ## bblock 10, line 115-3,  t2504,  t1032,  t1046
	c0    cmplt $b0.0 = $r0.17, $r0.0   ## bblock 10, line 115-3,  t2520,  t1070,  0(I32)
	c0    add $r0.23 = $r0.17, 255   ## bblock 10, line 115-3,  t2521,  t1070,  255(I32)
	c0    shr $r0.34 = $r0.34, 8   ## bblock 10, line 115-3,  t1094,  t2549,  8(I32)
	c0    cmplt $b0.2 = $r0.51, $r0.0   ## bblock 10, line 115-4,  t2568,  t787,  0(I32)
	c0    add $r0.50 = $r0.51, 255   ## bblock 10, line 115-4,  t2569,  t787,  255(I32)
	c0    cmplt $b0.3 = $r0.36, $r0.0   ## bblock 10, line 115-4,  t2583,  t810,  0(I32)
	c0    add $r0.60 = $r0.36, 255   ## bblock 10, line 115-4,  t2584,  t810,  255(I32)
	c0    cmplt $b0.4 = $r0.57, $r0.0   ## bblock 10, line 115-4,  t2628,  t879,  0(I32)
	c0    add $r0.62 = $r0.57, 255   ## bblock 10, line 115-4,  t2629,  t879,  255(I32)
	c0    add $r0.56 = $r0.56, $r0.53   ## bblock 10, line 115-5,  t665,  t2719,  t2720
	c0    mpylu $r0.43 = $r0.30, $r0.32   ## bblock 10, line 115-5,  t2734,  t673,  t687
	c0    mpyhs $r0.30 = $r0.30, $r0.32   ## bblock 10, line 115-5,  t2735,  t673,  t687
	c0    mpylu $r0.32 = $r0.58, $r0.63   ## bblock 10, line 115-5,  t2764,  t719,  t733
	c0    mpyhs $r0.58 = $r0.58, $r0.63   ## bblock 10, line 115-5,  t2765,  t719,  t733
	c0    add $r0.40 = $r0.40, $r0.43   ## bblock 10, line 115-5,  t757,  t2791,  t2792
	c0    mpyhs $r0.12 = $r0.12, $r0.9   ## bblock 10, line 115-6,  t2858,  t505,  t519
	c0    mpylu $r0.9 = $r0.10, $r0.13   ## bblock 10, line 115-6,  t2887,  t551,  t565
	c0    ldw $r0.53 = (((filter7x7 + 0) + 176) + 0)[$r0.0]   ## bblock 10, line 114-6, t482, 0(I32)
;;								## 139
	c0    and $r0.61 = $r0.61, 255   ## bblock 10, line 115-5,  t618,  t617(I24),  255(I32)
	c0    shru $r0.52 = $r0.52, 8   ## bblock 10, line 115-6,  t587(I24),  t579,  8(SI32)
	c0    add $r0.5 = $r0.5, $r0.48   ## bblock 10, line 115-1,  t2308,  t2304,  t2307
	c0    add $r0.14 = $r0.14, $r0.35   ## bblock 10, line 115-2,  t2430,  t1170,  t1193
	c0    add $r0.47 = $r0.47, $r0.11   ## bblock 10, line 115-2,  t2432,  t2428,  t2429
	c0    slct $r0.37 = $b0.1, $r0.37, $r0.7   ## bblock 10, line 115-3,  t2447,  t2445,  t2446,  t955
	c0    cmplt $b0.0 = $r0.18, $r0.0   ## bblock 10, line 115-3,  t2460,  t978,  0(I32)
	c0    add $r0.7 = $r0.18, 255   ## bblock 10, line 115-3,  t2461,  t978,  255(I32)
	c0    shr $r0.8 = $r0.8, 8   ## bblock 10, line 115-3,  t1002,  t2477,  8(I32)
	c0    shr $r0.31 = $r0.31, 8   ## bblock 10, line 115-3,  t1025,  t2492,  8(I32)
	c0    slct $r0.23 = $b0.0, $r0.23, $r0.17   ## bblock 10, line 115-3,  t2522,  t2520,  t2521,  t1070
	c0    slct $r0.50 = $b0.2, $r0.50, $r0.51   ## bblock 10, line 115-4,  t2570,  t2568,  t2569,  t787
	c0    slct $r0.60 = $b0.3, $r0.60, $r0.36   ## bblock 10, line 115-4,  t2585,  t2583,  t2584,  t810
	c0    add $r0.33 = $r0.33, $r0.38   ## bblock 10, line 115-4,  t833,  t2596,  t2597
	c0    add $r0.16 = $r0.16, $r0.45   ## bblock 10, line 115-4,  t856,  t2611,  t2612
	c0    slct $r0.62 = $b0.4, $r0.62, $r0.57   ## bblock 10, line 115-4,  t2630,  t2628,  t2629,  t879
	c0    add $r0.46 = $r0.46, $r0.19   ## bblock 10, line 115-4,  t902,  t2641,  t2642
	c0    add $r0.44 = $r0.44, $r0.20   ## bblock 10, line 115-4,  t925,  t2668,  t2669
	c0    mpylu $r0.19 = $r0.21, $r0.29   ## bblock 10, line 115-5,  t2704,  t627,  t641
	c0    mpyhs $r0.21 = $r0.21, $r0.29   ## bblock 10, line 115-5,  t2705,  t627,  t641
	c0    cmplt $b0.2 = $r0.56, $r0.0   ## bblock 10, line 115-5,  t2721,  t665,  0(I32)
	c0    add $r0.17 = $r0.56, 255   ## bblock 10, line 115-5,  t2722,  t665,  255(I32)
	c0    mpylu $r0.20 = $r0.49, $r0.28   ## bblock 10, line 115-5,  t2749,  t696,  t710
	c0    mpyhs $r0.49 = $r0.49, $r0.28   ## bblock 10, line 115-5,  t2750,  t696,  t710
	c0    cmplt $b0.1 = $r0.40, $r0.0   ## bblock 10, line 115-5,  t2793,  t757,  0(I32)
	c0    add $r0.11 = $r0.40, 255   ## bblock 10, line 115-5,  t2794,  t757,  255(I32)
	c0    mpylu $r0.13 = $r0.54, $r0.39   ## bblock 10, line 115-6,  t2812,  t436,  t450
	c0    mpyhs $r0.54 = $r0.54, $r0.39   ## bblock 10, line 115-6,  t2813,  t436,  t450
	c0    mpyhs $r0.10 = $r0.10, $r0.13   ## bblock 10, line 115-6,  t2888,  t551,  t565
	c0    ldw $r0.28 = 0x58[$r0.1]  ## restore ## t464
	c0    ldw $r0.29 = (((filter7x7 + 0) + 172) + 0)[$r0.0]   ## bblock 10, line 114-6, t459, 0(I32)
;;								## 140
	c0    and $r0.52 = $r0.52, 255   ## bblock 10, line 115-6,  t588,  t587(I24),  255(I32)
	c0    add $r0.5 = $r0.5, $r0.3   ## bblock 10, line 115-1,  t2014,  t2308,  t2309
	c0    shr $r0.37 = $r0.37, 8   ## bblock 10, line 115-3,  t956,  t2447,  8(I32)
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.18   ## bblock 10, line 115-3,  t2462,  t2460,  t2461,  t978
	c0    add $r0.42 = $r0.42, $r0.55   ## bblock 10, line 115-3,  t1047,  t2503,  t2504
	c0    shr $r0.23 = $r0.23, 8   ## bblock 10, line 115-3,  t1071,  t2522,  8(I32)
	c0    add $r0.8 = $r0.8, $r0.31   ## bblock 10, line 115-3,  t2553,  t1002,  t1025
	c0    shr $r0.50 = $r0.50, 8   ## bblock 10, line 115-4,  t788,  t2570,  8(I32)
	c0    shr $r0.60 = $r0.60, 8   ## bblock 10, line 115-4,  t811,  t2585,  8(I32)
	c0    cmplt $b0.3 = $r0.33, $r0.0   ## bblock 10, line 115-4,  t2598,  t833,  0(I32)
	c0    add $r0.18 = $r0.33, 255   ## bblock 10, line 115-4,  t2599,  t833,  255(I32)
	c0    cmplt $b0.4 = $r0.16, $r0.0   ## bblock 10, line 115-4,  t2613,  t856,  0(I32)
	c0    add $r0.31 = $r0.16, 255   ## bblock 10, line 115-4,  t2614,  t856,  255(I32)
	c0    shr $r0.62 = $r0.62, 8   ## bblock 10, line 115-4,  t880,  t2630,  8(I32)
	c0    cmplt $b0.5 = $r0.46, $r0.0   ## bblock 10, line 115-4,  t2643,  t902,  0(I32)
	c0    add $r0.35 = $r0.46, 255   ## bblock 10, line 115-4,  t2644,  t902,  255(I32)
	c0    cmplt $b0.0 = $r0.44, $r0.0   ## bblock 10, line 115-4,  t2670,  t925,  0(I32)
	c0    add $r0.3 = $r0.44, 255   ## bblock 10, line 115-4,  t2671,  t925,  255(I32)
	c0    mpylu $r0.30 = $r0.4, $r0.61   ## bblock 10, line 115-5,  t2689,  t604,  t618
	c0    mpyhs $r0.4 = $r0.4, $r0.61   ## bblock 10, line 115-5,  t2690,  t604,  t618
	c0    slct $r0.17 = $b0.2, $r0.17, $r0.56   ## bblock 10, line 115-5,  t2723,  t2721,  t2722,  t665
	c0    add $r0.43 = $r0.43, $r0.30   ## bblock 10, line 115-5,  t688,  t2734,  t2735
	c0    add $r0.32 = $r0.32, $r0.58   ## bblock 10, line 115-5,  t734,  t2764,  t2765
	c0    slct $r0.11 = $b0.1, $r0.11, $r0.40   ## bblock 10, line 115-5,  t2795,  t2793,  t2794,  t757
	c0    mpylu $r0.36 = $r0.53, $r0.15   ## bblock 10, line 115-6,  t2842,  t482,  t496
	c0    mpyhs $r0.53 = $r0.53, $r0.15   ## bblock 10, line 115-6,  t2843,  t482,  t496
	c0    add $r0.59 = $r0.59, $r0.12   ## bblock 10, line 115-6,  t520,  t2857,  t2858
	c0    ldw $r0.2 = 0x14[$r0.1]  ## restore ## t1468
	c0    ldw $r0.25 = 0x18[$r0.1]  ## restore ## t1443
	c0    ldw $r0.26 = 0x1c[$r0.1]  ## restore ## t1473
	c0    ldw $r0.6 = 0x3c[$r0.1]  ## restore ## t1469
	c0    ldw $r0.12 = 0x5c[$r0.1]  ## restore ## t533
;;								## 141
	c0    shru $r0.28 = $r0.28, 8   ## bblock 10, line 115-6,  t472(I24),  t464,  8(SI32)
	c0    add $r0.5 = $r0.5, $r0.41   ## bblock 10, line 115-2,  t2427,  t2014,  t1262
	c0    shr $r0.7 = $r0.7, 8   ## bblock 10, line 115-3,  t979,  t2462,  8(I32)
	c0    cmplt $b0.1 = $r0.42, $r0.0   ## bblock 10, line 115-3,  t2505,  t1047,  0(I32)
	c0    add $r0.15 = $r0.42, 255   ## bblock 10, line 115-3,  t2506,  t1047,  255(I32)
	c0    add $r0.37 = $r0.37, $r0.23   ## bblock 10, line 115-3,  t2551,  t956,  t1071
	c0    slct $r0.18 = $b0.3, $r0.18, $r0.33   ## bblock 10, line 115-4,  t2600,  t2598,  t2599,  t833
	c0    slct $r0.31 = $b0.4, $r0.31, $r0.16   ## bblock 10, line 115-4,  t2615,  t2613,  t2614,  t856
	c0    slct $r0.35 = $b0.5, $r0.35, $r0.46   ## bblock 10, line 115-4,  t2645,  t2643,  t2644,  t902
	c0    slct $r0.3 = $b0.0, $r0.3, $r0.44   ## bblock 10, line 115-4,  t2672,  t2670,  t2671,  t925
	c0    add $r0.60 = $r0.60, $r0.62   ## bblock 10, line 115-4,  t2675,  t811,  t880
	c0    add $r0.19 = $r0.19, $r0.21   ## bblock 10, line 115-5,  t642,  t2704,  t2705
	c0    shr $r0.17 = $r0.17, 8   ## bblock 10, line 115-5,  t666,  t2723,  8(I32)
	c0    cmplt $b0.0 = $r0.43, $r0.0   ## bblock 10, line 115-5,  t2736,  t688,  0(I32)
	c0    add $r0.16 = $r0.43, 255   ## bblock 10, line 115-5,  t2737,  t688,  255(I32)
	c0    add $r0.20 = $r0.20, $r0.49   ## bblock 10, line 115-5,  t711,  t2749,  t2750
	c0    cmplt $b0.2 = $r0.32, $r0.0   ## bblock 10, line 115-5,  t2766,  t734,  0(I32)
	c0    add $r0.23 = $r0.32, 255   ## bblock 10, line 115-5,  t2767,  t734,  255(I32)
	c0    shr $r0.11 = $r0.11, 8   ## bblock 10, line 115-5,  t758,  t2795,  8(I32)
	c0    add $r0.13 = $r0.13, $r0.54   ## bblock 10, line 115-6,  t451,  t2812,  t2813
	c0    cmplt $b0.3 = $r0.59, $r0.0   ## bblock 10, line 115-6,  t2859,  t520,  0(I32)
	c0    add $r0.33 = $r0.59, 255   ## bblock 10, line 115-6,  t2860,  t520,  255(I32)
	c0    add $r0.9 = $r0.9, $r0.10   ## bblock 10, line 115-6,  t566,  t2887,  t2888
	c0    mpylu $r0.21 = $r0.27, $r0.52   ## bblock 10, line 115-6,  t2914,  t574,  t588
	c0    mpyhs $r0.27 = $r0.27, $r0.52   ## bblock 10, line 115-6,  t2915,  t574,  t588
;;								## 142
	c0    and $r0.28 = $r0.28, 255   ## bblock 10, line 115-6,  t473,  t472(I24),  255(I32)
	c0    shru $r0.12 = $r0.12, 8   ## bblock 10, line 115-6,  t541(I24),  t533,  8(SI32)
	c0    add $r0.5 = $r0.5, $r0.14   ## bblock 10, line 115-2,  t2431,  t2427,  t2430
	c0    slct $r0.15 = $b0.1, $r0.15, $r0.42   ## bblock 10, line 115-3,  t2507,  t2505,  t2506,  t1047
	c0    shr $r0.18 = $r0.18, 8   ## bblock 10, line 115-4,  t834,  t2600,  8(I32)
	c0    shr $r0.31 = $r0.31, 8   ## bblock 10, line 115-4,  t857,  t2615,  8(I32)
	c0    shr $r0.35 = $r0.35, 8   ## bblock 10, line 115-4,  t903,  t2645,  8(I32)
	c0    shr $r0.3 = $r0.3, 8   ## bblock 10, line 115-4,  t926,  t2672,  8(I32)
	c0    add $r0.30 = $r0.30, $r0.4   ## bblock 10, line 115-5,  t619,  t2689,  t2690
	c0    cmplt $b0.0 = $r0.19, $r0.0   ## bblock 10, line 115-5,  t2706,  t642,  0(I32)
	c0    add $r0.10 = $r0.19, 255   ## bblock 10, line 115-5,  t2707,  t642,  255(I32)
	c0    slct $r0.16 = $b0.0, $r0.16, $r0.43   ## bblock 10, line 115-5,  t2738,  t2736,  t2737,  t688
	c0    cmplt $b0.1 = $r0.20, $r0.0   ## bblock 10, line 115-5,  t2751,  t711,  0(I32)
	c0    add $r0.14 = $r0.20, 255   ## bblock 10, line 115-5,  t2752,  t711,  255(I32)
	c0    slct $r0.23 = $b0.2, $r0.23, $r0.32   ## bblock 10, line 115-5,  t2768,  t2766,  t2767,  t734
	c0    cmplt $b0.3 = $r0.13, $r0.0   ## bblock 10, line 115-6,  t2814,  t451,  0(I32)
	c0    add $r0.38 = $r0.13, 255   ## bblock 10, line 115-6,  t2815,  t451,  255(I32)
	c0    add $r0.36 = $r0.36, $r0.53   ## bblock 10, line 115-6,  t497,  t2842,  t2843
	c0    slct $r0.33 = $b0.3, $r0.33, $r0.59   ## bblock 10, line 115-6,  t2861,  t2859,  t2860,  t520
	c0    cmplt $b0.2 = $r0.9, $r0.0   ## bblock 10, line 115-6,  t2889,  t566,  0(I32)
	c0    add $r0.32 = $r0.9, 255   ## bblock 10, line 115-6,  t2890,  t566,  255(I32)
	c0    sh2add $r0.39 = $r0.25, $r0.26   ## bblock 10, line 158,  t2926,  t1443,  t1473
	c0    add $r0.25 = $r0.25, 1   ## bblock 10, line 0,  t1443,  t1443,  1(I32)
;;								## 143
	c0    and $r0.12 = $r0.12, 255   ## bblock 10, line 115-6,  t542,  t541(I24),  255(I32)
	c0    add $r0.5 = $r0.5, $r0.47   ## bblock 10, line 115-2,  t2018,  t2431,  t2432
	c0    shr $r0.15 = $r0.15, 8   ## bblock 10, line 115-3,  t1048,  t2507,  8(I32)
	c0    add $r0.50 = $r0.50, $r0.35   ## bblock 10, line 115-4,  t2674,  t788,  t903
	c0    add $r0.18 = $r0.18, $r0.31   ## bblock 10, line 115-4,  t2676,  t834,  t857
	c0    cmplt $b0.4 = $r0.30, $r0.0   ## bblock 10, line 115-5,  t2691,  t619,  0(I32)
	c0    add $r0.31 = $r0.30, 255   ## bblock 10, line 115-5,  t2692,  t619,  255(I32)
	c0    slct $r0.10 = $b0.0, $r0.10, $r0.19   ## bblock 10, line 115-5,  t2708,  t2706,  t2707,  t642
	c0    shr $r0.16 = $r0.16, 8   ## bblock 10, line 115-5,  t689,  t2738,  8(I32)
	c0    slct $r0.14 = $b0.1, $r0.14, $r0.20   ## bblock 10, line 115-5,  t2753,  t2751,  t2752,  t711
	c0    shr $r0.23 = $r0.23, 8   ## bblock 10, line 115-5,  t735,  t2768,  8(I32)
	c0    slct $r0.38 = $b0.3, $r0.38, $r0.13   ## bblock 10, line 115-6,  t2816,  t2814,  t2815,  t451
	c0    mpylu $r0.9 = $r0.29, $r0.28   ## bblock 10, line 115-6,  t2827,  t459,  t473
	c0    mpyhs $r0.29 = $r0.29, $r0.28   ## bblock 10, line 115-6,  t2828,  t459,  t473
	c0    cmplt $b0.0 = $r0.36, $r0.0   ## bblock 10, line 115-6,  t2844,  t497,  0(I32)
	c0    add $r0.19 = $r0.36, 255   ## bblock 10, line 115-6,  t2845,  t497,  255(I32)
	c0    shr $r0.33 = $r0.33, 8   ## bblock 10, line 115-6,  t521,  t2861,  8(I32)
	c0    slct $r0.32 = $b0.2, $r0.32, $r0.9   ## bblock 10, line 115-6,  t2891,  t2889,  t2890,  t566
	c0    add $r0.21 = $r0.21, $r0.27   ## bblock 10, line 115-6,  t589,  t2914,  t2915
	c0    pft 32[$r0.39]   ## bblock 10, line 158,  t2926,  32(I32)
;;								## 144
	c0    add $r0.5 = $r0.5, $r0.34   ## bblock 10, line 115-3,  t2550,  t2018,  t1094
	c0    add $r0.7 = $r0.7, $r0.15   ## bblock 10, line 115-3,  t2552,  t979,  t1048
	c0    add $r0.50 = $r0.50, $r0.60   ## bblock 10, line 115-4,  t2678,  t2674,  t2675
	c0    slct $r0.31 = $b0.4, $r0.31, $r0.30   ## bblock 10, line 115-5,  t2693,  t2691,  t2692,  t619
	c0    shr $r0.10 = $r0.10, 8   ## bblock 10, line 115-5,  t643,  t2708,  8(I32)
	c0    shr $r0.14 = $r0.14, 8   ## bblock 10, line 115-5,  t712,  t2753,  8(I32)
	c0    add $r0.17 = $r0.17, $r0.16   ## bblock 10, line 115-5,  t2799,  t666,  t689
	c0    shr $r0.38 = $r0.38, 8   ## bblock 10, line 115-6,  t452,  t2816,  8(I32)
	c0    slct $r0.19 = $b0.0, $r0.19, $r0.36   ## bblock 10, line 115-6,  t2846,  t2844,  t2845,  t497
	c0    mpylu $r0.15 = $r0.24, $r0.12   ## bblock 10, line 115-6,  t2872,  t528,  t542
	c0    mpyhs $r0.24 = $r0.24, $r0.12   ## bblock 10, line 115-6,  t2873,  t528,  t542
	c0    shr $r0.32 = $r0.32, 8   ## bblock 10, line 115-6,  t567,  t2891,  8(I32)
	c0    cmplt $b0.1 = $r0.21, $r0.0   ## bblock 10, line 115-6,  t2916,  t589,  0(I32)
	c0    add $r0.13 = $r0.21, 255   ## bblock 10, line 115-6,  t2917,  t589,  255(I32)
;;								## 145
	c0    add $r0.5 = $r0.5, $r0.8   ## bblock 10, line 115-3,  t2554,  t2550,  t2553
	c0    add $r0.37 = $r0.37, $r0.7   ## bblock 10, line 115-3,  t2555,  t2551,  t2552
	c0    shr $r0.31 = $r0.31, 8   ## bblock 10, line 115-5,  t620,  t2693,  8(I32)
	c0    add $r0.10 = $r0.10, $r0.14   ## bblock 10, line 115-5,  t2798,  t643,  t712
	c0    add $r0.9 = $r0.9, $r0.29   ## bblock 10, line 115-6,  t474,  t2827,  t2828
	c0    shr $r0.19 = $r0.19, 8   ## bblock 10, line 115-6,  t498,  t2846,  8(I32)
	c0    slct $r0.13 = $b0.1, $r0.13, $r0.21   ## bblock 10, line 115-6,  t2918,  t2916,  t2917,  t589
	c0    add $r0.38 = $r0.38, $r0.32   ## bblock 10, line 115-6,  t2920,  t452,  t567
;;								## 146
	c0    add $r0.5 = $r0.5, $r0.37   ## bblock 10, line 115-3,  t2022,  t2554,  t2555
	c0    add $r0.31 = $r0.31, $r0.23   ## bblock 10, line 115-5,  t2797,  t620,  t735
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 10, line 115-6,  t2829,  t474,  0(I32)
	c0    add $r0.7 = $r0.9, 255   ## bblock 10, line 115-6,  t2830,  t474,  255(I32)
	c0    add $r0.15 = $r0.15, $r0.24   ## bblock 10, line 115-6,  t543,  t2872,  t2873
	c0    shr $r0.13 = $r0.13, 8   ## bblock 10, line 115-6,  t590,  t2918,  8(I32)
	c0    add $r0.19 = $r0.19, $r0.33   ## bblock 10, line 115-6,  t2922,  t498,  t521
;;								## 147
	c0    add $r0.5 = $r0.5, $r0.3   ## bblock 10, line 115-4,  t2673,  t2022,  t926
	c0    add $r0.31 = $r0.31, $r0.10   ## bblock 10, line 115-5,  t2801,  t2797,  t2798
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.9   ## bblock 10, line 115-6,  t2831,  t2829,  t2830,  t474
	c0    cmplt $b0.0 = $r0.15, $r0.0   ## bblock 10, line 115-6,  t2874,  t543,  0(I32)
	c0    add $r0.3 = $r0.15, 255   ## bblock 10, line 115-6,  t2875,  t543,  255(I32)
;;								## 148
	c0    add $r0.5 = $r0.5, $r0.18   ## bblock 10, line 115-4,  t2677,  t2673,  t2676
	c0    shr $r0.7 = $r0.7, 8   ## bblock 10, line 115-6,  t475,  t2831,  8(I32)
	c0    slct $r0.3 = $b0.0, $r0.3, $r0.15   ## bblock 10, line 115-6,  t2876,  t2874,  t2875,  t543
;;								## 149
	c0    add $r0.5 = $r0.5, $r0.50   ## bblock 10, line 115-4,  t2026,  t2677,  t2678
	c0    shr $r0.3 = $r0.3, 8   ## bblock 10, line 115-6,  t544,  t2876,  8(I32)
;;								## 150
	c0    add $r0.5 = $r0.5, $r0.11   ## bblock 10, line 115-5,  t2796,  t2026,  t758
	c0    add $r0.7 = $r0.7, $r0.3   ## bblock 10, line 115-6,  t2921,  t475,  t544
;;								## 151
	c0    add $r0.5 = $r0.5, $r0.17   ## bblock 10, line 115-5,  t2800,  t2796,  t2799
	c0    add $r0.38 = $r0.38, $r0.7   ## bblock 10, line 115-6,  t2924,  t2920,  t2921
;;								## 152
	c0    add $r0.5 = $r0.5, $r0.31   ## bblock 10, line 115-5,  t2030,  t2800,  t2801
;;								## 153
	c0    add $r0.5 = $r0.5, $r0.13   ## bblock 10, line 115-6,  t2919,  t2030,  t590
;;								## 154
	c0    add $r0.5 = $r0.5, $r0.19   ## bblock 10, line 115-6,  t2923,  t2919,  t2922
;;								## 155
	c0    add $r0.5 = $r0.5, $r0.38   ## bblock 10, line 115-6,  t429,  t2923,  t2924
;;								## 156
	c0    max $r0.5 = $r0.5, $r0.0   ## bblock 10, line 159,  t179,  t429,  0(SI32)
;;								## 157
	c0    min $r0.5 = $r0.5, 255   ## bblock 10, line 159,  t86,  t179,  255(SI32)
;;								## 158
	c0    shl $r0.5 = $r0.5, 8   ## bblock 10, line 160,  t89,  t86,  8(SI32)
;;								## 159
	c0    or $r0.22 = $r0.22, $r0.5   ## bblock 10, line 160,  t94,  t2925,  t89
;;								## 160
	c0    stw 0[$r0.39] = $r0.22   ## bblock 10, line 158, t2926, t94
;;								## 161
	c0    ldw $r0.4 = 0x38[$r0.1]  ## restore ## t1442
;;								## 162
	c0    goto L6?3 ## goto
;;								## 163
.trace 5
L7?3:
	c0    add $r0.2 = $r0.2, 1   ## bblock 9, line 0,  t1468,  t1468,  1(I32)
	c0    add $r0.6 = $r0.6, 64   ## bblock 9, line 0,  t1469,  t1469,  64(I32)
	c0    add $r0.26 = $r0.26, 256   ## bblock 9, line 0,  t1473,  t1473,  256(I32)
;;								## 0
	c0    stw 0x3c[$r0.1] = $r0.6  ## spill ## t1469
	c0    stw 0x1c[$r0.1] = $r0.26  ## spill ## t1473
	c0    stw 0x14[$r0.1] = $r0.2  ## spill ## t1468
	c0    goto L4?3 ## goto
;;								## 1
.trace 9
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 168,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $r0.63 = 0x78[$r0.1]  ## restore ## t138
	c0    ldw $r0.62 = 0x74[$r0.1]  ## restore ## t137
	c0    ldw $r0.61 = 0x70[$r0.1]  ## restore ## t136
	c0    ldw $r0.60 = 0x6c[$r0.1]  ## restore ## t135
	c0    ldw $r0.59 = 0x68[$r0.1]  ## restore ## t134
	c0    ldw $r0.58 = 0x64[$r0.1]  ## restore ## t133
	c0    ldw $r0.57 = 0x60[$r0.1]  ## restore ## t132
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t128
	      xnop 1
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x80), $l0.0   ## bblock 6, line 170,  t129,  ?2.4?2auto_size(I32),  t128
;;								## 3
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
.equ ?2.4?2auto_size, 0x80
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
