#ifndef WRITE_FILE_H
# define WRITE_FILE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void perror(const char *string);
void open_file(char *file);

#endif