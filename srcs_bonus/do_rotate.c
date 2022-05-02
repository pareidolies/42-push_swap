/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:29:00 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:35 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/libft.h"

void	do_ra(t_info *info)
{
	info->first_a = info->first_a->next;
	info->count++;
}

void	do_rb(t_info *info)
{
	info->first_b = info->first_b->next;
	info->count++;
}

void	do_rr(t_info *info)
{
	info->first_a = info->first_a->next;
	info->first_b = info->first_b->next;
	info->count++;
}
