#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	do_upward_move(int nbr, t_info *info, char stack_name)
{
	if (stack_name == 'a')
	{
		while (info->first_a->data != nbr)
		{
			do_ra(info);
		}
		do_pb(info);
	}
	else
	{
		if (info->biggest == 1)
		{
			while (info->first_b->data != nbr)
			{
				do_rb(info);
			}
			do_pa(info);
		}
		else
		{
			while (info->first_b->data != nbr)
			{
				do_rb(info);
			}
			do_pa(info);
			do_ra(info);
		}
	}
}

void	do_downward_move(int nbr, t_info *info, char stack_name)
{
	if (stack_name == 'a')
	{
		while (info->first_a->data != nbr)
		{
			do_rra(info);
		}
		do_pb(info);
	}
	else
	{
		if (info->biggest == 1)
		{
			while (info->first_b->data != nbr)
			{
				do_rrb(info);
			}
			do_pa(info);
		}
		else
		{
			while (info->first_b->data != nbr)
			{
				do_rrb(info);
			}
			do_pa(info);
			do_ra(info);
		}
	}
}

void	take_shortest_path(int nbr, t_info *info, char stack_name)
{
	int	distance;
	int	index;

	distance = lstsize_pushswap(info, stack_name);
	index = find_index(nbr, info, stack_name);
	if ((distance - index) > (distance / 2))
		do_upward_move(nbr, info, stack_name);
	else
		do_downward_move(nbr, info, stack_name);
}

int	most_reachable_number(t_info *info)
{
	int	center;
	int	smallest_index;
	int	biggest_index;

	center = lstsize_pushswap(info, 'b') / 2;
	smallest_index = find_index(find_smallest(info, 'b'), info, 'b');
	biggest_index = find_index(find_biggest(info, 'b'), info, 'b');
	if (absolute_value(center - smallest_index) > absolute_value(center - biggest_index))
	{
		info->smallest = 1;
		return (find_smallest(info, 'b'));
	}
		else
	{
		info->biggest = 1;
		return (find_biggest(info, 'b'));
	}
}

int	absolute_value(int nbr)
{
	if (nbr > 0)
		return (nbr);
	else
		return (nbr * (-1));
}
