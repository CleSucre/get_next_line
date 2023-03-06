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
#  define BUFFER_SIZE 2
# endif

typedef	struct {
	int					fd;
	int 				lines_number;
	int 				last_line_end;
	char 				*readed_buffer;
	char				*buffer;
	struct file_data_t	*next;
} file_data_t;

char		*get_next_line(int fd);
file_data_t *ft_get_file_data(int fd, file_data_t **files_data);
char		*ft_get_line(file_data_t *file_data, int get_last);

#endif
