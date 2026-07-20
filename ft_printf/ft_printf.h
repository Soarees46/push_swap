/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: venom <venom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:41:35 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/20 11:44:30 by venom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_print_p(void *p);
// str/char
int		ft_print_c(char c);
int		ft_print_s(char *s);
// decimal
int		ft_print_i(int n);
// int		ft_print_ud(unsigned int n);
int		ft_print_d(long n);
// hexadecimal
int		ft_print_hex(unsigned int n, char format);
//stderror
int		ft_print_double(double n);
int		ft_nbrlen(int n);
char	*ft_itoa(int n);
int		ft_print_2s(char *s);
int		ft_print_2c(char c);
int		ft_print_2i(int n);
int	ft_printf_err(const char *format, ...);

#endif