#include "../get_next_line.h"
#include "includes/colors.h"
#include "includes/tester.h"

int	main(void)
{
	int file_1;
	int file_2;
	int file_3;
	int success;

	file_1 = open("test/data/file_1.txt", O_RDONLY);
	success = 0;
	success += get_next_line_test(file_1, "hello x y z", "Line 1");
	success += get_next_line_test(file_1, "world ded a", "Line 2");
	success += get_next_line_test(file_1, "this zz \\t", "Line 3");
	success += get_next_line_test(file_1, "is zdzdez", "Line 4");
	success += get_next_line_test(file_1, "a zd azd zefpzkll", "Line 5");
	success += get_next_line_test(file_1, "testferfr", "Line 6");
	success += get_next_line_test(file_1, "file   \"ffz\"", "Line 7");
	success += get_next_line_test(file_1, "forzcz", "Line 8");
	success += get_next_line_test(file_1, "get_ne  xt_line", "Line 9");
	success += get_next_line_test(file_1, "function", "Line 10");
	success += get_next_line_test(file_1, "in  the                                 yo", "Line 11");
	success += get_next_line_test(file_1, "C", "Line 12");
	success += get_next_line_test(file_1, "language", "Line 13");
	success += get_next_line_test(file_1, "!", "Line 14");
	success += get_next_line_test(file_1, NULL, "Line 15");
	close(file_1);
	if (success != 15)
		printf("%sget_next_line: %d/15 tests passed%s\n", BOLDRED, success, RESET);
	else
		printf("%sget_next_line: All %d tests passed%s\n", BOLDGREEN, success, RESET);

	//bonus part
	file_1 = open("test/data/file_1.txt", O_RDONLY);
	file_2 = open("test/data/file_2.txt", O_RDONLY);
	file_3 = open("test/data/file_3.txt", O_RDONLY);
	success = 0;
	success += get_next_line_test(file_3, "Lorem ips", "Line 1 file 3");
	success += get_next_line_test(file_3, "um dolor", "Line 2 file 3");
	success += get_next_line_test(file_1, "hello x y z", "Line 1 file 1");
	success += get_next_line_test(file_2, "i", "Line 1 file 2");
	success += get_next_line_test(file_1, "world ded a", "Line 2 file 1");
	success += get_next_line_test(file_2, "am", "Line 2 file 2");
	success += get_next_line_test(file_3, "sit amet, co", "Line 3 file 3");
	success += get_next_line_test(file_1, "this zz \\t", "Line 3 file 1");
	success += get_next_line_test(file_1, "is zdzdez", "Line 4 file 1");
	success += get_next_line_test(file_3, "nsecte", "Line 4 file 3");
	success += get_next_line_test(file_3, "tur adipiscing elit. Done", "Line 5 file 3");
	success += get_next_line_test(file_3, "c tincidunt ma", "Line 6 file 3");
	success += get_next_line_test(file_3, "gna est, sit amet", "Line 7 file 3");
	success += get_next_line_test(file_2, "a super mega usefull", "Line 3 file 2");
	success += get_next_line_test(file_2, "", "Line 4 file 2");
	success += get_next_line_test(file_2, "file that i", "Line 5 file 2");
	success += get_next_line_test(file_1, "a zd azd zefpzkll", "Line 5 file 1");
	success += get_next_line_test(file_1, "testferfr", "Line 6 file 1");
	success += get_next_line_test(file_3, " congue mauris m", "Line 8 file 3");
	success += get_next_line_test(file_1, "file   \"ffz\"", "Line 7 file 1");
	success += get_next_line_test(file_1, "forzcz", "Line 8 file 1");
	success += get_next_line_test(file_2, "s used to", "Line 6 file 2");
	success += get_next_line_test(file_1, "get_ne  xt_line", "Line 9 file 1");
	success += get_next_line_test(file_1, "function", "Line 10 file 1");
	success += get_next_line_test(file_2, "", "Line 7 file 2");
	success += get_next_line_test(file_1, "in  the                                 yo", "Line 11 file 1");
	success += get_next_line_test(file_1, "C", "Line 12 file 1");
	success += get_next_line_test(file_1, "language", "Line 13 file 1");
	success += get_next_line_test(file_1, "!", "Line 14 file 1");
	success += get_next_line_test(file_1, NULL, "Line 15 file 1");
	success += get_next_line_test(file_2, "test a wird program", "Line 8 file 2");
	success += get_next_line_test(file_3, " attis non", "Line 9 file 3");
	success += get_next_line_test(file_3, " .", "Line 10 file 3");
	close(file_1);
	close(file_2);
	close(file_3);
	if (success != 33)
		printf("%sget_next_line_bonus: %d/33 tests passed%s\n", BOLDRED, success, RESET);
	else
		printf("%sget_next_line_bonus: All %d tests passed%s\n", BOLDGREEN, success, RESET);
	return (0);
}
