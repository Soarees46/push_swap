/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:48:35 by calberto          #+#    #+#             */
/*   Updated: 2026/07/16 13:40:25 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stk)
{
	t_stack	*tmp;

	if (!stk || !*stk)
		return ;
	while (*stk)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = tmp;
	}
}
