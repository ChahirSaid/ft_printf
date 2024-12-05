#include "ft_printf.h"

void	handle_flags(t_flag *flag, const char *str, int *pos)
{
	if (str[1] == '#')
		flag->sharp = 1;
	else if (str[1] == ' ')
		flag->space = 1;
	else if (str[1] == '+')
		flag->plus = 1;
	else if (str[1] == '0')
	{
		flag->zero_offset = ft_atoi(str + 2, pos);
		flag->zero = 1;
	}
	else if (str[1] == '-')
	{
		flag->offset = ft_atoi(str + 2, pos);
		flag->minus = 1;
	}
	else if (str[1] == '.')
	{
		flag->precision = ft_atoi(str + 2, pos);
		flag->dot = 1;
	}
}

int	handle_spec(const char *str, va_list *args, t_flag flag, int *args_used)
{
	int	total;

	total = 0;
	*args_used = 1;
	if (str[1] == 'c')
		total += ft_putchar(va_arg(*args, int), flag);
	else if (str[1] == 's')
		total += ft_putstr(va_arg(*args, char *), flag);
	else if (str[1] == 'p')
		total += ft_putptr(va_arg(*args, void *), flag);
	else if (str[1] == 'd' || str[1] == 'i')
		total += ft_putnbr(va_arg(*args, int), flag);
	else if (str[1] == 'u')
		total += ft_putunbr(va_arg(*args, unsigned int), flag);
	else if (str[1] == 'x' || str[1] == 'X')
		total += ft_puthex(va_arg(*args, int), (str[1] == 'X'), flag);
	else if (str[1] == '%')
	{
		total += ft_put_char('%');
		*args_used = 0;
	}
	else
		return (-1);
	return (total);
}

int	process(const char *str, va_list *args, int *pos)
{
	int		total;
	t_flag	flag;
	int		args_used;

	total = 0;
	init_flag(&flag);
	args_used = 0;
	if (str[(*pos) + 1] == '\0')
		return (-1);
	if (!check_format(str + (*pos)))
		return (total += print_invalid_format(str + (*pos), pos), total);
	while (ft_strchr(str[(*pos) + 1], "0123456789# +-."))
	{
		if (ft_strchr(str[(*pos) + 1], "# +0-."))
			handle_flags(&flag, str + (*pos), pos);
		else
		{
			flag.min_width = ft_atoi(str + (*pos) + 1, pos);
			(*pos)--;
		}
		(*pos)++;
	}
	total += handle_spec(str + (*pos), args, flag, &args_used);
	(*pos)++;
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		pos;
	int		total;
	int		temp;

	if (!str)
		return (-1);
	pos = 0;
	total = 0;
	va_start(args, str);
	while (str[pos])
	{
		if (str[pos] == '%')
		{
			temp = process(str, &args, &pos);
			if (temp == -1)
				return (va_end(args), -1);
			total += temp;
		}
		else
			total += ft_put_char(str[pos]);
		pos++;
	}
	va_end(args);
	return (total);
}
