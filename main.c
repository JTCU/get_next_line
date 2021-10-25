#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	char *line;
	int fd1;
	int fd2;
	int fd3;

	fd1 = open("test/files/42_with_nl", O_RDONLY);
	fd2 = open("file2", O_RDONLY);
	fd3 = open("file3", O_RDONLY);

	line = get_next_line(fd1);
	printf("1	%s\n", line);
	line = get_next_line(fd1);
	printf("2	%s\n", line);
}