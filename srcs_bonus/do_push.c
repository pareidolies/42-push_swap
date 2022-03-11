#include "../includes/checker.h"
#include "../libft/libft.h"

void    do_pa(t_info *info)
{
	if (!info->first_b)
		return;
	add_element_top(info->first_b->data, info, 'a');
	del_element_top(info, 'b');
	//ft_putstr_fd("pa\n", 1);
	//add_element_bottom(3, info, 'o');
	info->count++;
}

void    do_pb(t_info *info)
{
 	if (!info->first_a)
		return;
	add_element_top(info->first_a->data, info, 'b');
	del_element_top(info, 'a');
	//ft_putstr_fd("pb\n", 1);
	//add_element_bottom(4, info, 'o');
	info->count++;
}
