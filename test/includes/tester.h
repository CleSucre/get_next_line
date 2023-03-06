#ifndef TESTER_H
#define TESTER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);
int get_next_line_test(int fd, char *expected, char *test_name);

#endif
