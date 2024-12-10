#include "ft_printf.h"

static int	printptr_helper(t_format flag, size_t n)
{
	int	total;
	int	len;

	total = 0;
	if (n == 0)
	{
		if (flag.wdth > 5 && !flag.minus)
			total += ft_putnchar(' ', flag.wdth - 5);
		total += write(1, "(nil)", 5);
		if (flag.wdth > 5 && flag.minus)
			total += ft_putnchar(' ', flag.wdth - 5);
		return (total);
	}
	len = ft_hexlen(n);
	if (flag.precision < len || !flag.dot)
		flag.precision = len;
	flag.wdth -= 2;
	if (!flag.minus && flag.wdth > flag.precision && !flag.zero)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	total += write(1, "0x", 2);
	total += ft_putnchar('0', flag.precision - len);
	total += ft_puthex(flag, n, n);
	if (flag.minus && flag.wdth > flag.precision)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	return (total);
}

int	ft_printptr(t_format flag, va_list args)
{
	size_t	n;

	n = va_arg(args, size_t);
	return (printptr_helper(flag, n));
}
