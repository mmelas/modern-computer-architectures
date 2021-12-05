 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/modern-computer-architectures/configuration.mm -width 1 -c99inline -prefetch -mfinline -ms -mas_g -mas_G -O4 -o a.out"
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
	c0    cmpgt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 15,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L0?3   ## bblock 0, line 15,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 15,  t5,  ?2.1?2auto_size(I32),  t4
;;								## 2
.trace 2
L0?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 16,  t5,  ?2.1?2auto_size(I32),  t4
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
	c0    cmplt $b0.0 = $r0.3, $r0.4   ## bblock 0, line 21,  t19(I1),  t17,  t18
;;								## 0
	c0    brf $b0.0, L1?3   ## bblock 0, line 21,  t19(I1)
;;								## 1
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 2, line 21,  t5,  ?2.2?2auto_size(I32),  t4
;;								## 2
.trace 2
L1?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 1, line 22,  t5,  ?2.2?2auto_size(I32),  t4
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
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 24,  t1,  ?2.3?2auto_size(I32),  t0
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
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg()
main::
.trace 8
	c0    add $r0.1 = $r0.1, (-0x40)
;;								## 0
.call NOP, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = NOP   ## bblock 0, line 36,  raddr(NOP)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t62
;;								## 1
	c0    mov $r0.2 = (~0xfff)   ## bblock 1, line 0,  t2721,  (~0xfff)(I32)
	c0    mov $r0.3 = (grey_framebuffer + 0)   ## bblock 1, line 0,  t2720,  addr(grey_framebuffer?1.0)(P32)
	c0    ldw $r0.4 = 0x10[$r0.1]  ## restore ## t62
;;								## 2
;;								## 3
.trace 2
L2?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 2, line 60,  t3136(I1),  t2721,  0(SI32)
	c0    pft 128[$r0.3]   ## [spec] bblock 17, line 61,  t2720,  128(I32)
	c0    add $r0.2 = $r0.2, 32   ## [spec] bblock 17, line 0,  t2721,  t2721,  32(I32)
;;								## 0
	c0    brf $b0.0, L3?3   ## bblock 2, line 60,  t3136(I1)
;;								## 1
	c0    stw 0[$r0.3] = $r0.0   ## bblock 17, line 61, t2720, 0(SI32)
;;								## 2
	c0    stw 4[$r0.3] = $r0.0   ## bblock 17, line 61-1, t2720, 0(SI32)
;;								## 3
	c0    stw 8[$r0.3] = $r0.0   ## bblock 17, line 61-2, t2720, 0(SI32)
;;								## 4
	c0    stw 12[$r0.3] = $r0.0   ## bblock 17, line 61-3, t2720, 0(SI32)
;;								## 5
	c0    stw 16[$r0.3] = $r0.0   ## bblock 17, line 61-4, t2720, 0(SI32)
;;								## 6
	c0    stw 20[$r0.3] = $r0.0   ## bblock 17, line 61-5, t2720, 0(SI32)
;;								## 7
	c0    stw 24[$r0.3] = $r0.0   ## bblock 17, line 61-6, t2720, 0(SI32)
;;								## 8
	c0    stw 28[$r0.3] = $r0.0   ## bblock 17, line 61-7, t2720, 0(SI32)
;;								## 9
	c0    stw 32[$r0.3] = $r0.0   ## bblock 17, line 61-8, t2720, 0(SI32)
;;								## 10
	c0    stw 36[$r0.3] = $r0.0   ## bblock 17, line 61-9, t2720, 0(SI32)
;;								## 11
	c0    stw 40[$r0.3] = $r0.0   ## bblock 17, line 61-10, t2720, 0(SI32)
;;								## 12
	c0    stw 44[$r0.3] = $r0.0   ## bblock 17, line 61-11, t2720, 0(SI32)
;;								## 13
	c0    stw 48[$r0.3] = $r0.0   ## bblock 17, line 61-12, t2720, 0(SI32)
;;								## 14
	c0    stw 52[$r0.3] = $r0.0   ## bblock 17, line 61-13, t2720, 0(SI32)
;;								## 15
	c0    stw 56[$r0.3] = $r0.0   ## bblock 17, line 61-14, t2720, 0(SI32)
;;								## 16
	c0    stw 60[$r0.3] = $r0.0   ## bblock 17, line 61-15, t2720, 0(SI32)
;;								## 17
	c0    stw 64[$r0.3] = $r0.0   ## bblock 17, line 61-16, t2720, 0(SI32)
;;								## 18
	c0    stw 68[$r0.3] = $r0.0   ## bblock 17, line 61-17, t2720, 0(SI32)
;;								## 19
	c0    stw 72[$r0.3] = $r0.0   ## bblock 17, line 61-18, t2720, 0(SI32)
;;								## 20
	c0    stw 76[$r0.3] = $r0.0   ## bblock 17, line 61-19, t2720, 0(SI32)
;;								## 21
	c0    stw 80[$r0.3] = $r0.0   ## bblock 17, line 61-20, t2720, 0(SI32)
;;								## 22
	c0    stw 84[$r0.3] = $r0.0   ## bblock 17, line 61-21, t2720, 0(SI32)
;;								## 23
	c0    stw 88[$r0.3] = $r0.0   ## bblock 17, line 61-22, t2720, 0(SI32)
;;								## 24
	c0    stw 92[$r0.3] = $r0.0   ## bblock 17, line 61-23, t2720, 0(SI32)
;;								## 25
	c0    stw 96[$r0.3] = $r0.0   ## bblock 17, line 61-24, t2720, 0(SI32)
;;								## 26
	c0    stw 100[$r0.3] = $r0.0   ## bblock 17, line 61-25, t2720, 0(SI32)
;;								## 27
	c0    stw 104[$r0.3] = $r0.0   ## bblock 17, line 61-26, t2720, 0(SI32)
;;								## 28
	c0    stw 108[$r0.3] = $r0.0   ## bblock 17, line 61-27, t2720, 0(SI32)
;;								## 29
	c0    stw 112[$r0.3] = $r0.0   ## bblock 17, line 61-28, t2720, 0(SI32)
;;								## 30
	c0    stw 116[$r0.3] = $r0.0   ## bblock 17, line 61-29, t2720, 0(SI32)
;;								## 31
	c0    stw 120[$r0.3] = $r0.0   ## bblock 17, line 61-30, t2720, 0(SI32)
;;								## 32
	c0    stw 124[$r0.3] = $r0.0   ## bblock 17, line 61-31, t2720, 0(SI32)
	c0    add $r0.3 = $r0.3, 128   ## bblock 17, line 0,  t2720,  t2720,  128(I32)
	c0    goto L2?3 ## goto
;;								## 33
.trace 9
L3?3:
	c0    mov $r0.3 = (~0x3f)   ## bblock 3, line 0,  t1986,  (~0x3f)(I32)
	c0    mov $r0.6 = (grey_framebuffer + 0)   ## bblock 3, line 0,  t1953,  addr(grey_framebuffer?1.0)(P32)
	c0    mov $r0.7 = (grey_image + 0)   ## bblock 3, line 0,  t1985,  addr(grey_image?1.0)(P32)
	c0    stw 0x10[$r0.1] = $r0.4  ## spill ## t62
;;								## 0
	c0    stw 0x14[$r0.1] = $r0.58  ## spill ## t67
;;								## 1
	c0    stw 0x18[$r0.1] = $r0.59  ## spill ## t68
;;								## 2
	c0    stw 0x1c[$r0.1] = $r0.60  ## spill ## t69
;;								## 3
	c0    stw 0x20[$r0.1] = $r0.61  ## spill ## t70
;;								## 4
	c0    stw 0x24[$r0.1] = $r0.62  ## spill ## t71
;;								## 5
	c0    stw 0x28[$r0.1] = $r0.63  ## spill ## t72
