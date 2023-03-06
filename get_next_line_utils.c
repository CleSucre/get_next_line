/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:06:22 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 18:04:15 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s1, int n)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
	{
		res = malloc(sizeof(char) * 1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (len + start > size)
		len = size - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

file_data_t *ft_get_file_data(int fd, file_data_t **files_data)
{
	file_data_t	*file_data;

	if (!files_data)
		return (NULL);
	file_data = *files_data;
	while (file_data)
	{
		if (file_data->fd == fd)
			return (file_data);
		file_data = (file_data_t *) file_data->next;
	}
	file_data = (file_data_t *)malloc(sizeof(file_data_t));
	if (!file_data)
		return (NULL);
	file_data->fd = fd;
	file_data->lines_number = 0;
	file_data->last_line_end = 0;
	file_data->readed_buffer = NULL;
	file_data->buffer = NULL;
	file_data->next = (struct file_data_t *) *files_data;
	*files_data = file_data;
	return (file_data);
}

char *ft_get_line(file_data_t *file_data, int get_last)
{
	char	*res;
	int		i;

	if (!file_data->readed_buffer)
		file_data->readed_buffer = ft_strndup(file_data->buffer, BUFFER_SIZE);
	else
		file_data->readed_buffer = ft_strjoin(file_data->readed_buffer, file_data->buffer);
	if (!file_data->readed_buffer[file_data->last_line_end])
		return (NULL);
	i = file_data->last_line_end;
	while (file_data->readed_buffer[i])
	{
		if (file_data->readed_buffer[i] == '\n')
		{
			file_data->lines_number++;
			break;
		}
		if (!file_data->readed_buffer[++i])
		{
			if (get_last)
				break;
			return (NULL);
		}
	}
	res = ft_substr(file_data->readed_buffer, file_data->last_line_end, i - file_data->last_line_end);
	file_data->last_line_end = i + 1;
	return (res);
}