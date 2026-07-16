/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunck_based.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 11:03:08 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/16 11:53:19 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	ft_first_loop(t_stack **a, t_stack **b, int chunk, t_ops *ops)
{
	int		low;
	int		high;

	low = 0;
	high = chunk;
	while (*a != NULL)
	{
		if (*a == NULL)
			break ;
		if ((*a)->content <= high)
		{
			ops->pb += ft_px(a, b, 'b');
			if ((*b)->content < low - chunk / 2)
				ops->rb += ft_rx(b, 'b');
			low++;
			if (low > high)
				high += chunk;
		}
		else
			ops->ra += ft_rx(a, 'a');
	}
}

void	bring_max_to_top(t_stack **b, int max, t_ops *ops)
{
	int	pos;
	int	size;

	if (!*b)
		return ;
	pos = get_position(*b, max);
	size = stack_size(*b);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while (*b && (*b)->content != max)
			ops->rb += ft_rx(b, 'b');
	}
	else
	{
		while (*b && (*b)->content != max)
			ops->rrb += ft_rrx(b, 'b');
	}
}

t_ops	ft_chunck_based(t_stack **a, t_stack **b, int size)
{
	t_ops	ops;
	int		chunk;

	ops = (t_ops){0};
	chunk = ft_sqrt(size);
	ft_index_stack(*a);
	ft_first_loop(a, b, chunk, &ops);
	while (*b)
	{
		bring_max_to_top(b, find_max(*b), &ops);
		ops.pa += ft_px(b, a, 'a');
	}
	ops.total = (ops.pb + ops.rb + ops.ra + ops.pa);
	return (ops);
}
