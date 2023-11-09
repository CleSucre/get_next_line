/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:04:00 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/07 20:04:00 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_clean_readed(char **readed)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while ((*readed)[i] && (*readed)[i] != '\n')
		i++;
	if ((*readed)[i] == '\0')
	{
		free(*readed);
		*readed = NULL;
		return ;
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*readed) - i + 1));
	if (!tmp)
		return ;
	i++;
	j = 0;
	while ((*readed)[i])
		tmp[j++] = (*readed)[i++];
	tmp[j] = '\0';
	free(*readed);
	*readed = tmp;
}

char	*get_next_line(int fd)
{
	static char	*readed[4096];
	char		*buffer;
	int			byte_read;
	char		*res;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_read = BUFFER_SIZE;
	while (!ft_strchr(readed[fd], '\n') && byte_read == BUFFER_SIZE)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == 0 || byte_read == -1)
			break ;
		buffer[byte_read] = '\0';
		ft_realloc(&readed[fd], buffer);
	}
	free(buffer);
	if (readed[fd] == NULL)
		return (NULL);
	res = ft_get_line(readed[fd]);
	ft_clean_readed(&readed[fd]);
	return (res);
}
