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

static t_ops	bring_min_to_top(t_stack **a, int min, t_ops ops)
{
	int	pos;
	int	size;

	if (!*a)
		return (ops);
	pos = get_position(*a, min);
	if (pos == -1)
		return (ops);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (*a && (*a)->content != min)
			ops.ra += ft_rx(a, 'a');
	}
	else
	{
		while (*a && (*a)->content != min)
			ops.rra += ft_rrx(a, 'a');
	}
	return (ops);
}

t_ops	ft_simple(t_stack **a, t_stack **b)
{
	int		min;
	t_ops	ops;

	ops = (t_ops){0};
	while (*a)
	{
		min = find_min(*a);
		ops = bring_min_to_top(a, min, ops);
		ops.pb += ft_px(a, b, 'b');
	}
	while (*b)
		ops.pa += ft_px(b, a, 'a');
	ops.total = (ops.pa + ops.pb + ops.rra + ops.ra);
	return (ops);
}
