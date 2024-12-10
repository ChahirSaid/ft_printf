/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:23:52 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:23:53 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_intlen - Calculate length of an integer
 * 
 * @n: Input integer
 * 
 * Returns: Number of digits in the integer
 */
static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		if (n == 0)
			return (1);
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * ft_uintlen - Calculate length of an unsigned integer
 * 
 * @n: Input unsigned integer
 * 
 * Returns: Number of digits in the unsigned integer
 */
static size_t	ft_uintlen(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * fill_str - Fill string with digits of a number
 * 
 * @str: Output string
 * @n: Number to convert
 * @len: Length of the string
 */
static void	fill_str(char *str, long n, size_t len)
{
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return ;
	}
	while (n > 0)
	{
		str[--len] = 48 + (n % 10);
		n /= 10;
	}
}

/**
 * ft_itoa - Convert integer to string
 * 
 * @nb: Input integer
 * 
 * Returns: Dynamically allocated string representation of the integer
 */
char	*ft_itoa(int nb)
{
	long	n;
	size_t	len;
	char	*str;

	n = nb;
	len = ft_intlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		fill_str(str + 1, n, len - 1);
	}
	else
		fill_str(str, n, len);
	return (str);
}

/**
 * ft_uitoa - Convert unsigned integer to string
 * 
 * @nb: Input unsigned integer
 * 
 * Returns: Dynamically allocated string representation of the unsigned integer
 */
char	*ft_uitoa(unsigned int nb)
{
	unsigned long	n;
	size_t			len;
	char			*str;

	n = nb;
	len = ft_uintlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	fill_str(str, n, len);
	return (str);
}
