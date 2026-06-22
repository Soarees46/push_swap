/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:17:22 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/22 12:18:15 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_has_flag(int argc, char *argv[])
{
	if ((ft_strncmp(argv[1], "--simple", 8)) == 0)
		return (0.1);
	else if ((ft_strncmp(argv[1], "--medium", 8)) == 0)
		return (0.3);
	else if ((ft_strncmp(argv[1], "--complex", 9)) == 0)
		return (0.6);
	return (0);
}

void	ft_algo_chooser(t_stack *stk_a, t_stack *stk_b, int argc, char *argv[])
{
	double	disorder;

	disorder = ft_has_flag(argc, argv);
	if (disorder == 0)
		disorder = ft_disorder(stk_a);
	if (disorder == 0)
		ft_printf("order");
	else if (disorder < 0.2)
		ft_printf("simple");
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_printf("medium");
	else if (disorder >= 0.5)
		ft_printf("high");
	ft_printf("\nSTAK B:\n");
	print_stack(stk_b);
}
