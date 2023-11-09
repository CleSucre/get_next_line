/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:51:46 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/08 05:51:46 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return (1);
		i++;
	}
	if ((char)c == s[i])
		return (1);
	return (0);
}

void	ft_realloc(char **s1, const char *s2)
{
	char	*tmp;
	int		i;
	int		j;

	if (*s1 == NULL)
	{
		*s1 = (char *)malloc(sizeof(char) * 1);
		if (*s1 == NULL)
			return ;
		**s1 = '\0';
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return ;
	i = 0;
	while ((*s1)[i])
		tmp[i] = (*s1)[i++];
	j = 0;
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	free(*s1);
	*s1 = tmp;
}

char	*ft_get_line(char *readed)
{
	char	*res;
	size_t	i;

	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	if (i == 0 && readed[i] != '\n')
		return (NULL);
	if (readed[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (readed[i] && readed[i] != '\n')
	{
		res[i] = readed[i];
		i++;
	}
	if (readed[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}
