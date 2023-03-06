/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:52:39 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 15:53:30 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "includes/colors.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cps1;
	unsigned char	*cps2;

	cps1 = (unsigned char *)s1;
	cps2 = (unsigned char *)s2;
	while ((*cps1 || *cps2))
	{
		if (*cps1 != *cps2)
			return (*cps1 - *cps2);
		cps1++;
		cps2++;
	}
	return (0);
}

int get_next_line_test(int fd, char *expected, char *test_name)
{
	char *line;

	line = get_next_line(fd);
	if (!line || ft_strcmp(line, expected) != 0)
	{
		printf("%sKO%s : %s\n", BOLDRED, RESET, test_name);
		printf("Expected: %s\n", expected);
		printf("Got: %s\n", line);
		return (0);
	}
	else
	{
		printf("%sOK%s : %s | %s got: %s\n", BOLDGREEN, RESET, test_name, expected, line);
	}
	return (1);
}

int	main(void)
{
	int fd;
	int success;

	fd = open("test/data/data.txt", O_RDONLY);
	success = 0;
	success += get_next_line_test(fd, "hello", "Line 1");
	success += get_next_line_test(fd, "world", "Line 2");
	success += get_next_line_test(fd, "this", "Line 3");
	success += get_next_line_test(fd, "is", "Line 4");
	success += get_next_line_test(fd, "a", "Line 5");
	success += get_next_line_test(fd, "test", "Line 6");
	success += get_next_line_test(fd, "file", "Line 7");
	success += get_next_line_test(fd, "for", "Line 8");
	success += get_next_line_test(fd, "get_next_line", "Line 9");
	success += get_next_line_test(fd, "function", "Line 10");
	success += get_next_line_test(fd, "in", "Line 11");
	success += get_next_line_test(fd, "C", "Line 12");
	success += get_next_line_test(fd, "language", "Line 13");
	success += get_next_line_test(fd, "!", "Line 14");
	success += get_next_line_test(fd, NULL, "Line 15");
	close(fd);
	if (success != 30)
	{
		printf("%sget_next_line: %d/15 tests passed%s", BOLDRED, success, RESET);
		return (1);
	}
	printf("%sget_next_line: All %d tests passed%s", BOLDGREEN, success, RESET);
	return (0);
}
