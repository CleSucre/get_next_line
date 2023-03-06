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
#include "includes/tester.h"

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
	if (success != 15)
	{
		printf("%sget_next_line: %d/15 tests passed%s", BOLDRED, success, RESET);
		return (1);
	}
	printf("%sget_next_line: All %d tests passed%s", BOLDGREEN, success, RESET);
	return (0);
}
