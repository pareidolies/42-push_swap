/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:26:47 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 15:11:46 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	initialize_info(t_info *info)
{
	info->first_a = NULL;
	info->first_b = NULL;
	info->first_o = NULL;
	info->biggest = 0;
	info->smallest = 0;
	info->count = 0;
}

void	display_stack(t_info *info)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;

	tmp_a = info->first_a;
	tmp_b = info->first_b;
	i = 0;
	if (tmp_a && tmp_b)
	{
		printf("%15d  |  %-15d\n", tmp_a->data, tmp_b->data);
		i = 1;
		while (tmp_a->next != info->first_a
			&& tmp_b->next != info->first_b && tmp_a && tmp_b)
		{
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
			printf("%15d  |  %-15d\n", tmp_a->data, tmp_b->data);
		}
	}
	if (tmp_a)
	{
		if (i == 0)
			printf("%15d  |  %-15s\n", tmp_a->data, "");
		while (tmp_a && tmp_a->next != info->first_a)
		{
			tmp_a = tmp_a->next;
			printf("%15d  |  %-15s\n", tmp_a->data, "");
		}
	}
	if (tmp_b)
	{	
		if (i == 0)
			printf("%15s  |  %-15d\n", "", tmp_b->data);
		while (tmp_b && tmp_b->next != info->first_b)
		{	
			tmp_b = tmp_b->next;
			printf("%15s  |  %-15d\n", "", tmp_b->data);
		}
	}
	printf("%15s  |  %-15s\n", "Stack A", "Stack B");
}

void	fill_stack_a(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size)
	{
		add_element_bottom(info->tab[i], info, 'a');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;

	initialize_info(&info);
	i = 1;
	info.tab = malloc(sizeof(int) * (argc - 1));
	info.sort_tab = malloc(sizeof(int) * (argc - 1));
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!check_integers(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (!check_limits(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		info.tab[i - 1] = ft_atoi(argv[i]);
		info.sort_tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	info.size = argc - 1;
	info.sort_tab = sort_table(info.sort_tab, &info);
	i = 0;
	if (!check_duplicates(&info))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (info.size <= 1)
		return (0);
	if (info.size == 2)
		sort_size_two(&info);
	else if (info.size == 3)
		sort_size_three(&info, info.sort_tab, 0);
	else if (info.size == 4 || info.size == 5)
		sort_size_four_or_five(&info);
	else
		sort_big(&info);
	free_stack(&info, 'a');
	free_stack(&info, 'o');
	free(info.tab);
	free(info.sort_tab);
	return (0);
}
