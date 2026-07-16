/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:16:56 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/16 13:36:08 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rrx(t_stack **stk, char x)
{
	t_stack	*last;
	t_stack	*s_to_last;

	if (!stk || !*stk || !(*stk)->next)
		return (0);
	last = ft_lstlast(*stk);
	s_to_last = last->prev;
	s_to_last->next = NULL;
	last->prev = NULL;
	last->next = *stk;
	(*stk)->prev = last;
	*stk = last;
	ft_printf("rr%c\n", x);
	return (1);
}

// int	ft_rrx(t_stack **stk, char x)
// {
// 	t_stack	*last;
// 	t_stack	*s_to_last;

// 	if (stk == NULL)
// 		return (0);
// 	last = ft_lstlast(*stk);
// 	s_to_last = last->prev;
// 	last->next = *stk;
// 	s_to_last->next = NULL;
// 	*stk = last;
// 	ft_printf("rr%c\n", x);
// 	return (1);
// }
