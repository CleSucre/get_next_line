#include "../get_next_line.h"
#include "includes/colors.h"
#include "includes/tester.h"

int	main(void)
{
	int fd;
	int success;

	fd = open("test/data/file_1.txt", O_RDONLY);
	success = 0;
	success += get_next_line_test(fd, "hello x y z", "Line 1");
	success += get_next_line_test(fd, "world ded a", "Line 2");
	success += get_next_line_test(fd, "this zz \\t", "Line 3");
	success += get_next_line_test(fd, "is zdzdez", "Line 4");
	success += get_next_line_test(fd, "a zd azd zefpzkll", "Line 5");
	success += get_next_line_test(fd, "testferfr", "Line 6");
	success += get_next_line_test(fd, "file   \"ffz\"", "Line 7");
	success += get_next_line_test(fd, "forzcz", "Line 8");
	success += get_next_line_test(fd, "get_ne  xt_line", "Line 9");
	success += get_next_line_test(fd, "function", "Line 10");
	success += get_next_line_test(fd, "in  the                                 yo", "Line 11");
	success += get_next_line_test(fd, "C", "Line 12");
	success += get_next_line_test(fd, "language", "Line 13");
	success += get_next_line_test(fd, "!", "Line 14");
	success += get_next_line_test(fd, NULL, "Line 15");
	close(fd);
	if (success != 15)
	{
		printf("%sget_next_line: %d/15 tests passed%s\n", BOLDRED, success, RESET);
		return (1);
	}
	printf("%sget_next_line: All %d tests passed%s\n", BOLDGREEN, success, RESET);
	return (0);
}
