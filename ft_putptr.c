#include "ft_printf.h"

/**
 * ft_putlonghex - Recursively prints a long unsigned integer
 *				in hexadecimal format
 *
 * @addr: Long unsigned integer to convert and print
 *
 * Converts the number to hexadecimal digits (0-9, a-f)
 *
 * @return: Total number of characters printed
 */
static int	ft_putlonghex(long unsigned addr)
{
	char	c;
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total += ft_putlonghex(addr / 16);
		total += ft_putlonghex(addr % 16);
	}
	else
	{
		c = (addr % 16) + '0';
		if ((addr % 16) > 9)
			c = ((addr % 16) + 87);
		write(1, &c, 1);
		total++;
	}
	return (total);
}

/**
 * ft_hexlen - Calculates the number of hexadecimal digits
 *			for a long unsigned integer
 *
 * @addr: Long unsigned integer to calculate length for
 *
 * @return: Number of hexadecimal digits
 */
static int	ft_hexlen(long unsigned addr)
{
	int	total;

	total = 0;
	if (addr >= 16)
	{
		total += ft_hexlen(addr / 16);
		total += ft_hexlen(addr % 16);
	}
	else
		total++;
	return (total);
}

/**
 * ft_putptr - Prints a pointer address in hexadecimal format with formatting
 *
 * @ptr: Pointer to be printed
 * @flag: Formatting flags for width and alignment
 *
 * Handles special cases like NULL pointer, prints "0x" prefix
 * Applies minimum width and right/left alignment
 *
 * @return: Total number of characters printed
 */
int	ft_putptr(void *ptr, t_flag flag)
{
	long	addr;
	int		total;
	int		len;

	if (ptr == NULL)
	{
		total = 0;
		total += print_str("(nil)");
		while (total < flag.offset)
			total += ft_put_char(' ');
		return (total);
	}
	addr = (long unsigned)ptr;
	total = 0;
	len = ft_hexlen(addr) + 2;
	while (len + total < flag.min_width)
		total += ft_put_char(' ');
	total += print_str("0x");
	total += ft_putlonghex(addr);
	while (total < flag.offset)
		total += ft_put_char(' ');
	return (total);
}
