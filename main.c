/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:36:31 by schahir           #+#    #+#             */
/*   Updated: 2024/12/07 14:49:05 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int	x;
	int	y;

	printf("copy%d\n", ft_printf("|%10.5i|", -216));
	printf("original%d\n", printf("|%10.5i|", -216));
	/*
	a = 58;
	// scanf("%d", &a);
	x = printf("|%#17.5x|", a);
	printf("\n");
	y = ft_printf("|%#17.5x|", a);
	printf("\n Expected %d to deeply equal to %d\n", x, y);
	*/
}

/*int main()
{
	int	a;
	int	x;
	int	y;

		a = -58;
	//scanf("%d", &a);
	x = printf("|%10.5d|", a);
	printf("\n");
	y = ft_printf("|%10.5d|", a);
	printf("\n Expected %d to deeply equal to %d", x, y);
}

int	main(void)
{
		int a;
	int	x;
	int	y;

	scanf("%d", &a);
	x = printf("|%+10.7d|", a);
	printf("\n");
	y = ft_printf("|%+10.7d|", a);
	printf("\n Expected %d to deeply equal to %d", x, y);
}
int	main(void)
{
		int a;
	scanf("%d", &a);
	int x = printf("|%+10.7d|", a);
	printf("\n");
	int y = ft_printf("|%+10.7d|", a);
	printf("\n Expected %d to deeply equal to %d", x, y);
}*/