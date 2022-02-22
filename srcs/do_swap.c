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

void    do_ss(t_info *info)
{
	do_sa(info);
	do_sb(info);
}
