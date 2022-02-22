#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	find_index(int nbr, t_info *info, char stack_name)
{
	int	i;
	t_stack	*tmp;
	t_stack	*first;

	i = 0;
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
		i++;
	}
	return (i);
}

int	find_smallest(t_info *info, char stack_name)
{
	int	smallest;
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
	int     biggest;
	t_stack *tmp;
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
