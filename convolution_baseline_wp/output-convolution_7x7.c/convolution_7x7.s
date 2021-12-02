 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -mas_g -mas_G -O4 -o a.out"
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
;;								## 0
	c0    cmpgt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 19,  t19(I1),  t17,  t18
;;								## 1
	c0    brf $b0.0, L0?3   ## bblock 0, line 19,  t19(I1)
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 19,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 3
.trace 2
L0?3:
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 20,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 1
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
;;								## 0
	c0    cmplt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 25,  t19(I1),  t17,  t18
;;								## 1
	c0    brf $b0.0, L1?3   ## bblock 0, line 25,  t19(I1)
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 25,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 3
.trace 2
L1?3:
	c0    mov $r0.3 = $r0.4   ## t18
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 26,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 1
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
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 46,  t1,  ?2.3?2auto_size(I32),  t0
;;								## 2
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
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t128
;;								## 1
	c0    mov $r0.3 = (conv7_result + 0)   ## bblock 1, line 0,  t646,  addr(conv7_result?1.0)(P32)
;;								## 2
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t647,  (~0xfff)(I32)
;;								## 3
	c0    ldw $r0.4 = 0x10[$r0.1]  ## restore ## t128
;;								## 4
;;								## 5
.trace 7
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 89,  t759(I1),  t647,  0(SI32)
	c0    add $r0.2 = $r0.2, 8   ## [spec] bblock 35, line 0,  t647,  t647,  8(I32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 89,  t759(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 35, line 90, t646, 0(SI32)
;;								## 2
	c0    stw 4[$r0.3] = $r0.0   ## bblock 35, line 90-1, t646, 0(SI32)
;;								## 3
	c0    stw 8[$r0.3] = $r0.0   ## bblock 35, line 90-2, t646, 0(SI32)
;;								## 4
	c0    stw 12[$r0.3] = $r0.0   ## bblock 35, line 90-3, t646, 0(SI32)
;;								## 5
	c0    stw 16[$r0.3] = $r0.0   ## bblock 35, line 90-4, t646, 0(SI32)
;;								## 6
	c0    stw 20[$r0.3] = $r0.0   ## bblock 35, line 90-5, t646, 0(SI32)
;;								## 7
	c0    stw 24[$r0.3] = $r0.0   ## bblock 35, line 90-6, t646, 0(SI32)
;;								## 8
	c0    stw 28[$r0.3] = $r0.0   ## bblock 35, line 90-7, t646, 0(SI32)
	c0    add $r0.3 = $r0.3, 32   ## bblock 35, line 0,  t646,  t646,  32(I32)
	      ## goto
;;
	c0    goto L2?3 ## goto
;;								## 9
.trace 12
L3?3:
	c0    mov $r0.3 = (~0x39)   ## bblock 3, line 0,  t575,  (~0x39)(I32)
	c0    mov $r0.13 = $r0.0   ## bblock 3, line 0,  t571,  0(I32)
;;								## 0
	c0    mov $r0.29 = ((conv7_result + 0) + 780)   ## bblock 3, line 0,  t574,  (addr(conv7_result?1.0)(P32) + 0x30c(I32))(P32)
;;								## 1
	c0    mov $r0.31 = $r0.4   ## t128
;;								## 2
.trace 8
L4?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 4, line 98,  t760(I1),  t575,  0(SI32)
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 7, line 0,  t533,  0(I32)
;;								## 0
	c0    mov $r0.2 = (~0x39)   ## [spec] bblock 7, line 0,  t536,  (~0x39)(I32)
	c0    brf $b0.0, L5?3   ## bblock 4, line 98,  t760(I1)
;;								## 1
	c0    mov $r0.30 = $r0.3   ## t575
;;								## 2
.trace 5
L6?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 8, line 100,  t761(I1),  t536,  0(SI32)
	c0    mov $r0.12 = $r0.4   ## [spec] bblock 10, line 0,  t489,  t533
;;								## 0
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 10, line 102,  t153,  0(SI32)
	c0    brf $b0.0, L7?3   ## bblock 8, line 100,  t761(I1)
