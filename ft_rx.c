/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:15:48 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 13:49:56 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rx(t_stack **stk)
{
	t_stack *carruagem;
	t_stack *maquinista;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;

	carruagem = *stk; // Guarda a carruagem da frente para a meter na cauda do comboio mais tarde
	*stk = carruagem->next; // 2. O segundo nó passa a ser o NOVO topo da lista
	carruagem->next = NULL; // 3. Como o antigo 'primeiro' vai para o fim, ele já não pode apontar para ninguém

	maquinista = *stk; // 4. Criamos um boneco ('atual') para caminhar até ao fim da lista
	while (maquinista->next != NULL)
	{
		maquinista = maquinista->next; // O boneco salta para o nó seguinte
	}
	maquinista->next = carruagem; // 5. O nó que era o último agora passa a apontar para o nosso ex-primeiro
}
