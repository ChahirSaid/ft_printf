#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1,&c,1));
}
int ft_putstr(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
int	ft_printf(const char *format, ...)
{
	int count = 0;

	va_list args;
	va_start(args, format);
	if(!format)
		return(-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 'c')
				count += ft_putchar((char)va_arg(args, int));
			else if (*format == 's')
                count += ft_putstr(va_arg(args, const char *));
			else if (*format == '%')
				count += ft_putchar('%');
			else
				count += ft_putchar(*format++);
		}
		else
				count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}