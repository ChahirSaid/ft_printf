#include "ft_printf.h"

static int	print_long_as_hex(long unsigned addr)
{
	char	c;
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total += print_long_as_hex(addr / 16);
		total += print_long_as_hex(addr % 16);
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

static int	get_hex_size(long unsigned addr)
{
	int	total;

	total = 0;
	if (addr >= 16)
	{
		total += get_hex_size(addr / 16);
		total += get_hex_size(addr % 16);
	}
	else
		total++;
	return (total);
}

int	ft_printpointer(void *ptr, t_flag flag)
{
	long	addr;
	int		total;
	int		len;

	if (ptr == NULL)
	{
		total = 0;
		total += print_str("(nil)");
		while (total < flag.offset)
			total += ft_putchar(' ');
		return (total);
	}
	addr = (long unsigned)ptr;
	total = 0;
	len = get_hex_size(addr) + 2;
	while (len + total < flag.min_width)
		total += ft_putchar(' ');
	total += print_str("0x");
	total += print_long_as_hex(addr);
	while (total < flag.offset)
		total += ft_putchar(' ');
	return (total);
}
