/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberto <calberto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:00:07 by vaugusto          #+#    #+#             */
/*   Updated: 2026/06/11 11:59:12 by calberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h> 	
# include <stddef.h> 
# include <stdint.h>

typedef struct s_stack
{
	int			content;
	struct s_stack	*next;
}	t_stack;


#endif
