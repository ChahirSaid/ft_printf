/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:44:49 by schahir           #+#    #+#             */
/*   Updated: 2024/11/08 19:51:49 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *format, ...);
int ft_putptr(void *p);
int ft_putbhex(unsigned int n);
int ft_puthex(unsigned int n);
int ft_putunsnbr(unsigned int n);
int ft_putnbr(int n);
int ft_putstr(const char *str);
int ft_putchar(char c);

#endif/*LIBFTPRINTF_H*/