#include "ft_printf.h"

/**
 * ft_put_char - Writes a single character to standard output
 *
 * @c: Character to be printed
 *
 * @return: Number of characters printed (always 1)
 */
int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * ft_putchar - Prints a character with optional formatting
 *
 * @c: Character to print
 * @flag: Formatting flags (width, left/right alignment)
 *
 * @return: Total number of characters printed
 */
int	ft_putchar(char c, t_flag flag)
{
	int	pos;

	pos = 0;
	while (pos + 1 < flag.min_width)
		pos += ft_put_char(' ');
	pos += ft_put_char(c);
	while (pos < flag.offset)
		pos += ft_put_char(' ');
	return (pos);
}
