/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:24:47 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/23 12:07:31 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = a->content;
	bits = 0;
	while (a)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix(t_stack **a, t_stack **b, int size)
{
	int	bits;
	int	i;
	int	i2;

	bits = ft_max_bits(*a);
	i = 0;
	while (i < bits)
	{
		i2 = 0;
		while (i2 < size)
		{
			if (((*a)->content >> i) & 1)
				ft_rx(a, 'a');
			else
				ft_px(a, b, 'b');
			i2++;
		}
		while (*b)
			ft_px(a, b, 'a');
		i++;
	}
	print_stack(*a);
}
