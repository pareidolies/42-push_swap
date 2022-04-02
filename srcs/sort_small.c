/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:27:23 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 14:48:15 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	sort_size_two(t_info *info)
{
	initialize_info(info);
	fill_stack_a(info);
	if (info->first_a->data > info->first_a->next->data)
		do_sa(info);
	print_instructions(info);
}

void	sort_size_three(t_info *info, int *tab, int x)
{
	if (x == 0)
	{
		initialize_info(info);
		fill_stack_a(info);
		if (is_sort(info))
			return ;
	}
	info->smallest = tab[0];
	info->middle = tab[1];
	info->biggest = tab[2];
	while (!is_sort(info))
	{
		if (info->first_a->data == info->middle
			&& info->first_a->next->data == info->biggest)
			do_rra(info);
		else if (info->first_a->data == info->biggest
			&& info->first_a->next->data == info->smallest)
			do_ra(info);
		else
			do_sa(info);
	}
	if (x == 0)
		print_instructions(info);
}

int	comparison(int small_value, t_info *info)
{
	if (find_index(small_value, info, 'a') <= lstsize_pushswap(info, 'a') / 2)
		return (1);
	return (0);
}

void	sort_size_four_or_five(t_info *info)
{
	int	small_value;

	initialize_info(info);
	fill_stack_a(info);
	if (is_sort(info))
		return ;
	while (lstsize_pushswap(info, 'a') > 3)
	{
		small_value = find_smallest(info, 'a');
		if (comparison(small_value, info))
			while (info->first_a->data != small_value)
				do_ra(info);
		else
			while (info->first_a->data != small_value)
				do_rra(info);
		do_pb(info);
	}
	info->small_tab = create_table(info, lstsize_pushswap(info, 'a'));
	info->size = 3;
	info->small_tab = sort_table(info->small_tab, info);
	sort_size_three(info, info->small_tab, 1);
	while (info->first_b != NULL)
		do_pa(info);
	print_instructions(info);
	free(info->small_tab);
}
