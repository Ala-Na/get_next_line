#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	int fp = open("test.c", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	while (get_next_line(fp, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	close(fp);
	return (0);
}
