#include "ft_printf.h"

/**
 * ft_putnbr_base - Recursively prints a number in a given base
 *
 * @nbr: Number to print
 * @base: Character set representing the base
 *
 * @return: Total number of characters printed
 */
static int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				total;

	total = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		total += ft_putnbr_base(nbr / base_len, base);
	total += ft_put_char(base[nbr % base_len]);
	return (total);
}

/**
 * ft_hexlen - Calculates the number of digits in a hexadecimal representation
 *
 * @nbr: Number to calculate hex length for
 *
 * @return: Number of hexadecimal digits
 */
static int	ft_hexlen(unsigned int nbr)
{
	int	total;

	total = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		total++;
	}
	return (total);
}

/**
 * ft_puthex - Prints a number in hexadecimal format
 *			with comprehensive formatting
 *
 * @nbr: Number to print in hex
 * @isupper: Flag to determine uppercase (X) or lowercase (x)
 * @flag: Formatting flags
 *
 * @return: Total number of characters printed
 */
int	ft_puthex(unsigned int nbr, int isupper, t_flag flag)
{
	int		total;
	int		len;
	int		len_prec;
	int		len_with_prefix;
	char	prefix;
	char	*base;

	total = 0;
	len = ft_hexlen(nbr);
	len_with_prefix = len;
	if (flag.sharp && nbr != 0)
		len_with_prefix += 2;
	len_prec = (flag.precision > len) ? flag.precision : len;
	prefix = (flag.zero && !flag.dot) ? '0' : ' ';
	base = isupper ? "0123456789ABCDEF" : "0123456789abcdef";
	while (prefix == ' ' && len_with_prefix + total < flag.min_width)
		total += ft_put_char(' ');
	if (flag.sharp && nbr != 0)
		total += print_str(isupper ? "0X" : "0x");
	while (len_prec > len)
	{
		total += ft_put_char('0');
		len_prec--;
	}
	total += ft_putnbr_base(nbr, base);
	while (total < flag.min_width)
		total += ft_put_char(' ');
	return (total);
}
