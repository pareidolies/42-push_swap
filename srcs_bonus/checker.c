/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:28:16 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 14:17:36 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

int	number_of_args(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

int	fill_tab(char **arguments, t_info *info)
{
	info->j = 0;
	while (info->j < info->tab_size)
	{
		if (!check_integers(arguments[info->i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (!check_limits(arguments[info->i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		info->tab[info->j] = ft_atoi(arguments[info->i]);
		info->i++;
		info->j++;
	}
	info->size = info->tab_size;
	info->i = 0;
	if (!check_duplicates(info))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

char	**handle_arguments(int argc, char **argv, t_info *info)
{
	char	**arguments;

	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
		arguments = argv;
	initialize_info(info);
	if (argc == 2)
	{
		info->i = 0;
		info->tab_size = number_of_args(arguments);
	}
	else
	{
		info->i = 1;
		info->tab_size = argc - 1;
	}
	info->tab = malloc(sizeof(int) * info->tab_size);
	return (arguments);
}

void	free_info(t_info *info)
{
	free_stack(info, 'a');
	free_stack(info, 'b');
	free(info->tab);
}

int	main(int argc, char **argv)
{
	t_info	info;
	char	*line;
	char	**arguments;

	if (argc <= 1)
		return (0);
	if (argc >= 2)
	{
		arguments = handle_arguments(argc, argv, &info);
		if (!arguments[0] || !fill_tab(arguments, &info))
			return (0);
	}
	initialize_info(&info);
	fill_stack_a(&info);
	while (get_instruction(&line))
	{
		do_instruction(line, &info);
		if (info.error == 1)
			return (0);
	}
	print_result(&info);
	free_info(&info);
	return (0);
}
