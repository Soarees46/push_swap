/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossoares <carlossoares@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:42:48 by carlossoare       #+#    #+#             */
/*   Updated: 2026/07/05 15:50:52 by carlossoare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops ft_medium(t_stack **a, t_stack **b, int size)
{
	t_ops ops;
	int chunk_size;
	int limit;
	int max_val;
	int max_pos;
	int pos;
	t_stack *tmp;
	int safety1 = 0;
	int safety2 = 0;
	int safety3 = 0;

	ops = (t_ops){0};
	ft_index_stack(*a);

	if (size <= 20)
		chunk_size = size / 2 + 1;
	else if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 40;
	limit = chunk_size;

	// FASE 1: Enviar de A para B
	while (*a)
	{
		if (safety1++ > 1000)
		{
			ft_printf("\n[ERRO] Loop Infinito na FASE 1 (A para B)!\n");
			return (ops);
		}
		if ((*a)->content < limit)
		{
			ops.total += ft_px(b, a, 'b');
			if (stack_size(*b) >= limit && limit < size)
				limit += chunk_size;
		}
		else
		{
			ops.total += ft_rx(a, 'a');
		}
	}

	// FASE 2: Enviar de B para A
	while (*b)
	{
		if (safety2++ > 1000)
		{
			ft_printf("\n[ERRO] Loop Infinito na FASE 2 (B para A)!\n");
			return (ops);
		}

		tmp = *b;
		max_val = tmp->content;
		max_pos = 0;
		pos = 0;
		while (tmp)
		{
			if (tmp->content > max_val)
			{
				max_val = tmp->content;
				max_pos = pos;
			}
			pos++;
			tmp = tmp->next;
		}

		int b_size = stack_size(*b);
		if (max_pos <= b_size / 2)
		{
			while (max_pos > 0)
			{
				if (safety3++ > 2000)
				{
					ft_printf("\n[ERRO] Loop Infinito nas ROTAÇÕES de B!\n");
					return (ops);
				}
				ops.total += ft_rx(b, 'b');
				max_pos--;
			}
		}
		else
		{
			while (max_pos < b_size)
			{
				if (safety3++ > 2000)
				{
					ft_printf("\n[ERRO] Loop Infinito nas ROTAÇÕES REVERSAS de B!\n");
					return (ops);
				}
				ops.total += ft_rrx(b, 'b');
				max_pos++;
			}
		}
		ops.total += ft_px(a, b, 'a');
	}
	return (ops);
}