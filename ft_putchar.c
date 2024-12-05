#include "ft_printf.h"

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

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
