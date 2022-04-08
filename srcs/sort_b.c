/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:27:04 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:15:36 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	initialize_operations(t_info *info)
{
	info->ra = 0;
	info->rb = 0;
	info->rra = 0;
	info->rrb = 0;
	info->tmp_move = 1;
}

void	do_joint_operations(t_info *info)
{
	while (info->ra && info->rb)
	{
		do_rr(info);
		info->ra--;
		info->rb--;
	}
	while (info->rra && info->rrb)
	{
		do_rrr(info);
		info->rra--;
		info->rrb--;
	}
}

void	do_standard_operations(t_info *info)
{
	while (info->ra)
	{
		do_ra(info);
		info->ra--;
	}
	while (info->rra)
	{
		do_rra(info);
		info->rra--;
	}
	while (info->rb)
	{
		do_rb(info);
		info->rb--;
	}
	while (info->rrb)
	{
		do_rrb(info);
		info->rrb--;
	}
}

void	sort_elements_in_b(t_info *info)
{
	int	nbr;

	while (info->first_b != NULL)
	{
		nbr = most_reachable_number(info);
		initialize_operations(info);
		adjust_reception_stack_1(nbr, info);
		take_shortest_path(nbr, info, 'b');
		do_joint_operations(info);
		do_standard_operations(info);
		do_pa(info);
	}
}
