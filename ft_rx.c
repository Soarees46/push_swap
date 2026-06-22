/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:15:48 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/22 10:52:43 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_stack **stk)
{
	t_stack	*carruagem;
	t_stack	*maquinista;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	carruagem = *stk;
	*stk = carruagem->next;
	carruagem->next = NULL;
	maquinista = *stk;
	while (maquinista->next != NULL)
	{
		maquinista = maquinista->next;
	}
	maquinista->next = carruagem;
}
