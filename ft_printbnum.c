#include "ft_printf.h"

static int	print_number_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nbrl;
	int				total;

	total = 0;
	nbrl = nbr;
	base_len = ft_strlen(base);
	if (nbrl >= base_len)
	{
		total += print_number_base(nbrl / base_len, base);
		total += print_number_base(nbrl % base_len, base);
	}
	else
	{
		total += ft_putchar(base[nbrl]);
	}
	return (total);
}

static int	get_hex_size(int nbr)
{
	int				total;
	unsigned int	nbrl;

	total = 0;
	nbrl = nbr;
	if (nbrl >= 16)
	{
		total += get_hex_size(nbrl / 16);
		total += get_hex_size(nbrl % 16);
	}
	else
		total++;
	return (total);
}

static int	get_values(char	*prefix, int *len_prec, t_flag *flag, int nbr)
{
	int		len;

	len = get_hex_size(nbr);
	*len_prec = len;
	if (flag->precision > len)
		*len_prec = flag->precision;
	*prefix = '0';
	if (flag->zero && flag->dot && flag->zero_offset > flag->precision)
		*prefix = ' ';
	if (!flag->zero)
		*prefix = ' ';
	if (flag->zero)
		flag->min_width = flag->zero_offset;
	if (flag->precision > flag->min_width)
		flag->min_width = flag->precision;
	return (len);
}

static int	print_x(int isupper, int len, int nbr, t_flag flag)
{
	int	total;

	total = 0;
	if (nbr == 0 && flag.min_width && flag.min_width < len)
		total += ft_putchar(' ');
	else if (nbr == 0 && flag.dot && !flag.precision && flag.min_width >= len)
		total += ft_putchar(' ');
	else if (!(nbr == 0 && flag.dot && !flag.precision))
	{
		if (isupper)
			total += print_number_base(nbr, "0123456789ABCDEF");
		else
			total += print_number_base(nbr, "0123456789abcdef");
	}
	return (total);
}

int	ft_printbnum(int nbr, int isupper, t_flag flag)
{
	int		total;
	int		len;
	char	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &flag, nbr);
	while (len_prec + total < flag.min_width)
		total += ft_putchar(prefix);
	while (len + total < flag.min_width)
		total += ft_putchar('0');
	if (flag.sharp && nbr != 0)
	{
		if (isupper)
			total += print_str("0X");
		else
			total += print_str("0x");
	}
	total += print_x(isupper, len, nbr, flag);
	while (total < flag.offset)
		total += ft_putchar(' ');
	return (total);
}
