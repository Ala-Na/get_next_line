#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char *line = NULL;
	int i = 1;
	int gnl;
	printf("\nPlease, enter something and press \"ENTER\".\nPress \"ctrl\" + \"D\" to send an EOF signal and quit.\n\n");
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		printf("Line %i : |%s\n", i, line);
		free(line);
		i++;
	}
	if (gnl == 0)
		printf("EOF\n");
	else if (gnl < 0)
		printf("ERROR !!!\n");
	free(line);
	return (0);
}

