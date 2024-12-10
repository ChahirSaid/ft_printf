#include "ft_printf.h"

int	handle_null(t_format flag)
{
	if (flag.dot && flag.precision < 6)
		return (0);
	if (flag.dot && flag.precision > 0 && flag.precision <= 6)
		return (flag.precision);
	return (6);
}

int	ft_putnstr(char *s, int n)
{
	if (s)
		return (write(1, s, n));
	return (0);
}

int	ft_printstr(t_format flag, va_list args)
{
	char	*string;
	int		total;
	int		str_len;

	total = 0;
	string = va_arg(args, char *);
	if (!string)
	{
		string = "(null)";
		str_len = handle_null(flag);
		flag.precision = str_len;
	}
	else
		str_len = ft_strlen(string);
	if (!flag.dot || flag.precision > str_len || flag.precision < 0)
		flag.precision = str_len;
	if (!flag.minus && flag.wdth > flag.precision && flag.zero && (!flag.dot
			|| flag.prec_negative))
		total += ft_putnchar('0', flag.wdth - flag.precision);
	else if (!flag.minus && flag.wdth - flag.precision > 0)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	total += ft_putnstr(string, flag.precision);
	if (flag.minus && flag.wdth - flag.precision > 0)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	return (total);
}
