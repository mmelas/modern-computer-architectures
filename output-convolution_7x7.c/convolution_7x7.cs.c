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

unsigned int strbuf[3];
unsigned int conv7_result[4096];
unsigned int conv7_image[4096];

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

static unsigned int _X1STRINGPACKETX1[7]; 
unsigned int filter7x7[49]; 
static unsigned int _X1STRINGPACKETX1[7] = { 
	0x436F6E76,
	0x6F6C7574,
	0x696F6E20,
	0x3778373A,
	0x20737563,
	0x63657373,
	0x0A000000
}; 

unsigned int filter7x7[49] = { 
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020,
	0x00000020
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
  reg_l0_0 = (118 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 93 */
} /* line 93 */
  sim_icache_fetch(13 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 95 */
} /* line 95 */
  sim_icache_fetch(14 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_58); /* line 97 */
} /* line 97 */
  sim_icache_fetch(15 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_59); /* line 99 */
} /* line 99 */
  sim_icache_fetch(16 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_60); /* line 101 */
} /* line 101 */
  sim_icache_fetch(17 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_61); /* line 103 */
} /* line 103 */
  sim_icache_fetch(18 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_62); /* line 105 */
} /* line 105 */
		 /* line 106 */
  sim_icache_fetch(19 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_63); /* line 109 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(NOP);
   reg_l0_0 = (118 << 5);
   {
    typedef unsigned int t_FT ();
    t_FT *t_call = (t_FT*) NOP;
    reg_r0_3 =     (*t_call)();
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 109 */
l_lr_6: ;/* line 109 */
__LABEL(l_lr_6);
  sim_icache_fetch(22 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, (unsigned int) -4096); /* line 111 */
   __MOV(reg_r0_3, (unsigned int) conv7_result); /* line 112 */
} /* line 112 */
l_L2X3: ;/* line 115 */
__LABEL(l_L2X3);
  sim_icache_fetch(26 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 116 */
   __PFT(mem_trace_pf((reg_r0_3 + (unsigned int) 128),0,4)); /* line 117 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 32); /* line 118 */
} /* line 118 */
  sim_icache_fetch(29 + t_thisfile.offset, 1);
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
} /* line 120 */
  sim_icache_fetch(30 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_3,0,4), 0); /* line 122 */
} /* line 122 */
  sim_icache_fetch(31 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), 0); /* line 124 */
} /* line 124 */
  sim_icache_fetch(32 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), 0); /* line 126 */
} /* line 126 */
  sim_icache_fetch(33 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), 0); /* line 128 */
} /* line 128 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), 0); /* line 130 */
} /* line 130 */
  sim_icache_fetch(35 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), 0); /* line 132 */
} /* line 132 */
  sim_icache_fetch(36 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), 0); /* line 134 */
} /* line 134 */
  sim_icache_fetch(37 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), 0); /* line 136 */
} /* line 136 */
  sim_icache_fetch(38 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), 0); /* line 138 */
} /* line 138 */
  sim_icache_fetch(39 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), 0); /* line 140 */
} /* line 140 */
  sim_icache_fetch(40 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), 0); /* line 142 */
} /* line 142 */
  sim_icache_fetch(41 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), 0); /* line 144 */
} /* line 144 */
  sim_icache_fetch(42 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), 0); /* line 146 */
} /* line 146 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), 0); /* line 148 */
} /* line 148 */
  sim_icache_fetch(44 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), 0); /* line 150 */
} /* line 150 */
  sim_icache_fetch(45 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), 0); /* line 152 */
} /* line 152 */
  sim_icache_fetch(46 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 64),0,4), 0); /* line 154 */
} /* line 154 */
  sim_icache_fetch(47 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 68),0,4), 0); /* line 156 */
} /* line 156 */
  sim_icache_fetch(48 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 72),0,4), 0); /* line 158 */
} /* line 158 */
  sim_icache_fetch(49 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 76),0,4), 0); /* line 160 */
} /* line 160 */
  sim_icache_fetch(50 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 80),0,4), 0); /* line 162 */
} /* line 162 */
  sim_icache_fetch(51 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 84),0,4), 0); /* line 164 */
} /* line 164 */
  sim_icache_fetch(52 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 88),0,4), 0); /* line 166 */
} /* line 166 */
  sim_icache_fetch(53 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 92),0,4), 0); /* line 168 */
} /* line 168 */
  sim_icache_fetch(54 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 96),0,4), 0); /* line 170 */
} /* line 170 */
  sim_icache_fetch(55 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 100),0,4), 0); /* line 172 */
} /* line 172 */
  sim_icache_fetch(56 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 104),0,4), 0); /* line 174 */
} /* line 174 */
  sim_icache_fetch(57 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 108),0,4), 0); /* line 176 */
} /* line 176 */
  sim_icache_fetch(58 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 112),0,4), 0); /* line 178 */
} /* line 178 */
  sim_icache_fetch(59 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 116),0,4), 0); /* line 180 */
} /* line 180 */
  sim_icache_fetch(60 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 120),0,4), 0); /* line 182 */
} /* line 182 */
  sim_icache_fetch(61 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 124),0,4), 0); /* line 184 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 128); /* line 185 */
   __GOTO(l_L2X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L2X3;
} /* line 186 */
l_L3X3: ;/* line 189 */
__LABEL(l_L3X3);
  sim_icache_fetch(64 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_8, 0); /* line 190 */
   __MOV(reg_r0_3, 0); /* line 191 */
   __MOV(reg_r0_40, ((unsigned int) conv7_result + (unsigned int) 1012)); /* line 192 */
} /* line 192 */
l_L4X3: ;/* line 195 */
__LABEL(l_L4X3);
  sim_icache_fetch(68 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_3, (unsigned int) 58); /* line 196 */
   __MOV(reg_r0_4, (unsigned int) -58); /* line 197 */
   __MOV(reg_r0_7, 0); /* line 198 */
} /* line 198 */
  sim_icache_fetch(71 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 200 */
l_L6X3: ;/* line 203 */
__LABEL(l_L6X3);
  sim_icache_fetch(72 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_0, reg_r0_4, 0); /* line 204 */
   __MOV(reg_r0_6, 0); /* line 205 */
   __MOV(reg_r0_5, reg_r0_7); /* line 206 */
   __MOV(reg_r0_12, 0); /* line 207 */
   __MOV(reg_r0_11, 0); /* line 208 */
   __MOV(reg_r0_13, 0); /* line 209 */
} /* line 209 */
  sim_icache_fetch(78 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __MOV(reg_r0_2, (unsigned int) -7); /* line 211 */
   __MOV(reg_r0_38, reg_r0_4); /* line 212 */
   __MOV(reg_r0_39, reg_r0_7); /* line 213 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 214 */
l_L8X3: ;/* line 217 */
__LABEL(l_L8X3);
  sim_icache_fetch(82 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 218 */
   __ADD(reg_r0_9, reg_r0_5, reg_r0_8); /* line 219 */
   __ADD(reg_r0_10, reg_r0_3, (unsigned int) 2); /* line 220 */
   __ADD(reg_r0_4, reg_r0_3, (unsigned int) 6); /* line 221 */
   __SH2ADD(reg_r0_7, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 24)); /* line 222 */
} /* line 222 */
  sim_icache_fetch(88 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SH2ADD(reg_r0_9, reg_r0_9, (unsigned int) conv7_image); /* line 224 */
   __SHL(reg_r0_10, reg_r0_10, (unsigned int) 6); /* line 225 */
   __SHL(reg_r0_4, reg_r0_4, (unsigned int) 6); /* line 226 */
   __LDWs(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 227 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 228 */
  sim_icache_fetch(94 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SH2ADD(reg_r0_15, reg_r0_6, (unsigned int) filter7x7); /* line 230 */
   __LDW(reg_r0_14, mem_trace_ld(reg_r0_9,0,4)); /* line 231 */
   __ADD(reg_r0_10, reg_r0_5, reg_r0_10); /* line 232 */
   __ADD(reg_r0_16, reg_r0_3, (unsigned int) 3); /* line 233 */
   __ADD(reg_r0_4, reg_r0_5, reg_r0_4); /* line 234 */
} /* line 234 */
  sim_icache_fetch(100 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __LDW(reg_r0_17, mem_trace_ld(reg_r0_15,0,4)); /* line 236 */
   __SH2ADD(reg_r0_10, reg_r0_10, (unsigned int) conv7_image); /* line 237 */
   __SHL(reg_r0_16, reg_r0_16, (unsigned int) 6); /* line 238 */
   __SH2ADD(reg_r0_4, reg_r0_4, (unsigned int) conv7_image); /* line 239 */
} /* line 239 */
  sim_icache_fetch(106 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SHRU(reg_r0_18, reg_r0_14, (unsigned int) 8); /* line 241 */
   __SH2ADD(reg_r0_19, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 8)); /* line 242 */
   __ADD(reg_r0_16, reg_r0_5, reg_r0_16); /* line 243 */
   __ADD(reg_r0_20, reg_r0_3, (unsigned int) 5); /* line 244 */
   __LDW(reg_r0_4, mem_trace_ld(reg_r0_4,0,4)); /* line 245 */
} /* line 245 */
  sim_icache_fetch(112 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_18, reg_r0_18, (unsigned int) 255); /* line 247 */
   __LDW(reg_r0_10, mem_trace_ld(reg_r0_10,0,4)); /* line 248 */
   __SH2ADD(reg_r0_16, reg_r0_16, (unsigned int) conv7_image); /* line 249 */
   __SH2ADD(reg_r0_21, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 12)); /* line 250 */
} /* line 250 */
  sim_icache_fetch(118 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MULLU(reg_r0_23, reg_r0_17, reg_r0_18); /* line 252 */
   __MULHS(reg_r0_18, reg_r0_17, reg_r0_18); /* line 253 */
   __ADD(reg_r0_24, reg_r0_3, (unsigned int) 1); /* line 254 */
   __LDW(reg_r0_19, mem_trace_ld(reg_r0_19,0,4)); /* line 255 */
   __SHL(reg_r0_20, reg_r0_20, (unsigned int) 6); /* line 256 */
   __SHRU(reg_r0_22, reg_r0_4, (unsigned int) 8); /* line 257 */
} /* line 257 */
  sim_icache_fetch(124 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SHRU(reg_r0_25, reg_r0_10, (unsigned int) 8); /* line 259 */
   __LDW(reg_r0_16, mem_trace_ld(reg_r0_16,0,4)); /* line 260 */
   __ADD(reg_r0_20, reg_r0_5, reg_r0_20); /* line 261 */
   __SH2ADD(reg_r0_26, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 20)); /* line 262 */
   __AND(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 263 */
} /* line 263 */
  sim_icache_fetch(130 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_23, reg_r0_23, reg_r0_18); /* line 265 */
   __SHL(reg_r0_24, reg_r0_24, (unsigned int) 6); /* line 266 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 267 */
   __LDW(reg_r0_21, mem_trace_ld(reg_r0_21,0,4)); /* line 268 */
   __MULLU(reg_r0_27, reg_r0_7, reg_r0_22); /* line 269 */
   __MULHS(reg_r0_22, reg_r0_7, reg_r0_22); /* line 270 */
} /* line 270 */
  sim_icache_fetch(136 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_0, reg_r0_23, 0); /* line 272 */
   __ADD(reg_r0_18, reg_r0_23, (unsigned int) 255); /* line 273 */
   __MULLU(reg_r0_28, reg_r0_19, reg_r0_25); /* line 274 */
   __MULHS(reg_r0_25, reg_r0_19, reg_r0_25); /* line 275 */
   __SHRU(reg_r0_29, reg_r0_16, (unsigned int) 8); /* line 276 */
   __LDW(reg_r0_26, mem_trace_ld(reg_r0_26,0,4)); /* line 277 */
} /* line 277 */
  sim_icache_fetch(142 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SLCT(reg_r0_18, reg_b0_0, reg_r0_18, reg_r0_23); /* line 279 */
   __ADD(reg_r0_24, reg_r0_5, reg_r0_24); /* line 280 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 281 */
   __SH2ADD(reg_r0_20, reg_r0_20, (unsigned int) conv7_image); /* line 282 */
   __ADD(reg_r0_27, reg_r0_27, reg_r0_22); /* line 283 */
} /* line 283 */
  sim_icache_fetch(148 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 285 */
   __ADD(reg_r0_28, reg_r0_28, reg_r0_25); /* line 286 */
   __MULLU(reg_r0_23, reg_r0_21, reg_r0_29); /* line 287 */
   __MULHS(reg_r0_29, reg_r0_21, reg_r0_29); /* line 288 */
   __CMPLT(reg_b0_0, reg_r0_27, 0); /* line 289 */
   __ADD(reg_r0_22, reg_r0_27, (unsigned int) 255); /* line 290 */
} /* line 290 */
  sim_icache_fetch(154 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SH2ADD(reg_r0_24, reg_r0_24, (unsigned int) conv7_image); /* line 292 */
   __CMPLT(reg_b0_0, reg_r0_28, 0); /* line 293 */
   __ADD(reg_r0_25, reg_r0_28, (unsigned int) 255); /* line 294 */
   __LDW(reg_r0_20, mem_trace_ld(reg_r0_20,0,4)); /* line 295 */
   __SLCT(reg_r0_22, t__i32_0, reg_r0_22, reg_r0_27); /* line 296 */
} /* line 296 */
  sim_icache_fetch(160 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SH2ADD(reg_r0_27, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 4)); /* line 298 */
   __LDW(reg_r0_24, mem_trace_ld(reg_r0_24,0,4)); /* line 299 */
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_25, reg_r0_28); /* line 300 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_29); /* line 301 */
   __SHR(reg_r0_22, reg_r0_22, (unsigned int) 8); /* line 302 */
} /* line 302 */
  sim_icache_fetch(166 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_22 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __LDW(reg_r0_27, mem_trace_ld(reg_r0_27,0,4)); /* line 304 */
   __SHR(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 305 */
   __CMPLT(reg_b0_0, reg_r0_23, 0); /* line 306 */
   __ADD(reg_r0_22, reg_r0_23, (unsigned int) 255); /* line 307 */
   __SHRU(reg_r0_28, reg_r0_20, (unsigned int) 8); /* line 308 */
   __ADD(reg_r0_18, reg_r0_18, t__i32_0); /* line 309 */
} /* line 309 */
  sim_icache_fetch(172 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_23 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SHRU(reg_r0_23, reg_r0_24, (unsigned int) 8); /* line 311 */
   __SLCT(reg_r0_22, reg_b0_0, reg_r0_22, t__i32_0); /* line 312 */
   __ADD(reg_r0_29, reg_r0_3, (unsigned int) 4); /* line 313 */
   __SH2ADD(reg_r0_30, reg_r0_6, ((unsigned int) filter7x7 + (unsigned int) 16)); /* line 314 */
   __AND(reg_r0_28, reg_r0_28, (unsigned int) 255); /* line 315 */
} /* line 315 */
  sim_icache_fetch(178 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_23, reg_r0_23, (unsigned int) 255); /* line 317 */
   __SHR(reg_r0_22, reg_r0_22, (unsigned int) 8); /* line 318 */
   __SHL(reg_r0_29, reg_r0_29, (unsigned int) 6); /* line 319 */
   __LDW(reg_r0_30, mem_trace_ld(reg_r0_30,0,4)); /* line 320 */
   __MULLU(reg_r0_31, reg_r0_26, reg_r0_28); /* line 321 */
   __MULHS(reg_r0_28, reg_r0_26, reg_r0_28); /* line 322 */
} /* line 322 */
  sim_icache_fetch(184 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_22 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHRU(reg_r0_33, reg_r0_14, (unsigned int) 16); /* line 324 */
   __MULLU(reg_r0_22, reg_r0_27, reg_r0_23); /* line 325 */
   __MULHS(reg_r0_23, reg_r0_27, reg_r0_23); /* line 326 */
   __ADD(reg_r0_29, reg_r0_5, reg_r0_29); /* line 327 */
   __SHRU(reg_r0_32, reg_r0_4, (unsigned int) 16); /* line 328 */
   __ADD(reg_r0_25, reg_r0_25, t__i32_0); /* line 329 */
} /* line 329 */
  sim_icache_fetch(190 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 331 */
   __SH2ADD(reg_r0_29, reg_r0_29, (unsigned int) conv7_image); /* line 332 */
   __ADD(reg_r0_31, reg_r0_31, reg_r0_28); /* line 333 */
   __AND(reg_r0_32, reg_r0_32, (unsigned int) 255); /* line 334 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_25); /* line 335 */
} /* line 335 */
  sim_icache_fetch(196 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_22, reg_r0_22, reg_r0_23); /* line 337 */
   __LDW(reg_r0_29, mem_trace_ld(reg_r0_29,0,4)); /* line 338 */
   __CMPLT(reg_b0_0, reg_r0_31, 0); /* line 339 */
   __ADD(reg_r0_25, reg_r0_31, (unsigned int) 255); /* line 340 */
   __MULLU(reg_r0_23, reg_r0_7, reg_r0_32); /* line 341 */
   __MULHS(reg_r0_32, reg_r0_7, reg_r0_32); /* line 342 */
} /* line 342 */
  sim_icache_fetch(202 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_31 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MULLU(reg_r0_31, reg_r0_17, reg_r0_33); /* line 344 */
   __MULHS(reg_r0_33, reg_r0_17, reg_r0_33); /* line 345 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 346 */
   __ADD(reg_r0_28, reg_r0_22, (unsigned int) 255); /* line 347 */
   __SHRU(reg_r0_34, reg_r0_10, (unsigned int) 16); /* line 348 */
   __SLCT(reg_r0_25, t__i32_0, reg_r0_25, t__i32_1); /* line 349 */
} /* line 349 */
  sim_icache_fetch(208 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_32 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_28, reg_b0_0, reg_r0_28, reg_r0_22); /* line 351 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 352 */
   __SHRU(reg_r0_32, reg_r0_16, (unsigned int) 16); /* line 353 */
   __SHRU(reg_r0_22, reg_r0_29, (unsigned int) 8); /* line 354 */
   __SHR(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 355 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 356 */
} /* line 356 */
  sim_icache_fetch(214 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_25 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_31, reg_r0_31, reg_r0_33); /* line 358 */
   __SHR(reg_r0_28, reg_r0_28, (unsigned int) 8); /* line 359 */
   __AND(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 360 */
   __CMPLT(reg_b0_0, reg_r0_23, 0); /* line 361 */
   __ADD(reg_r0_25, reg_r0_23, (unsigned int) 255); /* line 362 */
   __ADD(reg_r0_11, reg_r0_11, t__i32_0); /* line 363 */
} /* line 363 */
  sim_icache_fetch(220 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_23 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_0, reg_r0_31, 0); /* line 365 */
   __ADD(reg_r0_23, reg_r0_31, (unsigned int) 255); /* line 366 */
   __MULLU(reg_r0_35, reg_r0_19, reg_r0_34); /* line 367 */
   __MULLU(reg_r0_33, reg_r0_30, reg_r0_22); /* line 368 */
   __MULHS(reg_r0_22, reg_r0_30, reg_r0_22); /* line 369 */
   __SLCT(reg_r0_25, t__i32_0, reg_r0_25, t__i32_1); /* line 370 */
} /* line 370 */
  sim_icache_fetch(226 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_31); /* line 372 */
   __SHRU(reg_r0_36, reg_r0_24, (unsigned int) 16); /* line 373 */
   __MULHS(reg_r0_34, reg_r0_19, reg_r0_34); /* line 374 */
   __AND(reg_r0_32, reg_r0_32, (unsigned int) 255); /* line 375 */
   __SHRU(reg_r0_31, reg_r0_20, (unsigned int) 16); /* line 376 */
   __SHR(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 377 */
} /* line 377 */
  sim_icache_fetch(232 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_22 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 8); /* line 379 */
   __AND(reg_r0_36, reg_r0_36, (unsigned int) 255); /* line 380 */
   __MULLU(reg_r0_22, reg_r0_21, reg_r0_32); /* line 381 */
   __MULHS(reg_r0_32, reg_r0_21, reg_r0_32); /* line 382 */
   __ADD(reg_r0_33, reg_r0_33, t__i32_0); /* line 383 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 384 */
} /* line 384 */
  sim_icache_fetch(238 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_25 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_35, reg_r0_35, reg_r0_34); /* line 386 */
   __CMPLT(reg_b0_0, reg_r0_33, 0); /* line 387 */
   __ADD(reg_r0_37, reg_r0_33, (unsigned int) 255); /* line 388 */
   __MULLU(reg_r0_25, reg_r0_26, reg_r0_31); /* line 389 */
   __MULHS(reg_r0_31, reg_r0_26, reg_r0_31); /* line 390 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 391 */
} /* line 391 */
  sim_icache_fetch(244 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_33 ;
  t__i32_0 = reg_r0_32 ;
  t__i32_1 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MULLU(reg_r0_32, reg_r0_27, reg_r0_36); /* line 393 */
   __MULHS(reg_r0_36, reg_r0_27, reg_r0_36); /* line 394 */
   __CMPLT(reg_b0_0, reg_r0_35, 0); /* line 395 */
   __ADD(reg_r0_33, reg_r0_35, (unsigned int) 255); /* line 396 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_0); /* line 397 */
   __SLCT(reg_r0_37, t__i32_1, reg_r0_37, t__i32_2); /* line 398 */
} /* line 398 */
  sim_icache_fetch(250 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_31 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_33, reg_b0_0, reg_r0_33, reg_r0_35); /* line 400 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 401 */
   __ADD(reg_r0_34, reg_r0_22, (unsigned int) 255); /* line 402 */
   __SHRU(reg_r0_31, reg_r0_29, (unsigned int) 16); /* line 403 */
   __SHR(reg_r0_37, reg_r0_37, (unsigned int) 8); /* line 404 */
   __ADD(reg_r0_25, reg_r0_25, t__i32_0); /* line 405 */
} /* line 405 */
  sim_icache_fetch(256 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_32, reg_r0_32, reg_r0_36); /* line 407 */
   __SHR(reg_r0_33, reg_r0_33, (unsigned int) 8); /* line 408 */
   __SLCT(reg_r0_34, reg_b0_0, reg_r0_34, reg_r0_22); /* line 409 */
   __CMPLT(reg_b0_0, reg_r0_25, 0); /* line 410 */
   __ADD(reg_r0_22, reg_r0_25, (unsigned int) 255); /* line 411 */
   __ADD(reg_r0_28, reg_r0_28, reg_r0_37); /* line 412 */
} /* line 412 */
  sim_icache_fetch(262 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_25 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_0, reg_r0_32, 0); /* line 414 */
   __ADD(reg_r0_25, reg_r0_32, (unsigned int) 255); /* line 415 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 416 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 417 */
   __SLCT(reg_r0_22, t__i32_0, reg_r0_22, t__i32_1); /* line 418 */
   __ADD(reg_r0_11, reg_r0_11, reg_r0_28); /* line 419 */
} /* line 419 */
  sim_icache_fetch(268 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_18 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_25, reg_r0_32); /* line 421 */
   __MULLU(reg_r0_18, reg_r0_30, reg_r0_31); /* line 422 */
   __MULHS(reg_r0_31, reg_r0_30, reg_r0_31); /* line 423 */
   __SHR(reg_r0_22, reg_r0_22, (unsigned int) 8); /* line 424 */
   __ADD(reg_r0_11, t__i32_0, reg_r0_11); /* line 425 */
   __ADD(reg_r0_33, reg_r0_33, reg_r0_34); /* line 426 */
} /* line 426 */
  sim_icache_fetch(274 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_14, reg_r0_14, (unsigned int) 255); /* line 428 */
   __SHR(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 429 */
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 430 */
   __AND(reg_r0_4, reg_r0_4, (unsigned int) 255); /* line 431 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_22); /* line 432 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_33); /* line 433 */
} /* line 433 */
  sim_icache_fetch(280 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MULLU(reg_r0_4, reg_r0_17, reg_r0_14); /* line 435 */
   __MULHS(reg_r0_17, reg_r0_17, reg_r0_14); /* line 436 */
   __AND(reg_r0_16, reg_r0_16, (unsigned int) 255); /* line 437 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_31); /* line 438 */
   __MULLU(reg_r0_22, reg_r0_7, t__i32_0); /* line 439 */
   __MULHS(reg_r0_7, reg_r0_7, t__i32_0); /* line 440 */
} /* line 440 */
  sim_icache_fetch(286 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MULLU(reg_r0_28, reg_r0_19, reg_r0_10); /* line 442 */
   __MULHS(reg_r0_19, reg_r0_19, reg_r0_10); /* line 443 */
   __MULLU(reg_r0_10, reg_r0_21, reg_r0_16); /* line 444 */
   __MULHS(reg_r0_21, reg_r0_21, reg_r0_16); /* line 445 */
   __CMPLT(reg_b0_0, reg_r0_18, 0); /* line 446 */
   __ADD(reg_r0_14, reg_r0_18, (unsigned int) 255); /* line 447 */
} /* line 447 */
  sim_icache_fetch(292 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __ADD(reg_r0_4, reg_r0_4, reg_r0_17); /* line 449 */
   __AND(reg_r0_24, reg_r0_24, (unsigned int) 255); /* line 450 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 451 */
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_18); /* line 452 */
   __AND(reg_r0_20, reg_r0_20, (unsigned int) 255); /* line 453 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_7); /* line 454 */
} /* line 454 */
  sim_icache_fetch(298 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_1, reg_r0_4, 0); /* line 456 */
   __ADD(reg_r0_16, reg_r0_4, (unsigned int) 255); /* line 457 */
   __ADD(reg_r0_28, reg_r0_28, reg_r0_19); /* line 458 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 459 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 460 */
   __ADD(reg_r0_7, reg_r0_22, (unsigned int) 255); /* line 461 */
} /* line 461 */
  sim_icache_fetch(304 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_16, reg_b0_1, reg_r0_16, reg_r0_4); /* line 463 */
   __CMPLT(reg_b0_0, reg_r0_28, 0); /* line 464 */
   __ADD(reg_r0_4, reg_r0_28, (unsigned int) 255); /* line 465 */
   __ADD(reg_r0_10, reg_r0_10, reg_r0_21); /* line 466 */
   __SLCT(reg_r0_7, t__i32_0, reg_r0_7, reg_r0_22); /* line 467 */
   __ADD(reg_r0_25, reg_r0_25, reg_r0_14); /* line 468 */
} /* line 468 */
  sim_icache_fetch(310 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 470 */
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, reg_r0_28); /* line 471 */
   __CMPLT(reg_b0_0, reg_r0_10, 0); /* line 472 */
   __ADD(reg_r0_14, reg_r0_10, (unsigned int) 255); /* line 473 */
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 474 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_25); /* line 475 */
} /* line 475 */
  sim_icache_fetch(316 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 477 */
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_10); /* line 478 */
   __MULLU(reg_r0_7, reg_r0_26, reg_r0_20); /* line 479 */
   __MULHS(reg_r0_26, reg_r0_26, reg_r0_20); /* line 480 */
   __ADD(reg_r0_16, reg_r0_16, t__i32_0); /* line 481 */
   __ADD(reg_r0_12, reg_r0_23, reg_r0_12); /* line 482 */
} /* line 482 */
  sim_icache_fetch(322 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MULLU(reg_r0_10, reg_r0_27, reg_r0_24); /* line 484 */
   __MULHS(reg_r0_27, reg_r0_27, reg_r0_24); /* line 485 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 486 */
   __MULLU(reg_r0_17, reg_r0_30, reg_r0_29); /* line 487 */
   __MULHS(reg_r0_30, reg_r0_30, reg_r0_29); /* line 488 */
   __ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 489 */
} /* line 489 */
  sim_icache_fetch(328 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __PFT(mem_trace_pf((reg_r0_9 + (unsigned int) 32),0,4)); /* line 491 */
   __ADD(reg_r0_7, reg_r0_7, reg_r0_26); /* line 492 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 493 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 494 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 7); /* line 495 */
} /* line 495 */
  sim_icache_fetch(333 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __PFT(mem_trace_pf((reg_r0_15 + (unsigned int) 32),0,4)); /* line 497 */
   __ADD(reg_r0_10, reg_r0_10, reg_r0_27); /* line 498 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_30); /* line 499 */
   __CMPLT(reg_b0_0, reg_r0_7, 0); /* line 500 */
   __ADD(reg_r0_4, reg_r0_7, (unsigned int) 255); /* line 501 */
   __ADD(reg_r0_16, reg_r0_16, t__i32_0); /* line 502 */
} /* line 502 */
  sim_icache_fetch(339 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_7 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __CMPLT(reg_b0_0, reg_r0_10, 0); /* line 504 */
   __ADD(reg_r0_7, reg_r0_10, (unsigned int) 255); /* line 505 */
   __CMPLT(reg_b0_1, reg_r0_17, 0); /* line 506 */
   __ADD(reg_r0_9, reg_r0_17, (unsigned int) 255); /* line 507 */
   __SLCT(reg_r0_4, t__i32_0, reg_r0_4, t__i32_1); /* line 508 */
} /* line 508 */
  sim_icache_fetch(344 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_10); /* line 510 */
   __SLCT(reg_r0_9, reg_b0_1, reg_r0_9, reg_r0_17); /* line 511 */
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 512 */
} /* line 512 */
  sim_icache_fetch(347 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 514 */
   __SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 515 */
   __ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 516 */
} /* line 516 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_7, reg_r0_9); /* line 518 */
} /* line 518 */
  sim_icache_fetch(351 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_13, reg_r0_7); /* line 520 */
} /* line 520 */
  sim_icache_fetch(352 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_13, reg_r0_16, reg_r0_13); /* line 522 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 523 */
