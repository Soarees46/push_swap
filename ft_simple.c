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

static int bring_min_to_top(t_stack **a, int min)
{
	int pos = get_position(*a, min);
	int size = stack_size(*a);
	int total = 0;

	if (pos <= size / 2)
	{
		while ((*a)->content != min)
			total += rx(a, 'a');   // rotação normal
	}
	else
	{
		while ((*a)->content != min)
			total += rrx(a, 'a');  // rotação inversa
	}
	return total;
}

int ft_simple(t_stack **a, t_stack **b)
{
	int min;
	int total = 0;

	while (*a)
	{
		min = find_min(*a);
		total += bring_min_to_top(a, min); // mover min para o topo
		total += px(a, b, 'b'); // push A -> B
	}
	while (*b)
		total += px(b, a, 'a'); // push B -> A

	return total;
}