/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:28:53 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:28:54 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/libft.h"

void    do_rra(t_info *info)
{
	info->first_a = info->first_a->prev;
	//ft_putstr_fd("rra\n", 1);
	//add_element_bottom(8, info, 'o');
	info->count++;
}

void    do_rrb(t_info *info)
{
	info->first_b = info->first_b->prev;
	//ft_putstr_fd("rrb\n", 1);
	//add_element_bottom(9, info, 'o');
	info->count++;
}

void    do_rrr(t_info *info)
{
	info->first_a = info->first_a->prev;
	info->first_b = info->first_b->prev;
	//ft_putstr_fd("rrr\n", 1);
	//add_element_bottom(10, info, 'o');
	info->count++;
}
