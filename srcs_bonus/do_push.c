/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:28:41 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:08 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/libft.h"

void	do_pa(t_info *info)
{
	if (!info->first_b)
		return ;
	add_element_top(info->first_b->data, info, 'a');
	del_element_top(info, 'b');
	info->count++;
}

void	do_pb(t_info *info)
{
	if (!info->first_a)
		return ;
	add_element_top(info->first_a->data, info, 'b');
	del_element_top(info, 'a');
	info->count++;
}
