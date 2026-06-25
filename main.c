/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/25 09:43:50 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stk)
{
	while (stk)
	{
		ft_printf("%d -> ", stk->content);
		stk = stk->next;
	}
	ft_printf("NULL\n");
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
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = ft_stack_builder(argc, argv);
	stk_b = ft_stack_builder(1, NULL);
	ft_algo_chooser(stk_a, stk_b, argc, argv);
	return (0);
}
