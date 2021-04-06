#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	test_1()
{
	char *line = NULL;
	char *line2 = NULL;
	int fd = open("./files/basic.txt", O_RDONLY);
	FILE *fd2 = fopen("./files/basic.txt", "r");
	size_t size = (size_t)BUFFER_SIZE;
	int i = 1;
	int ret = 0;
	int gnl;
	int gl;
	char *nline = NULL;
	if (fd < 0 || !fd2)
	{
		printf("Error at opening\n");
		return (1);
	}
	while ((gnl = get_next_line(fd, &line)) > 0 && (gl = getline(&line2, &size, fd2)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		free(line);
		if (strcmp(nline, line2))
		{
			printf("Error at line %i :\n--- |%s+++ |%s", i, nline, line2);
			ret = 1;
		}
		free(nline);
		i++;
	}
	if (gnl == 0)
		gl = getline(&line2, &size, fd2);
	if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line %i with return value %i :\n--- |%s\n+++ |%s", gnl, i, line, line2);
			ret = 1;
	}
	free(line);
	free(line2);
	close(fd);
	fclose(fd2);
	return (ret);
}



int main()
{
	printf("----------------------------------------\n");
	printf("    Test for BUFFER_SIZE of %i\n", BUFFER_SIZE);
	printf("----------------------------------------\n");
	printf("Basic file : ");
	if (!test_1())
		printf("OK\n");
	else
		printf("ERROR !!!\n");
}

