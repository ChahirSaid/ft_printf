#include "ft_printf.h"

void	process_flags(t_flag *flag, const char *str, int *pos)
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


int	handle_specifier(const char *str, va_list *params, t_flag flag, int *args_used)
{
	int	total;

	total = 0;
	*args_used = 1;
	if (str[1] == 'c')
		total += _putchar(va_arg(*params, int), flag);
	else if (str[1] == 's')
		total += ft_printstr(va_arg(*params, char *), flag);
	else if (str[1] == 'p')
		total += ft_printpointer(va_arg(*params, void *), flag);
	else if (str[1] == 'd' || str[1] == 'i')
		total += ft_printnum(va_arg(*params, int), flag);
	else if (str[1] == 'u')
		total += ft_printunum(va_arg(*params, unsigned int), flag);
	else if (str[1] == 'x' || str[1] == 'X')
		total += ft_printbnum(va_arg(*params, int), (str[1] == 'X'), flag);
	else if (str[1] == '%')
	{
		total += ft_putchar('%');
		*args_used = 0;
	}
	else
		return (-1);
	return (total);
}

int	process(const char *str, va_list *params, int *pos)
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
	while (in_set(str[(*pos) + 1], "0123456789# +-.")) 
	{
		if (in_set(str[(*pos) + 1], "# +0-.")) 
			process_flags(&flag, str + (*pos), pos);
		else 
		{
			flag.min_width = ft_atoi(str + (*pos) + 1, pos);
			(*pos)--;
		}
		(*pos)++;
	}
	total += handle_specifier(str + (*pos), params, flag, &args_used);
	(*pos)++;
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		pos;
	int		total;
	int		temp;

	if (!str)
		return (-1);
	pos = 0;
	total = 0;
	va_start(params, str);
	while (str[pos])
	{
		if (str[pos] == '%')
		{
			temp = process(str, &params, &pos);
			if (temp == -1) 
				return (va_end(params), -1);
			total += temp;
		}
		else
			total += ft_putchar(str[pos]);
		pos++;
	}
	va_end(params);
	return (total);
}
