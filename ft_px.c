/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:09:46 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 15:06:20 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_px(t_stack **stk_origem, t_stack **stk_destino)
{
	t_stack *caixa_a_mover;

	if (stk_origem == NULL || *stk_origem == NULL)
		return ;

	caixa_a_mover = *stk_origem; // PASSO 1: Agarras na primeira caixa da lista de origem com a mão para não a perder
	*stk_origem = caixa_a_mover->next; // PASSO 2: O segundo nó da origem passa a ser o NOVO topo da lista de origem
	caixa_a_mover->next = *stk_destino; // PASSO 3: A caixa que tens na mão vai apontar para o atual topo da lista de destino
	*stk_destino = caixa_a_mover; // PASSO 4: A lista de destino agora passa a começar oficialmente nesta caixa nova
}
