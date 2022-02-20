#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	is_space(char c)
{
	if (c == ' ' | c == '\t' | c == '\n' | c == '\v'
		| c == '\f' | c == '\r')
		return (1);
	return (0);
}

int	check_integers(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]) && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}


int	check_limits(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		if (ft_atoi(str) > 0)
			return (0);
		i++;
	}
	if (str[i] != '-')
	{
		if (ft_atoi(str) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	lstsize_pushswap(t_info *info)
{
	t_stack	*tmp;
	int	len;

	len = 1;
	tmp = info->first_a;
	tmp = tmp->next;
	while (tmp != info->first_a)
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
	info->size = lstsize_pushswap(info);
	info->tab = malloc(info->size * sizeof(int));
	tmp = info->first_a;
	while (i < info->size)
	{
		info->tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

int	check_duplicates(int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
