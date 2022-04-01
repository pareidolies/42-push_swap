/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_reception_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:25:24 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 15:21:22 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	adjust_reception_stack_1(int nbr, t_info *info)
{
	t_stack	*tmp;
	int		size;
	int		j;

	j = 0;
	tmp = info->first_a;
	size = lstsize_pushswap(info, 'a');
	while (j < size)
	{
		j++;
		if (is_extreme(nbr, info) && tmp->data > tmp->next->data)
			break ;
		if (nbr > tmp->data && nbr < tmp->next->data)
			break ;
		tmp = tmp->next;
	}
	adjust_reception_stack_2(j, size, info);
}

void	adjust_reception_stack_2(int j, int size, t_info *info)
{
	int	i;

	i = 0;
	if (info->move == 1 || info->move == 3)
	{
		while (i < j)
		{
			info->ra++;
			i++;
		}
	}
	if (info->move == 2 || info->move == 4)
	{
		while (i < (size - j))
		{
			info->rra++;
			i++;
		}
	}
}
