/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:27:29 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:17:56 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	find_index(int nbr, t_info *info, char stack_name)
{
	int		len;
	t_stack	*tmp;
	t_stack	*first;

	len = 1;
	if (stack_name == 'a')
	{
		tmp = info->first_a;
		first = info->first_a;
	}
	else
	{
		tmp = info->first_b;
		first = info->first_b;
	}
	while (tmp->next->data != first->data && tmp->data != nbr)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	find_smallest(t_info *info, char stack_name)
{
	int		smallest;
	t_stack	*tmp;
	t_stack	*first;

	if (stack_name == 'a')
	{
		smallest = info->first_a->data;
		tmp = info->first_a;
		first = info->first_a;
	}
	else
	{
		smallest = info->first_b->data;
		tmp = info->first_b;
		first = info->first_b;
	}
	while (tmp->next->data != first->data)
	{
		tmp = tmp->next;
		if (tmp->data < smallest)
			smallest = tmp->data;
	}
	return (smallest);
}

int	find_biggest(t_info *info, char stack_name)
{
	int		biggest;
	t_stack	*tmp;
	t_stack	*first;

	if (stack_name == 'a')
	{
		biggest = info->first_a->data;
		tmp = info->first_a;
		first = info->first_a;
	}
	else
	{
		biggest = info->first_b->data;
		tmp = info->first_b;
		first = info->first_b;
	}
	while (tmp->next->data != first->data)
	{
		tmp = tmp->next;
		if (tmp->data > biggest)
			biggest = tmp->data;
	}
	return (biggest);
}

int	is_sort(t_info *info)
{
	t_stack	*tmp;

	tmp = info->first_a;
	while (tmp->next != info->first_a)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
