/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -prefetch -mas_g -mas_G -O3 -o a.out" */

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
  reg_l0_0 = (120 << 5);
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
   reg_l0_0 = (120 << 5);
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
   __MOV(reg_r0_3, (unsigned int) conv7_result); /* line 104 */
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
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 114 */
} /* line 114 */
  sim_icache_fetch(27 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __PFT(mem_trace_pf((reg_r0_3 + (unsigned int) 32),0,4)); /* line 116 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 117 */
  sim_icache_fetch(29 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_3,0,4), 0); /* line 119 */
} /* line 119 */
  sim_icache_fetch(30 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), 0); /* line 121 */
} /* line 121 */
  sim_icache_fetch(31 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), 0); /* line 123 */
} /* line 123 */
  sim_icache_fetch(32 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), 0); /* line 125 */
} /* line 125 */
  sim_icache_fetch(33 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), 0); /* line 127 */
} /* line 127 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), 0); /* line 129 */
} /* line 129 */
  sim_icache_fetch(35 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), 0); /* line 131 */
} /* line 131 */
  sim_icache_fetch(36 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), 0); /* line 133 */
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 32); /* line 135 */
} /* line 135 */
  sim_icache_fetch(38 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L2X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L2X3;
} /* line 137 */
l_L3X3: ;/* line 140 */
__LABEL(l_L3X3);
  sim_icache_fetch(39 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) -58); /* line 141 */
   __MOV(reg_r0_14, 0); /* line 142 */
} /* line 142 */
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_30, ((unsigned int) conv7_result + (unsigned int) 780)); /* line 144 */
} /* line 144 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_32, reg_r0_4); /* line 146 */
} /* line 146 */
l_L4X3: ;/* line 149 */
__LABEL(l_L4X3);
  sim_icache_fetch(44 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 150 */
   __MOV(reg_r0_4, 0); /* line 151 */
} /* line 151 */
  sim_icache_fetch(46 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, (unsigned int) -58); /* line 153 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 154 */
  sim_icache_fetch(48 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_31, reg_r0_3); /* line 156 */
} /* line 156 */
l_L6X3: ;/* line 159 */
__LABEL(l_L6X3);
  sim_icache_fetch(49 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 160 */
   __MOV(reg_r0_13, reg_r0_4); /* line 161 */
} /* line 161 */
  sim_icache_fetch(51 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_6, 0); /* line 163 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 164 */
  sim_icache_fetch(53 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_16, (unsigned int) filter7x7); /* line 166 */
} /* line 166 */
  sim_icache_fetch(55 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_5, 0); /* line 168 */
   __MOV(reg_r0_9, 0); /* line 169 */
} /* line 169 */
  sim_icache_fetch(57 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) -7); /* line 171 */
   __MOV(reg_r0_28, reg_r0_2); /* line 172 */
} /* line 172 */
  sim_icache_fetch(59 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_29, reg_r0_4); /* line 174 */
} /* line 174 */
l_L8X3: ;/* line 177 */
__LABEL(l_L8X3);
  sim_icache_fetch(60 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_3, 0); /* line 178 */
   __ADD(reg_r0_15, reg_r0_13, reg_r0_14); /* line 179 */
} /* line 179 */
  sim_icache_fetch(62 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_11, (unsigned int) -4); /* line 181 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 182 */
  sim_icache_fetch(64 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_15, (unsigned int) conv7_image); /* line 184 */
} /* line 184 */
  sim_icache_fetch(66 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, reg_r0_15); /* line 186 */
   __MOV(reg_r0_8, 0); /* line 187 */
} /* line 187 */
  sim_icache_fetch(68 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_10, 0); /* line 189 */
   __MOV(reg_r0_7, 0); /* line 190 */
} /* line 190 */
  sim_icache_fetch(70 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_4, reg_r0_16); /* line 192 */
   __MOV(reg_r0_24, reg_r0_3); /* line 193 */
} /* line 193 */
  sim_icache_fetch(72 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_12, (unsigned int) 1024); /* line 195 */
} /* line 195 */
  sim_icache_fetch(74 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_25, reg_r0_13); /* line 197 */
   __MOV(reg_r0_26, reg_r0_14); /* line 198 */
} /* line 198 */
  sim_icache_fetch(76 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_27, reg_r0_16); /* line 200 */
} /* line 200 */
l_L10X3: ;/* line 203 */
__LABEL(l_L10X3);
  sim_icache_fetch(77 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 204 */
   __CMPLT(reg_b0_0, reg_r0_11, 0); /* line 205 */
} /* line 205 */
  sim_icache_fetch(79 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_13, mem_trace_ld(reg_r0_4,0,4)); /* line 207 */
   __ADD(reg_r0_11, reg_r0_11, (unsigned int) 4); /* line 208 */
} /* line 208 */
  sim_icache_fetch(81 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __LDW(reg_r0_15, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 210 */
   __SHRU(reg_r0_14, reg_r0_3, (unsigned int) 8); /* line 211 */
} /* line 211 */
  sim_icache_fetch(83 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_16, reg_r0_3, (unsigned int) 16); /* line 213 */
   __AND(reg_r0_14, reg_r0_14, (unsigned int) 255); /* line 214 */
} /* line 214 */
  sim_icache_fetch(85 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_16, reg_r0_16, (unsigned int) 255); /* line 216 */
   __MULLU(reg_r0_17, reg_r0_13, reg_r0_14); /* line 217 */
} /* line 217 */
  sim_icache_fetch(87 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_14, reg_r0_13, reg_r0_14); /* line 219 */
   __LDW(reg_r0_18, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 220 */
} /* line 220 */
  sim_icache_fetch(89 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_19, mem_trace_ld((reg_r0_2 + (unsigned int) 512),0,4)); /* line 222 */
} /* line 222 */
  sim_icache_fetch(91 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_14, reg_r0_13, reg_r0_16); /* line 224 */
   __ADD(reg_r0_17, reg_r0_17, t__i32_0); /* line 225 */
} /* line 225 */
  sim_icache_fetch(93 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_17, 0); /* line 227 */
   __ADD(reg_r0_20, reg_r0_17, (unsigned int) 255); /* line 228 */
} /* line 228 */
  sim_icache_fetch(95 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_20, reg_b0_1, reg_r0_20, reg_r0_17); /* line 230 */
   __SHRU(reg_r0_17, reg_r0_19, (unsigned int) 8); /* line 231 */
} /* line 231 */
  sim_icache_fetch(97 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_20, reg_r0_20, (unsigned int) 8); /* line 233 */
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 234 */
} /* line 234 */
  sim_icache_fetch(99 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_22, reg_r0_19, (unsigned int) 16); /* line 236 */
   __MULLU(reg_r0_21, reg_r0_15, reg_r0_17); /* line 237 */
} /* line 237 */
  sim_icache_fetch(101 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 239 */
   __MULHS(reg_r0_17, reg_r0_15, reg_r0_17); /* line 240 */
} /* line 240 */
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_16, reg_r0_13, reg_r0_16); /* line 242 */
   __AND(reg_r0_3, reg_r0_3, (unsigned int) 255); /* line 243 */
} /* line 243 */
  sim_icache_fetch(105 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_17 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_17, reg_r0_15, reg_r0_22); /* line 245 */
   __ADD(reg_r0_21, reg_r0_21, t__i32_0); /* line 246 */
} /* line 246 */
  sim_icache_fetch(107 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_21, 0); /* line 248 */
   __ADD(reg_r0_23, reg_r0_21, (unsigned int) 255); /* line 249 */
} /* line 249 */
  sim_icache_fetch(109 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 251 */
   __SLCT(reg_r0_23, reg_b0_1, reg_r0_23, reg_r0_21); /* line 252 */
} /* line 252 */
  sim_icache_fetch(111 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_14, 0); /* line 254 */
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 8); /* line 255 */
} /* line 255 */
  sim_icache_fetch(113 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_16, reg_r0_14, (unsigned int) 255); /* line 257 */
   __ADD(reg_r0_20, reg_r0_20, reg_r0_23); /* line 258 */
} /* line 258 */
  sim_icache_fetch(115 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_16, reg_b0_1, reg_r0_16, reg_r0_14); /* line 260 */
   __ADD(reg_r0_5, reg_r0_20, reg_r0_5); /* line 261 */
} /* line 261 */
  sim_icache_fetch(117 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 263 */
   __MULHS(reg_r0_22, reg_r0_15, reg_r0_22); /* line 264 */
} /* line 264 */
  sim_icache_fetch(119 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 256),0,4)); /* line 266 */
} /* line 266 */
  sim_icache_fetch(121 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_20, reg_r0_13, reg_r0_3); /* line 268 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_22); /* line 269 */
} /* line 269 */
  sim_icache_fetch(123 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_17, 0); /* line 271 */
   __ADD(reg_r0_21, reg_r0_17, (unsigned int) 255); /* line 272 */
} /* line 272 */
  sim_icache_fetch(125 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_17 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_17, reg_r0_14, (unsigned int) 8); /* line 274 */
   __SLCT(reg_r0_21, reg_b0_1, reg_r0_21, t__i32_0); /* line 275 */
} /* line 275 */
  sim_icache_fetch(127 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_17, reg_r0_17, (unsigned int) 255); /* line 277 */
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 8); /* line 278 */
} /* line 278 */
  sim_icache_fetch(129 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_21 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_21, reg_r0_18, reg_r0_17); /* line 280 */
   __ADD(reg_r0_16, reg_r0_16, t__i32_0); /* line 281 */
} /* line 281 */
  sim_icache_fetch(131 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_17, reg_r0_18, reg_r0_17); /* line 283 */
   __ADD(reg_r0_6, reg_r0_16, reg_r0_6); /* line 284 */
} /* line 284 */
  sim_icache_fetch(133 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_13, reg_r0_13, reg_r0_3); /* line 286 */
   __SHRU(reg_r0_16, reg_r0_14, (unsigned int) 16); /* line 287 */
} /* line 287 */
  sim_icache_fetch(135 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_16, reg_r0_16, (unsigned int) 255); /* line 289 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_17); /* line 290 */
} /* line 290 */
  sim_icache_fetch(137 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_21, 0); /* line 292 */
   __ADD(reg_r0_3, reg_r0_21, (unsigned int) 255); /* line 293 */
} /* line 293 */
  sim_icache_fetch(139 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_17, reg_r0_18, reg_r0_16); /* line 295 */
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_3, reg_r0_21); /* line 296 */
} /* line 296 */
  sim_icache_fetch(141 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_16, reg_r0_18, reg_r0_16); /* line 298 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 299 */
} /* line 299 */
  sim_icache_fetch(143 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_20, reg_r0_20, reg_r0_13); /* line 301 */
   __ADD(reg_r0_21, reg_r0_3, reg_r0_7); /* line 302 */
} /* line 302 */
  sim_icache_fetch(145 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_20, 0); /* line 304 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_16); /* line 305 */
} /* line 305 */
  sim_icache_fetch(147 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_2, reg_r0_17, 0); /* line 307 */
   __ADD(reg_r0_13, reg_r0_17, (unsigned int) 255); /* line 308 */
} /* line 308 */
  sim_icache_fetch(149 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_16, reg_r0_20, (unsigned int) 255); /* line 310 */
   __SLCT(reg_r0_13, reg_b0_2, reg_r0_13, reg_r0_17); /* line 311 */
} /* line 311 */
  sim_icache_fetch(151 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_16, reg_b0_1, reg_r0_16, reg_r0_20); /* line 313 */
   __SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 314 */
} /* line 314 */
  sim_icache_fetch(153 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 316 */
   __ADD(reg_r0_17, reg_r0_13, reg_r0_8); /* line 317 */
} /* line 317 */
  sim_icache_fetch(155 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_14, reg_r0_14, (unsigned int) 255); /* line 319 */
   __AND(reg_r0_19, reg_r0_19, (unsigned int) 255); /* line 320 */
} /* line 320 */
  sim_icache_fetch(157 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_20, reg_r0_15, reg_r0_19); /* line 322 */
   __LDWs(reg_r0_22, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 323 */
} /* line 323 */
  sim_icache_fetch(159 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __PFT(mem_trace_pf((reg_r0_4 + (unsigned int) 32),0,4)); /* line 325 */
   __MULHS(reg_r0_15, reg_r0_15, reg_r0_19); /* line 326 */
} /* line 326 */
  sim_icache_fetch(161 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_19, reg_r0_18, reg_r0_14); /* line 328 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 329 */
} /* line 329 */
  sim_icache_fetch(163 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_18, reg_r0_18, reg_r0_14); /* line 331 */
   __ADD(reg_r0_20, reg_r0_20, reg_r0_15); /* line 332 */
} /* line 332 */
  sim_icache_fetch(165 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_20, 0); /* line 334 */
   __ADD(reg_r0_14, reg_r0_20, (unsigned int) 255); /* line 335 */
} /* line 335 */
  sim_icache_fetch(167 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_19, reg_r0_19, reg_r0_18); /* line 337 */
   __SLCT(reg_r0_14, reg_b0_1, reg_r0_14, reg_r0_20); /* line 338 */
} /* line 338 */
  sim_icache_fetch(169 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_1, reg_r0_19, 0); /* line 340 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 341 */
} /* line 341 */
  sim_icache_fetch(171 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_14, reg_r0_19, (unsigned int) 255); /* line 343 */
   __ADD(reg_r0_16, reg_r0_16, t__i32_0); /* line 344 */
} /* line 344 */
  sim_icache_fetch(173 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_14, reg_b0_1, reg_r0_14, reg_r0_19); /* line 346 */
   __ADD(reg_r0_9, reg_r0_16, reg_r0_9); /* line 347 */
} /* line 347 */
  sim_icache_fetch(175 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 349 */
} /* line 349 */
  sim_icache_fetch(176 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_15, reg_r0_14, reg_r0_10); /* line 351 */
} /* line 351 */
  sim_icache_fetch(177 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDWs(reg_r0_16, mem_trace_ld((reg_r0_2 + (unsigned int) 768),0,4)); /* line 353 */
} /* line 353 */
  sim_icache_fetch(179 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __PFT(mem_trace_pf((reg_r0_2 + (unsigned int) 1024),0,4)); /* line 355 */
} /* line 355 */
  sim_icache_fetch(181 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHRU(reg_r0_18, reg_r0_16, (unsigned int) 16); /* line 357 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 358 */
  sim_icache_fetch(183 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __AND(reg_r0_18, reg_r0_18, (unsigned int) 255); /* line 360 */
   __SHRU(reg_r0_15, reg_r0_16, (unsigned int) 8); /* line 361 */
} /* line 361 */
  sim_icache_fetch(185 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_17, reg_r0_22, reg_r0_18); /* line 363 */
   __AND(reg_r0_15, reg_r0_15, (unsigned int) 255); /* line 364 */
} /* line 364 */
  sim_icache_fetch(187 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_18, reg_r0_22, reg_r0_18); /* line 366 */
   __AND(reg_r0_16, reg_r0_16, (unsigned int) 255); /* line 367 */
} /* line 367 */
  sim_icache_fetch(189 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_19, reg_r0_22, reg_r0_15); /* line 369 */
   __ADD(reg_r0_2, reg_r0_2, reg_r0_12); /* line 370 */
} /* line 370 */
  sim_icache_fetch(191 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_17, reg_r0_17, reg_r0_18); /* line 372 */
   __MULHS(reg_r0_15, reg_r0_22, reg_r0_15); /* line 373 */
} /* line 373 */
  sim_icache_fetch(193 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_17, 0); /* line 375 */
   __ADD(reg_r0_18, reg_r0_17, (unsigned int) 255); /* line 376 */
} /* line 376 */
  sim_icache_fetch(195 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_18, reg_b0_0, reg_r0_18, reg_r0_17); /* line 378 */
   __ADD(reg_r0_19, reg_r0_19, reg_r0_15); /* line 379 */
} /* line 379 */
  sim_icache_fetch(197 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 381 */
   __CMPLT(reg_b0_0, reg_r0_19, 0); /* line 382 */
} /* line 382 */
  sim_icache_fetch(199 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_15, reg_r0_19, (unsigned int) 255); /* line 384 */
   __ADD(reg_r0_13, reg_r0_13, reg_r0_18); /* line 385 */
} /* line 385 */
  sim_icache_fetch(201 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SLCT(reg_r0_15, reg_b0_0, reg_r0_15, reg_r0_19); /* line 387 */
   __ADD(reg_r0_8, reg_r0_13, reg_r0_8); /* line 388 */
} /* line 388 */
  sim_icache_fetch(203 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULLU(reg_r0_13, reg_r0_22, reg_r0_16); /* line 390 */
   __SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 391 */
} /* line 391 */
  sim_icache_fetch(205 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MULHS(reg_r0_22, reg_r0_22, reg_r0_16); /* line 393 */
   __ADD(reg_r0_3, reg_r0_3, reg_r0_15); /* line 394 */
} /* line 394 */
  sim_icache_fetch(207 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_7, reg_r0_3, reg_r0_7); /* line 396 */
} /* line 396 */
  sim_icache_fetch(208 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_13, reg_r0_13, reg_r0_22); /* line 398 */
} /* line 398 */
  sim_icache_fetch(209 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __CMPLT(reg_b0_0, reg_r0_13, 0); /* line 400 */
   __ADD(reg_r0_3, reg_r0_13, (unsigned int) 255); /* line 401 */
} /* line 401 */
  sim_icache_fetch(211 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_3, reg_r0_13); /* line 403 */
} /* line 403 */
  sim_icache_fetch(212 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 405 */
} /* line 405 */
  sim_icache_fetch(213 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_14, reg_r0_3); /* line 407 */
} /* line 407 */
  sim_icache_fetch(214 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_10, reg_r0_14, reg_r0_10); /* line 409 */
   __GOTO(l_L10X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L10X3;
} /* line 410 */
l_L11X3: ;/* line 413 */
__LABEL(l_L11X3);
  sim_icache_fetch(216 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_16, reg_r0_27, (unsigned int) 28); /* line 414 */
   __ADD(reg_r0_13, reg_r0_25, (unsigned int) 4); /* line 415 */
} /* line 415 */
  sim_icache_fetch(218 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_21); /* line 417 */
   __ADD(reg_r0_6, reg_r0_6, reg_r0_17); /* line 418 */
} /* line 418 */
  sim_icache_fetch(220 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_9, reg_r0_9, reg_r0_15); /* line 420 */
   __ADD(reg_r0_3, reg_r0_24, (unsigned int) 1); /* line 421 */
} /* line 421 */
  sim_icache_fetch(222 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_14, reg_r0_26); /* line 423 */
   __GOTO(l_L8X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L8X3;
} /* line 424 */
l_L9X3: ;/* line 427 */
__LABEL(l_L9X3);
  sim_icache_fetch(224 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_9, reg_r0_9, 0); /* line 428 */
   __MAX(reg_r0_6, reg_r0_6, 0); /* line 429 */
} /* line 429 */
  sim_icache_fetch(226 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MIN(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 431 */
   __MIN(reg_r0_6, reg_r0_6, (unsigned int) 255); /* line 432 */
} /* line 432 */
  sim_icache_fetch(228 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MAX(reg_r0_5, reg_r0_5, 0); /* line 434 */
   __SHL(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 435 */
} /* line 435 */
  sim_icache_fetch(230 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MIN(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 437 */
   __OR(reg_r0_9, reg_r0_9, reg_r0_6); /* line 438 */
} /* line 438 */
  sim_icache_fetch(232 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __SHL(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 440 */
   __ADD(reg_r0_3, reg_r0_29, reg_r0_30); /* line 441 */
} /* line 441 */
  sim_icache_fetch(234 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __OR(reg_r0_9, reg_r0_9, reg_r0_5); /* line 443 */
   __ADD(reg_r0_4, reg_r0_29, (unsigned int) 4); /* line 444 */
} /* line 444 */
  sim_icache_fetch(236 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __STW(mem_trace_st(reg_r0_3,0,4), reg_r0_9); /* line 446 */
   __ADD(reg_r0_2, reg_r0_28, (unsigned int) 1); /* line 447 */
} /* line 447 */
  sim_icache_fetch(238 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __PFT(mem_trace_pf((reg_r0_3 + (unsigned int) 32),0,4)); /* line 449 */
   __GOTO(l_L6X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L6X3;
} /* line 450 */
l_L7X3: ;/* line 453 */
__LABEL(l_L7X3);
  sim_icache_fetch(240 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_14, reg_r0_14, (unsigned int) 256); /* line 454 */
} /* line 454 */
  sim_icache_fetch(242 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_30, reg_r0_30, (unsigned int) 256); /* line 456 */
} /* line 456 */
  sim_icache_fetch(244 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_31, (unsigned int) 1); /* line 458 */
   __GOTO(l_L4X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L4X3;
} /* line 459 */
l_L5X3: ;/* line 462 */
__LABEL(l_L5X3);
  sim_icache_fetch(246 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_32); /* line 463 */
} /* line 463 */
  sim_icache_fetch(247 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 465 */
} /* line 465 */
		 /* line 466 */
  sim_icache_fetch(249 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __INC_BTU_CNT();
   __INC_STALL_CNT();
  sim_gprof_stop(&sim_gprof_idx);
   __CALL(puts);
   reg_l0_0 = (120 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) puts;
    (*t_call)(reg_r0_3);
   }
  sim_gprof_start(&sim_gprof_idx);
} /* line 468 */
l_lr_18: ;/* line 468 */
__LABEL(l_lr_18);
  sim_icache_fetch(251 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, 0); /* line 470 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 471 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 472 */
   __ADD_CYCLES(1);
} /* line 472 */
  sim_icache_fetch(254 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 475 */
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
    case 113: goto l_L10X3;
    case 114: goto l_L11X3;
    case 115: goto l_L9X3;
    case 116: goto l_L7X3;
    case 117: goto l_L5X3;
    case 119: goto l_lr_18;
    case 120:
      reg_l0_0 = t_client_rpc;
      sim_gprof_exit(&sim_gprof_idx);
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"convolution_7x7.s", 256, 0, 0, 0, 2};

