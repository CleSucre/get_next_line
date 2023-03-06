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

char	*get_next_line(int fd)
{
	static file_data_t	*files_data;
	file_data_t	*file_data;
	int			ret;
	char		*line;

	file_data = ft_get_file_data(fd, &files_data);
	file_data->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!file_data->buffer)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, file_data->buffer, BUFFER_SIZE);
		file_data->buffer[ret] = '\0';
		line = ft_get_line(file_data, 0);
		if (line)
		{
			free(file_data->buffer);
			return (line);
		}
	}
	free(file_data->buffer);
	return (NULL);
}
