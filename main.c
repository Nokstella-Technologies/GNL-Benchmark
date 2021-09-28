#include "benchmark.h"


int	main(void)
{
	int		fpointer;
	int		i = 0;
	int		a = 0;
	t_score	score;


	if(GNL == -1)
	{
		score.gnl1 = 0;
		score.gnl2 = 0;
		print_header();
		while(i < 16)
		{
			a = 0;
			while(a <= 3)
			{
				bench_print(g_files_outputs[a], g_files_outputs[a + 4], g_files[i],a, i, &score);
				a++;
			}
			i++;
		}
		print_end(score);
		exit(0);
	}
	open_file(g_files_outputs[GNL]);
	while(i < 16)
	{
		bench_time(g_files[i]);
		i++;
	}
	return (0);
}
