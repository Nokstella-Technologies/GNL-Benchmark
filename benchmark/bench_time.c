#include "../benchmark.h"

clock_t Test_GNl(int fd,char *(*gnl)(int))
{
	char *singleLine = malloc(1 * sizeof(char *));
	
	clock_t	start_clk = clock();
	while(singleLine != NULL)
	{
		free(singleLine);
		singleLine = gnl(fd);
		getpid();
	}
	start_clk = (clock() - start_clk);
	close(fd);
	return(start_clk);
}

void bench_time(char *str)
{
	clock_t			gnl1;
	char			*res;

	res = strjoin("../files/", str);
	gnl1 = Test_GNl(open(res, 256), &get_next_line);
	free(res);
	printf("%ld Milisec.\n",gnl1);
}
