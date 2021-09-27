#include "ft_utils_function.h"

static size_t	ft_count_size(long int n)
{
	if (n < 0)
		return (1 + ft_count_size(-n));
	if (n <= 9)
		return (1);
	else
		return (1 + ft_count_size(n / 10));
}

static void	ft_populete_loop(char *new, int n, int size)
{
	if (n < 0)
	{
		new[0] = '-';
		n *= -1;
	}
	if (n > 9)
		ft_populete_loop(new, n / 10, size - 1);
	new[size] = (n % 10) + 48;
}

char	*itoa(int n)
{
	size_t	size;
	char	*int_str;
	int		flag;

	flag = 0;
	if (n <= INT_MIN)
	{
		n = -INT_MAX;
		flag = 1;
	}
	size = ft_count_size(n);
	int_str = malloc(size + 1 * sizeof(char));
	int_str[size] = 0;
	if (!int_str)
		return (NULL);
	ft_populete_loop(int_str, n, --size);
	if (flag == 1)
		int_str[size] += flag;
	return (int_str);
}

size_t	strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != 0)
		a++;
	return (a);
}


char	*strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = strlen(s1) + strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