;;								## 1
	c0    mov $r0.15 = (filter7x7 + 0)   ## bblock 10, line 0,  t487,  addr(filter7x7?1.0)(P32)
;;								## 2
	c0    mov $r0.5 = $r0.0   ## bblock 10, line 102,  t152,  0(SI32)
	c0    mov $r0.9 = $r0.0   ## bblock 10, line 102,  t151,  0(SI32)
;;								## 3
	c0    mov $r0.3 = (~0x6)   ## bblock 10, line 0,  t490,  (~0x6)(I32)
	c0    mov $r0.27 = $r0.2   ## t536
;;								## 4
	c0    mov $r0.28 = $r0.4   ## t533
;;								## 5
.trace 3
L8?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 11, line 107,  t762(I1),  t490,  0(SI32)
	c0    add $r0.14 = $r0.12, $r0.13   ## [spec] bblock 31, line 0,  t355,  t489,  t571
;;								## 0
	c0    mov $r0.11 = (~0x3)   ## [spec] bblock 31, line 0,  t313,  (~0x3)(I32)
	c0    brf $b0.0, L9?3   ## bblock 11, line 107,  t762(I1)
;;								## 1
	c0    add $r0.14 = $r0.14, (conv7_image + 0)   ## bblock 31, line 0,  t323,  t355,  addr(conv7_image?1.0)(P32)
;;								## 2
	c0    mov $r0.2 = $r0.14   ## bblock 31, line 0,  t311,  t323
	c0    mov $r0.8 = $r0.0   ## bblock 31, line 110,  t203,  0(SI32)
;;								## 3
	c0    mov $r0.10 = $r0.0   ## bblock 31, line 110,  t189,  0(SI32)
	c0    mov $r0.7 = $r0.0   ## bblock 31, line 110,  t204,  0(SI32)
;;								## 4
	c0    mov $r0.4 = $r0.15   ## bblock 31, line 0,  t312,  t487
	c0    mov $r0.23 = $r0.3   ## t490
;;								## 5
	c0    mov $r0.24 = $r0.12   ## t489
	c0    mov $r0.25 = $r0.13   ## t571
;;								## 6
	c0    mov $r0.26 = $r0.15   ## t487
;;								## 7
.trace 1
L10?3:
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 32, line 117, t227, t311
	c0    cmplt $b0.0 = $r0.11, $r0.0   ## bblock 32, line 110-3,  t813(I1),  t313,  0(SI32)
;;								## 0
	c0    ldw $r0.12 = 0[$r0.4]   ## bblock 32, line 117, t224, t312
	c0    add $r0.11 = $r0.11, 4   ## [spec] bblock 41, line 0,  t313,  t313,  4(I32)
;;								## 1
	c0    ldw $r0.14 = 8[$r0.4]   ## bblock 32, line 117-2, t245, t312
	c0    shru $r0.13 = $r0.3, 8   ## bblock 32, line 118,  t235(I24),  t227,  8(SI32)
;;								## 2
	c0    shru $r0.15 = $r0.3, 16   ## bblock 32, line 117,  t228(I16),  t227,  16(SI32)
	c0    and $r0.13 = $r0.13, 255   ## bblock 32, line 118,  t236,  t235(I24),  255(I32)
;;								## 3
	c0    and $r0.15 = $r0.15, 255   ## bblock 32, line 117,  t229,  t228(I16),  255(I32)
	c0    mpylu $r0.16 = $r0.12, $r0.13   ## bblock 32, line 118,  t775,  t224,  t236
;;								## 4
	c0    mpyhs $r0.13 = $r0.12, $r0.13   ## bblock 32, line 118,  t776,  t224,  t236
	c0    ldw $r0.17 = 4[$r0.4]   ## bblock 32, line 117-1, t264, t312
;;								## 5
	c0    ldw $r0.18 = 512[$r0.2]   ## bblock 32, line 117-2, t78, t311
;;								## 6
	c0    mpylu $r0.13 = $r0.12, $r0.15   ## bblock 32, line 117,  t765,  t224,  t229
	c0    add $r0.16 = $r0.16, $r0.13   ## bblock 32, line 118,  t237,  t775,  t776
