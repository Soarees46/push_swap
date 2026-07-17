/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/17 11:13:52 by vaugusto         ###   ########.fr       */
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
		if (!s[i])
			break ;
		if (is_number(&s[i]))
		{
			ft_lstadd_back(stk, ft_lstnew(ft_atoi(&s[i]), NULL));
			if (s[i] == '+' || s[i] == '-')
				i++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		else
		{
			while (s[i] && s[i] != ' ')
				i++;
		}
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

int	ft_norminette(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
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
		else if (ft_norminette(argv[i]))
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
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (ft_is_error(argv[i]))
			return (1);
	}
	flags = ft_has_flag(argv);
	stk_a = ft_stack_builder(argc, argv);
	stk_b = ft_stack_builder(1, NULL);
	if (has_duplicates(stk_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_algo_chooser(stk_a, stk_b, flags);
	ft_free_stack(&stk_a);
	ft_free_stack(&stk_b);
	return (0);
}

// if (argv[i][0] == '|')
// 	break ;