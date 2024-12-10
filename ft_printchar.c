#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnchar(char c, int n)
{
	int	total;

	total = 0;
	while (n-- > 0)
		total += write(1, &c, 1);
	return (total);
}

int	ft_printchar(t_format flag, va_list args)
{
	char	c;
	int		total;

	total = 0;
	if (flag.specifier == 'c')
		c = va_arg(args, int);
	else
		c = '%';
	flag.precision = 1;
	if (!flag.minus && flag.zero)
		total += ft_putnchar('0', flag.wdth - flag.precision);
	else if (!flag.minus && flag.wdth > flag.precision)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	total += ft_putchar(c);
	if (flag.minus && flag.wdth - flag.precision > 0)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	return (total);
}