;;								## 7
	c0    cmplt $b0.1 = $r0.16, $r0.0   ## bblock 32, line 118,  t777,  t237,  0(I32)
	c0    add $r0.19 = $r0.16, 255   ## bblock 32, line 118,  t778,  t237,  255(I32)
;;								## 8
	c0    slct $r0.19 = $b0.1, $r0.19, $r0.16   ## bblock 32, line 118,  t779,  t777,  t778,  t237
	c0    shru $r0.16 = $r0.18, 8   ## bblock 32, line 118-2,  t61(I24),  t78,  8(SI32)
;;								## 9
	c0    shr $r0.19 = $r0.19, 8   ## bblock 32, line 118,  t238,  t779,  8(I32)
	c0    and $r0.16 = $r0.16, 255   ## bblock 32, line 118-2,  t62,  t61(I24),  255(I32)
;;								## 10
	c0    shru $r0.21 = $r0.18, 16   ## bblock 32, line 117-2,  t43(I16),  t78,  16(SI32)
	c0    mpylu $r0.20 = $r0.14, $r0.16   ## bblock 32, line 118-2,  t805,  t245,  t62
;;								## 11
	c0    and $r0.21 = $r0.21, 255   ## bblock 32, line 117-2,  t44,  t43(I16),  255(I32)
	c0    mpyhs $r0.16 = $r0.14, $r0.16   ## bblock 32, line 118-2,  t806,  t245,  t62
;;								## 12
	c0    mpyhs $r0.15 = $r0.12, $r0.15   ## bblock 32, line 117,  t766,  t224,  t229
	c0    and $r0.3 = $r0.3, 255   ## bblock 32, line 119,  t231,  t227,  255(I32)
;;								## 13
	c0    mpylu $r0.16 = $r0.14, $r0.21   ## bblock 32, line 117-2,  t795,  t245,  t44
	c0    add $r0.20 = $r0.20, $r0.16   ## bblock 32, line 118-2,  t63,  t805,  t806
;;								## 14
	c0    cmplt $b0.1 = $r0.20, $r0.0   ## bblock 32, line 118-2,  t807,  t63,  0(I32)
	c0    add $r0.22 = $r0.20, 255   ## bblock 32, line 118-2,  t808,  t63,  255(I32)
;;								## 15
	c0    add $r0.13 = $r0.13, $r0.15   ## bblock 32, line 117,  t230,  t765,  t766
	c0    slct $r0.22 = $b0.1, $r0.22, $r0.20   ## bblock 32, line 118-2,  t809,  t807,  t808,  t63
;;								## 16
	c0    cmplt $b0.1 = $r0.13, $r0.0   ## bblock 32, line 117,  t769,  t230,  0(I32)
	c0    shr $r0.22 = $r0.22, 8   ## bblock 32, line 118-2,  t64,  t809,  8(I32)
;;								## 17
	c0    add $r0.15 = $r0.13, 255   ## bblock 32, line 117,  t770,  t230,  255(I32)
	c0    add $r0.19 = $r0.19, $r0.22   ## bblock 32, line 118-2,  t810,  t238,  t64
;;								## 18
	c0    slct $r0.15 = $b0.1, $r0.15, $r0.13   ## bblock 32, line 117,  t771,  t769,  t770,  t230
	c0    add $r0.5 = $r0.19, $r0.5   ## bblock 32, line 118-2,  t152,  t810,  t152
;;								## 19
	c0    shr $r0.15 = $r0.15, 8   ## bblock 32, line 117,  t233,  t771,  8(I32)
	c0    mpyhs $r0.21 = $r0.14, $r0.21   ## bblock 32, line 117-2,  t796,  t245,  t44
;;								## 20
	c0    ldw $r0.13 = 256[$r0.2]   ## bblock 32, line 117-1, t269, t311
;;								## 21
	c0    mpylu $r0.19 = $r0.12, $r0.3   ## bblock 32, line 119,  t767,  t224,  t231
	c0    add $r0.16 = $r0.16, $r0.21   ## bblock 32, line 117-2,  t45,  t795,  t796
