#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	_putchar(char c, t_flag flag)
{
	int	pos;

	pos = 0;
	while (pos + 1 < flag.min_width)
		pos += ft_putchar(' ');
	pos += ft_putchar(c);
	while (pos < flag.offset)
		pos += ft_putchar(' ');
	return (pos);
}
