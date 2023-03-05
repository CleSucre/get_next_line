#include "get_next_line.h"

/*
typedef struct {
	int fd;
	int offset;
	char buffer[BUFFER_SIZE];
} file_info_t;
 */

/*
file_info_t	ft_get_file_info(int fd, file_info_t *file_info)
{
	int i;
	file_info_t new;

	i = 0;
	while (file_info[i])
	{
		if (file_info[i].fd == fd)
			return (file_info[i]);
		i++;
	}
	new	= file_info_t();
	new.fd = fd;
	new.offset = 0;
	return (new);
}
 */

int	ft_get_line(int fd, int num)
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
				newline++;
				if (newline == num)
				{
					line = (char *)realloc(line, sizeof(char) * (ft_strlen(line) + 2));
					line[ft_strlen(line) + 1] = '\0';
					line[ft_strlen(line)] = buffer[i];

					break ;
				}
			}
			i++;
		}
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}