;;								## 6
.trace 5
L4?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 4, line 70,  t3137(I1),  t1986,  0(SI32)
	c0    mov $r0.4 = (~0x3f)   ## [spec] bblock 7, line 0,  t963,  (~0x3f)(I32)
	c0    mov $r0.5 = $r0.6   ## [spec] bblock 7, line 0,  t961,  t1953
	c0    mov $r0.2 = $r0.7   ## [spec] bblock 7, line 0,  t962,  t1985
	c0    mov $r0.43 = $r0.3   ## t1986
	c0    mov $r0.44 = $r0.6   ## t1953
;;								## 0
	c0    mov $r0.45 = $r0.7   ## t1985
	c0    brf $b0.0, L5?3   ## bblock 4, line 70,  t3137(I1)
;;								## 1
.trace 1
L6?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 8, line 73,  t3138(I1),  t963,  0(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 10, line 76, t113, t962
	c0    add $r0.4 = $r0.4, 32   ## [spec] bblock 10, line 0,  t963,  t963,  32(I32)
;;								## 0
	c0    ldw.d $r0.6 = 4[$r0.2]   ## [spec] bblock 10, line 76-1, t787, t962
	c0    brf $b0.0, L7?3   ## bblock 8, line 73,  t3138(I1)
;;								## 1
	c0    and $r0.8 = $r0.3, 255   ## bblock 10, line 77,  t86,  t113,  255(I32)
	c0    shru $r0.7 = $r0.3, 8   ## bblock 10, line 77,  t31(I24),  t113,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77,  t34(I16),  t113,  16(SI32)
	c0    ldw $r0.9 = 8[$r0.2]   ## bblock 10, line 76-2, t767, t962
;;								## 2
	c0    and $r0.7 = $r0.7, 255   ## bblock 10, line 77,  t87,  t31(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77,  t90,  t34(I16),  255(I32)
	c0    and $r0.11 = $r0.6, 255   ## bblock 10, line 77-1,  t788,  t787,  255(I32)
	c0    shru $r0.10 = $r0.6, 8   ## bblock 10, line 77-1,  t789(I24),  t787,  8(SI32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-1,  t793(I16),  t787,  16(SI32)
	c0    ldw $r0.12 = 12[$r0.2]   ## bblock 10, line 76-3, t747, t962
;;								## 3
	c0    max $r0.8 = $r0.8, $r0.7   ## bblock 10, line 77,  t89,  t86,  t87
	c0    and $r0.10 = $r0.10, 255   ## bblock 10, line 77-1,  t790,  t789(I24),  255(I32)
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-1,  t794,  t793(I16),  255(I32)
	c0    and $r0.13 = $r0.9, 255   ## bblock 10, line 77-2,  t768,  t767,  255(I32)
	c0    shru $r0.7 = $r0.9, 8   ## bblock 10, line 77-2,  t769(I24),  t767,  8(SI32)
	c0    shru $r0.9 = $r0.9, 16   ## bblock 10, line 77-2,  t773(I16),  t767,  16(SI32)
;;								## 4
	c0    max $r0.8 = $r0.8, $r0.3   ## bblock 10, line 77,  t26,  t89,  t90
	c0    max $r0.11 = $r0.11, $r0.10   ## bblock 10, line 77-1,  t792,  t788,  t790
	c0    and $r0.7 = $r0.7, 255   ## bblock 10, line 77-2,  t770,  t769(I24),  255(I32)
	c0    and $r0.9 = $r0.9, 255   ## bblock 10, line 77-2,  t774,  t773(I16),  255(I32)
	c0    and $r0.10 = $r0.12, 255   ## bblock 10, line 77-3,  t748,  t747,  255(I32)
	c0    shru $r0.3 = $r0.12, 8   ## bblock 10, line 77-3,  t749(I24),  t747,  8(SI32)
;;								## 5
	c0    zxtb $r0.8 = $r0.8   ## bblock 10, line 77,  t41(I8),  t26
	c0    max $r0.11 = $r0.11, $r0.6   ## bblock 10, line 77-1,  t796,  t792,  t794
	c0    max $r0.13 = $r0.13, $r0.7   ## bblock 10, line 77-2,  t772,  t768,  t770
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-3,  t750,  t749(I24),  255(I32)
	c0    shru $r0.12 = $r0.12, 16   ## bblock 10, line 77-3,  t753(I16),  t747,  16(SI32)
	c0    ldw $r0.6 = 16[$r0.2]   ## bblock 10, line 76-4, t727, t962
;;								## 6
	c0    shl $r0.14 = $r0.8, 8   ## bblock 10, line 88,  t40,  t41(I8),  8(SI32)
	c0    shl $r0.7 = $r0.8, 16   ## bblock 10, line 88,  t42,  t41(I8),  16(SI32)
	c0    zxtb $r0.11 = $r0.11   ## bblock 10, line 77-1,  t798(I8),  t796
	c0    max $r0.13 = $r0.13, $r0.9   ## bblock 10, line 77-2,  t776,  t772,  t774
	c0    max $r0.10 = $r0.10, $r0.3   ## bblock 10, line 77-3,  t752,  t748,  t750
	c0    and $r0.12 = $r0.12, 255   ## bblock 10, line 77-3,  t754,  t753(I16),  255(I32)
;;								## 7
	c0    or $r0.8 = $r0.8, $r0.7   ## bblock 10, line 88,  t3139,  t41(I8),  t42
	c0    shl $r0.7 = $r0.11, 8   ## bblock 10, line 88-1,  t799,  t798(I8),  8(SI32)
	c0    shl $r0.3 = $r0.11, 16   ## bblock 10, line 88-1,  t800,  t798(I8),  16(SI32)
	c0    zxtb $r0.13 = $r0.13   ## bblock 10, line 77-2,  t778(I8),  t776
	c0    max $r0.10 = $r0.10, $r0.12   ## bblock 10, line 77-3,  t756,  t752,  t754
	c0    shru $r0.9 = $r0.6, 8   ## bblock 10, line 77-4,  t729(I24),  t727,  8(SI32)
;;								## 8
	c0    or $r0.8 = $r0.8, $r0.14   ## bblock 10, line 88,  t44,  t3139,  t40
	c0    or $r0.11 = $r0.11, $r0.3   ## bblock 10, line 88-1,  t3140,  t798(I8),  t800
	c0    shl $r0.12 = $r0.13, 8   ## bblock 10, line 88-2,  t779,  t778(I8),  8(SI32)
	c0    shl $r0.3 = $r0.13, 16   ## bblock 10, line 88-2,  t780,  t778(I8),  16(SI32)
	c0    zxtb $r0.10 = $r0.10   ## bblock 10, line 77-3,  t758(I8),  t756
	c0    and $r0.9 = $r0.9, 255   ## bblock 10, line 77-4,  t730,  t729(I24),  255(I32)
;;								## 9
	c0    or $r0.11 = $r0.11, $r0.7   ## bblock 10, line 88-1,  t801,  t3140,  t799
	c0    or $r0.13 = $r0.13, $r0.3   ## bblock 10, line 88-2,  t3141,  t778(I8),  t780
	c0    shl $r0.7 = $r0.10, 8   ## bblock 10, line 88-3,  t759,  t758(I8),  8(SI32)
	c0    shl $r0.3 = $r0.10, 16   ## bblock 10, line 88-3,  t760,  t758(I8),  16(SI32)
	c0    and $r0.14 = $r0.6, 255   ## bblock 10, line 77-4,  t728,  t727,  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-4,  t733(I16),  t727,  16(SI32)
;;								## 10
	c0    or $r0.13 = $r0.13, $r0.12   ## bblock 10, line 88-2,  t781,  t3141,  t779
	c0    or $r0.10 = $r0.10, $r0.3   ## bblock 10, line 88-3,  t3142,  t758(I8),  t760
	c0    max $r0.14 = $r0.14, $r0.9   ## bblock 10, line 77-4,  t732,  t728,  t730
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-4,  t734,  t733(I16),  255(I32)
	c0    ldw $r0.3 = 20[$r0.2]   ## bblock 10, line 76-5, t707, t962
;;								## 11
	c0    or $r0.10 = $r0.10, $r0.7   ## bblock 10, line 88-3,  t761,  t3142,  t759
	c0    max $r0.14 = $r0.14, $r0.6   ## bblock 10, line 77-4,  t736,  t732,  t734
	c0    ldw $r0.6 = 24[$r0.2]   ## bblock 10, line 76-6, t687, t962
;;								## 12
	c0    zxtb $r0.14 = $r0.14   ## bblock 10, line 77-4,  t738(I8),  t736
	c0    and $r0.9 = $r0.3, 255   ## bblock 10, line 77-5,  t708,  t707,  255(I32)
	c0    shru $r0.7 = $r0.3, 8   ## bblock 10, line 77-5,  t709(I24),  t707,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-5,  t713(I16),  t707,  16(SI32)
	c0    ldw $r0.12 = 28[$r0.2]   ## bblock 10, line 76-7, t667, t962
;;								## 13
	c0    shl $r0.16 = $r0.14, 8   ## bblock 10, line 88-4,  t739,  t738(I8),  8(SI32)
	c0    shl $r0.15 = $r0.14, 16   ## bblock 10, line 88-4,  t740,  t738(I8),  16(SI32)
	c0    and $r0.7 = $r0.7, 255   ## bblock 10, line 77-5,  t710,  t709(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-5,  t714,  t713(I16),  255(I32)
	c0    and $r0.18 = $r0.6, 255   ## bblock 10, line 77-6,  t688,  t687,  255(I32)
	c0    shru $r0.17 = $r0.6, 8   ## bblock 10, line 77-6,  t689(I24),  t687,  8(SI32)
;;								## 14
	c0    or $r0.14 = $r0.14, $r0.15   ## bblock 10, line 88-4,  t3143,  t738(I8),  t740
	c0    max $r0.9 = $r0.9, $r0.7   ## bblock 10, line 77-5,  t712,  t708,  t710
	c0    and $r0.17 = $r0.17, 255   ## bblock 10, line 77-6,  t690,  t689(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-6,  t693(I16),  t687,  16(SI32)
	c0    and $r0.15 = $r0.12, 255   ## bblock 10, line 77-7,  t668,  t667,  255(I32)
	c0    shru $r0.7 = $r0.12, 8   ## bblock 10, line 77-7,  t669(I24),  t667,  8(SI32)
;;								## 15
	c0    or $r0.14 = $r0.14, $r0.16   ## bblock 10, line 88-4,  t741,  t3143,  t739
	c0    max $r0.9 = $r0.9, $r0.3   ## bblock 10, line 77-5,  t716,  t712,  t714
	c0    max $r0.18 = $r0.18, $r0.17   ## bblock 10, line 77-6,  t692,  t688,  t690
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-6,  t694,  t693(I16),  255(I32)
	c0    and $r0.7 = $r0.7, 255   ## bblock 10, line 77-7,  t670,  t669(I24),  255(I32)
	c0    shru $r0.12 = $r0.12, 16   ## bblock 10, line 77-7,  t673(I16),  t667,  16(SI32)
;;								## 16
	c0    zxtb $r0.9 = $r0.9   ## bblock 10, line 77-5,  t718(I8),  t716
	c0    max $r0.18 = $r0.18, $r0.6   ## bblock 10, line 77-6,  t696,  t692,  t694
	c0    max $r0.15 = $r0.15, $r0.7   ## bblock 10, line 77-7,  t672,  t668,  t670
	c0    and $r0.12 = $r0.12, 255   ## bblock 10, line 77-7,  t674,  t673(I16),  255(I32)
	c0    ldw $r0.3 = 32[$r0.2]   ## bblock 10, line 76-8, t647, t962
;;								## 17
	c0    shl $r0.7 = $r0.9, 8   ## bblock 10, line 88-5,  t719,  t718(I8),  8(SI32)
	c0    shl $r0.6 = $r0.9, 16   ## bblock 10, line 88-5,  t720,  t718(I8),  16(SI32)
	c0    zxtb $r0.18 = $r0.18   ## bblock 10, line 77-6,  t698(I8),  t696
	c0    max $r0.15 = $r0.15, $r0.12   ## bblock 10, line 77-7,  t676,  t672,  t674
	c0    ldw $r0.12 = 36[$r0.2]   ## bblock 10, line 76-9, t627, t962
;;								## 18
	c0    or $r0.9 = $r0.9, $r0.6   ## bblock 10, line 88-5,  t3144,  t718(I8),  t720
	c0    shl $r0.16 = $r0.18, 8   ## bblock 10, line 88-6,  t699,  t698(I8),  8(SI32)
	c0    shl $r0.6 = $r0.18, 16   ## bblock 10, line 88-6,  t700,  t698(I8),  16(SI32)
	c0    zxtb $r0.15 = $r0.15   ## bblock 10, line 77-7,  t678(I8),  t676
	c0    and $r0.19 = $r0.3, 255   ## bblock 10, line 77-8,  t648,  t647,  255(I32)
	c0    shru $r0.17 = $r0.3, 8   ## bblock 10, line 77-8,  t649(I24),  t647,  8(SI32)
;;								## 19
	c0    or $r0.9 = $r0.9, $r0.7   ## bblock 10, line 88-5,  t721,  t3144,  t719
	c0    or $r0.18 = $r0.18, $r0.6   ## bblock 10, line 88-6,  t3145,  t698(I8),  t700
	c0    shl $r0.7 = $r0.15, 8   ## bblock 10, line 88-7,  t679,  t678(I8),  8(SI32)
	c0    shl $r0.6 = $r0.15, 16   ## bblock 10, line 88-7,  t680,  t678(I8),  16(SI32)
	c0    and $r0.17 = $r0.17, 255   ## bblock 10, line 77-8,  t650,  t649(I24),  255(I32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-8,  t653(I16),  t647,  16(SI32)
;;								## 20
	c0    or $r0.18 = $r0.18, $r0.16   ## bblock 10, line 88-6,  t701,  t3145,  t699
	c0    or $r0.15 = $r0.15, $r0.6   ## bblock 10, line 88-7,  t3146,  t678(I8),  t680
	c0    max $r0.19 = $r0.19, $r0.17   ## bblock 10, line 77-8,  t652,  t648,  t650
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-8,  t654,  t653(I16),  255(I32)
	c0    and $r0.16 = $r0.12, 255   ## bblock 10, line 77-9,  t628,  t627,  255(I32)
	c0    shru $r0.6 = $r0.12, 8   ## bblock 10, line 77-9,  t629(I24),  t627,  8(SI32)
;;								## 21
	c0    or $r0.15 = $r0.15, $r0.7   ## bblock 10, line 88-7,  t681,  t3146,  t679
	c0    max $r0.19 = $r0.19, $r0.3   ## bblock 10, line 77-8,  t656,  t652,  t654
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-9,  t630,  t629(I24),  255(I32)
	c0    shru $r0.12 = $r0.12, 16   ## bblock 10, line 77-9,  t633(I16),  t627,  16(SI32)
	c0    ldw $r0.3 = 40[$r0.2]   ## bblock 10, line 76-10, t607, t962
;;								## 22
	c0    zxtb $r0.19 = $r0.19   ## bblock 10, line 77-8,  t658(I8),  t656
	c0    max $r0.16 = $r0.16, $r0.6   ## bblock 10, line 77-9,  t632,  t628,  t630
	c0    and $r0.12 = $r0.12, 255   ## bblock 10, line 77-9,  t634,  t633(I16),  255(I32)
	c0    ldw $r0.6 = 44[$r0.2]   ## bblock 10, line 76-11, t587, t962
;;								## 23
	c0    shl $r0.17 = $r0.19, 8   ## bblock 10, line 88-8,  t659,  t658(I8),  8(SI32)
	c0    shl $r0.7 = $r0.19, 16   ## bblock 10, line 88-8,  t660,  t658(I8),  16(SI32)
	c0    max $r0.16 = $r0.16, $r0.12   ## bblock 10, line 77-9,  t636,  t632,  t634
	c0    and $r0.20 = $r0.3, 255   ## bblock 10, line 77-10,  t608,  t607,  255(I32)
	c0    shru $r0.12 = $r0.3, 8   ## bblock 10, line 77-10,  t609(I24),  t607,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-10,  t613(I16),  t607,  16(SI32)
;;								## 24
	c0    or $r0.19 = $r0.19, $r0.7   ## bblock 10, line 88-8,  t3147,  t658(I8),  t660
	c0    zxtb $r0.16 = $r0.16   ## bblock 10, line 77-9,  t638(I8),  t636
	c0    and $r0.12 = $r0.12, 255   ## bblock 10, line 77-10,  t610,  t609(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-10,  t614,  t613(I16),  255(I32)
	c0    and $r0.21 = $r0.6, 255   ## bblock 10, line 77-11,  t588,  t587,  255(I32)
	c0    shru $r0.7 = $r0.6, 8   ## bblock 10, line 77-11,  t589(I24),  t587,  8(SI32)
;;								## 25
	c0    or $r0.19 = $r0.19, $r0.17   ## bblock 10, line 88-8,  t661,  t3147,  t659
	c0    shl $r0.22 = $r0.16, 8   ## bblock 10, line 88-9,  t639,  t638(I8),  8(SI32)
	c0    shl $r0.17 = $r0.16, 16   ## bblock 10, line 88-9,  t640,  t638(I8),  16(SI32)
	c0    max $r0.20 = $r0.20, $r0.12   ## bblock 10, line 77-10,  t612,  t608,  t610
	c0    and $r0.7 = $r0.7, 255   ## bblock 10, line 77-11,  t590,  t589(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-11,  t593(I16),  t587,  16(SI32)
;;								## 26
	c0    or $r0.16 = $r0.16, $r0.17   ## bblock 10, line 88-9,  t3148,  t638(I8),  t640
	c0    max $r0.20 = $r0.20, $r0.3   ## bblock 10, line 77-10,  t616,  t612,  t614
	c0    max $r0.21 = $r0.21, $r0.7   ## bblock 10, line 77-11,  t592,  t588,  t590
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-11,  t594,  t593(I16),  255(I32)
	c0    ldw $r0.3 = 48[$r0.2]   ## bblock 10, line 76-12, t567, t962
;;								## 27
	c0    or $r0.16 = $r0.16, $r0.22   ## bblock 10, line 88-9,  t641,  t3148,  t639
	c0    zxtb $r0.20 = $r0.20   ## bblock 10, line 77-10,  t618(I8),  t616
	c0    max $r0.21 = $r0.21, $r0.6   ## bblock 10, line 77-11,  t596,  t592,  t594
	c0    ldw $r0.6 = 52[$r0.2]   ## bblock 10, line 76-13, t547, t962
;;								## 28
	c0    shl $r0.12 = $r0.20, 8   ## bblock 10, line 88-10,  t619,  t618(I8),  8(SI32)
	c0    shl $r0.7 = $r0.20, 16   ## bblock 10, line 88-10,  t620,  t618(I8),  16(SI32)
	c0    zxtb $r0.21 = $r0.21   ## bblock 10, line 77-11,  t598(I8),  t596
	c0    and $r0.22 = $r0.3, 255   ## bblock 10, line 77-12,  t568,  t567,  255(I32)
	c0    shru $r0.17 = $r0.3, 8   ## bblock 10, line 77-12,  t569(I24),  t567,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-12,  t573(I16),  t567,  16(SI32)
;;								## 29
	c0    or $r0.20 = $r0.20, $r0.7   ## bblock 10, line 88-10,  t3149,  t618(I8),  t620
	c0    shl $r0.23 = $r0.21, 8   ## bblock 10, line 88-11,  t599,  t598(I8),  8(SI32)
	c0    shl $r0.7 = $r0.21, 16   ## bblock 10, line 88-11,  t600,  t598(I8),  16(SI32)
	c0    and $r0.17 = $r0.17, 255   ## bblock 10, line 77-12,  t570,  t569(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-12,  t574,  t573(I16),  255(I32)
	c0    shru $r0.24 = $r0.6, 8   ## bblock 10, line 77-13,  t549(I24),  t547,  8(SI32)
;;								## 30
	c0    or $r0.20 = $r0.20, $r0.12   ## bblock 10, line 88-10,  t621,  t3149,  t619
	c0    or $r0.21 = $r0.21, $r0.7   ## bblock 10, line 88-11,  t3150,  t598(I8),  t600
	c0    max $r0.22 = $r0.22, $r0.17   ## bblock 10, line 77-12,  t572,  t568,  t570
	c0    and $r0.7 = $r0.6, 255   ## bblock 10, line 77-13,  t548,  t547,  255(I32)
	c0    and $r0.24 = $r0.24, 255   ## bblock 10, line 77-13,  t550,  t549(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-13,  t553(I16),  t547,  16(SI32)
;;								## 31
	c0    or $r0.21 = $r0.21, $r0.23   ## bblock 10, line 88-11,  t601,  t3150,  t599
	c0    max $r0.22 = $r0.22, $r0.3   ## bblock 10, line 77-12,  t576,  t572,  t574
	c0    max $r0.7 = $r0.7, $r0.24   ## bblock 10, line 77-13,  t552,  t548,  t550
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-13,  t554,  t553(I16),  255(I32)
	c0    ldw $r0.3 = 56[$r0.2]   ## bblock 10, line 76-14, t527, t962
;;								## 32
	c0    zxtb $r0.22 = $r0.22   ## bblock 10, line 77-12,  t578(I8),  t576
	c0    max $r0.7 = $r0.7, $r0.6   ## bblock 10, line 77-13,  t556,  t552,  t554
	c0    ldw $r0.6 = 60[$r0.2]   ## bblock 10, line 76-15, t507, t962
;;								## 33
	c0    shl $r0.17 = $r0.22, 8   ## bblock 10, line 88-12,  t579,  t578(I8),  8(SI32)
	c0    shl $r0.12 = $r0.22, 16   ## bblock 10, line 88-12,  t580,  t578(I8),  16(SI32)
	c0    zxtb $r0.7 = $r0.7   ## bblock 10, line 77-13,  t558(I8),  t556
	c0    and $r0.24 = $r0.3, 255   ## bblock 10, line 77-14,  t528,  t527,  255(I32)
	c0    shru $r0.23 = $r0.3, 8   ## bblock 10, line 77-14,  t529(I24),  t527,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-14,  t533(I16),  t527,  16(SI32)
;;								## 34
	c0    or $r0.22 = $r0.22, $r0.12   ## bblock 10, line 88-12,  t3151,  t578(I8),  t580
	c0    shl $r0.25 = $r0.7, 8   ## bblock 10, line 88-13,  t559,  t558(I8),  8(SI32)
	c0    shl $r0.12 = $r0.7, 16   ## bblock 10, line 88-13,  t560,  t558(I8),  16(SI32)
	c0    and $r0.23 = $r0.23, 255   ## bblock 10, line 77-14,  t530,  t529(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-14,  t534,  t533(I16),  255(I32)
	c0    shru $r0.26 = $r0.6, 8   ## bblock 10, line 77-15,  t509(I24),  t507,  8(SI32)
;;								## 35
	c0    or $r0.22 = $r0.22, $r0.17   ## bblock 10, line 88-12,  t581,  t3151,  t579
	c0    or $r0.7 = $r0.7, $r0.12   ## bblock 10, line 88-13,  t3152,  t558(I8),  t560
	c0    max $r0.24 = $r0.24, $r0.23   ## bblock 10, line 77-14,  t532,  t528,  t530
	c0    and $r0.12 = $r0.6, 255   ## bblock 10, line 77-15,  t508,  t507,  255(I32)
	c0    and $r0.26 = $r0.26, 255   ## bblock 10, line 77-15,  t510,  t509(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-15,  t513(I16),  t507,  16(SI32)
;;								## 36
	c0    or $r0.7 = $r0.7, $r0.25   ## bblock 10, line 88-13,  t561,  t3152,  t559
	c0    max $r0.24 = $r0.24, $r0.3   ## bblock 10, line 77-14,  t536,  t532,  t534
	c0    max $r0.12 = $r0.12, $r0.26   ## bblock 10, line 77-15,  t512,  t508,  t510
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-15,  t514,  t513(I16),  255(I32)
	c0    ldw $r0.3 = 64[$r0.2]   ## bblock 10, line 76-16, t487, t962
;;								## 37
	c0    zxtb $r0.24 = $r0.24   ## bblock 10, line 77-14,  t538(I8),  t536
	c0    max $r0.12 = $r0.12, $r0.6   ## bblock 10, line 77-15,  t516,  t512,  t514
	c0    ldw $r0.6 = 68[$r0.2]   ## bblock 10, line 76-17, t467, t962
;;								## 38
	c0    shl $r0.23 = $r0.24, 8   ## bblock 10, line 88-14,  t539,  t538(I8),  8(SI32)
	c0    shl $r0.17 = $r0.24, 16   ## bblock 10, line 88-14,  t540,  t538(I8),  16(SI32)
	c0    zxtb $r0.12 = $r0.12   ## bblock 10, line 77-15,  t518(I8),  t516
	c0    and $r0.26 = $r0.3, 255   ## bblock 10, line 77-16,  t488,  t487,  255(I32)
	c0    shru $r0.25 = $r0.3, 8   ## bblock 10, line 77-16,  t489(I24),  t487,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-16,  t493(I16),  t487,  16(SI32)
;;								## 39
	c0    or $r0.24 = $r0.24, $r0.17   ## bblock 10, line 88-14,  t3153,  t538(I8),  t540
	c0    shl $r0.27 = $r0.12, 8   ## bblock 10, line 88-15,  t519,  t518(I8),  8(SI32)
	c0    shl $r0.17 = $r0.12, 16   ## bblock 10, line 88-15,  t520,  t518(I8),  16(SI32)
	c0    and $r0.25 = $r0.25, 255   ## bblock 10, line 77-16,  t490,  t489(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-16,  t494,  t493(I16),  255(I32)
	c0    shru $r0.28 = $r0.6, 8   ## bblock 10, line 77-17,  t469(I24),  t467,  8(SI32)
;;								## 40
	c0    or $r0.24 = $r0.24, $r0.23   ## bblock 10, line 88-14,  t541,  t3153,  t539
	c0    or $r0.12 = $r0.12, $r0.17   ## bblock 10, line 88-15,  t3154,  t518(I8),  t520
	c0    max $r0.26 = $r0.26, $r0.25   ## bblock 10, line 77-16,  t492,  t488,  t490
	c0    and $r0.17 = $r0.6, 255   ## bblock 10, line 77-17,  t468,  t467,  255(I32)
	c0    and $r0.28 = $r0.28, 255   ## bblock 10, line 77-17,  t470,  t469(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-17,  t473(I16),  t467,  16(SI32)
;;								## 41
	c0    or $r0.12 = $r0.12, $r0.27   ## bblock 10, line 88-15,  t521,  t3154,  t519
	c0    max $r0.26 = $r0.26, $r0.3   ## bblock 10, line 77-16,  t496,  t492,  t494
	c0    max $r0.17 = $r0.17, $r0.28   ## bblock 10, line 77-17,  t472,  t468,  t470
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-17,  t474,  t473(I16),  255(I32)
	c0    ldw $r0.3 = 72[$r0.2]   ## bblock 10, line 76-18, t447, t962
;;								## 42
	c0    zxtb $r0.26 = $r0.26   ## bblock 10, line 77-16,  t498(I8),  t496
	c0    max $r0.17 = $r0.17, $r0.6   ## bblock 10, line 77-17,  t476,  t472,  t474
	c0    ldw $r0.6 = 76[$r0.2]   ## bblock 10, line 76-19, t427, t962
;;								## 43
	c0    shl $r0.25 = $r0.26, 8   ## bblock 10, line 88-16,  t499,  t498(I8),  8(SI32)
	c0    shl $r0.23 = $r0.26, 16   ## bblock 10, line 88-16,  t500,  t498(I8),  16(SI32)
	c0    zxtb $r0.17 = $r0.17   ## bblock 10, line 77-17,  t478(I8),  t476
	c0    and $r0.28 = $r0.3, 255   ## bblock 10, line 77-18,  t448,  t447,  255(I32)
	c0    shru $r0.27 = $r0.3, 8   ## bblock 10, line 77-18,  t449(I24),  t447,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-18,  t453(I16),  t447,  16(SI32)
;;								## 44
	c0    or $r0.26 = $r0.26, $r0.23   ## bblock 10, line 88-16,  t3155,  t498(I8),  t500
	c0    shl $r0.29 = $r0.17, 8   ## bblock 10, line 88-17,  t479,  t478(I8),  8(SI32)
	c0    shl $r0.23 = $r0.17, 16   ## bblock 10, line 88-17,  t480,  t478(I8),  16(SI32)
	c0    and $r0.27 = $r0.27, 255   ## bblock 10, line 77-18,  t450,  t449(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-18,  t454,  t453(I16),  255(I32)
	c0    shru $r0.30 = $r0.6, 8   ## bblock 10, line 77-19,  t429(I24),  t427,  8(SI32)
;;								## 45
	c0    or $r0.26 = $r0.26, $r0.25   ## bblock 10, line 88-16,  t501,  t3155,  t499
	c0    or $r0.17 = $r0.17, $r0.23   ## bblock 10, line 88-17,  t3156,  t478(I8),  t480
	c0    max $r0.28 = $r0.28, $r0.27   ## bblock 10, line 77-18,  t452,  t448,  t450
	c0    and $r0.23 = $r0.6, 255   ## bblock 10, line 77-19,  t428,  t427,  255(I32)
	c0    and $r0.30 = $r0.30, 255   ## bblock 10, line 77-19,  t430,  t429(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-19,  t433(I16),  t427,  16(SI32)
;;								## 46
	c0    or $r0.17 = $r0.17, $r0.29   ## bblock 10, line 88-17,  t481,  t3156,  t479
	c0    max $r0.28 = $r0.28, $r0.3   ## bblock 10, line 77-18,  t456,  t452,  t454
	c0    max $r0.23 = $r0.23, $r0.30   ## bblock 10, line 77-19,  t432,  t428,  t430
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-19,  t434,  t433(I16),  255(I32)
	c0    ldw $r0.3 = 80[$r0.2]   ## bblock 10, line 76-20, t407, t962
;;								## 47
	c0    zxtb $r0.28 = $r0.28   ## bblock 10, line 77-18,  t458(I8),  t456
	c0    max $r0.23 = $r0.23, $r0.6   ## bblock 10, line 77-19,  t436,  t432,  t434
	c0    ldw $r0.6 = 84[$r0.2]   ## bblock 10, line 76-21, t387, t962
;;								## 48
	c0    shl $r0.27 = $r0.28, 8   ## bblock 10, line 88-18,  t459,  t458(I8),  8(SI32)
	c0    shl $r0.25 = $r0.28, 16   ## bblock 10, line 88-18,  t460,  t458(I8),  16(SI32)
	c0    zxtb $r0.23 = $r0.23   ## bblock 10, line 77-19,  t438(I8),  t436
	c0    and $r0.30 = $r0.3, 255   ## bblock 10, line 77-20,  t408,  t407,  255(I32)
	c0    shru $r0.29 = $r0.3, 8   ## bblock 10, line 77-20,  t409(I24),  t407,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-20,  t413(I16),  t407,  16(SI32)
;;								## 49
	c0    or $r0.28 = $r0.28, $r0.25   ## bblock 10, line 88-18,  t3157,  t458(I8),  t460
	c0    shl $r0.31 = $r0.23, 8   ## bblock 10, line 88-19,  t439,  t438(I8),  8(SI32)
	c0    shl $r0.25 = $r0.23, 16   ## bblock 10, line 88-19,  t440,  t438(I8),  16(SI32)
	c0    and $r0.29 = $r0.29, 255   ## bblock 10, line 77-20,  t410,  t409(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-20,  t414,  t413(I16),  255(I32)
	c0    shru $r0.32 = $r0.6, 8   ## bblock 10, line 77-21,  t389(I24),  t387,  8(SI32)
;;								## 50
	c0    or $r0.28 = $r0.28, $r0.27   ## bblock 10, line 88-18,  t461,  t3157,  t459
	c0    or $r0.23 = $r0.23, $r0.25   ## bblock 10, line 88-19,  t3158,  t438(I8),  t440
	c0    max $r0.30 = $r0.30, $r0.29   ## bblock 10, line 77-20,  t412,  t408,  t410
	c0    and $r0.25 = $r0.6, 255   ## bblock 10, line 77-21,  t388,  t387,  255(I32)
	c0    and $r0.32 = $r0.32, 255   ## bblock 10, line 77-21,  t390,  t389(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-21,  t393(I16),  t387,  16(SI32)
;;								## 51
	c0    or $r0.23 = $r0.23, $r0.31   ## bblock 10, line 88-19,  t441,  t3158,  t439
	c0    max $r0.30 = $r0.30, $r0.3   ## bblock 10, line 77-20,  t416,  t412,  t414
	c0    max $r0.25 = $r0.25, $r0.32   ## bblock 10, line 77-21,  t392,  t388,  t390
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-21,  t394,  t393(I16),  255(I32)
	c0    ldw $r0.3 = 88[$r0.2]   ## bblock 10, line 76-22, t367, t962
;;								## 52
	c0    zxtb $r0.30 = $r0.30   ## bblock 10, line 77-20,  t418(I8),  t416
	c0    max $r0.25 = $r0.25, $r0.6   ## bblock 10, line 77-21,  t396,  t392,  t394
	c0    ldw $r0.6 = 92[$r0.2]   ## bblock 10, line 76-23, t347, t962
;;								## 53
	c0    shl $r0.29 = $r0.30, 8   ## bblock 10, line 88-20,  t419,  t418(I8),  8(SI32)
	c0    shl $r0.27 = $r0.30, 16   ## bblock 10, line 88-20,  t420,  t418(I8),  16(SI32)
	c0    zxtb $r0.25 = $r0.25   ## bblock 10, line 77-21,  t398(I8),  t396
	c0    and $r0.32 = $r0.3, 255   ## bblock 10, line 77-22,  t368,  t367,  255(I32)
	c0    shru $r0.31 = $r0.3, 8   ## bblock 10, line 77-22,  t369(I24),  t367,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-22,  t373(I16),  t367,  16(SI32)
;;								## 54
	c0    or $r0.30 = $r0.30, $r0.27   ## bblock 10, line 88-20,  t3159,  t418(I8),  t420
	c0    shl $r0.33 = $r0.25, 8   ## bblock 10, line 88-21,  t399,  t398(I8),  8(SI32)
	c0    shl $r0.27 = $r0.25, 16   ## bblock 10, line 88-21,  t400,  t398(I8),  16(SI32)
	c0    and $r0.31 = $r0.31, 255   ## bblock 10, line 77-22,  t370,  t369(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-22,  t374,  t373(I16),  255(I32)
	c0    shru $r0.34 = $r0.6, 8   ## bblock 10, line 77-23,  t349(I24),  t347,  8(SI32)
;;								## 55
	c0    or $r0.30 = $r0.30, $r0.29   ## bblock 10, line 88-20,  t421,  t3159,  t419
	c0    or $r0.25 = $r0.25, $r0.27   ## bblock 10, line 88-21,  t3160,  t398(I8),  t400
	c0    max $r0.32 = $r0.32, $r0.31   ## bblock 10, line 77-22,  t372,  t368,  t370
	c0    and $r0.27 = $r0.6, 255   ## bblock 10, line 77-23,  t348,  t347,  255(I32)
	c0    and $r0.34 = $r0.34, 255   ## bblock 10, line 77-23,  t350,  t349(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-23,  t353(I16),  t347,  16(SI32)
;;								## 56
	c0    or $r0.25 = $r0.25, $r0.33   ## bblock 10, line 88-21,  t401,  t3160,  t399
	c0    max $r0.32 = $r0.32, $r0.3   ## bblock 10, line 77-22,  t376,  t372,  t374
	c0    max $r0.27 = $r0.27, $r0.34   ## bblock 10, line 77-23,  t352,  t348,  t350
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-23,  t354,  t353(I16),  255(I32)
	c0    ldw $r0.3 = 96[$r0.2]   ## bblock 10, line 76-24, t327, t962
;;								## 57
	c0    zxtb $r0.32 = $r0.32   ## bblock 10, line 77-22,  t378(I8),  t376
	c0    max $r0.27 = $r0.27, $r0.6   ## bblock 10, line 77-23,  t356,  t352,  t354
	c0    ldw $r0.6 = 100[$r0.2]   ## bblock 10, line 76-25, t307, t962
;;								## 58
	c0    shl $r0.31 = $r0.32, 8   ## bblock 10, line 88-22,  t379,  t378(I8),  8(SI32)
	c0    shl $r0.29 = $r0.32, 16   ## bblock 10, line 88-22,  t380,  t378(I8),  16(SI32)
	c0    zxtb $r0.27 = $r0.27   ## bblock 10, line 77-23,  t358(I8),  t356
	c0    and $r0.34 = $r0.3, 255   ## bblock 10, line 77-24,  t328,  t327,  255(I32)
	c0    shru $r0.33 = $r0.3, 8   ## bblock 10, line 77-24,  t329(I24),  t327,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-24,  t333(I16),  t327,  16(SI32)
;;								## 59
	c0    or $r0.32 = $r0.32, $r0.29   ## bblock 10, line 88-22,  t3161,  t378(I8),  t380
	c0    shl $r0.35 = $r0.27, 8   ## bblock 10, line 88-23,  t359,  t358(I8),  8(SI32)
	c0    shl $r0.29 = $r0.27, 16   ## bblock 10, line 88-23,  t360,  t358(I8),  16(SI32)
	c0    and $r0.33 = $r0.33, 255   ## bblock 10, line 77-24,  t330,  t329(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-24,  t334,  t333(I16),  255(I32)
	c0    shru $r0.36 = $r0.6, 8   ## bblock 10, line 77-25,  t309(I24),  t307,  8(SI32)
;;								## 60
	c0    or $r0.32 = $r0.32, $r0.31   ## bblock 10, line 88-22,  t381,  t3161,  t379
	c0    or $r0.27 = $r0.27, $r0.29   ## bblock 10, line 88-23,  t3162,  t358(I8),  t360
	c0    max $r0.34 = $r0.34, $r0.33   ## bblock 10, line 77-24,  t332,  t328,  t330
	c0    and $r0.29 = $r0.6, 255   ## bblock 10, line 77-25,  t308,  t307,  255(I32)
	c0    and $r0.36 = $r0.36, 255   ## bblock 10, line 77-25,  t310,  t309(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-25,  t313(I16),  t307,  16(SI32)
;;								## 61
	c0    or $r0.27 = $r0.27, $r0.35   ## bblock 10, line 88-23,  t361,  t3162,  t359
	c0    max $r0.34 = $r0.34, $r0.3   ## bblock 10, line 77-24,  t336,  t332,  t334
	c0    max $r0.29 = $r0.29, $r0.36   ## bblock 10, line 77-25,  t312,  t308,  t310
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-25,  t314,  t313(I16),  255(I32)
	c0    ldw $r0.3 = 104[$r0.2]   ## bblock 10, line 76-26, t287, t962
;;								## 62
	c0    zxtb $r0.34 = $r0.34   ## bblock 10, line 77-24,  t338(I8),  t336
	c0    max $r0.29 = $r0.29, $r0.6   ## bblock 10, line 77-25,  t316,  t312,  t314
	c0    ldw $r0.6 = 108[$r0.2]   ## bblock 10, line 76-27, t267, t962
;;								## 63
	c0    shl $r0.33 = $r0.34, 8   ## bblock 10, line 88-24,  t339,  t338(I8),  8(SI32)
	c0    shl $r0.31 = $r0.34, 16   ## bblock 10, line 88-24,  t340,  t338(I8),  16(SI32)
	c0    zxtb $r0.29 = $r0.29   ## bblock 10, line 77-25,  t318(I8),  t316
	c0    and $r0.36 = $r0.3, 255   ## bblock 10, line 77-26,  t288,  t287,  255(I32)
	c0    shru $r0.35 = $r0.3, 8   ## bblock 10, line 77-26,  t289(I24),  t287,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-26,  t293(I16),  t287,  16(SI32)
;;								## 64
	c0    or $r0.34 = $r0.34, $r0.31   ## bblock 10, line 88-24,  t3163,  t338(I8),  t340
	c0    shl $r0.37 = $r0.29, 8   ## bblock 10, line 88-25,  t319,  t318(I8),  8(SI32)
	c0    shl $r0.31 = $r0.29, 16   ## bblock 10, line 88-25,  t320,  t318(I8),  16(SI32)
	c0    and $r0.35 = $r0.35, 255   ## bblock 10, line 77-26,  t290,  t289(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-26,  t294,  t293(I16),  255(I32)
	c0    shru $r0.38 = $r0.6, 8   ## bblock 10, line 77-27,  t269(I24),  t267,  8(SI32)
;;								## 65
	c0    or $r0.34 = $r0.34, $r0.33   ## bblock 10, line 88-24,  t341,  t3163,  t339
	c0    or $r0.29 = $r0.29, $r0.31   ## bblock 10, line 88-25,  t3164,  t318(I8),  t320
	c0    max $r0.36 = $r0.36, $r0.35   ## bblock 10, line 77-26,  t292,  t288,  t290
	c0    and $r0.31 = $r0.6, 255   ## bblock 10, line 77-27,  t268,  t267,  255(I32)
	c0    and $r0.38 = $r0.38, 255   ## bblock 10, line 77-27,  t270,  t269(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-27,  t273(I16),  t267,  16(SI32)
;;								## 66
	c0    or $r0.29 = $r0.29, $r0.37   ## bblock 10, line 88-25,  t321,  t3164,  t319
	c0    max $r0.36 = $r0.36, $r0.3   ## bblock 10, line 77-26,  t296,  t292,  t294
	c0    max $r0.31 = $r0.31, $r0.38   ## bblock 10, line 77-27,  t272,  t268,  t270
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-27,  t274,  t273(I16),  255(I32)
	c0    ldw $r0.3 = 112[$r0.2]   ## bblock 10, line 76-28, t247, t962
;;								## 67
	c0    zxtb $r0.36 = $r0.36   ## bblock 10, line 77-26,  t298(I8),  t296
	c0    max $r0.31 = $r0.31, $r0.6   ## bblock 10, line 77-27,  t276,  t272,  t274
	c0    ldw $r0.6 = 116[$r0.2]   ## bblock 10, line 76-29, t227, t962
;;								## 68
	c0    shl $r0.35 = $r0.36, 8   ## bblock 10, line 88-26,  t299,  t298(I8),  8(SI32)
	c0    shl $r0.33 = $r0.36, 16   ## bblock 10, line 88-26,  t300,  t298(I8),  16(SI32)
	c0    zxtb $r0.31 = $r0.31   ## bblock 10, line 77-27,  t278(I8),  t276
	c0    and $r0.38 = $r0.3, 255   ## bblock 10, line 77-28,  t248,  t247,  255(I32)
	c0    shru $r0.37 = $r0.3, 8   ## bblock 10, line 77-28,  t249(I24),  t247,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-28,  t253(I16),  t247,  16(SI32)
;;								## 69
	c0    or $r0.36 = $r0.36, $r0.33   ## bblock 10, line 88-26,  t3165,  t298(I8),  t300
	c0    shl $r0.39 = $r0.31, 8   ## bblock 10, line 88-27,  t279,  t278(I8),  8(SI32)
	c0    shl $r0.33 = $r0.31, 16   ## bblock 10, line 88-27,  t280,  t278(I8),  16(SI32)
	c0    and $r0.37 = $r0.37, 255   ## bblock 10, line 77-28,  t250,  t249(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-28,  t254,  t253(I16),  255(I32)
	c0    shru $r0.40 = $r0.6, 8   ## bblock 10, line 77-29,  t229(I24),  t227,  8(SI32)
;;								## 70
	c0    or $r0.36 = $r0.36, $r0.35   ## bblock 10, line 88-26,  t301,  t3165,  t299
	c0    or $r0.31 = $r0.31, $r0.33   ## bblock 10, line 88-27,  t3166,  t278(I8),  t280
	c0    max $r0.38 = $r0.38, $r0.37   ## bblock 10, line 77-28,  t252,  t248,  t250
	c0    and $r0.33 = $r0.6, 255   ## bblock 10, line 77-29,  t228,  t227,  255(I32)
	c0    and $r0.40 = $r0.40, 255   ## bblock 10, line 77-29,  t230,  t229(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-29,  t233(I16),  t227,  16(SI32)
;;								## 71
	c0    or $r0.31 = $r0.31, $r0.39   ## bblock 10, line 88-27,  t281,  t3166,  t279
	c0    max $r0.38 = $r0.38, $r0.3   ## bblock 10, line 77-28,  t256,  t252,  t254
	c0    max $r0.33 = $r0.33, $r0.40   ## bblock 10, line 77-29,  t232,  t228,  t230
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-29,  t234,  t233(I16),  255(I32)
	c0    ldw $r0.3 = 120[$r0.2]   ## bblock 10, line 76-30, t204, t962
;;								## 72
	c0    zxtb $r0.38 = $r0.38   ## bblock 10, line 77-28,  t258(I8),  t256
	c0    max $r0.33 = $r0.33, $r0.6   ## bblock 10, line 77-29,  t236,  t232,  t234
	c0    ldw $r0.6 = 124[$r0.2]   ## bblock 10, line 76-31, t78, t962
;;								## 73
	c0    shl $r0.37 = $r0.38, 8   ## bblock 10, line 88-28,  t259,  t258(I8),  8(SI32)
	c0    shl $r0.35 = $r0.38, 16   ## bblock 10, line 88-28,  t260,  t258(I8),  16(SI32)
	c0    zxtb $r0.33 = $r0.33   ## bblock 10, line 77-29,  t238(I8),  t236
	c0    and $r0.40 = $r0.3, 255   ## bblock 10, line 77-30,  t208,  t204,  255(I32)
	c0    shru $r0.39 = $r0.3, 8   ## bblock 10, line 77-30,  t209(I24),  t204,  8(SI32)
	c0    shru $r0.3 = $r0.3, 16   ## bblock 10, line 77-30,  t213(I16),  t204,  16(SI32)
;;								## 74
	c0    or $r0.38 = $r0.38, $r0.35   ## bblock 10, line 88-28,  t3167,  t258(I8),  t260
	c0    shl $r0.41 = $r0.33, 8   ## bblock 10, line 88-29,  t239,  t238(I8),  8(SI32)
	c0    shl $r0.35 = $r0.33, 16   ## bblock 10, line 88-29,  t240,  t238(I8),  16(SI32)
	c0    and $r0.39 = $r0.39, 255   ## bblock 10, line 77-30,  t210,  t209(I24),  255(I32)
	c0    and $r0.3 = $r0.3, 255   ## bblock 10, line 77-30,  t214,  t213(I16),  255(I32)
	c0    shru $r0.42 = $r0.6, 8   ## bblock 10, line 77-31,  t121(I24),  t78,  8(SI32)
;;								## 75
	c0    or $r0.38 = $r0.38, $r0.37   ## bblock 10, line 88-28,  t261,  t3167,  t259
	c0    or $r0.33 = $r0.33, $r0.35   ## bblock 10, line 88-29,  t3168,  t238(I8),  t240
	c0    max $r0.40 = $r0.40, $r0.39   ## bblock 10, line 77-30,  t212,  t208,  t210
	c0    and $r0.35 = $r0.6, 255   ## bblock 10, line 77-31,  t117,  t78,  255(I32)
	c0    and $r0.42 = $r0.42, 255   ## bblock 10, line 77-31,  t125,  t121(I24),  255(I32)
	c0    shru $r0.6 = $r0.6, 16   ## bblock 10, line 77-31,  t137(I16),  t78,  16(SI32)
;;								## 76
	c0    stw 0[$r0.5] = $r0.8   ## bblock 10, line 89, t961, t44
	c0    or $r0.33 = $r0.33, $r0.41   ## bblock 10, line 88-29,  t241,  t3168,  t239
	c0    max $r0.40 = $r0.40, $r0.3   ## bblock 10, line 77-30,  t216,  t212,  t214
	c0    max $r0.35 = $r0.35, $r0.42   ## bblock 10, line 77-31,  t133,  t117,  t125
	c0    and $r0.6 = $r0.6, 255   ## bblock 10, line 77-31,  t141,  t137(I16),  255(I32)
;;								## 77
	c0    stw 4[$r0.5] = $r0.11   ## bblock 10, line 89-1, t961, t801
	c0    zxtb $r0.40 = $r0.40   ## bblock 10, line 77-30,  t218(I8),  t216
	c0    max $r0.35 = $r0.35, $r0.6   ## bblock 10, line 77-31,  t149,  t133,  t141
;;								## 78
	c0    stw 8[$r0.5] = $r0.13   ## bblock 10, line 89-2, t961, t781
	c0    shl $r0.6 = $r0.40, 8   ## bblock 10, line 88-30,  t219,  t218(I8),  8(SI32)
	c0    shl $r0.3 = $r0.40, 16   ## bblock 10, line 88-30,  t220,  t218(I8),  16(SI32)
	c0    zxtb $r0.35 = $r0.35   ## bblock 10, line 77-31,  t157(I8),  t149
;;								## 79
	c0    stw 12[$r0.5] = $r0.10   ## bblock 10, line 89-3, t961, t761
	c0    or $r0.40 = $r0.40, $r0.3   ## bblock 10, line 88-30,  t3169,  t218(I8),  t220
	c0    shl $r0.8 = $r0.35, 8   ## bblock 10, line 88-31,  t161,  t157(I8),  8(SI32)
	c0    shl $r0.3 = $r0.35, 16   ## bblock 10, line 88-31,  t165,  t157(I8),  16(SI32)
;;								## 80
	c0    stw 16[$r0.5] = $r0.14   ## bblock 10, line 89-4, t961, t741
	c0    or $r0.40 = $r0.40, $r0.6   ## bblock 10, line 88-30,  t221,  t3169,  t219
	c0    or $r0.35 = $r0.35, $r0.3   ## bblock 10, line 88-31,  t3170,  t157(I8),  t165
;;								## 81
	c0    stw 20[$r0.5] = $r0.9   ## bblock 10, line 89-5, t961, t721
	c0    or $r0.35 = $r0.35, $r0.8   ## bblock 10, line 88-31,  t169,  t3170,  t161
;;								## 82
	c0    stw 24[$r0.5] = $r0.18   ## bblock 10, line 89-6, t961, t701
;;								## 83
	c0    stw 28[$r0.5] = $r0.15   ## bblock 10, line 89-7, t961, t681
;;								## 84
	c0    stw 32[$r0.5] = $r0.19   ## bblock 10, line 89-8, t961, t661
;;								## 85
	c0    stw 36[$r0.5] = $r0.16   ## bblock 10, line 89-9, t961, t641
;;								## 86
	c0    stw 40[$r0.5] = $r0.20   ## bblock 10, line 89-10, t961, t621
;;								## 87
	c0    stw 44[$r0.5] = $r0.21   ## bblock 10, line 89-11, t961, t601
;;								## 88
	c0    stw 48[$r0.5] = $r0.22   ## bblock 10, line 89-12, t961, t581
;;								## 89
	c0    stw 52[$r0.5] = $r0.7   ## bblock 10, line 89-13, t961, t561
;;								## 90
	c0    stw 56[$r0.5] = $r0.24   ## bblock 10, line 89-14, t961, t541
;;								## 91
	c0    stw 60[$r0.5] = $r0.12   ## bblock 10, line 89-15, t961, t521
;;								## 92
	c0    stw 64[$r0.5] = $r0.26   ## bblock 10, line 89-16, t961, t501
;;								## 93
	c0    stw 68[$r0.5] = $r0.17   ## bblock 10, line 89-17, t961, t481
;;								## 94
	c0    stw 72[$r0.5] = $r0.28   ## bblock 10, line 89-18, t961, t461
;;								## 95
	c0    stw 76[$r0.5] = $r0.23   ## bblock 10, line 89-19, t961, t441
;;								## 96
	c0    stw 80[$r0.5] = $r0.30   ## bblock 10, line 89-20, t961, t421
;;								## 97
	c0    stw 84[$r0.5] = $r0.25   ## bblock 10, line 89-21, t961, t401
;;								## 98
	c0    stw 88[$r0.5] = $r0.32   ## bblock 10, line 89-22, t961, t381
;;								## 99
	c0    stw 92[$r0.5] = $r0.27   ## bblock 10, line 89-23, t961, t361
;;								## 100
	c0    stw 96[$r0.5] = $r0.34   ## bblock 10, line 89-24, t961, t341
;;								## 101
	c0    stw 100[$r0.5] = $r0.29   ## bblock 10, line 89-25, t961, t321
;;								## 102
	c0    stw 104[$r0.5] = $r0.36   ## bblock 10, line 89-26, t961, t301
;;								## 103
	c0    stw 108[$r0.5] = $r0.31   ## bblock 10, line 89-27, t961, t281
;;								## 104
	c0    stw 112[$r0.5] = $r0.38   ## bblock 10, line 89-28, t961, t261
;;								## 105
	c0    stw 116[$r0.5] = $r0.33   ## bblock 10, line 89-29, t961, t241
;;								## 106
	c0    stw 120[$r0.5] = $r0.40   ## bblock 10, line 89-30, t961, t221
;;								## 107
	c0    stw 124[$r0.5] = $r0.35   ## bblock 10, line 89-31, t961, t169
;;								## 108
	c0    pft 128[$r0.5]   ## bblock 10, line 89,  t961,  128(I32)
	c0    add $r0.5 = $r0.5, 128   ## bblock 10, line 0,  t961,  t961,  128(I32)
;;								## 109
	c0    pft 128[$r0.2]   ## bblock 10, line 76,  t962,  128(I32)
	c0    add $r0.2 = $r0.2, 128   ## bblock 10, line 0,  t962,  t962,  128(I32)
	c0    goto L6?3 ## goto
;;								## 110
.trace 6
L7?3:
	c0    add $r0.3 = $r0.43, 1   ## bblock 9, line 0,  t1986,  t1986,  1(I32)
	c0    add $r0.7 = $r0.45, 256   ## bblock 9, line 0,  t1985,  t1985,  256(I32)
;;								## 0
	c0    add $r0.6 = $r0.44, 256   ## bblock 9, line 0,  t1953,  t1953,  256(I32)
	c0    goto L4?3 ## goto
;;								## 1
.trace 7
L5?3:
.call puts, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = puts   ## bblock 5, line 105,  raddr(puts)(P32),  addr(_?1STRINGVAR.1)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t62
	      xnop 1
;;								## 2
	c0    ldw $r0.58 = 0x14[$r0.1]  ## restore ## t67
;;								## 3
	c0    ldw $r0.59 = 0x18[$r0.1]  ## restore ## t68
;;								## 4
	c0    ldw $r0.60 = 0x1c[$r0.1]  ## restore ## t69
;;								## 5
	c0    ldw $r0.61 = 0x20[$r0.1]  ## restore ## t70
;;								## 6
	c0    ldw $r0.62 = 0x24[$r0.1]  ## restore ## t71
;;								## 7
	c0    ldw $r0.63 = 0x28[$r0.1]  ## restore ## t72
;;								## 8
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 6, line 107,  t63,  ?2.4?2auto_size(I32),  t62
;;								## 9
.endp
.section .bss
.section .data
_?1STRINGPACKET.1:
    .data1 71
    .data1 114
    .data1 101
    .data1 121
    .data1 115
    .data1 99
    .data1 97
    .data1 108
    .data1 101
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
.equ ?2.4?2auto_size, 0x40
 ## End main
.section .bss
.section .data
.section .data
.comm grey_image, 0x4000, 4
.comm grey_framebuffer, 0x4000, 4
.section .text
.import NOP
.type NOP,@function
.import puts
.type puts,@function
