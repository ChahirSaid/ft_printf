#include "ft_printf.h"

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
