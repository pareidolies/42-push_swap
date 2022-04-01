/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:26:54 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:26:55 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	add_element_bottom(int nbr, t_info *info, char stack_name)
{
	t_stack	*new;
	t_stack	**first;

	new = malloc(sizeof(t_stack));
	new->data = nbr;
	if (stack_name == 'a')
		first = &info->first_a;
	else if (stack_name == 'b')
		first = &info->first_b;
	else
		first = &info->first_o;
	if (!(*first))
	{
		new->next = new;
		new->prev = new;
		(*first) = new;
	}
	else
	{
		new->next = (*first);
		new->prev = (*first)->prev;
		(*first)->prev = new;
		new->prev->next = new;
	}
}

void	add_element_top(int nbr, t_info *info, char stack_name)
{
	t_stack *new;
	t_stack	**first;

	new = malloc(sizeof(t_stack));
	new->data = nbr;
	if (stack_name == 'a')
		first = &info->first_a;
	else
		first = &info->first_b;
	if (!(*first))
	{
		new->next = new;
		new->prev = new;
		(*first) = new;
	}
	else
	{
		new->next = (*first);
		new->prev = (*first)->prev;
		(*first)->prev = new;
		new->prev->next = new;
		(*first) = new;
	}
}

void	del_element_top(t_info *info, char stack_name)
{
	t_stack	*tmp;
	t_stack	**first;

	if (stack_name == 'a')
		first = &info->first_a;
	else
		first = &info->first_b;
	if ((*first)->next == *first)
	{
		free(*first);
		*first = NULL;
	}
	else
	{
		tmp = (*first);
		(*first) = (*first)->next;
		tmp->prev->next = (*first);
		(*first)->prev = tmp->prev;
		free(tmp);
	}
}
