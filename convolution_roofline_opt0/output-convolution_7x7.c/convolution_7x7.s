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
.trace 13
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 64,  raddr(NOP)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t128
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t791,  (~0xfff)(I32)
	c0    mov $r0.3 = (conv7_result + 0)   ## bblock 1, line 0,  t790,  addr(conv7_result?1.0)(P32)
;;								## 2
.trace 7
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 88,  t1217(I1),  t791,  0(SI32)
	c0    pft 128[$r0.3]   ## [spec] bblock 35, line 89,  t790,  128(I32)
	c0    add $r0.2 = $r0.2, 32   ## [spec] bblock 35, line 0,  t791,  t791,  32(I32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 88,  t1217(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 35, line 89, t790, 0(SI32)
	c0    stw 4[$r0.3] = $r0.0   ## bblock 35, line 89-1, t790, 0(SI32)
	c0    stw 8[$r0.3] = $r0.0   ## bblock 35, line 89-2, t790, 0(SI32)
	c0    stw 12[$r0.3] = $r0.0   ## bblock 35, line 89-3, t790, 0(SI32)
	c0    stw 16[$r0.3] = $r0.0   ## bblock 35, line 89-4, t790, 0(SI32)
	c0    stw 20[$r0.3] = $r0.0   ## bblock 35, line 89-5, t790, 0(SI32)
	c0    stw 24[$r0.3] = $r0.0   ## bblock 35, line 89-6, t790, 0(SI32)
	c0    stw 28[$r0.3] = $r0.0   ## bblock 35, line 89-7, t790, 0(SI32)
	c0    stw 32[$r0.3] = $r0.0   ## bblock 35, line 89-8, t790, 0(SI32)
	c0    stw 36[$r0.3] = $r0.0   ## bblock 35, line 89-9, t790, 0(SI32)
	c0    stw 40[$r0.3] = $r0.0   ## bblock 35, line 89-10, t790, 0(SI32)
	c0    stw 44[$r0.3] = $r0.0   ## bblock 35, line 89-11, t790, 0(SI32)
	c0    stw 48[$r0.3] = $r0.0   ## bblock 35, line 89-12, t790, 0(SI32)
	c0    stw 52[$r0.3] = $r0.0   ## bblock 35, line 89-13, t790, 0(SI32)
	c0    stw 56[$r0.3] = $r0.0   ## bblock 35, line 89-14, t790, 0(SI32)
	c0    stw 60[$r0.3] = $r0.0   ## bblock 35, line 89-15, t790, 0(SI32)
	c0    stw 64[$r0.3] = $r0.0   ## bblock 35, line 89-16, t790, 0(SI32)
	c0    stw 68[$r0.3] = $r0.0   ## bblock 35, line 89-17, t790, 0(SI32)
	c0    stw 72[$r0.3] = $r0.0   ## bblock 35, line 89-18, t790, 0(SI32)
	c0    stw 76[$r0.3] = $r0.0   ## bblock 35, line 89-19, t790, 0(SI32)
	c0    stw 80[$r0.3] = $r0.0   ## bblock 35, line 89-20, t790, 0(SI32)
	c0    stw 84[$r0.3] = $r0.0   ## bblock 35, line 89-21, t790, 0(SI32)
	c0    stw 88[$r0.3] = $r0.0   ## bblock 35, line 89-22, t790, 0(SI32)
	c0    stw 92[$r0.3] = $r0.0   ## bblock 35, line 89-23, t790, 0(SI32)
	c0    stw 96[$r0.3] = $r0.0   ## bblock 35, line 89-24, t790, 0(SI32)
	c0    stw 100[$r0.3] = $r0.0   ## bblock 35, line 89-25, t790, 0(SI32)
	c0    stw 104[$r0.3] = $r0.0   ## bblock 35, line 89-26, t790, 0(SI32)
	c0    stw 108[$r0.3] = $r0.0   ## bblock 35, line 89-27, t790, 0(SI32)
	c0    stw 112[$r0.3] = $r0.0   ## bblock 35, line 89-28, t790, 0(SI32)
	c0    stw 116[$r0.3] = $r0.0   ## bblock 35, line 89-29, t790, 0(SI32)
	c0    stw 120[$r0.3] = $r0.0   ## bblock 35, line 89-30, t790, 0(SI32)
	c0    stw 124[$r0.3] = $r0.0   ## bblock 35, line 89-31, t790, 0(SI32)
