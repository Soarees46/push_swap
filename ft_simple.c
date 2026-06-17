/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:36:42 by calberto          #+#    #+#             */
/*   Updated: 2026/06/17 11:34:16 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bring_min_to_top(t_stack **a, int min)
{
    while ((*a)->content != min) // Enquanto o valor do topo da stack não for o menor...
        ra(a);
}

void	ft_simple(t_stack **a, t_stack **b)
{
	int	min;

	while (*a) // enquanto A não estiver vazia
	{
		min = find_min(*a);          // 1) encontra o menor
		bring_min_to_top(a, min);    // 2) roda até o menor estar no topo
		pb(a, b);                    // 3) manda o menor para B
	}
	while (*b != NULL) // quando A estiver vazia, devolve tudo
		pa(b, a);
}