/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:06:08 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 18:04:29 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef	struct {
	int		fd;
	int		offset;
	char	buffer[BUFFER_SIZE];
} file_info_t;

char	*get_next_line(int fd);
char	*ft_get_line(file_info_t data);
int		ft_strlen(const char *s);
char	*ft_strndup(char *s1, int n);
int		ft_check_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