;;								## 2
	c0    add $r0.3 = $r0.3, 128   ## bblock 35, line 0,  t790,  t790,  128(I32)
	c0    goto L2?3 ## goto
;;								## 3
.trace 11
L3?3:
	c0    mov $r0.3 = (~0x39)   ## bblock 3, line 0,  t647,  (~0x39)(I32)
	c0    mov $r0.6 = $r0.0   ## bblock 3, line 0,  t643,  0(I32)
	c0    mov $r0.43 = ((conv7_result + 0) + 780)   ## bblock 3, line 0,  t646,  (addr(conv7_result?1.0)(P32) + 0x30c(I32))(P32)
;;								## 0
.trace 8
L4?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 4, line 95,  t1218(I1),  t647,  0(SI32)
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 7, line 0,  t605,  0(I32)
	c0    mov $r0.2 = (~0x39)   ## [spec] bblock 7, line 0,  t608,  (~0x39)(I32)
	c0    mov $r0.44 = $r0.3   ## t647
;;								## 0
	c0    brf $b0.0, L5?3   ## bblock 4, line 95,  t1218(I1)
;;								## 1
.trace 5
L6?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 8, line 96,  t1219(I1),  t608,  0(SI32)
	c0    mov $r0.3 = (~0x6)   ## [spec] bblock 10, line 0,  t562,  (~0x6)(I32)
	c0    mov $r0.10 = (filter7x7 + 0)   ## [spec] bblock 10, line 0,  t559,  addr(filter7x7?1.0)(P32)
	c0    mov $r0.5 = $r0.4   ## [spec] bblock 10, line 0,  t561,  t605
	c0    mov $r0.9 = $r0.0   ## [spec] bblock 10, line 98,  t153,  0(SI32)
	c0    mov $r0.8 = $r0.0   ## [spec] bblock 10, line 98,  t152,  0(SI32)
	c0    mov $r0.14 = $r0.0   ## [spec] bblock 10, line 98,  t151,  0(SI32)
	c0    mov $r0.41 = $r0.2   ## t608
	c0    mov $r0.42 = $r0.4   ## t605
;;								## 0
	c0    brf $b0.0, L7?3   ## bblock 8, line 96,  t1219(I1)
;;								## 1
.trace 3
L8?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 11, line 102,  t1220(I1),  t562,  0(SI32)
	c0    add $r0.7 = $r0.5, $r0.6   ## [spec] bblock 31, line 0,  t427,  t561,  t643
	c0    mov $r0.4 = $r0.10   ## [spec] bblock 31, line 0,  t384,  t559
	c0    mov $r0.15 = $r0.0   ## [spec] bblock 31, line 104,  t189,  0(SI32)
	c0    mov $r0.12 = $r0.0   ## [spec] bblock 31, line 104,  t190,  0(SI32)
	c0    mov $r0.13 = $r0.0   ## [spec] bblock 31, line 104,  t191,  0(SI32)
	c0    mov $r0.16 = (~0x3)   ## [spec] bblock 31, line 0,  t385,  (~0x3)(I32)
	c0    mov $r0.19 = 1024   ## 1024(I32)
	c0    mov $r0.37 = $r0.3   ## t562
	c0    mov $r0.38 = $r0.5   ## t561
	c0    mov $r0.39 = $r0.6   ## t643
	c0    mov $r0.40 = $r0.10   ## t559
;;								## 0
	c0    add $r0.7 = $r0.7, (conv7_image + 0)   ## [spec] bblock 31, line 0,  t395,  t427,  addr(conv7_image?1.0)(P32)
	c0    brf $b0.0, L9?3   ## bblock 11, line 102,  t1220(I1)
;;								## 1
	c0    mov $r0.2 = $r0.7   ## bblock 31, line 0,  t383,  t395
