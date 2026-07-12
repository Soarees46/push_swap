/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:15:52 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/30 21:39:49 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_2s(char *s)
{
	int	i;

	if (!s)
		return (ft_print_2s("(null)"));
	i = 0;
	while (s[i] != '\0')
		write(2, &s[i++], 1);
	return (i);
}

int	ft_print_2c(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_print_2i(int n)
{
	char	*n_ptr;
	int		len;

	n_ptr = ft_itoa(n);
	len = ft_print_2s(n_ptr);
	free(n_ptr);
	return (len);
}

int	ft_print_double(double n)
{
	long	integer;
	long	decimal;
	int		len;

	len = 0;
	integer = (long)n;
	decimal = (long)((n - integer) * 100 + 0.5);
	if (decimal == 100)
	{
		integer++;
		decimal = 0;
	}
	if (decimal < 0)
		decimal = -decimal;
	if (n < 0 && integer == 0)
		len += ft_print_2c('-');
	len += ft_print_2i(integer);
	len += ft_print_2c('.');
	if (decimal < 10)
		len += ft_print_2c('0');
	len += ft_print_2i(decimal);
	return (len);
}
