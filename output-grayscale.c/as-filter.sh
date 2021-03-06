#!/bin/sh

## $Id: as-filter.sh,v 1.1 2009/12/17 12:52:24 frb Exp $

arg0=$0
bindir=`expr ${arg0-.}'/' : '\(/\)[^/]*/$' \
         \|  ${arg0-.}'/' : '\(.*[^/]\)//*[^/][^/]*//*$' \
         \|  .`
curdir=`pwd`
case $bindir in
/*)	tmpdir=$bindir ;;
.)	tmpdir=$curdir ;;
*)	tmpdir=$curdir/$bindir ;;
esac


################################################################################
## This needs to point to the vex release (see Makefile)
RELEASE_DIR=@VEX@


tmp_as_objfile=/tmp/csim$$.o
tmp_cs_files=/tmp/csim$$

trap "rm -f /tmp/csim$$*; exit 4" 1 2 3 4 6 15

usage_and_die()
{
    echo "usage: as [flags] name"
    echo "Flags:"
    echo " -o name                      output to <name>"
    echo " -prob_dir name               probability dir is <name>"
    echo " -prob_gen                    generate probability info"
    echo " -s name                      srcfile name is <name>"
    echo " -s_align_1                   pass +u1 (byte align) to cs compilation"
    echo " -s_atexit proc               call procedure "proc" at simulation exit"
    echo " -s_chk                       invoke the static checker (**UNSUPPORTED**)"
    echo " -s_d                         show invocation"
    echo " -s_dn                        show invocation and do nothing"
    echo " -s_g                         pass debug flag to cs compilation"
    echo " -s_G                         pass gprof flag to cs compilation"
    echo " -s_O2                        pass optimize flag to cs compilation"
    echo " -s_l                         use asm directives for line numbers"
    echo " -s_t                         set dcache, bundle count, and icache tracing on (default)"
    echo " -s_tb                        set bundle count on"
    echo " -s_td                        set dcache tracing on"
    echo " -s_ti                        set icache tracing on"
    echo " -s_tn                        set bundle count, dcache, and icache tracing off"
    echo " -s_rcils                     runtime configurable icache line size"
    echo " -s_little[_endian]           generate little endian code"

    echo " -C -q -u -w -LIL             ignored"
    exit 4
}

echo_or_exec()
{
    if [ $debug -eq 1 ]; then
        case $1 in
        cd|mv|rm|cc)
            echo $*
            echo
            ;;
        *)
            j=1
            for parm in $*
            do
                if   [ $j -eq 1  ]; then echo $parm \\
                elif [ $j -lt $# ]; then echo "   " $parm \\
                else                     echo "   " $parm
                fi
                j=`expr $j + 1`
            done
            echo
            ;;
        esac
    fi

    if [ $noexec -eq 0 ]; then
        $*
    fi
}

uname=`uname`
case $uname in
    Linux*)
	cc_exe="gcc"
        cc_options="-m32 -w -ffreestanding"
	cc_opt_flag="-O0"
	cc_fix_flag=""
	cc_align1_flag="-mno-strict-align"
	cc_gprof_flag="-pg"
	cc_O2_flag="-O2"
        cs_options="-little_endian" 
	;;
    *)
        echo "Error: unsupported host ($uname)"
	exit 5 
	;;
esac

#to generate the profiling information
cs_options="$cs_options -atexit __dyn_prof_generate "

ascs="echo_or_exec ${RELEASE_DIR}/lib/ascs"
s2cs="echo_or_exec ${RELEASE_DIR}/lib/s2cs"

trace_ops=1
trace_dmem=1
trace_imem=1

cc="echo_or_exec $cc_exe"
cd="echo_or_exec cd"
mv="echo_or_exec mv"
rm="echo_or_exec rm"

debug=0
noexec=0
stcheck=0
cs_debug=0
input_file=""

while [ $# -gt 0 ]
do
        case $1 in
        -o) 	if [ $# -lt 2 ]; then usage_and_die; fi
                as_objfile=$2
                shift; shift ;;
        -prob_gen*)
                cs_options="$cs_options -atexit sim_dump_ifprob_data"
                shift ;;
        -prob_dir)
                # shift next arg and ignore
                shift; shift ;;
        -s)     if [ $# -lt 2 ]; then usage_and_die; fi
                as_srcfile=$2
                shift; shift ;;
        -s_align_1)
                cc_options="$cc_options $cc_align1_flag"
                shift ;;
        -s_atexit)
		if [ $# -lt 2]; then usage_and_die; fi
                cs_options="$cs_options -atexit $2"
                shift; shift ;;
        -s_chk) stcheck=1
		usage_and_die;
                shift ;;
        -s_d)   debug=1
                shift ;;
        -s_dn)  debug=1
                noexec=1
                shift ;;
        -s_g)   cs_debug=1
		cc_opt_flag="-g"
                shift ;;
        -s_G)   cc_options="$cc_options $cc_gprof_flag"
                cs_options="$cs_options -gprof"
		cc_fix_flag=""
                shift ;;
        -s_O2)  cs_debug=0
		cc_opt_flag="$cc_O2_flag"
                shift ;;
        -s_tb)
	        trace_ops=1
                cs_options="$cs_options -show_bundle_counts"
                shift ;;
        -s_t)   trace_ops=1
	        trace_dmem=1
		trace_imem=1
                shift ;;
        -s_td)  trace_ops=1
		trace_dmem=1
                shift ;;
	-s_ti)  trace_ops=1
		trace_imem=1
	        shift ;;
        -s_tn)  trace_ops=0
	        trace_imem=0
	        trace_dmem=0
                shift ;;
	-s_little*[_endian]) cs_options="$cs_options -little_endian"
		shift ;;
        -C)     shift ;; #Ignore
        -q)     shift ;; #Ignore
        -u)     shift ;; #Ignore
        -w)     shift ;; #Ignore
        -LIL)   shift ;; #Ignore
        -*)     usage_and_die
                exit 4
                shift ;;
        *)      if [ "$input_file" != "" ]; then usage_and_die; fi
                input_file=$1
                shift ;;
        esac
done

if [ $trace_ops -eq 1 ]; then cs_options="$cs_options -show_bundle_counts"; fi
if [ $trace_dmem -eq 1 ]; then cs_options="$cs_options -trace_memory"; fi
if [ $trace_imem -eq 1 ]; then cs_options="$cs_options -trace_icache -runtime_icache_cfg"; fi

if [ "$input_file" = "" ]; then usage_and_die; fi

if [ $cs_debug -eq 0 ]; then
    cs_options="$cs_options -nolineno"
else tmp_cs_files=`basename ${as_srcfile:-$input_file} .s`.cs
fi

if $s2cs $input_file $tmp_cs_files.c $cs_options; then
    $rm -f ${as_objfile:-$tmp_as_objfile}
else
    echo CS-S2CS FAILED ${as_srcfile:-$input_file}
    $rm -f ${as_objfile:-$tmp_as_objfile}
    if [ $cs_debug -eq 0 ]; then $rm -f $tmp_cs_files.c; fi
    exit 4
fi

################################################################################
## Insert filter here (from $tmp_cs_files.c to $tmp_cs_files.filter.cs.c)

 ./add_profiling  < $tmp_cs_files.c > $tmp_cs_files.filter.cs.c

################################################################################

cc_options="$cc_options $cc_opt_flag $cc_fix_flag"

if [ "$CS_CCOPTS" ]; then
    cc_options="CS_CCOPTS $cc_options"
fi

if $cc $cc_options -o $tmp_cs_files.o -c $tmp_cs_files.filter.cs.c; then
    if [ $cs_debug -eq 0 ]; then $rm -f $tmp_cs_files.filter.cs.c; fi
else
    echo CS-CC FAILED ${as_srcfile:-$input_file}
    if [ $cs_debug -eq 0 ]; then $rm -f $tmp_cs_files.filter.cs.c; fi
    $rm -f $tmp_cs_files.o
    exit 4
fi

$mv -f $tmp_cs_files.o ${as_objfile:-`basename $input_file .s`.o}

exit 0

