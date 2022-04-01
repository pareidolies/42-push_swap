/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:28:01 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 14:52:01 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/libft.h"

int	is_space(char c)
{
	if (c == ' ' | c == '\t' | c == '\n' | c == '\v'
		| c == '\f' | c == '\r')
		return (1);
	return (0);
}

int	check_integers(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && str[i] == '-')
	{
		if (ft_atoi(str) > 0)
			return (0);
		i++;
	}
	else if (str[i] && str[i] != '-')
	{
		if (ft_atoi(str) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->size)
	{
		j = i + 1;
		while (j < info->size)
		{
			if (info->tab[i] == info->tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
