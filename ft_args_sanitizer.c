/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_sanitizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:20:35 by vaugusto          #+#    #+#             */
/*   Updated: 2026/07/06 12:04:37 by vaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static int	ft_count_numbers(char *arg)
{
	char	**tmp;
	int		i;

	if (!ft_strchr(arg, ' '))
		return (1);
	tmp = ft_split(arg, ' ');
	i = 0;
	while (tmp[i])
		i++;
	free_matrix(tmp);
	return (i);
}

static void	ft_fill_stack(char **stack, char *arg, int *j)
{
	char	**tmp;
	int		i;

	if (ft_strchr(arg, ' '))
	{
		tmp = ft_split(arg, ' ');
		i = 0;
		while (tmp[i])
			stack[(*j)++] = ft_strdup(tmp[i++]);
		free_matrix(tmp);
	}
	else
	{
		ft_printf("aqui 2\n");
		stack[(*j)++] = ft_strdup(arg);
	}
}

char	**ft_args_sanitizer(char *argv[], int argc)
{
	char	**stack_n;
	int		i;
	int		j;
	int		tam;

	tam = 0;
	i = 1;
	while (i < argc)
		tam += ft_count_numbers(argv[i++]);
	stack_n = malloc((tam + 1) * sizeof(char *));
	if (!stack_n)
		return (NULL);
	i = 1;
	stack_n[0] = argv[0];
	j = 1;
	while (i < argc)
		ft_fill_stack(stack_n, argv[i++], &j);
	stack_n[j] = NULL;
	return (stack_n);
}
