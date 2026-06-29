/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:04:38 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/29 09:46:46 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sx(t_stack *stk, char x)
{
	int	tmp;

	if (stk == NULL || stk->next == NULL)
		return ;
	tmp = stk->content;
	stk->content = stk->next->content;
	stk->next->content = tmp;
	ft_printf("s%c\n", x);
	return (1);
}
