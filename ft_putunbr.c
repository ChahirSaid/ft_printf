#include "ft_printf.h"

int	print_unumber(unsigned long nb)
{
	int				total;
	unsigned long	num;

	total = 0;
	num = nb;
	if (num >= 10)
		total += print_unumber(num / 10);
	total += ft_put_char((num % 10) + '0');
	return (total);
}

static int	ft_intlen(unsigned long num)
{
	int	pos;

	if (num == 0)
		return (1);
	pos = 0;
	while (num != 0)
	{
		num = num / 10;
		pos++;
	}
	return (pos);
}

static int	get_values(char *prefix, int *lp, t_flag *flag, unsigned long num)
{
	int	len;

	len = ft_intlen(num);
	*lp = len;
	if (flag->precision > len)
		*lp = flag->precision;
	*prefix = ' ';
	if (flag->zero && (!flag->dot || flag->zero_offset > flag->precision))
		*prefix = '0';
	if (flag->zero)
		flag->min_width = flag->zero_offset;
	if (flag->precision > flag->min_width)
		flag->min_width = flag->precision;
	return (len);
}

static int	print_u(int len, unsigned long num, t_flag flag)
{
	if (num == 0 && ((flag.min_width && flag.min_width < len) || (flag.dot
				&& !flag.precision && flag.min_width >= len)))
		return (ft_put_char(' '));
	if (num == 0 && flag.dot && !flag.precision)
		return (0);
	return (print_unumber(num));
}

int	ft_putunbr(unsigned long num, t_flag flag)
{
	int		total;
	int		len;
	int		len_prec;
	char	prefix;

	total = 0;
	len = get_values(&prefix, &len_prec, &flag, num);
	while (len_prec + total < flag.min_width)
		total += ft_put_char(prefix);
	while (len + total < flag.min_width)
		total += ft_put_char('0');
	total += print_u(len, num, flag);
	while (total < flag.offset)
		total += ft_put_char(' ');
	return (total);
}
