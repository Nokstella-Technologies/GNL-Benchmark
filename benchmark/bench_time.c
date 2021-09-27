#include "../benchmark.h"

clock_t Test_GNl(int fd,char *(*gnl)(int))
{
	char *singleLine = malloc(1 * sizeof(char *));
	clock_t	start_clk = clock();

	while(singleLine != NULL)
	{
		free(singleLine);
		singleLine = gnl(fd);
	}
	close(fd);
	return((clock() - start_clk));
}

void *bench_time(char *str)
{
	clock_t			gnl1;
	clock_t			gnl2;
	char			*res;

	printf("for %s files:", str);
	res = strjoin("../files/", str);
	gnl1 = Test_GNl(open(res, 256), &get_next_line);
	free(res);
	printf(" %ld Milisec \n",gnl1);
}
