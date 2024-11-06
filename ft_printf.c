/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:55:53 by schahir           #+#    #+#             */
/*   Updated: 2024/11/05 22:47:37 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1,&c,1));
}

int ft_putstr(const char *str)
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

int	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
unsigned int ft_putunsnbr(unsigned int n)
{
	long	nb;

	nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
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
			{
				count += ft_putchar((char)va_arg(args, int));
				format++;
			}
			else if (*format == 's')
			{
                count += ft_putstr(va_arg(args, const char *));
				format++;
			}
			else if (*format == '%')
				count += ft_putchar('%');
			else if (*format == 'd' || *format == 'i')
			{
				count += ft_putnbr(va_arg(args, int));
				format++;
			}
			else if (*format == 'u')
			{
				count += ft_putunsnbr(va_arg(args,unsigned int));
				format++;
			}
			else
				count += ft_putchar(*format++);
		}
		else
				count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}
int main()
{
	ft_printf("hello % %s %c %u \" \n","hello", 'c', -12);
}