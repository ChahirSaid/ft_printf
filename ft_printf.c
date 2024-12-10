#include "ft_printf.h"

int	handle_specifier(t_format flag, va_list args)
{
	int	total;

	total = 0;
	if (flag.specifier == 'c')
		total = ft_printchar(flag, args);
	if (flag.specifier == 's')
		total = ft_printstr(flag, args);
	if (flag.specifier == 'd' || flag.specifier == 'i' || flag.specifier == 'u')
		total = ft_printint(flag, args);
	if (flag.specifier == 'X' || flag.specifier == 'x')
		total = ft_printhex(flag, args);
	if (flag.specifier == 'p')
		total = ft_printptr(flag, args);
	if (flag.specifier == '%')
		return (ft_putchar('%'));
	return (total);
}

int	validate_format(const char *format)
{
	int	i;

	i = 0;
	if (format[i] != '%')
		return (0);
	i++;
	while (format[i] && ft_strchr("-+ #0", format[i]))
		i++;
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		i++;
		while (format[i] && ft_isdigit(format[i]))
			i++;
	}
	if (!ft_strchr(SPEC, format[i]))
		return (0);
	return (1);
}

static int	process_format(const char **str, va_list args)
{
	int			total;
	const char	*start = *str;

	total = 0;
	if (!validate_format(start))
	{
		total += write(1, start, 1);
		(*str)++;
		return (total);
	}
	(*str)++;
	total += process((char *)*str, args);
	while (**str && !ft_strchr(SPEC, **str))
		(*str)++;
	if (**str)
		(*str)++;
	return (total);
}

int	ft_printf(const char *str, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			total += process_format(&str, args);
		else
			total += ft_putchar(*str++);
	}
	va_end(args);
	return (total);
}
