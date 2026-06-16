/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/16 12:28:39 by vaugusto         ###   ########.fr       */
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
	t_stack	*stk;

	n1.content = 1;
	n2.content = 5;
	n3.content = 4;
	n4.content = 3;
	n5.content = 2;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;

	n1.prev = NULL;
	n2.prev = &n1;
	n3.prev = &n2;
	n4.prev = &n3;
	n5.prev = &n4;

	stk = &n1;
	printf("Antes:\n");
	print_stack(stk);

	ft_rrx(&stk);

	printf("Depois:\n");
	print_stack(stk);

	// printf("Disorder: %f", ft_disorder(&n1));

	return (0);
}
