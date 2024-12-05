#include "ft_printf.h"

static int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nb;
	int				total;

	total = 0;
	nb = nbr;
	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		total += ft_putnbr_base(nb / base_len, base);
		total += ft_putnbr_base(nb % base_len, base);
	}
	else
	{
		total += ft_put_char(base[nb]);
	}
	return (total);
}

static int	ft_hexlen(int nbr)
{
	int				total;
	unsigned int	nb;

	total = 0;
	nb = nbr;
	if (nb >= 16)
	{
		total += ft_hexlen(nb / 16);
		total += ft_hexlen(nb % 16);
	}
	else
		total++;
	return (total);
}

static int	get_values(char	*prefix, int *len_prec, t_flag *flag, int nbr)
{
	int		len;

	len = ft_hexlen(nbr);
	*len_prec = len;
	if (flag->precision > len)
		*len_prec = flag->precision;
	*prefix = ' ';
	if (flag->zero && (!flag->dot || flag->zero_offset > flag->precision))
		*prefix = '0';
	if (flag->zero)
		flag->min_width = flag->zero_offset;
	if (flag->precision > flag->min_width)
		flag->min_width = flag->precision;
	return (len);
}

static int	print_x(int isupper, int len, int nbr, t_flag flag)
{
	char	*base;

	if (nbr == 0 && ((flag.min_width && flag.min_width < len)
			|| (flag.dot && !flag.precision && flag.min_width >= len)))
		return (ft_put_char(' '));
	if (nbr == 0 && flag.dot && !flag.precision)
		return (0);
	if (isupper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_putnbr_base(nbr, base));
}

int	ft_puthex(int nbr, int isupper, t_flag flag)
{
	int		total;
	int		len;
	char	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &flag, nbr);
	while (len_prec + total < flag.min_width)
		total += ft_put_char(prefix);
	while (len + total < flag.min_width)
		total += ft_put_char('0');
	if (flag.sharp && nbr != 0)
	{
		if (isupper)
			total += print_str("0X");
		else
			total += print_str("0x");
	}
	total += print_x(isupper, len, nbr, flag);
	while (total < flag.offset)
		total += ft_put_char(' ');
	return (total);
}
