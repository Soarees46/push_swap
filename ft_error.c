/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: venom <venom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 22:47:55 by venom             #+#    #+#             */
/*   Updated: 2026/07/12 22:49:42 by venom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *stk)
{
	t_stack	*check;

	while (stk)
	{
		check = stk->next;
		while (check)
		{
			if (stk->content == check->content)
				return (1);
			check = check->next;
		}
		stk = stk->next;
	}
	return (0);
}

static int	ft_is_flag(char *str)
{
	if (!ft_strncmp(str, "--simple", 8))
		return (1);
	if (!ft_strncmp(str, "--medium", 8))
		return (1);
	if (!ft_strncmp(str, "--complex", 9))
		return (1);
	if (!ft_strncmp(str, "--adaptive", 10))
		return (1);
	if (!ft_strncmp(str, "--bench", 7))
		return (1);
	return (0);
}

static int	ft_is_valid_number(char *str)
{
	long long	nb;
	int			sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] && str[i] != ' ')
		return (0);
	if ((sign == 1 && nb > 2147483647)
		|| (sign == -1 && nb > 2147483648LL))
		return (0);
	return (1);
}

static int	ft_check_number_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (!ft_is_valid_number(&str[i]))
			return (0);
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (1);
}

int	ft_is_error(char *str)
{
	if (ft_is_flag(str))
		return (0);
	if (ft_strchr(str, ' '))
	{
		if (!ft_check_number_str(str))
		{
			ft_printf("Error\n");
			return (1);
		}
		return (0);
	}
	if (!ft_is_valid_number(str))
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

