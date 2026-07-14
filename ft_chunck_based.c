/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunck_based.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 11:03:08 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/14 11:29:53 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// DIVIDIR PARA CONQUISTAR
// INDEXAR STACK_A
// CALCULAR CHUNCK_SIZE = RAIZ DE STACK_A.LEN()
// DIVIDIR STACK_A EM CHUNKS CONFORME CHUNK_SIZE
// 1. Para cada chunk, encontre o elemento do intervalo
// 		mais barato de alcançar, rotacione A (ra/rra) até 
// 		ele e faça pb (podendo fazer rb para organizar B).
// 2. Quando A estiver vazia, encontre sempre o maior
// 		elemento de B, rotacione (rb/rrb) até ele e faça pa.
// 3. Repita até B ficar vazia; como os maiores voltam
// 		primeiro, A termina ordenada.