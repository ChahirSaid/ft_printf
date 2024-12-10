/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:29 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:25:23 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * init_flag - Initialize formatting flags structure to default values
 *
 * @format: Pointer to formatting flags structure
 */
void	init_flag(t_format *format)
{
	format->sharp = 0;
	format->space = 0;
	format->plus = 0;
	format->wdth = 0;
	format->prec_negative = 0;
	format->precision = 0;
	format->dot = 0;
	format->zero = 0;
	format->minus = 0;
	format->specifier = 0;
}

/**
 * ft_atoi - Convert string to integer
 *
 * @str: String to convert
 *
 * Returns: Converted integer value
 */
int	ft_atoi(const char *str)
{
	int		sign;
	long	nb;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (sign * nb);
}

/**
 * ft_strchr - Find first occurrence of a character in a string
 *
 * @str: String to search
 * @c: Character to find
 *
 * Returns: Pointer to first occurrence of character, or NULL if not found
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}

/**
 * ft_strlen - Calculate length of a string
 *
 * @str: String to measure
 *
 * Returns: Number of characters in the string
 */
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
