#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static t_format	handle_flags(char *str, t_format flag)
{
	while (*str != '.' && !ft_strchr(SPEC, *str))
	{
		if (*str == '+')
			flag.plus = 1;
		if (*str == ' ')
			flag.space = 1;
		if (*str == '#')
			flag.sharp = 1;
		str++;
	}
	return (flag);
}

static t_format	handle_width(char *str, t_format flag)
{
	int	is_set;

	is_set = 0;
	while (*str != '.' && !ft_strchr(SPEC, *str))
	{
		if (*str == '-')
			flag.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			flag.zero = 1;
		else if ((*str > '0' && *str <= '9') && !is_set)
		{
			flag.wdth = ft_atoi(str);
			is_set = 1;
		}
		str++;
	}
	return (flag);
}

static t_format	handle_precision(char *str, t_format flag)
{
	int	is_set;

	is_set = 0;
	while (!ft_strchr(SPEC, *str))
	{
		if (ft_isdigit(*str) && !is_set)
		{
			flag.precision = ft_atoi(str);
			is_set = 1;
		}
		str++;
	}
	return (flag);
}

int	process(char *str, va_list args)
{
	t_format	format;

	init_flag(&format);
	format = handle_width(str, format);
	format = handle_flags(str, format);
	while (!ft_strchr(SPEC, *str) && *str != '.')
		str++;
	if (*str == '.' && !format.specifier)
	{
		format.dot = 1;
		format = handle_precision(str++, format);
		while (!ft_strchr(SPEC, *str))
			str++;
	}
	if (format.wdth < 0)
	{
		format.minus = 1;
		format.wdth *= -1;
	}
	format.specifier = *str;
	format.prec_negative = format.precision < 0;
	return (handle_specifier(format, args));
}
