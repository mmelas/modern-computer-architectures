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
   __INC_BUNDLE_CNT(1);
   __CMPGT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 20 */
} /* line 20 */
  sim_icache_fetch(1 + t_thisfile.offset, 1);
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
} /* line 22 */
  sim_icache_fetch(2 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(max);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 25 */
l_L0X3: ;/* line 28 */
__LABEL(l_L0X3);
  sim_icache_fetch(3 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_4); /* line 31 */
   __RETURN(max);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 31 */
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

  sim_icache_fetch(5 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __CMPLT(reg_b0_0, reg_r0_3, reg_r0_4); /* line 47 */
} /* line 47 */
  sim_icache_fetch(6 + t_thisfile.offset, 1);
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
} /* line 49 */
  sim_icache_fetch(7 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(min);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 52 */
l_L1X3: ;/* line 55 */
__LABEL(l_L1X3);
  sim_icache_fetch(8 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, reg_r0_4); /* line 58 */
   __RETURN(min);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 58 */
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

  sim_icache_fetch(10 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, 0); /* line 74 */
} /* line 74 */
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(NOP);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 77 */
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

  sim_check_stack(reg_r0_1, -64); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (116 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 93 */
} /* line 93 */
		 /* line 94 */
  sim_icache_fetch(13 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 97 */
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
} /* line 97 */
l_lr_6: ;/* line 97 */
__LABEL(l_lr_6);
  sim_icache_fetch(16 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_2, (unsigned int) -4096); /* line 99 */
   __MOV(reg_r0_3, (unsigned int) grey_framebuffer); /* line 100 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 101 */
} /* line 101 */
  sim_icache_fetch(21 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(0);
} /* line 102 */
l_L2X3: ;/* line 105 */
__LABEL(l_L2X3);
  sim_icache_fetch(22 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 106 */
   __PFT(mem_trace_pf((reg_r0_3 + (unsigned int) 128),0,4)); /* line 107 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 32); /* line 108 */
} /* line 108 */
  sim_icache_fetch(25 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 110 */
  sim_icache_fetch(26 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_3,0,4), 0); /* line 112 */
} /* line 112 */
  sim_icache_fetch(27 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), 0); /* line 114 */
} /* line 114 */
  sim_icache_fetch(28 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), 0); /* line 116 */
} /* line 116 */
  sim_icache_fetch(29 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), 0); /* line 118 */
} /* line 118 */
  sim_icache_fetch(30 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), 0); /* line 120 */
} /* line 120 */
  sim_icache_fetch(31 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), 0); /* line 122 */
} /* line 122 */
  sim_icache_fetch(32 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), 0); /* line 124 */
} /* line 124 */
  sim_icache_fetch(33 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), 0); /* line 126 */
} /* line 126 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), 0); /* line 128 */
} /* line 128 */
  sim_icache_fetch(35 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), 0); /* line 130 */
} /* line 130 */
  sim_icache_fetch(36 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), 0); /* line 132 */
} /* line 132 */
  sim_icache_fetch(37 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), 0); /* line 134 */
} /* line 134 */
  sim_icache_fetch(38 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), 0); /* line 136 */
} /* line 136 */
  sim_icache_fetch(39 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), 0); /* line 138 */
} /* line 138 */
  sim_icache_fetch(40 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), 0); /* line 140 */
} /* line 140 */
  sim_icache_fetch(41 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), 0); /* line 142 */
} /* line 142 */
  sim_icache_fetch(42 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 64),0,4), 0); /* line 144 */
} /* line 144 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 68),0,4), 0); /* line 146 */
} /* line 146 */
  sim_icache_fetch(44 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 72),0,4), 0); /* line 148 */
} /* line 148 */
  sim_icache_fetch(45 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 76),0,4), 0); /* line 150 */
} /* line 150 */
  sim_icache_fetch(46 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 80),0,4), 0); /* line 152 */
} /* line 152 */
  sim_icache_fetch(47 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 84),0,4), 0); /* line 154 */
} /* line 154 */
  sim_icache_fetch(48 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 88),0,4), 0); /* line 156 */
} /* line 156 */
  sim_icache_fetch(49 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 92),0,4), 0); /* line 158 */
} /* line 158 */
  sim_icache_fetch(50 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 96),0,4), 0); /* line 160 */
} /* line 160 */
  sim_icache_fetch(51 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 100),0,4), 0); /* line 162 */
} /* line 162 */
  sim_icache_fetch(52 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 104),0,4), 0); /* line 164 */
} /* line 164 */
  sim_icache_fetch(53 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 108),0,4), 0); /* line 166 */
} /* line 166 */
  sim_icache_fetch(54 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 112),0,4), 0); /* line 168 */
} /* line 168 */
  sim_icache_fetch(55 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 116),0,4), 0); /* line 170 */
} /* line 170 */
  sim_icache_fetch(56 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 120),0,4), 0); /* line 172 */
} /* line 172 */
  sim_icache_fetch(57 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 124),0,4), 0); /* line 174 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 128); /* line 175 */
   __GOTO(l_L2X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L2X3;
} /* line 176 */
l_L3X3: ;/* line 179 */
__LABEL(l_L3X3);
  sim_icache_fetch(60 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_3, (unsigned int) -64); /* line 180 */
   __MOV(reg_r0_6, (unsigned int) grey_framebuffer); /* line 181 */
   __MOV(reg_r0_7, (unsigned int) grey_image); /* line 182 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_4); /* line 183 */
} /* line 183 */
  sim_icache_fetch(66 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_58); /* line 185 */
} /* line 185 */
  sim_icache_fetch(67 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_59); /* line 187 */
} /* line 187 */
  sim_icache_fetch(68 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_60); /* line 189 */
} /* line 189 */
  sim_icache_fetch(69 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_61); /* line 191 */
} /* line 191 */
  sim_icache_fetch(70 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_62); /* line 193 */
} /* line 193 */
  sim_icache_fetch(71 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_63); /* line 195 */
} /* line 195 */
l_L4X3: ;/* line 198 */
__LABEL(l_L4X3);
  sim_icache_fetch(72 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 199 */
   __MOV(reg_r0_4, (unsigned int) -64); /* line 200 */
   __MOV(reg_r0_5, reg_r0_6); /* line 201 */
   __MOV(reg_r0_2, reg_r0_7); /* line 202 */
   __MOV(reg_r0_43, reg_r0_3); /* line 203 */
   __MOV(reg_r0_44, reg_r0_6); /* line 204 */
} /* line 204 */
  sim_icache_fetch(78 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_45, reg_r0_7); /* line 206 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 207 */
