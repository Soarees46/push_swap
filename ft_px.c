/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:09:46 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/29 10:48:41 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_px(t_stack **stk_y, t_stack **stk_x, char x)
{
	t_stack	*tmp;

	if (!stk_y || !*stk_y)
		return (0);
	tmp = *stk_y;
	*stk_y = (*stk_y)->next;
	if (*stk_y)
		(*stk_y)->prev = NULL;
	tmp->next = *stk_x;
	if (*stk_x)
		(*stk_x)->prev = tmp;
	tmp->prev = NULL;
	*stk_x = tmp;
	ft_printf("p%c\n", x);
	return (1);
}
