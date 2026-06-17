/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:00:07 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/17 11:33:34 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc
# include <unistd.h> //write
# include <stddef.h> 
# include <stdint.h>
# include <stdio.h> //printf

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	struct s_stack	*next;
}	t_stack;

void	ft_rrx(t_stack **stk);
void	ft_px(int *stk_x, int *stk_y, int tam_y);
t_stack	*ft_lstlast(t_stack *lst);
double	ft_disorder(t_stack *stk);
t_stack	*ft_lstnew(int content, t_stack *prev);
int		ft_atoi(char *nptr);
int		is_number(char *str);

#endif
