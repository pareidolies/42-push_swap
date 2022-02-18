#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    do_pa(t_info *info)
{
	if (!info->first_b)
		return;
	add_element_top_a(info->first_b->data, info);
	del_element_top_b(info);
}
