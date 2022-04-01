/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:24:45 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 15:25:08 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	push_elements_to_b(t_info *info)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = info->first_a;
	while (i < info->size)
	{
		if (tmp->in_place == 1)
		{
			do_ra(info);
			i++;
		}
		else
		{
			do_pb(info);
			i++;
		}
		tmp = info->first_a;
	}
}
