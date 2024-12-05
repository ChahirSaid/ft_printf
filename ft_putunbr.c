#include "ft_printf.h"

int	print_unumber(unsigned long nl)
{
	int				total;
	unsigned long	num;	

	total = 0;
	num = nl;
	if (num >= 10)
		total += print_unumber(num / 10);
	total += ft_put_char((num % 10) + '0');
	return (total);
}

static int	number_of_digit(unsigned long num)
{
	int	pos;

	pos = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		pos++;
	}
	return (pos);
}

static int	get_values(char	*prefix, int *lp, t_flag *flag, unsigned long num)
{
	int	len;

	len = number_of_digit(num);
	*lp = len;
	if (flag->precision > len)
		*lp = flag->precision;
	*prefix = '0';
	if (flag->zero && flag->dot && flag->zero_offset > flag->precision)
		*prefix = ' ';
	if (!flag->zero)
		*prefix = ' ';
	if (flag->zero)
		flag->min_width = flag->zero_offset;
	if (flag->precision > flag->min_width)
		flag->min_width = flag->precision;
	return (len);
}

static int	print_u(int len, unsigned long num, t_flag flag)
{
	int	total;

	total = 0;
	if (num == 0 && flag.min_width && flag.min_width < len)
		total += ft_put_char(' ');
	else if (num == 0 && flag.dot && !flag.precision && flag.min_width >= len)
		total += ft_put_char(' ');
	else if (!(num == 0 && flag.dot && !flag.precision))
		total += print_unumber(num);
	return (total);
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
