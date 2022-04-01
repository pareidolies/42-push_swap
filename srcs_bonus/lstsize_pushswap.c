#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	lstsize_pushswap(t_info *info, char stack_name)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stack_name == 'a')
	{
		tmp = info->first_a;
		first = info->first_a;
	}
	else if (stack_name == 'b')
	{
		tmp = info->first_b;
		first = info->first_b;
	}
	else
	{
		tmp = info->first_o;
		first = info->first_o;
	}
	tmp = tmp->next;
	return (lstsize_pushswap_2(tmp, first));
}

int	lstsize_pushswap_2(t_stack *tmp, t_stack *first)
{
	int	len;

	len = 1;
	while (tmp != first)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
