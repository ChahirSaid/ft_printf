/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:55:53 by schahir           #+#    #+#             */
/*   Updated: 2024/11/08 19:56:48 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putchar(char c)
{
	return (write(1, &c, 1));
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
	return i;
}

int ft_putnbr(int n)
{
	long nb = n;
	int count = 0;	
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		count++;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	count++;
	return count;
}

int ft_putunsnbr(unsigned int n)
{
	long nb = n;
	int count = 0;
	
	if (nb > 9)
		count += ft_putunsnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	count++;
	return count;
}

int ft_puthex(unsigned int n)
{
	char hex_digits[] = "0123456789abcdef";
	int count = 0;

	if (n >= 16)
		count += ft_puthex(n / 16);
	ft_putchar(hex_digits[n % 16]);
	count++;
	return count;
}


int ft_putbhex(unsigned int n)
{
	char hex_digits[] = "0123456789ABCDEF";
	int count = 0;

	if (n >= 16)
		count += ft_putbhex(n / 16);
	ft_putchar(hex_digits[n % 16]);
	count++;
	return count;
}

int ft_putptr(void *p)
{
	unsigned long ptr = (unsigned long)p;
	char hex_digits[] = "0123456789abcdef";
	int count = 0;

	if (p == NULL)
	{
		count += ft_putstr("(nil)");
		return count;
	}
	if (ptr >= 16)
		count += ft_putptr((void *)(ptr / 16));
	ft_putchar(hex_digits[ptr % 16]);
	count++;
	return count;
}

int ft_printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	if (!format)
		return -1;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
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
			{
				count += ft_putchar('%');
				format++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				count += ft_putnbr(va_arg(args, int));
				format++;
			}
			else if (*format == 'u')
			{
				count += ft_putunsnbr(va_arg(args, unsigned int));
				format++;
			}
			else if (*format == 'x')
			{
				count += ft_puthex(va_arg(args, int));
				format++;
			}
			else if (*format == 'X')
			{
				count += ft_putbhex(va_arg(args, int));
				format++;
			}
			else if (*format == 'p')
			{
				count += ft_putstr("0x");
			    count += ft_putptr(va_arg(args, void *));
				format++;
			}
			else
			{
				count += ft_putchar(*format++);
			}
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(args);
	return count;
}

int main()
{
	int a = 1337;
	int *ptr = NULL;
	ft_printf("hello %s  %% %s %c %u %x %X %p %p \" \n",NULL, "hello", 'c', -12, -34, 255, &a, ptr);
}
