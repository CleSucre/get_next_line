#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char    *buffer;
	char    *line;
	int     b;
	int     i;
	int     newline;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	line[0] = '\0';
	newline = 0;
	while ((b = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[b] = '\0';
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n') {
				newline = 1;
			}
			line = (char *)realloc(line, sizeof(char) * (ft_strlen(line) + 2));
			line[ft_strlen(line) + 1] = '\0';
			line[ft_strlen(line)] = buffer[i];
			i++;
		}
		if (newline)
			break ;
	}
	printf("line: %s", line);
	free(buffer);
	if (b < 0)
	{
		free(line);
		return (NULL);
	}
	else if (b == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}