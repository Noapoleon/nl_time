#ifndef NL_TIME_H
# define NL_TIME_H

# include <time.h>
# include <stdio.h>

# define NLT_START	0x1
# define NLT_PRINT	0x2
# define NLT_SEC	0x10
# define NLT_MILLI	0x20
# define NLT_MICRO	0x40

long		nl_time(char masks);

#endif

// ADD CONTINUOUS MODE where it doesn't reset start to 0
// NLT_NORESET
//
// make it so that if invalid mask combination are given it
// prints an error like printf
