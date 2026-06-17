/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:04:38 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 12:25:26 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sx(t_stack *stk)
{
	int tmp;

	if (stk == NULL || stk->next == NULL)
		return ;

	tmp = stk->content;
	stk->content = stk->next->content;
	stk->next->content = tmp;
	
}
