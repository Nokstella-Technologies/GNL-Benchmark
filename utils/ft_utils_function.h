#ifndef FT_UTILS_FUNCTION_H
# define FT_UTILS_FUNCTION_H
#include <limits.h>
#include <stdlib.h>
#include <string.h>

char	*itoa(int n);
char	*strtrim(char const *s1, char const *set);
char	*strjoin(char const *s1, char const *s2);
char	*substr(char const *s, unsigned int start, size_t len);
char	*strdup(const char *str);

#endif