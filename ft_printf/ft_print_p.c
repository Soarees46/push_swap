/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:07:02 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/01 17:55:51 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_p(unsigned long int n, char format)
{
	const char	*base;
	int			len;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_print_hex_p(n / 16, format);
	len += ft_print_c(base[n % 16]);
	return (len);
}

int	ft_print_p(void *p)
{
	long int	address;
	int			tam;

	if (p == NULL)
	{
		ft_print_s("(nil)");
		return (5);
	}
	address = (long int)p;
	ft_print_s("0x");
	tam = ft_print_hex_p(address, 'x');
	return (tam + 2);
}
