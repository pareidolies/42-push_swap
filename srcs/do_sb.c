#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_sb(t_info *info)
{
	int     tmp;

	if (info->first_b)
	{
		tmp = info->first_b->data;
		info->first_b->data = info->first_b->next->data;
		info->first_b->next->data = tmp;
	}
}
