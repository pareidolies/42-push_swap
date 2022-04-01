/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_most_reachable_number.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:26:33 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:26:34 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	find_path_in_a_length(int nbr, t_info *info)
{
	t_stack	*tmp;
	int	i;
	int	size;

	size = lstsize_pushswap(info, 'a');
	i = 0;
	tmp = info->first_a;
	while (i < size)
	{
		i++;
		if (is_extreme(nbr, info) && tmp->data > tmp->next->data)
			break;
		if (nbr > tmp->data && nbr < tmp->next->data)
			break;
		tmp = tmp->next;
	}
	info->ra = i;
	info->rra = size - i + 1;
}

void	find_path_in_b_length(int nbr, t_info *info)
{
	int	size;
	int	index;

	size = lstsize_pushswap(info, 'b');
	index = find_index(nbr, info, 'b') - 1;
	info->rb = index;
	info->rrb = size - index + 1;
}

int	analyze_path(t_info *info)
{
	int	smallest;

	smallest = info->ra + info->rrb;
	//info->tmp_move = 1;
	if (smallest > (info->rb + info->rra))
	{
		smallest = info->rb + info->rra;
		info->tmp_move = 2;
	}
	if (smallest > info->ra && smallest > info->rb)
	{
		if (info->ra > info->rb)
			smallest = info->ra;
		else
			smallest = info->rb;
		info->tmp_move = 3;
	}
	if (smallest > info->rra && smallest > info->rrb)
	{
		if (info->rra > info->rrb)
			smallest = info->rra;
		else
			smallest = info->rrb;
		info->tmp_move = 4;
	}
	return (smallest);
}

int	most_reachable_number(t_info *info)
{
	int	path_length;
	t_stack	*tmp;
	int	distance;
	int	nbr;

	path_length = 10000;
	tmp = info->first_b;
	nbr = tmp->data;
	while (tmp->next != info->first_b)
	{
		initialize_operations(info);
		find_path_in_a_length(tmp->data, info);
		find_path_in_b_length(tmp->data, info);
		distance = analyze_path(info);
		if (path_length > distance)
		{
			path_length = distance;
			nbr = tmp->data;
			info->move = info->tmp_move;
		}
		tmp = tmp->next;
	}
	return (nbr);
}
