#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_rra(t_info *info)
{
	info->first_a = info->first_a->prev;
}

void    do_rrb(t_info *info)
{
	info->first_b = info->first_b->prev;
}

void    do_rrr(t_info *info)
{
	do_rra(info);
	do_rrb(info);
}
