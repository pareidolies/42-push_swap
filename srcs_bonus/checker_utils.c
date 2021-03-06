/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:28:31 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:23:59 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	initialize_info(t_info *info)
{
	info->first_a = NULL;
	info->first_b = NULL;
	info->first_o = NULL;
	info->biggest = 0;
	info->smallest = 0;
	info->count = 0;
	info->error = 0;
}

void	fill_stack_a(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size)
	{
		add_element_bottom(info->tab[i], info, 'a');
		i++;
	}
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

int	*create_table(t_info *info, int size)
{
	int		i;
	int		*tab;
	t_stack	*tmp;

	i = 0;
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	tmp = info->first_a;
	while (i < size)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

void	free_stack(t_info *info, char c)
{
	int		i;
	int		size;
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
