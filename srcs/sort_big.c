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
	while (batch_in_progress(0, info))
	{
		while (tmp->next->data != info->first_a->data)
		{
			if (tmp->data >= info->quarters[batch_id]
				&& tmp->data <= info->quarters[batch_id + 1])
				do_downward_move(tmp->data, info);
			tmp = tmp->next;
		}
	}
}

void	sort_batch(t_info *info)
{
	while (info->first_b != NULL)
	{

	}


}
