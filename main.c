/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/09 10:28:14 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strchr_parsing(char *s, t_stack **stk)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (is_number(&s[i]))
		{
			ft_lstadd_back(stk, ft_lstnew(ft_atoi(&s[i]), NULL));
			if (s[i] == '+' || s[i] == '-')
				i++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		else
			i++;
	}
}

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
	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			ft_strchr_parsing(argv[i], &head);
		else if (is_number(argv[i]) && !ft_strchr(argv[i], ' '))
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
	}
	return (head);
}

int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_flags	flags;

	flags = ft_has_flag(argv);
	stk_a = ft_stack_builder(argc, argv);
	stk_b = ft_stack_builder(1, NULL);
	ft_algo_chooser(stk_a, stk_b, argc, flags);
	return (0);
}
