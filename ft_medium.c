/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:45:21 by calberto          #+#    #+#             */
/*   Updated: 2026/06/29 12:11:48 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // feito com co-pilot para guardar a informacao

int push_chunk_to_b(t_stack **a, t_stack **b, int start, int end)
{
    int total = 0;

    while (1)
    {
        t_stack *tmp = *a;
        int found = 0;

        // procurar índice do chunk na stack A
        while (tmp)
        {
            if (tmp->content >= start && tmp->content <= end)
            {
                found = 1;
                break;
            }
            tmp = tmp->next;
        }

        if (!found)
            break; // chunk completo

        // rodar até o índice do chunk aparecer no topo
        while ((*a)->content < start || (*a)->content > end)
            total += ft_rx(a, 'a'); // ra

        // push para B
        total += ft_px(a, b, 'b'); // pb
    }

    return total;
}

int push_back_to_a(t_stack **a, t_stack **b)
{
    int total = 0;

    while (*b)
    {
        // encontrar o maior índice em B
        int max = (*b)->content;
        t_stack *tmp = *b;

        while (tmp)
        {
            if (tmp->content > max)
                max = tmp->content;
            tmp = tmp->next;
        }

        // rodar até o maior estar no topo
        while ((*b)->content != max)
            total += ft_rrx(b, 'b'); // rrb

        // push para A
        total += ft_px(b, a, 'a'); // pa
    }

    return total;
}

int ft_medium(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int chunk = (int)sqrt(size); // √n chunks
    int total = 0;

    ft_index_stack(*a); // transforma valores em índices

    int start = 0;
    int end = chunk;

    while (start < size)
    {
        if (end >= size)
            end = size - 1;

        total += push_chunk_to_b(a, b, start, end);

        start += chunk + 1;
        end += chunk + 1;
    }

    total += push_back_to_a(a, b);

    return total;
}