#include "ft_printf.h"

int	print_str(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
		write(1, &str[pos++], 1);
	return (pos);
}

static int	print_str_size(char *str, int size)
{
	int	pos;

	if (size == -1)
		return (print_str(str));
	pos = 0;
	while (str[pos] && pos < size)
		write(1, &str[pos++], 1);
	return (pos);
}

int	ft_putstr(char *str, t_flag flag)
{
	int	pos;
	int	len;

	pos = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	while (pos + len < flag.min_width)
		pos += ft_put_char(' ');
	if (!flag.dot)
		flag.precision = -1;
	if (!str)
		pos += print_str_size("(null)", flag.precision);
	else
		pos += print_str_size(str, flag.precision);
	while (pos < flag.offset)
		pos += ft_put_char(' ');
	return (pos);
}
