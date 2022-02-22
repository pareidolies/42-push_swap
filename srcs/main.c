#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	initialize_info(t_info *info)
{
	info->first_a = NULL;
	info->first_b = NULL;
	info->biggest = 0;
	info->smallest = 0;
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
	int	index;
	t_info info;

	initialize_info(&info);
	add_element_top(ft_atoi(argv[1]), &info, 'a');
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
		add_element_bottom(ft_atoi(argv[i]), &info, 'a');
		i++;
	}
	display_stack(&info);
	printf("SIZE : %d\n", info.size);
	create_table(&info);
	if (!check_duplicates(info.tab))
	{
		printf("Error 3\n");
		return (0);
	}
	info.tab = sort_table(info.tab);
	find_quarters(&info);
	find_deciles(&info);
	index = find_index(4, &info, 'a');
	printf("quarter 0 : %d\n", info.quarters[0]);
	printf("quarter 1 : %d\n", info.quarters[1]);
	printf("index de 4 : %d\n", index);
	sort_big(&info);	
	display_stack(&info);
	//printf("biggest : %d\n", find_biggest(&info));
	//printf("smallest : %d\n", find_smallest(&info));
	return (0);
}