;;								## 2
.trace 1
L10?3:
	c0    pft 1024[$r0.2]   ## bblock 32, line 111,  t383,  1024(I32)
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 32, line 111, t78, t383
	c0    pft 32[$r0.4]   ## bblock 32, line 111,  t384,  32(I32)
	c0    ldw $r0.5 = 0[$r0.4]   ## bblock 32, line 111, t226, t384
	c0    ldw $r0.7 = 8[$r0.4]   ## bblock 32, line 111-2, t316, t384
	c0    ldw $r0.11 = 4[$r0.4]   ## bblock 32, line 111-1, t336, t384
	c0    ldw $r0.10 = 256[$r0.2]   ## bblock 32, line 111-1, t341, t383
	c0    ldw $r0.6 = 512[$r0.2]   ## bblock 32, line 111-2, t321, t383
	c0    cmplt $b0.0 = $r0.16, $r0.0   ## bblock 32, line 104-3,  t1271(I1),  t385,  0(SI32)
	c0    ldw.d $r0.18 = 12[$r0.4]   ## [spec] bblock 113, line 111-3, t70, t384
	c0    ldw.d $r0.17 = 768[$r0.2]   ## [spec] bblock 113, line 111-3, t251, t383
	c0    add $r0.16 = $r0.16, 4   ## [spec] bblock 113, line 0,  t385,  t385,  4(I32)
	c0    add $r0.2 = $r0.2, $r0.19   ## [spec] bblock 113, line 0,  t383,  t383,  1024(I32)
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 113, line 0,  t384,  t384,  16(I32)
	      xnop 1
;;								## 1
	c0    shru $r0.22 = $r0.3, 16   ## bblock 32, line 111,  t43(I16),  t78,  16(SI32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 32, line 113,  t79,  t78,  255(I32)
	c0    shru $r0.20 = $r0.3, 8   ## bblock 32, line 112,  t61(I24),  t78,  8(SI32)
	c0    shru $r0.25 = $r0.10, 16   ## bblock 32, line 111-1,  t342(I16),  t341,  16(SI32)
	c0    and $r0.10 = $r0.10, 255   ## bblock 32, line 113-1,  t345,  t341,  255(I32)
	c0    shru $r0.24 = $r0.10, 8   ## bblock 32, line 112-1,  t349(I24),  t341,  8(SI32)
	c0    shru $r0.23 = $r0.6, 16   ## bblock 32, line 111-2,  t322(I16),  t321,  16(SI32)
	c0    and $r0.6 = $r0.6, 255   ## bblock 32, line 113-2,  t325,  t321,  255(I32)
	c0    shru $r0.21 = $r0.6, 8   ## bblock 32, line 112-2,  t329(I24),  t321,  8(SI32)
	c0    shru $r0.27 = $r0.17, 16   ## [spec] bblock 113, line 111-3,  t255(I16),  t251,  16(SI32)
	c0    and $r0.17 = $r0.17, 255   ## [spec] bblock 113, line 113-3,  t267,  t251,  255(I32)
	c0    shru $r0.26 = $r0.17, 8   ## [spec] bblock 113, line 112-3,  t283(I24),  t251,  8(SI32)
;;								## 2
	c0    and $r0.22 = $r0.22, 255   ## bblock 32, line 111,  t44,  t43(I16),  255(I32)
	c0    mpylu $r0.28 = $r0.5, $r0.3   ## bblock 32, line 113,  t1225,  t226,  t79
	c0    mpyhs $r0.3 = $r0.5, $r0.3   ## bblock 32, line 113,  t1226,  t226,  t79
	c0    and $r0.20 = $r0.20, 255   ## bblock 32, line 112,  t62,  t61(I24),  255(I32)
	c0    and $r0.25 = $r0.25, 255   ## bblock 32, line 111-1,  t343,  t342(I16),  255(I32)
	c0    mpylu $r0.30 = $r0.11, $r0.10   ## bblock 32, line 113-1,  t1243,  t336,  t345
	c0    mpyhs $r0.10 = $r0.11, $r0.10   ## bblock 32, line 113-1,  t1244,  t336,  t345
	c0    and $r0.24 = $r0.24, 255   ## bblock 32, line 112-1,  t350,  t349(I24),  255(I32)
	c0    and $r0.23 = $r0.23, 255   ## bblock 32, line 111-2,  t323,  t322(I16),  255(I32)
	c0    mpylu $r0.29 = $r0.7, $r0.6   ## bblock 32, line 113-2,  t1258,  t316,  t325
	c0    mpyhs $r0.6 = $r0.7, $r0.6   ## bblock 32, line 113-2,  t1259,  t316,  t325
	c0    and $r0.21 = $r0.21, 255   ## bblock 32, line 112-2,  t330,  t329(I24),  255(I32)
	c0    and $r0.27 = $r0.27, 255   ## [spec] bblock 113, line 111-3,  t259,  t255(I16),  255(I32)
	c0    mpylu $r0.31 = $r0.18, $r0.17   ## [spec] bblock 113, line 113-3,  t1274,  t70,  t267
	c0    mpyhs $r0.17 = $r0.18, $r0.17   ## [spec] bblock 113, line 113-3,  t1275,  t70,  t267
	c0    and $r0.26 = $r0.26, 255   ## [spec] bblock 113, line 112-3,  t287,  t283(I24),  255(I32)
