#include "ft_printf.h"

int	print_str(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
		write(1, &str[pos++], 1);
	return (pos);
}

static int	putstr_size(char *str, int size)
{
	int	pos;

	pos = 0;
	if (size == -1)
		return (print_str(str));
	while (str[pos] && pos < size)
		write(1, &str[pos++], 1);
	return (pos);
}

static int	handle_null_str(t_flag flag)
{
	if (!flag.dot || flag.precision < 0)
		return (putstr_size("(null)", -1));
	if (flag.precision < 6)
		return (0);
	return (putstr_size("(null)", 6));
}

int	ft_putstr(char *str, t_flag flag)
{
	int	pos;
	int	len;
	int	padding_before;
	int	padding_after;

	pos = 0;
	if (!str)
	{
		len = handle_null_str(flag);
		padding_before = flag.min_width - len;
		while (padding_before-- > 0)
			pos += ft_put_char(' ');
		pos += len;
		return (pos);
	}
	else
		len = ft_strlen(str);
	if (flag.dot && flag.precision < len)
		len = flag.precision;
	padding_before = flag.min_width - len;
	while (padding_before-- > 0)
		pos += ft_put_char(' ');
	pos += putstr_size(str, len);
	padding_after = flag.offset - pos;
	while (padding_after-- > 0)
		pos += ft_put_char(' ');
	return (pos);
}