;;								## 22
	c0    cmplt $b0.1 = $r0.16, $r0.0   ## bblock 32, line 117-2,  t797,  t45,  0(I32)
	c0    add $r0.20 = $r0.16, 255   ## bblock 32, line 117-2,  t798,  t45,  255(I32)
;;								## 23
	c0    shru $r0.16 = $r0.13, 8   ## bblock 32, line 118-1,  t277(I24),  t269,  8(SI32)
	c0    slct $r0.20 = $b0.1, $r0.20, $r0.16   ## bblock 32, line 117-2,  t799,  t797,  t798,  t45
;;								## 24
	c0    and $r0.16 = $r0.16, 255   ## bblock 32, line 118-1,  t278,  t277(I24),  255(I32)
	c0    shr $r0.20 = $r0.20, 8   ## bblock 32, line 117-2,  t46,  t799,  8(I32)
;;								## 25
	c0    mpylu $r0.20 = $r0.17, $r0.16   ## bblock 32, line 118-1,  t790,  t264,  t278
	c0    add $r0.15 = $r0.15, $r0.20   ## bblock 32, line 117-2,  t812,  t233,  t46
;;								## 26
	c0    mpyhs $r0.16 = $r0.17, $r0.16   ## bblock 32, line 118-1,  t791,  t264,  t278
	c0    add $r0.6 = $r0.15, $r0.6   ## bblock 32, line 117-2,  t153,  t812,  t153
;;								## 27
	c0    mpyhs $r0.12 = $r0.12, $r0.3   ## bblock 32, line 119,  t768,  t224,  t231
	c0    shru $r0.15 = $r0.13, 16   ## bblock 32, line 117-1,  t270(I16),  t269,  16(SI32)
;;								## 28
	c0    and $r0.15 = $r0.15, 255   ## bblock 32, line 117-1,  t271,  t270(I16),  255(I32)
	c0    add $r0.20 = $r0.20, $r0.16   ## bblock 32, line 118-1,  t279,  t790,  t791
;;								## 29
	c0    cmplt $b0.1 = $r0.20, $r0.0   ## bblock 32, line 118-1,  t792,  t279,  0(I32)
	c0    add $r0.3 = $r0.20, 255   ## bblock 32, line 118-1,  t793,  t279,  255(I32)
;;								## 30
	c0    mpylu $r0.16 = $r0.17, $r0.15   ## bblock 32, line 117-1,  t780,  t264,  t271
	c0    slct $r0.3 = $b0.1, $r0.3, $r0.20   ## bblock 32, line 118-1,  t794,  t792,  t793,  t279
;;								## 31
	c0    mpyhs $r0.15 = $r0.17, $r0.15   ## bblock 32, line 117-1,  t781,  t264,  t271
	c0    shr $r0.3 = $r0.3, 8   ## bblock 32, line 118-1,  t280,  t794,  8(I32)
;;								## 32
	c0    add $r0.19 = $r0.19, $r0.12   ## bblock 32, line 119,  t232,  t767,  t768
	c0    add $r0.20 = $r0.3, $r0.7   ## bblock 32, line 118-1,  t282,  t280,  t204
;;								## 33
	c0    cmplt $b0.1 = $r0.19, $r0.0   ## bblock 32, line 119,  t772,  t232,  0(I32)
	c0    add $r0.16 = $r0.16, $r0.15   ## bblock 32, line 117-1,  t272,  t780,  t781
;;								## 34
	c0    cmplt $b0.2 = $r0.16, $r0.0   ## bblock 32, line 117-1,  t782,  t272,  0(I32)
	c0    add $r0.12 = $r0.16, 255   ## bblock 32, line 117-1,  t783,  t272,  255(I32)
;;								## 35
	c0    add $r0.15 = $r0.19, 255   ## bblock 32, line 119,  t773,  t232,  255(I32)
	c0    slct $r0.12 = $b0.2, $r0.12, $r0.16   ## bblock 32, line 117-1,  t784,  t782,  t783,  t272
