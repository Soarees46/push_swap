/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:09:46 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/19 10:21:34 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_px(t_stack **stk_x, t_stack **stk_y)
{
	t_stack	*tmp;

	if (!stk_y || !*stk_y)
		return ;
	tmp = *stk_y;
	*stk_y = (*stk_y)->next;
	if (*stk_y)
		(*stk_y)->prev = NULL;
	tmp->next = *stk_x;
	if (*stk_x)
		(*stk_x)->prev = tmp;
	tmp->prev = NULL;
	*stk_x = tmp;
}

// i = 0;
// while (0 < tam_y)
// {
// 	stk_y[tam_y] = stk_y[tam_y - 1];
// 	tam_y--;
// }