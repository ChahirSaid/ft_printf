#include "ft_printf.h"

/**
 * print_minus - Handles negative number sign printing
 *
 * @nl: Pointer to number, modified to positive
 * @len: Pointer to length, adjusted for sign
 * @flag: Formatting flags
 *
 * @return: Always 1 (for the printed minus sign)
 */
static int	print_minus(long *nb, int *len, t_flag flag)
{
	ft_put_char('-');
	*nb = -*nb;
	(*len)--;
	if (flag.dot)
		(*len)--;
	return (1);
}

/**
 * ft_intlen - Calculates number of digits in a number
 *
 * @num: Number to count digits for
 *
 * @return: Number of digits (including sign for negative numbers)
 */
static int	ft_intlen(long num)
{
	int	pos;

	pos = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		pos++;
	while (num != 0)
	{
		num = num / 10;
		pos++;
	}
	return (pos);
}

/**
 * get_values - Prepares values for number printing with formatting
 *
 * @prefix: Pointer to store padding character
 * @len_prec: Pointer to store precision length
 * @flag: Formatting flags
 * @nl: Number to be printed
 *
 * @return: Actual length of the number
 */
static int	get_values(char *prefix, int *len_prec, t_flag *flag, long nb)
{
	int	len;

	len = ft_intlen(nb);
	*len_prec = len;
	if (flag->precision > len)
		*len_prec = flag->precision;
	if (nb < 0)
	{
		if (flag->zero_offset > len && flag->precision > len)
			(*len_prec)++;
		if (flag->dot && flag->precision < flag->zero_offset)
			len++;
	}
	*prefix = ' ';
	if (flag->zero && (!flag->dot || flag->zero_offset > flag->precision))
		*prefix = '0';
	if (flag->zero)
		flag->min_width = flag->zero_offset;
	if (flag->precision > flag->min_width)
		flag->min_width = flag->precision;
	return (len);
}

/**
 * print_di - Prints a decimal or integer number with specific formatting
 *
 * @len: Length of the number
 * @nl: Number to print
 * @flag: Formatting flags
 *
 * @return: Number of characters printed
 */
static int	print_di(int len, long nb, t_flag flag)
{
	if (nb == 0 && ((flag.min_width && flag.min_width < len) || (flag.dot
				&& !flag.precision && flag.min_width >= len)))
		return (ft_put_char(' '));
	if (nb == 0 && flag.dot && !flag.precision)
		return (0);
	return (putnbr(nb));
}

/**
 * ft_putnbr - Prints a number with comprehensive formatting
 *
 * @nl: Number to print
 * @flag: Formatting flags
 *
 * @return: Total number of characters printed
 */
int	ft_putnbr(long nb, t_flag flag)
{
	int		total;
	int		len;
	char	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &flag, nb);
	while (prefix == ' ' && len_prec + total < flag.min_width)
		total += ft_put_char(' ');
	if (nb < 0)
		total += print_minus(&nb, &len, flag);
	else if (flag.space && nb >= 0 && !flag.plus && !flag.dot)
		total += ft_put_char(' ');
	else if (flag.plus && nb >= 0 && !flag.dot)
		total += ft_put_char('+');
	while (len + total < flag.min_width)
		total += ft_put_char('0');
	total += print_di(len, nb, flag);
	while (total < flag.offset)
		total += ft_put_char(' ');
	return (total);
}
