#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	sort_size_two(t_info *info)
{
	initialize_info(info);
	fill_stack_a(info);
	if (info->first_a->data > info->first_a->next->data)
		do_sa(info);
	print_instructions(info);
}

void	sort_size_three(t_info *info, int *tab, int x)
{
	t_stack *first;

	if (x == 0)
	{
		initialize_info(info);
		fill_stack_a(info);
		if (is_sort(info))
		{
			return;
		}
	}
	first = info->first_a;
	info->smallest = tab[0];
	info->middle = tab[1];
	info->biggest = tab[2];
	while (!is_sort(info))
	{
		if (first->data == info->middle && first->next->data == info->biggest)
			do_rra(info);
		else if (first->data == info->biggest && first->next->data == info->smallest)
			do_ra(info);
		else
			do_sa(info);
	}
	if (x == 0)
		print_instructions(info);
}

void sort_size_four_or_five(t_info *info)
{
	int	small_value;

	initialize_info(info);
	fill_stack_a(info);
	if (is_sort(info))
		return;
	while (lstsize_pushswap(info, 'a') > 3)
	{
		small_value = find_smallest(info, 'a');
		if (find_index(small_value, info, 'a') < lstsize_pushswap(info, 'a') / 2)
			while (info->first_a->data != small_value)
				do_ra(info);
		else
			while (info->first_a->data != small_value)
				do_rra(info);
		do_pb(info);
	}
	info->small_tab = create_table(info, lstsize_pushswap(info, 'a'));
	info->size = 3;
	info->small_tab = sort_table(info->small_tab, info);
	sort_size_three(info, info->small_tab, 1);
	while (info->first_b != NULL)
		do_pa(info);	
	print_instructions(info);
	free(info->small_tab);
}
