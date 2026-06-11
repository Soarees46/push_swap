/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 12:17:20 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_stack(t_stack *stk)
{
	while (stk)
	{
		printf("%d -> ", stk->content);
		stk = stk->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_stack	n1;
	t_stack	n2;
	t_stack	n3;
	t_stack	n4;
	t_stack	n5;

	n1.content = 1;
	n2.content = 2;
	n3.content = 3;
	n4.content = 4;
	n5.content = 5;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;

	printf("Antes:\n");
	print_stack(&n1);

	ft_rrx(&n1);

	printf("Depois:\n");
	print_stack(&n1);

	return (0);
}