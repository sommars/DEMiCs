#ifndef __GROBAL_H
#define __GROBAL_H

#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <sys/times.h>
#include <unistd.h>
#include <cassert>

#ifndef CLK_TCK
#define  CLK_TCK  sysconf(_SC_CLK_TCK)
#endif

using namespace std;

#define ITER_BLAND 25
#define ITER 1000

#define EXCESS 5
#define STRLENGTH 128

#define PLUSZERO 1.0E-8
#define MINUSZERO -1.0E-8
#define BIGDOUBLE 1.0E+16
#define SMALLDOUBLE -1.0E+16
#define BIGINT 1000000000

#define FREE 2
#define NONNEGATIVE 3
#define POSITIVE 25
#define NEGATIVE 26

#define POSTHETA 6
#define NEGTHETA 7

#define OPT 4 // this probably means optimal solution
#define UNBOUNDED  8 // optimal solution is unbounded

#define CONTINUE 9
#define STOP 14
#define PIVOT_IN 28

#define ICHECK 20
#define MCHECK 21

#define TRIANGLE 28
#define SQUARE 29

#define SLIDE 16
#define DOWN 17

#define NODE 22
#define FN 23
#define FNN 24

#define ON 30
#define OFF 31

#define UNB_TAR 32
#define UNB_COR 33

#define ERROR_ITER 27

//------------------------------------------------------------------------------
///// DEBUG /////////////////////////////
#define DBG_INFO 0

#define DBG_NODE 0
#define DBG_FEA 0
#define DBG_SUC 0
#define DBG_TMP 0
#define DEBUG 0

// For relation table
#define DBG_REL_TABLE 0

// For initial one_point_test
#define DBG_INI_CUR_INFO 0

// For one_point_test
#define DBG_PRE_INFO 0
#define DBG_CUR_INFO 0

// For suc_one_point_test
#define DBG_S_PRE_INFO 0
#define DBG_S_CUR_INFO 0

// For solLP
#define DBG_TSOLLP 0
#define DBG_SOLLP 0
#define DBG_ISOLLP 0
#define DBG_MSOLLP 0

// For chooseSup
#define DBG_CHOOSESUP 0
#define DBG_FINDUNB 0

// For modify p_sol
#define DBG_MODIFY 0

#endif
