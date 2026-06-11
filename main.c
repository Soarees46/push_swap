/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 11:37:40 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	ft_rx(int *stk, int tam);
void	ft_rrx(int *stk, int tam);
void	ft_sx(int	*stk);

int	main()
{
	int n1[] = {1, 2, 3, 4, 5};
	int	i;

	ft_sx(n1);
	i = 0;
	while (i < 5)
		printf("%d", n1[i++]);
	
}
