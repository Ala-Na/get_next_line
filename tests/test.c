#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	test_6()
{
	char *line = NULL;
	char *line2 = NULL;
	char *nline = NULL;
	int fd = open("./files/big_line.txt", O_RDONLY);
	FILE *fd2 = fopen("./files/big_line.txt", "r");
	size_t size = (size_t)BUFFER_SIZE;
	int i = 1;
	int ret = 0;
	int gnl;
	int gl;
	if (fd < 0 || !fd2)
	{
		printf("Error at opening\n");
		return (1);
	}
	while ((gnl = get_next_line(fd, &line)) > 0 && (gl = getline(&line2, &size, fd2)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, line2))
		{
			printf("Error at line %i :\n--- |%s+++ |%s", i, nline, line2);
			ret = 1;
		}
		free(nline);
		free(line);
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

int	test_5()
{
	char *line = NULL;
	char *line2 = NULL;
	int fd = open("./files/big.txt", O_RDONLY);
	FILE *fd2 = fopen("./files/big.txt", "r");
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
		if (strcmp(nline, line2))
		{
			printf("Error at line %i :\n--- |%s+++ |%s", i, nline, line2);
			ret = 1;
		}
		free(nline);
		free(line);
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

int	test_4()
{
	char *line = NULL;
	char *line2 = NULL;
	int fd = open("./files/cat.txt", O_RDONLY);
	FILE *fd2 = fopen("./files/cat.txt", "r");
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
		if (strcmp(nline, line2))
		{
			printf("Error at line %i :\n--- |%s+++ |%s", i, nline, line2);
			ret = 1;
		}
		free(nline);
		free(line);
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


int	test_3()
{
	char *line = NULL;
	char *line2 = NULL;
	int fd = open("./files/cat.txt", O_RDONLY);
	FILE *fd2 = fopen("./files/cat.txt", "r");
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
		if (strcmp(nline, line2))
		{
			printf("Error at line %i :\n--- |%s+++ |%s", i, nline, line2);
			ret = 1;
		}
		free(nline);
		free(line);
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

int	test_2()
{
	char *line = NULL;
	char *line2 = NULL;
	int fd = open("./files/newlines_only.txt", O_RDONLY);
	FILE *fd2 = fopen("./files/newlines_only.txt", "r");
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
		if (strcmp(nline, line2))
		{
			printf("Error at line %i :\n--- |%s+++ |%s", i, nline, line2);
			ret = 1;
		}
		free(nline);
		free(line);
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
	printf("Newlines only file : ");
	if (!test_2())
		printf("OK\n");
	else
		printf("ERROR !!!\n");
	printf("Ascii art file : ");
	if (!test_3())
		printf("OK\n");
	else
	printf("ERROR !!!\n");
	printf("Empty file : ");
	if (!test_4())
		printf("OK\n");
	else
		printf("ERROR !!!\n");
	printf("Huge file : ");
	if (!test_5())
		printf("OK\n");
	else
		printf("ERROR !!!\n");
	printf("Huge line : ");
	if (!test_6())
		printf("OK\n");
	else
		printf("ERROR !!!\n");

	return (0);
}
