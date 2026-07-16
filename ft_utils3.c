/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:16:18 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/16 13:28:35 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_stack	*ft_stack_copy(t_stack *stk)
{
	t_stack	*new_head;
	t_stack	*new_node;
	t_stack	*prev;
	t_stack	*tmp;

	new_head = NULL;
	prev = NULL;
	tmp = stk;
	while (tmp)
	{
		new_node = ft_lstnew(tmp->content, prev);
		if (!new_node)
		{
			ft_lstclear(&new_head);
			return (NULL);
		}
		if (!new_head)
			new_head = new_node;
		else
			prev->next = new_node;
		prev = new_node;
		tmp = tmp->next;
	}
	return (new_head);
}

int	get_position(t_stack *a, int value)
{
	int	pos;

	pos = 0;
	while (a != NULL)
	{
		if (a->content == value)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	ft_error(void)
{
	ft_printf("%g", "Error");
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	str = malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
