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
 * ft_putstr - Prints a string with formatting options
 *
 * @str: String to print
 * @flag: Formatting flags for width, precision, and alignment
 *
 * Handles NULL strings, applies minimum width and precision
 * Supports right/left alignment
 * 
 * @return: Total number of characters printed
 */
int	ft_putstr(char *str, t_flag flag)
{
	int	pos;
	int	len;

	pos = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	while (pos + len < flag.min_width)
		pos += ft_put_char(' ');
	if (!flag.dot)
		flag.precision = -1;
	if (!str)
		pos += putstr_size("(null)", flag.precision);
	else
		pos += putstr_size(str, flag.precision);
	while (pos < flag.offset)
		pos += ft_put_char(' ');
	return (pos);
}
