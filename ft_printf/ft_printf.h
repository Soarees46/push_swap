/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:41:35 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/01 16:20:32 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_p(void *p);
// str/char
int	ft_print_c(char c);
int	ft_print_s(char *s);
// decimal
int	ft_print_i(int n);
int	ft_print_ud(unsigned int n);
int	ft_print_d(long n);
// hexadecimal
int	ft_print_hex(unsigned int n, char format);

#endif