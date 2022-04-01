/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:29:09 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:29:10 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/libft.h"

void	do_sa(t_info *info)
{
	int	tmp;

	if (info->first_a)
	{
		tmp = info->first_a->data;
		info->first_a->data = info->first_a->next->data;
		info->first_a->next->data = tmp;
		//ft_putstr_fd("sa\n", 1);
		//add_element_bottom(0, info, 'o');
	}
	info->count++;
}

void    do_sb(t_info *info)
{
	int     tmp;

	if (info->first_b)
	{
		tmp = info->first_b->data;
		info->first_b->data = info->first_b->next->data;
		info->first_b->next->data = tmp;
		//ft_putstr_fd("sb\n", 1);
		//add_element_bottom(1, info, 'o');
	}
	info->count++;
}

void    do_ss(t_info *info)
{
	do_sa(info);
	do_sb(info);
	//ft_putstr_fd("ss\n", 1);
	//add_element_bottom(2, info, 'o');
	info->count++;
}
