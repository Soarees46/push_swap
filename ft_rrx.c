/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:16:56 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 15:10:20 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rrx(t_stack **stk)
{
	t_stack *penultimo;
	t_stack *ultimo;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;

	penultimo = *stk; // PASSO 1: Pomos o 'penultimo' a caminhar até parar no gajo que está antes do último
	while (penultimo->next->next != NULL)
	{
		penultimo = penultimo->next; // Salta para a próxima carruagem
	}

	ultimo = penultimo->next;// PASSO 2: O 'ultimo' vai ser a carruagem que está à frente do penúltimo
	penultimo->next = NULL;// PASSO 3: O penúltimo passa a ser o novo fim da lista, por isso aponta para NULL
	ultimo->next = *stk;// PASSO 4: O último gajo agora vai apontar para o antigo topo da lista
	*stk = ultimo;// PASSO 5: A lista no main agora começa oficialmente neste 'ultimo' gajo
}
