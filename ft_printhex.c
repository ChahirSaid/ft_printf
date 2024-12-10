#include "ft_printf.h"

int	ft_hexlen(unsigned long nbr)
{
	unsigned long	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

static char	*ft_sharp(t_format flag)
{
	if (flag.specifier == 'X')
		return ("0X");
	return ("0x");
}

int	ft_puthex(t_format flag, size_t n, size_t iteration)
{
	int			total;
	const char	*base;

	if (!(n > 0 || (!iteration && (flag.specifier != 'p' || !flag.dot))))
		return (0);
	if (flag.specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	total = ft_puthex(flag, n / 16, 1);
	return (total + ft_putchar(base[n % 16]));
}

static int	printhex_helper(t_format flag, unsigned int n)
{
	int	total;
	int	len;

	total = 0;
	len = ft_hexlen(n);
	if (!n && !flag.precision && flag.dot)
		len = 0;
	if (flag.precision < 0 || flag.precision < len || !flag.dot)
		flag.precision = len;
	if (flag.sharp && n)
		flag.wdth -= 2;
	total += ft_putnstr(ft_sharp(flag), 2 * (flag.sharp && flag.zero && n));
	if (!flag.minus && flag.wdth > flag.precision && (!flag.dot
			|| flag.prec_negative) && flag.zero)
		total += ft_putnchar('0', (flag.wdth - flag.precision));
	else if (!flag.minus && flag.wdth > flag.precision)
		total += ft_putnchar(' ', (flag.wdth - flag.precision));
	total += ft_putnstr(ft_sharp(flag), 2 * (flag.sharp && !flag.zero && n));
	total += ft_putnchar('0', (flag.precision - len));
	if (len)
		total += ft_puthex(flag, n, n);
	if (flag.minus && flag.wdth > flag.precision)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	return (total);
}

int	ft_printhex(t_format flag, va_list args)
{
	int				total;
	unsigned int	n;

	total = 0;
	n = va_arg(args, unsigned int);
	total += printhex_helper(flag, n);
	return (total);
}
