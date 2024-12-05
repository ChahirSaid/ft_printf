#include "ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->sharp = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->min_width = 0;
	flag->dot = 0;
	flag->precision = 0;
	flag->zero = 0;
	flag->zero_offset = 0;
	flag->offset = 0;
}

int	ft_strlen(char *str)
{
	int	pos;

	pos = 0;
	if (!str)
		return (pos);
	while (str[pos])
		pos++;
	return (pos);
}

int	ft_atoi(const char *str, int *o_pos)
{
	int	pos;
	int	num;

	pos = 0;
	num = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		num = num * 10 + str[pos] - '0';
		pos++;
		(*o_pos)++;
	}
	return (num);
}

int	in_set(char c, char *set)
{
	int	pos;

	pos = -1;
	while (set[++pos])
		if (set[pos] == c)
			return (1);
	return (0);
}

int	print_number(long nl)
{
	int		total;
	long	num;	

	total = 0;
	num = nl;
	if (nl < 0)
	{
		total += ft_putchar('-');
		num = -nl;
	}
	if (num >= 10)
		total += print_number(num / 10);
	total += ft_putchar((num % 10) + '0');
	return (total);
}