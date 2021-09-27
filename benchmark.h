#ifndef BENCHMAEK_H
# define BENCHMAEK_H

# ifndef GNL
#  define GNL 1
# endif

# include "./utils/color.h"
# include "get_next_line.h"
# include "./utils/ft_utils_function.h"
# include "./utils/write_file.h"
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <wchar.h>

void *bench_time(char *str);

typedef struct s_point 
{
	int gnl1;
	int gnl2;
}				t_score;

#endif