;;								## 36
	c0    slct $r0.15 = $b0.1, $r0.15, $r0.19   ## bblock 32, line 119,  t774,  t772,  t773,  t232
	c0    shr $r0.12 = $r0.12, 8   ## bblock 32, line 117-1,  t275,  t784,  8(I32)
;;								## 37
	c0    shr $r0.15 = $r0.15, 8   ## bblock 32, line 119,  t234,  t774,  8(I32)
	c0    add $r0.16 = $r0.12, $r0.8   ## bblock 32, line 117-1,  t283,  t275,  t203
;;								## 38
	c0    and $r0.13 = $r0.13, 255   ## bblock 32, line 119-1,  t273,  t269,  255(I32)
	c0    and $r0.18 = $r0.18, 255   ## bblock 32, line 119-2,  t79,  t78,  255(I32)
;;								## 39
	c0    mpylu $r0.19 = $r0.14, $r0.18   ## bblock 32, line 119-2,  t800,  t245,  t79
	c0    ldw.d $r0.21 = 12[$r0.4]   ## [spec] bblock 41, line 117-3, t70, t312
;;								## 40
	c0    mpyhs $r0.14 = $r0.14, $r0.18   ## bblock 32, line 119-2,  t801,  t245,  t79
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 41, line 0,  t312,  t312,  16(I32)
;;								## 41
	c0    mpylu $r0.18 = $r0.17, $r0.13   ## bblock 32, line 119-1,  t785,  t264,  t273
;;								## 42
	c0    mpyhs $r0.17 = $r0.17, $r0.13   ## bblock 32, line 119-1,  t786,  t264,  t273
	c0    add $r0.19 = $r0.19, $r0.14   ## bblock 32, line 119-2,  t80,  t800,  t801
;;								## 43
	c0    cmplt $b0.1 = $r0.19, $r0.0   ## bblock 32, line 119-2,  t802,  t80,  0(I32)
	c0    add $r0.13 = $r0.19, 255   ## bblock 32, line 119-2,  t803,  t80,  255(I32)
;;								## 44
	c0    add $r0.18 = $r0.18, $r0.17   ## bblock 32, line 119-1,  t274,  t785,  t786
	c0    slct $r0.13 = $b0.1, $r0.13, $r0.19   ## bblock 32, line 119-2,  t804,  t802,  t803,  t80
;;								## 45
	c0    cmplt $b0.1 = $r0.18, $r0.0   ## bblock 32, line 119-1,  t787,  t274,  0(I32)
	c0    shr $r0.13 = $r0.13, 8   ## bblock 32, line 119-2,  t81,  t804,  8(I32)
;;								## 46
	c0    add $r0.13 = $r0.18, 255   ## bblock 32, line 119-1,  t788,  t274,  255(I32)
	c0    add $r0.15 = $r0.15, $r0.13   ## bblock 32, line 119-2,  t811,  t234,  t81
;;								## 47
	c0    slct $r0.13 = $b0.1, $r0.13, $r0.18   ## bblock 32, line 119-1,  t789,  t787,  t788,  t274
	c0    add $r0.9 = $r0.15, $r0.9   ## bblock 32, line 119-2,  t151,  t811,  t151
;;								## 48
	c0    shr $r0.13 = $r0.13, 8   ## bblock 32, line 119-1,  t276,  t789,  8(I32)
;;								## 49
	c0    add $r0.14 = $r0.13, $r0.10   ## bblock 32, line 119-1,  t281,  t276,  t189
	c0    brf $b0.0, L11?3   ## bblock 32, line 110-3,  t813(I1)
;;								## 50
	c0    ldw $r0.14 = 768[$r0.2]   ## bblock 41, line 117-3, t215, t311
;;								## 51
	c0    add $r0.2 = $r0.2, 1024   ## bblock 41, line 0,  t311,  t311,  1024(I32)
;;								## 52
	c0    shru $r0.15 = $r0.14, 16   ## bblock 41, line 117-3,  t214(I16),  t215,  16(SI32)
	c0    shru $r0.16 = $r0.14, 8   ## bblock 41, line 118-3,  t209(I24),  t215,  8(SI32)