;;								## 3
	c0    mpylu $r0.34 = $r0.5, $r0.22   ## bblock 32, line 111,  t1223,  t226,  t44
	c0    mpyhs $r0.5 = $r0.5, $r0.22   ## bblock 32, line 111,  t1224,  t226,  t44
	c0    mpylu $r0.32 = $r0.5, $r0.20   ## bblock 32, line 112,  t1233,  t226,  t62
	c0    mpyhs $r0.20 = $r0.5, $r0.20   ## bblock 32, line 112,  t1234,  t226,  t62
	c0    mpylu $r0.35 = $r0.11, $r0.25   ## bblock 32, line 111-1,  t1238,  t336,  t343
	c0    mpyhs $r0.11 = $r0.11, $r0.25   ## bblock 32, line 111-1,  t1239,  t336,  t343
	c0    mpylu $r0.23 = $r0.11, $r0.24   ## bblock 32, line 112-1,  t1248,  t336,  t350
	c0    mpyhs $r0.24 = $r0.11, $r0.24   ## bblock 32, line 112-1,  t1249,  t336,  t350
	c0    mpylu $r0.22 = $r0.7, $r0.23   ## bblock 32, line 111-2,  t1253,  t316,  t323
	c0    mpyhs $r0.7 = $r0.7, $r0.23   ## bblock 32, line 111-2,  t1254,  t316,  t323
	c0    mpylu $r0.33 = $r0.7, $r0.21   ## bblock 32, line 112-2,  t1263,  t316,  t330
	c0    mpyhs $r0.21 = $r0.7, $r0.21   ## bblock 32, line 112-2,  t1264,  t316,  t330
	c0    mpylu $r0.36 = $r0.18, $r0.27   ## [spec] bblock 113, line 111-3,  t1272,  t70,  t259
	c0    mpyhs $r0.18 = $r0.18, $r0.27   ## [spec] bblock 113, line 111-3,  t1273,  t70,  t259
	c0    mpylu $r0.25 = $r0.18, $r0.26   ## [spec] bblock 113, line 112-3,  t1282,  t70,  t287
	c0    mpyhs $r0.26 = $r0.18, $r0.26   ## [spec] bblock 113, line 112-3,  t1283,  t70,  t287
;;								## 4
	c0    add $r0.28 = $r0.28, $r0.3   ## bblock 32, line 113,  t80,  t1225,  t1226
	c0    add $r0.30 = $r0.30, $r0.10   ## bblock 32, line 113-1,  t346,  t1243,  t1244
	c0    add $r0.29 = $r0.29, $r0.6   ## bblock 32, line 113-2,  t326,  t1258,  t1259
	c0    add $r0.31 = $r0.31, $r0.17   ## [spec] bblock 113, line 113-3,  t271,  t1274,  t1275
