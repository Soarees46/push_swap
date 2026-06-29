/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:15:48 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/29 10:08:05 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rx(t_stack **stk, char x)
{
	t_stack	*carruagem;
	t_stack	*maquinista;

	if (*stk == NULL || (*stk)->next == NULL)
		return (0);
	carruagem = *stk;
	*stk = carruagem->next;
	carruagem->next = NULL;
	(*stk)->prev = NULL;
	maquinista = *stk;
	while (maquinista->next != NULL)
	{
		maquinista = maquinista->next;
	}
	maquinista->next = carruagem;
	carruagem->prev = maquinista;
	ft_printf("r%c\n", x);
	return (1);
}
