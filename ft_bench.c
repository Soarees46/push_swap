/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:32:43 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/11 16:55:58 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bench(double disorder, t_ops ops)
{
	char	*strategy;

	if (disorder < 20)
		strategy = "simple / O(n2)";
	else if (disorder >= 20 && disorder < 50)
		strategy = "medium / O(n√n)";
	else if (disorder >= 50)
		strategy = "complex / O(n log n)";
	else
		strategy = "adaptive";
	ft_print_2s("\n[bench] disorder: ");
	ft_printf("%f%%", disorder);
	ft_print_2s("\n[bench] strategy: ");
	ft_printf("%g", strategy);
	ft_print_2s("\n[bench] total_ops: ");
	ft_printf("%a", ops.total);
	ft_printf("\n%g %a %g %a %g %a %g %a %g %a",
		"[bench] sa: ", ops.sa, "sb: ", ops.sb,
		"ss: ", ops.ss, "pa: ", ops.pa, "pb: ", ops.pb);
	ft_printf("\n[bench] ra: %a rb: %a rr: %a rra: %a rrb: %a rrr: %a\n",
		ops.ra, ops.rb, ops.rr, ops.rra,
		ops.rrb, ops.rrr);
}
