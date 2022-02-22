#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_ra(t_info *info)
{
	info->first_a = info->first_a->next;
}

void    do_rb(t_info *info)
{
	info->first_b = info->first_b->next;
}

void    do_rr(t_info *info)
{
	do_ra(info);
	do_rb(info);
}
