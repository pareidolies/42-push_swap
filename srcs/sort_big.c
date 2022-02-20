#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	batch_in_progress(int batch_id, t_info *info)
{
	t_stack *tmp;

	tmp = info->first_a;
	while (tmp->next->data != info->first_a->data)
	{
		if (tmp->data >= info->quarters[batch_id]
			&& tmp->data <= info->quarters[batch_id + 1])
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	create_batch(int batch_id, t_info *info)
{
	t_stack	*tmp;

	tmp = info->first_a;
	while (batch_in_progress(batch_id, info))
	{
		while (tmp->next->data != info->first_a->data)
		{
			if (tmp->data >= info->quarters[batch_id]
				&& tmp->data <= info->quarters[batch_id + 1])
			{
				if ((lstsize_pushswap(info) - find_index(tmp->data, info)) > (lstsize_pushswap(info) / 2))
				{
					do_upward_move(tmp->data, info);
				}
				else
				{
					do_downward_move(tmp->data, info);
				}
			}
			tmp = tmp->next;
		}
	}
}

void	sort_batch(t_info *info)
{
	int	nbr_to_sort;
	int	i;
	i = 0;
	while (info->first_b != NULL)
	{
		nbr_to_sort = find_smallest(info);
		do_upward_move_smallest(nbr_to_sort, info);
		i++;
	}
}
