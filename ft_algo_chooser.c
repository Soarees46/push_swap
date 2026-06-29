/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:17:22 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/29 10:48:23 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_has_flag(char *argv[])
double	ft_has_flag(char *argv[])
{
	if ((ft_strncmp(argv[1], "--bench", 7)) == 0)
		return (1.5);
	else if ((ft_strncmp(argv[1], "--simple", 8)) == 0)
	if ((ft_strncmp(argv[1], "--bench", 7)) == 0)
		return (1.5);
	else if ((ft_strncmp(argv[1], "--simple", 8)) == 0)
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
	// int		bench;
	// int		bench;

	disorder = ft_has_flag(argv);
	// bench = 0;
	disorder = ft_has_flag(argv);
	// bench = 0;
	if (disorder == 0)
		disorder = ft_disorder(stk_a);
	// if (disorder == 1.5)
	// {
	// 	bench = 1;
	// 	disorder = ft_disorder(stk_a);
	// }
	// if (disorder == 1.5)
	// {
	// 	bench = 1;
	// 	disorder = ft_disorder(stk_a);
	// }
	if (disorder == 0)
		return;
	else if (disorder < 0.2)
		ft_simple(&stk_a, &stk_b);
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_printf("medium");
	else if (disorder >= 0.5)
		ft_radix(&stk_a, &stk_b, argc);
	// if (bench == 1)
	// 	ft_bench(disorder, );
		ft_radix(&stk_a, &stk_b, argc);
	// if (bench == 1)
	// 	ft_bench(disorder, );
}
