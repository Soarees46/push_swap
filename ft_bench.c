/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:32:43 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/01 12:05:38 by vaugusto         ###   ########.fr       */
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
	ft_printf("\n[bench] disorder: %f%%", disorder);
	ft_printf("\n[bench] strategy: %g", strategy);
	ft_printf("\n[bench] total_ops: %a", ops.total);
	ft_printf("\n[bench] sa: %a sb: %a ss: %a pa: %a pb: %a",
		ops.sa, ops.sb, ops.ss, ops.pa, ops.pb);
	ft_printf("\n[bench] ra: %a rb: %a rr: %a rra: %a rrb: %a rrr: %a\n",
		ops.ra, ops.rb, ops.rr, ops.rra,
		ops.rrb, ops.rrr);
}
