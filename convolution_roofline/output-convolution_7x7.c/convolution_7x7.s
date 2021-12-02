 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -prefetch -mas_g -mas_G -O3 -o a.out"
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
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t128
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t647,  (~0xfff)(I32)
	c0    mov $r0.3 = (conv7_result + 0)   ## bblock 1, line 0,  t646,  addr(conv7_result?1.0)(P32)
	c0    ldw $r0.4 = 0x10[$r0.1]  ## restore ## t128
;;								## 2
;;								## 3
.trace 7
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 88,  t761(I1),  t647,  0(SI32)
	c0    pft 32[$r0.3]   ## [spec] bblock 35, line 89,  t646,  32(I32)
	c0    add $r0.2 = $r0.2, 8   ## [spec] bblock 35, line 0,  t647,  t647,  8(I32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 88,  t761(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 35, line 89, t646, 0(SI32)
	c0    stw 4[$r0.3] = $r0.0   ## bblock 35, line 89-1, t646, 0(SI32)
	c0    stw 8[$r0.3] = $r0.0   ## bblock 35, line 89-2, t646, 0(SI32)
	c0    stw 12[$r0.3] = $r0.0   ## bblock 35, line 89-3, t646, 0(SI32)
	c0    stw 16[$r0.3] = $r0.0   ## bblock 35, line 89-4, t646, 0(SI32)
	c0    stw 20[$r0.3] = $r0.0   ## bblock 35, line 89-5, t646, 0(SI32)
	c0    stw 24[$r0.3] = $r0.0   ## bblock 35, line 89-6, t646, 0(SI32)
	c0    stw 28[$r0.3] = $r0.0   ## bblock 35, line 89-7, t646, 0(SI32)
	c0    add $r0.3 = $r0.3, 32   ## bblock 35, line 0,  t646,  t646,  32(I32)
	c0    goto L2?3 ## goto
;;								## 2
.trace 12
L3?3:
	c0    mov $r0.3 = (~0x39)   ## bblock 3, line 0,  t575,  (~0x39)(I32)
	c0    mov $r0.6 = $r0.0   ## bblock 3, line 0,  t571,  0(I32)
	c0    mov $r0.43 = ((conv7_result + 0) + 780)   ## bblock 3, line 0,  t574,  (addr(conv7_result?1.0)(P32) + 0x30c(I32))(P32)
	c0    mov $r0.45 = $r0.4   ## t128
;;								## 0
.trace 8
L4?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 4, line 95,  t762(I1),  t575,  0(SI32)
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 7, line 0,  t533,  0(I32)
	c0    mov $r0.2 = (~0x39)   ## [spec] bblock 7, line 0,  t536,  (~0x39)(I32)
	c0    mov $r0.44 = $r0.3   ## t575
;;								## 0
	c0    brf $b0.0, L5?3   ## bblock 4, line 95,  t762(I1)
;;								## 1
.trace 5
L6?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 8, line 96,  t763(I1),  t536,  0(SI32)
	c0    mov $r0.3 = (~0x6)   ## [spec] bblock 10, line 0,  t490,  (~0x6)(I32)
	c0    mov $r0.10 = (filter7x7 + 0)   ## [spec] bblock 10, line 0,  t487,  addr(filter7x7?1.0)(P32)
	c0    mov $r0.5 = $r0.4   ## [spec] bblock 10, line 0,  t489,  t533
	c0    mov $r0.9 = $r0.0   ## [spec] bblock 10, line 98,  t153,  0(SI32)
	c0    mov $r0.8 = $r0.0   ## [spec] bblock 10, line 98,  t152,  0(SI32)
	c0    mov $r0.14 = $r0.0   ## [spec] bblock 10, line 98,  t151,  0(SI32)
	c0    mov $r0.41 = $r0.2   ## t536
	c0    mov $r0.42 = $r0.4   ## t533
;;								## 0
	c0    brf $b0.0, L7?3   ## bblock 8, line 96,  t763(I1)
