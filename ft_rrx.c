/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:16:56 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/23 11:55:59 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_stack **stk, char x)
{
	t_stack	*last;
	t_stack	*s_to_last;

	if (stk == NULL)
		return ;
	last = ft_lstlast(*stk);
	s_to_last = last->prev;
	last->next = *stk;
	s_to_last->next = NULL;
	*stk = last;
	ft_printf("rr%c\n", x);
}

// t_stack	*tmp;
// tmp = *stk;