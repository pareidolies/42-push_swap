/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:12:09 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 12:11:57 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	free_all(t_info *info)
{
	free_stack(info, 'a');
	free_stack(info, 'o');
	free(info->tab);
	free(info->sort_tab);
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
