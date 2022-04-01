/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:25:43 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 14:11:32 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	do_pa(t_info *info)
{
	if (!info->first_b)
		return ;
	add_element_top(info->first_b->data, info, 'a');
	del_element_top(info, 'b');
	add_element_bottom(3, info, 'o');
	info->count++;
}

void	do_pb(t_info *info)
{
	if (!info->first_a)
		return ;
	add_element_top(info->first_a->data, info, 'b');
	del_element_top(info, 'a');
	add_element_bottom(4, info, 'o');
	info->count++;
}
