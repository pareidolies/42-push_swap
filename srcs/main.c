#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	add_element_bottom_a(int nbr, t_info *info)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->data = nbr;
	if (!info->first_a)
	{
		new->next = new;
		new->prev = new;
		info->first_a = new;
	}
	else
	{
		new->next = info->first_a;
		new->prev = info->first_a->prev;
		info->first_a->prev = new;
		new->prev->next = new;
	}
}

void	add_element_top_a(int nbr, t_info *info)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->data = nbr;
	if (!info->first_a)
	{
		new->next = new;
		new->prev = new;
		info->first_a = new;
	}
	else
	{
		new->next = info->first_a;
		new->prev = info->first_a->prev;
		info->first_a->prev = new;
		new->prev->next = new;
		info->first_a = new;
	}
}

void    add_element_bottom_b(int nbr, t_info *info)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->data = nbr;
	if (!info->first_b)
	{
		new->next = new;
		new->prev = new;
		info->first_b = new;
	}
	else
	{
		new->next = info->first_b;
		new->prev = info->first_b->prev;
		info->first_b->prev = new;
		new->prev->next = new;
	}
}

void    add_element_top_b(int nbr, t_info *info)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->data = nbr;
	if (!info->first_b)
	{
		new->next = new;
		new->prev = new;
		info->first_b = new;
	}
	else
	{
		new->next = info->first_b;
		new->prev = info->first_b->prev;
		info->first_b->prev = new;
		new->prev->next = new;
		info->first_b = new;
	}
}

void	del_element_top_a(t_info *info)
{
	t_stack	*tmp;

	if (info->first_a->next == info->first_a)
	{
		free(info->first_a);
		info->first_a = NULL;
	}
	else
	{
		tmp = info->first_a;
		info->first_a = info->first_a->next;
		tmp->prev->next = info->first_a;
		info->first_a->prev = tmp->prev;
		free(tmp);
	}
}

void	del_element_top_b(t_info *info)
{
	t_stack *tmp;
	if (info->first_b->next == info->first_b)
	{
		printf("coucou");
		free(info->first_b);
		info->first_b = NULL;
	}
	else
	{
		tmp = info->first_b;
		info->first_b = info->first_b->next;
		tmp->prev->next = info->first_b;
		info->first_b->prev = tmp->prev;
		free(tmp);
	}
}

void	initialize_info(t_info *info)
{
	info->first_a = NULL;
	info->first_b = NULL;
}

void	display_stack(t_info *info)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = info->first_a;
	tmp_b = info->first_b;
	if (tmp_a && tmp_b)
	{
		printf("%15d  |  %-15d\n", tmp_a->data, tmp_b->data);
		while (tmp_a->next != info->first_a && tmp_b->next != info->first_b && tmp_a && tmp_b)
		{
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
			printf("%15d  |  %-15d\n", tmp_a->data, tmp_b->data);
		}
	}
	while (tmp_a && tmp_a->next != info->first_a)
	{
		tmp_a = tmp_a->next;
		printf("%15d  |  %-15s\n", tmp_a->data, "");
	}
	while (tmp_b && tmp_b->next != info->first_b)
	{
		tmp_b = tmp_b->next;
		printf("%15s  |  %-15d\n", "", tmp_b->data);
	}
	printf("%15s  |  %-15s\n", "Stack A", "Stack B");
}

int main(int argc, char **argv)
{
	int	i;
	t_info info;

	initialize_info(&info);
	add_element_top_a(ft_atoi(argv[1]), &info);
	i = 2;
	while (i < argc)
	{
		if (!check_integers(argv[i]) || !check_integers(argv[1]))
		{
			printf("Error 1\n");
			return (0);
		}
		if (!check_limits(argv[i]) || !check_limits(argv[1]))
		{
			printf("Error 2\n");
			return (0);
		}
		add_element_bottom_a(ft_atoi(argv[i]), &info);
		i++;
	}
	lstsize_pushswap(&info);
	create_table(&info);
	if (!check_duplicates(info.tab))
	{
		printf("Error 3\n");
		return (0);
	}
	info.tab = sort_table(info.tab);
	find_quarters(&info);
	find_deciles(&info);
	printf("quarter 0 : %d\n", info.quarters[0]);
	printf("quarter 1 : %d\n", info.quarters[1]);
	//do_sa(&info);
	//add_element_top_b(7, &info);
	//add_element_top_b(8, &info);
	//do_sb(&info);
	//printf("FIRST B : %d\n", info.first_b->data);
	//do_pa(&info);
	//do_downward_move(3, &info);
	//do_upward_move(7, &info);
	//do_upward_move(1, &info);
	create_batch(0, &info);
	sort_batch(&info);	
	create_batch(1, &info);	
	sort_batch(&info);	
	display_stack(&info);
	//printf("biggest : %d\n", find_biggest(&info));
	//printf("smallest : %d\n", find_smallest(&info));
	return (0);
}
