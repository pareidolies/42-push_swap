/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_reception_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:25:24 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:25:26 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    adjust_reception_stack(int nbr, t_info *info)
{
	t_stack	*tmp;
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = info->first_a;
	size = lstsize_pushswap(info, 'a');
	while (j < size)
	{
		j++;
		if (is_extreme(nbr, info) && tmp->data > tmp->next->data)
			break;
		if (nbr >tmp->data && nbr < tmp->next->data)
			break;
		tmp = tmp->next;
	}
	if (info->move == 1 || info->move == 3)
		while (i < j)
		{
			info->ra++;
			i++;
		}
	if (info->move == 2 || info->move == 4)
		while (i < (size - j))
		{
			info->rra++;
			i++;
		}
}
