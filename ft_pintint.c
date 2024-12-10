#include "ft_printf.h"

static char	plus(t_format flag)
{
	if (flag.plus)
		return ('+');
	return ('-');
}

static int	ft_strncmp(const char *s1, const char *s2, size_t t)
{
	size_t	i;

	i = 0;
	if (t == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < t - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

static int	ft_printnbr(t_format flag, char *nb, int len, int is_neg)
{
	int	t;

	t = 0;
	flag.wdth -= (flag.space && !is_neg && !flag.plus && flag.wdth);
	if (is_neg || flag.plus)
		t += ft_putnchar(plus(flag), flag.zero && (!flag.dot
					|| flag.prec_negative));
	else if (flag.space)
		t += ft_putnchar(' ', flag.zero && !flag.dot);
	if (!flag.minus && flag.wdth > flag.precision && (!flag.dot
			|| flag.prec_negative) && flag.zero)
		t += ft_putnchar('0', flag.wdth - flag.precision - is_neg - flag.plus);
	else if (!flag.minus && flag.wdth > flag.precision)
		t += ft_putnchar(' ', flag.wdth - flag.precision - is_neg - flag.plus);
	if ((is_neg || flag.plus) && ft_strncmp(nb, "-2147483648", 12))
		t += ft_putnchar(plus(flag), !flag.zero || (flag.dot
					&& !flag.prec_negative));
	else if (flag.space && ft_strncmp(nb, "-2147483648", 12))
		t += ft_putnchar(' ', !flag.zero || flag.dot);
	t += ft_putnchar('0', flag.precision - len);
	t += write(1, nb, len);
	if (flag.minus && flag.wdth > flag.precision)
		t += ft_putnchar(' ', flag.wdth - flag.precision - is_neg - flag.plus);
	return (t);
}

int	ft_printint(t_format flag, va_list args)
{
	char	*nb;
	int		n;
	int		t;
	int		len;
	int		is_neg;

	t = 0;
	n = va_arg(args, int);
	is_neg = (n < 0 && n != INT_MIN && flag.specifier != 'u');
	if (is_neg)
		flag.plus = 0;
	if (n < 0 && flag.specifier != 'u')
		n *= -1;
	if (n < 0 && flag.specifier == 'u')
		nb = ft_uitoa((unsigned)n);
	else
		nb = ft_itoa(n);
	len = ft_strlen(nb);
	if (*nb == '0' && !flag.precision && flag.dot)
		len = 0;
	if (flag.precision < len || !flag.dot)
		flag.precision = len;
	t += ft_printnbr(flag, nb, len, is_neg);
	free(nb);
	return (t);
}