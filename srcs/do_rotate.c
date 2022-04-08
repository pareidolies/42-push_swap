/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:26:03 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 14:02:09 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	do_ra(t_info *info)
{
	info->first_a = info->first_a->next;
	add_element_bottom(5, info, 'o');
	info->count++;
}

void	do_rb(t_info *info)
{
	info->first_b = info->first_b->next;
	add_element_bottom(6, info, 'o');
	info->count++;
}

void	do_rr(t_info *info)
{
	info->first_a = info->first_a->next;
	info->first_b = info->first_b->next;
	add_element_bottom(7, info, 'o');
	info->count++;
}
