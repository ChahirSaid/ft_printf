#include "ft_printf.h"

static int	print_minus(long *nl, int *len, t_flag flag)
{
	ft_put_char('-');
	*nl = -*nl;
	(*len)--;
	if (flag.dot)
		(*len)--;
	return (1);
}

static int	number_of_digit(long num)
{
	int	pos;

	pos = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		pos++;
	while (num != 0)
	{
		num = num / 10;
		pos++;
	}
	return (pos);
}

static int	get_values(char *prefix, int *len_prec, t_flag *flag, long nl)
{
	int	len;

	len = number_of_digit(nl);
	*len_prec = len;
	if (flag->precision > len)
		*len_prec = flag->precision;
	if (nl < 0)
	{
		if (flag->zero_offset > len && flag->precision > len)
			(*len_prec)++;
		if (flag->dot && flag->precision < flag->zero_offset)
			len++;
	}
	*prefix = ' ';
	if (flag->zero && (!flag->dot || flag->zero_offset > flag->precision))
		*prefix = '0';
	if (flag->zero)
		flag->min_width = flag->zero_offset;
	if (flag->precision > flag->min_width)
		flag->min_width = flag->precision;
	return (len);
}

static int	print_di(int len, long nl, t_flag flag)
{
	if (nl == 0 && ((flag.min_width && flag.min_width < len) || (flag.dot
				&& !flag.precision && flag.min_width >= len)))
		return (ft_put_char(' '));
	if (nl == 0 && flag.dot && !flag.precision)
		return (0);
	return (putnbr(nl));
}

int	ft_putnbr(long nl, t_flag flag)
{
	int		total;
	int		len;
	char	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &flag, nl);
	while (prefix == ' ' && len_prec + total < flag.min_width)
		total += ft_put_char(' ');
	if (nl < 0)
		total += print_minus(&nl, &len, flag);
	else if (flag.space && nl >= 0 && !flag.plus && !flag.dot)
		total += ft_put_char(' ');
	else if (flag.plus && nl >= 0 && !flag.dot)
		total += ft_put_char('+');
	while (len + total < flag.min_width)
		total += ft_put_char('0');
	total += print_di(len, nl, flag);
	while (total < flag.offset)
		total += ft_put_char(' ');
	return (total);
}
