/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: venom <venom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:17:22 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/20 11:21:11 by venom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flags	ft_has_flag(char *argv[])
{
	t_flags	flags;
	int		i;

	flags.bench = 0;
	flags.disorder = 0;
	i = 1;
	while (argv[i])
	{
		if ((ft_strncmp(argv[i], "--simple", 8)) == 0)
			flags.disorder = 0.1;
		else if ((ft_strncmp(argv[i], "--medium", 8)) == 0)
			flags.disorder = 0.3;
		else if ((ft_strncmp(argv[i], "--complex", 9)) == 0)
			flags.disorder = 0.6;
		else if ((ft_strncmp(argv[i], "--adaptive", 10)) == 0)
			flags.disorder = 0;
		if ((ft_strncmp(argv[i], "--bench", 7)) == 0)
			flags.bench = 1;
		i++;
	}
	flags.position = i;
	return (flags);
}
// && argv[i][0] == '-'

void	ft_algo_chooser(t_stack **stk_a, t_stack **stk_b, t_flags flags)
{
	t_ops	ops;
	int		stk_size;

	ops = (t_ops){0};
	stk_size = ft_lsttam(*stk_a);
	if (flags.disorder == 0)
		flags.disorder = ft_disorder(*stk_a);
	if (flags.disorder == 0)
		return ;
	else if (flags.disorder < 0.2)
		ops = ft_simple(stk_a, stk_b);
	else if (flags.disorder >= 0.2 && flags.disorder < 0.5)
		ops = ft_chunck_based(stk_a, stk_b, stk_size);
	else if (flags.disorder >= 0.5)
		ops = ft_radix(stk_a, stk_b, stk_size);
	if (flags.bench == 1)
		ft_bench((flags.disorder * 100), ops);
}