;;								## 53
	c0    and $r0.15 = $r0.15, 255   ## bblock 41, line 117-3,  t213,  t214(I16),  255(I32)
	c0    and $r0.16 = $r0.16, 255   ## bblock 41, line 118-3,  t208,  t209(I24),  255(I32)
;;								## 54
	c0    mpylu $r0.17 = $r0.21, $r0.15   ## bblock 41, line 117-3,  t814,  t70,  t213
	c0    and $r0.14 = $r0.14, 255   ## bblock 41, line 119-3,  t211,  t215,  255(I32)
;;								## 55
	c0    mpyhs $r0.15 = $r0.21, $r0.15   ## bblock 41, line 117-3,  t815,  t70,  t213
;;								## 56
	c0    mpylu $r0.18 = $r0.21, $r0.16   ## bblock 41, line 118-3,  t824,  t70,  t208
;;								## 57
	c0    add $r0.17 = $r0.17, $r0.15   ## bblock 41, line 117-3,  t212,  t814,  t815
	c0    mpyhs $r0.16 = $r0.21, $r0.16   ## bblock 41, line 118-3,  t825,  t70,  t208
;;								## 58
	c0    cmplt $b0.0 = $r0.17, $r0.0   ## bblock 41, line 117-3,  t818,  t212,  0(I32)
	c0    add $r0.15 = $r0.17, 255   ## bblock 41, line 117-3,  t819,  t212,  255(I32)
;;								## 59
	c0    slct $r0.15 = $b0.0, $r0.15, $r0.17   ## bblock 41, line 117-3,  t820,  t818,  t819,  t212
	c0    add $r0.18 = $r0.18, $r0.16   ## bblock 41, line 118-3,  t207,  t824,  t825
;;								## 60
	c0    shr $r0.15 = $r0.15, 8   ## bblock 41, line 117-3,  t242,  t820,  8(I32)
	c0    cmplt $b0.0 = $r0.18, $r0.0   ## bblock 41, line 118-3,  t826,  t207,  0(I32)
;;								## 61
	c0    add $r0.15 = $r0.18, 255   ## bblock 41, line 118-3,  t827,  t207,  255(I32)
	c0    add $r0.12 = $r0.12, $r0.15   ## bblock 41, line 117-3,  t829,  t275,  t242
;;								## 62
	c0    slct $r0.15 = $b0.0, $r0.15, $r0.18   ## bblock 41, line 118-3,  t828,  t826,  t827,  t207
	c0    add $r0.8 = $r0.12, $r0.8   ## bblock 41, line 117-3,  t203,  t829,  t203
;;								## 63
	c0    mpylu $r0.12 = $r0.21, $r0.14   ## bblock 41, line 119-3,  t816,  t70,  t211
	c0    shr $r0.15 = $r0.15, 8   ## bblock 41, line 118-3,  t206,  t828,  8(I32)
;;								## 64
	c0    mpyhs $r0.21 = $r0.21, $r0.14   ## bblock 41, line 119-3,  t817,  t70,  t211
	c0    add $r0.3 = $r0.3, $r0.15   ## bblock 41, line 118-3,  t830,  t280,  t206
;;								## 65
	c0    add $r0.7 = $r0.3, $r0.7   ## bblock 41, line 118-3,  t204,  t830,  t204
;;								## 66
	c0    add $r0.12 = $r0.12, $r0.21   ## bblock 41, line 119-3,  t210,  t816,  t817
;;								## 67
	c0    cmplt $b0.0 = $r0.12, $r0.0   ## bblock 41, line 119-3,  t821,  t210,  0(I32)
	c0    add $r0.3 = $r0.12, 255   ## bblock 41, line 119-3,  t822,  t210,  255(I32)
;;								## 68
	c0    slct $r0.3 = $b0.0, $r0.3, $r0.12   ## bblock 41, line 119-3,  t823,  t821,  t822,  t210
;;								## 69
	c0    shr $r0.3 = $r0.3, 8   ## bblock 41, line 119-3,  t243,  t823,  8(I32)
