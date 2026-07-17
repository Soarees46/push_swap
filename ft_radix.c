/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:24:47 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/17 11:20:26 by vaugusto         ###   ########.fr       */
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

void	ft_index_stack(t_stack *stk)
{
	t_stack	*tmp;
	t_stack	*cmp;
	t_stack	*save;
	int		rank;
	int		value;

	tmp = stk;
	save = ft_stack_copy(stk);
	while (tmp)
	{
		value = tmp->content;
		rank = 0;
		cmp = save;
		while (cmp)
		{
			if (value > cmp->content)
				rank++;
			cmp = cmp->next;
		}
		tmp->content = rank;
		tmp = tmp->next;
	}
	ft_free_stack(&save);
}

t_ops	ft_radix(t_stack **a, t_stack **b, int size)
{
	int		bits;
	int		i;
	int		i2;
	t_ops	ops;

	bits = ft_max_bits(*a);
	ft_index_stack(*a);
	ops = (t_ops){0};
	i = -1;
	while (++i < bits)
	{
		i2 = 0;
		while (i2 < size && *a)
		{
			if (((*a)->content >> i) & 1)
				ops.ra += ft_rx(a, 'a');
			else
				ops.pb += ft_px(a, b, 'b');
			i2++;
		}
		while (*b)
			ops.pa += ft_px(b, a, 'a');
	}
	ops.total = (ops.ra + ops.pb + ops.pa);
	return (ops);
}
