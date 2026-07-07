/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:17:22 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/06 11:25:14 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

t_flags	ft_has_flag(char *argv[])
{
	t_flags	flags;
	int		i;

	flags.bench = 0;
	flags.disorder = 0;
	i = 1;
	while (argv[i] && argv[i][0] == '-')
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

void	ft_algo_chooser(t_stack *stk_a, t_stack *stk_b, int argc, t_flags flags)
{
	// t_flags	flags; FAZER VIR DOS PARAMETROS
	t_ops	ops;
	// char	**stkss;

	// flags = ft_has_flag(argv);
	// stkss = ft_args_sanitizer(argv, flags.position, argc);
	ops = (t_ops){0};
	if (flags.disorder == 0)
		flags.disorder = ft_disorder(stk_a);
	if (flags.disorder == 0)
		return ;
	else if (flags.disorder < 0.2)
		ops.total = ft_simple(&stk_a, &stk_b);
	else if (flags.disorder >= 0.2 && flags.disorder < 0.5)
		ops.total = ft_printf("medium");
	else if (flags.disorder >= 0.5)
		ops = ft_radix(&stk_a, &stk_b, argc);
	if (flags.bench == 1)
		ft_bench((flags.disorder * 100), ops);
}
