/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:28:53 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:18 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/libft.h"

void	do_rra(t_info *info)
{
	info->first_a = info->first_a->prev;
	info->count++;
}

void	do_rrb(t_info *info)
{
	info->first_b = info->first_b->prev;
	info->count++;
}

void	do_rrr(t_info *info)
{
	info->first_a = info->first_a->prev;
	info->first_b = info->first_b->prev;
	info->count++;
}
