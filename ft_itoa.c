#include "ft_printf.h"

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
