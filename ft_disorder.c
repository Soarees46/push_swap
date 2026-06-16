/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:14:23 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/16 11:08:14 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_disorder(t_stack *stk)
{
	double		mistakes;
	double		total_pairs;
	t_stack		*i;
	t_stack		*i2;

	mistakes = 0;
	total_pairs = 0;
	i = stk;
	while (i)
	{
		i2 = i->next;
		while (i2)
		{
			total_pairs++;
			if (i->content > i2->content)
				mistakes++;
			i2 = i2->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}
