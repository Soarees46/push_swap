/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:36:42 by calberto          #+#    #+#             */
/*   Updated: 2026/06/22 15:06:26 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_min_to_top(t_stack **a, int min)
{
	while (*a && (*a)->content != min)
		ft_rx(a);
}

void	ft_simple(t_stack **a, t_stack **b)
{
	int	min;

	while (stack_size(*a) > 0)
	{
		min = find_min(*a);
		bring_min_to_top(a, min);
		ft_px(a, b);
	}
	while (*b)
		ft_px(b, a);
}
