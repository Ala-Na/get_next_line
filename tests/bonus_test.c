#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	check(int gnl, int gl, char **line, char **fline)
{
	int ret = 0;
	if (gnl > 0 && gnl > 0)
	{
		*line = ft_strjoin(*line, "\n");
		if (strcmp(*line, *fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", *line, *fline);
			ret = 1;
		}
		free(*line);
		return (ret);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
		printf("Error at line %i with return value :\n--- |%s+++ |%s", gnl, *line, *fline);
		return (1);
	}
	else
		return (0);
}

int	test_8()
{
	char *line = NULL;
	char *fline = NULL;
	char *nline = NULL;
	int fd1 = open("./files/basic.txt", O_RDONLY);
	int fd2 = open("./files/cat.txt", O_RDONLY);
	int fd3 = open("./files/empty.txt", O_RDONLY);
	int fd4 = open("./files/newlines_only.txt", O_RDONLY);
	FILE *ffd1 = fopen("./files/basic.txt", "r");
	FILE *ffd2 = fopen("./files/cat.txt", "r");
	FILE *ffd3 = fopen("./files/empty.txt", "r");
	FILE *ffd4 = fopen("./files/newlines_only.txt", "r");
	int ret = 0;
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0 || !ffd1 || !ffd2 || !ffd3 || !ffd4)
	{
		printf("Error at opening\n");
		return (1);
	}
	size_t size = (size_t)BUFFER_SIZE;
	int gnl = get_next_line(fd1, &line);
	int gl = getline(&fline, &size, ffd1);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd2, &line);
	gl = getline(&fline, &size, ffd2);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd3, &line);
	gl = getline(&fline, &size, ffd3);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd4, &line);
	gl = getline(&fline, &size, ffd4);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd1, &line);
	gl = getline(&fline, &size, ffd1);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd1, &line);
	gl = getline(&fline, &size, ffd1);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}	
	gnl = get_next_line(fd2, &line);
	gl = getline(&fline, &size, ffd2);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd2, &line);
	gl = getline(&fline, &size, ffd2);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}	
	while ((gnl = get_next_line(fd1, &line)) > 0 && (gl = getline(&fline, &size, ffd1)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		free(line);
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(nline);
	}
	if (gnl == 0)
		gl = getline(&fline, &size, ffd1);
	if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	free(line);
	while ((gnl = get_next_line(fd2, &line)) > 0 && (gl = getline(&fline, &size, ffd2)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		free(line);
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(nline);
	}
	if (gnl == 0)	
		gl = getline(&fline, &size, ffd2);
	if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	free(line);
	while ((gnl = get_next_line(fd3, &line)) > 0 && (gl = getline(&fline, &size, ffd3)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		free(line);
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(nline);
	}
	if (gnl == 0)
		gl = getline(&fline, &size, ffd3);
	if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	while ((gnl = get_next_line(fd4, &line)) > 0 && (gl = getline(&fline, &size, ffd4)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		free(line);
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(nline);
	}
	if (gnl == 0)
		gl = getline(&fline, &size, ffd4);
	if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	free(line);
	free(fline);
	close(fd1);
	close(fd2);
	close(fd2);
	close(fd4);
	fclose(ffd1);
	fclose(ffd2);
	fclose(ffd3);
	fclose(ffd4);
	return (ret);
}


int	test_7()
{
	char *line = NULL;
	char *fline = NULL;
	char *nline = NULL;
	int fd1 = open("./files/basic.txt", O_RDONLY);
	int fd2 = open("./files/cat.txt", O_RDONLY);
	FILE *ffd1 = fopen("./files/basic.txt", "r");
	FILE *ffd2 = fopen("./files/cat.txt", "r");
	int ret = 0;
	if (fd1 < 0 || fd2 < 0 || !ffd1 || !ffd2)
	{
		printf("Error at opening\n");
		return (1);
	}
	size_t size = (size_t)BUFFER_SIZE;
	int gnl = get_next_line(fd1, &line);
	int gl = getline(&fline, &size, ffd1);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd1, &line);
	gl = getline(&fline, &size, ffd1);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd2, &line);
	gl = getline(&fline, &size, ffd2);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd1, &line);
	gl = getline(&fline, &size, ffd1);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd2, &line);
	gl = getline(&fline, &size, ffd2);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	gnl = get_next_line(fd2, &line);
	gl = getline(&fline, &size, ffd2);
	if (gnl > 0 && gl > 0)
	{
		nline = ft_strjoin(line, "\n");
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(line);
		free(nline);
	}
	else if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error at line with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	while ((gnl = get_next_line(fd1, &line)) > 0 && (gl = getline(&fline, &size, ffd1)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		free(line);
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(nline);
	}
	if (gnl == 0)
		gl = getline(&fline, &size, ffd1);
	if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	free(line);
	while ((gnl = get_next_line(fd2, &line)) > 0 && (gl = getline(&fline, &size, ffd2)) > 0)
	{
		nline = ft_strjoin(line, "\n");
		free(line);
		if (strcmp(nline, fline))
		{
			printf("Error at line :\n--- |%s+++ |%s", nline, fline);
			ret = 1;
		}
		free(nline);
	}
	if (gnl == 0)
		gl = getline(&fline, &size, ffd2);
	if ((gnl <= 0 && gl > 0) || (gnl > 0 && gl <= 0))
	{
			printf("Error with return value %i :\n--- |%s\n+++ |%s", gnl, line, fline);
			ret = 1;
	}
	free(fline);
	free(line);
	close(fd1);
	close(fd2);
	fclose(ffd1);
	fclose(ffd2);
	return (ret);
}

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

int	check_static()
{
	char *line = NULL;
	FILE *fd = fopen("../get_next_line_bonus.c", "r");
	size_t size = (size_t)BUFFER_SIZE;
	int occ = 0;
	int gl;
	if (!fd)
	{
		printf("Error at opening get_next_line_bonus\n");
		return (1);
	}
	while ((gl = getline(&line, &size, fd)) > 0)
	{
		if (strstr(line, "static") != NULL)
			occ += 1;

	}
	fclose(fd);
	fd = fopen("../get_next_line_utils_bonus.c", "r");
	if (!fd)
	{
		printf("Error at opening get_next_line_utils_bonus\n");
		return (1);
	}
	while ((gl = getline(&line, &size, fd)) > 0)
	{
		if (strstr(line, "static") != NULL)
			occ += 1;
	}
	free(line);
	fclose(fd);
	return (occ);
}

int main()
{
	printf("---------------------------------------------\n");
	printf("    Bonus test for BUFFER_SIZE of %i\n", BUFFER_SIZE);
	printf("---------------------------------------------\n");
	int stat;
	printf("Check static : ");
	if ((stat = check_static()) != 1)
	{
		printf("Not right number of static (found %ix)\n", stat);
		return (1);
	}
	else
		printf("OK\n");
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
	printf("Two files : ");
	if (!test_7())
		printf("OK\n");
	else
		printf("ERROR !!!\n");
	printf("Four files : ");
	if (!test_8())
		printf("OK\n");
	else
		printf("ERROR !!!\n");
	return (0);
}
