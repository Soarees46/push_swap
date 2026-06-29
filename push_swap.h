/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:00:07 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/29 09:47:47 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc
# include <unistd.h> //write
# include <stddef.h> 
# include <stdint.h>
# include <stdio.h> //printf RETIRAR ou TROACAR POR ft_printf
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	struct s_stack	*next;
}	t_stack;

int		ft_rrx(t_stack **stk, char x);
int		ft_px(t_stack **stk_y, t_stack **stk_x, char x);
int		ft_sx(t_stack *stk, char x);
int		ft_rx(t_stack **stk, char x);
double	ft_disorder(t_stack *stk);
void	ft_algo_chooser(t_stack *stk_a, t_stack *stk_b, int argc, char *argv[]);

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content, t_stack *prev);
int		ft_atoi(char *nptr);
int		is_number(char *str);
int		ft_printf(const char *format, ...);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_stack(t_stack *stk);
void	ft_index_stack(t_stack *stk);
void	ft_lstclear(t_stack **lst);
t_stack	*ft_stack_copy(t_stack *stk);

int		ft_radix(t_stack **a, t_stack **b, int size);

#endif
