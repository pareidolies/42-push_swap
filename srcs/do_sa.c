#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	do_sa(t_info *info)
{
	int	tmp;

	if (info->first_a)
	{
		tmp = info->first_a->data;
		info->first_a->data = info->first_a->next->data;
		info->first_a->next->data = tmp;
	}
}
