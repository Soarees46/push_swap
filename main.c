/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/19 22:18:25 by vaugusto         ###   ########.fr       */
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

void	ft_algo_chooser(t_stack *stk_a, t_stack *stk_b)
{
	double	disorder;

	disorder = ft_disorder(stk_a);
	if (disorder == 0)
		ft_printf("order");
	else if (disorder < 0.2)
		ft_printf("simple");
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_printf("medium");
	else if (disorder >= 0.5)
		ft_printf("high");
	print_stack(stk_b);
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

	ft_algo_chooser(stk_a, stk_b);

	return (0);
}