;;								## 5
	c0    add $r0.34 = $r0.34, $r0.5   ## bblock 32, line 111,  t45,  t1223,  t1224
	c0    cmplt $b0.1 = $r0.28, $r0.0   ## bblock 32, line 113,  t1230,  t80,  0(I32)
	c0    add $r0.3 = $r0.28, 255   ## bblock 32, line 113,  t1231,  t80,  255(I32)
	c0    add $r0.32 = $r0.32, $r0.20   ## bblock 32, line 112,  t63,  t1233,  t1234
	c0    add $r0.35 = $r0.35, $r0.11   ## bblock 32, line 111-1,  t344,  t1238,  t1239
	c0    cmplt $b0.3 = $r0.30, $r0.0   ## bblock 32, line 113-1,  t1245,  t346,  0(I32)
	c0    add $r0.6 = $r0.30, 255   ## bblock 32, line 113-1,  t1246,  t346,  255(I32)
	c0    add $r0.23 = $r0.23, $r0.24   ## bblock 32, line 112-1,  t351,  t1248,  t1249
	c0    add $r0.22 = $r0.22, $r0.7   ## bblock 32, line 111-2,  t324,  t1253,  t1254
	c0    cmplt $b0.2 = $r0.29, $r0.0   ## bblock 32, line 113-2,  t1260,  t326,  0(I32)
	c0    add $r0.5 = $r0.29, 255   ## bblock 32, line 113-2,  t1261,  t326,  255(I32)
	c0    add $r0.33 = $r0.33, $r0.21   ## bblock 32, line 112-2,  t331,  t1263,  t1264
	c0    add $r0.36 = $r0.36, $r0.18   ## [spec] bblock 113, line 111-3,  t263,  t1272,  t1273
	c0    cmplt $b0.4 = $r0.31, $r0.0   ## [spec] bblock 113, line 113-3,  t1279,  t271,  0(I32)
	c0    add $r0.7 = $r0.31, 255   ## [spec] bblock 113, line 113-3,  t1280,  t271,  255(I32)
	c0    add $r0.25 = $r0.25, $r0.26   ## [spec] bblock 113, line 112-3,  t291,  t1282,  t1283
;;								## 6
	c0    cmplt $b0.7 = $r0.34, $r0.0   ## bblock 32, line 111,  t1227,  t45,  0(I32)
	c0    add $r0.17 = $r0.34, 255   ## bblock 32, line 111,  t1228,  t45,  255(I32)
	c0    slct $r0.3 = $b0.1, $r0.3, $r0.28   ## bblock 32, line 113,  t1232,  t1230,  t1231,  t80
	c0    cmplt $b0.5 = $r0.32, $r0.0   ## bblock 32, line 112,  t1235,  t63,  0(I32)
	c0    add $r0.10 = $r0.32, 255   ## bblock 32, line 112,  t1236,  t63,  255(I32)
	c0    cmplt $b0.3 = $r0.35, $r0.0   ## bblock 32, line 111-1,  t1240,  t344,  0(I32)
	c0    add $r0.27 = $r0.35, 255   ## bblock 32, line 111-1,  t1241,  t344,  255(I32)
	c0    cmplt $b0.0 = $r0.23, $r0.0   ## bblock 32, line 112-1,  t1250,  t351,  0(I32)
	c0    add $r0.24 = $r0.23, 255   ## bblock 32, line 112-1,  t1251,  t351,  255(I32)
	c0    cmplt $b0.4 = $r0.22, $r0.0   ## bblock 32, line 111-2,  t1255,  t324,  0(I32)
	c0    add $r0.20 = $r0.22, 255   ## bblock 32, line 111-2,  t1256,  t324,  255(I32)
	c0    slct $r0.5 = $b0.2, $r0.5, $r0.29   ## bblock 32, line 113-2,  t1262,  t1260,  t1261,  t326
	c0    cmplt $b0.6 = $r0.33, $r0.0   ## bblock 32, line 112-2,  t1265,  t331,  0(I32)
	c0    add $r0.11 = $r0.33, 255   ## bblock 32, line 112-2,  t1266,  t331,  255(I32)
	c0    cmplt $b0.2 = $r0.36, $r0.0   ## [spec] bblock 113, line 111-3,  t1276,  t263,  0(I32)
	c0    add $r0.29 = $r0.36, 255   ## [spec] bblock 113, line 111-3,  t1277,  t263,  255(I32)
	c0    cmplt $b0.1 = $r0.25, $r0.0   ## [spec] bblock 113, line 112-3,  t1284,  t291,  0(I32)
	c0    add $r0.28 = $r0.25, 255   ## [spec] bblock 113, line 112-3,  t1285,  t291,  255(I32)
	c0    mfb $r0.18 = $b0.4   ## [spec] t1279
	c0    mfb $r0.21 = $b0.0   ## t1271(I1)
	c0    mfb $r0.26 = $b0.3   ## t1245
