/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:24:47 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/26 10:09:08 by vaugusto         ###   ########.fr       */
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
}

void	ft_radix(t_stack **a, t_stack **b, int size)
{
	int	bits;
	int	i;
	int	i2;

	bits = ft_max_bits(*a);
	ft_index_stack(*a);
	print_stack(*a); //REMOVER 
	i = 0;
	while (i < bits)
	{
		i2 = 0;
		while (i2 < size && *a)
		{
			if (((*a)->content >> i) & 1)
				ft_rx(a, 'a');
			else
				ft_px(a, b, 'b');
			i2++;
		}
		while (*b)
			ft_px(b, a, 'a');
		i++;
	}
	print_stack(*a); //REMOVER 
}