;;								## 1
.trace 3
L8?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 11, line 102,  t764(I1),  t490,  0(SI32)
	c0    add $r0.7 = $r0.5, $r0.6   ## [spec] bblock 31, line 0,  t355,  t489,  t571
	c0    mov $r0.4 = $r0.10   ## [spec] bblock 31, line 0,  t312,  t487
	c0    mov $r0.15 = $r0.0   ## [spec] bblock 31, line 104,  t189,  0(SI32)
	c0    mov $r0.12 = $r0.0   ## [spec] bblock 31, line 104,  t204,  0(SI32)
	c0    mov $r0.13 = $r0.0   ## [spec] bblock 31, line 104,  t203,  0(SI32)
	c0    mov $r0.16 = (~0x3)   ## [spec] bblock 31, line 0,  t313,  (~0x3)(I32)
	c0    mov $r0.19 = 1024   ## 1024(I32)
	c0    mov $r0.37 = $r0.3   ## t490
	c0    mov $r0.38 = $r0.5   ## t489
	c0    mov $r0.39 = $r0.6   ## t571
	c0    mov $r0.40 = $r0.10   ## t487
;;								## 0
	c0    add $r0.7 = $r0.7, (conv7_image + 0)   ## [spec] bblock 31, line 0,  t323,  t355,  addr(conv7_image?1.0)(P32)
	c0    brf $b0.0, L9?3   ## bblock 11, line 102,  t764(I1)
;;								## 1
	c0    mov $r0.2 = $r0.7   ## bblock 31, line 0,  t311,  t323
;;								## 2
.trace 1
L10?3:
	c0    pft 1024[$r0.2]   ## bblock 32, line 111,  t311,  1024(I32)
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 32, line 111, t227, t311
	c0    pft 32[$r0.4]   ## bblock 32, line 111,  t312,  32(I32)
	c0    ldw $r0.5 = 0[$r0.4]   ## bblock 32, line 111, t224, t312
	c0    ldw $r0.7 = 8[$r0.4]   ## bblock 32, line 111-2, t245, t312
	c0    ldw $r0.11 = 4[$r0.4]   ## bblock 32, line 111-1, t264, t312
	c0    ldw $r0.10 = 256[$r0.2]   ## bblock 32, line 111-1, t269, t311
	c0    ldw $r0.6 = 512[$r0.2]   ## bblock 32, line 111-2, t78, t311
	c0    cmplt $b0.0 = $r0.16, $r0.0   ## bblock 32, line 104-3,  t815(I1),  t313,  0(SI32)
	c0    ldw.d $r0.18 = 12[$r0.4]   ## [spec] bblock 41, line 111-3, t70, t312
	c0    ldw.d $r0.17 = 768[$r0.2]   ## [spec] bblock 41, line 111-3, t215, t311
	c0    add $r0.16 = $r0.16, 4   ## [spec] bblock 41, line 0,  t313,  t313,  4(I32)
	c0    add $r0.2 = $r0.2, $r0.19   ## [spec] bblock 41, line 0,  t311,  t311,  1024(I32)
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 41, line 0,  t312,  t312,  16(I32)
	      xnop 1
