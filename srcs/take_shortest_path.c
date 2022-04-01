/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:27:38 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 12:27:39 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	take_shortest_path(int nbr, t_info *info, char stack_name)
{
	int	size;
	int	index;
	int	i;

	i = 0;
	size = lstsize_pushswap(info, stack_name);
	index = find_index(nbr, info, stack_name) - 1;
	if (info->move == 2 || info->move == 3)
		while (i < index)
		{
			info->rb++;
			i++;
		}
	if (info->move == 1 || info->move == 4)
		while (i < (size - index))
		{
			info->rrb++;
			i++;
		}
}

int	is_extreme(int nbr, t_info *info)
{
	int smallest;
	int biggest;

	smallest = find_smallest(info, 'a');
	biggest = find_biggest(info, 'a');
	if (nbr < smallest || nbr > biggest)
		return (1);
	return (0);
}
