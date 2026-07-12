/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:23:29 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/01 17:50:13 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_nbrlen(long n)
{
	long	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_long_itoa(long nb)
{
	char		*str;
	long		len;

	len = ft_nbrlen(nb);
	if (nb < 0)
	{
		str = (char *)malloc((len + 2) * sizeof(char));
		str[0] = '-';
		nb = -nb;
	}
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int	ft_print_d(long n)
{
	char	*n_ptr;
	int		len;

	n_ptr = ft_long_itoa(n);
	len = ft_print_s(n_ptr);
	free(n_ptr);
	return (len);
}

// int	main(void)
// {
// 	ft_print_d(ft_print_d(42));
// }