;;								## 1
	c0    shru $r0.22 = $r0.3, 16   ## bblock 32, line 111,  t228(I16),  t227,  16(SI32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 32, line 113,  t231,  t227,  255(I32)
	c0    shru $r0.20 = $r0.3, 8   ## bblock 32, line 112,  t235(I24),  t227,  8(SI32)
	c0    shru $r0.25 = $r0.10, 16   ## bblock 32, line 111-1,  t270(I16),  t269,  16(SI32)
	c0    and $r0.10 = $r0.10, 255   ## bblock 32, line 113-1,  t273,  t269,  255(I32)
	c0    shru $r0.24 = $r0.10, 8   ## bblock 32, line 112-1,  t277(I24),  t269,  8(SI32)
	c0    shru $r0.23 = $r0.6, 16   ## bblock 32, line 111-2,  t43(I16),  t78,  16(SI32)
	c0    and $r0.6 = $r0.6, 255   ## bblock 32, line 113-2,  t79,  t78,  255(I32)
	c0    shru $r0.21 = $r0.6, 8   ## bblock 32, line 112-2,  t61(I24),  t78,  8(SI32)
	c0    shru $r0.26 = $r0.17, 16   ## [spec] bblock 41, line 111-3,  t214(I16),  t215,  16(SI32)
	c0    and $r0.17 = $r0.17, 255   ## [spec] bblock 41, line 113-3,  t211,  t215,  255(I32)
	c0    shru $r0.27 = $r0.17, 8   ## [spec] bblock 41, line 112-3,  t209(I24),  t215,  8(SI32)
;;								## 2
	c0    and $r0.22 = $r0.22, 255   ## bblock 32, line 111,  t229,  t228(I16),  255(I32)
	c0    mpylu $r0.28 = $r0.5, $r0.3   ## bblock 32, line 113,  t769,  t224,  t231
	c0    mpyhs $r0.3 = $r0.5, $r0.3   ## bblock 32, line 113,  t770,  t224,  t231
	c0    and $r0.20 = $r0.20, 255   ## bblock 32, line 112,  t236,  t235(I24),  255(I32)
	c0    and $r0.25 = $r0.25, 255   ## bblock 32, line 111-1,  t271,  t270(I16),  255(I32)
	c0    mpylu $r0.30 = $r0.11, $r0.10   ## bblock 32, line 113-1,  t787,  t264,  t273
	c0    mpyhs $r0.10 = $r0.11, $r0.10   ## bblock 32, line 113-1,  t788,  t264,  t273
	c0    and $r0.24 = $r0.24, 255   ## bblock 32, line 112-1,  t278,  t277(I24),  255(I32)
	c0    and $r0.23 = $r0.23, 255   ## bblock 32, line 111-2,  t44,  t43(I16),  255(I32)
	c0    mpylu $r0.29 = $r0.7, $r0.6   ## bblock 32, line 113-2,  t802,  t245,  t79
	c0    mpyhs $r0.6 = $r0.7, $r0.6   ## bblock 32, line 113-2,  t803,  t245,  t79
	c0    and $r0.21 = $r0.21, 255   ## bblock 32, line 112-2,  t62,  t61(I24),  255(I32)
	c0    and $r0.26 = $r0.26, 255   ## [spec] bblock 41, line 111-3,  t213,  t214(I16),  255(I32)
	c0    mpylu $r0.31 = $r0.18, $r0.17   ## [spec] bblock 41, line 113-3,  t818,  t70,  t211
	c0    mpyhs $r0.17 = $r0.18, $r0.17   ## [spec] bblock 41, line 113-3,  t819,  t70,  t211
	c0    and $r0.27 = $r0.27, 255   ## [spec] bblock 41, line 112-3,  t208,  t209(I24),  255(I32)