;;								## 7
	c0    slct $r0.17 = $b0.7, $r0.17, $r0.34   ## bblock 32, line 111,  t1229,  t1227,  t1228,  t45
	c0    shr $r0.3 = $r0.3, 8   ## bblock 32, line 113,  t81,  t1232,  8(I32)
	c0    slct $r0.10 = $b0.5, $r0.10, $r0.32   ## bblock 32, line 112,  t1237,  t1235,  t1236,  t63
	c0    slct $r0.27 = $b0.3, $r0.27, $r0.35   ## bblock 32, line 111-1,  t1242,  t1240,  t1241,  t344
	c0    slct $r0.24 = $b0.0, $r0.24, $r0.23   ## bblock 32, line 112-1,  t1252,  t1250,  t1251,  t351
	c0    slct $r0.20 = $b0.4, $r0.20, $r0.22   ## bblock 32, line 111-2,  t1257,  t1255,  t1256,  t324
	c0    shr $r0.5 = $r0.5, 8   ## bblock 32, line 113-2,  t328,  t1262,  8(I32)
	c0    slct $r0.11 = $b0.6, $r0.11, $r0.33   ## bblock 32, line 112-2,  t1267,  t1265,  t1266,  t331
	c0    slct $r0.29 = $b0.2, $r0.29, $r0.36   ## [spec] bblock 113, line 111-3,  t1278,  t1276,  t1277,  t263
	c0    slct $r0.28 = $b0.1, $r0.28, $r0.25   ## [spec] bblock 113, line 112-3,  t1286,  t1284,  t1285,  t291
	c0    mtb $b0.1 = $r0.18   ## [spec] t1279
	c0    mtb $b0.3 = $r0.21   ## t1271(I1)
	c0    mtb $b0.0 = $r0.26   ## t1245
;;								## 8
	c0    shr $r0.17 = $r0.17, 8   ## bblock 32, line 111,  t46,  t1229,  8(I32)
	c0    shr $r0.10 = $r0.10, 8   ## bblock 32, line 112,  t64,  t1237,  8(I32)
	c0    shr $r0.27 = $r0.27, 8   ## bblock 32, line 111-1,  t347,  t1242,  8(I32)
	c0    slct $r0.6 = $b0.0, $r0.6, $r0.30   ## bblock 32, line 113-1,  t1247,  t1245,  t1246,  t346
	c0    shr $r0.24 = $r0.24, 8   ## bblock 32, line 112-1,  t352,  t1252,  8(I32)
	c0    shr $r0.20 = $r0.20, 8   ## bblock 32, line 111-2,  t327,  t1257,  8(I32)
	c0    shr $r0.11 = $r0.11, 8   ## bblock 32, line 112-2,  t332,  t1267,  8(I32)
	c0    add $r0.3 = $r0.3, $r0.5   ## bblock 32, line 113-2,  t1269,  t81,  t328
	c0    shr $r0.29 = $r0.29, 8   ## [spec] bblock 113, line 111-3,  t275,  t1278,  8(I32)
	c0    slct $r0.7 = $b0.1, $r0.7, $r0.31   ## [spec] bblock 113, line 113-3,  t1281,  t1279,  t1280,  t271
	c0    shr $r0.28 = $r0.28, 8   ## [spec] bblock 113, line 112-3,  t295,  t1286,  8(I32)
;;								## 9
	c0    shr $r0.6 = $r0.6, 8   ## bblock 32, line 113-1,  t348,  t1247,  8(I32)
	c0    add $r0.5 = $r0.24, $r0.12   ## bblock 32, line 112-1,  t354,  t352,  t190
	c0    add $r0.11 = $r0.27, $r0.13   ## bblock 32, line 111-1,  t355,  t347,  t191
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 32, line 112-2,  t1268,  t64,  t332
	c0    add $r0.14 = $r0.3, $r0.14   ## bblock 32, line 113-2,  t151,  t1269,  t151
	c0    add $r0.17 = $r0.17, $r0.20   ## bblock 32, line 111-2,  t1270,  t46,  t327
	c0    shr $r0.7 = $r0.7, 8   ## [spec] bblock 113, line 113-3,  t279,  t1281,  8(I32)
	c0    add $r0.27 = $r0.27, $r0.29   ## [spec] bblock 113, line 111-3,  t1287,  t347,  t275
	c0    add $r0.24 = $r0.24, $r0.28   ## [spec] bblock 113, line 112-3,  t1288,  t352,  t295
