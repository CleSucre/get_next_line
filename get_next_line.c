/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:05:47 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 18:04:52 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **args)
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(args[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("line: %s\n", line);
		free(line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			ret;
	int			index;

	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (1)
	{
		if (!buffer || buffer[0] == '\0')
		{
			buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!buffer)
				return (NULL);
			ret = read(fd, buffer, BUFFER_SIZE);
			if (ret <= 0)
			{
				free(buffer);
				return (*line ? line : NULL);
			}
			buffer[ret] = '\0';
		}
		index = ft_check_newline(buffer);
		if (index >= 0)
		{
			line = ft_strjoin(line, ft_strndup(buffer, index));
			buffer = ft_strndup(buffer + index + 1, ft_strlen(buffer + index + 1));
			return (line);
		}
		line = ft_strjoin(line, buffer);
		buffer[0] = '\0';
	}
}