;;								## 3
	c0    mpylu $r0.34 = $r0.5, $r0.22   ## bblock 32, line 111,  t767,  t224,  t229
	c0    mpyhs $r0.5 = $r0.5, $r0.22   ## bblock 32, line 111,  t768,  t224,  t229
	c0    mpylu $r0.32 = $r0.5, $r0.20   ## bblock 32, line 112,  t777,  t224,  t236
	c0    mpyhs $r0.20 = $r0.5, $r0.20   ## bblock 32, line 112,  t778,  t224,  t236
	c0    mpylu $r0.35 = $r0.11, $r0.25   ## bblock 32, line 111-1,  t782,  t264,  t271
	c0    mpyhs $r0.11 = $r0.11, $r0.25   ## bblock 32, line 111-1,  t783,  t264,  t271
	c0    mpylu $r0.23 = $r0.11, $r0.24   ## bblock 32, line 112-1,  t792,  t264,  t278
	c0    mpyhs $r0.24 = $r0.11, $r0.24   ## bblock 32, line 112-1,  t793,  t264,  t278
	c0    mpylu $r0.22 = $r0.7, $r0.23   ## bblock 32, line 111-2,  t797,  t245,  t44
	c0    mpyhs $r0.7 = $r0.7, $r0.23   ## bblock 32, line 111-2,  t798,  t245,  t44
	c0    mpylu $r0.33 = $r0.7, $r0.21   ## bblock 32, line 112-2,  t807,  t245,  t62
	c0    mpyhs $r0.21 = $r0.7, $r0.21   ## bblock 32, line 112-2,  t808,  t245,  t62
	c0    mpylu $r0.25 = $r0.18, $r0.26   ## [spec] bblock 41, line 111-3,  t816,  t70,  t213
	c0    mpyhs $r0.26 = $r0.18, $r0.26   ## [spec] bblock 41, line 111-3,  t817,  t70,  t213
	c0    mpylu $r0.36 = $r0.18, $r0.27   ## [spec] bblock 41, line 112-3,  t826,  t70,  t208
	c0    mpyhs $r0.18 = $r0.18, $r0.27   ## [spec] bblock 41, line 112-3,  t827,  t70,  t208
;;								## 4
	c0    add $r0.28 = $r0.28, $r0.3   ## bblock 32, line 113,  t232,  t769,  t770
	c0    add $r0.30 = $r0.30, $r0.10   ## bblock 32, line 113-1,  t274,  t787,  t788
	c0    add $r0.29 = $r0.29, $r0.6   ## bblock 32, line 113-2,  t80,  t802,  t803
	c0    add $r0.31 = $r0.31, $r0.17   ## [spec] bblock 41, line 113-3,  t210,  t818,  t819
;;								## 5
	c0    add $r0.34 = $r0.34, $r0.5   ## bblock 32, line 111,  t230,  t767,  t768
	c0    cmplt $b0.1 = $r0.28, $r0.0   ## bblock 32, line 113,  t774,  t232,  0(I32)
	c0    add $r0.3 = $r0.28, 255   ## bblock 32, line 113,  t775,  t232,  255(I32)
	c0    add $r0.32 = $r0.32, $r0.20   ## bblock 32, line 112,  t237,  t777,  t778
	c0    add $r0.35 = $r0.35, $r0.11   ## bblock 32, line 111-1,  t272,  t782,  t783
	c0    cmplt $b0.3 = $r0.30, $r0.0   ## bblock 32, line 113-1,  t789,  t274,  0(I32)
	c0    add $r0.6 = $r0.30, 255   ## bblock 32, line 113-1,  t790,  t274,  255(I32)
	c0    add $r0.23 = $r0.23, $r0.24   ## bblock 32, line 112-1,  t279,  t792,  t793
	c0    add $r0.22 = $r0.22, $r0.7   ## bblock 32, line 111-2,  t45,  t797,  t798
	c0    cmplt $b0.2 = $r0.29, $r0.0   ## bblock 32, line 113-2,  t804,  t80,  0(I32)
	c0    add $r0.5 = $r0.29, 255   ## bblock 32, line 113-2,  t805,  t80,  255(I32)
	c0    add $r0.33 = $r0.33, $r0.21   ## bblock 32, line 112-2,  t63,  t807,  t808
	c0    add $r0.25 = $r0.25, $r0.26   ## [spec] bblock 41, line 111-3,  t212,  t816,  t817
	c0    cmplt $b0.4 = $r0.31, $r0.0   ## [spec] bblock 41, line 113-3,  t823,  t210,  0(I32)
	c0    add $r0.7 = $r0.31, 255   ## [spec] bblock 41, line 113-3,  t824,  t210,  255(I32)
	c0    add $r0.36 = $r0.36, $r0.18   ## [spec] bblock 41, line 112-3,  t207,  t826,  t827