;;								## 10
	c0    add $r0.3 = $r0.6, $r0.15   ## bblock 32, line 113-1,  t353,  t348,  t189
	c0    add $r0.8 = $r0.10, $r0.8   ## bblock 32, line 112-2,  t152,  t1268,  t152
	c0    add $r0.9 = $r0.17, $r0.9   ## bblock 32, line 111-2,  t153,  t1270,  t153
	c0    add $r0.13 = $r0.27, $r0.13   ## [spec] bblock 113, line 111-3,  t191,  t1287,  t191
	c0    add $r0.12 = $r0.24, $r0.12   ## [spec] bblock 113, line 112-3,  t190,  t1288,  t190
	c0    add $r0.6 = $r0.6, $r0.7   ## [spec] bblock 113, line 113-3,  t1289,  t348,  t279
	c0    brf $b0.3, L11?3   ## bblock 32, line 104-3,  t1271(I1)
;;								## 11
	c0    add $r0.15 = $r0.6, $r0.15   ## bblock 113, line 113-3,  t189,  t1289,  t189
	c0    goto L10?3 ## goto
;;								## 12
.trace 4
L11?3:
	c0    add $r0.14 = $r0.14, $r0.3   ## bblock 114, line 0,  t151,  t151,  t353
	c0    add $r0.9 = $r0.9, $r0.11   ## bblock 114, line 0,  t153,  t153,  t355
	c0    add $r0.3 = $r0.37, 1   ## bblock 114, line 0,  t562,  t562,  1(I32)
	c0    add $r0.10 = $r0.40, 28   ## bblock 114, line 0,  t559,  t559,  28(I32)
	c0    add $r0.5 = $r0.38, 4   ## bblock 114, line 0,  t561,  t561,  4(I32)
	c0    mov $r0.6 = $r0.39   ## t643
	c0    mov $r0.2 = $r0.5   ## t354
;;								## 0
	c0    add $r0.8 = $r0.8, $r0.2   ## bblock 114, line 0,  t152,  t152,  t354
	c0    goto L8?3 ## goto
;;								## 1
.trace 6
L9?3:
	c0    max $r0.14 = $r0.14, $r0.0   ## bblock 12, line 157,  t173,  t151,  0(SI32)
	c0    max $r0.8 = $r0.8, $r0.0   ## bblock 12, line 156,  t179,  t152,  0(SI32)
	c0    max $r0.9 = $r0.9, $r0.0   ## bblock 12, line 155,  t185,  t153,  0(SI32)
	c0    add $r0.3 = $r0.42, $r0.43   ## bblock 12, line 155,  t1222,  t605,  t646
	c0    add $r0.2 = $r0.41, 1   ## bblock 12, line 0,  t608,  t608,  1(I32)
	c0    add $r0.4 = $r0.42, 4   ## bblock 12, line 0,  t605,  t605,  4(I32)
	c0    mov $r0.6 = $r0.39   ## t643
;;								## 0
	c0    min $r0.14 = $r0.14, 255   ## bblock 12, line 157,  t83,  t173,  255(SI32)
	c0    min $r0.8 = $r0.8, 255   ## bblock 12, line 156,  t86,  t179,  255(SI32)
	c0    min $r0.9 = $r0.9, 255   ## bblock 12, line 155,  t90,  t185,  255(SI32)
	c0    pft 32[$r0.3]   ## bblock 12, line 155,  t1222,  32(I32)
;;								## 1
	c0    shl $r0.8 = $r0.8, 8   ## bblock 12, line 157,  t89,  t86,  8(SI32)
	c0    shl $r0.9 = $r0.9, 16   ## bblock 12, line 156,  t93,  t90,  16(SI32)
;;								## 2
	c0    or $r0.14 = $r0.14, $r0.9   ## bblock 12, line 157,  t1221,  t83,  t93
;;								## 3
	c0    or $r0.14 = $r0.14, $r0.8   ## bblock 12, line 157,  t94,  t1221,  t89
;;								## 4
	c0    stw 0[$r0.3] = $r0.14   ## bblock 12, line 155, t1222, t94
	c0    goto L6?3 ## goto
;;								## 5
.trace 9
L7?3:
	c0    add $r0.3 = $r0.44, 1   ## bblock 9, line 0,  t647,  t647,  1(I32)
	c0    add $r0.6 = $r0.6, 256   ## bblock 9, line 0,  t643,  t643,  256(I32)
	c0    add $r0.43 = $r0.43, 256   ## bblock 9, line 0,  t646,  t646,  256(I32)
	c0    goto L4?3 ## goto
;;								## 0
.trace 12
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 165,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
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
