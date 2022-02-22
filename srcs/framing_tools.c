#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	lstsize_pushswap(t_info *info, char stack_name)
{
	t_stack	*tmp;
	t_stack	*first;
	int	len;

	len = 0;
	if (stack_name == 'a')
	{
		tmp = info->first_a;
		first = info->first_a;
	}
	else
	{
		tmp = info->first_b;
		first = info->first_b;
	}
	tmp = tmp->next;
	while (tmp != first)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	create_table(t_info *info)
{
	int	i;
	t_stack *tmp;

	i = 0;
	info->size = lstsize_pushswap(info, 'a');
	info->tab = malloc(info->size * sizeof(int));
	tmp = info->first_a;
	while (i < info->size)
	{
		info->tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

int	*sort_table(int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
