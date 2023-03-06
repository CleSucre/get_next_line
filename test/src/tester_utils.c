#include "../../get_next_line.h"
#include "../includes/colors.h"
#include "../includes/tester.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cps1;
	const unsigned char	*cps2;

	cps1 = (const unsigned char *)s1;
	cps2 = (const unsigned char *)s2;
	while (n-- > 0)
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

	if (line == NULL)
		line = "NULL";
	if (expected == NULL)
		expected = "NULL";
	if (ft_memcmp(line, expected, ft_strlen(expected)) != 0 || ft_strlen(line) != ft_strlen(expected))
	{
		printf("%sKO%s : %s\nExpected: %s\nGot: %s\n", BOLDRED, RESET, test_name, expected, line);
		return (0);
	}
	else
	{
		printf("%sOK%s : %s | %s got: %s\n", BOLDGREEN, RESET, test_name, expected, line);
	}
	return (1);
}