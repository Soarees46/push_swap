/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:16:56 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/16 12:30:48 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_stack **stk)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*s_to_last;

	tmp = *stk;
	if (stk == NULL)
		return ;
	last = ft_lstlast(*stk);
	s_to_last = last->prev;
	last->next = *stk;
	s_to_last->next = NULL;
	*stk = last;
}
