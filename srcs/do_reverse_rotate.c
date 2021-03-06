/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:25:52 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 14:02:24 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	do_rra(t_info *info)
{
	info->first_a = info->first_a->prev;
	add_element_bottom(8, info, 'o');
	info->count++;
}

void	do_rrb(t_info *info)
{
	info->first_b = info->first_b->prev;
	add_element_bottom(9, info, 'o');
	info->count++;
}

void	do_rrr(t_info *info)
{
	info->first_a = info->first_a->prev;
	info->first_b = info->first_b->prev;
	add_element_bottom(10, info, 'o');
	info->count++;
}
