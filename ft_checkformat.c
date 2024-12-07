#include "ft_printf.h"

/**
 * check_format - Validates the format specifier syntax in a printf-like string
 *
 * @str: The format string to validate
 *
 * Checks for valid flag combinations,
 *		dot (.) occurrence, and valid conversion specifiers
 *
 * @return: 1 if format is valid, 0 if invalid
 */
int	check_format(const char *str)
{
	int	dots;
	int	i;

	dots = 0;
	i = 1;
	if (str[1] == '\0')
		return (0);
	while (str[i] && ft_strchr(str[i], "# +0-"))
		i++;
	while (str[i] && (str[i] == '.' || (str[i] >= '0' && str[i] <= '9')))
	{
		if (str[i] == '.')
		{
			dots++;
			if (str[i + 1] == '.')
				return (0);
		}
		i++;
	}
	if (dots > 1 || !ft_strchr(str[i], "cspdiuxX%"))
		return (0);
	return (1);
}

/**
 * print_invalid_format - Handles and prints an invalid format specifier
 *
 * @str: The invalid format string
 * @pos: Pointer to the current position in the main string,
 *		updated after processing
 *
 * Prints out characters until a valid conversion specifier or end of string
 *
 * @return: Number of characters printed
 */
int	print_invalid_format(const char *str, int *pos)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (str[i] && !(ft_strchr(str[i], "cspdiuxX%")))
	{
		total += ft_put_char(str[i]);
		i++;
	}
	if (str[i])
		total += ft_put_char(str[i]);
	*pos += i;
	return (total);
}