;;								## 6
	c0    cmplt $b0.7 = $r0.34, $r0.0   ## bblock 32, line 111,  t771,  t230,  0(I32)
	c0    add $r0.17 = $r0.34, 255   ## bblock 32, line 111,  t772,  t230,  255(I32)
	c0    slct $r0.3 = $b0.1, $r0.3, $r0.28   ## bblock 32, line 113,  t776,  t774,  t775,  t232
	c0    cmplt $b0.5 = $r0.32, $r0.0   ## bblock 32, line 112,  t779,  t237,  0(I32)
	c0    add $r0.10 = $r0.32, 255   ## bblock 32, line 112,  t780,  t237,  255(I32)
	c0    cmplt $b0.3 = $r0.35, $r0.0   ## bblock 32, line 111-1,  t784,  t272,  0(I32)
	c0    add $r0.27 = $r0.35, 255   ## bblock 32, line 111-1,  t785,  t272,  255(I32)
	c0    cmplt $b0.0 = $r0.23, $r0.0   ## bblock 32, line 112-1,  t794,  t279,  0(I32)
	c0    add $r0.24 = $r0.23, 255   ## bblock 32, line 112-1,  t795,  t279,  255(I32)
	c0    cmplt $b0.4 = $r0.22, $r0.0   ## bblock 32, line 111-2,  t799,  t45,  0(I32)
	c0    add $r0.20 = $r0.22, 255   ## bblock 32, line 111-2,  t800,  t45,  255(I32)
	c0    slct $r0.5 = $b0.2, $r0.5, $r0.29   ## bblock 32, line 113-2,  t806,  t804,  t805,  t80
	c0    cmplt $b0.6 = $r0.33, $r0.0   ## bblock 32, line 112-2,  t809,  t63,  0(I32)
	c0    add $r0.11 = $r0.33, 255   ## bblock 32, line 112-2,  t810,  t63,  255(I32)
	c0    cmplt $b0.1 = $r0.25, $r0.0   ## [spec] bblock 41, line 111-3,  t820,  t212,  0(I32)
	c0    add $r0.28 = $r0.25, 255   ## [spec] bblock 41, line 111-3,  t821,  t212,  255(I32)
	c0    cmplt $b0.2 = $r0.36, $r0.0   ## [spec] bblock 41, line 112-3,  t828,  t207,  0(I32)
	c0    add $r0.29 = $r0.36, 255   ## [spec] bblock 41, line 112-3,  t829,  t207,  255(I32)
	c0    mfb $r0.18 = $b0.4   ## [spec] t823
	c0    mfb $r0.21 = $b0.0   ## t815(I1)
	c0    mfb $r0.26 = $b0.3   ## t789
;;								## 7
	c0    slct $r0.17 = $b0.7, $r0.17, $r0.34   ## bblock 32, line 111,  t773,  t771,  t772,  t230
	c0    shr $r0.3 = $r0.3, 8   ## bblock 32, line 113,  t234,  t776,  8(I32)
	c0    slct $r0.10 = $b0.5, $r0.10, $r0.32   ## bblock 32, line 112,  t781,  t779,  t780,  t237
	c0    slct $r0.27 = $b0.3, $r0.27, $r0.35   ## bblock 32, line 111-1,  t786,  t784,  t785,  t272
	c0    slct $r0.24 = $b0.0, $r0.24, $r0.23   ## bblock 32, line 112-1,  t796,  t794,  t795,  t279
	c0    slct $r0.20 = $b0.4, $r0.20, $r0.22   ## bblock 32, line 111-2,  t801,  t799,  t800,  t45
	c0    shr $r0.5 = $r0.5, 8   ## bblock 32, line 113-2,  t81,  t806,  8(I32)
	c0    slct $r0.11 = $b0.6, $r0.11, $r0.33   ## bblock 32, line 112-2,  t811,  t809,  t810,  t63
	c0    slct $r0.28 = $b0.1, $r0.28, $r0.25   ## [spec] bblock 41, line 111-3,  t822,  t820,  t821,  t212
	c0    slct $r0.29 = $b0.2, $r0.29, $r0.36   ## [spec] bblock 41, line 112-3,  t830,  t828,  t829,  t207
	c0    mtb $b0.1 = $r0.18   ## [spec] t823
	c0    mtb $b0.3 = $r0.21   ## t815(I1)
	c0    mtb $b0.0 = $r0.26   ## t789
