/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:26:23 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:26:25 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	add_index_to_stack(t_info *info)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	while (i < info->size)
	{
		tmp = info->first_a;
		while (tmp->data != info->sort_tab[i])
		{
			tmp = tmp->next;
		}
		tmp->index = i;
		i++;
	}
}

void	is_in_place(t_info *info)
{
	t_stack *tmp;
	t_stack *prev_in_place;

	info->head->in_place = 1;
	prev_in_place = info->head;
	tmp = info->head->next;
	while (tmp->next != info->head)
	{
		if ((tmp->index - prev_in_place->index) < info->jump
			&& (tmp->index - prev_in_place->index) > 0)
		{
			prev_in_place = tmp;
			tmp->in_place = 1;
		}
		tmp = tmp->next;
	}
}

int	count_of_in_place(t_stack *head, int i)
{
	t_stack	*tmp;
	t_stack *prev_in_place;
	int	count;

	count = 0;
	prev_in_place = head;
	tmp = head->next;
	while (tmp->next != head)
	{
		if ((tmp->index - prev_in_place->index) < i
			&& (tmp->index - prev_in_place->index) > 0)
		{
			prev_in_place = tmp;
			count++;
		}
		tmp = tmp->next;
	}
	return (count);
}

void	find_head(t_info *info)
{
	t_stack *tmp;
	int greatest_count;
	
	add_index_to_stack(info);
	greatest_count = count_of_in_place(info->first_a, info->jump);
	info->head = info->first_a;
	tmp = info->first_a->next;
	while (tmp->next != info->first_a)
	{
		if (greatest_count < count_of_in_place(tmp, info->jump))
		{
			greatest_count = count_of_in_place(tmp, info->jump);
			info->head = tmp;
		}
		tmp = tmp->next;
	}
}

void	add_information_to_elements(t_info *info)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = info->first_a;
	while (i < info->size)
	{
		tmp->in_place = 0;
		tmp = tmp->next;
		i++;
	}
	is_in_place(info);
}

void	push_elements_to_b(t_info *info)
{
	t_stack *tmp;
	int	i;

	i = 0;
	tmp = info->first_a;
	while (i < info->size)
	{
		if (tmp->in_place == 1)
		{
			do_ra(info);
			i++;
		}
		else
		{
			do_pb(info);
			i++;
		}
		tmp = info->first_a;
	}
}
