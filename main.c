#include "benchmark.h"


int	main(void)
{
	int		fpointer;
	char	*file_output;
	char	*res;

	file_output = strjoin("./outputs/BUFFER_", itoa(BUFFER_SIZE));
	res = strjoin(file_output, "_libgnl");
	free(file_output);
	file_output = strjoin(res, itoa(GNL));
	free(res);
	res = strjoin(file_output, ".output");
	free(file_output);
	open_file(res);
	printf("GNL\n");
	bench_time("empty");
	bench_time("nl");
	bench_time("multiple_nlx5");
	bench_time("41_no_nl");
	bench_time("41_with_nl");
	bench_time("42_no_nl");
	bench_time("42_with_nl");
	bench_time("43_no_nl");
	bench_time("43_with_nl");
	bench_time("alternate_line_nl_no_nl");
	bench_time("alternate_line_nl_with_nl");
	bench_time("multiple_line_no_nl");
	bench_time("multiple_line_with_nl");
	bench_time("big_line_no_nl");
	bench_time("big_fucker");
	return (0);
}
