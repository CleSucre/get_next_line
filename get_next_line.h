#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#if !defined(BUFFER_SIZE)
#define BUFFER_SIZE 42
#endif

typedef struct {
	int fd;
	int offset;
	char buffer[BUFFER_SIZE];
} file_info_t;

char		*get_next_line(int fd);
file_info_t	ft_get_save(int fd, file_info_t *files_info);
char		*ft_get_line(file_info_t data);
void		ft_save(file_info_t data, file_info_t *files_info);
int			ft_strlen(const char *s);

#endif
