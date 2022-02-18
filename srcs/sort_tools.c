#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	find_index(int nbr, t_info *info)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = info->first_a;
	while (tmp->next->data != info->first_a->data && tmp->data != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_smallest(t_info *info)
{
	int	smallest;
	t_stack	*tmp;

	smallest = info->first_b->data;
	tmp = info->first_b;
	while (tmp->next->data != info->first_b->data)
	{
		tmp = tmp->next;
		if (tmp->data < smallest)
			smallest = tmp->data;
	}
	return (smallest);
}

int	find_biggest(t_info *info)
{
	int     biggest;
	t_stack *tmp;

	biggest = info->first_b->data;
	tmp = info->first_b;
	while (tmp->next->data != info->first_b->data)
	{
		tmp = tmp->next;
		if (tmp->data > biggest)
			biggest = tmp->data;
	}
	return (biggest);
}

void	do_upward_move(int nbr, t_info *info)
{
	while (info->first_a->data != nbr)
	{
		do_ra(info);
	}
	do_pb(info);
}

void	do_downward_move(int nbr, t_info *info)
{
	while (info->first_a->data != nbr)
	{
		do_rra(info);
	}
	do_pb(info);
}
