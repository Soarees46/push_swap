/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:16:56 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 12:22:47 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_stack **stk)
{
	t_stack	*tmp;

	tmp = *stk;
	if (stk == NULL)
		return ;
	while (stk->next != NULL)
		stk = stk->next;
	stk->next = tmp;
}

// int	tmp;

// tmp = stk[tam - 1];
// while (tam > 0)
// {
// 	stk[tam] = stk[tam -1];
// 	tam--;
// }
// stk[0] = tmp;