/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/modern-computer-architectures/configuration.mm -width 1 -c99inline -prefetch -mfinline -ms -mas_g -mas_G -O4 -o a.out" */

/********************************************/
/*         SYSTEM HEADER                    */
/********************************************/

extern int sim_mem_probe(volatile unsigned int);
extern unsigned int sim_mem_access32(volatile unsigned int);
extern unsigned short sim_mem_access16(volatile unsigned int);
extern unsigned char sim_mem_access8(volatile unsigned int);
extern unsigned long long sim_cycle_counter;
extern unsigned long long sim_stall_counter;
extern unsigned long long sim_branch_stall;
extern unsigned long long sim_bundle_index[];
extern unsigned long long sim_oper_counter;
extern unsigned long long sim_bnt_counter;
extern unsigned long long sim_btc_counter;
extern unsigned long long sim_btu_counter;
extern unsigned long long sim_nop_counter;
extern unsigned int mem_trace_ld(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_st(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_pf(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_lds(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_sts(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_pfs(unsigned int, unsigned int, unsigned int);
extern void sim_ta_init(int);
/*         TRACING HANDLES                */
#define __GOTO(x) /**/
#define __CALL(x) /**/
#define __ENTRY(x) /**/
#define __RETURN(x) /**/
#define __BRANCH(x) /**/
#define __BRANCHF(x) /**/
#define __LABEL(x) /**/
#define __INC_STALL_CNT() sim_stall_counter += sim_branch_stall
#define __INC_BNT_CNT() sim_bnt_counter++
#define __INC_BTC_CNT() sim_btc_counter++
#define __INC_BTU_CNT() sim_btu_counter++
#define __INC_NOP_CNT(n) sim_nop_counter += (n)
#define __INC_BUNDLE_CNT(index) sim_bundle_index[index]++
#define __ADD_CYCLES(cycles)  sim_cycle_counter += (cycles)

typedef struct
{
  char *name;
  int length;
  int init;
  int offset;
  int linesize;
  int rta;
} sim_fileinfo_t;

extern int sim_init_fileinfo(sim_fileinfo_t *);
extern void sim_icache_fetch(int, int);
extern void sim_gprof_enter(int *, char *f);
extern void sim_gprof_start(int *);
extern void sim_gprof_stop(int *);
extern void sim_gprof_exit(int *);
/***********************************************/
/*         MACHINE MODEL HEADER                */
/***********************************************/

#define __UINT8(s)  ((s) & 0xff)
#define __INT8(s)   (((int) ((s) << 24)) >> 24)
#define __UINT16(s) ((s) & 0xffff)
#define __INT16(s)  (((int) ((s) << 16)) >> 16)
#define __UINT32(s) ((unsigned int) (s))
#define __INT32(s)  ((int) (s))


 		 /*  MEMORY MACROS */

#define __ADDR8(a)  ((a) ^ 0x3)
#define __ADDR16(a) ((a) ^ 0x2)
#define __ADDR32(a) (a)
#define __MEM8(a) (*((volatile unsigned char  *)(__ADDR8(a))))
#define __MEM16(a) (*((volatile unsigned short *)(__ADDR16(a))))
#define __MEM32(a) (*((volatile unsigned int *)(__ADDR32(a))))
#define __MEMSPEC8(a) sim_mem_access8(__ADDR8(a))
#define __MEMSPEC16(a) sim_mem_access16(__ADDR16(a))
#define __MEMSPEC32(a) sim_mem_access32(__ADDR32(a))
#define __LDBs(t,s1) t = __INT8(__MEMSPEC8(s1))
#define __LDB(t,s1) t = __INT8(__MEM8(s1))
#define __LDBUs(t,s1) t = __UINT8(__MEMSPEC8(s1))
#define __LDBU(t,s1) t = __UINT8(__MEM8(s1))
#define __LDHs(t,s1) t = __INT16(__MEMSPEC16(s1))
#define __LDH(t,s1) t = __INT16(__MEM16(s1))
#define __LDHUs(t,s1) t = __UINT16(__MEMSPEC16(s1))
#define __LDHU(t,s1) t = __UINT16(__MEM16(s1))
#define __LDWs(t,s1) t = __INT32(__MEMSPEC32(s1))
#define __LDW(t,s1) t = __INT32(__MEM32(s1))
#define __STB(t,s1) __MEM8(t) = __UINT8(s1)
#define __STH(t,s1) __MEM16(t) = __UINT16(s1)
#define __STW(t,s1) __MEM32(t) = __UINT32(s1)


 		 /*  INSTRUCTION MACROS */

#define __MULL(t,s1,s2) t = (s1) * __INT16(s2)
#define __MULLU(t,s1,s2) t = (s1) * __UINT16(s2)
#define __MULH(t,s1,s2) t = (s1) * __INT16((s2) >> 16)
#define __MULHU(t,s1,s2) t = (s1) * __UINT16((s2) >> 16)
#define __MULHS(t,s1,s2) t = ((s1) * __UINT16((s2) >> 16)) << 16
#define __MULLL(t,s1,s2)  t = __INT16(s1) * __INT16(s2)
#define __MULLLU(t,s1,s2) t = __UINT16(s1) * __UINT16(s2)
#define __MULLH(t,s1,s2)  t = __INT16(s1) * __INT16((s2) >> 16)
#define __MULLHU(t,s1,s2) t = __UINT16(s1) * __UINT16((s2) >> 16)
#define __MULHH(t,s1,s2)  t = __INT16((s1) >> 16) * __INT16((s2) >> 16)
#define __MULHHU(t,s1,s2) t = __UINT16((s1) >> 16) * __UINT16((s2) >> 16)
#define __ADD(t,s1,s2) t = (s1) + (s2)
#define __AND(t,s1,s2) t = (s1) & (s2)
#define __ANDC(t,s1,s2) t = ~(s1) & (s2)
#define __ANDL(t,s1,s2) t = ((((s1) == 0) | ((s2) == 0)) ? 0 : 1)
#define __CMPEQ(t,s1,s2) t = ((s1) == (s2))
#define __CMPGE(t,s1,s2) t = ((int) (s1) >= (int) (s2))
#define __CMPGEU(t,s1,s2) t = ((unsigned int) (s1) >= (unsigned int) (s2))
#define __CMPGT(t,s1,s2) t = ((int) (s1) > (int) (s2))
#define __CMPGTU(t,s1,s2) t = ((unsigned int) (s1) > (unsigned int) (s2))
#define __CMPLE(t,s1,s2) t = ((int) (s1) <= (int) (s2))
#define __CMPLEU(t,s1,s2) t = ((unsigned int) (s1) <= (unsigned int) (s2))
#define __CMPLT(t,s1,s2) t = ((int) (s1) < (int) (s2))
#define __CMPLTU(t,s1,s2) t = ((unsigned int) (s1) < (unsigned int) (s2))
#define __CMPNE(t,s1,s2) t = ( (s1) !=  (s2))
#define __MAX(t,s1,s2) t = ((int) (s1) > (int) (s2)) ? (s1) : (s2)
#define __MAXU(t,s1,s2) t = ((unsigned int) (s1) > (unsigned int) (s2)) ? (s1) : (s2)
#define __MIN(t,s1,s2) t = ((int) (s1) < (int) (s2)) ? (s1) : (s2)
#define __MINU(t,s1,s2) t = ((unsigned int) (s1) < (unsigned int) (s2)) ? (s1) : (s2)
#define __MFB(t,s1) t = s1
#define __MFL(t,s1) t = s1
#define __MOV(t,s1) t = s1
#define __MTL(t,s1) t = s1
#define __MTB(t,s1) t = ((s1) == 0) ? 0 : 1
#define __MTBINV(t,s1) t = ((s1) == 0) ? 1 : 0
#define __MUL(t,s1,s2) t = (s1) * (s2)
#define __NANDL(t,s1,s2) t = (((s1) == 0) | ((s2) == 0)) ? 1 : 0
#define __NOP()
#define __NORL(t,s1,s2) t = (((s1) == 0) & ((s2) == 0)) ? 1 : 0
#define __ORL(t,s1,s2) t = (((s1) == 0) & ((s2) == 0)) ? 0 : 1
#define __OR(t,s1,s2) t = (s1) | (s2)
#define __ORC(t,s1,s2) t = (~(s1)) | (s2)
#define __PFT(s1) (s1)
#define __SBIT(t,s1,s2) t = (s1) | ((unsigned int) 1 << (s2))
#define __SBITF(t,s1,s2) t = (s1) & ~((unsigned int) 1 << (s2))
#define __SH1ADD(t,s1,s2) t = ((s1) << 1) + (s2)
#define __SH2ADD(t,s1,s2) t = ((s1) << 2) + (s2)
#define __SH3ADD(t,s1,s2) t = ((s1) << 3) + (s2)
#define __SH4ADD(t,s1,s2) t = ((s1) << 4) + (s2)
#define __SHL(t,s1,s2) t = ((int) (s1)) << (s2)
#define __SHR(t,s1,s2) t = ((int) (s1)) >> (s2)
#define __SHRU(t,s1,s2) t = ((unsigned int) (s1)) >> (s2)
#define __SLCT(t,s1,s2,s3) t = (unsigned int) (((s1) != 0) ? (s2) : (s3))
#define __SLCTF(t,s1,s2,s3) t = (unsigned int) (((s1) == 0) ? (s2) : (s3))
#define __SUB(t,s1,s2) t = (s1) - (s2)
#define __SXTB(t,s1) t = (unsigned int) (((signed int) ((s1) << 24)) >> 24)
#define __SXTH(t,s1) t = (unsigned int) (((signed int) ((s1) << 16)) >> 16)
#define __TBIT(t,s1,s2) t = ((s1) & ((unsigned int) 1 << (s2))) ? 1 : 0
#define __TBITF(t,s1,s2) t = ((s1) & ((unsigned int) 1 << (s2))) ? 0 : 1
#define __XNOP(s1)
#define __XOR(t,s1,s2) t = (s1) ^ (s2)
#define __ZXTB(t,s1) t = ((s1) & 0xff)
#define __ZXTH(t,s1) t = ((s1) & 0xffff)
#define __ADDCG(t,cout,s1,s2,cin) {\
    t = (s1) + (s2) + ((cin) & 0x1);\
    cout =   ((cin) & 0x1)\
           ? ((unsigned int) t <= (unsigned int) (s1))\
           : ((unsigned int) t <  (unsigned int) (s1));\
}
#define __DIVS(t,cout,s1,s2,cin) {\
    unsigned int tmp = ((s1) << 1) | (cin);\
    cout = (unsigned int) (s1) >> 31;\
    t = cout ? tmp + (s2) : tmp - (s2);\
}
static sim_fileinfo_t t_thisfile;
extern void sim_asm_op0(int, ...);
extern unsigned int sim_asm_op1(int, ...);
typedef struct { unsigned int n0,n1; } sim_asm2_t;
extern sim_asm2_t sim_asm_op2(int, ...);
typedef struct { unsigned int n0,n1,n2; } sim_asm3_t;
extern sim_asm3_t sim_asm_op3(int, ...);
typedef struct { unsigned int n0,n1,n2,n3; } sim_asm4_t;
extern sim_asm4_t sim_asm_op4(int, ...);

/*********************************
            BSS SYMBOLS
*********************************/

unsigned int grey_image[4096];
unsigned int grey_framebuffer[4096];

/*********************************
            ENTRY SYMBOLS
*********************************/

extern unsigned int max( unsigned int, unsigned int );
extern unsigned int min( unsigned int, unsigned int );
extern unsigned int NOP(  );
extern unsigned int __vex_main(  );
extern  puts(  );

/*********************************
            DATA SYMBOLS
*********************************/

static unsigned int _X1STRINGPACKETX1[5]; 
static unsigned int _X1STRINGPACKETX1[5] = { 
	0x47726579,
	0x7363616C,
	0x653A2073,
	0x75636365,
	0x73730A00
}; 


/*********************************
            TEXT
*********************************/
extern unsigned int sim_create_stack(unsigned int, unsigned int);
extern void sim_check_stack(unsigned int, unsigned int);
extern void sim_bad_label(int);
unsigned int reg_b0_0;
unsigned int reg_b0_1;
unsigned int reg_b0_2;
unsigned int reg_b0_3;
unsigned int reg_b0_4;
unsigned int reg_b0_5;
unsigned int reg_b0_6;
unsigned int reg_b0_7;
unsigned int reg_b0_8;
unsigned int reg_b0_9;
unsigned int reg_b0_10;
unsigned int reg_b0_11;
unsigned int reg_b0_12;
unsigned int reg_b0_13;
unsigned int reg_b0_14;
unsigned int reg_b0_15;
unsigned int reg_b1_0;
unsigned int reg_b1_1;
unsigned int reg_b1_2;
unsigned int reg_b1_3;
unsigned int reg_b1_4;
unsigned int reg_b1_5;
unsigned int reg_b1_6;
unsigned int reg_b1_7;
unsigned int reg_b1_8;
unsigned int reg_b1_9;
unsigned int reg_b1_10;
unsigned int reg_b1_11;
unsigned int reg_b1_12;
unsigned int reg_b1_13;
unsigned int reg_b1_14;
unsigned int reg_b1_15;
unsigned int reg_b2_0;
unsigned int reg_b2_1;
unsigned int reg_b2_2;
unsigned int reg_b2_3;
unsigned int reg_b2_4;
unsigned int reg_b2_5;
unsigned int reg_b2_6;
unsigned int reg_b2_7;
unsigned int reg_b2_8;
unsigned int reg_b2_9;
unsigned int reg_b2_10;
unsigned int reg_b2_11;
unsigned int reg_b2_12;
unsigned int reg_b2_13;
unsigned int reg_b2_14;
unsigned int reg_b2_15;
unsigned int reg_b3_0;
unsigned int reg_b3_1;
unsigned int reg_b3_2;
unsigned int reg_b3_3;
unsigned int reg_b3_4;
unsigned int reg_b3_5;
unsigned int reg_b3_6;
unsigned int reg_b3_7;
unsigned int reg_b3_8;
unsigned int reg_b3_9;
unsigned int reg_b3_10;
unsigned int reg_b3_11;
unsigned int reg_b3_12;
unsigned int reg_b3_13;
unsigned int reg_b3_14;
unsigned int reg_b3_15;
unsigned int reg_l0_0;
unsigned int reg_r0_0;
unsigned int reg_r0_1;
unsigned int reg_r0_2;
unsigned int reg_r0_3;
unsigned int reg_r0_4;
unsigned int reg_r0_5;
unsigned int reg_r0_6;
unsigned int reg_r0_7;
unsigned int reg_r0_8;
unsigned int reg_r0_9;
unsigned int reg_r0_10;
unsigned int reg_r0_11;
unsigned int reg_r0_12;
unsigned int reg_r0_13;
unsigned int reg_r0_14;
unsigned int reg_r0_15;
unsigned int reg_r0_16;
unsigned int reg_r0_17;
unsigned int reg_r0_18;
unsigned int reg_r0_19;
unsigned int reg_r0_20;
unsigned int reg_r0_21;
unsigned int reg_r0_22;
unsigned int reg_r0_23;
unsigned int reg_r0_24;
unsigned int reg_r0_25;
unsigned int reg_r0_26;
unsigned int reg_r0_27;
unsigned int reg_r0_28;
unsigned int reg_r0_29;
unsigned int reg_r0_30;
unsigned int reg_r0_31;
unsigned int reg_r0_32;
unsigned int reg_r0_33;
unsigned int reg_r0_34;
unsigned int reg_r0_35;
unsigned int reg_r0_36;
unsigned int reg_r0_37;
unsigned int reg_r0_38;
unsigned int reg_r0_39;
unsigned int reg_r0_40;
unsigned int reg_r0_41;
unsigned int reg_r0_42;
unsigned int reg_r0_43;
unsigned int reg_r0_44;
unsigned int reg_r0_45;
unsigned int reg_r0_46;
unsigned int reg_r0_47;
unsigned int reg_r0_48;
unsigned int reg_r0_49;
unsigned int reg_r0_50;
unsigned int reg_r0_51;
unsigned int reg_r0_52;
unsigned int reg_r0_53;
unsigned int reg_r0_54;
unsigned int reg_r0_55;
unsigned int reg_r0_56;
unsigned int reg_r0_57;
unsigned int reg_r0_58;
unsigned int reg_r0_59;
unsigned int reg_r0_60;
unsigned int reg_r0_61;
unsigned int reg_r0_62;
unsigned int reg_r0_63;
unsigned int reg_r0_64;
unsigned int reg_r0_65;
unsigned int reg_r0_66;
unsigned int reg_r0_67;
unsigned int reg_r0_68;
unsigned int reg_r0_69;
unsigned int reg_r0_70;
unsigned int reg_r0_71;
unsigned int reg_r0_72;
unsigned int reg_r0_73;
unsigned int reg_r0_74;
unsigned int reg_r0_75;
unsigned int reg_r0_76;
unsigned int reg_r0_77;
unsigned int reg_r0_78;
unsigned int reg_r0_79;
unsigned int reg_r0_80;
unsigned int reg_r0_81;
unsigned int reg_r0_82;
unsigned int reg_r0_83;
unsigned int reg_r0_84;
unsigned int reg_r0_85;
unsigned int reg_r0_86;
unsigned int reg_r0_87;
unsigned int reg_r0_88;
unsigned int reg_r0_89;
unsigned int reg_r0_90;
unsigned int reg_r0_91;
unsigned int reg_r0_92;
unsigned int reg_r0_93;
unsigned int reg_r0_94;
unsigned int reg_r0_95;
unsigned int reg_r0_96;
unsigned int reg_r0_97;
unsigned int reg_r0_98;
unsigned int reg_r0_99;
unsigned int reg_r0_100;
unsigned int reg_r0_101;
unsigned int reg_r0_102;
unsigned int reg_r0_103;
unsigned int reg_r0_104;
unsigned int reg_r0_105;
unsigned int reg_r0_106;
unsigned int reg_r0_107;
unsigned int reg_r0_108;
unsigned int reg_r0_109;
unsigned int reg_r0_110;
unsigned int reg_r0_111;
unsigned int reg_r0_112;
unsigned int reg_r0_113;
unsigned int reg_r0_114;
unsigned int reg_r0_115;
unsigned int reg_r0_116;
unsigned int reg_r0_117;
unsigned int reg_r0_118;
unsigned int reg_r0_119;
unsigned int reg_r0_120;
unsigned int reg_r0_121;
unsigned int reg_r0_122;
unsigned int reg_r0_123;
unsigned int reg_r0_124;
unsigned int reg_r0_125;
unsigned int reg_r0_126;
unsigned int reg_r0_127;
unsigned int reg_r1_0;
unsigned int reg_r1_1;
unsigned int reg_r1_2;
unsigned int reg_r1_3;
unsigned int reg_r1_4;
unsigned int reg_r1_5;
unsigned int reg_r1_6;
unsigned int reg_r1_7;
unsigned int reg_r1_8;
unsigned int reg_r1_9;
unsigned int reg_r1_10;
unsigned int reg_r1_11;
unsigned int reg_r1_12;
unsigned int reg_r1_13;
unsigned int reg_r1_14;
unsigned int reg_r1_15;
unsigned int reg_r1_16;
unsigned int reg_r1_17;
unsigned int reg_r1_18;
unsigned int reg_r1_19;
unsigned int reg_r1_20;
unsigned int reg_r1_21;
unsigned int reg_r1_22;
unsigned int reg_r1_23;
unsigned int reg_r1_24;
unsigned int reg_r1_25;
unsigned int reg_r1_26;
unsigned int reg_r1_27;
unsigned int reg_r1_28;
unsigned int reg_r1_29;
unsigned int reg_r1_30;
unsigned int reg_r1_31;
unsigned int reg_r1_32;
unsigned int reg_r1_33;
unsigned int reg_r1_34;
unsigned int reg_r1_35;
unsigned int reg_r1_36;
unsigned int reg_r1_37;
unsigned int reg_r1_38;
unsigned int reg_r1_39;
unsigned int reg_r1_40;
unsigned int reg_r1_41;
unsigned int reg_r1_42;
unsigned int reg_r1_43;
unsigned int reg_r1_44;
unsigned int reg_r1_45;
unsigned int reg_r1_46;
unsigned int reg_r1_47;
unsigned int reg_r1_48;
unsigned int reg_r1_49;
unsigned int reg_r1_50;
unsigned int reg_r1_51;
unsigned int reg_r1_52;
unsigned int reg_r1_53;
unsigned int reg_r1_54;
unsigned int reg_r1_55;
unsigned int reg_r1_56;
unsigned int reg_r1_57;
unsigned int reg_r1_58;
unsigned int reg_r1_59;
unsigned int reg_r1_60;
unsigned int reg_r1_61;
unsigned int reg_r1_62;
unsigned int reg_r1_63;
unsigned int reg_r1_64;
unsigned int reg_r1_65;
unsigned int reg_r1_66;
unsigned int reg_r1_67;
unsigned int reg_r1_68;
unsigned int reg_r1_69;
unsigned int reg_r1_70;
unsigned int reg_r1_71;
unsigned int reg_r1_72;
unsigned int reg_r1_73;
unsigned int reg_r1_74;
unsigned int reg_r1_75;
unsigned int reg_r1_76;
unsigned int reg_r1_77;
unsigned int reg_r1_78;
unsigned int reg_r1_79;
unsigned int reg_r1_80;
unsigned int reg_r1_81;
unsigned int reg_r1_82;
unsigned int reg_r1_83;
unsigned int reg_r1_84;
unsigned int reg_r1_85;
unsigned int reg_r1_86;
unsigned int reg_r1_87;
unsigned int reg_r1_88;
unsigned int reg_r1_89;
unsigned int reg_r1_90;
unsigned int reg_r1_91;
unsigned int reg_r1_92;
unsigned int reg_r1_93;
unsigned int reg_r1_94;
unsigned int reg_r1_95;
unsigned int reg_r1_96;
unsigned int reg_r1_97;
unsigned int reg_r1_98;
unsigned int reg_r1_99;
unsigned int reg_r1_100;
unsigned int reg_r1_101;
unsigned int reg_r1_102;
unsigned int reg_r1_103;
unsigned int reg_r1_104;
unsigned int reg_r1_105;
unsigned int reg_r1_106;
unsigned int reg_r1_107;
unsigned int reg_r1_108;
unsigned int reg_r1_109;
unsigned int reg_r1_110;
unsigned int reg_r1_111;
unsigned int reg_r1_112;
unsigned int reg_r1_113;
unsigned int reg_r1_114;
unsigned int reg_r1_115;
unsigned int reg_r1_116;
unsigned int reg_r1_117;
unsigned int reg_r1_118;
unsigned int reg_r1_119;
unsigned int reg_r1_120;
unsigned int reg_r1_121;
unsigned int reg_r1_122;
unsigned int reg_r1_123;
unsigned int reg_r1_124;
unsigned int reg_r1_125;
unsigned int reg_r1_126;
unsigned int reg_r1_127;
unsigned int reg_r2_0;
unsigned int reg_r2_1;
unsigned int reg_r2_2;
unsigned int reg_r2_3;
unsigned int reg_r2_4;
unsigned int reg_r2_5;
unsigned int reg_r2_6;
unsigned int reg_r2_7;
unsigned int reg_r2_8;
unsigned int reg_r2_9;
unsigned int reg_r2_10;
unsigned int reg_r2_11;
unsigned int reg_r2_12;
unsigned int reg_r2_13;
unsigned int reg_r2_14;
unsigned int reg_r2_15;
unsigned int reg_r2_16;
unsigned int reg_r2_17;
unsigned int reg_r2_18;
unsigned int reg_r2_19;
unsigned int reg_r2_20;
unsigned int reg_r2_21;
unsigned int reg_r2_22;
unsigned int reg_r2_23;
unsigned int reg_r2_24;
unsigned int reg_r2_25;
unsigned int reg_r2_26;
unsigned int reg_r2_27;
unsigned int reg_r2_28;
unsigned int reg_r2_29;
unsigned int reg_r2_30;
unsigned int reg_r2_31;
unsigned int reg_r2_32;
unsigned int reg_r2_33;
unsigned int reg_r2_34;
unsigned int reg_r2_35;
unsigned int reg_r2_36;
unsigned int reg_r2_37;
unsigned int reg_r2_38;
unsigned int reg_r2_39;
unsigned int reg_r2_40;
unsigned int reg_r2_41;
unsigned int reg_r2_42;
unsigned int reg_r2_43;
unsigned int reg_r2_44;
unsigned int reg_r2_45;
unsigned int reg_r2_46;
unsigned int reg_r2_47;
unsigned int reg_r2_48;
unsigned int reg_r2_49;
unsigned int reg_r2_50;
unsigned int reg_r2_51;
unsigned int reg_r2_52;
unsigned int reg_r2_53;
unsigned int reg_r2_54;
unsigned int reg_r2_55;
unsigned int reg_r2_56;
unsigned int reg_r2_57;
unsigned int reg_r2_58;
unsigned int reg_r2_59;
unsigned int reg_r2_60;
unsigned int reg_r2_61;
unsigned int reg_r2_62;
unsigned int reg_r2_63;
unsigned int reg_r2_64;
unsigned int reg_r2_65;
unsigned int reg_r2_66;
unsigned int reg_r2_67;
unsigned int reg_r2_68;
unsigned int reg_r2_69;
unsigned int reg_r2_70;
unsigned int reg_r2_71;
unsigned int reg_r2_72;
unsigned int reg_r2_73;
unsigned int reg_r2_74;
unsigned int reg_r2_75;
unsigned int reg_r2_76;
unsigned int reg_r2_77;
unsigned int reg_r2_78;
unsigned int reg_r2_79;
unsigned int reg_r2_80;
unsigned int reg_r2_81;
unsigned int reg_r2_82;
unsigned int reg_r2_83;
unsigned int reg_r2_84;
unsigned int reg_r2_85;
unsigned int reg_r2_86;
unsigned int reg_r2_87;
unsigned int reg_r2_88;
unsigned int reg_r2_89;
unsigned int reg_r2_90;
unsigned int reg_r2_91;
unsigned int reg_r2_92;
unsigned int reg_r2_93;
unsigned int reg_r2_94;
unsigned int reg_r2_95;
unsigned int reg_r2_96;
unsigned int reg_r2_97;
unsigned int reg_r2_98;
unsigned int reg_r2_99;
unsigned int reg_r2_100;
unsigned int reg_r2_101;
unsigned int reg_r2_102;
unsigned int reg_r2_103;
unsigned int reg_r2_104;
unsigned int reg_r2_105;
unsigned int reg_r2_106;
unsigned int reg_r2_107;
unsigned int reg_r2_108;
unsigned int reg_r2_109;
unsigned int reg_r2_110;
unsigned int reg_r2_111;
unsigned int reg_r2_112;
unsigned int reg_r2_113;
unsigned int reg_r2_114;
unsigned int reg_r2_115;
unsigned int reg_r2_116;
unsigned int reg_r2_117;
unsigned int reg_r2_118;
unsigned int reg_r2_119;
unsigned int reg_r2_120;
unsigned int reg_r2_121;
unsigned int reg_r2_122;
unsigned int reg_r2_123;
unsigned int reg_r2_124;
unsigned int reg_r2_125;
unsigned int reg_r2_126;
unsigned int reg_r2_127;
unsigned int reg_r3_0;
unsigned int reg_r3_1;
unsigned int reg_r3_2;
unsigned int reg_r3_3;
unsigned int reg_r3_4;
unsigned int reg_r3_5;
unsigned int reg_r3_6;
unsigned int reg_r3_7;
unsigned int reg_r3_8;
unsigned int reg_r3_9;
unsigned int reg_r3_10;
unsigned int reg_r3_11;
unsigned int reg_r3_12;
unsigned int reg_r3_13;
unsigned int reg_r3_14;
unsigned int reg_r3_15;
unsigned int reg_r3_16;
unsigned int reg_r3_17;
unsigned int reg_r3_18;
unsigned int reg_r3_19;
unsigned int reg_r3_20;
unsigned int reg_r3_21;
unsigned int reg_r3_22;
unsigned int reg_r3_23;
unsigned int reg_r3_24;
unsigned int reg_r3_25;
unsigned int reg_r3_26;
unsigned int reg_r3_27;
unsigned int reg_r3_28;
unsigned int reg_r3_29;
unsigned int reg_r3_30;
unsigned int reg_r3_31;
unsigned int reg_r3_32;
unsigned int reg_r3_33;
unsigned int reg_r3_34;
unsigned int reg_r3_35;
unsigned int reg_r3_36;
unsigned int reg_r3_37;
unsigned int reg_r3_38;
unsigned int reg_r3_39;
unsigned int reg_r3_40;
unsigned int reg_r3_41;
unsigned int reg_r3_42;
unsigned int reg_r3_43;
unsigned int reg_r3_44;
unsigned int reg_r3_45;
unsigned int reg_r3_46;
unsigned int reg_r3_47;
unsigned int reg_r3_48;
unsigned int reg_r3_49;
unsigned int reg_r3_50;
unsigned int reg_r3_51;
unsigned int reg_r3_52;
unsigned int reg_r3_53;
unsigned int reg_r3_54;
unsigned int reg_r3_55;
unsigned int reg_r3_56;
unsigned int reg_r3_57;
unsigned int reg_r3_58;
unsigned int reg_r3_59;
unsigned int reg_r3_60;
unsigned int reg_r3_61;
unsigned int reg_r3_62;
unsigned int reg_r3_63;
unsigned int reg_r3_64;
unsigned int reg_r3_65;
unsigned int reg_r3_66;
unsigned int reg_r3_67;
unsigned int reg_r3_68;
unsigned int reg_r3_69;
unsigned int reg_r3_70;
unsigned int reg_r3_71;
unsigned int reg_r3_72;
unsigned int reg_r3_73;
unsigned int reg_r3_74;
unsigned int reg_r3_75;
unsigned int reg_r3_76;
unsigned int reg_r3_77;
unsigned int reg_r3_78;
unsigned int reg_r3_79;
unsigned int reg_r3_80;
unsigned int reg_r3_81;
unsigned int reg_r3_82;
unsigned int reg_r3_83;
unsigned int reg_r3_84;
unsigned int reg_r3_85;
unsigned int reg_r3_86;
unsigned int reg_r3_87;
unsigned int reg_r3_88;
unsigned int reg_r3_89;
unsigned int reg_r3_90;
unsigned int reg_r3_91;
unsigned int reg_r3_92;
unsigned int reg_r3_93;
unsigned int reg_r3_94;
unsigned int reg_r3_95;
unsigned int reg_r3_96;
unsigned int reg_r3_97;
unsigned int reg_r3_98;
unsigned int reg_r3_99;
unsigned int reg_r3_100;
unsigned int reg_r3_101;
unsigned int reg_r3_102;
unsigned int reg_r3_103;
unsigned int reg_r3_104;
unsigned int reg_r3_105;
unsigned int reg_r3_106;
unsigned int reg_r3_107;
unsigned int reg_r3_108;
unsigned int reg_r3_109;
unsigned int reg_r3_110;
unsigned int reg_r3_111;
unsigned int reg_r3_112;
unsigned int reg_r3_113;
unsigned int reg_r3_114;
unsigned int reg_r3_115;
unsigned int reg_r3_116;
unsigned int reg_r3_117;
unsigned int reg_r3_118;
unsigned int reg_r3_119;
unsigned int reg_r3_120;
unsigned int reg_r3_121;
unsigned int reg_r3_122;
unsigned int reg_r3_123;
unsigned int reg_r3_124;
unsigned int reg_r3_125;
unsigned int reg_r3_126;
unsigned int reg_r3_127;


extern unsigned int max( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(max);  sim_gprof_enter(&sim_gprof_idx,"max");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (102 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(0 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 19 */
  sim_icache_fetch(1 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 21 */
} /* line 21 */
  sim_icache_fetch(2 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L0X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 23 */
  sim_icache_fetch(3 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(max);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 26 */
l_L0X3: ;/* line 29 */
__LABEL(l_L0X3);
  sim_icache_fetch(4 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_4); /* line 30 */
} /* line 30 */
  sim_icache_fetch(5 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(max);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 33 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 101: goto l_L0X3;
    case 102:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int min( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(min);  sim_gprof_enter(&sim_gprof_idx,"min");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (104 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(6 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 48 */
  sim_icache_fetch(7 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 50 */
} /* line 50 */
  sim_icache_fetch(8 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 52 */
  sim_icache_fetch(9 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(min);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 55 */
l_L1X3: ;/* line 58 */
__LABEL(l_L1X3);
  sim_icache_fetch(10 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, reg_r0_4); /* line 59 */
} /* line 59 */
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(min);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 62 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 103: goto l_L1X3;
    case 104:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int NOP(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(NOP);  sim_gprof_enter(&sim_gprof_idx,"NOP");

  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (105 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 77 */
  sim_icache_fetch(13 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 79 */
} /* line 79 */
  sim_icache_fetch(14 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(NOP);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 82 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 105:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int __vex_main(  )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   __ENTRY(__vex_main);  sim_gprof_enter(&sim_gprof_idx,"__vex_main");

  sim_ta_init(1); /* enable cache simulation */
  reg_r0_1 = sim_create_stack(1048576,reg_r0_1); 

  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (116 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(15 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 98 */
} /* line 98 */
		 /* line 99 */
  sim_icache_fetch(16 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 102 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(NOP);
   reg_l0_0 = (116 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) NOP;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 102 */
l_lr_6: ;/* line 102 */
__LABEL(l_lr_6);
  sim_icache_fetch(19 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) grey_framebuffer); /* line 104 */
} /* line 104 */
  sim_icache_fetch(21 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_2, (unsigned int) -4096); /* line 106 */
} /* line 106 */
  sim_icache_fetch(23 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 108 */
} /* line 108 */
  sim_icache_fetch(24 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 109 */
l_L2X3: ;/* line 112 */
__LABEL(l_L2X3);
  sim_icache_fetch(25 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 113 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 32); /* line 114 */
} /* line 114 */
  sim_icache_fetch(27 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __PFT(mem_trace_pf((reg_r0_3 + (unsigned int) 128),0,4)); /* line 116 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 117 */
  sim_icache_fetch(29 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_3,0,4), 0); /* line 119 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), 0); /* line 120 */
} /* line 120 */
  sim_icache_fetch(31 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), 0); /* line 122 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), 0); /* line 123 */
} /* line 123 */
  sim_icache_fetch(33 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), 0); /* line 125 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), 0); /* line 126 */
} /* line 126 */
  sim_icache_fetch(35 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), 0); /* line 128 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), 0); /* line 129 */
} /* line 129 */
  sim_icache_fetch(37 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), 0); /* line 131 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), 0); /* line 132 */
} /* line 132 */
  sim_icache_fetch(39 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), 0); /* line 134 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), 0); /* line 135 */
} /* line 135 */
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), 0); /* line 137 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), 0); /* line 138 */
} /* line 138 */
  sim_icache_fetch(43 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), 0); /* line 140 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), 0); /* line 141 */
} /* line 141 */
  sim_icache_fetch(45 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 64),0,4), 0); /* line 143 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 68),0,4), 0); /* line 144 */
} /* line 144 */
  sim_icache_fetch(47 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 72),0,4), 0); /* line 146 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 76),0,4), 0); /* line 147 */
} /* line 147 */
  sim_icache_fetch(49 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 80),0,4), 0); /* line 149 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 84),0,4), 0); /* line 150 */
} /* line 150 */
  sim_icache_fetch(51 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 88),0,4), 0); /* line 152 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 92),0,4), 0); /* line 153 */
} /* line 153 */
  sim_icache_fetch(53 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 96),0,4), 0); /* line 155 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 100),0,4), 0); /* line 156 */
} /* line 156 */
  sim_icache_fetch(55 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 104),0,4), 0); /* line 158 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 108),0,4), 0); /* line 159 */
} /* line 159 */
  sim_icache_fetch(57 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 112),0,4), 0); /* line 161 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 116),0,4), 0); /* line 162 */
} /* line 162 */
  sim_icache_fetch(59 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 120),0,4), 0); /* line 164 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 124),0,4), 0); /* line 165 */
} /* line 165 */
  sim_icache_fetch(61 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 128); /* line 167 */
   __GOTO(l_L2X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L2X3;
} /* line 168 */
l_L3X3: ;/* line 171 */
__LABEL(l_L3X3);
  sim_icache_fetch(63 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_4); /* line 172 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_62); /* line 173 */
} /* line 173 */
  sim_icache_fetch(65 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) -64); /* line 175 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_63); /* line 176 */
} /* line 176 */
  sim_icache_fetch(67 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_7, (unsigned int) grey_image); /* line 178 */
} /* line 178 */
  sim_icache_fetch(69 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_6, (unsigned int) grey_framebuffer); /* line 180 */
} /* line 180 */
l_L4X3: ;/* line 183 */
__LABEL(l_L4X3);
  sim_icache_fetch(71 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 184 */
   __MOV(reg_r0_5, reg_r0_6); /* line 185 */
} /* line 185 */
  sim_icache_fetch(73 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_7); /* line 187 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 188 */
  sim_icache_fetch(75 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, (unsigned int) -64); /* line 190 */
   __MOV(reg_r0_40, reg_r0_3); /* line 191 */
} /* line 191 */
  sim_icache_fetch(77 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_41, reg_r0_6); /* line 193 */
   __MOV(reg_r0_42, reg_r0_7); /* line 194 */
} /* line 194 */
l_L6X3: ;/* line 197 */
__LABEL(l_L6X3);
  sim_icache_fetch(79 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 198 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 199 */
} /* line 199 */
  sim_icache_fetch(81 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 201 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 202 */
  sim_icache_fetch(83 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_8, reg_r0_3, (unsigned int) 255); /* line 204 */
   __SHRU(reg_r0_7, reg_r0_3, (unsigned int) 8); /* line 205 */
} /* line 205 */
  sim_icache_fetch(85 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_7, reg_r0_7, (unsigned int) 255); /* line 207 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 208 */
} /* line 208 */
  sim_icache_fetch(87 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_8, reg_r0_8, reg_r0_7); /* line 210 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 211 */
} /* line 211 */
  sim_icache_fetch(89 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_8, reg_r0_8, reg_r0_3); /* line 213 */
   __SHRU(reg_r0_3, reg_r0_6, (unsigned int) 8); /* line 214 */
} /* line 214 */
  sim_icache_fetch(91 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 216 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 217 */
} /* line 217 */
  sim_icache_fetch(93 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_9, reg_r0_8, (unsigned int) 8); /* line 219 */
   __SHL(reg_r0_7, reg_r0_8, (unsigned int) 16); /* line 220 */
} /* line 220 */
  sim_icache_fetch(95 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_8, reg_r0_8, reg_r0_7); /* line 222 */
   __AND(reg_r0_7, reg_r0_6, (unsigned int) 255); /* line 223 */
} /* line 223 */
  sim_icache_fetch(97 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_8, reg_r0_8, reg_r0_9); /* line 225 */
   __MAX(reg_r0_7, reg_r0_7, reg_r0_3); /* line 226 */
} /* line 226 */
  sim_icache_fetch(99 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 228 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 229 */
} /* line 229 */
  sim_icache_fetch(101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 231 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 232 */
} /* line 232 */
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_7, reg_r0_7, reg_r0_6); /* line 234 */
   __SHRU(reg_r0_6, reg_r0_3, (unsigned int) 8); /* line 235 */
} /* line 235 */
  sim_icache_fetch(105 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_7, reg_r0_7); /* line 237 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 238 */
} /* line 238 */
  sim_icache_fetch(107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_11, reg_r0_7, (unsigned int) 8); /* line 240 */
   __SHL(reg_r0_10, reg_r0_7, (unsigned int) 16); /* line 241 */
} /* line 241 */
  sim_icache_fetch(109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_7, reg_r0_7, reg_r0_10); /* line 243 */
   __AND(reg_r0_10, reg_r0_3, (unsigned int) 255); /* line 244 */
} /* line 244 */
  sim_icache_fetch(111 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_7, reg_r0_7, reg_r0_11); /* line 246 */
   __MAX(reg_r0_10, reg_r0_10, reg_r0_6); /* line 247 */
} /* line 247 */
  sim_icache_fetch(113 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 249 */
   __SHRU(reg_r0_6, reg_r0_9, (unsigned int) 8); /* line 250 */
} /* line 250 */
  sim_icache_fetch(115 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 252 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 253 */
} /* line 253 */
  sim_icache_fetch(117 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_10, reg_r0_10, reg_r0_3); /* line 255 */
   __AND(reg_r0_3, reg_r0_9, (unsigned int) 255); /* line 256 */
} /* line 256 */
  sim_icache_fetch(119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_10, reg_r0_10); /* line 258 */
   __MAX(reg_r0_3, reg_r0_3, reg_r0_6); /* line 259 */
} /* line 259 */
  sim_icache_fetch(121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_11, reg_r0_10, (unsigned int) 8); /* line 261 */
   __SHL(reg_r0_6, reg_r0_10, (unsigned int) 16); /* line 262 */
} /* line 262 */
  sim_icache_fetch(123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_10, reg_r0_10, reg_r0_6); /* line 264 */
   __SHRU(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 265 */
} /* line 265 */
  sim_icache_fetch(125 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_10, reg_r0_10, reg_r0_11); /* line 267 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 268 */
} /* line 268 */
  sim_icache_fetch(127 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_3, reg_r0_3, reg_r0_9); /* line 270 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 16),0,4)); /* line 271 */
} /* line 271 */
  sim_icache_fetch(129 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_3, reg_r0_3); /* line 273 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 20),0,4)); /* line 274 */
} /* line 274 */
  sim_icache_fetch(131 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_12, reg_r0_3, (unsigned int) 8); /* line 276 */
   __SHL(reg_r0_11, reg_r0_3, (unsigned int) 16); /* line 277 */
} /* line 277 */
  sim_icache_fetch(133 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_3, reg_r0_11); /* line 279 */
   __SHRU(reg_r0_11, reg_r0_6, (unsigned int) 8); /* line 280 */
} /* line 280 */
  sim_icache_fetch(135 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_3, reg_r0_3, reg_r0_12); /* line 282 */
   __AND(reg_r0_11, reg_r0_11, (unsigned int) 255); /* line 283 */
} /* line 283 */
  sim_icache_fetch(137 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_12, reg_r0_6, (unsigned int) 255); /* line 285 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 286 */
} /* line 286 */
  sim_icache_fetch(139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_12, reg_r0_12, reg_r0_11); /* line 288 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 289 */
} /* line 289 */
  sim_icache_fetch(141 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_12, reg_r0_12, reg_r0_6); /* line 291 */
   __SHRU(reg_r0_6, reg_r0_9, (unsigned int) 8); /* line 292 */
} /* line 292 */
  sim_icache_fetch(143 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_12, reg_r0_12); /* line 294 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 295 */
} /* line 295 */
  sim_icache_fetch(145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_13, reg_r0_12, (unsigned int) 8); /* line 297 */
   __SHL(reg_r0_11, reg_r0_12, (unsigned int) 16); /* line 298 */
} /* line 298 */
  sim_icache_fetch(147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_12, reg_r0_12, reg_r0_11); /* line 300 */
   __AND(reg_r0_11, reg_r0_9, (unsigned int) 255); /* line 301 */
} /* line 301 */
  sim_icache_fetch(149 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_12, reg_r0_12, reg_r0_13); /* line 303 */
   __MAX(reg_r0_11, reg_r0_11, reg_r0_6); /* line 304 */
} /* line 304 */
  sim_icache_fetch(151 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 306 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 24),0,4)); /* line 307 */
} /* line 307 */
  sim_icache_fetch(153 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 309 */
   __LDW(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 28),0,4)); /* line 310 */
} /* line 310 */
  sim_icache_fetch(155 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_11, reg_r0_11, reg_r0_9); /* line 312 */
   __SHRU(reg_r0_9, reg_r0_6, (unsigned int) 8); /* line 313 */
} /* line 313 */
  sim_icache_fetch(157 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_11, reg_r0_11); /* line 315 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 316 */
} /* line 316 */
  sim_icache_fetch(159 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_15, reg_r0_11, (unsigned int) 8); /* line 318 */
   __SHL(reg_r0_14, reg_r0_11, (unsigned int) 16); /* line 319 */
} /* line 319 */
  sim_icache_fetch(161 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_11, reg_r0_11, reg_r0_14); /* line 321 */
   __AND(reg_r0_14, reg_r0_6, (unsigned int) 255); /* line 322 */
} /* line 322 */
  sim_icache_fetch(163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_11, reg_r0_11, reg_r0_15); /* line 324 */
   __MAX(reg_r0_14, reg_r0_14, reg_r0_9); /* line 325 */
} /* line 325 */
  sim_icache_fetch(165 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 327 */
   __SHRU(reg_r0_9, reg_r0_13, (unsigned int) 8); /* line 328 */
} /* line 328 */
  sim_icache_fetch(167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 330 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 331 */
} /* line 331 */
  sim_icache_fetch(169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_14, reg_r0_14, reg_r0_6); /* line 333 */
   __AND(reg_r0_6, reg_r0_13, (unsigned int) 255); /* line 334 */
} /* line 334 */
  sim_icache_fetch(171 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 336 */
   __MAX(reg_r0_6, reg_r0_6, reg_r0_9); /* line 337 */
} /* line 337 */
  sim_icache_fetch(173 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_15, reg_r0_14, (unsigned int) 8); /* line 339 */
   __SHL(reg_r0_9, reg_r0_14, (unsigned int) 16); /* line 340 */
} /* line 340 */
  sim_icache_fetch(175 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_14, reg_r0_14, reg_r0_9); /* line 342 */
   __SHRU(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 343 */
} /* line 343 */
  sim_icache_fetch(177 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_14, reg_r0_14, reg_r0_15); /* line 345 */
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 346 */
} /* line 346 */
  sim_icache_fetch(179 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_6, reg_r0_6, reg_r0_13); /* line 348 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 32),0,4)); /* line 349 */
} /* line 349 */
  sim_icache_fetch(181 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_6, reg_r0_6); /* line 351 */
   __LDW(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 36),0,4)); /* line 352 */
} /* line 352 */
  sim_icache_fetch(183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_16, reg_r0_6, (unsigned int) 8); /* line 354 */
   __SHL(reg_r0_15, reg_r0_6, (unsigned int) 16); /* line 355 */
} /* line 355 */
  sim_icache_fetch(185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_6, reg_r0_6, reg_r0_15); /* line 357 */
   __SHRU(reg_r0_15, reg_r0_9, (unsigned int) 8); /* line 358 */
} /* line 358 */
  sim_icache_fetch(187 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_6, reg_r0_6, reg_r0_16); /* line 360 */
   __AND(reg_r0_15, reg_r0_15, (unsigned int) 255); /* line 361 */
} /* line 361 */
  sim_icache_fetch(189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_16, reg_r0_9, (unsigned int) 255); /* line 363 */
   __SHRU(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 364 */
} /* line 364 */
  sim_icache_fetch(191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_16, reg_r0_16, reg_r0_15); /* line 366 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 367 */
} /* line 367 */
  sim_icache_fetch(193 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_16, reg_r0_16, reg_r0_9); /* line 369 */
   __SHRU(reg_r0_9, reg_r0_13, (unsigned int) 8); /* line 370 */
} /* line 370 */
  sim_icache_fetch(195 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_16, reg_r0_16); /* line 372 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 373 */
} /* line 373 */
  sim_icache_fetch(197 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_17, reg_r0_16, (unsigned int) 8); /* line 375 */
   __SHL(reg_r0_15, reg_r0_16, (unsigned int) 16); /* line 376 */
} /* line 376 */
  sim_icache_fetch(199 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_16, reg_r0_16, reg_r0_15); /* line 378 */
   __AND(reg_r0_15, reg_r0_13, (unsigned int) 255); /* line 379 */
} /* line 379 */
  sim_icache_fetch(201 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_16, reg_r0_16, reg_r0_17); /* line 381 */
   __MAX(reg_r0_15, reg_r0_15, reg_r0_9); /* line 382 */
} /* line 382 */
  sim_icache_fetch(203 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 384 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 40),0,4)); /* line 385 */
} /* line 385 */
  sim_icache_fetch(205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 387 */
   __LDW(reg_r0_17, mem_trace_ld((reg_r0_2 + (unsigned int) 44),0,4)); /* line 388 */
} /* line 388 */
  sim_icache_fetch(207 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_15, reg_r0_15, reg_r0_13); /* line 390 */
   __SHRU(reg_r0_13, reg_r0_9, (unsigned int) 8); /* line 391 */
} /* line 391 */
  sim_icache_fetch(209 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_15, reg_r0_15); /* line 393 */
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 394 */
} /* line 394 */
  sim_icache_fetch(211 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_19, reg_r0_15, (unsigned int) 8); /* line 396 */
   __SHL(reg_r0_18, reg_r0_15, (unsigned int) 16); /* line 397 */
} /* line 397 */
  sim_icache_fetch(213 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_15, reg_r0_15, reg_r0_18); /* line 399 */
   __AND(reg_r0_18, reg_r0_9, (unsigned int) 255); /* line 400 */
} /* line 400 */
  sim_icache_fetch(215 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_15, reg_r0_15, reg_r0_19); /* line 402 */
   __MAX(reg_r0_18, reg_r0_18, reg_r0_13); /* line 403 */
} /* line 403 */
  sim_icache_fetch(217 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 405 */
   __SHRU(reg_r0_13, reg_r0_17, (unsigned int) 8); /* line 406 */
} /* line 406 */
  sim_icache_fetch(219 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 408 */
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 409 */
} /* line 409 */
  sim_icache_fetch(221 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_18, reg_r0_18, reg_r0_9); /* line 411 */
   __AND(reg_r0_9, reg_r0_17, (unsigned int) 255); /* line 412 */
} /* line 412 */
  sim_icache_fetch(223 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_18, reg_r0_18); /* line 414 */
   __MAX(reg_r0_9, reg_r0_9, reg_r0_13); /* line 415 */
} /* line 415 */
  sim_icache_fetch(225 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_19, reg_r0_18, (unsigned int) 8); /* line 417 */
   __SHL(reg_r0_13, reg_r0_18, (unsigned int) 16); /* line 418 */
} /* line 418 */
  sim_icache_fetch(227 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_18, reg_r0_18, reg_r0_13); /* line 420 */
   __SHRU(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 421 */
} /* line 421 */
  sim_icache_fetch(229 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_18, reg_r0_18, reg_r0_19); /* line 423 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 424 */
} /* line 424 */
  sim_icache_fetch(231 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_9, reg_r0_9, reg_r0_17); /* line 426 */
   __LDW(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 48),0,4)); /* line 427 */
} /* line 427 */
  sim_icache_fetch(233 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_9, reg_r0_9); /* line 429 */
   __LDW(reg_r0_17, mem_trace_ld((reg_r0_2 + (unsigned int) 52),0,4)); /* line 430 */
} /* line 430 */
  sim_icache_fetch(235 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_20, reg_r0_9, (unsigned int) 8); /* line 432 */
   __SHL(reg_r0_19, reg_r0_9, (unsigned int) 16); /* line 433 */
} /* line 433 */
  sim_icache_fetch(237 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_9, reg_r0_9, reg_r0_19); /* line 435 */
   __SHRU(reg_r0_19, reg_r0_13, (unsigned int) 8); /* line 436 */
} /* line 436 */
  sim_icache_fetch(239 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_9, reg_r0_9, reg_r0_20); /* line 438 */
   __AND(reg_r0_19, reg_r0_19, (unsigned int) 255); /* line 439 */
} /* line 439 */
  sim_icache_fetch(241 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_20, reg_r0_13, (unsigned int) 255); /* line 441 */
   __SHRU(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 442 */
} /* line 442 */
  sim_icache_fetch(243 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, reg_r0_19); /* line 444 */
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 445 */
} /* line 445 */
  sim_icache_fetch(245 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_20, reg_r0_20, reg_r0_13); /* line 447 */
   __SHRU(reg_r0_13, reg_r0_17, (unsigned int) 8); /* line 448 */
} /* line 448 */
  sim_icache_fetch(247 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_20, reg_r0_20); /* line 450 */
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 451 */
} /* line 451 */
  sim_icache_fetch(249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_21, reg_r0_20, (unsigned int) 8); /* line 453 */
   __SHL(reg_r0_19, reg_r0_20, (unsigned int) 16); /* line 454 */
} /* line 454 */
  sim_icache_fetch(251 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_20, reg_r0_20, reg_r0_19); /* line 456 */
   __AND(reg_r0_19, reg_r0_17, (unsigned int) 255); /* line 457 */
} /* line 457 */
  sim_icache_fetch(253 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_20, reg_r0_20, reg_r0_21); /* line 459 */
   __MAX(reg_r0_19, reg_r0_19, reg_r0_13); /* line 460 */
} /* line 460 */
  sim_icache_fetch(255 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 462 */
   __LDW(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 56),0,4)); /* line 463 */
} /* line 463 */
  sim_icache_fetch(257 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 465 */
   __LDW(reg_r0_21, mem_trace_ld((reg_r0_2 + (unsigned int) 60),0,4)); /* line 466 */
} /* line 466 */
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_19, reg_r0_19, reg_r0_17); /* line 468 */
   __SHRU(reg_r0_17, reg_r0_13, (unsigned int) 8); /* line 469 */
} /* line 469 */
  sim_icache_fetch(261 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_19, reg_r0_19); /* line 471 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 472 */
} /* line 472 */
  sim_icache_fetch(263 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_23, reg_r0_19, (unsigned int) 8); /* line 474 */
   __SHL(reg_r0_22, reg_r0_19, (unsigned int) 16); /* line 475 */
} /* line 475 */
  sim_icache_fetch(265 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_19, reg_r0_19, reg_r0_22); /* line 477 */
   __AND(reg_r0_22, reg_r0_13, (unsigned int) 255); /* line 478 */
} /* line 478 */
  sim_icache_fetch(267 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_19, reg_r0_19, reg_r0_23); /* line 480 */
   __MAX(reg_r0_22, reg_r0_22, reg_r0_17); /* line 481 */
} /* line 481 */
  sim_icache_fetch(269 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 483 */
   __SHRU(reg_r0_17, reg_r0_21, (unsigned int) 8); /* line 484 */
} /* line 484 */
  sim_icache_fetch(271 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 486 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 487 */
} /* line 487 */
  sim_icache_fetch(273 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_22, reg_r0_22, reg_r0_13); /* line 489 */
   __AND(reg_r0_13, reg_r0_21, (unsigned int) 255); /* line 490 */
} /* line 490 */
  sim_icache_fetch(275 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_22, reg_r0_22); /* line 492 */
   __MAX(reg_r0_13, reg_r0_13, reg_r0_17); /* line 493 */
} /* line 493 */
  sim_icache_fetch(277 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_23, reg_r0_22, (unsigned int) 8); /* line 495 */
   __SHL(reg_r0_17, reg_r0_22, (unsigned int) 16); /* line 496 */
} /* line 496 */
  sim_icache_fetch(279 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_22, reg_r0_22, reg_r0_17); /* line 498 */
   __SHRU(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 499 */
} /* line 499 */
  sim_icache_fetch(281 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_22, reg_r0_22, reg_r0_23); /* line 501 */
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 502 */
} /* line 502 */
  sim_icache_fetch(283 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_13, reg_r0_13, reg_r0_21); /* line 504 */
   __LDW(reg_r0_17, mem_trace_ld((reg_r0_2 + (unsigned int) 64),0,4)); /* line 505 */
} /* line 505 */
  sim_icache_fetch(285 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_13, reg_r0_13); /* line 507 */
   __LDW(reg_r0_21, mem_trace_ld((reg_r0_2 + (unsigned int) 68),0,4)); /* line 508 */
} /* line 508 */
  sim_icache_fetch(287 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_24, reg_r0_13, (unsigned int) 8); /* line 510 */
   __SHL(reg_r0_23, reg_r0_13, (unsigned int) 16); /* line 511 */
} /* line 511 */
  sim_icache_fetch(289 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_13, reg_r0_13, reg_r0_23); /* line 513 */
   __SHRU(reg_r0_23, reg_r0_17, (unsigned int) 8); /* line 514 */
} /* line 514 */
  sim_icache_fetch(291 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_13, reg_r0_13, reg_r0_24); /* line 516 */
   __AND(reg_r0_23, reg_r0_23, (unsigned int) 255); /* line 517 */
} /* line 517 */
  sim_icache_fetch(293 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_24, reg_r0_17, (unsigned int) 255); /* line 519 */
   __SHRU(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 520 */
} /* line 520 */
  sim_icache_fetch(295 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_24, reg_r0_24, reg_r0_23); /* line 522 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 523 */
} /* line 523 */
  sim_icache_fetch(297 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_24, reg_r0_24, reg_r0_17); /* line 525 */
   __SHRU(reg_r0_17, reg_r0_21, (unsigned int) 8); /* line 526 */
} /* line 526 */
  sim_icache_fetch(299 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_24, reg_r0_24); /* line 528 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 529 */
} /* line 529 */
  sim_icache_fetch(301 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_25, reg_r0_24, (unsigned int) 8); /* line 531 */
   __SHL(reg_r0_23, reg_r0_24, (unsigned int) 16); /* line 532 */
} /* line 532 */
  sim_icache_fetch(303 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_24, reg_r0_24, reg_r0_23); /* line 534 */
   __AND(reg_r0_23, reg_r0_21, (unsigned int) 255); /* line 535 */
} /* line 535 */
  sim_icache_fetch(305 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_24, reg_r0_24, reg_r0_25); /* line 537 */
   __MAX(reg_r0_23, reg_r0_23, reg_r0_17); /* line 538 */
} /* line 538 */
  sim_icache_fetch(307 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 540 */
   __LDW(reg_r0_17, mem_trace_ld((reg_r0_2 + (unsigned int) 72),0,4)); /* line 541 */
} /* line 541 */
  sim_icache_fetch(309 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 543 */
   __LDW(reg_r0_25, mem_trace_ld((reg_r0_2 + (unsigned int) 76),0,4)); /* line 544 */
} /* line 544 */
  sim_icache_fetch(311 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_23, reg_r0_23, reg_r0_21); /* line 546 */
   __SHRU(reg_r0_21, reg_r0_17, (unsigned int) 8); /* line 547 */
} /* line 547 */
  sim_icache_fetch(313 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_23, reg_r0_23); /* line 549 */
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 550 */
} /* line 550 */
  sim_icache_fetch(315 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_27, reg_r0_23, (unsigned int) 8); /* line 552 */
   __SHL(reg_r0_26, reg_r0_23, (unsigned int) 16); /* line 553 */
} /* line 553 */
  sim_icache_fetch(317 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_23, reg_r0_23, reg_r0_26); /* line 555 */
   __AND(reg_r0_26, reg_r0_17, (unsigned int) 255); /* line 556 */
} /* line 556 */
  sim_icache_fetch(319 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_23, reg_r0_23, reg_r0_27); /* line 558 */
   __MAX(reg_r0_26, reg_r0_26, reg_r0_21); /* line 559 */
} /* line 559 */
  sim_icache_fetch(321 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_17, reg_r0_17, (unsigned int) 16); /* line 561 */
   __SHRU(reg_r0_21, reg_r0_25, (unsigned int) 8); /* line 562 */
} /* line 562 */
  sim_icache_fetch(323 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 564 */
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 565 */
} /* line 565 */
  sim_icache_fetch(325 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_26, reg_r0_26, reg_r0_17); /* line 567 */
   __AND(reg_r0_17, reg_r0_25, (unsigned int) 255); /* line 568 */
} /* line 568 */
  sim_icache_fetch(327 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_26, reg_r0_26); /* line 570 */
   __MAX(reg_r0_17, reg_r0_17, reg_r0_21); /* line 571 */
} /* line 571 */
  sim_icache_fetch(329 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_27, reg_r0_26, (unsigned int) 8); /* line 573 */
   __SHL(reg_r0_21, reg_r0_26, (unsigned int) 16); /* line 574 */
} /* line 574 */
  sim_icache_fetch(331 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_26, reg_r0_26, reg_r0_21); /* line 576 */
   __SHRU(reg_r0_25, reg_r0_25, (unsigned int) 16); /* line 577 */
} /* line 577 */
  sim_icache_fetch(333 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_26, reg_r0_26, reg_r0_27); /* line 579 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 580 */
} /* line 580 */
  sim_icache_fetch(335 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_17, reg_r0_17, reg_r0_25); /* line 582 */
   __LDW(reg_r0_21, mem_trace_ld((reg_r0_2 + (unsigned int) 80),0,4)); /* line 583 */
} /* line 583 */
  sim_icache_fetch(337 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_17, reg_r0_17); /* line 585 */
   __LDW(reg_r0_25, mem_trace_ld((reg_r0_2 + (unsigned int) 84),0,4)); /* line 586 */
} /* line 586 */
  sim_icache_fetch(339 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_28, reg_r0_17, (unsigned int) 8); /* line 588 */
   __SHL(reg_r0_27, reg_r0_17, (unsigned int) 16); /* line 589 */
} /* line 589 */
  sim_icache_fetch(341 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_17, reg_r0_17, reg_r0_27); /* line 591 */
   __SHRU(reg_r0_27, reg_r0_21, (unsigned int) 8); /* line 592 */
} /* line 592 */
  sim_icache_fetch(343 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_17, reg_r0_17, reg_r0_28); /* line 594 */
   __AND(reg_r0_27, reg_r0_27, (unsigned int) 255); /* line 595 */
} /* line 595 */
  sim_icache_fetch(345 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_28, reg_r0_21, (unsigned int) 255); /* line 597 */
   __SHRU(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 598 */
} /* line 598 */
  sim_icache_fetch(347 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_28, reg_r0_28, reg_r0_27); /* line 600 */
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 601 */
} /* line 601 */
  sim_icache_fetch(349 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_28, reg_r0_28, reg_r0_21); /* line 603 */
   __SHRU(reg_r0_21, reg_r0_25, (unsigned int) 8); /* line 604 */
} /* line 604 */
  sim_icache_fetch(351 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_28, reg_r0_28); /* line 606 */
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 607 */
} /* line 607 */
  sim_icache_fetch(353 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_29, reg_r0_28, (unsigned int) 8); /* line 609 */
   __SHL(reg_r0_27, reg_r0_28, (unsigned int) 16); /* line 610 */
} /* line 610 */
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_28, reg_r0_28, reg_r0_27); /* line 612 */
   __AND(reg_r0_27, reg_r0_25, (unsigned int) 255); /* line 613 */
} /* line 613 */
  sim_icache_fetch(357 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_28, reg_r0_28, reg_r0_29); /* line 615 */
   __MAX(reg_r0_27, reg_r0_27, reg_r0_21); /* line 616 */
} /* line 616 */
  sim_icache_fetch(359 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_25, reg_r0_25, (unsigned int) 16); /* line 618 */
   __LDW(reg_r0_21, mem_trace_ld((reg_r0_2 + (unsigned int) 88),0,4)); /* line 619 */
} /* line 619 */
  sim_icache_fetch(361 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 621 */
   __LDW(reg_r0_29, mem_trace_ld((reg_r0_2 + (unsigned int) 92),0,4)); /* line 622 */
} /* line 622 */
  sim_icache_fetch(363 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_27, reg_r0_27, reg_r0_25); /* line 624 */
   __SHRU(reg_r0_25, reg_r0_21, (unsigned int) 8); /* line 625 */
} /* line 625 */
  sim_icache_fetch(365 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_27, reg_r0_27); /* line 627 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 628 */
} /* line 628 */
  sim_icache_fetch(367 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_31, reg_r0_27, (unsigned int) 8); /* line 630 */
   __SHL(reg_r0_30, reg_r0_27, (unsigned int) 16); /* line 631 */
} /* line 631 */
  sim_icache_fetch(369 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_27, reg_r0_27, reg_r0_30); /* line 633 */
   __AND(reg_r0_30, reg_r0_21, (unsigned int) 255); /* line 634 */
} /* line 634 */
  sim_icache_fetch(371 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_27, reg_r0_27, reg_r0_31); /* line 636 */
   __MAX(reg_r0_30, reg_r0_30, reg_r0_25); /* line 637 */
} /* line 637 */
  sim_icache_fetch(373 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_21, reg_r0_21, (unsigned int) 16); /* line 639 */
   __SHRU(reg_r0_25, reg_r0_29, (unsigned int) 8); /* line 640 */
} /* line 640 */
  sim_icache_fetch(375 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 642 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 643 */
} /* line 643 */
  sim_icache_fetch(377 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_30, reg_r0_30, reg_r0_21); /* line 645 */
   __AND(reg_r0_21, reg_r0_29, (unsigned int) 255); /* line 646 */
} /* line 646 */
  sim_icache_fetch(379 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_30, reg_r0_30); /* line 648 */
   __MAX(reg_r0_21, reg_r0_21, reg_r0_25); /* line 649 */
} /* line 649 */
  sim_icache_fetch(381 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_31, reg_r0_30, (unsigned int) 8); /* line 651 */
   __SHL(reg_r0_25, reg_r0_30, (unsigned int) 16); /* line 652 */
} /* line 652 */
  sim_icache_fetch(383 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_30, reg_r0_30, reg_r0_25); /* line 654 */
   __SHRU(reg_r0_29, reg_r0_29, (unsigned int) 16); /* line 655 */
} /* line 655 */
  sim_icache_fetch(385 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_30, reg_r0_30, reg_r0_31); /* line 657 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 658 */
} /* line 658 */
  sim_icache_fetch(387 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_21, reg_r0_21, reg_r0_29); /* line 660 */
   __LDW(reg_r0_25, mem_trace_ld((reg_r0_2 + (unsigned int) 96),0,4)); /* line 661 */
} /* line 661 */
  sim_icache_fetch(389 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_21, reg_r0_21); /* line 663 */
   __LDW(reg_r0_29, mem_trace_ld((reg_r0_2 + (unsigned int) 100),0,4)); /* line 664 */
} /* line 664 */
  sim_icache_fetch(391 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_32, reg_r0_21, (unsigned int) 8); /* line 666 */
   __SHL(reg_r0_31, reg_r0_21, (unsigned int) 16); /* line 667 */
} /* line 667 */
  sim_icache_fetch(393 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_21, reg_r0_21, reg_r0_31); /* line 669 */
   __SHRU(reg_r0_31, reg_r0_25, (unsigned int) 8); /* line 670 */
} /* line 670 */
  sim_icache_fetch(395 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_21, reg_r0_21, reg_r0_32); /* line 672 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 673 */
} /* line 673 */
  sim_icache_fetch(397 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_32, reg_r0_25, (unsigned int) 255); /* line 675 */
   __SHRU(reg_r0_25, reg_r0_25, (unsigned int) 16); /* line 676 */
} /* line 676 */
  sim_icache_fetch(399 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_32, reg_r0_32, reg_r0_31); /* line 678 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 679 */
} /* line 679 */
  sim_icache_fetch(401 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_32, reg_r0_32, reg_r0_25); /* line 681 */
   __SHRU(reg_r0_25, reg_r0_29, (unsigned int) 8); /* line 682 */
} /* line 682 */
  sim_icache_fetch(403 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_32, reg_r0_32); /* line 684 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 685 */
} /* line 685 */
  sim_icache_fetch(405 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_33, reg_r0_32, (unsigned int) 8); /* line 687 */
   __SHL(reg_r0_31, reg_r0_32, (unsigned int) 16); /* line 688 */
} /* line 688 */
  sim_icache_fetch(407 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_32, reg_r0_32, reg_r0_31); /* line 690 */
   __AND(reg_r0_31, reg_r0_29, (unsigned int) 255); /* line 691 */
} /* line 691 */
  sim_icache_fetch(409 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_32, reg_r0_32, reg_r0_33); /* line 693 */
   __MAX(reg_r0_31, reg_r0_31, reg_r0_25); /* line 694 */
} /* line 694 */
  sim_icache_fetch(411 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_29, reg_r0_29, (unsigned int) 16); /* line 696 */
   __LDW(reg_r0_25, mem_trace_ld((reg_r0_2 + (unsigned int) 104),0,4)); /* line 697 */
} /* line 697 */
  sim_icache_fetch(413 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 699 */
   __LDW(reg_r0_33, mem_trace_ld((reg_r0_2 + (unsigned int) 108),0,4)); /* line 700 */
} /* line 700 */
  sim_icache_fetch(415 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_31, reg_r0_31, reg_r0_29); /* line 702 */
   __SHRU(reg_r0_29, reg_r0_25, (unsigned int) 8); /* line 703 */
} /* line 703 */
  sim_icache_fetch(417 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_31, reg_r0_31); /* line 705 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 706 */
} /* line 706 */
  sim_icache_fetch(419 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_35, reg_r0_31, (unsigned int) 8); /* line 708 */
   __SHL(reg_r0_34, reg_r0_31, (unsigned int) 16); /* line 709 */
} /* line 709 */
  sim_icache_fetch(421 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_31, reg_r0_31, reg_r0_34); /* line 711 */
   __AND(reg_r0_34, reg_r0_25, (unsigned int) 255); /* line 712 */
} /* line 712 */
  sim_icache_fetch(423 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_31, reg_r0_31, reg_r0_35); /* line 714 */
   __MAX(reg_r0_34, reg_r0_34, reg_r0_29); /* line 715 */
} /* line 715 */
  sim_icache_fetch(425 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_25, reg_r0_25, (unsigned int) 16); /* line 717 */
   __SHRU(reg_r0_29, reg_r0_33, (unsigned int) 8); /* line 718 */
} /* line 718 */
  sim_icache_fetch(427 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 720 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 721 */
} /* line 721 */
  sim_icache_fetch(429 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_34, reg_r0_34, reg_r0_25); /* line 723 */
   __AND(reg_r0_25, reg_r0_33, (unsigned int) 255); /* line 724 */
} /* line 724 */
  sim_icache_fetch(431 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_34, reg_r0_34); /* line 726 */
   __MAX(reg_r0_25, reg_r0_25, reg_r0_29); /* line 727 */
} /* line 727 */
  sim_icache_fetch(433 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_35, reg_r0_34, (unsigned int) 8); /* line 729 */
   __SHL(reg_r0_29, reg_r0_34, (unsigned int) 16); /* line 730 */
} /* line 730 */
  sim_icache_fetch(435 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_34, reg_r0_34, reg_r0_29); /* line 732 */
   __SHRU(reg_r0_33, reg_r0_33, (unsigned int) 16); /* line 733 */
} /* line 733 */
  sim_icache_fetch(437 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_34, reg_r0_34, reg_r0_35); /* line 735 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 736 */
} /* line 736 */
  sim_icache_fetch(439 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_25, reg_r0_25, reg_r0_33); /* line 738 */
   __LDW(reg_r0_29, mem_trace_ld((reg_r0_2 + (unsigned int) 112),0,4)); /* line 739 */
} /* line 739 */
  sim_icache_fetch(441 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_25, reg_r0_25); /* line 741 */
   __LDW(reg_r0_33, mem_trace_ld((reg_r0_2 + (unsigned int) 116),0,4)); /* line 742 */
} /* line 742 */
  sim_icache_fetch(443 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_36, reg_r0_25, (unsigned int) 8); /* line 744 */
   __SHL(reg_r0_35, reg_r0_25, (unsigned int) 16); /* line 745 */
} /* line 745 */
  sim_icache_fetch(445 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_25, reg_r0_25, reg_r0_35); /* line 747 */
   __SHRU(reg_r0_35, reg_r0_29, (unsigned int) 8); /* line 748 */
} /* line 748 */
  sim_icache_fetch(447 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_25, reg_r0_25, reg_r0_36); /* line 750 */
   __AND(reg_r0_35, reg_r0_35, (unsigned int) 255); /* line 751 */
} /* line 751 */
  sim_icache_fetch(449 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_36, reg_r0_29, (unsigned int) 255); /* line 753 */
   __SHRU(reg_r0_29, reg_r0_29, (unsigned int) 16); /* line 754 */
} /* line 754 */
  sim_icache_fetch(451 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_36, reg_r0_36, reg_r0_35); /* line 756 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 757 */
} /* line 757 */
  sim_icache_fetch(453 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_36, reg_r0_36, reg_r0_29); /* line 759 */
   __SHRU(reg_r0_29, reg_r0_33, (unsigned int) 8); /* line 760 */
} /* line 760 */
  sim_icache_fetch(455 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_36, reg_r0_36); /* line 762 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 763 */
} /* line 763 */
  sim_icache_fetch(457 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_37, reg_r0_36, (unsigned int) 8); /* line 765 */
   __SHL(reg_r0_35, reg_r0_36, (unsigned int) 16); /* line 766 */
} /* line 766 */
  sim_icache_fetch(459 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_36, reg_r0_36, reg_r0_35); /* line 768 */
   __AND(reg_r0_35, reg_r0_33, (unsigned int) 255); /* line 769 */
} /* line 769 */
  sim_icache_fetch(461 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_36, reg_r0_36, reg_r0_37); /* line 771 */
   __MAX(reg_r0_35, reg_r0_35, reg_r0_29); /* line 772 */
} /* line 772 */
  sim_icache_fetch(463 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_33, reg_r0_33, (unsigned int) 16); /* line 774 */
   __LDW(reg_r0_29, mem_trace_ld((reg_r0_2 + (unsigned int) 120),0,4)); /* line 775 */
} /* line 775 */
  sim_icache_fetch(465 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 777 */
   __LDW(reg_r0_37, mem_trace_ld((reg_r0_2 + (unsigned int) 124),0,4)); /* line 778 */
} /* line 778 */
  sim_icache_fetch(467 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_35, reg_r0_35, reg_r0_33); /* line 780 */
   __SHRU(reg_r0_33, reg_r0_29, (unsigned int) 8); /* line 781 */
} /* line 781 */
  sim_icache_fetch(469 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_35, reg_r0_35); /* line 783 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 784 */
} /* line 784 */
  sim_icache_fetch(471 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_39, reg_r0_35, (unsigned int) 8); /* line 786 */
   __SHL(reg_r0_38, reg_r0_35, (unsigned int) 16); /* line 787 */
} /* line 787 */
  sim_icache_fetch(473 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_35, reg_r0_35, reg_r0_38); /* line 789 */
   __AND(reg_r0_38, reg_r0_29, (unsigned int) 255); /* line 790 */
} /* line 790 */
  sim_icache_fetch(475 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_35, reg_r0_35, reg_r0_39); /* line 792 */
   __MAX(reg_r0_38, reg_r0_38, reg_r0_33); /* line 793 */
} /* line 793 */
  sim_icache_fetch(477 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_29, reg_r0_29, (unsigned int) 16); /* line 795 */
   __SHRU(reg_r0_33, reg_r0_37, (unsigned int) 8); /* line 796 */
} /* line 796 */
  sim_icache_fetch(479 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 798 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 799 */
} /* line 799 */
  sim_icache_fetch(481 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_38, reg_r0_38, reg_r0_29); /* line 801 */
   __AND(reg_r0_29, reg_r0_37, (unsigned int) 255); /* line 802 */
} /* line 802 */
  sim_icache_fetch(483 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ZXTB(reg_r0_38, reg_r0_38); /* line 804 */
   __MAX(reg_r0_29, reg_r0_29, reg_r0_33); /* line 805 */
} /* line 805 */
  sim_icache_fetch(485 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_39, reg_r0_38, (unsigned int) 8); /* line 807 */
   __SHL(reg_r0_33, reg_r0_38, (unsigned int) 16); /* line 808 */
} /* line 808 */
  sim_icache_fetch(487 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_38, reg_r0_38, reg_r0_33); /* line 810 */
   __SHRU(reg_r0_37, reg_r0_37, (unsigned int) 16); /* line 811 */
} /* line 811 */
  sim_icache_fetch(489 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_38, reg_r0_38, reg_r0_39); /* line 813 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 814 */
} /* line 814 */
  sim_icache_fetch(491 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_29, reg_r0_29, reg_r0_37); /* line 816 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 32); /* line 817 */
} /* line 817 */
  sim_icache_fetch(493 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_5,0,4), reg_r0_8); /* line 819 */
   __ZXTB(reg_r0_29, reg_r0_29); /* line 820 */
} /* line 820 */
  sim_icache_fetch(495 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_33, reg_r0_29, (unsigned int) 8); /* line 822 */
   __SHL(reg_r0_8, reg_r0_29, (unsigned int) 16); /* line 823 */
} /* line 823 */
  sim_icache_fetch(497 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,4), reg_r0_7); /* line 825 */
   __OR(reg_r0_29, reg_r0_29, reg_r0_8); /* line 826 */
} /* line 826 */
  sim_icache_fetch(499 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,4), reg_r0_10); /* line 828 */
   __OR(reg_r0_29, reg_r0_29, reg_r0_33); /* line 829 */
} /* line 829 */
  sim_icache_fetch(501 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,4), reg_r0_3); /* line 831 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 16),0,4), reg_r0_12); /* line 832 */
} /* line 832 */
  sim_icache_fetch(503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 20),0,4), reg_r0_11); /* line 834 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 24),0,4), reg_r0_14); /* line 835 */
} /* line 835 */
  sim_icache_fetch(505 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 28),0,4), reg_r0_6); /* line 837 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 32),0,4), reg_r0_16); /* line 838 */
} /* line 838 */
  sim_icache_fetch(507 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 36),0,4), reg_r0_15); /* line 840 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 40),0,4), reg_r0_18); /* line 841 */
} /* line 841 */
  sim_icache_fetch(509 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 44),0,4), reg_r0_9); /* line 843 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 48),0,4), reg_r0_20); /* line 844 */
} /* line 844 */
  sim_icache_fetch(511 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 52),0,4), reg_r0_19); /* line 846 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 56),0,4), reg_r0_22); /* line 847 */
} /* line 847 */
  sim_icache_fetch(513 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 60),0,4), reg_r0_13); /* line 849 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 64),0,4), reg_r0_24); /* line 850 */
} /* line 850 */
  sim_icache_fetch(515 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 68),0,4), reg_r0_23); /* line 852 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 72),0,4), reg_r0_26); /* line 853 */
} /* line 853 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 76),0,4), reg_r0_17); /* line 855 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 80),0,4), reg_r0_28); /* line 856 */
} /* line 856 */
  sim_icache_fetch(519 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 84),0,4), reg_r0_27); /* line 858 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 88),0,4), reg_r0_30); /* line 859 */
} /* line 859 */
  sim_icache_fetch(521 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 92),0,4), reg_r0_21); /* line 861 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 96),0,4), reg_r0_32); /* line 862 */
} /* line 862 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 100),0,4), reg_r0_31); /* line 864 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 104),0,4), reg_r0_34); /* line 865 */
} /* line 865 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 108),0,4), reg_r0_25); /* line 867 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 112),0,4), reg_r0_36); /* line 868 */
} /* line 868 */
  sim_icache_fetch(527 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 116),0,4), reg_r0_35); /* line 870 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 120),0,4), reg_r0_38); /* line 871 */
} /* line 871 */
  sim_icache_fetch(529 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __PFT(mem_trace_pf((reg_r0_5 + (unsigned int) 128),0,4)); /* line 873 */
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 124),0,4), reg_r0_29); /* line 874 */
} /* line 874 */
  sim_icache_fetch(531 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __PFT(mem_trace_pf((reg_r0_2 + (unsigned int) 128),0,4)); /* line 876 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 128); /* line 877 */
} /* line 877 */
  sim_icache_fetch(533 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 128); /* line 879 */
   __GOTO(l_L6X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L6X3;
} /* line 880 */
l_L7X3: ;/* line 883 */
__LABEL(l_L7X3);
  sim_icache_fetch(535 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_42, (unsigned int) 256); /* line 884 */
} /* line 884 */
  sim_icache_fetch(537 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_6, reg_r0_41, (unsigned int) 256); /* line 886 */
} /* line 886 */
  sim_icache_fetch(539 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_40, (unsigned int) 1); /* line 888 */
   __GOTO(l_L4X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L4X3;
} /* line 889 */
l_L5X3: ;/* line 892 */
__LABEL(l_L5X3);
  sim_icache_fetch(541 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 893 */
} /* line 893 */
		 /* line 894 */
  sim_icache_fetch(543 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (116 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 896 */
l_lr_14: ;/* line 896 */
__LABEL(l_lr_14);
  sim_icache_fetch(545 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 898 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 899 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 900 */
   __ADD_CYCLES(1);
} /* line 900 */
  sim_icache_fetch(548 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 902 */
} /* line 902 */
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 904 */
} /* line 904 */
  sim_icache_fetch(550 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 907 */
  reg_l0_0 = t_client_rpc;
  sim_gprof_exit(&sim_gprof_idx);
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 107: goto l_lr_6;
    case 108: goto l_L2X3;
    case 109: goto l_L3X3;
    case 110: goto l_L4X3;
    case 111: goto l_L6X3;
    case 112: goto l_L7X3;
    case 113: goto l_L5X3;
    case 115: goto l_lr_14;
    case 116:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"greyscale.s", 560, 0, 0, 0, 2};

