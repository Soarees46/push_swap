/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:21:31 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/01 16:38:17 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_tam(unsigned int n)
// {
// 	int	len;

// 	len = 0;
// 	while (n > 0)
// 	{
// 		len++;
// 		n /= 16;
// 	}
// 	return (len);
// }

int	ft_print_hex(unsigned int n, char format)
{
	const char	*base;
	int			len;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, format);
	len += ft_print_c(base[n % 16]);
	return (len);
}

// int	main(void)
// {
// 	ft_print_d(ft_print_hex(17, 'X'));
// }
// unsigned int		*arr;
// int					i;
// if (n == 0)
// 		return (ft_print_c('0'));
// 	arr = malloc(len * sizeof(unsigned int));
// 	if (!arr)
// 		return (0);
// 	i = 0;
// 	while (n > 0)
// 	{
// 		arr[i++] = n % 16;
// 		n /= 16;
// 	}
// 	while (i-- > 0)
// 		ft_print_c(base[arr[i]]);