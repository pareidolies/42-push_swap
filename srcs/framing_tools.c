/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:26:40 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:11:45 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	lstsize_pushswap(t_info *info, char stack_name)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stack_name == 'a')
	{
		tmp = info->first_a;
		first = info->first_a;
	}
	else if (stack_name == 'b')
	{
		tmp = info->first_b;
		first = info->first_b;
	}
	else
	{
		tmp = info->first_o;
		first = info->first_o;
	}
	tmp = tmp->next;
	return (lstsize_pushswap_2(tmp, first));
}

int	lstsize_pushswap_2(t_stack *tmp, t_stack *first)
{
	int	len;

	len = 1;
	while (tmp != first)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
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

int	*sort_table(int *tab, t_info *info)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < info->size)
	{
		j = i + 1;
		while (j < info->size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
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
