/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:26:15 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 14:00:32 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	do_sa(t_info *info)
{
	int	tmp;

	if (info->first_a)
	{
		tmp = info->first_a->data;
		info->first_a->data = info->first_a->next->data;
		info->first_a->next->data = tmp;
		add_element_bottom(0, info, 'o');
	}
	info->count++;
}

void	do_sb(t_info *info)
{
	int	tmp;

	if (info->first_b)
	{
		tmp = info->first_b->data;
		info->first_b->data = info->first_b->next->data;
		info->first_b->next->data = tmp;
		add_element_bottom(1, info, 'o');
	}
	info->count++;
}

void	do_ss(t_info *info)
{
	do_sa(info);
	do_sb(info);
	add_element_bottom(2, info, 'o');
	info->count++;
}