;;								## 8
	c0    shr $r0.17 = $r0.17, 8   ## bblock 32, line 111,  t233,  t773,  8(I32)
	c0    shr $r0.10 = $r0.10, 8   ## bblock 32, line 112,  t238,  t781,  8(I32)
	c0    shr $r0.27 = $r0.27, 8   ## bblock 32, line 111-1,  t275,  t786,  8(I32)
	c0    slct $r0.6 = $b0.0, $r0.6, $r0.30   ## bblock 32, line 113-1,  t791,  t789,  t790,  t274
	c0    shr $r0.24 = $r0.24, 8   ## bblock 32, line 112-1,  t280,  t796,  8(I32)
	c0    shr $r0.20 = $r0.20, 8   ## bblock 32, line 111-2,  t46,  t801,  8(I32)
	c0    shr $r0.11 = $r0.11, 8   ## bblock 32, line 112-2,  t64,  t811,  8(I32)
	c0    add $r0.3 = $r0.3, $r0.5   ## bblock 32, line 113-2,  t813,  t234,  t81
	c0    shr $r0.28 = $r0.28, 8   ## [spec] bblock 41, line 111-3,  t242,  t822,  8(I32)
	c0    slct $r0.7 = $b0.1, $r0.7, $r0.31   ## [spec] bblock 41, line 113-3,  t825,  t823,  t824,  t210
	c0    shr $r0.29 = $r0.29, 8   ## [spec] bblock 41, line 112-3,  t206,  t830,  8(I32)
;;								## 9
	c0    shr $r0.6 = $r0.6, 8   ## bblock 32, line 113-1,  t276,  t791,  8(I32)
	c0    add $r0.5 = $r0.24, $r0.12   ## bblock 32, line 112-1,  t282,  t280,  t204
	c0    add $r0.11 = $r0.27, $r0.13   ## bblock 32, line 111-1,  t283,  t275,  t203
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 32, line 112-2,  t812,  t238,  t64
	c0    add $r0.14 = $r0.3, $r0.14   ## bblock 32, line 113-2,  t151,  t813,  t151
	c0    add $r0.17 = $r0.17, $r0.20   ## bblock 32, line 111-2,  t814,  t233,  t46
	c0    shr $r0.7 = $r0.7, 8   ## [spec] bblock 41, line 113-3,  t243,  t825,  8(I32)
	c0    add $r0.27 = $r0.27, $r0.28   ## [spec] bblock 41, line 111-3,  t831,  t275,  t242
	c0    add $r0.24 = $r0.24, $r0.29   ## [spec] bblock 41, line 112-3,  t832,  t280,  t206
;;								## 10
	c0    add $r0.3 = $r0.6, $r0.15   ## bblock 32, line 113-1,  t281,  t276,  t189
	c0    add $r0.8 = $r0.10, $r0.8   ## bblock 32, line 112-2,  t152,  t812,  t152
	c0    add $r0.9 = $r0.17, $r0.9   ## bblock 32, line 111-2,  t153,  t814,  t153
	c0    add $r0.13 = $r0.27, $r0.13   ## [spec] bblock 41, line 111-3,  t203,  t831,  t203
	c0    add $r0.12 = $r0.24, $r0.12   ## [spec] bblock 41, line 112-3,  t204,  t832,  t204
	c0    add $r0.6 = $r0.6, $r0.7   ## [spec] bblock 41, line 113-3,  t833,  t276,  t243
	c0    brf $b0.3, L11?3   ## bblock 32, line 104-3,  t815(I1)
