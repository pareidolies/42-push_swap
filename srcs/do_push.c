#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_pa(t_info *info)
{
	if (!info->first_b)
		return;
	add_element_top(info->first_b->data, info, 'a');
	del_element_top(info, 'b');
}

void    do_pb(t_info *info)
{
 	if (!info->first_a)
		return;
	add_element_top(info->first_a->data, info, 'b');
	del_element_top(info, 'a');
}
