#include "../includes/checker.h"
#include "../libft/libft.h"

void    do_ra(t_info *info)
{
	info->first_a = info->first_a->next;
	//ft_putstr_fd("ra\n", 1);
	//add_element_bottom(5, info, 'o');
	info->count++;
}

void    do_rb(t_info *info)
{
	info->first_b = info->first_b->next;
	//ft_putstr_fd("rb\n", 1);
	//add_element_bottom(6, info, 'o');
	info->count++;
}

void    do_rr(t_info *info)
{
	info->first_a = info->first_a->next;
	info->first_b = info->first_b->next;
	//ft_putstr_fd("rr\n", 1);
	//add_element_bottom(7, info, 'o');
	info->count++;
}
