#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_pb(t_info *info)
{
 	if (!info->first_a)
		return;
	add_element_top_b(info->first_a->data, info);
	del_element_top_a(info);
}
