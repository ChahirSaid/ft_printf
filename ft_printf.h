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

int	check_format(const char *str);
int	print_invalid_format(const char *str, int *pos);

int		_putchar(char c, t_flag flag);
int		ft_printstr(char *str, t_flag flag);
int		ft_printpointer(void *ptr, t_flag flag);
int		ft_printnum(long nl, t_flag flag);
int		ft_printunum(unsigned long nl, t_flag flag);
int		ft_printbnum(int nl, int isupper, t_flag flag);

int		ft_strlen(char *str);
int		ft_atoi(const char *str, int *o_pos);
int		print_str(char *str);
int		ft_putchar(char c);
int		in_set(char c, char *set);
int		print_number(long nl);
void	init_flag(t_flag *flag);

#endif
