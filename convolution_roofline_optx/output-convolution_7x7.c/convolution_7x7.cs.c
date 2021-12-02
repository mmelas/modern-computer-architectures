/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/user/tools/vex-3.43 -fmm=/home/user/workspace/assignment1/configurations/example-4-issue/configuration.mm -width 1 -c99inline -ms -prefetch -mfinline -mas_g -mas_G -O3 -o a.out" */

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

  sim_check_stack(reg_r0_1, -128); 

  t_client_rpc = reg_l0_0; 
  reg_l0_0 = (116 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_1, reg_r0_1, (unsigned int) -128); /* line 93 */
} /* line 93 */
		 /* line 94 */
  sim_icache_fetch(13 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_57); /* line 97 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 100),0,4), reg_r0_58); /* line 98 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 104),0,4), reg_r0_59); /* line 99 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 108),0,4), reg_r0_60); /* line 100 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 112),0,4), reg_r0_61); /* line 101 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 116),0,4), reg_r0_62); /* line 102 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 120),0,4), reg_r0_63); /* line 103 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 104 */
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
} /* line 104 */
l_lr_6: ;/* line 104 */
__LABEL(l_lr_6);
  sim_icache_fetch(23 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_2, (unsigned int) -4096); /* line 106 */
   __MOV(reg_r0_3, (unsigned int) conv7_result); /* line 107 */
} /* line 107 */
l_L2X3: ;/* line 110 */
__LABEL(l_L2X3);
  sim_icache_fetch(27 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, 0); /* line 111 */
   __PFT(mem_trace_pf((reg_r0_3 + (unsigned int) 128),0,4)); /* line 112 */
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 32); /* line 113 */
} /* line 113 */
  sim_icache_fetch(30 + t_thisfile.offset, 1);
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
} /* line 115 */
  sim_icache_fetch(31 + t_thisfile.offset, 32);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(32);
   __STW(mem_trace_st(reg_r0_3,0,4), 0); /* line 117 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 4),0,4), 0); /* line 118 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 8),0,4), 0); /* line 119 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 12),0,4), 0); /* line 120 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 16),0,4), 0); /* line 121 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 20),0,4), 0); /* line 122 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 24),0,4), 0); /* line 123 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 28),0,4), 0); /* line 124 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 32),0,4), 0); /* line 125 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 36),0,4), 0); /* line 126 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 40),0,4), 0); /* line 127 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 44),0,4), 0); /* line 128 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 48),0,4), 0); /* line 129 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 52),0,4), 0); /* line 130 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 56),0,4), 0); /* line 131 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 60),0,4), 0); /* line 132 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 64),0,4), 0); /* line 133 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 68),0,4), 0); /* line 134 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 72),0,4), 0); /* line 135 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 76),0,4), 0); /* line 136 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 80),0,4), 0); /* line 137 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 84),0,4), 0); /* line 138 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 88),0,4), 0); /* line 139 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 92),0,4), 0); /* line 140 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 96),0,4), 0); /* line 141 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 100),0,4), 0); /* line 142 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 104),0,4), 0); /* line 143 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 108),0,4), 0); /* line 144 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 112),0,4), 0); /* line 145 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 116),0,4), 0); /* line 146 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 120),0,4), 0); /* line 147 */
   __STW(mem_trace_st((reg_r0_3 + (unsigned int) 124),0,4), 0); /* line 148 */
} /* line 148 */
  sim_icache_fetch(63 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_3, reg_r0_3, (unsigned int) 128); /* line 150 */
   __GOTO(l_L2X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L2X3;
} /* line 151 */
l_L3X3: ;/* line 154 */
__LABEL(l_L3X3);
  sim_icache_fetch(65 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __MOV(reg_r0_6, 0); /* line 155 */
   __MOV(reg_r0_2, 0); /* line 156 */
   __MOV(reg_r0_26, ((unsigned int) conv7_result + (unsigned int) 1012)); /* line 157 */
} /* line 157 */
  sim_icache_fetch(69 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_6); /* line 159 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_26); /* line 160 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 161 */
} /* line 161 */
l_L4X3: ;/* line 164 */
__LABEL(l_L4X3);
  sim_icache_fetch(72 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_2, (unsigned int) 58); /* line 165 */
   __MOV(reg_r0_25, (unsigned int) -58); /* line 166 */
   __MOV(reg_r0_4, 0); /* line 167 */
} /* line 167 */
  sim_icache_fetch(75 + t_thisfile.offset, 1);
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
} /* line 169 */
l_L6X3: ;/* line 172 */
__LABEL(l_L6X3);
  sim_icache_fetch(76 + t_thisfile.offset, 30);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __LDWs(reg_r0_8, mem_trace_ld((unsigned int) filter7x7,0,4)); /* line 173 */
   __ADD(reg_r0_19, reg_r0_4, (unsigned int) 1); /* line 174 */
   __ADD(reg_r0_7, reg_r0_4, reg_r0_6); /* line 175 */
   __ADD(reg_r0_11, reg_r0_2, (unsigned int) 1); /* line 176 */
   __LDWs(reg_r0_12, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 4),0,4)); /* line 177 */
   __ADD(reg_r0_15, reg_r0_2, (unsigned int) 2); /* line 178 */
   __LDWs(reg_r0_16, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 8),0,4)); /* line 179 */
   __ADD(reg_r0_9, reg_r0_2, (unsigned int) 3); /* line 180 */
   __LDWs(reg_r0_10, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 12),0,4)); /* line 181 */
   __ADD(reg_r0_17, reg_r0_2, (unsigned int) 4); /* line 182 */
   __LDWs(reg_r0_18, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 16),0,4)); /* line 183 */
   __ADD(reg_r0_13, reg_r0_2, (unsigned int) 5); /* line 184 */
   __LDWs(reg_r0_14, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 20),0,4)); /* line 185 */
   __ADD(reg_r0_3, reg_r0_2, (unsigned int) 6); /* line 186 */
   __LDWs(reg_r0_5, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 24),0,4)); /* line 187 */
   __LDWs(reg_r0_21, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 36),0,4)); /* line 188 */
   __LDWs(reg_r0_22, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 40),0,4)); /* line 189 */
   __LDWs(reg_r0_23, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 48),0,4)); /* line 190 */
   __LDWs(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 52),0,4)); /* line 191 */
} /* line 191 */
  sim_icache_fetch(106 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __ADD(reg_r0_27, reg_r0_6, reg_r0_19); /* line 193 */
   __SH2ADD(reg_r0_7, reg_r0_7, (unsigned int) conv7_image); /* line 194 */
   __SHL(reg_r0_11, reg_r0_11, (unsigned int) 6); /* line 195 */
   __SHL(reg_r0_15, reg_r0_15, (unsigned int) 6); /* line 196 */
   __ADD(reg_r0_30, reg_r0_4, (unsigned int) 2); /* line 197 */
   __SHL(reg_r0_9, reg_r0_9, (unsigned int) 6); /* line 198 */
   __ADD(reg_r0_38, reg_r0_4, (unsigned int) 3); /* line 199 */
   __SHL(reg_r0_17, reg_r0_17, (unsigned int) 6); /* line 200 */
   __ADD(reg_r0_40, reg_r0_4, (unsigned int) 4); /* line 201 */
   __SHL(reg_r0_13, reg_r0_13, (unsigned int) 6); /* line 202 */
   __SHL(reg_r0_3, reg_r0_3, (unsigned int) 6); /* line 203 */
} /* line 203 */
  sim_icache_fetch(118 + t_thisfile.offset, 27);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_30 ;
  t__i32_0 = reg_r0_19 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(26);
   __CMPLT(reg_b0_0, reg_r0_25, 0); /* line 205 */
   __SH2ADD(reg_r0_27, reg_r0_27, (unsigned int) conv7_image); /* line 206 */
   __PFT(mem_trace_pf((reg_r0_7 + (unsigned int) 32),0,4)); /* line 207 */
   __LDWs(reg_r0_42, mem_trace_ld(reg_r0_7,0,4)); /* line 208 */
   __ADD(reg_r0_44, reg_r0_4, reg_r0_11); /* line 209 */
   __ADD(reg_r0_52, reg_r0_11, t__i32_0); /* line 210 */
   __ADD(reg_r0_46, reg_r0_4, reg_r0_15); /* line 211 */
   __ADD(reg_r0_49, reg_r0_15, t__i32_0); /* line 212 */
   __ADD(reg_r0_57, reg_r0_6, t__i32_1); /* line 213 */
   __ADD(reg_r0_58, reg_r0_11, t__i32_1); /* line 214 */
   __ADD(reg_r0_54, reg_r0_15, t__i32_1); /* line 215 */
   __ADD(reg_r0_43, reg_r0_4, reg_r0_9); /* line 216 */
   __ADD(reg_r0_50, reg_r0_9, t__i32_0); /* line 217 */
   __ADD(reg_r0_55, reg_r0_9, t__i32_1); /* line 218 */
   __ADD(reg_r0_60, reg_r0_15, reg_r0_38); /* line 219 */
   __ADD(reg_r0_62, reg_r0_9, reg_r0_38); /* line 220 */
   __ADD(reg_r0_47, reg_r0_4, reg_r0_17); /* line 221 */
   __ADD(reg_r0_19, reg_r0_17, t__i32_0); /* line 222 */
   __ADD(reg_r0_30, reg_r0_17, t__i32_1); /* line 223 */
   __ADD(reg_r0_45, reg_r0_4, reg_r0_13); /* line 224 */
   __ADD(reg_r0_51, reg_r0_13, t__i32_0); /* line 225 */
   __ADD(reg_r0_56, reg_r0_13, t__i32_1); /* line 226 */
   __ADD(reg_r0_41, reg_r0_4, reg_r0_3); /* line 227 */
   __ADD(reg_r0_48, reg_r0_3, t__i32_0); /* line 228 */
   __ADD(reg_r0_53, reg_r0_3, t__i32_1); /* line 229 */
   __ADD(reg_r0_59, reg_r0_3, reg_r0_38); /* line 230 */
} /* line 230 */
  sim_icache_fetch(145 + t_thisfile.offset, 32);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __LDWs(reg_r0_27, mem_trace_ld(reg_r0_27,0,4)); /* line 232 */
   __SH2ADD(reg_r0_44, reg_r0_44, (unsigned int) conv7_image); /* line 233 */
   __SH2ADD(reg_r0_52, reg_r0_52, (unsigned int) conv7_image); /* line 234 */
   __SH2ADD(reg_r0_46, reg_r0_46, (unsigned int) conv7_image); /* line 235 */
   __SH2ADD(reg_r0_49, reg_r0_49, (unsigned int) conv7_image); /* line 236 */
   __SH2ADD(reg_r0_54, reg_r0_54, (unsigned int) conv7_image); /* line 237 */
   __SH2ADD(reg_r0_43, reg_r0_43, (unsigned int) conv7_image); /* line 238 */
   __SH2ADD(reg_r0_50, reg_r0_50, (unsigned int) conv7_image); /* line 239 */
   __SH2ADD(reg_r0_55, reg_r0_55, (unsigned int) conv7_image); /* line 240 */
   __SH2ADD(reg_r0_47, reg_r0_47, (unsigned int) conv7_image); /* line 241 */
   __SH2ADD(reg_r0_19, reg_r0_19, (unsigned int) conv7_image); /* line 242 */
   __SH2ADD(reg_r0_45, reg_r0_45, (unsigned int) conv7_image); /* line 243 */
   __SH2ADD(reg_r0_51, reg_r0_51, (unsigned int) conv7_image); /* line 244 */
   __ADD(reg_r0_7, reg_r0_13, reg_r0_38); /* line 245 */
   __SH2ADD(reg_r0_41, reg_r0_41, (unsigned int) conv7_image); /* line 246 */
   __SH2ADD(reg_r0_48, reg_r0_48, (unsigned int) conv7_image); /* line 247 */
   __SH2ADD(reg_r0_53, reg_r0_53, (unsigned int) conv7_image); /* line 248 */
} /* line 248 */
  sim_icache_fetch(177 + t_thisfile.offset, 32);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(24);
   __SHRU(reg_r0_63, reg_r0_42, (unsigned int) 16); /* line 250 */
   __LDWs(reg_r0_44, mem_trace_ld(reg_r0_44,0,4)); /* line 251 */
   __LDWs(reg_r0_52, mem_trace_ld(reg_r0_52,0,4)); /* line 252 */
   __LDWs(reg_r0_46, mem_trace_ld(reg_r0_46,0,4)); /* line 253 */
   __LDWs(reg_r0_49, mem_trace_ld(reg_r0_49,0,4)); /* line 254 */
   __SH2ADD(reg_r0_57, reg_r0_57, (unsigned int) conv7_image); /* line 255 */
   __SH2ADD(reg_r0_58, reg_r0_58, (unsigned int) conv7_image); /* line 256 */
   __LDWs(reg_r0_54, mem_trace_ld(reg_r0_54,0,4)); /* line 257 */
   __LDWs(reg_r0_43, mem_trace_ld(reg_r0_43,0,4)); /* line 258 */
   __LDWs(reg_r0_50, mem_trace_ld(reg_r0_50,0,4)); /* line 259 */
   __LDWs(reg_r0_55, mem_trace_ld(reg_r0_55,0,4)); /* line 260 */
   __SH2ADD(reg_r0_60, reg_r0_60, (unsigned int) conv7_image); /* line 261 */
   __SH2ADD(reg_r0_62, reg_r0_62, (unsigned int) conv7_image); /* line 262 */
   __LDWs(reg_r0_47, mem_trace_ld(reg_r0_47,0,4)); /* line 263 */
   __LDWs(reg_r0_19, mem_trace_ld(reg_r0_19,0,4)); /* line 264 */
   __SH2ADD(reg_r0_30, reg_r0_30, (unsigned int) conv7_image); /* line 265 */
   __LDWs(reg_r0_45, mem_trace_ld(reg_r0_45,0,4)); /* line 266 */
   __LDWs(reg_r0_51, mem_trace_ld(reg_r0_51,0,4)); /* line 267 */
   __SH2ADD(reg_r0_56, reg_r0_56, (unsigned int) conv7_image); /* line 268 */
   __SH2ADD(reg_r0_7, reg_r0_7, (unsigned int) conv7_image); /* line 269 */
   __LDWs(reg_r0_41, mem_trace_ld(reg_r0_41,0,4)); /* line 270 */
   __LDWs(reg_r0_48, mem_trace_ld(reg_r0_48,0,4)); /* line 271 */
   __LDWs(reg_r0_53, mem_trace_ld(reg_r0_53,0,4)); /* line 272 */
   __SH2ADD(reg_r0_59, reg_r0_59, (unsigned int) conv7_image); /* line 273 */
} /* line 273 */
  sim_icache_fetch(209 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __SHRU(reg_r0_61, reg_r0_27, (unsigned int) 16); /* line 275 */
   __AND(reg_r0_63, reg_r0_63, (unsigned int) 255); /* line 276 */
   __LDWs(reg_r0_57, mem_trace_ld(reg_r0_57,0,4)); /* line 277 */
   __LDWs(reg_r0_58, mem_trace_ld(reg_r0_58,0,4)); /* line 278 */
   __LDWs(reg_r0_60, mem_trace_ld(reg_r0_60,0,4)); /* line 279 */
   __LDWs(reg_r0_62, mem_trace_ld(reg_r0_62,0,4)); /* line 280 */
   __LDWs(reg_r0_30, mem_trace_ld(reg_r0_30,0,4)); /* line 281 */
   __LDWs(reg_r0_56, mem_trace_ld(reg_r0_56,0,4)); /* line 282 */
   __LDWs(reg_r0_7, mem_trace_ld(reg_r0_7,0,4)); /* line 283 */
   __LDWs(reg_r0_59, mem_trace_ld(reg_r0_59,0,4)); /* line 284 */
   if (!reg_b0_0) {    __BRANCHF(reg_b0_0);
      __INC_BTC_CNT();
      __INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      __INC_BNT_CNT();
   }
} /* line 285 */
  sim_icache_fetch(220 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __MULLU(reg_r0_37, reg_r0_8, reg_r0_63); /* line 287 */
   __MULHS(reg_r0_63, reg_r0_8, reg_r0_63); /* line 288 */
   __AND(reg_r0_61, reg_r0_61, (unsigned int) 255); /* line 289 */
   __SHRU(reg_r0_36, reg_r0_44, (unsigned int) 16); /* line 290 */
   __SHRU(reg_r0_34, reg_r0_46, (unsigned int) 16); /* line 291 */
   __SHRU(reg_r0_31, reg_r0_49, (unsigned int) 16); /* line 292 */
   __SHRU(reg_r0_8, reg_r0_43, (unsigned int) 16); /* line 293 */
   __SHRU(reg_r0_29, reg_r0_50, (unsigned int) 16); /* line 294 */
   __SHRU(reg_r0_33, reg_r0_47, (unsigned int) 16); /* line 295 */
   __SHRU(reg_r0_35, reg_r0_45, (unsigned int) 16); /* line 296 */
   __SHRU(reg_r0_28, reg_r0_51, (unsigned int) 16); /* line 297 */
   __SHRU(reg_r0_39, reg_r0_41, (unsigned int) 16); /* line 298 */
   __SHRU(reg_r0_32, reg_r0_48, (unsigned int) 16); /* line 299 */
} /* line 299 */
  sim_icache_fetch(233 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_36, reg_r0_36, (unsigned int) 255); /* line 301 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 302 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 303 */
   __AND(reg_r0_8, reg_r0_8, (unsigned int) 255); /* line 304 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 305 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 306 */
   __AND(reg_r0_35, reg_r0_35, (unsigned int) 255); /* line 307 */
   __AND(reg_r0_28, reg_r0_28, (unsigned int) 255); /* line 308 */
   __AND(reg_r0_39, reg_r0_39, (unsigned int) 255); /* line 309 */
   __AND(reg_r0_32, reg_r0_32, (unsigned int) 255); /* line 310 */
} /* line 310 */
  sim_icache_fetch(243 + t_thisfile.offset, 14);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_14 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __ADD(reg_r0_37, reg_r0_37, reg_r0_63); /* line 312 */
   __MULLU(reg_r0_63, reg_r0_10, reg_r0_8); /* line 313 */
   __MULHS(reg_r0_8, reg_r0_10, reg_r0_8); /* line 314 */
   __MULLU(reg_r0_14, reg_r0_18, reg_r0_33); /* line 315 */
   __MULHS(reg_r0_33, reg_r0_18, reg_r0_33); /* line 316 */
   __MULLU(reg_r0_10, t__i32_0, reg_r0_35); /* line 317 */
   __MULHS(reg_r0_35, t__i32_0, reg_r0_35); /* line 318 */
   __ADD(reg_r0_5, reg_r0_3, reg_r0_40); /* line 319 */
   __MULLU(reg_r0_24, t__i32_1, reg_r0_39); /* line 320 */
   __MULHS(reg_r0_39, t__i32_1, reg_r0_39); /* line 321 */
   __MULLU(reg_r0_18, reg_r0_21, reg_r0_31); /* line 322 */
   __MULHS(reg_r0_31, reg_r0_21, reg_r0_31); /* line 323 */
   __MULLU(reg_r0_21, reg_r0_23, reg_r0_28); /* line 324 */
   __MULHS(reg_r0_28, reg_r0_23, reg_r0_28); /* line 325 */
} /* line 325 */
  sim_icache_fetch(257 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __CMPLT(reg_b0_0, reg_r0_37, 0); /* line 327 */
   __ADD(reg_r0_23, reg_r0_37, (unsigned int) 255); /* line 328 */
   __SH2ADD(reg_r0_5, reg_r0_5, (unsigned int) conv7_image); /* line 329 */
} /* line 329 */
  sim_icache_fetch(261 + t_thisfile.offset, 24);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_35 ;
  t__i32_0 = reg_r0_8 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(22);
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_37); /* line 331 */
   __MULLU(reg_r0_8, reg_r0_12, reg_r0_36); /* line 332 */
   __MULHS(reg_r0_36, reg_r0_12, reg_r0_36); /* line 333 */
   __SHRU(reg_r0_37, reg_r0_52, (unsigned int) 16); /* line 334 */
   __MULLU(reg_r0_35, reg_r0_16, reg_r0_34); /* line 335 */
   __MULHS(reg_r0_34, reg_r0_16, reg_r0_34); /* line 336 */
   __ADD(reg_r0_63, reg_r0_63, t__i32_0); /* line 337 */
   __ADD(reg_r0_16, reg_r0_15, reg_r0_40); /* line 338 */
   __ADD(reg_r0_2, reg_r0_9, reg_r0_40); /* line 339 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_33); /* line 340 */
   __ADD(reg_r0_10, reg_r0_10, t__i32_1); /* line 341 */
   __LDW(reg_r0_5, mem_trace_ld(reg_r0_5,0,4)); /* line 342 */
   __ADD(reg_r0_24, reg_r0_24, reg_r0_39); /* line 343 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_31); /* line 344 */
   __MULLU(reg_r0_31, reg_r0_22, reg_r0_29); /* line 345 */
   __MULHS(reg_r0_29, reg_r0_22, reg_r0_29); /* line 346 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_28); /* line 347 */
   __MULLU(reg_r0_33, reg_r0_20, reg_r0_32); /* line 348 */
   __MULHS(reg_r0_32, reg_r0_20, reg_r0_32); /* line 349 */
   __LDW(reg_r0_39, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 32),0,4)); /* line 350 */
   __LDW(reg_r0_28, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 28),0,4)); /* line 351 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_25); /* line 352 */
} /* line 352 */
  sim_icache_fetch(285 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 8); /* line 354 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 355 */
   __CMPLT(reg_b0_1, reg_r0_63, 0); /* line 356 */
   __ADD(reg_r0_12, reg_r0_63, (unsigned int) 255); /* line 357 */
   __SH2ADD(reg_r0_16, reg_r0_16, (unsigned int) conv7_image); /* line 358 */
   __SH2ADD(reg_r0_2, reg_r0_2, (unsigned int) conv7_image); /* line 359 */
   __CMPLT(reg_b0_3, reg_r0_14, 0); /* line 360 */
   __CMPLT(reg_b0_2, reg_r0_10, 0); /* line 361 */
   __CMPLT(reg_b0_0, reg_r0_24, 0); /* line 362 */
   __ADD(reg_r0_25, reg_r0_24, (unsigned int) 255); /* line 363 */
   __CMPLT(reg_b0_4, reg_r0_18, 0); /* line 364 */
   __CMPLT(reg_b0_5, reg_r0_21, 0); /* line 365 */
} /* line 365 */
  sim_icache_fetch(299 + t_thisfile.offset, 17);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_32 ;
  t__i32_1 = reg_r0_28 ;
  t__i32_0 = reg_r0_24 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __ADD(reg_r0_8, reg_r0_8, reg_r0_36); /* line 367 */
   __ADD(reg_r0_35, reg_r0_35, reg_r0_34); /* line 368 */
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, reg_r0_63); /* line 369 */
   __LDW(reg_r0_16, mem_trace_ld(reg_r0_16,0,4)); /* line 370 */
   __LDW(reg_r0_2, mem_trace_ld(reg_r0_2,0,4)); /* line 371 */
   __ADD(reg_r0_34, reg_r0_14, (unsigned int) 255); /* line 372 */
   __ADD(reg_r0_28, reg_r0_4, (unsigned int) 5); /* line 373 */
   __ADD(reg_r0_24, reg_r0_10, (unsigned int) 255); /* line 374 */
   __SLCT(reg_r0_25, reg_b0_0, reg_r0_25, t__i32_0); /* line 375 */
   __MULLU(reg_r0_36, t__i32_1, reg_r0_61); /* line 376 */
   __MULHS(reg_r0_61, t__i32_1, reg_r0_61); /* line 377 */
   __MULLU(reg_r0_63, reg_r0_39, reg_r0_37); /* line 378 */
   __MULHS(reg_r0_37, reg_r0_39, reg_r0_37); /* line 379 */
   __ADD(reg_r0_32, reg_r0_18, (unsigned int) 255); /* line 380 */
   __ADD(reg_r0_31, reg_r0_31, reg_r0_29); /* line 381 */
   __ADD(reg_r0_29, reg_r0_21, (unsigned int) 255); /* line 382 */
   __ADD(reg_r0_33, reg_r0_33, t__i32_2); /* line 383 */
} /* line 383 */
  sim_icache_fetch(316 + t_thisfile.offset, 15);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_21 ;
  t__i32_0 = reg_r0_10 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __CMPLT(reg_b0_0, reg_r0_8, 0); /* line 385 */
   __ADD(reg_r0_39, reg_r0_8, (unsigned int) 255); /* line 386 */
   __CMPLT(reg_b0_1, reg_r0_35, 0); /* line 387 */
   __ADD(reg_r0_10, reg_r0_35, (unsigned int) 255); /* line 388 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 389 */
   __SHRU(reg_r0_21, reg_r0_19, (unsigned int) 16); /* line 390 */
   __SLCT(reg_r0_34, reg_b0_3, reg_r0_34, reg_r0_14); /* line 391 */
   __SLCT(reg_r0_24, reg_b0_2, reg_r0_24, t__i32_0); /* line 392 */
   __SHR(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 393 */
   __SLCT(reg_r0_32, reg_b0_4, reg_r0_32, reg_r0_18); /* line 394 */
   __CMPLT(reg_b0_3, reg_r0_31, 0); /* line 395 */
   __ADD(reg_r0_18, reg_r0_31, (unsigned int) 255); /* line 396 */
   __SLCT(reg_r0_29, reg_b0_5, reg_r0_29, t__i32_1); /* line 397 */
   __CMPLT(reg_b0_2, reg_r0_33, 0); /* line 398 */
   __ADD(reg_r0_14, reg_r0_33, (unsigned int) 255); /* line 399 */
} /* line 399 */
  sim_icache_fetch(331 + t_thisfile.offset, 28);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_61 ;
  t__i32_0 = reg_r0_35 ;
  t__i32_2 = reg_r0_31 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(23);
   __SLCT(reg_r0_39, reg_b0_0, reg_r0_39, reg_r0_8); /* line 401 */
   __SHRU(reg_r0_26, reg_r0_57, (unsigned int) 16); /* line 402 */
   __SHRU(reg_r0_35, reg_r0_54, (unsigned int) 16); /* line 403 */
   __SLCT(reg_r0_10, reg_b0_1, reg_r0_10, t__i32_0); /* line 404 */
   __SHRU(reg_r0_61, reg_r0_55, (unsigned int) 16); /* line 405 */
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 406 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 407 */
   __SHRU(reg_r0_20, reg_r0_56, (unsigned int) 16); /* line 408 */
   __SHR(reg_r0_24, reg_r0_24, (unsigned int) 8); /* line 409 */
   __SHRU(reg_r0_31, reg_r0_53, (unsigned int) 16); /* line 410 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_25); /* line 411 */
   __ADD(reg_r0_36, reg_r0_36, t__i32_1); /* line 412 */
   __ADD(reg_r0_63, reg_r0_63, reg_r0_37); /* line 413 */
   __SHR(reg_r0_32, reg_r0_32, (unsigned int) 8); /* line 414 */
   __SLCT(reg_r0_18, reg_b0_3, reg_r0_18, t__i32_2); /* line 415 */
   __SHR(reg_r0_29, reg_r0_29, (unsigned int) 8); /* line 416 */
   __SLCT(reg_r0_14, reg_b0_2, reg_r0_14, reg_r0_33); /* line 417 */
   __LDW(reg_r0_22, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 76),0,4)); /* line 418 */
   __LDW(reg_r0_25, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 68),0,4)); /* line 419 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 64),0,4)); /* line 420 */
   __LDW(reg_r0_33, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 80),0,4)); /* line 421 */
   __LDW(reg_r0_8, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 44),0,4)); /* line 422 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_57); /* line 423 */
} /* line 423 */
  sim_icache_fetch(359 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __SHR(reg_r0_39, reg_r0_39, (unsigned int) 8); /* line 425 */
   __AND(reg_r0_26, reg_r0_26, (unsigned int) 255); /* line 426 */
   __AND(reg_r0_35, reg_r0_35, (unsigned int) 255); /* line 427 */
   __SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 428 */
   __AND(reg_r0_61, reg_r0_61, (unsigned int) 255); /* line 429 */
   __AND(reg_r0_20, reg_r0_20, (unsigned int) 255); /* line 430 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 431 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_12); /* line 432 */
   __CMPLT(reg_b0_0, reg_r0_36, 0); /* line 433 */
   __ADD(reg_r0_12, reg_r0_36, (unsigned int) 255); /* line 434 */
   __CMPLT(reg_b0_1, reg_r0_63, 0); /* line 435 */
   __ADD(reg_r0_57, reg_r0_63, (unsigned int) 255); /* line 436 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 437 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 438 */
} /* line 438 */
  sim_icache_fetch(373 + t_thisfile.offset, 18);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_37 ;
  t__i32_1 = reg_r0_18 ;
  t__i32_0 = reg_r0_8 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(18);
   __ADD(reg_r0_8, reg_r0_15, reg_r0_28); /* line 440 */
   __ADD(reg_r0_37, reg_r0_3, reg_r0_28); /* line 441 */
   __ADD(reg_r0_39, reg_r0_39, reg_r0_24); /* line 442 */
   __ADD(reg_r0_10, reg_r0_10, reg_r0_34); /* line 443 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, reg_r0_36); /* line 444 */
   __SLCT(reg_r0_57, reg_b0_1, reg_r0_57, reg_r0_63); /* line 445 */
   __MULLU(reg_r0_18, t__i32_0, reg_r0_21); /* line 446 */
   __MULHS(reg_r0_21, t__i32_0, reg_r0_21); /* line 447 */
   __ADD(reg_r0_32, reg_r0_32, t__i32_1); /* line 448 */
   __MULLU(reg_r0_34, t__i32_2, reg_r0_35); /* line 449 */
   __MULHS(reg_r0_35, t__i32_2, reg_r0_35); /* line 450 */
   __MULLU(reg_r0_36, reg_r0_25, reg_r0_61); /* line 451 */
   __MULHS(reg_r0_61, reg_r0_25, reg_r0_61); /* line 452 */
   __MULLU(reg_r0_63, reg_r0_22, reg_r0_20); /* line 453 */
   __MULHS(reg_r0_20, reg_r0_22, reg_r0_20); /* line 454 */
   __MULLU(reg_r0_24, reg_r0_33, reg_r0_31); /* line 455 */
   __MULHS(reg_r0_31, reg_r0_33, reg_r0_31); /* line 456 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_22); /* line 457 */
} /* line 457 */
  sim_icache_fetch(391 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SHRU(reg_r0_22, reg_r0_58, (unsigned int) 16); /* line 459 */
   __SH2ADD(reg_r0_8, reg_r0_8, (unsigned int) conv7_image); /* line 460 */
   __SH2ADD(reg_r0_37, reg_r0_37, (unsigned int) conv7_image); /* line 461 */
   __ADD(reg_r0_39, reg_r0_39, reg_r0_10); /* line 462 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 463 */
   __SHR(reg_r0_57, reg_r0_57, (unsigned int) 8); /* line 464 */
   __LDW(reg_r0_10, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 56),0,4)); /* line 465 */
} /* line 465 */
  sim_icache_fetch(401 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_35 ;
  t__i32_2 = reg_r0_31 ;
  t__i32_0 = reg_r0_21 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(17);
   __AND(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 467 */
   __SHRU(reg_r0_35, reg_r0_60, (unsigned int) 16); /* line 468 */
   __SHRU(reg_r0_33, reg_r0_62, (unsigned int) 16); /* line 469 */
   __SHRU(reg_r0_21, reg_r0_30, (unsigned int) 16); /* line 470 */
   __LDW(reg_r0_8, mem_trace_ld(reg_r0_8,0,4)); /* line 471 */
   __SHRU(reg_r0_31, reg_r0_59, (unsigned int) 16); /* line 472 */
   __LDW(reg_r0_37, mem_trace_ld(reg_r0_37,0,4)); /* line 473 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_39); /* line 474 */
   __ADD(reg_r0_18, reg_r0_18, t__i32_0); /* line 475 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_29); /* line 476 */
   __ADD(reg_r0_34, reg_r0_34, t__i32_1); /* line 477 */
   __ADD(reg_r0_36, reg_r0_36, reg_r0_61); /* line 478 */
   __ADD(reg_r0_63, reg_r0_63, reg_r0_20); /* line 479 */
   __ADD(reg_r0_24, reg_r0_24, t__i32_2); /* line 480 */
   __LDW(reg_r0_39, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 108),0,4)); /* line 481 */
   __LDW(reg_r0_29, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 72),0,4)); /* line 482 */
   __LDW(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 60),0,4)); /* line 483 */
} /* line 483 */
  sim_icache_fetch(421 + t_thisfile.offset, 12);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __AND(reg_r0_35, reg_r0_35, (unsigned int) 255); /* line 485 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 486 */
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 487 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 488 */
   __CMPLT(reg_b0_0, reg_r0_18, 0); /* line 489 */
   __ADD(reg_r0_14, reg_r0_18, (unsigned int) 255); /* line 490 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 491 */
   __MULHS(reg_r0_25, reg_r0_10, reg_r0_26); /* line 492 */
   __CMPLT(reg_b0_2, reg_r0_34, 0); /* line 493 */
   __CMPLT(reg_b0_3, reg_r0_36, 0); /* line 494 */
   __CMPLT(reg_b0_4, reg_r0_63, 0); /* line 495 */
   __CMPLT(reg_b0_1, reg_r0_24, 0); /* line 496 */
} /* line 496 */
  sim_icache_fetch(433 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, reg_r0_18); /* line 498 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_32); /* line 499 */
   __MULLU(reg_r0_26, reg_r0_10, reg_r0_26); /* line 500 */
   __ADD(reg_r0_32, reg_r0_34, (unsigned int) 255); /* line 501 */
   __MULHS(reg_r0_10, reg_r0_29, reg_r0_21); /* line 502 */
   __ADD(reg_r0_18, reg_r0_24, (unsigned int) 255); /* line 503 */
   __MULHS(reg_r0_61, reg_r0_39, reg_r0_31); /* line 504 */
} /* line 504 */
  sim_icache_fetch(440 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_39 ;
  t__i32_0 = reg_r0_24 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __SHRU(reg_r0_39, reg_r0_37, (unsigned int) 16); /* line 506 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 507 */
   __SLCT(reg_r0_32, reg_b0_2, reg_r0_32, reg_r0_34); /* line 508 */
   __ADD(reg_r0_24, reg_r0_36, (unsigned int) 255); /* line 509 */
   __MULLU(reg_r0_21, reg_r0_29, reg_r0_21); /* line 510 */
   __ADD(reg_r0_34, reg_r0_63, (unsigned int) 255); /* line 511 */
   __SLCT(reg_r0_18, reg_b0_1, reg_r0_18, t__i32_0); /* line 512 */
   __MULLU(reg_r0_31, t__i32_1, reg_r0_31); /* line 513 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_37); /* line 514 */
} /* line 514 */
  sim_icache_fetch(449 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __SHRU(reg_r0_37, reg_r0_7, (unsigned int) 16); /* line 516 */
   __SHRU(reg_r0_29, reg_r0_5, (unsigned int) 16); /* line 517 */
   __AND(reg_r0_39, reg_r0_39, (unsigned int) 255); /* line 518 */
   __ADD(reg_r0_57, reg_r0_57, reg_r0_14); /* line 519 */
   __ADD(reg_r0_26, reg_r0_26, reg_r0_25); /* line 520 */
   __MULLU(reg_r0_14, reg_r0_20, reg_r0_22); /* line 521 */
   __MULHS(reg_r0_22, reg_r0_20, reg_r0_22); /* line 522 */
   __SHR(reg_r0_32, reg_r0_32, (unsigned int) 8); /* line 523 */
   __SLCT(reg_r0_24, reg_b0_3, reg_r0_24, reg_r0_36); /* line 524 */
   __SLCT(reg_r0_34, reg_b0_4, reg_r0_34, reg_r0_63); /* line 525 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 526 */
   __LDW(reg_r0_25, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 104),0,4)); /* line 527 */
   __LDW(reg_r0_63, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 96),0,4)); /* line 528 */
   __LDW(reg_r0_36, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 92),0,4)); /* line 529 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_5); /* line 530 */
} /* line 530 */
  sim_icache_fetch(467 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_61 ;
  t__i32_0 = reg_r0_10 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __ADD(reg_r0_10, reg_r0_6, reg_r0_38); /* line 532 */
   __ADD(reg_r0_61, reg_r0_11, reg_r0_38); /* line 533 */
   __ADD(reg_r0_38, reg_r0_17, reg_r0_38); /* line 534 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 535 */
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 536 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_57); /* line 537 */
   __CMPLT(reg_b0_0, reg_r0_26, 0); /* line 538 */
   __ADD(reg_r0_5, reg_r0_26, (unsigned int) 255); /* line 539 */
   __SHR(reg_r0_24, reg_r0_24, (unsigned int) 8); /* line 540 */
   __ADD(reg_r0_21, reg_r0_21, t__i32_0); /* line 541 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 542 */
   __LDW(reg_r0_57, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 84),0,4)); /* line 543 */
   __LDW(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 88),0,4)); /* line 544 */
   __ADD(reg_r0_31, reg_r0_31, t__i32_1); /* line 545 */
} /* line 545 */
  sim_icache_fetch(483 + t_thisfile.offset, 18);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __SH2ADD(reg_r0_10, reg_r0_10, (unsigned int) conv7_image); /* line 547 */
   __SH2ADD(reg_r0_61, reg_r0_61, (unsigned int) conv7_image); /* line 548 */
   __SH2ADD(reg_r0_38, reg_r0_38, (unsigned int) conv7_image); /* line 549 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_12); /* line 550 */
   __SLCT(reg_r0_5, reg_b0_0, reg_r0_5, reg_r0_26); /* line 551 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_22); /* line 552 */
   __CMPLT(reg_b0_0, reg_r0_21, 0); /* line 553 */
   __ADD(reg_r0_12, reg_r0_21, (unsigned int) 255); /* line 554 */
   __ADD(reg_r0_32, reg_r0_32, reg_r0_24); /* line 555 */
   __MULLU(reg_r0_24, reg_r0_36, reg_r0_35); /* line 556 */
   __MULHS(reg_r0_35, reg_r0_36, reg_r0_35); /* line 557 */
   __MULLU(reg_r0_26, reg_r0_63, reg_r0_33); /* line 558 */
   __MULHS(reg_r0_33, reg_r0_63, reg_r0_33); /* line 559 */
   __CMPLT(reg_b0_1, reg_r0_31, 0); /* line 560 */
   __ADD(reg_r0_22, reg_r0_31, (unsigned int) 255); /* line 561 */
} /* line 561 */
  sim_icache_fetch(501 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_18 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __LDW(reg_r0_10, mem_trace_ld(reg_r0_10,0,4)); /* line 563 */
   __LDW(reg_r0_61, mem_trace_ld(reg_r0_61,0,4)); /* line 564 */
   __LDW(reg_r0_38, mem_trace_ld(reg_r0_38,0,4)); /* line 565 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 566 */
   __CMPLT(reg_b0_2, reg_r0_14, 0); /* line 567 */
   __ADD(reg_r0_18, reg_r0_14, (unsigned int) 255); /* line 568 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, reg_r0_21); /* line 569 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 570 */
   __MULLU(reg_r0_21, reg_r0_25, reg_r0_37); /* line 571 */
   __MULHS(reg_r0_37, reg_r0_25, reg_r0_37); /* line 572 */
   __SLCT(reg_r0_22, reg_b0_1, reg_r0_22, reg_r0_31); /* line 573 */
   __LDW(reg_r0_31, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 100),0,4)); /* line 574 */
} /* line 574 */
  sim_icache_fetch(514 + t_thisfile.offset, 15);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_34 ;
  t__i32_1 = reg_r0_32 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __ADD(reg_r0_36, reg_r0_6, reg_r0_40); /* line 576 */
   __SHRU(reg_r0_32, reg_r0_16, (unsigned int) 16); /* line 577 */
   __SHRU(reg_r0_34, reg_r0_2, (unsigned int) 16); /* line 578 */
   __ADD(reg_r0_25, reg_r0_13, reg_r0_40); /* line 579 */
   __SLCT(reg_r0_18, reg_b0_2, reg_r0_18, reg_r0_14); /* line 580 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 581 */
   __ADD(reg_r0_5, reg_r0_5, t__i32_0); /* line 582 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_1); /* line 583 */
   __ADD(reg_r0_24, reg_r0_24, reg_r0_35); /* line 584 */
   __ADD(reg_r0_26, reg_r0_26, reg_r0_33); /* line 585 */
   __SHR(reg_r0_22, reg_r0_22, (unsigned int) 8); /* line 586 */
   __LDW(reg_r0_33, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 120),0,4)); /* line 587 */
   __LDW(reg_r0_14, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 136),0,4)); /* line 588 */
} /* line 588 */
  sim_icache_fetch(529 + t_thisfile.offset, 12);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_37 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SHRU(reg_r0_37, reg_r0_10, (unsigned int) 16); /* line 590 */
   __SH2ADD(reg_r0_36, reg_r0_36, (unsigned int) conv7_image); /* line 591 */
   __AND(reg_r0_32, reg_r0_32, (unsigned int) 255); /* line 592 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 593 */
   __SH2ADD(reg_r0_25, reg_r0_25, (unsigned int) conv7_image); /* line 594 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 595 */
   __CMPLT(reg_b0_0, reg_r0_24, 0); /* line 596 */
   __ADD(reg_r0_63, reg_r0_24, (unsigned int) 255); /* line 597 */
   __CMPLT(reg_b0_1, reg_r0_26, 0); /* line 598 */
   __ADD(reg_r0_21, reg_r0_21, t__i32_0); /* line 599 */
} /* line 599 */
  sim_icache_fetch(541 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 601 */
   __LDW(reg_r0_36, mem_trace_ld(reg_r0_36,0,4)); /* line 602 */
   __LDW(reg_r0_25, mem_trace_ld(reg_r0_25,0,4)); /* line 603 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_12); /* line 604 */
   __SLCT(reg_r0_63, reg_b0_0, reg_r0_63, reg_r0_24); /* line 605 */
   __ADD(reg_r0_12, reg_r0_26, (unsigned int) 255); /* line 606 */
   __CMPLT(reg_b0_0, reg_r0_21, 0); /* line 607 */
   __ADD(reg_r0_24, reg_r0_21, (unsigned int) 255); /* line 608 */
   __MULHS(reg_r0_35, reg_r0_14, reg_r0_29); /* line 609 */
} /* line 609 */
  sim_icache_fetch(550 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_0 = reg_r0_26 ;
  t__i32_1 = reg_r0_21 ;
  t__i32_2 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SHRU(reg_r0_21, reg_r0_61, (unsigned int) 16); /* line 611 */
   __SHRU(reg_r0_26, reg_r0_38, (unsigned int) 16); /* line 612 */
   __SHRU(reg_r0_14, reg_r0_8, (unsigned int) 16); /* line 613 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_18); /* line 614 */
   __MULLU(reg_r0_18, reg_r0_57, reg_r0_37); /* line 615 */
   __MULHS(reg_r0_37, reg_r0_57, reg_r0_37); /* line 616 */
   __SHR(reg_r0_63, reg_r0_63, (unsigned int) 8); /* line 617 */
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, t__i32_0); /* line 618 */
   __SLCT(reg_r0_24, reg_b0_0, reg_r0_24, t__i32_1); /* line 619 */
   __MULLU(reg_r0_29, t__i32_2, reg_r0_29); /* line 620 */
} /* line 620 */
  sim_icache_fetch(560 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 622 */
   __AND(reg_r0_26, reg_r0_26, (unsigned int) 255); /* line 623 */
   __AND(reg_r0_14, reg_r0_14, (unsigned int) 255); /* line 624 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_5); /* line 625 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 626 */
   __SHR(reg_r0_24, reg_r0_24, (unsigned int) 8); /* line 627 */
   __MULLU(reg_r0_5, reg_r0_33, reg_r0_32); /* line 628 */
   __MULHS(reg_r0_32, reg_r0_33, reg_r0_32); /* line 629 */
} /* line 629 */
  sim_icache_fetch(568 + t_thisfile.offset, 12);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  unsigned int t__i32_3;
  t__i32_0 = reg_r0_37 ;
  t__i32_2 = reg_r0_22 ;
  t__i32_1 = reg_r0_20 ;
  t__i32_3 = reg_r0_12 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __SHRU(reg_r0_37, reg_r0_25, (unsigned int) 16); /* line 631 */
   __ADD(reg_r0_20, reg_r0_6, reg_r0_28); /* line 632 */
   __ADD(reg_r0_18, reg_r0_18, t__i32_0); /* line 633 */
   __MULLU(reg_r0_12, t__i32_1, reg_r0_21); /* line 634 */
   __MULHS(reg_r0_21, t__i32_1, reg_r0_21); /* line 635 */
   __MULLU(reg_r0_22, reg_r0_31, reg_r0_26); /* line 636 */
   __MULHS(reg_r0_26, reg_r0_31, reg_r0_26); /* line 637 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_2); /* line 638 */
   __ADD(reg_r0_63, reg_r0_63, t__i32_3); /* line 639 */
   __ADD(reg_r0_29, reg_r0_29, reg_r0_35); /* line 640 */
   __LDW(reg_r0_35, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 124),0,4)); /* line 641 */
} /* line 641 */
  sim_icache_fetch(580 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_63 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SHRU(reg_r0_31, reg_r0_36, (unsigned int) 16); /* line 643 */
   __ADD(reg_r0_57, reg_r0_11, reg_r0_40); /* line 644 */
   __ADD(reg_r0_40, reg_r0_17, reg_r0_40); /* line 645 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 646 */
   __SH2ADD(reg_r0_20, reg_r0_20, (unsigned int) conv7_image); /* line 647 */
   __CMPLT(reg_b0_0, reg_r0_18, 0); /* line 648 */
   __ADD(reg_r0_63, reg_r0_18, (unsigned int) 255); /* line 649 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 650 */
   __LDW(reg_r0_33, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 112),0,4)); /* line 651 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_32); /* line 652 */
   __CMPLT(reg_b0_1, reg_r0_29, 0); /* line 653 */
   __LDW(reg_r0_32, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 132),0,4)); /* line 654 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_8); /* line 655 */
} /* line 655 */
  sim_icache_fetch(596 + t_thisfile.offset, 16);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 657 */
   __SH2ADD(reg_r0_57, reg_r0_57, (unsigned int) conv7_image); /* line 658 */
   __SH2ADD(reg_r0_40, reg_r0_40, (unsigned int) conv7_image); /* line 659 */
   __LDW(reg_r0_20, mem_trace_ld(reg_r0_20,0,4)); /* line 660 */
   __SLCT(reg_r0_63, reg_b0_0, reg_r0_63, reg_r0_18); /* line 661 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_21); /* line 662 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_26); /* line 663 */
   __LDW(reg_r0_26, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 116),0,4)); /* line 664 */
   __CMPLT(reg_b0_0, reg_r0_5, 0); /* line 665 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) 255); /* line 666 */
   __MULLU(reg_r0_21, reg_r0_35, reg_r0_34); /* line 667 */
   __MULHS(reg_r0_34, reg_r0_35, reg_r0_34); /* line 668 */
   __ADD(reg_r0_8, reg_r0_29, (unsigned int) 255); /* line 669 */
} /* line 669 */
  sim_icache_fetch(612 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_29 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __LDW(reg_r0_57, mem_trace_ld(reg_r0_57,0,4)); /* line 671 */
   __LDW(reg_r0_40, mem_trace_ld(reg_r0_40,0,4)); /* line 672 */
   __SHR(reg_r0_63, reg_r0_63, (unsigned int) 8); /* line 673 */
   __CMPLT(reg_b0_2, reg_r0_12, 0); /* line 674 */
   __ADD(reg_r0_35, reg_r0_12, (unsigned int) 255); /* line 675 */
   __CMPLT(reg_b0_3, reg_r0_22, 0); /* line 676 */
   __MULLU(reg_r0_29, reg_r0_33, reg_r0_31); /* line 677 */
   __MULHS(reg_r0_31, reg_r0_33, reg_r0_31); /* line 678 */
   __SLCT(reg_r0_18, reg_b0_0, reg_r0_18, reg_r0_5); /* line 679 */
   __MULLU(reg_r0_5, reg_r0_32, reg_r0_37); /* line 680 */
   __MULHS(reg_r0_37, reg_r0_32, reg_r0_37); /* line 681 */
   __SLCT(reg_r0_8, reg_b0_1, reg_r0_8, t__i32_0); /* line 682 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 52),0,4), reg_r0_33); /* line 683 */
} /* line 683 */
  sim_icache_fetch(625 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __ADD(reg_r0_32, reg_r0_9, reg_r0_28); /* line 685 */
   __SLCT(reg_r0_35, reg_b0_2, reg_r0_35, reg_r0_12); /* line 686 */
   __ADD(reg_r0_12, reg_r0_22, (unsigned int) 255); /* line 687 */
   __ADD(reg_r0_63, reg_r0_63, reg_r0_24); /* line 688 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 689 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_34); /* line 690 */
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 691 */
   __LDW(reg_r0_33, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 164),0,4)); /* line 692 */
   __LDW(reg_r0_24, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 128),0,4)); /* line 693 */
} /* line 693 */
  sim_icache_fetch(636 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_37 ;
  t__i32_0 = reg_r0_31 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __SHRU(reg_r0_31, reg_r0_57, (unsigned int) 16); /* line 695 */
   __SHRU(reg_r0_37, reg_r0_40, (unsigned int) 16); /* line 696 */
   __SH2ADD(reg_r0_32, reg_r0_32, (unsigned int) conv7_image); /* line 697 */
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 698 */
   __SLCT(reg_r0_12, reg_b0_3, reg_r0_12, reg_r0_22); /* line 699 */
   __ADD(reg_r0_29, reg_r0_29, t__i32_0); /* line 700 */
   __CMPLT(reg_b0_0, reg_r0_21, 0); /* line 701 */
   __ADD(reg_r0_22, reg_r0_21, (unsigned int) 255); /* line 702 */
   __ADD(reg_r0_5, reg_r0_5, t__i32_1); /* line 703 */
} /* line 703 */
  sim_icache_fetch(646 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 705 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 706 */
   __LDW(reg_r0_32, mem_trace_ld(reg_r0_32,0,4)); /* line 707 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 708 */
   __CMPLT(reg_b0_1, reg_r0_29, 0); /* line 709 */
   __SLCT(reg_r0_22, reg_b0_0, reg_r0_22, reg_r0_21); /* line 710 */
   __CMPLT(reg_b0_0, reg_r0_5, 0); /* line 711 */
   __ADD(reg_r0_21, reg_r0_5, (unsigned int) 255); /* line 712 */
   __MULLU(reg_r0_34, reg_r0_33, reg_r0_39); /* line 713 */
   __MULHS(reg_r0_39, reg_r0_33, reg_r0_39); /* line 714 */
   __LDW(reg_r0_33, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 148),0,4)); /* line 715 */
} /* line 715 */
  sim_icache_fetch(658 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_35, reg_r0_35, reg_r0_12); /* line 717 */
   __ADD(reg_r0_5, reg_r0_29, (unsigned int) 255); /* line 718 */
   __MULLU(reg_r0_12, reg_r0_26, reg_r0_31); /* line 719 */
   __MULHS(reg_r0_31, reg_r0_26, reg_r0_31); /* line 720 */
   __SHR(reg_r0_22, reg_r0_22, (unsigned int) 8); /* line 721 */
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, t__i32_0); /* line 722 */
   __LDW(reg_r0_26, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 156),0,4)); /* line 723 */
} /* line 723 */
  sim_icache_fetch(666 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_39 ;
  t__i32_0 = reg_r0_35 ;
  t__i32_1 = reg_r0_22 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SHRU(reg_r0_35, reg_r0_32, (unsigned int) 16); /* line 725 */
   __ADD(reg_r0_63, reg_r0_63, t__i32_0); /* line 726 */
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_5, reg_r0_29); /* line 727 */
   __MULLU(reg_r0_22, reg_r0_24, reg_r0_37); /* line 728 */
   __MULHS(reg_r0_37, reg_r0_24, reg_r0_37); /* line 729 */
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 8); /* line 730 */
   __ADD(reg_r0_18, reg_r0_18, t__i32_1); /* line 731 */
   __MULLU(reg_r0_29, reg_r0_33, reg_r0_14); /* line 732 */
   __MULHS(reg_r0_14, reg_r0_33, reg_r0_14); /* line 733 */
   __LDW(reg_r0_39, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 152),0,4)); /* line 734 */
   __ADD(reg_r0_34, reg_r0_34, t__i32_2); /* line 735 */
   __LDW(reg_r0_24, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 176),0,4)); /* line 736 */
   __LDW(reg_r0_33, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 192),0,4)); /* line 737 */
} /* line 737 */
  sim_icache_fetch(682 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_63 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __AND(reg_r0_35, reg_r0_35, (unsigned int) 255); /* line 739 */
   __ADD(reg_r0_63, reg_r0_13, reg_r0_28); /* line 740 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 741 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 742 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_31); /* line 743 */
   __CMPLT(reg_b0_0, reg_r0_34, 0); /* line 744 */
   __ADD(reg_r0_31, reg_r0_34, (unsigned int) 255); /* line 745 */
} /* line 745 */
  sim_icache_fetch(689 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_34 ;
  t__i32_0 = reg_r0_8 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SHRU(reg_r0_34, reg_r0_20, (unsigned int) 16); /* line 747 */
   __SH2ADD(reg_r0_63, reg_r0_63, (unsigned int) conv7_image); /* line 748 */
   __CMPLT(reg_b0_1, reg_r0_12, 0); /* line 749 */
   __ADD(reg_r0_8, reg_r0_12, (unsigned int) 255); /* line 750 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_37); /* line 751 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 752 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_21); /* line 753 */
   __ADD(reg_r0_29, reg_r0_29, reg_r0_14); /* line 754 */
   __MULLU(reg_r0_14, reg_r0_39, reg_r0_35); /* line 755 */
   __MULHS(reg_r0_35, reg_r0_39, reg_r0_35); /* line 756 */
   __SLCT(reg_r0_31, reg_b0_0, reg_r0_31, t__i32_1); /* line 757 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 140),0,4)); /* line 758 */
   __LDW(reg_r0_21, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 160),0,4)); /* line 759 */
} /* line 759 */
  sim_icache_fetch(705 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 761 */
   __LDW(reg_r0_63, mem_trace_ld(reg_r0_63,0,4)); /* line 762 */
   __ADD(reg_r0_39, reg_r0_4, (unsigned int) 6); /* line 763 */
   __SLCT(reg_r0_8, reg_b0_1, reg_r0_8, reg_r0_12); /* line 764 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 765 */
   __ADD(reg_r0_12, reg_r0_22, (unsigned int) 255); /* line 766 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_18); /* line 767 */
   __CMPLT(reg_b0_1, reg_r0_29, 0); /* line 768 */
   __ADD(reg_r0_18, reg_r0_29, (unsigned int) 255); /* line 769 */
   __SHR(reg_r0_31, reg_r0_31, (unsigned int) 8); /* line 770 */
   __ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 771 */
} /* line 771 */
  sim_icache_fetch(716 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_35 ;
  t__i32_0 = reg_r0_29 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __ADD(reg_r0_29, reg_r0_11, reg_r0_28); /* line 773 */
   __ADD(reg_r0_28, reg_r0_17, reg_r0_28); /* line 774 */
   __ADD(reg_r0_11, reg_r0_11, reg_r0_39); /* line 775 */
   __ADD(reg_r0_15, reg_r0_15, reg_r0_39); /* line 776 */
   __ADD(reg_r0_9, reg_r0_9, reg_r0_39); /* line 777 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_39); /* line 778 */
   __ADD(reg_r0_13, reg_r0_13, reg_r0_39); /* line 779 */
   __ADD(reg_r0_3, reg_r0_3, reg_r0_39); /* line 780 */
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 781 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, reg_r0_22); /* line 782 */
   __MULLU(reg_r0_22, reg_r0_37, reg_r0_34); /* line 783 */
   __MULHS(reg_r0_34, reg_r0_37, reg_r0_34); /* line 784 */
   __LDW(reg_r0_35, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 144),0,4)); /* line 785 */
   __SLCT(reg_r0_18, reg_b0_1, reg_r0_18, t__i32_0); /* line 786 */
   __ADD(reg_r0_14, reg_r0_14, t__i32_1); /* line 787 */
} /* line 787 */
  sim_icache_fetch(732 + t_thisfile.offset, 21);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SH2ADD(reg_r0_29, reg_r0_29, (unsigned int) conv7_image); /* line 789 */
   __SH2ADD(reg_r0_28, reg_r0_28, (unsigned int) conv7_image); /* line 790 */
   __ADD(reg_r0_39, reg_r0_6, reg_r0_39); /* line 791 */
   __SH2ADD(reg_r0_11, reg_r0_11, (unsigned int) conv7_image); /* line 792 */
   __SH2ADD(reg_r0_15, reg_r0_15, (unsigned int) conv7_image); /* line 793 */
   __SH2ADD(reg_r0_9, reg_r0_9, (unsigned int) conv7_image); /* line 794 */
   __SH2ADD(reg_r0_17, reg_r0_17, (unsigned int) conv7_image); /* line 795 */
   __SH2ADD(reg_r0_13, reg_r0_13, (unsigned int) conv7_image); /* line 796 */
   __SH2ADD(reg_r0_3, reg_r0_3, (unsigned int) conv7_image); /* line 797 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 798 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 799 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 800 */
   __ADD(reg_r0_37, reg_r0_14, (unsigned int) 255); /* line 801 */
} /* line 801 */
  sim_icache_fetch(753 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_12 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __LDW(reg_r0_29, mem_trace_ld(reg_r0_29,0,4)); /* line 803 */
   __LDW(reg_r0_28, mem_trace_ld(reg_r0_28,0,4)); /* line 804 */
   __SHRU(reg_r0_12, reg_r0_63, (unsigned int) 16); /* line 805 */
   __SH2ADD(reg_r0_39, reg_r0_39, (unsigned int) conv7_image); /* line 806 */
   __LDW(reg_r0_11, mem_trace_ld(reg_r0_11,0,4)); /* line 807 */
   __LDW(reg_r0_15, mem_trace_ld(reg_r0_15,0,4)); /* line 808 */
   __LDW(reg_r0_9, mem_trace_ld(reg_r0_9,0,4)); /* line 809 */
   __LDW(reg_r0_17, mem_trace_ld(reg_r0_17,0,4)); /* line 810 */
   __LDW(reg_r0_13, mem_trace_ld(reg_r0_13,0,4)); /* line 811 */
   __LDW(reg_r0_3, mem_trace_ld(reg_r0_3,0,4)); /* line 812 */
   __ADD(reg_r0_8, reg_r0_8, t__i32_0); /* line 813 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_34); /* line 814 */
   __SLCT(reg_r0_37, reg_b0_0, reg_r0_37, reg_r0_14); /* line 815 */
   __LDW(reg_r0_14, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 180),0,4)); /* line 816 */
} /* line 816 */
  sim_icache_fetch(769 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_12, reg_r0_12, (unsigned int) 255); /* line 818 */
   __LDW(reg_r0_39, mem_trace_ld(reg_r0_39,0,4)); /* line 819 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_8); /* line 820 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 821 */
   __ADD(reg_r0_8, reg_r0_22, (unsigned int) 255); /* line 822 */
   __SHR(reg_r0_37, reg_r0_37, (unsigned int) 8); /* line 823 */
} /* line 823 */
  sim_icache_fetch(775 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_37 ;
  t__i32_0 = reg_r0_22 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SHRU(reg_r0_22, reg_r0_29, (unsigned int) 16); /* line 825 */
   __SHRU(reg_r0_37, reg_r0_28, (unsigned int) 16); /* line 826 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_5); /* line 827 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, t__i32_0); /* line 828 */
   __MULLU(reg_r0_5, reg_r0_21, reg_r0_12); /* line 829 */
   __MULHS(reg_r0_12, reg_r0_21, reg_r0_12); /* line 830 */
   __ADD(reg_r0_18, reg_r0_18, t__i32_1); /* line 831 */
} /* line 831 */
  sim_icache_fetch(782 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_31 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __AND(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 833 */
   __AND(reg_r0_37, reg_r0_37, (unsigned int) 255); /* line 834 */
   __SHRU(reg_r0_21, reg_r0_15, (unsigned int) 16); /* line 835 */
   __SHRU(reg_r0_34, reg_r0_9, (unsigned int) 16); /* line 836 */
   __SHRU(reg_r0_31, reg_r0_3, (unsigned int) 16); /* line 837 */
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 838 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_0); /* line 839 */
} /* line 839 */
  sim_icache_fetch(789 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_0 = reg_r0_35 ;
  t__i32_2 = reg_r0_18 ;
  t__i32_1 = reg_r0_12 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 841 */
   __AND(reg_r0_34, reg_r0_34, (unsigned int) 255); /* line 842 */
   __SHRU(reg_r0_35, reg_r0_13, (unsigned int) 16); /* line 843 */
   __AND(reg_r0_31, reg_r0_31, (unsigned int) 255); /* line 844 */
   __MULLU(reg_r0_12, t__i32_0, reg_r0_22); /* line 845 */
   __MULHS(reg_r0_22, t__i32_0, reg_r0_22); /* line 846 */
   __MULLU(reg_r0_18, reg_r0_26, reg_r0_37); /* line 847 */
   __MULHS(reg_r0_37, reg_r0_26, reg_r0_37); /* line 848 */
   __ADD(reg_r0_5, reg_r0_5, t__i32_1); /* line 849 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_2); /* line 850 */
} /* line 850 */
  sim_icache_fetch(799 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __AND(reg_r0_35, reg_r0_35, (unsigned int) 255); /* line 852 */
   __CMPLT(reg_b0_0, reg_r0_5, 0); /* line 853 */
   __ADD(reg_r0_26, reg_r0_5, (unsigned int) 255); /* line 854 */
} /* line 854 */
  sim_icache_fetch(802 + t_thisfile.offset, 9);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __ADD(reg_r0_12, reg_r0_12, reg_r0_22); /* line 856 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_37); /* line 857 */
   __SLCT(reg_r0_26, reg_b0_0, reg_r0_26, reg_r0_5); /* line 858 */
   __MULLU(reg_r0_22, reg_r0_24, reg_r0_21); /* line 859 */
   __MULHS(reg_r0_21, reg_r0_24, reg_r0_21); /* line 860 */
   __MULLU(reg_r0_37, reg_r0_14, reg_r0_34); /* line 861 */
   __MULHS(reg_r0_34, reg_r0_14, reg_r0_34); /* line 862 */
   __MULLU(reg_r0_5, reg_r0_33, reg_r0_31); /* line 863 */
   __MULHS(reg_r0_31, reg_r0_33, reg_r0_31); /* line 864 */
} /* line 864 */
  sim_icache_fetch(811 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_0, reg_r0_12, 0); /* line 866 */
   __ADD(reg_r0_33, reg_r0_12, (unsigned int) 255); /* line 867 */
   __CMPLT(reg_b0_1, reg_r0_18, 0); /* line 868 */
   __SHR(reg_r0_26, reg_r0_26, (unsigned int) 8); /* line 869 */
} /* line 869 */
  sim_icache_fetch(815 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_31 ;
  t__i32_0 = reg_r0_26 ;
  t__i32_1 = reg_r0_21 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SHRU(reg_r0_21, reg_r0_39, (unsigned int) 16); /* line 871 */
   __SHRU(reg_r0_26, reg_r0_11, (unsigned int) 16); /* line 872 */
   __SHRU(reg_r0_14, reg_r0_17, (unsigned int) 16); /* line 873 */
   __SLCT(reg_r0_33, reg_b0_0, reg_r0_33, reg_r0_12); /* line 874 */
   __ADD(reg_r0_12, reg_r0_18, (unsigned int) 255); /* line 875 */
   __ADD(reg_r0_8, reg_r0_8, t__i32_0); /* line 876 */
   __LDW(reg_r0_31, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 168),0,4)); /* line 877 */
   __LDW(reg_r0_24, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 172),0,4)); /* line 878 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_1); /* line 879 */
   __ADD(reg_r0_37, reg_r0_37, reg_r0_34); /* line 880 */
   __ADD(reg_r0_5, reg_r0_5, t__i32_2); /* line 881 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 188),0,4)); /* line 882 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_4); /* line 883 */
} /* line 883 */
  sim_icache_fetch(831 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_21, reg_r0_21, (unsigned int) 255); /* line 885 */
   __AND(reg_r0_26, reg_r0_26, (unsigned int) 255); /* line 886 */
   __AND(reg_r0_14, reg_r0_14, (unsigned int) 255); /* line 887 */
   __SHR(reg_r0_33, reg_r0_33, (unsigned int) 8); /* line 888 */
   __SLCT(reg_r0_12, reg_b0_1, reg_r0_12, reg_r0_18); /* line 889 */
   __CMPLT(reg_b0_1, reg_r0_22, 0); /* line 890 */
   __ADD(reg_r0_4, reg_r0_22, (unsigned int) 255); /* line 891 */
   __CMPLT(reg_b0_2, reg_r0_37, 0); /* line 892 */
   __CMPLT(reg_b0_0, reg_r0_5, 0); /* line 893 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) 255); /* line 894 */
} /* line 894 */
  sim_icache_fetch(841 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_34 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 896 */
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, reg_r0_22); /* line 897 */
   __ADD(reg_r0_5, reg_r0_37, (unsigned int) 255); /* line 898 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 184),0,4)); /* line 899 */
   __MULLU(reg_r0_22, t__i32_0, reg_r0_35); /* line 900 */
   __MULHS(reg_r0_35, t__i32_0, reg_r0_35); /* line 901 */
   __SLCT(reg_r0_18, reg_b0_0, reg_r0_18, t__i32_1); /* line 902 */
} /* line 902 */
  sim_icache_fetch(849 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_37 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_33, reg_r0_33, reg_r0_12); /* line 904 */
   __MULLU(reg_r0_12, reg_r0_31, reg_r0_21); /* line 905 */
   __MULHS(reg_r0_21, reg_r0_31, reg_r0_21); /* line 906 */
   __MULLU(reg_r0_37, reg_r0_24, reg_r0_26); /* line 907 */
   __MULHS(reg_r0_26, reg_r0_24, reg_r0_26); /* line 908 */
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 909 */
   __SLCT(reg_r0_5, reg_b0_2, reg_r0_5, t__i32_0); /* line 910 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 911 */
} /* line 911 */
  sim_icache_fetch(857 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_35 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __AND(reg_r0_35, reg_r0_41, (unsigned int) 255); /* line 913 */
   __SHRU(reg_r0_41, reg_r0_41, (unsigned int) 8); /* line 914 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_33); /* line 915 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 916 */
   __MULLU(reg_r0_33, reg_r0_34, reg_r0_14); /* line 917 */
   __MULHS(reg_r0_14, reg_r0_34, reg_r0_14); /* line 918 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_0); /* line 919 */
} /* line 919 */
  sim_icache_fetch(864 + t_thisfile.offset, 19);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_21 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(16);
   __AND(reg_r0_21, reg_r0_42, (unsigned int) 255); /* line 921 */
   __SHRU(reg_r0_42, reg_r0_42, (unsigned int) 8); /* line 922 */
   __AND(reg_r0_24, reg_r0_44, (unsigned int) 255); /* line 923 */
   __AND(reg_r0_31, reg_r0_43, (unsigned int) 255); /* line 924 */
   __SHRU(reg_r0_43, reg_r0_43, (unsigned int) 8); /* line 925 */
   __AND(reg_r0_41, reg_r0_41, (unsigned int) 255); /* line 926 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_8); /* line 927 */
   __ADD(reg_r0_12, reg_r0_12, t__i32_0); /* line 928 */
   __ADD(reg_r0_37, reg_r0_37, reg_r0_26); /* line 929 */
   __CMPLT(reg_b0_0, reg_r0_22, 0); /* line 930 */
   __ADD(reg_r0_5, reg_r0_22, (unsigned int) 255); /* line 931 */
   __ADD(reg_r0_4, reg_r0_4, t__i32_1); /* line 932 */
   __LDW(reg_r0_26, mem_trace_ld((unsigned int) filter7x7,0,4)); /* line 933 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 12),0,4)); /* line 934 */
   __LDW(reg_r0_8, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 24),0,4)); /* line 935 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_44); /* line 936 */
} /* line 936 */
  sim_icache_fetch(883 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_22 ;
  t__i32_2 = reg_r0_18 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __AND(reg_r0_42, reg_r0_42, (unsigned int) 255); /* line 938 */
   __AND(reg_r0_43, reg_r0_43, (unsigned int) 255); /* line 939 */
   __AND(reg_r0_6, reg_r0_45, (unsigned int) 255); /* line 940 */
   __SHRU(reg_r0_45, reg_r0_45, (unsigned int) 8); /* line 941 */
   __CMPLT(reg_b0_0, reg_r0_12, 0); /* line 942 */
   __ADD(reg_r0_18, reg_r0_12, (unsigned int) 255); /* line 943 */
   __CMPLT(reg_b0_1, reg_r0_37, 0); /* line 944 */
   __ADD(reg_r0_22, reg_r0_37, (unsigned int) 255); /* line 945 */
   __ADD(reg_r0_33, reg_r0_33, reg_r0_14); /* line 946 */
   __SLCT(reg_r0_5, t__i32_0, reg_r0_5, t__i32_1); /* line 947 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_2); /* line 948 */
   __LDW(reg_r0_44, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 4),0,4)); /* line 949 */
} /* line 949 */
  sim_icache_fetch(896 + t_thisfile.offset, 17);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_37 ;
  t__i32_0 = reg_r0_8 ;
  t__i32_2 = reg_r0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __MULLU(reg_r0_4, reg_r0_26, reg_r0_21); /* line 951 */
   __MULHS(reg_r0_21, reg_r0_26, reg_r0_21); /* line 952 */
   __AND(reg_r0_8, reg_r0_46, (unsigned int) 255); /* line 953 */
   __SHRU(reg_r0_46, reg_r0_46, (unsigned int) 8); /* line 954 */
   __AND(reg_r0_45, reg_r0_45, (unsigned int) 255); /* line 955 */
   __MULLU(reg_r0_37, t__i32_0, reg_r0_35); /* line 956 */
   __MULHS(reg_r0_35, t__i32_0, reg_r0_35); /* line 957 */
   __SLCT(reg_r0_18, reg_b0_0, reg_r0_18, reg_r0_12); /* line 958 */
   __SLCT(reg_r0_22, reg_b0_1, reg_r0_22, t__i32_1); /* line 959 */
   __CMPLT(reg_b0_0, reg_r0_33, 0); /* line 960 */
   __ADD(reg_r0_12, reg_r0_33, (unsigned int) 255); /* line 961 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 962 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_2); /* line 963 */
   __LDW(reg_r0_26, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 20),0,4)); /* line 964 */
   __LDW(reg_r0_14, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 8),0,4)); /* line 965 */
} /* line 965 */
  sim_icache_fetch(913 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_33 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_46, reg_r0_46, (unsigned int) 255); /* line 967 */
   __MULLU(reg_r0_33, reg_r0_34, reg_r0_31); /* line 968 */
   __MULHS(reg_r0_31, reg_r0_34, reg_r0_31); /* line 969 */
   __AND(reg_r0_34, reg_r0_47, (unsigned int) 255); /* line 970 */
   __SHRU(reg_r0_47, reg_r0_47, (unsigned int) 8); /* line 971 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 972 */
   __SHR(reg_r0_22, reg_r0_22, (unsigned int) 8); /* line 973 */
   __SLCT(reg_r0_12, reg_b0_0, reg_r0_12, t__i32_0); /* line 974 */
} /* line 974 */
  sim_icache_fetch(921 + t_thisfile.offset, 11);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_35 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __ADD(reg_r0_4, reg_r0_4, reg_r0_21); /* line 976 */
   __MULLU(reg_r0_5, reg_r0_44, reg_r0_24); /* line 977 */
   __MULHS(reg_r0_24, reg_r0_44, reg_r0_24); /* line 978 */
   __MULLU(reg_r0_35, reg_r0_14, reg_r0_8); /* line 979 */
   __MULHS(reg_r0_8, reg_r0_14, reg_r0_8); /* line 980 */
   __AND(reg_r0_47, reg_r0_47, (unsigned int) 255); /* line 981 */
   __MULLU(reg_r0_21, reg_r0_26, reg_r0_6); /* line 982 */
   __MULHS(reg_r0_6, reg_r0_26, reg_r0_6); /* line 983 */
   __ADD(reg_r0_37, reg_r0_37, t__i32_0); /* line 984 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 985 */
   __ADD(reg_r0_18, reg_r0_18, t__i32_1); /* line 986 */
} /* line 986 */
  sim_icache_fetch(932 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_12 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __CMPLT(reg_b0_1, reg_r0_4, 0); /* line 988 */
   __ADD(reg_r0_33, reg_r0_33, reg_r0_31); /* line 989 */
   __CMPLT(reg_b0_0, reg_r0_37, 0); /* line 990 */
   __ADD(reg_r0_12, reg_r0_37, (unsigned int) 255); /* line 991 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_0); /* line 992 */
   __LDW(reg_r0_31, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 16),0,4)); /* line 993 */
} /* line 993 */
  sim_icache_fetch(939 + t_thisfile.offset, 18);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_37 ;
  t__i32_2 = reg_r0_22 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(16);
   __ADD(reg_r0_22, reg_r0_4, (unsigned int) 255); /* line 995 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_24); /* line 996 */
   __AND(reg_r0_44, reg_r0_49, (unsigned int) 255); /* line 997 */
   __SHRU(reg_r0_49, reg_r0_49, (unsigned int) 8); /* line 998 */
   __ADD(reg_r0_35, reg_r0_35, reg_r0_8); /* line 999 */
   __AND(reg_r0_14, reg_r0_50, (unsigned int) 255); /* line 1000 */
   __SHRU(reg_r0_50, reg_r0_50, (unsigned int) 8); /* line 1001 */
   __CMPLT(reg_b0_0, reg_r0_33, 0); /* line 1002 */
   __ADD(reg_r0_37, reg_r0_33, (unsigned int) 255); /* line 1003 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_6); /* line 1004 */
   __AND(reg_r0_8, reg_r0_48, (unsigned int) 255); /* line 1005 */
   __SHRU(reg_r0_48, reg_r0_48, (unsigned int) 8); /* line 1006 */
   __SLCT(reg_r0_12, t__i32_0, reg_r0_12, t__i32_1); /* line 1007 */
   __ADD(reg_r0_18, reg_r0_18, t__i32_2); /* line 1008 */
   __LDW(reg_r0_26, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 36),0,4)); /* line 1009 */
   __LDW(reg_r0_6, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 52),0,4)); /* line 1010 */
} /* line 1010 */
  sim_icache_fetch(957 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_18 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(13);
   __SLCT(reg_r0_22, reg_b0_1, reg_r0_22, reg_r0_4); /* line 1012 */
   __CMPLT(reg_b0_0, reg_r0_5, 0); /* line 1013 */
   __ADD(reg_r0_18, reg_r0_5, (unsigned int) 255); /* line 1014 */
   __AND(reg_r0_49, reg_r0_49, (unsigned int) 255); /* line 1015 */
   __CMPLT(reg_b0_2, reg_r0_35, 0); /* line 1016 */
   __ADD(reg_r0_4, reg_r0_35, (unsigned int) 255); /* line 1017 */
   __AND(reg_r0_50, reg_r0_50, (unsigned int) 255); /* line 1018 */
   __SLCT(reg_r0_37, t__i32_0, reg_r0_37, reg_r0_33); /* line 1019 */
   __CMPLT(reg_b0_1, reg_r0_21, 0); /* line 1020 */
   __ADD(reg_r0_33, reg_r0_21, (unsigned int) 255); /* line 1021 */
   __AND(reg_r0_48, reg_r0_48, (unsigned int) 255); /* line 1022 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1023 */
   __ADD(reg_r0_23, reg_r0_23, t__i32_1); /* line 1024 */
} /* line 1024 */
  sim_icache_fetch(970 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __SHR(reg_r0_22, reg_r0_22, (unsigned int) 8); /* line 1026 */
   __SLCT(reg_r0_18, reg_b0_0, reg_r0_18, reg_r0_5); /* line 1027 */
   __SLCT(reg_r0_4, reg_b0_2, reg_r0_4, reg_r0_35); /* line 1028 */
   __SHR(reg_r0_37, reg_r0_37, (unsigned int) 8); /* line 1029 */
   __MULLU(reg_r0_5, reg_r0_31, reg_r0_34); /* line 1030 */
   __MULHS(reg_r0_34, reg_r0_31, reg_r0_34); /* line 1031 */
   __SLCT(reg_r0_33, reg_b0_1, reg_r0_33, reg_r0_21); /* line 1032 */
   __MULLU(reg_r0_35, reg_r0_26, reg_r0_44); /* line 1033 */
   __MULHS(reg_r0_44, reg_r0_26, reg_r0_44); /* line 1034 */
   __MULLU(reg_r0_21, reg_r0_6, reg_r0_8); /* line 1035 */
   __MULHS(reg_r0_8, reg_r0_6, reg_r0_8); /* line 1036 */
   __MAX(reg_r0_23, reg_r0_23, 0); /* line 1037 */
} /* line 1037 */
  sim_icache_fetch(982 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 1039 */
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1040 */
   __SHR(reg_r0_33, reg_r0_33, (unsigned int) 8); /* line 1041 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_12); /* line 1042 */
   __MIN(reg_r0_23, reg_r0_23, (unsigned int) 255); /* line 1043 */
} /* line 1043 */
  sim_icache_fetch(987 + t_thisfile.offset, 18);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_44 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __AND(reg_r0_44, reg_r0_27, (unsigned int) 255); /* line 1045 */
   __SHRU(reg_r0_27, reg_r0_27, (unsigned int) 8); /* line 1046 */
   __AND(reg_r0_31, reg_r0_52, (unsigned int) 255); /* line 1047 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_34); /* line 1048 */
   __AND(reg_r0_34, reg_r0_51, (unsigned int) 255); /* line 1049 */
   __SHRU(reg_r0_51, reg_r0_51, (unsigned int) 8); /* line 1050 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_33); /* line 1051 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_37); /* line 1052 */
   __ADD(reg_r0_35, reg_r0_35, t__i32_0); /* line 1053 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_8); /* line 1054 */
   __SHL(reg_r0_23, reg_r0_23, (unsigned int) 16); /* line 1055 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 48),0,4)); /* line 1056 */
   __LDW(reg_r0_33, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 40),0,4)); /* line 1057 */
   __LDW(reg_r0_6, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 28),0,4)); /* line 1058 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_52); /* line 1059 */
} /* line 1059 */
  sim_icache_fetch(1005 + t_thisfile.offset, 13);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_27, reg_r0_27, (unsigned int) 255); /* line 1061 */
   __AND(reg_r0_8, reg_r0_19, (unsigned int) 255); /* line 1062 */
   __SHRU(reg_r0_19, reg_r0_19, (unsigned int) 8); /* line 1063 */
   __CMPLT(reg_b0_0, reg_r0_5, 0); /* line 1064 */
   __ADD(reg_r0_52, reg_r0_5, (unsigned int) 255); /* line 1065 */
   __AND(reg_r0_51, reg_r0_51, (unsigned int) 255); /* line 1066 */
   __CMPLT(reg_b0_2, reg_r0_35, 0); /* line 1067 */
   __CMPLT(reg_b0_1, reg_r0_21, 0); /* line 1068 */
   __ADD(reg_r0_26, reg_r0_21, (unsigned int) 255); /* line 1069 */
   __LDW(reg_r0_12, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 32),0,4)); /* line 1070 */
   __LDW(reg_r0_24, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 44),0,4)); /* line 1071 */
} /* line 1071 */
  sim_icache_fetch(1018 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_21 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __AND(reg_r0_19, reg_r0_19, (unsigned int) 255); /* line 1073 */
   __SLCT(reg_r0_52, reg_b0_0, reg_r0_52, reg_r0_5); /* line 1074 */
   __ADD(reg_r0_5, reg_r0_35, (unsigned int) 255); /* line 1075 */
   __MULLU(reg_r0_21, reg_r0_33, reg_r0_14); /* line 1076 */
   __MULHS(reg_r0_14, reg_r0_33, reg_r0_14); /* line 1077 */
   __MULHS(reg_r0_33, reg_r0_37, reg_r0_34); /* line 1078 */
   __SLCT(reg_r0_26, reg_b0_1, reg_r0_26, t__i32_0); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(1025 + t_thisfile.offset, 7);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_35 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __SHR(reg_r0_52, reg_r0_52, (unsigned int) 8); /* line 1081 */
   __MULLU(reg_r0_35, reg_r0_6, reg_r0_44); /* line 1082 */
   __MULHS(reg_r0_44, reg_r0_6, reg_r0_44); /* line 1083 */
   __SLCT(reg_r0_5, reg_b0_2, reg_r0_5, t__i32_0); /* line 1084 */
   __MULLU(reg_r0_34, reg_r0_37, reg_r0_34); /* line 1085 */
   __SHR(reg_r0_26, reg_r0_26, (unsigned int) 8); /* line 1086 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 72),0,4), reg_r0_6); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(1032 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __AND(reg_r0_6, reg_r0_53, (unsigned int) 255); /* line 1089 */
   __SHRU(reg_r0_53, reg_r0_53, (unsigned int) 8); /* line 1090 */
   __ADD(reg_r0_4, reg_r0_4, reg_r0_52); /* line 1091 */
   __MULLU(reg_r0_14, reg_r0_12, reg_r0_31); /* line 1092 */
   __MULHS(reg_r0_31, reg_r0_12, reg_r0_31); /* line 1093 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1094 */
   __ADD(reg_r0_21, reg_r0_21, t__i32_0); /* line 1095 */
   __MULLU(reg_r0_52, reg_r0_24, reg_r0_8); /* line 1096 */
   __MULHS(reg_r0_8, reg_r0_24, reg_r0_8); /* line 1097 */
} /* line 1097 */
  sim_icache_fetch(1041 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_53, reg_r0_53, (unsigned int) 255); /* line 1099 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_4); /* line 1100 */
   __ADD(reg_r0_35, reg_r0_35, reg_r0_44); /* line 1101 */
   __CMPLT(reg_b0_0, reg_r0_21, 0); /* line 1102 */
   __ADD(reg_r0_4, reg_r0_21, (unsigned int) 255); /* line 1103 */
   __ADD(reg_r0_34, reg_r0_34, reg_r0_33); /* line 1104 */
} /* line 1104 */
  sim_icache_fetch(1047 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_21 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __ADD(reg_r0_22, reg_r0_22, reg_r0_18); /* line 1106 */
   __CMPLT(reg_b0_1, reg_r0_35, 0); /* line 1107 */
   __ADD(reg_r0_21, reg_r0_35, (unsigned int) 255); /* line 1108 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_31); /* line 1109 */
   __SLCT(reg_r0_4, reg_b0_0, reg_r0_4, t__i32_0); /* line 1110 */
   __ADD(reg_r0_52, reg_r0_52, reg_r0_8); /* line 1111 */
   __CMPLT(reg_b0_0, reg_r0_34, 0); /* line 1112 */
   __ADD(reg_r0_18, reg_r0_34, (unsigned int) 255); /* line 1113 */
   __LDW(reg_r0_31, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 80),0,4)); /* line 1114 */
} /* line 1114 */
  sim_icache_fetch(1057 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_34 ;
  t__i32_2 = reg_r0_26 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_26, reg_r0_54, (unsigned int) 255); /* line 1116 */
   __SHRU(reg_r0_54, reg_r0_54, (unsigned int) 8); /* line 1117 */
   __SLCT(reg_r0_21, reg_b0_1, reg_r0_21, reg_r0_35); /* line 1118 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 1119 */
   __ADD(reg_r0_34, reg_r0_14, (unsigned int) 255); /* line 1120 */
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1121 */
   __CMPLT(reg_b0_1, reg_r0_52, 0); /* line 1122 */
   __ADD(reg_r0_35, reg_r0_52, (unsigned int) 255); /* line 1123 */
   __SLCT(reg_r0_18, t__i32_0, reg_r0_18, t__i32_1); /* line 1124 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_2); /* line 1125 */
} /* line 1125 */
  sim_icache_fetch(1067 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_31 ;
  t__i32_0 = reg_r0_4 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __AND(reg_r0_54, reg_r0_54, (unsigned int) 255); /* line 1127 */
   __AND(reg_r0_4, reg_r0_55, (unsigned int) 255); /* line 1128 */
   __SHRU(reg_r0_55, reg_r0_55, (unsigned int) 8); /* line 1129 */
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 8); /* line 1130 */
   __SLCT(reg_r0_34, reg_b0_0, reg_r0_34, reg_r0_14); /* line 1131 */
   __SLCT(reg_r0_35, reg_b0_1, reg_r0_35, reg_r0_52); /* line 1132 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 1133 */
   __MULHS(reg_r0_31, reg_r0_37, reg_r0_51); /* line 1134 */
   __ADD(reg_r0_5, reg_r0_5, t__i32_0); /* line 1135 */
   __MULLU(reg_r0_14, t__i32_1, reg_r0_6); /* line 1136 */
   __MULHS(reg_r0_6, t__i32_1, reg_r0_6); /* line 1137 */
   __LDW(reg_r0_52, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 64),0,4)); /* line 1138 */
} /* line 1138 */
  sim_icache_fetch(1080 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __AND(reg_r0_33, reg_r0_58, (unsigned int) 255); /* line 1140 */
   __SHRU(reg_r0_58, reg_r0_58, (unsigned int) 8); /* line 1141 */
   __AND(reg_r0_55, reg_r0_55, (unsigned int) 255); /* line 1142 */
   __AND(reg_r0_8, reg_r0_30, (unsigned int) 255); /* line 1143 */
   __SHRU(reg_r0_30, reg_r0_30, (unsigned int) 8); /* line 1144 */
   __AND(reg_r0_24, reg_r0_56, (unsigned int) 255); /* line 1145 */
   __SHRU(reg_r0_56, reg_r0_56, (unsigned int) 8); /* line 1146 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 1147 */
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 1148 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_18); /* line 1149 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_5); /* line 1150 */
   __LDW(reg_r0_18, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 68),0,4)); /* line 1151 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 56),0,4)); /* line 1152 */
   __LDW(reg_r0_44, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 60),0,4)); /* line 1153 */
} /* line 1153 */
  sim_icache_fetch(1097 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_58, reg_r0_58, (unsigned int) 255); /* line 1155 */
   __AND(reg_r0_30, reg_r0_30, (unsigned int) 255); /* line 1156 */
   __AND(reg_r0_56, reg_r0_56, (unsigned int) 255); /* line 1157 */
   __AND(reg_r0_5, reg_r0_59, (unsigned int) 255); /* line 1158 */
   __SHRU(reg_r0_59, reg_r0_59, (unsigned int) 8); /* line 1159 */
   __ADD(reg_r0_34, reg_r0_34, reg_r0_35); /* line 1160 */
   __MULLU(reg_r0_35, reg_r0_52, reg_r0_26); /* line 1161 */
   __MULHS(reg_r0_26, reg_r0_52, reg_r0_26); /* line 1162 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_6); /* line 1163 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1164 */
   __LDW(reg_r0_12, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 72),0,4)); /* line 1165 */
} /* line 1165 */
  sim_icache_fetch(1109 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_59, reg_r0_59, (unsigned int) 255); /* line 1167 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_34); /* line 1168 */
   __MULLU(reg_r0_52, reg_r0_44, reg_r0_33); /* line 1169 */
   __MULHS(reg_r0_33, reg_r0_44, reg_r0_33); /* line 1170 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 1171 */
   __ADD(reg_r0_34, reg_r0_14, (unsigned int) 255); /* line 1172 */
} /* line 1172 */
  sim_icache_fetch(1115 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_18 ;
  t__i32_1 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_18, reg_r0_60, (unsigned int) 255); /* line 1174 */
   __SHRU(reg_r0_60, reg_r0_60, (unsigned int) 8); /* line 1175 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_21); /* line 1176 */
   __ADD(reg_r0_35, reg_r0_35, reg_r0_26); /* line 1177 */
   __MULLU(reg_r0_14, t__i32_0, reg_r0_4); /* line 1178 */
   __MULHS(reg_r0_4, t__i32_0, reg_r0_4); /* line 1179 */
   __MULLU(reg_r0_21, reg_r0_6, reg_r0_24); /* line 1180 */
   __MULHS(reg_r0_24, reg_r0_6, reg_r0_24); /* line 1181 */
   __SLCT(reg_r0_34, reg_b0_0, reg_r0_34, t__i32_1); /* line 1182 */
   __LDW(reg_r0_26, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1183 */
} /* line 1183 */
  sim_icache_fetch(1125 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __AND(reg_r0_60, reg_r0_60, (unsigned int) 255); /* line 1185 */
   __ADD(reg_r0_52, reg_r0_52, reg_r0_33); /* line 1186 */
   __CMPLT(reg_b0_0, reg_r0_35, 0); /* line 1187 */
   __ADD(reg_r0_44, reg_r0_35, (unsigned int) 255); /* line 1188 */
   __MULLU(reg_r0_33, reg_r0_12, reg_r0_8); /* line 1189 */
   __MULHS(reg_r0_8, reg_r0_12, reg_r0_8); /* line 1190 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 1191 */
} /* line 1191 */
  sim_icache_fetch(1132 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_34 ;
  t__i32_1 = reg_r0_24 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __AND(reg_r0_24, reg_r0_26, (unsigned int) 255); /* line 1193 */
   __SHRU(reg_r0_26, reg_r0_26, (unsigned int) 8); /* line 1194 */
   __CMPLT(reg_b0_0, reg_r0_52, 0); /* line 1195 */
   __ADD(reg_r0_34, reg_r0_52, (unsigned int) 255); /* line 1196 */
   __SLCT(reg_r0_44, t__i32_0, reg_r0_44, reg_r0_35); /* line 1197 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_4); /* line 1198 */
   __ADD(reg_r0_21, reg_r0_21, t__i32_1); /* line 1199 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_2); /* line 1200 */
   __LDW(reg_r0_35, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 108),0,4)); /* line 1201 */
} /* line 1201 */
  sim_icache_fetch(1142 + t_thisfile.offset, 12);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_52 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_26, reg_r0_26, (unsigned int) 255); /* line 1203 */
   __AND(reg_r0_52, reg_r0_62, (unsigned int) 255); /* line 1204 */
   __SHRU(reg_r0_62, reg_r0_62, (unsigned int) 8); /* line 1205 */
   __SLCT(reg_r0_34, reg_b0_0, reg_r0_34, t__i32_0); /* line 1206 */
   __SHR(reg_r0_44, reg_r0_44, (unsigned int) 8); /* line 1207 */
   __CMPLT(reg_b0_1, reg_r0_14, 0); /* line 1208 */
   __ADD(reg_r0_4, reg_r0_14, (unsigned int) 255); /* line 1209 */
   __ADD(reg_r0_33, reg_r0_33, reg_r0_8); /* line 1210 */
   __CMPLT(reg_b0_2, reg_r0_21, 0); /* line 1211 */
   __ADD(reg_r0_12, reg_r0_21, (unsigned int) 255); /* line 1212 */
   __LDW(reg_r0_8, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 92),0,4)); /* line 1213 */
} /* line 1213 */
  sim_icache_fetch(1154 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_21 ;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __AND(reg_r0_62, reg_r0_62, (unsigned int) 255); /* line 1215 */
   __MULLU(reg_r0_14, reg_r0_37, reg_r0_24); /* line 1216 */
   __MULHS(reg_r0_24, reg_r0_37, reg_r0_24); /* line 1217 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 1218 */
   __SLCT(reg_r0_4, reg_b0_1, reg_r0_4, t__i32_0); /* line 1219 */
   __CMPLT(reg_b0_0, reg_r0_33, 0); /* line 1220 */
   __ADD(reg_r0_21, reg_r0_33, (unsigned int) 255); /* line 1221 */
   __SLCT(reg_r0_12, reg_b0_2, reg_r0_12, t__i32_1); /* line 1222 */
   __MULHS(reg_r0_37, reg_r0_35, reg_r0_5); /* line 1223 */
} /* line 1223 */
  sim_icache_fetch(1163 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1225 */
   __SLCT(reg_r0_21, reg_b0_0, reg_r0_21, reg_r0_33); /* line 1226 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1227 */
   __MULLU(reg_r0_33, reg_r0_8, reg_r0_18); /* line 1228 */
   __MULHS(reg_r0_18, reg_r0_8, reg_r0_18); /* line 1229 */
   __MULLU(reg_r0_5, reg_r0_35, reg_r0_5); /* line 1230 */
} /* line 1230 */
  sim_icache_fetch(1169 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_14, reg_r0_14, reg_r0_24); /* line 1232 */
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 8); /* line 1233 */
   __ADD(reg_r0_44, reg_r0_44, reg_r0_4); /* line 1234 */
   __LDW(reg_r0_4, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 96),0,4)); /* line 1235 */
} /* line 1235 */
  sim_icache_fetch(1174 + t_thisfile.offset, 14);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_44 ;
  t__i32_1 = reg_r0_18 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(12);
   __AND(reg_r0_35, reg_r0_10, (unsigned int) 255); /* line 1237 */
   __SHRU(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1238 */
   __AND(reg_r0_18, reg_r0_7, (unsigned int) 255); /* line 1239 */
   __SHRU(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1240 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 1241 */
   __ADD(reg_r0_44, reg_r0_14, (unsigned int) 255); /* line 1242 */
   __ADD(reg_r0_34, reg_r0_34, reg_r0_21); /* line 1243 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_0); /* line 1244 */
   __ADD(reg_r0_33, reg_r0_33, t__i32_1); /* line 1245 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_37); /* line 1246 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 104),0,4)); /* line 1247 */
   __LDW(reg_r0_8, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 84),0,4)); /* line 1248 */
} /* line 1248 */
  sim_icache_fetch(1188 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_10, reg_r0_10, (unsigned int) 255); /* line 1250 */
   __AND(reg_r0_7, reg_r0_7, (unsigned int) 255); /* line 1251 */
   __SLCT(reg_r0_44, reg_b0_0, reg_r0_44, reg_r0_14); /* line 1252 */
   __CMPLT(reg_b0_1, reg_r0_33, 0); /* line 1253 */
   __ADD(reg_r0_21, reg_r0_33, (unsigned int) 255); /* line 1254 */
   __MULHS(reg_r0_24, reg_r0_4, reg_r0_52); /* line 1255 */
   __CMPLT(reg_b0_0, reg_r0_5, 0); /* line 1256 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) 255); /* line 1257 */
} /* line 1257 */
  sim_icache_fetch(1196 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_33 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __SHR(reg_r0_44, reg_r0_44, (unsigned int) 8); /* line 1259 */
   __MULLU(reg_r0_33, reg_r0_8, reg_r0_35); /* line 1260 */
   __MULHS(reg_r0_35, reg_r0_8, reg_r0_35); /* line 1261 */
   __SLCT(reg_r0_21, reg_b0_1, reg_r0_21, t__i32_0); /* line 1262 */
   __MULLU(reg_r0_52, reg_r0_4, reg_r0_52); /* line 1263 */
   __MULLU(reg_r0_5, reg_r0_37, reg_r0_18); /* line 1264 */
   __MULHS(reg_r0_18, reg_r0_37, reg_r0_18); /* line 1265 */
   __SLCT(reg_r0_14, reg_b0_0, reg_r0_14, t__i32_1); /* line 1266 */
} /* line 1266 */
  sim_icache_fetch(1204 + t_thisfile.offset, 5);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_12 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __AND(reg_r0_12, reg_r0_61, (unsigned int) 255); /* line 1268 */
   __SHRU(reg_r0_61, reg_r0_61, (unsigned int) 8); /* line 1269 */
   __ADD(reg_r0_44, reg_r0_44, t__i32_0); /* line 1270 */
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 8); /* line 1271 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1272 */
} /* line 1272 */
  sim_icache_fetch(1209 + t_thisfile.offset, 11);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_24 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __AND(reg_r0_61, reg_r0_61, (unsigned int) 255); /* line 1274 */
   __AND(reg_r0_24, reg_r0_38, (unsigned int) 255); /* line 1275 */
   __ADD(reg_r0_44, reg_r0_44, reg_r0_34); /* line 1276 */
   __ADD(reg_r0_33, reg_r0_33, reg_r0_35); /* line 1277 */
   __ADD(reg_r0_52, reg_r0_52, t__i32_0); /* line 1278 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_18); /* line 1279 */
   __LDW(reg_r0_18, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 88),0,4)); /* line 1280 */
   __LDW(reg_r0_8, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 100),0,4)); /* line 1281 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_38); /* line 1282 */
} /* line 1282 */
  sim_icache_fetch(1220 + t_thisfile.offset, 12);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_35, reg_r0_16, (unsigned int) 255); /* line 1284 */
   __SHRU(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 1285 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_44); /* line 1286 */
   __CMPLT(reg_b0_2, reg_r0_33, 0); /* line 1287 */
   __CMPLT(reg_b0_0, reg_r0_52, 0); /* line 1288 */
   __ADD(reg_r0_38, reg_r0_52, (unsigned int) 255); /* line 1289 */
   __CMPLT(reg_b0_1, reg_r0_5, 0); /* line 1290 */
   __ADD(reg_r0_44, reg_r0_5, (unsigned int) 255); /* line 1291 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 120),0,4)); /* line 1292 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 136),0,4)); /* line 1293 */
} /* line 1293 */
  sim_icache_fetch(1232 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_0 = reg_r0_18 ;
  t__i32_2 = reg_r0_14 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_16, reg_r0_16, (unsigned int) 255); /* line 1295 */
   __MULHS(reg_r0_18, reg_r0_6, reg_r0_56); /* line 1296 */
   __ADD(reg_r0_5, reg_r0_33, (unsigned int) 255); /* line 1297 */
   __MULLU(reg_r0_14, t__i32_0, reg_r0_12); /* line 1298 */
   __MULHS(reg_r0_12, t__i32_0, reg_r0_12); /* line 1299 */
   __SLCT(reg_r0_38, reg_b0_0, reg_r0_38, reg_r0_52); /* line 1300 */
   __MULLU(reg_r0_52, reg_r0_8, reg_r0_24); /* line 1301 */
   __MULHS(reg_r0_24, reg_r0_8, reg_r0_24); /* line 1302 */
   __SLCT(reg_r0_44, reg_b0_1, reg_r0_44, t__i32_1); /* line 1303 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_2); /* line 1304 */
} /* line 1304 */
  sim_icache_fetch(1242 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __MULLU(reg_r0_6, reg_r0_6, reg_r0_56); /* line 1306 */
   __SLCT(reg_r0_5, reg_b0_2, reg_r0_5, reg_r0_33); /* line 1307 */
   __SHR(reg_r0_38, reg_r0_38, (unsigned int) 8); /* line 1308 */
   __SHR(reg_r0_44, reg_r0_44, (unsigned int) 8); /* line 1309 */
   __LDW(reg_r0_33, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1310 */
   __LDW(reg_r0_56, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 72),0,4)); /* line 1311 */
} /* line 1311 */
  sim_icache_fetch(1249 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_24 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_24, reg_r0_2, (unsigned int) 255); /* line 1313 */
   __SHRU(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1314 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1315 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_12); /* line 1316 */
   __ADD(reg_r0_52, reg_r0_52, t__i32_0); /* line 1317 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_38); /* line 1318 */
   __MULLU(reg_r0_12, reg_r0_37, reg_r0_35); /* line 1319 */
   __MULHS(reg_r0_35, reg_r0_37, reg_r0_35); /* line 1320 */
} /* line 1320 */
  sim_icache_fetch(1257 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_44 ;
  t__i32_2 = reg_r0_21 ;
  t__i32_0 = reg_r0_18 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_2, reg_r0_2, (unsigned int) 255); /* line 1322 */
   __MULLU(reg_r0_18, reg_r0_56, reg_r0_30); /* line 1323 */
   __MULHS(reg_r0_56, reg_r0_56, reg_r0_30); /* line 1324 */
   __ADD(reg_r0_6, reg_r0_6, t__i32_0); /* line 1325 */
   __CMPLT(reg_b0_0, reg_r0_14, 0); /* line 1326 */
   __ADD(reg_r0_21, reg_r0_14, (unsigned int) 255); /* line 1327 */
   __CMPLT(reg_b0_1, reg_r0_52, 0); /* line 1328 */
   __ADD(reg_r0_44, reg_r0_52, (unsigned int) 255); /* line 1329 */
   __ADD(reg_r0_5, reg_r0_5, t__i32_1); /* line 1330 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_2); /* line 1331 */
} /* line 1331 */
  sim_icache_fetch(1267 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_52 ;
  t__i32_1 = reg_r0_14 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __AND(reg_r0_30, reg_r0_36, (unsigned int) 255); /* line 1333 */
   __SHRU(reg_r0_36, reg_r0_36, (unsigned int) 8); /* line 1334 */
   __AND(reg_r0_8, reg_r0_57, (unsigned int) 255); /* line 1335 */
   __SHRU(reg_r0_57, reg_r0_57, (unsigned int) 8); /* line 1336 */
   __AND(reg_r0_52, reg_r0_25, (unsigned int) 255); /* line 1337 */
   __SHRU(reg_r0_25, reg_r0_25, (unsigned int) 8); /* line 1338 */
   __AND(reg_r0_14, reg_r0_33, (unsigned int) 255); /* line 1339 */
   __SHRU(reg_r0_33, reg_r0_33, (unsigned int) 8); /* line 1340 */
   __CMPLT(reg_b0_0, reg_r0_6, 0); /* line 1341 */
   __SLCT(reg_r0_21, t__i32_0, reg_r0_21, t__i32_1); /* line 1342 */
   __SLCT(reg_r0_44, reg_b0_1, reg_r0_44, t__i32_2); /* line 1343 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_35); /* line 1344 */
   __LDW(reg_r0_35, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 124),0,4)); /* line 1345 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 132),0,4)); /* line 1346 */
} /* line 1346 */
  sim_icache_fetch(1283 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_36, reg_r0_36, (unsigned int) 255); /* line 1348 */
   __AND(reg_r0_57, reg_r0_57, (unsigned int) 255); /* line 1349 */
   __AND(reg_r0_25, reg_r0_25, (unsigned int) 255); /* line 1350 */
   __AND(reg_r0_33, reg_r0_33, (unsigned int) 255); /* line 1351 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_56); /* line 1352 */
   __SHR(reg_r0_21, reg_r0_21, (unsigned int) 8); /* line 1353 */
   __SHR(reg_r0_44, reg_r0_44, (unsigned int) 8); /* line 1354 */
   __CMPLT(reg_b0_1, reg_r0_12, 0); /* line 1355 */
   __MULLU(reg_r0_4, reg_r0_34, reg_r0_14); /* line 1356 */
   __MULHS(reg_r0_14, reg_r0_34, reg_r0_14); /* line 1357 */
} /* line 1357 */
  sim_icache_fetch(1293 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_34, reg_r0_40, (unsigned int) 255); /* line 1359 */
   __SHRU(reg_r0_40, reg_r0_40, (unsigned int) 8); /* line 1360 */
   __CMPLT(reg_b0_2, reg_r0_18, 0); /* line 1361 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_44); /* line 1362 */
   __ADD(reg_r0_44, reg_r0_12, (unsigned int) 255); /* line 1363 */
   __LDW(reg_r0_56, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 116),0,4)); /* line 1364 */
} /* line 1364 */
  sim_icache_fetch(1300 + t_thisfile.offset, 13);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_40, reg_r0_40, (unsigned int) 255); /* line 1366 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_21); /* line 1367 */
   __SLCT(reg_r0_44, reg_b0_1, reg_r0_44, reg_r0_12); /* line 1368 */
   __MULLU(reg_r0_12, reg_r0_35, reg_r0_24); /* line 1369 */
   __MULHS(reg_r0_24, reg_r0_35, reg_r0_24); /* line 1370 */
   __MULLU(reg_r0_14, reg_r0_37, reg_r0_52); /* line 1371 */
   __MULHS(reg_r0_52, reg_r0_37, reg_r0_52); /* line 1372 */
   __ADD(reg_r0_4, reg_r0_4, t__i32_0); /* line 1373 */
   __LDW(reg_r0_21, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1374 */
   __LDW(reg_r0_38, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 164),0,4)); /* line 1375 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 128),0,4)); /* line 1376 */
} /* line 1376 */
  sim_icache_fetch(1313 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_22, reg_r0_22, reg_r0_5); /* line 1378 */
   __MULHS(reg_r0_35, reg_r0_56, reg_r0_8); /* line 1379 */
   __SHR(reg_r0_44, reg_r0_44, (unsigned int) 8); /* line 1380 */
   __CMPLT(reg_b0_1, reg_r0_4, 0); /* line 1381 */
   __ADD(reg_r0_5, reg_r0_4, (unsigned int) 255); /* line 1382 */
} /* line 1382 */
  sim_icache_fetch(1318 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_52 ;
  t__i32_0 = reg_r0_24 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __MULLU(reg_r0_24, reg_r0_21, reg_r0_30); /* line 1384 */
   __MULHS(reg_r0_30, reg_r0_21, reg_r0_30); /* line 1385 */
   __MULLU(reg_r0_8, reg_r0_56, reg_r0_8); /* line 1386 */
   __ADD(reg_r0_12, reg_r0_12, t__i32_0); /* line 1387 */
   __MULLU(reg_r0_52, reg_r0_37, reg_r0_34); /* line 1388 */
   __MULHS(reg_r0_34, reg_r0_37, reg_r0_34); /* line 1389 */
   __ADD(reg_r0_14, reg_r0_14, t__i32_1); /* line 1390 */
   __SLCT(reg_r0_5, reg_b0_1, reg_r0_5, reg_r0_4); /* line 1391 */
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1392 */
} /* line 1392 */
  sim_icache_fetch(1327 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __CMPLT(reg_b0_1, reg_r0_12, 0); /* line 1394 */
   __ADD(reg_r0_37, reg_r0_12, (unsigned int) 255); /* line 1395 */
   __CMPLT(reg_b0_3, reg_r0_14, 0); /* line 1396 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1397 */
} /* line 1397 */
  sim_icache_fetch(1331 + t_thisfile.offset, 11);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_12 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_12, reg_r0_4, (unsigned int) 255); /* line 1399 */
   __SHRU(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1400 */
   __ADD(reg_r0_24, reg_r0_24, reg_r0_30); /* line 1401 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_35); /* line 1402 */
   __SLCT(reg_r0_37, reg_b0_1, reg_r0_37, t__i32_0); /* line 1403 */
   __ADD(reg_r0_52, reg_r0_52, reg_r0_34); /* line 1404 */
   __ADD(reg_r0_5, reg_r0_14, (unsigned int) 255); /* line 1405 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_1); /* line 1406 */
   __LDW(reg_r0_30, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 1407 */
   __LDW(reg_r0_56, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 148),0,4)); /* line 1408 */
} /* line 1408 */
  sim_icache_fetch(1342 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_14 ;
  t__i32_0 = reg_b0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_4, reg_r0_4, (unsigned int) 255); /* line 1410 */
   __CMPLT(reg_b0_1, reg_r0_24, 0); /* line 1411 */
   __ADD(reg_r0_14, reg_r0_24, (unsigned int) 255); /* line 1412 */
   __CMPLT(reg_b0_3, reg_r0_8, 0); /* line 1413 */
   __SHR(reg_r0_37, reg_r0_37, (unsigned int) 8); /* line 1414 */
   __CMPLT(reg_b0_4, reg_r0_52, 0); /* line 1415 */
   __SLCT(reg_r0_5, t__i32_0, reg_r0_5, t__i32_1); /* line 1416 */
   __MULHS(reg_r0_34, reg_r0_38, reg_r0_12); /* line 1417 */
} /* line 1417 */
  sim_icache_fetch(1350 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_37 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __SLCT(reg_r0_14, reg_b0_1, reg_r0_14, reg_r0_24); /* line 1419 */
   __ADD(reg_r0_24, reg_r0_8, (unsigned int) 255); /* line 1420 */
   __ADD(reg_r0_37, reg_r0_52, (unsigned int) 255); /* line 1421 */
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1422 */
   __ADD(reg_r0_44, reg_r0_44, t__i32_0); /* line 1423 */
   __MULLU(reg_r0_12, reg_r0_38, reg_r0_12); /* line 1424 */
} /* line 1424 */
  sim_icache_fetch(1356 + t_thisfile.offset, 8);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_44 ;
  t__i32_0 = reg_r0_8 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __AND(reg_r0_8, reg_r0_30, (unsigned int) 255); /* line 1426 */
   __SHRU(reg_r0_30, reg_r0_30, (unsigned int) 8); /* line 1427 */
   __AND(reg_r0_44, reg_r0_32, (unsigned int) 255); /* line 1428 */
   __SHRU(reg_r0_32, reg_r0_32, (unsigned int) 8); /* line 1429 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1430 */
   __SLCT(reg_r0_24, reg_b0_3, reg_r0_24, t__i32_0); /* line 1431 */
   __SLCT(reg_r0_37, reg_b0_4, reg_r0_37, reg_r0_52); /* line 1432 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_1); /* line 1433 */
} /* line 1433 */
  sim_icache_fetch(1364 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_56 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __AND(reg_r0_52, reg_r0_20, (unsigned int) 255); /* line 1435 */
   __AND(reg_r0_30, reg_r0_30, (unsigned int) 255); /* line 1436 */
   __AND(reg_r0_32, reg_r0_32, (unsigned int) 255); /* line 1437 */
   __AND(reg_r0_56, reg_r0_63, (unsigned int) 255); /* line 1438 */
   __SHRU(reg_r0_63, reg_r0_63, (unsigned int) 8); /* line 1439 */
   __SHR(reg_r0_24, reg_r0_24, (unsigned int) 8); /* line 1440 */
   __SHR(reg_r0_37, reg_r0_37, (unsigned int) 8); /* line 1441 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_5); /* line 1442 */
   __MULLU(reg_r0_5, t__i32_0, reg_r0_8); /* line 1443 */
   __MULHS(reg_r0_8, t__i32_0, reg_r0_8); /* line 1444 */
   __ADD(reg_r0_12, reg_r0_12, reg_r0_34); /* line 1445 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 152),0,4)); /* line 1446 */
   __LDW(reg_r0_35, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 160),0,4)); /* line 1447 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 80),0,4), reg_r0_20); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(1380 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __AND(reg_r0_63, reg_r0_63, (unsigned int) 255); /* line 1450 */
   __ADD(reg_r0_24, reg_r0_24, reg_r0_37); /* line 1451 */
   __CMPLT(reg_b0_1, reg_r0_12, 0); /* line 1452 */
   __ADD(reg_r0_20, reg_r0_12, (unsigned int) 255); /* line 1453 */
} /* line 1453 */
  sim_icache_fetch(1384 + t_thisfile.offset, 9);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_12 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_14, reg_r0_14, reg_r0_24); /* line 1455 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_8); /* line 1456 */
   __MULLU(reg_r0_8, reg_r0_34, reg_r0_44); /* line 1457 */
   __MULHS(reg_r0_44, reg_r0_34, reg_r0_44); /* line 1458 */
   __MULLU(reg_r0_12, reg_r0_35, reg_r0_56); /* line 1459 */
   __MULHS(reg_r0_56, reg_r0_35, reg_r0_56); /* line 1460 */
   __SLCT(reg_r0_20, reg_b0_1, reg_r0_20, t__i32_0); /* line 1461 */
   __LDW(reg_r0_24, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 140),0,4)); /* line 1462 */
} /* line 1462 */
  sim_icache_fetch(1393 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __ADD(reg_r0_22, reg_r0_22, reg_r0_14); /* line 1464 */
   __CMPLT(reg_b0_1, reg_r0_5, 0); /* line 1465 */
   __ADD(reg_r0_14, reg_r0_5, (unsigned int) 255); /* line 1466 */
   __SHR(reg_r0_20, reg_r0_20, (unsigned int) 8); /* line 1467 */
} /* line 1467 */
  sim_icache_fetch(1397 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_56 ;
  t__i32_2 = reg_r0_20 ;
  t__i32_0 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __AND(reg_r0_20, reg_r0_29, (unsigned int) 255); /* line 1469 */
   __SHRU(reg_r0_29, reg_r0_29, (unsigned int) 8); /* line 1470 */
   __AND(reg_r0_56, reg_r0_28, (unsigned int) 255); /* line 1471 */
   __SHRU(reg_r0_28, reg_r0_28, (unsigned int) 8); /* line 1472 */
   __AND(reg_r0_38, reg_r0_3, (unsigned int) 255); /* line 1473 */
   __MULLU(reg_r0_5, reg_r0_24, reg_r0_52); /* line 1474 */
   __MULHS(reg_r0_52, reg_r0_24, reg_r0_52); /* line 1475 */
   __SLCT(reg_r0_14, reg_b0_1, reg_r0_14, t__i32_0); /* line 1476 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_44); /* line 1477 */
   __ADD(reg_r0_12, reg_r0_12, t__i32_1); /* line 1478 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_2); /* line 1479 */
   __LDW(reg_r0_44, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 144),0,4)); /* line 1480 */
   __LDW(reg_r0_35, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 156),0,4)); /* line 1481 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 84),0,4), reg_r0_3); /* line 1482 */
} /* line 1482 */
  sim_icache_fetch(1413 + t_thisfile.offset, 11);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __AND(reg_r0_29, reg_r0_29, (unsigned int) 255); /* line 1484 */
   __AND(reg_r0_28, reg_r0_28, (unsigned int) 255); /* line 1485 */
   __AND(reg_r0_34, reg_r0_15, (unsigned int) 255); /* line 1486 */
   __SHRU(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1487 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1488 */
   __CMPLT(reg_b0_1, reg_r0_8, 0); /* line 1489 */
   __ADD(reg_r0_3, reg_r0_8, (unsigned int) 255); /* line 1490 */
   __CMPLT(reg_b0_3, reg_r0_12, 0); /* line 1491 */
   __ADD(reg_r0_24, reg_r0_12, (unsigned int) 255); /* line 1492 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 192),0,4)); /* line 1493 */
} /* line 1493 */
  sim_icache_fetch(1424 + t_thisfile.offset, 12);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_0 = reg_r0_44 ;
  t__i32_2 = reg_r0_12 ;
  t__i32_1 = reg_r0_8 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_15, reg_r0_15, (unsigned int) 255); /* line 1495 */
   __AND(reg_r0_44, reg_r0_9, (unsigned int) 255); /* line 1496 */
   __SHRU(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1497 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_52); /* line 1498 */
   __MULLU(reg_r0_8, t__i32_0, reg_r0_20); /* line 1499 */
   __MULHS(reg_r0_20, t__i32_0, reg_r0_20); /* line 1500 */
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_3, t__i32_1); /* line 1501 */
   __MULLU(reg_r0_12, reg_r0_35, reg_r0_56); /* line 1502 */
   __MULHS(reg_r0_56, reg_r0_35, reg_r0_56); /* line 1503 */
   __SLCT(reg_r0_24, reg_b0_3, reg_r0_24, t__i32_2); /* line 1504 */
   __LDW(reg_r0_52, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 176),0,4)); /* line 1505 */
} /* line 1505 */
  sim_icache_fetch(1436 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __AND(reg_r0_9, reg_r0_9, (unsigned int) 255); /* line 1507 */
   __CMPLT(reg_b0_1, reg_r0_5, 0); /* line 1508 */
   __ADD(reg_r0_35, reg_r0_5, (unsigned int) 255); /* line 1509 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1510 */
   __SHR(reg_r0_24, reg_r0_24, (unsigned int) 8); /* line 1511 */
} /* line 1511 */
  sim_icache_fetch(1441 + t_thisfile.offset, 12);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_56 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(11);
   __AND(reg_r0_56, reg_r0_13, (unsigned int) 255); /* line 1513 */
   __SHRU(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1514 */
   __SLCT(reg_r0_35, reg_b0_1, reg_r0_35, reg_r0_5); /* line 1515 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_20); /* line 1516 */
   __ADD(reg_r0_12, reg_r0_12, t__i32_0); /* line 1517 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_3); /* line 1518 */
   __MULLU(reg_r0_5, reg_r0_52, reg_r0_34); /* line 1519 */
   __MULHS(reg_r0_34, reg_r0_52, reg_r0_34); /* line 1520 */
   __MULLU(reg_r0_3, reg_r0_37, reg_r0_38); /* line 1521 */
   __MULHS(reg_r0_38, reg_r0_37, reg_r0_38); /* line 1522 */
   __LDW(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 180),0,4)); /* line 1523 */
} /* line 1523 */
  sim_icache_fetch(1453 + t_thisfile.offset, 6);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(6);
   __AND(reg_r0_13, reg_r0_13, (unsigned int) 255); /* line 1525 */
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 1526 */
   __CMPLT(reg_b0_1, reg_r0_8, 0); /* line 1527 */
   __ADD(reg_r0_14, reg_r0_8, (unsigned int) 255); /* line 1528 */
   __CMPLT(reg_b0_3, reg_r0_12, 0); /* line 1529 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_0); /* line 1530 */
} /* line 1530 */
  sim_icache_fetch(1459 + t_thisfile.offset, 17);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_38 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __AND(reg_r0_38, reg_r0_39, (unsigned int) 255); /* line 1532 */
   __SHRU(reg_r0_39, reg_r0_39, (unsigned int) 8); /* line 1533 */
   __AND(reg_r0_37, reg_r0_11, (unsigned int) 255); /* line 1534 */
   __SLCT(reg_r0_14, reg_b0_1, reg_r0_14, reg_r0_8); /* line 1535 */
   __ADD(reg_r0_8, reg_r0_12, (unsigned int) 255); /* line 1536 */
   __ADD(reg_r0_35, reg_r0_35, reg_r0_24); /* line 1537 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_34); /* line 1538 */
   __MULLU(reg_r0_24, reg_r0_20, reg_r0_44); /* line 1539 */
   __MULHS(reg_r0_44, reg_r0_20, reg_r0_44); /* line 1540 */
   __ADD(reg_r0_3, reg_r0_3, t__i32_0); /* line 1541 */
   __LDW(reg_r0_52, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 168),0,4)); /* line 1542 */
   __LDW(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 172),0,4)); /* line 1543 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 188),0,4)); /* line 1544 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 88),0,4), reg_r0_11); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(1476 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __AND(reg_r0_39, reg_r0_39, (unsigned int) 255); /* line 1547 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1548 */
   __SLCT(reg_r0_8, reg_b0_3, reg_r0_8, reg_r0_12); /* line 1549 */
   __CMPLT(reg_b0_3, reg_r0_5, 0); /* line 1550 */
   __ADD(reg_r0_12, reg_r0_5, (unsigned int) 255); /* line 1551 */
   __CMPLT(reg_b0_1, reg_r0_3, 0); /* line 1552 */
   __ADD(reg_r0_11, reg_r0_3, (unsigned int) 255); /* line 1553 */
} /* line 1553 */
  sim_icache_fetch(1483 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_1 = reg_r0_44 ;
  t__i32_0 = reg_r0_5 ;
  t__i32_2 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1555 */
   __MULLU(reg_r0_5, reg_r0_52, reg_r0_38); /* line 1556 */
   __MULHS(reg_r0_38, reg_r0_52, reg_r0_38); /* line 1557 */
   __MULLU(reg_r0_44, reg_r0_20, reg_r0_37); /* line 1558 */
   __MULHS(reg_r0_37, reg_r0_20, reg_r0_37); /* line 1559 */
   __SLCT(reg_r0_12, reg_b0_3, reg_r0_12, t__i32_0); /* line 1560 */
   __ADD(reg_r0_24, reg_r0_24, t__i32_1); /* line 1561 */
   __MULLU(reg_r0_3, reg_r0_34, reg_r0_56); /* line 1562 */
   __MULHS(reg_r0_56, reg_r0_34, reg_r0_56); /* line 1563 */
   __SLCT(reg_r0_11, reg_b0_1, reg_r0_11, t__i32_2); /* line 1564 */
} /* line 1564 */
  sim_icache_fetch(1493 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_14, reg_r0_14, reg_r0_8); /* line 1566 */
   __SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1567 */
   __CMPLT(reg_b0_1, reg_r0_24, 0); /* line 1568 */
   __ADD(reg_r0_8, reg_r0_24, (unsigned int) 255); /* line 1569 */
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1570 */
} /* line 1570 */
  sim_icache_fetch(1498 + t_thisfile.offset, 21);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_14 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __AND(reg_r0_14, reg_r0_17, (unsigned int) 255); /* line 1572 */
   __ADD(reg_r0_35, reg_r0_35, t__i32_0); /* line 1573 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_38); /* line 1574 */
   __ADD(reg_r0_44, reg_r0_44, reg_r0_37); /* line 1575 */
   __SLCT(reg_r0_8, reg_b0_1, reg_r0_8, reg_r0_24); /* line 1576 */
   __ADD(reg_r0_3, reg_r0_3, reg_r0_56); /* line 1577 */
   __LDW(reg_r0_52, mem_trace_ld((unsigned int) filter7x7,0,4)); /* line 1578 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 24),0,4)); /* line 1579 */
   __LDW(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 4),0,4)); /* line 1580 */
   __LDW(reg_r0_56, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 20),0,4)); /* line 1581 */
   __LDW(reg_r0_38, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 36),0,4)); /* line 1582 */
   __LDW(reg_r0_24, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 184),0,4)); /* line 1583 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 12),0,4)); /* line 1584 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 92),0,4), reg_r0_17); /* line 1585 */
} /* line 1585 */
  sim_icache_fetch(1519 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_22, reg_r0_22, reg_r0_35); /* line 1587 */
   __CMPLT(reg_b0_3, reg_r0_5, 0); /* line 1588 */
   __ADD(reg_r0_35, reg_r0_5, (unsigned int) 255); /* line 1589 */
   __CMPLT(reg_b0_4, reg_r0_44, 0); /* line 1590 */
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1591 */
   __CMPLT(reg_b0_1, reg_r0_3, 0); /* line 1592 */
   __ADD(reg_r0_17, reg_r0_3, (unsigned int) 255); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(1526 + t_thisfile.offset, 16);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  unsigned int t__i32_3;
  t__i32_0 = reg_r0_41 ;
  t__i32_2 = reg_r0_11 ;
  t__i32_3 = reg_r0_8 ;
  t__i32_1 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(16);
   __MULLU(reg_r0_11, reg_r0_52, reg_r0_42); /* line 1595 */
   __MULHS(reg_r0_52, reg_r0_52, reg_r0_42); /* line 1596 */
   __MULLU(reg_r0_41, reg_r0_34, reg_r0_43); /* line 1597 */
   __MULHS(reg_r0_34, reg_r0_34, reg_r0_43); /* line 1598 */
   __MULLU(reg_r0_43, reg_r0_56, reg_r0_45); /* line 1599 */
   __MULHS(reg_r0_56, reg_r0_56, reg_r0_45); /* line 1600 */
   __MULLU(reg_r0_8, reg_r0_37, t__i32_0); /* line 1601 */
   __MULHS(reg_r0_37, reg_r0_37, t__i32_0); /* line 1602 */
   __SLCT(reg_r0_35, reg_b0_3, reg_r0_35, reg_r0_5); /* line 1603 */
   __ADD(reg_r0_3, reg_r0_44, (unsigned int) 255); /* line 1604 */
   __MULLU(reg_r0_5, reg_r0_24, reg_r0_14); /* line 1605 */
   __MULHS(reg_r0_14, reg_r0_24, reg_r0_14); /* line 1606 */
   __SLCT(reg_r0_17, reg_b0_1, reg_r0_17, t__i32_1); /* line 1607 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_2); /* line 1608 */
   __ADD(reg_r0_12, reg_r0_12, t__i32_3); /* line 1609 */
   __LDW(reg_r0_42, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 1610 */
} /* line 1610 */
  sim_icache_fetch(1542 + t_thisfile.offset, 6);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 1612 */
   __SLCT(reg_r0_3, reg_b0_4, reg_r0_3, reg_r0_44); /* line 1613 */
   __SHR(reg_r0_17, reg_r0_17, (unsigned int) 8); /* line 1614 */
   __ADD(reg_r0_22, reg_r0_22, reg_r0_12); /* line 1615 */
   __LDW(reg_r0_12, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 180),0,4)); /* line 1616 */
} /* line 1616 */
  sim_icache_fetch(1548 + t_thisfile.offset, 22);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(16);
   __ADD(reg_r0_11, reg_r0_11, reg_r0_52); /* line 1618 */
   __SHRU(reg_r0_42, reg_r0_42, (unsigned int) 8); /* line 1619 */
   __ADD(reg_r0_41, reg_r0_41, reg_r0_34); /* line 1620 */
   __ADD(reg_r0_43, reg_r0_43, reg_r0_56); /* line 1621 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_37); /* line 1622 */
   __MULLU(reg_r0_52, reg_r0_38, reg_r0_49); /* line 1623 */
   __MULHS(reg_r0_38, reg_r0_38, reg_r0_49); /* line 1624 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1625 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_14); /* line 1626 */
   __ADD(reg_r0_35, reg_r0_35, reg_r0_17); /* line 1627 */
   __LDW(reg_r0_37, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 52),0,4)); /* line 1628 */
   __LDW(reg_r0_34, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 16),0,4)); /* line 1629 */
   __LDW(reg_r0_49, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 40),0,4)); /* line 1630 */
   __LDW(reg_r0_45, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 48),0,4)); /* line 1631 */
   __LDW(reg_r0_56, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 56),0,4)); /* line 1632 */
   __LDW(reg_r0_17, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 8),0,4)); /* line 1633 */
} /* line 1633 */
  sim_icache_fetch(1570 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 1635 */
   __AND(reg_r0_42, reg_r0_42, (unsigned int) 255); /* line 1636 */
   __CMPLT(reg_b0_5, reg_r0_41, 0); /* line 1637 */
   __CMPLT(reg_b0_6, reg_r0_43, 0); /* line 1638 */
   __CMPLT(reg_b0_3, reg_r0_8, 0); /* line 1639 */
   __ADD(reg_r0_14, reg_r0_8, (unsigned int) 255); /* line 1640 */
   __CMPLT(reg_b0_1, reg_r0_5, 0); /* line 1641 */
   __ADD(reg_r0_44, reg_r0_5, (unsigned int) 255); /* line 1642 */
} /* line 1642 */
  sim_icache_fetch(1578 + t_thisfile.offset, 10);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_0 = reg_r0_8 ;
  t__i32_1 = reg_r0_5 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(10);
   __ADD(reg_r0_5, reg_r0_11, (unsigned int) 255); /* line 1644 */
   __ADD(reg_r0_8, reg_r0_41, (unsigned int) 255); /* line 1645 */
   __SLCT(reg_r0_14, reg_b0_3, reg_r0_14, t__i32_0); /* line 1646 */
   __ADD(reg_r0_52, reg_r0_52, reg_r0_38); /* line 1647 */
   __MULLU(reg_r0_38, reg_r0_49, reg_r0_50); /* line 1648 */
   __MULHS(reg_r0_49, reg_r0_49, reg_r0_50); /* line 1649 */
   __MULLU(reg_r0_45, reg_r0_45, reg_r0_51); /* line 1650 */
   __SLCT(reg_r0_44, reg_b0_1, reg_r0_44, t__i32_1); /* line 1651 */
   __LDW(reg_r0_51, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 1652 */
   __LDW(reg_r0_50, mem_trace_ld((reg_r0_1 + (unsigned int) 72),0,4)); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(1588 + t_thisfile.offset, 15);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_48 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __SLCT(reg_r0_5, reg_b0_4, reg_r0_5, reg_r0_11); /* line 1655 */
   __MULLU(reg_r0_11, reg_r0_20, reg_r0_42); /* line 1656 */
   __MULHS(reg_r0_20, reg_r0_20, reg_r0_42); /* line 1657 */
   __MULLU(reg_r0_42, reg_r0_17, reg_r0_46); /* line 1658 */
   __MULHS(reg_r0_17, reg_r0_17, reg_r0_46); /* line 1659 */
   __SLCT(reg_r0_8, reg_b0_5, reg_r0_8, reg_r0_41); /* line 1660 */
   __MULLU(reg_r0_46, reg_r0_34, reg_r0_47); /* line 1661 */
   __MULHS(reg_r0_34, reg_r0_34, reg_r0_47); /* line 1662 */
   __ADD(reg_r0_41, reg_r0_43, (unsigned int) 255); /* line 1663 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1664 */
   __CMPLT(reg_b0_1, reg_r0_52, 0); /* line 1665 */
   __ADD(reg_r0_48, reg_r0_52, (unsigned int) 255); /* line 1666 */
   __MULLU(reg_r0_47, reg_r0_37, t__i32_0); /* line 1667 */
   __MULHS(reg_r0_37, reg_r0_37, t__i32_0); /* line 1668 */
   __SHR(reg_r0_44, reg_r0_44, (unsigned int) 8); /* line 1669 */
} /* line 1669 */
  sim_icache_fetch(1603 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_31 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1671 */
   __SHRU(reg_r0_51, reg_r0_51, (unsigned int) 8); /* line 1672 */
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1673 */
   __SLCT(reg_r0_41, reg_b0_6, reg_r0_41, reg_r0_43); /* line 1674 */
   __MULLU(reg_r0_31, reg_r0_50, reg_r0_27); /* line 1675 */
   __MULHS(reg_r0_50, reg_r0_50, reg_r0_27); /* line 1676 */
   __SLCT(reg_r0_48, reg_b0_1, reg_r0_48, reg_r0_52); /* line 1677 */
   __ADD(reg_r0_38, reg_r0_38, reg_r0_49); /* line 1678 */
   __ADD(reg_r0_45, reg_r0_45, t__i32_0); /* line 1679 */
   __ADD(reg_r0_3, reg_r0_3, reg_r0_44); /* line 1680 */
   __LDW(reg_r0_52, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 80),0,4)); /* line 1681 */
   __LDW(reg_r0_49, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 44),0,4)); /* line 1682 */
   __LDW(reg_r0_44, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 32),0,4)); /* line 1683 */
   __LDW(reg_r0_43, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 164),0,4)); /* line 1684 */
   __LDW(reg_r0_27, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 192),0,4)); /* line 1685 */
} /* line 1685 */
  sim_icache_fetch(1623 + t_thisfile.offset, 22);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __ADD(reg_r0_11, reg_r0_11, reg_r0_20); /* line 1687 */
   __AND(reg_r0_51, reg_r0_51, (unsigned int) 255); /* line 1688 */
   __ADD(reg_r0_42, reg_r0_42, reg_r0_17); /* line 1689 */
   __ADD(reg_r0_46, reg_r0_46, reg_r0_34); /* line 1690 */
   __SHR(reg_r0_41, reg_r0_41, (unsigned int) 8); /* line 1691 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_14); /* line 1692 */
   __SHR(reg_r0_48, reg_r0_48, (unsigned int) 8); /* line 1693 */
   __CMPLT(reg_b0_1, reg_r0_38, 0); /* line 1694 */
   __ADD(reg_r0_3, reg_r0_38, (unsigned int) 255); /* line 1695 */
   __CMPLT(reg_b0_3, reg_r0_45, 0); /* line 1696 */
   __ADD(reg_r0_14, reg_r0_45, (unsigned int) 255); /* line 1697 */
   __ADD(reg_r0_47, reg_r0_47, reg_r0_37); /* line 1698 */
   __MULLU(reg_r0_37, reg_r0_56, reg_r0_26); /* line 1699 */
   __MULHS(reg_r0_56, reg_r0_56, reg_r0_26); /* line 1700 */
   __ADD(reg_r0_34, reg_r0_6, (unsigned int) 255); /* line 1701 */
   __ADD(reg_r0_35, reg_r0_35, t__i32_0); /* line 1702 */
   __LDW(reg_r0_17, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 64),0,4)); /* line 1703 */
   __LDW(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 68),0,4)); /* line 1704 */
   __LDW(reg_r0_26, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 60),0,4)); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(1645 + t_thisfile.offset, 25);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  unsigned int t__i32_3;
  t__i32_2 = reg_r0_45 ;
  t__i32_1 = reg_r0_38 ;
  t__i32_3 = reg_r0_35 ;
  t__i32_0 = reg_r0_8 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(22);
   __CMPLT(reg_b0_4, reg_r0_11, 0); /* line 1707 */
   __ADD(reg_r0_8, reg_r0_11, (unsigned int) 255); /* line 1708 */
   __CMPLT(reg_b0_5, reg_r0_42, 0); /* line 1709 */
   __ADD(reg_r0_35, reg_r0_42, (unsigned int) 255); /* line 1710 */
   __CMPLT(reg_b0_6, reg_r0_46, 0); /* line 1711 */
   __ADD(reg_r0_5, reg_r0_5, t__i32_0); /* line 1712 */
   __ADD(reg_r0_31, reg_r0_31, reg_r0_50); /* line 1713 */
   __MULLU(reg_r0_38, reg_r0_44, reg_r0_51); /* line 1714 */
   __MULHS(reg_r0_44, reg_r0_44, reg_r0_51); /* line 1715 */
   __SLCT(reg_r0_3, reg_b0_1, reg_r0_3, t__i32_1); /* line 1716 */
   __MULLU(reg_r0_45, reg_r0_49, reg_r0_19); /* line 1717 */
   __MULHS(reg_r0_49, reg_r0_49, reg_r0_19); /* line 1718 */
   __SLCT(reg_r0_14, reg_b0_3, reg_r0_14, t__i32_2); /* line 1719 */
   __CMPLT(reg_b0_7, reg_r0_47, 0); /* line 1720 */
   __ADD(reg_r0_50, reg_r0_18, (unsigned int) 255); /* line 1721 */
   __SLCT(reg_r0_34, reg_b0_0, reg_r0_34, reg_r0_6); /* line 1722 */
   __MULLU(reg_r0_19, reg_r0_52, reg_r0_53); /* line 1723 */
   __MULHS(reg_r0_52, reg_r0_52, reg_r0_53); /* line 1724 */
   __ADD(reg_r0_22, reg_r0_22, t__i32_3); /* line 1725 */
   __LDW(reg_r0_6, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 116),0,4)); /* line 1726 */
   __LDW(reg_r0_51, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 108),0,4)); /* line 1727 */
   __LDW(reg_r0_53, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 148),0,4)); /* line 1728 */
} /* line 1728 */
  sim_icache_fetch(1670 + t_thisfile.offset, 17);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(15);
   __SLCT(reg_r0_8, reg_b0_4, reg_r0_8, reg_r0_11); /* line 1730 */
   __SLCT(reg_r0_35, reg_b0_5, reg_r0_35, reg_r0_42); /* line 1731 */
   __ADD(reg_r0_11, reg_r0_46, (unsigned int) 255); /* line 1732 */
   __CMPLT(reg_b0_0, reg_r0_31, 0); /* line 1733 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1734 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1735 */
   __ADD(reg_r0_42, reg_r0_47, (unsigned int) 255); /* line 1736 */
   __ADD(reg_r0_37, reg_r0_37, reg_r0_56); /* line 1737 */
   __MULLU(reg_r0_56, reg_r0_26, reg_r0_58); /* line 1738 */
   __MULHS(reg_r0_26, reg_r0_26, reg_r0_58); /* line 1739 */
   __SLCT(reg_r0_50, reg_b0_2, reg_r0_50, reg_r0_18); /* line 1740 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 1741 */
   __MAX(reg_r0_22, reg_r0_22, 0); /* line 1742 */
   __LDW(reg_r0_58, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 96),0,4)); /* line 1743 */
   __LDW(reg_r0_18, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 92),0,4)); /* line 1744 */
} /* line 1744 */
  sim_icache_fetch(1687 + t_thisfile.offset, 27);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(23);
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1746 */
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 1747 */
   __SLCT(reg_r0_11, reg_b0_6, reg_r0_11, reg_r0_46); /* line 1748 */
   __ADD(reg_r0_3, reg_r0_31, (unsigned int) 255); /* line 1749 */
   __ADD(reg_r0_38, reg_r0_38, reg_r0_44); /* line 1750 */
   __ADD(reg_r0_45, reg_r0_45, reg_r0_49); /* line 1751 */
   __SLCT(reg_r0_42, reg_b0_7, reg_r0_42, reg_r0_47); /* line 1752 */
   __ADD(reg_r0_48, reg_r0_48, t__i32_0); /* line 1753 */
   __CMPLT(reg_b0_1, reg_r0_37, 0); /* line 1754 */
   __ADD(reg_r0_47, reg_r0_37, (unsigned int) 255); /* line 1755 */
   __MULLU(reg_r0_44, reg_r0_17, reg_r0_54); /* line 1756 */
   __MULHS(reg_r0_17, reg_r0_17, reg_r0_54); /* line 1757 */
   __MULLU(reg_r0_46, reg_r0_20, reg_r0_55); /* line 1758 */
   __MULHS(reg_r0_20, reg_r0_20, reg_r0_55); /* line 1759 */
   __SHR(reg_r0_50, reg_r0_50, (unsigned int) 8); /* line 1760 */
   __ADD(reg_r0_19, reg_r0_19, reg_r0_52); /* line 1761 */
   __MULLU(reg_r0_49, reg_r0_51, reg_r0_59); /* line 1762 */
   __MULHS(reg_r0_51, reg_r0_51, reg_r0_59); /* line 1763 */
   __MIN(reg_r0_22, reg_r0_22, (unsigned int) 255); /* line 1764 */
   __LDW(reg_r0_59, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 84),0,4)); /* line 1765 */
   __LDW(reg_r0_54, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 104),0,4)); /* line 1766 */
   __LDW(reg_r0_52, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 128),0,4)); /* line 1767 */
   __LDW(reg_r0_55, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 100),0,4)); /* line 1768 */
} /* line 1768 */
  sim_icache_fetch(1714 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_23 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(19);
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1770 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_41); /* line 1771 */
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_3, reg_r0_31); /* line 1772 */
   __CMPLT(reg_b0_0, reg_r0_38, 0); /* line 1773 */
   __ADD(reg_r0_23, reg_r0_38, (unsigned int) 255); /* line 1774 */
   __CMPLT(reg_b0_2, reg_r0_45, 0); /* line 1775 */
   __ADD(reg_r0_31, reg_r0_45, (unsigned int) 255); /* line 1776 */
   __SHR(reg_r0_42, reg_r0_42, (unsigned int) 8); /* line 1777 */
   __SLCT(reg_r0_47, reg_b0_1, reg_r0_47, reg_r0_37); /* line 1778 */
   __ADD(reg_r0_56, reg_r0_56, reg_r0_26); /* line 1779 */
   __CMPLT(reg_b0_3, reg_r0_19, 0); /* line 1780 */
   __ADD(reg_r0_41, reg_r0_19, (unsigned int) 255); /* line 1781 */
   __MULLU(reg_r0_37, reg_r0_18, reg_r0_60); /* line 1782 */
   __MULHS(reg_r0_18, reg_r0_18, reg_r0_60); /* line 1783 */
   __MULLU(reg_r0_60, reg_r0_58, reg_r0_62); /* line 1784 */
   __MULHS(reg_r0_58, reg_r0_58, reg_r0_62); /* line 1785 */
   __OR(reg_r0_22, reg_r0_22, t__i32_0); /* line 1786 */
   __LDW(reg_r0_26, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 1787 */
   __LDW(reg_r0_62, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 88),0,4)); /* line 1788 */
} /* line 1788 */
  sim_icache_fetch(1734 + t_thisfile.offset, 32);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_7 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(27);
   __ADD(reg_r0_35, reg_r0_35, reg_r0_11); /* line 1790 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1791 */
   __SLCT(reg_r0_23, reg_b0_0, reg_r0_23, reg_r0_38); /* line 1792 */
   __SLCT(reg_r0_31, reg_b0_2, reg_r0_31, reg_r0_45); /* line 1793 */
   __SHR(reg_r0_47, reg_r0_47, (unsigned int) 8); /* line 1794 */
   __CMPLT(reg_b0_0, reg_r0_56, 0); /* line 1795 */
   __ADD(reg_r0_11, reg_r0_56, (unsigned int) 255); /* line 1796 */
   __ADD(reg_r0_44, reg_r0_44, reg_r0_17); /* line 1797 */
   __ADD(reg_r0_46, reg_r0_46, reg_r0_20); /* line 1798 */
   __SLCT(reg_r0_41, reg_b0_3, reg_r0_41, reg_r0_19); /* line 1799 */
   __MULLU(reg_r0_7, reg_r0_59, reg_r0_10); /* line 1800 */
   __MULHS(reg_r0_59, reg_r0_59, reg_r0_10); /* line 1801 */
   __MULLU(reg_r0_17, reg_r0_54, t__i32_0); /* line 1802 */
   __MULHS(reg_r0_54, reg_r0_54, t__i32_0); /* line 1803 */
   __ADD(reg_r0_49, reg_r0_49, reg_r0_51); /* line 1804 */
   __MULLU(reg_r0_51, reg_r0_21, reg_r0_36); /* line 1805 */
   __MULHS(reg_r0_21, reg_r0_21, reg_r0_36); /* line 1806 */
   __MULLU(reg_r0_36, reg_r0_6, reg_r0_57); /* line 1807 */
   __MULHS(reg_r0_6, reg_r0_6, reg_r0_57); /* line 1808 */
   __MULLU(reg_r0_57, reg_r0_52, reg_r0_40); /* line 1809 */
   __MULHS(reg_r0_52, reg_r0_52, reg_r0_40); /* line 1810 */
   __MULLU(reg_r0_40, reg_r0_43, reg_r0_4); /* line 1811 */
   __LDW(reg_r0_38, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 120),0,4)); /* line 1812 */
   __LDW(reg_r0_20, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 136),0,4)); /* line 1813 */
   __LDW(reg_r0_45, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 124),0,4)); /* line 1814 */
   __LDW(reg_r0_19, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 132),0,4)); /* line 1815 */
   __LDW(reg_r0_10, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 188),0,4)); /* line 1816 */
} /* line 1816 */
  sim_icache_fetch(1766 + t_thisfile.offset, 28);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_18 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(25);
   __SHRU(reg_r0_26, reg_r0_26, (unsigned int) 8); /* line 1818 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_35); /* line 1819 */
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 8); /* line 1820 */
   __SHR(reg_r0_31, reg_r0_31, (unsigned int) 8); /* line 1821 */
   __ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 1822 */
   __SLCT(reg_r0_11, reg_b0_0, reg_r0_11, reg_r0_56); /* line 1823 */
   __CMPLT(reg_b0_1, reg_r0_44, 0); /* line 1824 */
   __ADD(reg_r0_14, reg_r0_44, (unsigned int) 255); /* line 1825 */
   __CMPLT(reg_b0_2, reg_r0_46, 0); /* line 1826 */
   __ADD(reg_r0_35, reg_r0_46, (unsigned int) 255); /* line 1827 */
   __SHR(reg_r0_41, reg_r0_41, (unsigned int) 8); /* line 1828 */
   __ADD(reg_r0_47, reg_r0_47, reg_r0_34); /* line 1829 */
   __MULLU(reg_r0_18, reg_r0_62, reg_r0_61); /* line 1830 */
   __MULHS(reg_r0_62, reg_r0_62, reg_r0_61); /* line 1831 */
   __ADD(reg_r0_37, reg_r0_37, t__i32_0); /* line 1832 */
   __ADD(reg_r0_60, reg_r0_60, reg_r0_58); /* line 1833 */
   __CMPLT(reg_b0_0, reg_r0_49, 0); /* line 1834 */
   __ADD(reg_r0_34, reg_r0_49, (unsigned int) 255); /* line 1835 */
   __MULLU(reg_r0_56, reg_r0_53, reg_r0_30); /* line 1836 */
   __MULHS(reg_r0_53, reg_r0_53, reg_r0_30); /* line 1837 */
   __MULHS(reg_r0_43, reg_r0_43, reg_r0_4); /* line 1838 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 80),0,4)); /* line 1839 */
   __LDW(reg_r0_4, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 140),0,4)); /* line 1840 */
   __LDW(reg_r0_30, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 152),0,4)); /* line 1841 */
   __LDW(reg_r0_58, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 160),0,4)); /* line 1842 */
} /* line 1842 */
  sim_icache_fetch(1794 + t_thisfile.offset, 32);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_33 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(29);
   __AND(reg_r0_26, reg_r0_26, (unsigned int) 255); /* line 1844 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_8); /* line 1845 */
   __ADD(reg_r0_23, reg_r0_23, reg_r0_31); /* line 1846 */
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1847 */
   __SLCT(reg_r0_14, reg_b0_1, reg_r0_14, reg_r0_44); /* line 1848 */
   __SLCT(reg_r0_35, reg_b0_2, reg_r0_35, reg_r0_46); /* line 1849 */
   __ADD(reg_r0_7, reg_r0_7, reg_r0_59); /* line 1850 */
   __CMPLT(reg_b0_0, reg_r0_37, 0); /* line 1851 */
   __ADD(reg_r0_8, reg_r0_37, (unsigned int) 255); /* line 1852 */
   __CMPLT(reg_b0_1, reg_r0_60, 0); /* line 1853 */
   __ADD(reg_r0_31, reg_r0_60, (unsigned int) 255); /* line 1854 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_54); /* line 1855 */
   __SLCT(reg_r0_34, t__i32_0, reg_r0_34, reg_r0_49); /* line 1856 */
   __ADD(reg_r0_51, reg_r0_51, reg_r0_21); /* line 1857 */
   __ADD(reg_r0_36, reg_r0_36, reg_r0_6); /* line 1858 */
   __MULLU(reg_r0_33, reg_r0_38, reg_r0_16); /* line 1859 */
   __MULHS(reg_r0_38, reg_r0_38, reg_r0_16); /* line 1860 */
   __MULLU(reg_r0_16, reg_r0_45, reg_r0_2); /* line 1861 */
   __MULHS(reg_r0_45, reg_r0_45, reg_r0_2); /* line 1862 */
   __ADD(reg_r0_57, reg_r0_57, reg_r0_52); /* line 1863 */
   __MULLU(reg_r0_46, reg_r0_19, reg_r0_25); /* line 1864 */
   __MULHS(reg_r0_19, reg_r0_19, reg_r0_25); /* line 1865 */
   __MULLU(reg_r0_44, reg_r0_20, t__i32_1); /* line 1866 */
   __MULHS(reg_r0_20, reg_r0_20, t__i32_1); /* line 1867 */
   __MULLU(reg_r0_59, reg_r0_12, reg_r0_9); /* line 1868 */
   __LDW(reg_r0_52, mem_trace_ld((reg_r0_1 + (unsigned int) 84),0,4)); /* line 1869 */
   __LDW(reg_r0_21, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 144),0,4)); /* line 1870 */
   __LDW(reg_r0_54, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 168),0,4)); /* line 1871 */
   __LDW(reg_r0_49, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 156),0,4)); /* line 1872 */
} /* line 1872 */
  sim_icache_fetch(1826 + t_thisfile.offset, 32);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  unsigned int t__i32_2;
  t__i32_2 = reg_r0_43 ;
  t__i32_0 = reg_r0_37 ;
  t__i32_1 = reg_b0_1 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(31);
   __SHRU(reg_r0_61, reg_r0_61, (unsigned int) 8); /* line 1874 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_42); /* line 1875 */
   __ADD(reg_r0_3, reg_r0_3, reg_r0_23); /* line 1876 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1877 */
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 1878 */
   __ADD(reg_r0_11, reg_r0_11, reg_r0_50); /* line 1879 */
   __CMPLT(reg_b0_1, reg_r0_7, 0); /* line 1880 */
   __ADD(reg_r0_37, reg_r0_7, (unsigned int) 255); /* line 1881 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_62); /* line 1882 */
   __SLCT(reg_r0_8, reg_b0_0, reg_r0_8, t__i32_0); /* line 1883 */
   __SLCT(reg_r0_31, t__i32_1, reg_r0_31, reg_r0_60); /* line 1884 */
   __MULLU(reg_r0_42, reg_r0_55, reg_r0_26); /* line 1885 */
   __MULHS(reg_r0_55, reg_r0_55, reg_r0_26); /* line 1886 */
   __CMPLT(reg_b0_0, reg_r0_17, 0); /* line 1887 */
   __ADD(reg_r0_23, reg_r0_17, (unsigned int) 255); /* line 1888 */
   __SHR(reg_r0_34, reg_r0_34, (unsigned int) 8); /* line 1889 */
   __CMPLT(reg_b0_2, reg_r0_51, 0); /* line 1890 */
   __ADD(reg_r0_50, reg_r0_51, (unsigned int) 255); /* line 1891 */
   __CMPLT(reg_b0_3, reg_r0_36, 0); /* line 1892 */
   __ADD(reg_r0_60, reg_r0_36, (unsigned int) 255); /* line 1893 */
   __CMPLT(reg_b0_4, reg_r0_57, 0); /* line 1894 */
   __ADD(reg_r0_62, reg_r0_57, (unsigned int) 255); /* line 1895 */
   __ADD(reg_r0_56, reg_r0_56, reg_r0_53); /* line 1896 */
   __MULLU(reg_r0_43, reg_r0_30, reg_r0_32); /* line 1897 */
   __MULHS(reg_r0_30, reg_r0_30, reg_r0_32); /* line 1898 */
   __MULLU(reg_r0_32, reg_r0_58, reg_r0_63); /* line 1899 */
   __MULHS(reg_r0_58, reg_r0_58, reg_r0_63); /* line 1900 */
   __ADD(reg_r0_40, reg_r0_40, t__i32_2); /* line 1901 */
   __MULHS(reg_r0_12, reg_r0_12, reg_r0_9); /* line 1902 */
   __MULLU(reg_r0_9, reg_r0_10, reg_r0_13); /* line 1903 */
   __LDW(reg_r0_53, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 176),0,4)); /* line 1904 */
} /* line 1904 */
  sim_icache_fetch(1858 + t_thisfile.offset, 32);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_13 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(31);
   __AND(reg_r0_61, reg_r0_61, (unsigned int) 255); /* line 1906 */
   __SHRU(reg_r0_52, reg_r0_52, (unsigned int) 8); /* line 1907 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_48); /* line 1908 */
   __ADD(reg_r0_14, reg_r0_14, reg_r0_35); /* line 1909 */
   __ADD(reg_r0_47, reg_r0_47, reg_r0_11); /* line 1910 */
   __SLCT(reg_r0_37, reg_b0_1, reg_r0_37, reg_r0_7); /* line 1911 */
   __CMPLT(reg_b0_0, reg_r0_18, 0); /* line 1912 */
   __ADD(reg_r0_7, reg_r0_18, (unsigned int) 255); /* line 1913 */
   __SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1914 */
   __SHR(reg_r0_31, reg_r0_31, (unsigned int) 8); /* line 1915 */
   __SLCT(reg_r0_23, t__i32_0, reg_r0_23, reg_r0_17); /* line 1916 */
   __SLCT(reg_r0_50, reg_b0_2, reg_r0_50, reg_r0_51); /* line 1917 */
   __SLCT(reg_r0_60, reg_b0_3, reg_r0_60, reg_r0_36); /* line 1918 */
   __ADD(reg_r0_33, reg_r0_33, reg_r0_38); /* line 1919 */
   __ADD(reg_r0_16, reg_r0_16, reg_r0_45); /* line 1920 */
   __SLCT(reg_r0_62, reg_b0_4, reg_r0_62, reg_r0_57); /* line 1921 */
   __ADD(reg_r0_46, reg_r0_46, reg_r0_19); /* line 1922 */
   __ADD(reg_r0_44, reg_r0_44, reg_r0_20); /* line 1923 */
   __MULLU(reg_r0_19, reg_r0_21, reg_r0_29); /* line 1924 */
   __MULHS(reg_r0_21, reg_r0_21, reg_r0_29); /* line 1925 */
   __CMPLT(reg_b0_2, reg_r0_56, 0); /* line 1926 */
   __ADD(reg_r0_17, reg_r0_56, (unsigned int) 255); /* line 1927 */
   __MULLU(reg_r0_20, reg_r0_49, reg_r0_28); /* line 1928 */
   __MULHS(reg_r0_49, reg_r0_49, reg_r0_28); /* line 1929 */
   __CMPLT(reg_b0_1, reg_r0_40, 0); /* line 1930 */
   __ADD(reg_r0_11, reg_r0_40, (unsigned int) 255); /* line 1931 */
   __MULLU(reg_r0_13, reg_r0_54, reg_r0_39); /* line 1932 */
   __MULHS(reg_r0_54, reg_r0_54, reg_r0_39); /* line 1933 */
   __MULHS(reg_r0_10, reg_r0_10, t__i32_1); /* line 1934 */
   __LDW(reg_r0_28, mem_trace_ld((reg_r0_1 + (unsigned int) 88),0,4)); /* line 1935 */
   __LDW(reg_r0_29, mem_trace_ld(((unsigned int) filter7x7 + (unsigned int) 172),0,4)); /* line 1936 */
} /* line 1936 */
  sim_icache_fetch(1890 + t_thisfile.offset, 32);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_30 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(32);
   __AND(reg_r0_52, reg_r0_52, (unsigned int) 255); /* line 1938 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_3); /* line 1939 */
   __SHR(reg_r0_37, reg_r0_37, (unsigned int) 8); /* line 1940 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_18); /* line 1941 */
   __ADD(reg_r0_42, reg_r0_42, reg_r0_55); /* line 1942 */
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 8); /* line 1943 */
   __ADD(reg_r0_8, reg_r0_8, reg_r0_31); /* line 1944 */
   __SHR(reg_r0_50, reg_r0_50, (unsigned int) 8); /* line 1945 */
   __SHR(reg_r0_60, reg_r0_60, (unsigned int) 8); /* line 1946 */
   __CMPLT(reg_b0_3, reg_r0_33, 0); /* line 1947 */
   __ADD(reg_r0_18, reg_r0_33, (unsigned int) 255); /* line 1948 */
   __CMPLT(reg_b0_4, reg_r0_16, 0); /* line 1949 */
   __ADD(reg_r0_31, reg_r0_16, (unsigned int) 255); /* line 1950 */
   __SHR(reg_r0_62, reg_r0_62, (unsigned int) 8); /* line 1951 */
   __CMPLT(reg_b0_5, reg_r0_46, 0); /* line 1952 */
   __ADD(reg_r0_35, reg_r0_46, (unsigned int) 255); /* line 1953 */
   __CMPLT(reg_b0_0, reg_r0_44, 0); /* line 1954 */
   __ADD(reg_r0_3, reg_r0_44, (unsigned int) 255); /* line 1955 */
   __MULLU(reg_r0_30, reg_r0_4, reg_r0_61); /* line 1956 */
   __MULHS(reg_r0_4, reg_r0_4, reg_r0_61); /* line 1957 */
   __SLCT(reg_r0_17, reg_b0_2, reg_r0_17, reg_r0_56); /* line 1958 */
   __ADD(reg_r0_43, reg_r0_43, t__i32_0); /* line 1959 */
   __ADD(reg_r0_32, reg_r0_32, reg_r0_58); /* line 1960 */
   __SLCT(reg_r0_11, reg_b0_1, reg_r0_11, reg_r0_40); /* line 1961 */
   __MULLU(reg_r0_36, reg_r0_53, reg_r0_15); /* line 1962 */
   __MULHS(reg_r0_53, reg_r0_53, reg_r0_15); /* line 1963 */
   __ADD(reg_r0_59, reg_r0_59, reg_r0_12); /* line 1964 */
   __LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1965 */
   __LDW(reg_r0_25, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1966 */
   __LDW(reg_r0_26, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1967 */
   __LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1968 */
   __LDW(reg_r0_12, mem_trace_ld((reg_r0_1 + (unsigned int) 92),0,4)); /* line 1969 */
} /* line 1969 */
  sim_icache_fetch(1922 + t_thisfile.offset, 25);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(25);
   __SHRU(reg_r0_28, reg_r0_28, (unsigned int) 8); /* line 1971 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_41); /* line 1972 */
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1973 */
   __CMPLT(reg_b0_1, reg_r0_42, 0); /* line 1974 */
   __ADD(reg_r0_15, reg_r0_42, (unsigned int) 255); /* line 1975 */
   __ADD(reg_r0_37, reg_r0_37, reg_r0_23); /* line 1976 */
   __SLCT(reg_r0_18, reg_b0_3, reg_r0_18, reg_r0_33); /* line 1977 */
   __SLCT(reg_r0_31, reg_b0_4, reg_r0_31, reg_r0_16); /* line 1978 */
   __SLCT(reg_r0_35, reg_b0_5, reg_r0_35, reg_r0_46); /* line 1979 */
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_3, reg_r0_44); /* line 1980 */
   __ADD(reg_r0_60, reg_r0_60, reg_r0_62); /* line 1981 */
   __ADD(reg_r0_19, reg_r0_19, reg_r0_21); /* line 1982 */
   __SHR(reg_r0_17, reg_r0_17, (unsigned int) 8); /* line 1983 */
   __CMPLT(reg_b0_0, reg_r0_43, 0); /* line 1984 */
   __ADD(reg_r0_16, reg_r0_43, (unsigned int) 255); /* line 1985 */
   __ADD(reg_r0_20, reg_r0_20, reg_r0_49); /* line 1986 */
   __CMPLT(reg_b0_2, reg_r0_32, 0); /* line 1987 */
   __ADD(reg_r0_23, reg_r0_32, (unsigned int) 255); /* line 1988 */
   __SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1989 */
   __ADD(reg_r0_13, reg_r0_13, reg_r0_54); /* line 1990 */
   __CMPLT(reg_b0_3, reg_r0_59, 0); /* line 1991 */
   __ADD(reg_r0_33, reg_r0_59, (unsigned int) 255); /* line 1992 */
   __ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 1993 */
   __MULLU(reg_r0_21, reg_r0_27, reg_r0_52); /* line 1994 */
   __MULHS(reg_r0_27, reg_r0_27, reg_r0_52); /* line 1995 */
} /* line 1995 */
  sim_icache_fetch(1947 + t_thisfile.offset, 23);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_b0_3 ;
  t__i32_0 = reg_b0_0 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(23);
   __AND(reg_r0_28, reg_r0_28, (unsigned int) 255); /* line 1997 */
   __SHRU(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1998 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_14); /* line 1999 */
   __SLCT(reg_r0_15, reg_b0_1, reg_r0_15, reg_r0_42); /* line 2000 */
   __SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 2001 */
   __SHR(reg_r0_31, reg_r0_31, (unsigned int) 8); /* line 2002 */
   __SHR(reg_r0_35, reg_r0_35, (unsigned int) 8); /* line 2003 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2004 */
   __ADD(reg_r0_30, reg_r0_30, reg_r0_4); /* line 2005 */
   __CMPLT(reg_b0_0, reg_r0_19, 0); /* line 2006 */
   __ADD(reg_r0_10, reg_r0_19, (unsigned int) 255); /* line 2007 */
   __SLCT(reg_r0_16, t__i32_0, reg_r0_16, reg_r0_43); /* line 2008 */
   __CMPLT(reg_b0_1, reg_r0_20, 0); /* line 2009 */
   __ADD(reg_r0_14, reg_r0_20, (unsigned int) 255); /* line 2010 */
   __SLCT(reg_r0_23, reg_b0_2, reg_r0_23, reg_r0_32); /* line 2011 */
   __CMPLT(reg_b0_3, reg_r0_13, 0); /* line 2012 */
   __ADD(reg_r0_38, reg_r0_13, (unsigned int) 255); /* line 2013 */
   __ADD(reg_r0_36, reg_r0_36, reg_r0_53); /* line 2014 */
   __SLCT(reg_r0_33, t__i32_1, reg_r0_33, reg_r0_59); /* line 2015 */
   __CMPLT(reg_b0_2, reg_r0_9, 0); /* line 2016 */
   __ADD(reg_r0_32, reg_r0_9, (unsigned int) 255); /* line 2017 */
   __SH2ADD(reg_r0_39, reg_r0_25, reg_r0_26); /* line 2018 */
   __ADD(reg_r0_25, reg_r0_25, (unsigned int) 1); /* line 2019 */
} /* line 2019 */
  sim_icache_fetch(1970 + t_thisfile.offset, 20);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_9 ;
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(20);
   __AND(reg_r0_12, reg_r0_12, (unsigned int) 255); /* line 2021 */
   __ADD(reg_r0_5, reg_r0_5, reg_r0_47); /* line 2022 */
   __SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2023 */
   __ADD(reg_r0_50, reg_r0_50, reg_r0_35); /* line 2024 */
   __ADD(reg_r0_18, reg_r0_18, reg_r0_31); /* line 2025 */
   __CMPLT(reg_b0_4, reg_r0_30, 0); /* line 2026 */
   __ADD(reg_r0_31, reg_r0_30, (unsigned int) 255); /* line 2027 */
   __SLCT(reg_r0_10, reg_b0_0, reg_r0_10, reg_r0_19); /* line 2028 */
   __SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 2029 */
   __SLCT(reg_r0_14, reg_b0_1, reg_r0_14, reg_r0_20); /* line 2030 */
   __SHR(reg_r0_23, reg_r0_23, (unsigned int) 8); /* line 2031 */
   __SLCT(reg_r0_38, reg_b0_3, reg_r0_38, reg_r0_13); /* line 2032 */
   __MULLU(reg_r0_9, reg_r0_29, reg_r0_28); /* line 2033 */
   __MULHS(reg_r0_29, reg_r0_29, reg_r0_28); /* line 2034 */
   __CMPLT(reg_b0_0, reg_r0_36, 0); /* line 2035 */
   __ADD(reg_r0_19, reg_r0_36, (unsigned int) 255); /* line 2036 */
   __SHR(reg_r0_33, reg_r0_33, (unsigned int) 8); /* line 2037 */
   __SLCT(reg_r0_32, reg_b0_2, reg_r0_32, t__i32_0); /* line 2038 */
   __ADD(reg_r0_21, reg_r0_21, reg_r0_27); /* line 2039 */
   __PFT(mem_trace_pf((reg_r0_39 + (unsigned int) 32),0,4)); /* line 2040 */
} /* line 2040 */
  sim_icache_fetch(1990 + t_thisfile.offset, 14);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(14);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_34); /* line 2042 */
   __ADD(reg_r0_7, reg_r0_7, reg_r0_15); /* line 2043 */
   __ADD(reg_r0_50, reg_r0_50, reg_r0_60); /* line 2044 */
   __SLCT(reg_r0_31, reg_b0_4, reg_r0_31, reg_r0_30); /* line 2045 */
   __SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2046 */
   __SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 2047 */
   __ADD(reg_r0_17, reg_r0_17, reg_r0_16); /* line 2048 */
   __SHR(reg_r0_38, reg_r0_38, (unsigned int) 8); /* line 2049 */
   __SLCT(reg_r0_19, reg_b0_0, reg_r0_19, reg_r0_36); /* line 2050 */
   __MULLU(reg_r0_15, reg_r0_24, reg_r0_12); /* line 2051 */
   __MULHS(reg_r0_24, reg_r0_24, reg_r0_12); /* line 2052 */
   __SHR(reg_r0_32, reg_r0_32, (unsigned int) 8); /* line 2053 */
   __CMPLT(reg_b0_1, reg_r0_21, 0); /* line 2054 */
   __ADD(reg_r0_13, reg_r0_21, (unsigned int) 255); /* line 2055 */
} /* line 2055 */
  sim_icache_fetch(2004 + t_thisfile.offset, 8);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(8);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_8); /* line 2057 */
   __ADD(reg_r0_37, reg_r0_37, reg_r0_7); /* line 2058 */
   __SHR(reg_r0_31, reg_r0_31, (unsigned int) 8); /* line 2059 */
   __ADD(reg_r0_10, reg_r0_10, reg_r0_14); /* line 2060 */
   __ADD(reg_r0_9, reg_r0_9, reg_r0_29); /* line 2061 */
   __SHR(reg_r0_19, reg_r0_19, (unsigned int) 8); /* line 2062 */
   __SLCT(reg_r0_13, reg_b0_1, reg_r0_13, reg_r0_21); /* line 2063 */
   __ADD(reg_r0_38, reg_r0_38, reg_r0_32); /* line 2064 */
} /* line 2064 */
  sim_icache_fetch(2012 + t_thisfile.offset, 7);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(7);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_37); /* line 2066 */
   __ADD(reg_r0_31, reg_r0_31, reg_r0_23); /* line 2067 */
   __CMPLT(reg_b0_0, reg_r0_9, 0); /* line 2068 */
   __ADD(reg_r0_7, reg_r0_9, (unsigned int) 255); /* line 2069 */
   __ADD(reg_r0_15, reg_r0_15, reg_r0_24); /* line 2070 */
   __SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2071 */
   __ADD(reg_r0_19, reg_r0_19, reg_r0_33); /* line 2072 */
} /* line 2072 */
  sim_icache_fetch(2019 + t_thisfile.offset, 5);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(5);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_3); /* line 2074 */
   __ADD(reg_r0_31, reg_r0_31, reg_r0_10); /* line 2075 */
   __SLCT(reg_r0_7, reg_b0_0, reg_r0_7, reg_r0_9); /* line 2076 */
   __CMPLT(reg_b0_0, reg_r0_15, 0); /* line 2077 */
   __ADD(reg_r0_3, reg_r0_15, (unsigned int) 255); /* line 2078 */
} /* line 2078 */
  sim_icache_fetch(2024 + t_thisfile.offset, 3);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_18); /* line 2080 */
   __SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2081 */
   __SLCT(reg_r0_3, reg_b0_0, reg_r0_3, reg_r0_15); /* line 2082 */
} /* line 2082 */
  sim_icache_fetch(2027 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_50); /* line 2084 */
   __SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2085 */
} /* line 2085 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2087 */
   __ADD(reg_r0_7, reg_r0_7, reg_r0_3); /* line 2088 */
} /* line 2088 */
  sim_icache_fetch(2031 + t_thisfile.offset, 2);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_17); /* line 2090 */
   __ADD(reg_r0_38, reg_r0_38, reg_r0_7); /* line 2091 */
} /* line 2091 */
  sim_icache_fetch(2033 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_31); /* line 2093 */
} /* line 2093 */
  sim_icache_fetch(2034 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_13); /* line 2095 */
} /* line 2095 */
  sim_icache_fetch(2035 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_19); /* line 2097 */
} /* line 2097 */
  sim_icache_fetch(2036 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __ADD(reg_r0_5, reg_r0_5, reg_r0_38); /* line 2099 */
} /* line 2099 */
  sim_icache_fetch(2037 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MAX(reg_r0_5, reg_r0_5, 0); /* line 2101 */
} /* line 2101 */
  sim_icache_fetch(2038 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __MIN(reg_r0_5, reg_r0_5, (unsigned int) 255); /* line 2103 */
} /* line 2103 */
  sim_icache_fetch(2039 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __SHL(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2105 */
} /* line 2105 */
  sim_icache_fetch(2040 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __OR(reg_r0_22, reg_r0_22, reg_r0_5); /* line 2107 */
} /* line 2107 */
  sim_icache_fetch(2041 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __STW(mem_trace_st(reg_r0_39,0,4), reg_r0_22); /* line 2109 */
} /* line 2109 */
  sim_icache_fetch(2042 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 2111 */
} /* line 2111 */
  sim_icache_fetch(2043 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __GOTO(l_L6X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L6X3;
} /* line 2113 */
l_L7X3: ;/* line 2116 */
__LABEL(l_L7X3);
  sim_icache_fetch(2044 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(3);
   __ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 2117 */
   __ADD(reg_r0_6, reg_r0_6, (unsigned int) 64); /* line 2118 */
   __ADD(reg_r0_26, reg_r0_26, (unsigned int) 256); /* line 2119 */
} /* line 2119 */
  sim_icache_fetch(2048 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(4);
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_6); /* line 2121 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_26); /* line 2122 */
   __STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_2); /* line 2123 */
   __GOTO(l_L4X3);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   goto l_L4X3;
} /* line 2124 */
l_L5X3: ;/* line 2127 */
__LABEL(l_L5X3);
		 /* line 2127 */
  sim_icache_fetch(2052 + t_thisfile.offset, 4);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(2);
   __MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 2130 */
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
} /* line 2130 */
l_lr_14: ;/* line 2130 */
__LABEL(l_lr_14);
  sim_icache_fetch(2056 + t_thisfile.offset, 10);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(9);
   __MOV(reg_r0_3, 0); /* line 2132 */
   __LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 120),0,4)); /* line 2133 */
   __LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 116),0,4)); /* line 2134 */
   __LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 112),0,4)); /* line 2135 */
   __LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 108),0,4)); /* line 2136 */
   __LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 104),0,4)); /* line 2137 */
   __LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 100),0,4)); /* line 2138 */
   __LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 2139 */
   __LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2140 */
   __INC_NOP_CNT((unsigned int) 1);
   __XNOP((unsigned int) 1); /* line 2141 */
   __ADD_CYCLES(1);
} /* line 2141 */
  sim_icache_fetch(2066 + t_thisfile.offset, 1);
{
   __ADD_CYCLES(1);
   __INC_BUNDLE_CNT(1);
   __RETURN(__vex_main);   __INC_BTU_CNT();
   __INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 128; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2144 */
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


static sim_fileinfo_t t_thisfile = {"convolution_7x7.s", 2080, 0, 0, 0, 2};