;;								## 11
	c0    add $r0.15 = $r0.6, $r0.15   ## bblock 41, line 113-3,  t189,  t833,  t189
	c0    goto L10?3 ## goto
;;								## 12
.trace 4
L11?3:
	c0    add $r0.14 = $r0.14, $r0.3   ## bblock 42, line 0,  t151,  t151,  t281
	c0    add $r0.9 = $r0.9, $r0.11   ## bblock 42, line 0,  t153,  t153,  t283
	c0    add $r0.3 = $r0.37, 1   ## bblock 42, line 0,  t490,  t490,  1(I32)
	c0    add $r0.10 = $r0.40, 28   ## bblock 42, line 0,  t487,  t487,  28(I32)
	c0    add $r0.5 = $r0.38, 4   ## bblock 42, line 0,  t489,  t489,  4(I32)
	c0    mov $r0.6 = $r0.39   ## t571
	c0    mov $r0.2 = $r0.5   ## t282
;;								## 0
	c0    add $r0.8 = $r0.8, $r0.2   ## bblock 42, line 0,  t152,  t152,  t282
	c0    goto L8?3 ## goto
;;								## 1
.trace 6
L9?3:
	c0    max $r0.14 = $r0.14, $r0.0   ## bblock 12, line 157,  t173,  t151,  0(SI32)
	c0    max $r0.8 = $r0.8, $r0.0   ## bblock 12, line 156,  t179,  t152,  0(SI32)
	c0    max $r0.9 = $r0.9, $r0.0   ## bblock 12, line 155,  t185,  t153,  0(SI32)
	c0    add $r0.3 = $r0.42, $r0.43   ## bblock 12, line 155,  t766,  t533,  t574
	c0    add $r0.2 = $r0.41, 1   ## bblock 12, line 0,  t536,  t536,  1(I32)
	c0    add $r0.4 = $r0.42, 4   ## bblock 12, line 0,  t533,  t533,  4(I32)
	c0    mov $r0.6 = $r0.39   ## t571
;;								## 0
	c0    min $r0.14 = $r0.14, 255   ## bblock 12, line 157,  t83,  t173,  255(SI32)
	c0    min $r0.8 = $r0.8, 255   ## bblock 12, line 156,  t86,  t179,  255(SI32)
	c0    min $r0.9 = $r0.9, 255   ## bblock 12, line 155,  t90,  t185,  255(SI32)
	c0    pft 32[$r0.3]   ## bblock 12, line 155,  t766,  32(I32)
;;								## 1
	c0    shl $r0.8 = $r0.8, 8   ## bblock 12, line 157,  t89,  t86,  8(SI32)
	c0    shl $r0.9 = $r0.9, 16   ## bblock 12, line 156,  t93,  t90,  16(SI32)
;;								## 2
	c0    or $r0.14 = $r0.14, $r0.9   ## bblock 12, line 157,  t765,  t83,  t93
;;								## 3
	c0    or $r0.14 = $r0.14, $r0.8   ## bblock 12, line 157,  t94,  t765,  t89
;;								## 4
	c0    stw 0[$r0.3] = $r0.14   ## bblock 12, line 155, t766, t94
	c0    goto L6?3 ## goto
;;								## 5
.trace 9
L7?3:
	c0    add $r0.3 = $r0.44, 1   ## bblock 9, line 0,  t575,  t575,  1(I32)
	c0    add $r0.6 = $r0.6, 256   ## bblock 9, line 0,  t571,  t571,  256(I32)
	c0    add $r0.43 = $r0.43, 256   ## bblock 9, line 0,  t574,  t574,  256(I32)
	c0    goto L4?3 ## goto
;;								## 0
.trace 13
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 165,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    stw 0x10[$r0.1] = $r0.45  ## spill ## t128
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t128
	      xnop 1
;;								## 2
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 6, line 167,  t129,  ?2.4?2auto_size(I32),  t128
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
