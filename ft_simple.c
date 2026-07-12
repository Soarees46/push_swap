/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:36:42 by calberto          #+#    #+#             */
/*   Updated: 2026/06/22 10:58:36 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bring_min_to_top(t_stack **a, int min)
{
	int	pos;
	int	size;
	int	total;

	pos = get_position(*a, min);
	size = stack_size(*a);
	total = 0;
	if (pos <= size / 2)
	{
		while ((*a)->content != min)
			total += ft_rx(a, 'a');
	}
	else
	{
		while ((*a)->content != min)
			total += ft_rrx(a, 'a');
	}
	return (total);
}

int	ft_simple(t_stack **a, t_stack **b)
{
	int	min;
	int	total;

	total = 0;
	while (*a)
	{
		min = find_min(*a);
		total += bring_min_to_top(a, min);
		total += ft_px(a, b, 'b');
	}
	while (*b)
		total += ft_px(b, a, 'a');
	return (total);
}