;;								## 70
	c0    add $r0.13 = $r0.13, $r0.3   ## bblock 41, line 119-3,  t831,  t276,  t243
;;								## 71
	c0    add $r0.10 = $r0.13, $r0.10   ## bblock 41, line 119-3,  t189,  t831,  t189
	c0    goto L10?3 ## goto
;;								## 72
.trace 4
L11?3:
	c0    add $r0.12 = $r0.24, 4   ## bblock 42, line 0,  t489,  t489,  4(I32)
	c0    add $r0.15 = $r0.26, 28   ## bblock 42, line 0,  t487,  t487,  28(I32)
;;								## 0
	c0    add $r0.5 = $r0.5, $r0.20   ## bblock 42, line 0,  t152,  t152,  t282
	c0    add $r0.6 = $r0.6, $r0.16   ## bblock 42, line 0,  t153,  t153,  t283
;;								## 1
	c0    add $r0.3 = $r0.23, 1   ## bblock 42, line 0,  t490,  t490,  1(I32)
	c0    add $r0.9 = $r0.9, $r0.14   ## bblock 42, line 0,  t151,  t151,  t281
;;								## 2
	c0    mov $r0.13 = $r0.25   ## t571
	c0    goto L8?3 ## goto
;;								## 3
.trace 6
L9?3:
	c0    max $r0.9 = $r0.9, $r0.0   ## bblock 12, line 163,  t173,  t151,  0(SI32)
	c0    max $r0.6 = $r0.6, $r0.0   ## bblock 12, line 161,  t185,  t153,  0(SI32)
;;								## 0
	c0    min $r0.9 = $r0.9, 255   ## bblock 12, line 163,  t83,  t173,  255(SI32)
	c0    min $r0.6 = $r0.6, 255   ## bblock 12, line 161,  t90,  t185,  255(SI32)
;;								## 1
	c0    max $r0.5 = $r0.5, $r0.0   ## bblock 12, line 162,  t179,  t152,  0(SI32)
	c0    shl $r0.6 = $r0.6, 16   ## bblock 12, line 162,  t93,  t90,  16(SI32)
;;								## 2
	c0    min $r0.5 = $r0.5, 255   ## bblock 12, line 162,  t86,  t179,  255(SI32)
	c0    or $r0.9 = $r0.9, $r0.6   ## bblock 12, line 163,  t763,  t83,  t93
;;								## 3
	c0    shl $r0.5 = $r0.5, 8   ## bblock 12, line 163,  t89,  t86,  8(SI32)
	c0    add $r0.3 = $r0.28, $r0.29   ## bblock 12, line 161,  t764,  t533,  t574
;;								## 4
	c0    or $r0.9 = $r0.9, $r0.5   ## bblock 12, line 163,  t94,  t763,  t89
	c0    add $r0.4 = $r0.28, 4   ## bblock 12, line 0,  t533,  t533,  4(I32)
;;								## 5
	c0    stw 0[$r0.3] = $r0.9   ## bblock 12, line 161, t764, t94
	c0    add $r0.2 = $r0.27, 1   ## bblock 12, line 0,  t536,  t536,  1(I32)
	      ## goto
;;
	c0    goto L6?3 ## goto
;;								## 6
.trace 9
L7?3:
	c0    add $r0.13 = $r0.13, 256   ## bblock 9, line 0,  t571,  t571,  256(I32)
;;								## 0
	c0    add $r0.29 = $r0.29, 256   ## bblock 9, line 0,  t574,  t574,  256(I32)
;;								## 1
	c0    add $r0.3 = $r0.30, 1   ## bblock 9, line 0,  t575,  t575,  1(I32)
	c0    goto L4?3 ## goto
;;								## 2
.trace 13
L5?3:
	c0    stw 0x10[$r0.1] = $r0.31  ## spill ## t128
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 1
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 171,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
;;								## 2
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t128
	      xnop 1
;;								## 4
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 6, line 173,  t129,  ?2.4?2auto_size(I32),  t128
;;								## 5
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
