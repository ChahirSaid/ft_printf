#include "ft_printf.h"

/**
 * print_str - Prints an entire string to standard output
 *
 * @str: String to print
 *
 * @return: Number of characters printed
 */
int	print_str(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
		write(1, &str[pos++], 1);
	return (pos);
}

/**
 * putstr_size - Prints a string with optional size limitation
 *
 * @str: String to print
 * @size: Maximum number of characters to print, or -1 for full string
 *
 * @return: Number of characters printed
 */
static int	putstr_size(char *str, int size)
{
	int	pos;

	if (size == -1)
		return (print_str(str));
	pos = 0;
	while (str[pos] && pos < size)
		write(1, &str[pos++], 1);
	return (pos);
}

/**
 * handle_null_str - Handles printing of NULL string based on precision
 *
 * @flag: Formatting flags for precision
 *
 * @return: Number of characters printed or 0
 */
static int	handle_null_str(t_flag flag)
{
	if (!flag.dot || flag.precision < 0)
		return (putstr_size("(null)", -1));
	if (flag.precision < 6)
		return (0);
	return (putstr_size("(null)", 6));
}

/**
 * ft_putstr - Prints a string with formatting options
 *
 * @str: String to print
 * @flag: Formatting flags for width, precision, and alignment
 *
 * Handles NULL strings with precision according to printf behavior
 *
 * @return: Total number of characters printed
 */
int	ft_putstr(char *str, t_flag flag)
{
	int	pos;
	int	len;

	pos = 0;
	if (!str)
	{
		len = handle_null_str(flag);
		return (len);
	}
	else
		len = ft_strlen(str);
	while (pos + len < flag.min_width)
		pos += ft_put_char(' ');
	if (!flag.dot)
		flag.precision = -1;
	pos += putstr_size(str, flag.precision);
	while (pos < flag.offset)
		pos += ft_put_char(' ');
	return (pos);
}
