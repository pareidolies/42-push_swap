#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	decile_batch_in_progress(int batch_id, t_info *info)
{
	t_stack *tmp;

	tmp = info->first_a;
	while (tmp->next->data != info->first_a->data)
	{
		if (tmp->data >= info->deciles[batch_id]
			&& tmp->data <= info->deciles[batch_id + 1])
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_in_decile_batch_range(int nbr, int batch_id, t_info *info)
{
	if (nbr >=info->deciles[batch_id] && nbr <= info->deciles[batch_id + 1])
		return (1);
	return (0);
}

void	create_decile_batch(int batch_id, t_info *info)
{
	t_stack	*tmp;

	tmp = info->first_a;
	while (decile_batch_in_progress(batch_id, info))
	{
		while (tmp->next->data != info->first_a->data)
		{
			if (is_in_decile_batch_range(tmp->data, batch_id, info))
				take_shortest_path(tmp->data, info, 'a');
			tmp = tmp->next;
		}
	}
}

void	sort_decile_batch(t_info *info)
{
	int	nbr_to_sort;
	int	i;
	int	value;

	i = 0;
	value = lstsize_pushswap(info, 'b') / 2;
	while (info->first_b != NULL)
	{
		nbr_to_sort = most_reachable_number(info);
		take_shortest_path(nbr_to_sort, info, 'b');
		info->smallest = 0;
		info->biggest = 0;
		i++;
	}
}

void	finish_sorting_decile_batch(int batch_id, t_info *info)
{
	while (is_in_decile_batch_range(info->first_a->data, batch_id, info))
		do_ra(info);
}

void	sort_very_big(t_info *info)
{
	int	batch_id;

	batch_id = 0;
	while (batch_id < 10)
	{
		create_decile_batch(batch_id, info);
		sort_decile_batch(info);
		finish_sorting_decile_batch(batch_id, info);
		batch_id++;
	}
}
