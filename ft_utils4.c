/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:17:21 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/15 10:02:54 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

t_stack	*ft_stack_concat(t_stack *dest, t_stack *origin)
{
	t_stack	*last_dest;

	if (!dest)
		return (origin);
	if (!origin)
		return (dest);
	last_dest = ft_lstlast(dest);
	last_dest->next = origin;
	origin->prev = last_dest;
	return (dest);
}

int	ft_lsttam(t_stack *lst)
{
	int	tam;

	tam = 0;
	if (lst == NULL)
		return (tam);
	while (lst != NULL)
	{
		lst = lst->next;
		tam++;
	}
	return (tam);
}
