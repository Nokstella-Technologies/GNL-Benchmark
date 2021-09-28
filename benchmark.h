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
typedef struct s_point 
{
	int gnl1;
	int gnl2;
}				t_score;

static char *g_files_outputs[] = 
{
	"./outputs/BUFFER_1_gnl1.output",
	"./outputs/BUFFER_5_gnl1.output",
	"./outputs/BUFFER_42_gnl1.output",
	"./outputs/BUFFER_10000000_gnl1.output",
	"./outputs/BUFFER_1_gnl2.output",
	"./outputs/BUFFER_5_gnl2.output",
	"./outputs/BUFFER_42_gnl2.output",
	"./outputs/BUFFER_10000000_gnl2.output",
};

static char *g_files[] = 
{
	"empty",
	"nl",
	"multiple_nlx5",
	"41_no_nl",
	"41_with_nl",
	"42_no_nl",
	"42_with_nl",
	"43_no_nl",
	"43_with_nl",
	"alternate_line_nl_no_nl",
	"alternate_line_nl_with_nl",
	"multiple_line_no_nl",
	"multiple_line_with_nl",
	"big_line_no_nl",
	"big_line_with_nl",
	"big_fucker",
};
void bench_time(char *str);
void bench_print(char *gnl1,char *gnl2,char *str,int a, int b , t_score *score);
void print_header(void);
void print_end(t_score score);
#endif