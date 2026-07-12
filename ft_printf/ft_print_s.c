/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 13:07:17 by vaugusto          #+#    #+#             */
/*   Updated: 2026/05/26 18:10:59 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	i;

	if (!s)
		return (ft_print_s("(null)"));
	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	return (i);
}

// int	main(void)
// {
// 	ft_print_d(ft_print_s("vini"));
// }