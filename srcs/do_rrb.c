#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_rrb(t_info *info)
{
	info->first_b = info->first_b->prev;
}
