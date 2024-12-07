#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	int	sharp;
	int	space;
	int	plus;
	int	min_width;
	int	minus;
	int	dot;
	int	precision;
	int	offset;
	int	zero;
	int	zero_offset;
}		t_flag;

int		ft_printf(const char *str, ...);

int		check_format(const char *str);
int		print_invalid_format(const char *str, int *pos);

int		ft_putchar(char c, t_flag flag);
int		ft_putstr(char *str, t_flag flag);
int		ft_putptr(void *ptr, t_flag flag);
int		ft_putnbr(long nb, t_flag flag);
int		ft_putunbr(unsigned long nb, t_flag flag);
int	ft_puthex(unsigned int nbr, int isupper, t_flag flag);

void	init_flag(t_flag *flag);
int		ft_strchr(char c, char *set);
int		ft_atoi(const char *str, int *o_pos);
int		ft_strlen(char *str);
int		ft_put_char(char c);
int		print_str(char *str);
int		putnbr(long nb);

#endif
