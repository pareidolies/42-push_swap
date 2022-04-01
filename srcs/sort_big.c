/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:27:14 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:27:16 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	finish_sorting_a(t_info *info)
{
	int smallest;
	int size;
	int index;

	smallest = find_smallest(info, 'a');
	index = find_index(smallest, info, 'a');
	size = lstsize_pushswap(info, 'a');
	while (info->first_a->data != smallest)
	{
		if (index < size / 2)
			do_ra(info);
		else
			do_rra(info);
	}
}

void	print_one_instruction(int nbr)
{
	if (nbr == 0)
		ft_putstr_fd("sa\n", 1);
	if (nbr == 1)
		ft_putstr_fd("sb\n", 1);
	if (nbr == 2)
		ft_putstr_fd("ss\n", 1);
	if (nbr == 3)
		ft_putstr_fd("pa\n", 1);
	if (nbr == 4)
		ft_putstr_fd("pb\n", 1);
	if (nbr == 5)
		ft_putstr_fd("ra\n", 1);
	if (nbr == 6)
		ft_putstr_fd("rb\n", 1);
	if (nbr == 7)
		ft_putstr_fd("rr\n", 1);
	if (nbr == 8)
		ft_putstr_fd("rra\n", 1);
	if (nbr == 9)
		ft_putstr_fd("rrb\n", 1);
	if (nbr == 10)
		ft_putstr_fd("rrr\n", 1);
}

void	print_instructions(t_info *info)
{
	t_stack *tmp;

	tmp = info->first_o;
	if (tmp)
	{
		while (tmp->next != info->first_o)
		{
			print_one_instruction(tmp->data);
			tmp = tmp->next;
		}
		print_one_instruction(tmp->data);
	}
}

void	free_stack(t_info *info, char c)
{
	int	i;
	int	size;
	t_stack	*current;
	t_stack	*delete;

	i = 0;
	if (c == 'a')
		current = info->first_a;
	else if (c == 'b')
		current = info->first_b;
	else
		current = info->first_o;
	if (current)
	{
	size = lstsize_pushswap(info, c);
		while (i < size - 1)
		{
			delete = current;
			current = current->next;
			free(delete);
			i++;
		}
		free(current);
	}
}

void	sort_big(t_info *info)
{
	info->jump = 2;
	while (info->jump < 20)
	{
		initialize_info(info);
		fill_stack_a(info);
		if (is_sort(info))
			break;
		find_head(info);
		add_information_to_elements(info);
		push_elements_to_b(info);
		sort_elements_in_b(info);
		finish_sorting_a(info);
			if (info->size > 100)
			{
				if (info->count < 5500)
					break;
			}
			else
			{
				if (info->count < 700)
					break;
			}
		info->jump = info->jump + 2;
		free_stack(info, 'a');
		free_stack(info, 'o');
	}
	print_instructions(info);
}
