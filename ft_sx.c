/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:04:38 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/22 10:53:04 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_stack *stk)
{
	int	tmp;

	if (stk == NULL || stk->next == NULL)
		return ;
	tmp = stk->content;
	stk->content = stk->next->content;
	stk->next->content = tmp;
}