l_L6X3: ;/* line 210 */
__LABEL(l_L6X3);
  sim_icache_fetch(80 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 211 */
   __LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 212 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 32); /* line 213 */
} /* line 213 */
  sim_icache_fetch(83 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 215 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 216 */
  sim_icache_fetch(85 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_8, reg_r0_3, (unsigned int) 255); /* line 218 */
   __SHRU(reg_r0_7, reg_r0_3, (unsigned int) 8); /* line 219 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 220 */
   __LDW(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 221 */
} /* line 221 */
  sim_icache_fetch(89 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_7, reg_r0_7, (unsigned int) 255); /* line 223 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 224 */
   __AND(reg_r0_11, reg_r0_6, (unsigned int) 255); /* line 225 */
   __SHRU(reg_r0_10, reg_r0_6, (unsigned int) 8); /* line 226 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 227 */
   __LDW(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 228 */
} /* line 228 */
  sim_icache_fetch(95 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MAX(reg_r0_8, reg_r0_8, reg_r0_7); /* line 230 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 231 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 232 */
   __AND(reg_r0_13, reg_r0_9, (unsigned int) 255); /* line 233 */
   __SHRU(reg_r0_7, reg_r0_9, (unsigned int) 8); /* line 234 */
   __SHRU(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 235 */
} /* line 235 */
  sim_icache_fetch(101 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MAX(reg_r0_8, reg_r0_8, reg_r0_3); /* line 237 */
   __MAX(reg_r0_11, reg_r0_11, reg_r0_10); /* line 238 */
   __AND(reg_r0_7, reg_r0_7, (unsigned int) 255); /* line 239 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 240 */
   __AND(reg_r0_10, reg_r0_12, (unsigned int) 255); /* line 241 */
   __SHRU(reg_r0_3, reg_r0_12, (unsigned int) 8); /* line 242 */
} /* line 242 */
  sim_icache_fetch(107 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ZXTB(reg_r0_8, reg_r0_8); /* line 244 */
   __MAX(reg_r0_11, reg_r0_11, reg_r0_6); /* line 245 */
   __MAX(reg_r0_13, reg_r0_13, reg_r0_7); /* line 246 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 247 */
   __SHRU(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 248 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 16),0,4)); /* line 249 */
} /* line 249 */
  sim_icache_fetch(113 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_14, reg_r0_8, (unsigned int) 8); /* line 251 */
   __SHL(reg_r0_7, reg_r0_8, (unsigned int) 16); /* line 252 */
   __ZXTB(reg_r0_11, reg_r0_11); /* line 253 */
   __MAX(reg_r0_13, reg_r0_13, reg_r0_9); /* line 254 */
   __MAX(reg_r0_10, reg_r0_10, reg_r0_3); /* line 255 */
   __AND(reg_r0_12, reg_r0_12, (unsigned int) 255); /* line 256 */
} /* line 256 */
  sim_icache_fetch(119 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_8, reg_r0_8, reg_r0_7); /* line 258 */
   __SHL(reg_r0_7, reg_r0_11, (unsigned int) 8); /* line 259 */
   __SHL(reg_r0_3, reg_r0_11, (unsigned int) 16); /* line 260 */
   __ZXTB(reg_r0_13, reg_r0_13); /* line 261 */
   __MAX(reg_r0_10, reg_r0_10, reg_r0_12); /* line 262 */
   __SHRU(reg_r0_9, reg_r0_6, (unsigned int) 8); /* line 263 */
} /* line 263 */
  sim_icache_fetch(125 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_8, reg_r0_8, reg_r0_14); /* line 265 */
   __OR(reg_r0_11, reg_r0_11, reg_r0_3); /* line 266 */
   __SHL(reg_r0_12, reg_r0_13, (unsigned int) 8); /* line 267 */
   __SHL(reg_r0_3, reg_r0_13, (unsigned int) 16); /* line 268 */
   __ZXTB(reg_r0_10, reg_r0_10); /* line 269 */
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 270 */
} /* line 270 */
  sim_icache_fetch(131 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_11, reg_r0_11, reg_r0_7); /* line 272 */
   __OR(reg_r0_13, reg_r0_13, reg_r0_3); /* line 273 */
   __SHL(reg_r0_7, reg_r0_10, (unsigned int) 8); /* line 274 */
   __SHL(reg_r0_3, reg_r0_10, (unsigned int) 16); /* line 275 */
   __AND(reg_r0_14, reg_r0_6, (unsigned int) 255); /* line 276 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 277 */
} /* line 277 */
  sim_icache_fetch(137 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_13, reg_r0_13, reg_r0_12); /* line 279 */
   __OR(reg_r0_10, reg_r0_10, reg_r0_3); /* line 280 */
   __MAX(reg_r0_14, reg_r0_14, reg_r0_9); /* line 281 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 282 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 20),0,4)); /* line 283 */
} /* line 283 */
  sim_icache_fetch(142 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __OR(reg_r0_10, reg_r0_10, reg_r0_7); /* line 285 */
   __MAX(reg_r0_14, reg_r0_14, reg_r0_6); /* line 286 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 24),0,4)); /* line 287 */
} /* line 287 */
  sim_icache_fetch(145 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ZXTB(reg_r0_14, reg_r0_14); /* line 289 */
   __AND(reg_r0_9, reg_r0_3, (unsigned int) 255); /* line 290 */
   __SHRU(reg_r0_7, reg_r0_3, (unsigned int) 8); /* line 291 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 292 */
   __LDW(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 28),0,4)); /* line 293 */
} /* line 293 */
  sim_icache_fetch(150 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_16, reg_r0_14, (unsigned int) 8); /* line 295 */
   __SHL(reg_r0_15, reg_r0_14, (unsigned int) 16); /* line 296 */
   __AND(reg_r0_7, reg_r0_7, (unsigned int) 255); /* line 297 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 298 */
   __AND(reg_r0_18, reg_r0_6, (unsigned int) 255); /* line 299 */
   __SHRU(reg_r0_17, reg_r0_6, (unsigned int) 8); /* line 300 */
} /* line 300 */
  sim_icache_fetch(156 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_14, reg_r0_14, reg_r0_15); /* line 302 */
   __MAX(reg_r0_9, reg_r0_9, reg_r0_7); /* line 303 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 304 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 305 */
   __AND(reg_r0_15, reg_r0_12, (unsigned int) 255); /* line 306 */
   __SHRU(reg_r0_7, reg_r0_12, (unsigned int) 8); /* line 307 */
} /* line 307 */
  sim_icache_fetch(162 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_14, reg_r0_14, reg_r0_16); /* line 309 */
   __MAX(reg_r0_9, reg_r0_9, reg_r0_3); /* line 310 */
   __MAX(reg_r0_18, reg_r0_18, reg_r0_17); /* line 311 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 312 */
   __AND(reg_r0_7, reg_r0_7, (unsigned int) 255); /* line 313 */
   __SHRU(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 314 */
} /* line 314 */
  sim_icache_fetch(168 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ZXTB(reg_r0_9, reg_r0_9); /* line 316 */
   __MAX(reg_r0_18, reg_r0_18, reg_r0_6); /* line 317 */
   __MAX(reg_r0_15, reg_r0_15, reg_r0_7); /* line 318 */
   __AND(reg_r0_12, reg_r0_12, (unsigned int) 255); /* line 319 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 32),0,4)); /* line 320 */
} /* line 320 */
  sim_icache_fetch(173 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SHL(reg_r0_7, reg_r0_9, (unsigned int) 8); /* line 322 */
   __SHL(reg_r0_6, reg_r0_9, (unsigned int) 16); /* line 323 */
   __ZXTB(reg_r0_18, reg_r0_18); /* line 324 */
   __MAX(reg_r0_15, reg_r0_15, reg_r0_12); /* line 325 */
   __LDW(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 36),0,4)); /* line 326 */
} /* line 326 */
  sim_icache_fetch(178 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_9, reg_r0_9, reg_r0_6); /* line 328 */
   __SHL(reg_r0_16, reg_r0_18, (unsigned int) 8); /* line 329 */
   __SHL(reg_r0_6, reg_r0_18, (unsigned int) 16); /* line 330 */
   __ZXTB(reg_r0_15, reg_r0_15); /* line 331 */
   __AND(reg_r0_19, reg_r0_3, (unsigned int) 255); /* line 332 */
   __SHRU(reg_r0_17, reg_r0_3, (unsigned int) 8); /* line 333 */
} /* line 333 */
  sim_icache_fetch(184 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_9, reg_r0_9, reg_r0_7); /* line 335 */
   __OR(reg_r0_18, reg_r0_18, reg_r0_6); /* line 336 */
   __SHL(reg_r0_7, reg_r0_15, (unsigned int) 8); /* line 337 */
   __SHL(reg_r0_6, reg_r0_15, (unsigned int) 16); /* line 338 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 339 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 340 */
} /* line 340 */
  sim_icache_fetch(190 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_18, reg_r0_18, reg_r0_16); /* line 342 */
   __OR(reg_r0_15, reg_r0_15, reg_r0_6); /* line 343 */
   __MAX(reg_r0_19, reg_r0_19, reg_r0_17); /* line 344 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 345 */
   __AND(reg_r0_16, reg_r0_12, (unsigned int) 255); /* line 346 */
   __SHRU(reg_r0_6, reg_r0_12, (unsigned int) 8); /* line 347 */
} /* line 347 */
  sim_icache_fetch(196 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_15, reg_r0_15, reg_r0_7); /* line 349 */
   __MAX(reg_r0_19, reg_r0_19, reg_r0_3); /* line 350 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 351 */
   __SHRU(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 352 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 40),0,4)); /* line 353 */
} /* line 353 */
  sim_icache_fetch(201 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ZXTB(reg_r0_19, reg_r0_19); /* line 355 */
   __MAX(reg_r0_16, reg_r0_16, reg_r0_6); /* line 356 */
   __AND(reg_r0_12, reg_r0_12, (unsigned int) 255); /* line 357 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 44),0,4)); /* line 358 */
} /* line 358 */
  sim_icache_fetch(205 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_17, reg_r0_19, (unsigned int) 8); /* line 360 */
   __SHL(reg_r0_7, reg_r0_19, (unsigned int) 16); /* line 361 */
   __MAX(reg_r0_16, reg_r0_16, reg_r0_12); /* line 362 */
   __AND(reg_r0_20, reg_r0_3, (unsigned int) 255); /* line 363 */
   __SHRU(reg_r0_12, reg_r0_3, (unsigned int) 8); /* line 364 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 365 */
} /* line 365 */
  sim_icache_fetch(211 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_19, reg_r0_19, reg_r0_7); /* line 367 */
   __ZXTB(reg_r0_16, reg_r0_16); /* line 368 */
   __AND(reg_r0_12, reg_r0_12, (unsigned int) 255); /* line 369 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 370 */
   __AND(reg_r0_21, reg_r0_6, (unsigned int) 255); /* line 371 */
   __SHRU(reg_r0_7, reg_r0_6, (unsigned int) 8); /* line 372 */
} /* line 372 */
  sim_icache_fetch(217 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_19, reg_r0_19, reg_r0_17); /* line 374 */
   __SHL(reg_r0_22, reg_r0_16, (unsigned int) 8); /* line 375 */
   __SHL(reg_r0_17, reg_r0_16, (unsigned int) 16); /* line 376 */
   __MAX(reg_r0_20, reg_r0_20, reg_r0_12); /* line 377 */
   __AND(reg_r0_7, reg_r0_7, (unsigned int) 255); /* line 378 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 379 */
} /* line 379 */
  sim_icache_fetch(223 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_16, reg_r0_16, reg_r0_17); /* line 381 */
   __MAX(reg_r0_20, reg_r0_20, reg_r0_3); /* line 382 */
   __MAX(reg_r0_21, reg_r0_21, reg_r0_7); /* line 383 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 384 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 48),0,4)); /* line 385 */
} /* line 385 */
  sim_icache_fetch(228 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __OR(reg_r0_16, reg_r0_16, reg_r0_22); /* line 387 */
   __ZXTB(reg_r0_20, reg_r0_20); /* line 388 */
   __MAX(reg_r0_21, reg_r0_21, reg_r0_6); /* line 389 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 52),0,4)); /* line 390 */
} /* line 390 */
  sim_icache_fetch(232 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_12, reg_r0_20, (unsigned int) 8); /* line 392 */
   __SHL(reg_r0_7, reg_r0_20, (unsigned int) 16); /* line 393 */
   __ZXTB(reg_r0_21, reg_r0_21); /* line 394 */
   __AND(reg_r0_22, reg_r0_3, (unsigned int) 255); /* line 395 */
   __SHRU(reg_r0_17, reg_r0_3, (unsigned int) 8); /* line 396 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 397 */
} /* line 397 */
  sim_icache_fetch(238 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_20, reg_r0_20, reg_r0_7); /* line 399 */
   __SHL(reg_r0_23, reg_r0_21, (unsigned int) 8); /* line 400 */
   __SHL(reg_r0_7, reg_r0_21, (unsigned int) 16); /* line 401 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 402 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 403 */
   __SHRU(reg_r0_24, reg_r0_6, (unsigned int) 8); /* line 404 */
} /* line 404 */
  sim_icache_fetch(244 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_20, reg_r0_20, reg_r0_12); /* line 406 */
   __OR(reg_r0_21, reg_r0_21, reg_r0_7); /* line 407 */
   __MAX(reg_r0_22, reg_r0_22, reg_r0_17); /* line 408 */
   __AND(reg_r0_7, reg_r0_6, (unsigned int) 255); /* line 409 */
   __AND(reg_r0_24, reg_r0_24, (unsigned int) 255); /* line 410 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 411 */
} /* line 411 */
  sim_icache_fetch(250 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_21, reg_r0_21, reg_r0_23); /* line 413 */
   __MAX(reg_r0_22, reg_r0_22, reg_r0_3); /* line 414 */
   __MAX(reg_r0_7, reg_r0_7, reg_r0_24); /* line 415 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 416 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 56),0,4)); /* line 417 */
} /* line 417 */
  sim_icache_fetch(255 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_22, reg_r0_22); /* line 419 */
   __MAX(reg_r0_7, reg_r0_7, reg_r0_6); /* line 420 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 60),0,4)); /* line 421 */
} /* line 421 */
  sim_icache_fetch(258 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_17, reg_r0_22, (unsigned int) 8); /* line 423 */
   __SHL(reg_r0_12, reg_r0_22, (unsigned int) 16); /* line 424 */
   __ZXTB(reg_r0_7, reg_r0_7); /* line 425 */
   __AND(reg_r0_24, reg_r0_3, (unsigned int) 255); /* line 426 */
   __SHRU(reg_r0_23, reg_r0_3, (unsigned int) 8); /* line 427 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 428 */
} /* line 428 */
  sim_icache_fetch(264 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_22, reg_r0_22, reg_r0_12); /* line 430 */
   __SHL(reg_r0_25, reg_r0_7, (unsigned int) 8); /* line 431 */
   __SHL(reg_r0_12, reg_r0_7, (unsigned int) 16); /* line 432 */
   __AND(reg_r0_23, reg_r0_23, (unsigned int) 255); /* line 433 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 434 */
   __SHRU(reg_r0_26, reg_r0_6, (unsigned int) 8); /* line 435 */
} /* line 435 */
  sim_icache_fetch(270 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_22, reg_r0_22, reg_r0_17); /* line 437 */
   __OR(reg_r0_7, reg_r0_7, reg_r0_12); /* line 438 */
   __MAX(reg_r0_24, reg_r0_24, reg_r0_23); /* line 439 */
   __AND(reg_r0_12, reg_r0_6, (unsigned int) 255); /* line 440 */
   __AND(reg_r0_26, reg_r0_26, (unsigned int) 255); /* line 441 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 442 */
} /* line 442 */
  sim_icache_fetch(276 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_7, reg_r0_7, reg_r0_25); /* line 444 */
   __MAX(reg_r0_24, reg_r0_24, reg_r0_3); /* line 445 */
   __MAX(reg_r0_12, reg_r0_12, reg_r0_26); /* line 446 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 447 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 64),0,4)); /* line 448 */
} /* line 448 */
  sim_icache_fetch(281 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_24, reg_r0_24); /* line 450 */
   __MAX(reg_r0_12, reg_r0_12, reg_r0_6); /* line 451 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 68),0,4)); /* line 452 */
} /* line 452 */
  sim_icache_fetch(284 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_23, reg_r0_24, (unsigned int) 8); /* line 454 */
   __SHL(reg_r0_17, reg_r0_24, (unsigned int) 16); /* line 455 */
   __ZXTB(reg_r0_12, reg_r0_12); /* line 456 */
   __AND(reg_r0_26, reg_r0_3, (unsigned int) 255); /* line 457 */
   __SHRU(reg_r0_25, reg_r0_3, (unsigned int) 8); /* line 458 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 459 */
} /* line 459 */
  sim_icache_fetch(290 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_24, reg_r0_24, reg_r0_17); /* line 461 */
   __SHL(reg_r0_27, reg_r0_12, (unsigned int) 8); /* line 462 */
   __SHL(reg_r0_17, reg_r0_12, (unsigned int) 16); /* line 463 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 464 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 465 */
   __SHRU(reg_r0_28, reg_r0_6, (unsigned int) 8); /* line 466 */
} /* line 466 */
  sim_icache_fetch(296 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_24, reg_r0_24, reg_r0_23); /* line 468 */
   __OR(reg_r0_12, reg_r0_12, reg_r0_17); /* line 469 */
   __MAX(reg_r0_26, reg_r0_26, reg_r0_25); /* line 470 */
   __AND(reg_r0_17, reg_r0_6, (unsigned int) 255); /* line 471 */
   __AND(reg_r0_28, reg_r0_28, (unsigned int) 255); /* line 472 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 473 */
} /* line 473 */
  sim_icache_fetch(302 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_12, reg_r0_12, reg_r0_27); /* line 475 */
   __MAX(reg_r0_26, reg_r0_26, reg_r0_3); /* line 476 */
   __MAX(reg_r0_17, reg_r0_17, reg_r0_28); /* line 477 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 478 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 72),0,4)); /* line 479 */
} /* line 479 */
  sim_icache_fetch(307 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_26, reg_r0_26); /* line 481 */
   __MAX(reg_r0_17, reg_r0_17, reg_r0_6); /* line 482 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 76),0,4)); /* line 483 */
} /* line 483 */
  sim_icache_fetch(310 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_25, reg_r0_26, (unsigned int) 8); /* line 485 */
   __SHL(reg_r0_23, reg_r0_26, (unsigned int) 16); /* line 486 */
   __ZXTB(reg_r0_17, reg_r0_17); /* line 487 */
   __AND(reg_r0_28, reg_r0_3, (unsigned int) 255); /* line 488 */
   __SHRU(reg_r0_27, reg_r0_3, (unsigned int) 8); /* line 489 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 490 */
} /* line 490 */
  sim_icache_fetch(316 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_26, reg_r0_26, reg_r0_23); /* line 492 */
   __SHL(reg_r0_29, reg_r0_17, (unsigned int) 8); /* line 493 */
   __SHL(reg_r0_23, reg_r0_17, (unsigned int) 16); /* line 494 */
   __AND(reg_r0_27, reg_r0_27, (unsigned int) 255); /* line 495 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 496 */
   __SHRU(reg_r0_30, reg_r0_6, (unsigned int) 8); /* line 497 */
} /* line 497 */
  sim_icache_fetch(322 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_26, reg_r0_26, reg_r0_25); /* line 499 */
   __OR(reg_r0_17, reg_r0_17, reg_r0_23); /* line 500 */
   __MAX(reg_r0_28, reg_r0_28, reg_r0_27); /* line 501 */
   __AND(reg_r0_23, reg_r0_6, (unsigned int) 255); /* line 502 */
   __AND(reg_r0_30, reg_r0_30, (unsigned int) 255); /* line 503 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 504 */
} /* line 504 */
  sim_icache_fetch(328 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_17, reg_r0_17, reg_r0_29); /* line 506 */
   __MAX(reg_r0_28, reg_r0_28, reg_r0_3); /* line 507 */
   __MAX(reg_r0_23, reg_r0_23, reg_r0_30); /* line 508 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 509 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 80),0,4)); /* line 510 */
} /* line 510 */
  sim_icache_fetch(333 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_28, reg_r0_28); /* line 512 */
   __MAX(reg_r0_23, reg_r0_23, reg_r0_6); /* line 513 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 84),0,4)); /* line 514 */
} /* line 514 */
  sim_icache_fetch(336 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_27, reg_r0_28, (unsigned int) 8); /* line 516 */
   __SHL(reg_r0_25, reg_r0_28, (unsigned int) 16); /* line 517 */
   __ZXTB(reg_r0_23, reg_r0_23); /* line 518 */
   __AND(reg_r0_30, reg_r0_3, (unsigned int) 255); /* line 519 */
   __SHRU(reg_r0_29, reg_r0_3, (unsigned int) 8); /* line 520 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 521 */
} /* line 521 */
  sim_icache_fetch(342 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_28, reg_r0_28, reg_r0_25); /* line 523 */
   __SHL(reg_r0_31, reg_r0_23, (unsigned int) 8); /* line 524 */
   __SHL(reg_r0_25, reg_r0_23, (unsigned int) 16); /* line 525 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 526 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 527 */
   __SHRU(reg_r0_32, reg_r0_6, (unsigned int) 8); /* line 528 */
} /* line 528 */
  sim_icache_fetch(348 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_28, reg_r0_28, reg_r0_27); /* line 530 */
   __OR(reg_r0_23, reg_r0_23, reg_r0_25); /* line 531 */
   __MAX(reg_r0_30, reg_r0_30, reg_r0_29); /* line 532 */
   __AND(reg_r0_25, reg_r0_6, (unsigned int) 255); /* line 533 */
   __AND(reg_r0_32, reg_r0_32, (unsigned int) 255); /* line 534 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 535 */
} /* line 535 */
  sim_icache_fetch(354 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_23, reg_r0_23, reg_r0_31); /* line 537 */
   __MAX(reg_r0_30, reg_r0_30, reg_r0_3); /* line 538 */
   __MAX(reg_r0_25, reg_r0_25, reg_r0_32); /* line 539 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 540 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 88),0,4)); /* line 541 */
} /* line 541 */
  sim_icache_fetch(359 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_30, reg_r0_30); /* line 543 */
   __MAX(reg_r0_25, reg_r0_25, reg_r0_6); /* line 544 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 92),0,4)); /* line 545 */
} /* line 545 */
  sim_icache_fetch(362 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_29, reg_r0_30, (unsigned int) 8); /* line 547 */
   __SHL(reg_r0_27, reg_r0_30, (unsigned int) 16); /* line 548 */
   __ZXTB(reg_r0_25, reg_r0_25); /* line 549 */
   __AND(reg_r0_32, reg_r0_3, (unsigned int) 255); /* line 550 */
   __SHRU(reg_r0_31, reg_r0_3, (unsigned int) 8); /* line 551 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 552 */
} /* line 552 */
  sim_icache_fetch(368 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_30, reg_r0_30, reg_r0_27); /* line 554 */
   __SHL(reg_r0_33, reg_r0_25, (unsigned int) 8); /* line 555 */
   __SHL(reg_r0_27, reg_r0_25, (unsigned int) 16); /* line 556 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 557 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 558 */
   __SHRU(reg_r0_34, reg_r0_6, (unsigned int) 8); /* line 559 */
} /* line 559 */
  sim_icache_fetch(374 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_30, reg_r0_30, reg_r0_29); /* line 561 */
   __OR(reg_r0_25, reg_r0_25, reg_r0_27); /* line 562 */
   __MAX(reg_r0_32, reg_r0_32, reg_r0_31); /* line 563 */
   __AND(reg_r0_27, reg_r0_6, (unsigned int) 255); /* line 564 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 565 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 566 */
} /* line 566 */
  sim_icache_fetch(380 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_25, reg_r0_25, reg_r0_33); /* line 568 */
   __MAX(reg_r0_32, reg_r0_32, reg_r0_3); /* line 569 */
   __MAX(reg_r0_27, reg_r0_27, reg_r0_34); /* line 570 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 571 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 96),0,4)); /* line 572 */
} /* line 572 */
  sim_icache_fetch(385 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_32, reg_r0_32); /* line 574 */
   __MAX(reg_r0_27, reg_r0_27, reg_r0_6); /* line 575 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 100),0,4)); /* line 576 */
} /* line 576 */
  sim_icache_fetch(388 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_31, reg_r0_32, (unsigned int) 8); /* line 578 */
   __SHL(reg_r0_29, reg_r0_32, (unsigned int) 16); /* line 579 */
   __ZXTB(reg_r0_27, reg_r0_27); /* line 580 */
   __AND(reg_r0_34, reg_r0_3, (unsigned int) 255); /* line 581 */
   __SHRU(reg_r0_33, reg_r0_3, (unsigned int) 8); /* line 582 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 583 */
} /* line 583 */
  sim_icache_fetch(394 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_32, reg_r0_32, reg_r0_29); /* line 585 */
   __SHL(reg_r0_35, reg_r0_27, (unsigned int) 8); /* line 586 */
   __SHL(reg_r0_29, reg_r0_27, (unsigned int) 16); /* line 587 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 588 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 589 */
   __SHRU(reg_r0_36, reg_r0_6, (unsigned int) 8); /* line 590 */
} /* line 590 */
  sim_icache_fetch(400 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_32, reg_r0_32, reg_r0_31); /* line 592 */
   __OR(reg_r0_27, reg_r0_27, reg_r0_29); /* line 593 */
   __MAX(reg_r0_34, reg_r0_34, reg_r0_33); /* line 594 */
   __AND(reg_r0_29, reg_r0_6, (unsigned int) 255); /* line 595 */
   __AND(reg_r0_36, reg_r0_36, (unsigned int) 255); /* line 596 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 597 */
} /* line 597 */
  sim_icache_fetch(406 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_27, reg_r0_27, reg_r0_35); /* line 599 */
   __MAX(reg_r0_34, reg_r0_34, reg_r0_3); /* line 600 */
   __MAX(reg_r0_29, reg_r0_29, reg_r0_36); /* line 601 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 602 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 104),0,4)); /* line 603 */
} /* line 603 */
  sim_icache_fetch(411 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_34, reg_r0_34); /* line 605 */
   __MAX(reg_r0_29, reg_r0_29, reg_r0_6); /* line 606 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 108),0,4)); /* line 607 */
} /* line 607 */
  sim_icache_fetch(414 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_33, reg_r0_34, (unsigned int) 8); /* line 609 */
   __SHL(reg_r0_31, reg_r0_34, (unsigned int) 16); /* line 610 */
   __ZXTB(reg_r0_29, reg_r0_29); /* line 611 */
   __AND(reg_r0_36, reg_r0_3, (unsigned int) 255); /* line 612 */
   __SHRU(reg_r0_35, reg_r0_3, (unsigned int) 8); /* line 613 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 614 */
} /* line 614 */
  sim_icache_fetch(420 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_34, reg_r0_34, reg_r0_31); /* line 616 */
   __SHL(reg_r0_37, reg_r0_29, (unsigned int) 8); /* line 617 */
   __SHL(reg_r0_31, reg_r0_29, (unsigned int) 16); /* line 618 */
   __AND(reg_r0_35, reg_r0_35, (unsigned int) 255); /* line 619 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 620 */
   __SHRU(reg_r0_38, reg_r0_6, (unsigned int) 8); /* line 621 */
} /* line 621 */
  sim_icache_fetch(426 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_34, reg_r0_34, reg_r0_33); /* line 623 */
   __OR(reg_r0_29, reg_r0_29, reg_r0_31); /* line 624 */
   __MAX(reg_r0_36, reg_r0_36, reg_r0_35); /* line 625 */
   __AND(reg_r0_31, reg_r0_6, (unsigned int) 255); /* line 626 */
   __AND(reg_r0_38, reg_r0_38, (unsigned int) 255); /* line 627 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 628 */
} /* line 628 */
  sim_icache_fetch(432 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_29, reg_r0_29, reg_r0_37); /* line 630 */
   __MAX(reg_r0_36, reg_r0_36, reg_r0_3); /* line 631 */
   __MAX(reg_r0_31, reg_r0_31, reg_r0_38); /* line 632 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 633 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 112),0,4)); /* line 634 */
} /* line 634 */
  sim_icache_fetch(437 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_36, reg_r0_36); /* line 636 */
   __MAX(reg_r0_31, reg_r0_31, reg_r0_6); /* line 637 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 116),0,4)); /* line 638 */
} /* line 638 */
  sim_icache_fetch(440 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_35, reg_r0_36, (unsigned int) 8); /* line 640 */
   __SHL(reg_r0_33, reg_r0_36, (unsigned int) 16); /* line 641 */
   __ZXTB(reg_r0_31, reg_r0_31); /* line 642 */
   __AND(reg_r0_38, reg_r0_3, (unsigned int) 255); /* line 643 */
   __SHRU(reg_r0_37, reg_r0_3, (unsigned int) 8); /* line 644 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 645 */
} /* line 645 */
  sim_icache_fetch(446 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_36, reg_r0_36, reg_r0_33); /* line 647 */
   __SHL(reg_r0_39, reg_r0_31, (unsigned int) 8); /* line 648 */
   __SHL(reg_r0_33, reg_r0_31, (unsigned int) 16); /* line 649 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 650 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 651 */
   __SHRU(reg_r0_40, reg_r0_6, (unsigned int) 8); /* line 652 */
} /* line 652 */
  sim_icache_fetch(452 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_36, reg_r0_36, reg_r0_35); /* line 654 */
   __OR(reg_r0_31, reg_r0_31, reg_r0_33); /* line 655 */
   __MAX(reg_r0_38, reg_r0_38, reg_r0_37); /* line 656 */
   __AND(reg_r0_33, reg_r0_6, (unsigned int) 255); /* line 657 */
   __AND(reg_r0_40, reg_r0_40, (unsigned int) 255); /* line 658 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 659 */
} /* line 659 */
  sim_icache_fetch(458 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __OR(reg_r0_31, reg_r0_31, reg_r0_39); /* line 661 */
   __MAX(reg_r0_38, reg_r0_38, reg_r0_3); /* line 662 */
   __MAX(reg_r0_33, reg_r0_33, reg_r0_40); /* line 663 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 664 */
   __LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 120),0,4)); /* line 665 */
} /* line 665 */
  sim_icache_fetch(463 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ZXTB(reg_r0_38, reg_r0_38); /* line 667 */
   __MAX(reg_r0_33, reg_r0_33, reg_r0_6); /* line 668 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 124),0,4)); /* line 669 */
} /* line 669 */
  sim_icache_fetch(466 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHL(reg_r0_37, reg_r0_38, (unsigned int) 8); /* line 671 */
   __SHL(reg_r0_35, reg_r0_38, (unsigned int) 16); /* line 672 */
   __ZXTB(reg_r0_33, reg_r0_33); /* line 673 */
   __AND(reg_r0_40, reg_r0_3, (unsigned int) 255); /* line 674 */
   __SHRU(reg_r0_39, reg_r0_3, (unsigned int) 8); /* line 675 */
   __SHRU(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 676 */
} /* line 676 */
  sim_icache_fetch(472 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_38, reg_r0_38, reg_r0_35); /* line 678 */
   __SHL(reg_r0_41, reg_r0_33, (unsigned int) 8); /* line 679 */
   __SHL(reg_r0_35, reg_r0_33, (unsigned int) 16); /* line 680 */
   __AND(reg_r0_39, reg_r0_39, (unsigned int) 255); /* line 681 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 682 */
   __SHRU(reg_r0_42, reg_r0_6, (unsigned int) 8); /* line 683 */
} /* line 683 */
  sim_icache_fetch(478 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __OR(reg_r0_38, reg_r0_38, reg_r0_37); /* line 685 */
   __OR(reg_r0_33, reg_r0_33, reg_r0_35); /* line 686 */
   __MAX(reg_r0_40, reg_r0_40, reg_r0_39); /* line 687 */
   __AND(reg_r0_35, reg_r0_6, (unsigned int) 255); /* line 688 */
   __AND(reg_r0_42, reg_r0_42, (unsigned int) 255); /* line 689 */
   __SHRU(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 690 */
} /* line 690 */
  sim_icache_fetch(484 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __STW(mem_trace_st(reg_r0_5,0,4), reg_r0_8); /* line 692 */
   __OR(reg_r0_33, reg_r0_33, reg_r0_41); /* line 693 */
   __MAX(reg_r0_40, reg_r0_40, reg_r0_3); /* line 694 */
   __MAX(reg_r0_35, reg_r0_35, reg_r0_42); /* line 695 */
   __AND(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 696 */
} /* line 696 */
  sim_icache_fetch(489 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 4),0,4), reg_r0_11); /* line 698 */
   __ZXTB(reg_r0_40, reg_r0_40); /* line 699 */
   __MAX(reg_r0_35, reg_r0_35, reg_r0_6); /* line 700 */
} /* line 700 */
  sim_icache_fetch(492 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 8),0,4), reg_r0_13); /* line 702 */
   __SHL(reg_r0_6, reg_r0_40, (unsigned int) 8); /* line 703 */
   __SHL(reg_r0_3, reg_r0_40, (unsigned int) 16); /* line 704 */
   __ZXTB(reg_r0_35, reg_r0_35); /* line 705 */
} /* line 705 */
  sim_icache_fetch(496 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 12),0,4), reg_r0_10); /* line 707 */
   __OR(reg_r0_40, reg_r0_40, reg_r0_3); /* line 708 */
   __SHL(reg_r0_8, reg_r0_35, (unsigned int) 8); /* line 709 */
   __SHL(reg_r0_3, reg_r0_35, (unsigned int) 16); /* line 710 */
} /* line 710 */
  sim_icache_fetch(500 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 16),0,4), reg_r0_14); /* line 712 */
   __OR(reg_r0_40, reg_r0_40, reg_r0_6); /* line 713 */
   __OR(reg_r0_35, reg_r0_35, reg_r0_3); /* line 714 */
} /* line 714 */
  sim_icache_fetch(503 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 20),0,4), reg_r0_9); /* line 716 */
   __OR(reg_r0_35, reg_r0_35, reg_r0_8); /* line 717 */
} /* line 717 */
  sim_icache_fetch(505 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 24),0,4), reg_r0_18); /* line 719 */
} /* line 719 */
  sim_icache_fetch(506 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 28),0,4), reg_r0_15); /* line 721 */
} /* line 721 */
  sim_icache_fetch(507 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 32),0,4), reg_r0_19); /* line 723 */
} /* line 723 */
  sim_icache_fetch(508 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 36),0,4), reg_r0_16); /* line 725 */
} /* line 725 */
  sim_icache_fetch(509 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 40),0,4), reg_r0_20); /* line 727 */
} /* line 727 */
  sim_icache_fetch(510 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 44),0,4), reg_r0_21); /* line 729 */
} /* line 729 */
  sim_icache_fetch(511 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 48),0,4), reg_r0_22); /* line 731 */
} /* line 731 */
  sim_icache_fetch(512 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 52),0,4), reg_r0_7); /* line 733 */
} /* line 733 */
  sim_icache_fetch(513 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 56),0,4), reg_r0_24); /* line 735 */
} /* line 735 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 60),0,4), reg_r0_12); /* line 737 */
} /* line 737 */
  sim_icache_fetch(515 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 64),0,4), reg_r0_26); /* line 739 */
} /* line 739 */
  sim_icache_fetch(516 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 68),0,4), reg_r0_17); /* line 741 */
} /* line 741 */
  sim_icache_fetch(517 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 72),0,4), reg_r0_28); /* line 743 */
} /* line 743 */
  sim_icache_fetch(518 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 76),0,4), reg_r0_23); /* line 745 */
} /* line 745 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 80),0,4), reg_r0_30); /* line 747 */
} /* line 747 */
  sim_icache_fetch(520 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 84),0,4), reg_r0_25); /* line 749 */
} /* line 749 */
  sim_icache_fetch(521 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 88),0,4), reg_r0_32); /* line 751 */
} /* line 751 */
  sim_icache_fetch(522 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 92),0,4), reg_r0_27); /* line 753 */
} /* line 753 */
  sim_icache_fetch(523 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 96),0,4), reg_r0_34); /* line 755 */
} /* line 755 */
  sim_icache_fetch(524 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 100),0,4), reg_r0_29); /* line 757 */
} /* line 757 */
  sim_icache_fetch(525 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 104),0,4), reg_r0_36); /* line 759 */
} /* line 759 */
  sim_icache_fetch(526 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 108),0,4), reg_r0_31); /* line 761 */
} /* line 761 */
  sim_icache_fetch(527 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 112),0,4), reg_r0_38); /* line 763 */
} /* line 763 */
  sim_icache_fetch(528 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 116),0,4), reg_r0_33); /* line 765 */
} /* line 765 */
  sim_icache_fetch(529 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 120),0,4), reg_r0_40); /* line 767 */
} /* line 767 */
  sim_icache_fetch(530 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_5 + (unsigned int) 124),0,4), reg_r0_35); /* line 769 */
} /* line 769 */
  sim_icache_fetch(531 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __PFT(mem_trace_pf((reg_r0_5 + (unsigned int) 128),0,4)); /* line 771 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 128); /* line 772 */
} /* line 772 */
  sim_icache_fetch(533 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __PFT(mem_trace_pf((reg_r0_2 + (unsigned int) 128),0,4)); /* line 774 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 128); /* line 775 */
   __GOTO(l_L6X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L6X3;
} /* line 776 */
l_L7X3: ;/* line 779 */
__LABEL(l_L7X3);
  sim_icache_fetch(536 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_43, (unsigned int) 1); /* line 780 */
   __ADD(reg_r0_7, reg_r0_45, (unsigned int) 256); /* line 781 */
} /* line 781 */
  sim_icache_fetch(539 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_6, reg_r0_44, (unsigned int) 256); /* line 783 */
   __GOTO(l_L4X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L4X3;
} /* line 784 */
l_L5X3: ;/* line 787 */
__LABEL(l_L5X3);
		 /* line 787 */
  sim_icache_fetch(542 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 790 */
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
} /* line 790 */
l_lr_14: ;/* line 790 */
__LABEL(l_lr_14);
  sim_icache_fetch(546 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 792 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 793 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 794 */
   __ADD_CYCLES(1);
} /* line 794 */
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 796 */
} /* line 796 */
  sim_icache_fetch(550 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 798 */
} /* line 798 */
  sim_icache_fetch(551 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 800 */
} /* line 800 */
  sim_icache_fetch(552 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 802 */
} /* line 802 */
  sim_icache_fetch(553 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 804 */
} /* line 804 */
  sim_icache_fetch(554 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 806 */
} /* line 806 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 809 */
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