l_L9X3: ;/* line 526 */
__LABEL(l_L9X3);
  sim_icache_fetch(354 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MAX(reg_r0_13, reg_r0_13, 0); /* line 527 */
   __MAX(reg_r0_11, reg_r0_11, 0); /* line 528 */
   __MAX(reg_r0_12, reg_r0_12, 0); /* line 529 */
   __SH2ADD(reg_r0_2, reg_r0_38, reg_r0_40); /* line 530 */
   __ADD(reg_r0_4, reg_r0_38, (unsigned int) 1); /* line 531 */
} /* line 531 */
  sim_icache_fetch(359 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __MIN(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 533 */
   __MIN(reg_r0_11, reg_r0_11, (unsigned int) 255); /* line 534 */
   __MIN(reg_r0_12, reg_r0_12, (unsigned int) 255); /* line 535 */
   __PFT(mem_trace_pf((reg_r0_2 + (unsigned int) 32),0,4)); /* line 536 */
   __ADD(reg_r0_7, reg_r0_39, (unsigned int) 1); /* line 537 */
} /* line 537 */
  sim_icache_fetch(364 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 539 */
   __SHL(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 540 */
} /* line 540 */
  sim_icache_fetch(366 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_13, reg_r0_13, reg_r0_12); /* line 542 */
} /* line 542 */
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_13, reg_r0_13, reg_r0_11); /* line 544 */
} /* line 544 */
  sim_icache_fetch(368 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_2,0,4), reg_r0_13); /* line 546 */
   __GOTO(l_L6X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L6X3;
} /* line 547 */
l_L7X3: ;/* line 550 */
__LABEL(l_L7X3);
  sim_icache_fetch(370 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 551 */
   __ADD(reg_r0_8, reg_r0_8, (unsigned int) 64); /* line 552 */
   __ADD(reg_r0_40, reg_r0_40, (unsigned int) 256); /* line 553 */
   __GOTO(l_L4X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L4X3;
} /* line 554 */
l_L5X3: ;/* line 557 */
__LABEL(l_L5X3);
		 /* line 557 */
  sim_icache_fetch(375 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 560 */
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (118 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 560 */
l_lr_16: ;/* line 560 */
__LABEL(l_lr_16);
  sim_icache_fetch(379 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 562 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 563 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 564 */
   __ADD_CYCLES(1);
} /* line 564 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 566 */
} /* line 566 */
  sim_icache_fetch(383 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 568 */
} /* line 568 */
  sim_icache_fetch(384 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 570 */
} /* line 570 */
  sim_icache_fetch(385 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 572 */
} /* line 572 */
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 574 */
} /* line 574 */
  sim_icache_fetch(387 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 576 */
} /* line 576 */
  sim_icache_fetch(388 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 579 */
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
    case 112: goto l_L8X3;
    case 113: goto l_L9X3;
    case 114: goto l_L7X3;
    case 115: goto l_L5X3;
    case 117: goto l_lr_16;
    case 118:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"convolution_7x7.s", 400, 0, 0, 0, 2};

