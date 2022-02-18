#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_rra(t_info *info)
{
	info->first_a = info->first_a->prev;
}
