#include "ft_printf.h"

int	check_format(const char *str)
{
	int	dots;
	int	i;

	dots = 0;
	i = 1;
	if (str[1] == '\0')
		return (0);
	while (str[i] && ft_strchr(str[i], "# +0-"))
		i++;
	while (str[i] && (str[i] == '.' || (str[i] >= '0' && str[i] <= '9')))
	{
		if (str[i] == '.')
		{
			dots++;
			if (str[i + 1] == '.')
				return (0);
		}
		i++;
	}
	if (dots > 1 || !ft_strchr(str[i], "cspdiuxX%"))
		return (0);
	return (1);
}

int	print_invalid_format(const char *str, int *pos)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (str[i] && !(ft_strchr(str[i], "cspdiuxX%")))
	{
		total += ft_put_char(str[i]);
		i++;
	}
	if (str[i])
		total += ft_put_char(str[i]);
	*pos += i;
	return (total);
}
