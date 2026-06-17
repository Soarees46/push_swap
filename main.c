/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/17 11:56:45 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_stack	*ft_stack_builder(int argc, char *argv[])
{
	int		i;
	t_stack	*head;
	t_stack	*prev;
	t_stack	*new;

	head = NULL;
	prev = NULL;
	i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]))
		{
			new = ft_lstnew(ft_atoi(argv[i]), prev);
			if (!new)
				return (NULL);
			if (!head)
				head = new;
			if (prev)
				prev->next = new;
			prev = new;
		}
		i++;
	}
	return (head);
}

int	main(int argc, char *argv[])
{
	t_stack	*stk;

	stk = ft_stack_builder(argc, argv);
	printf("Antes:\n");
	print_stack(stk);

	ft_rrx(&stk);

	printf("Depois:\n");
	print_stack(stk);
	//printf("Disorder: %f", ft_disorder(&n1));

	return (0);
}
