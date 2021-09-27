#include "write_file.h"

void open_file(char *file)
{
    int fd;
	char *reads = malloc(101 *sizeof(char));
	reads[100] = 0;
    fd = open(file, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror(file);
        exit(1);
    }
    if (dup2(fd, 1) == -1) {
        perror("dup2 failed"); 
        exit(1);
    }
	while(read(fd,reads,100) >= 0)
	{
		free(reads);
	}
}