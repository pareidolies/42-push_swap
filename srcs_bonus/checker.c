/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:28:16 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 14:53:35 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	do_instruction(char *str, t_info *info)
{
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		do_sa(info);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		do_sb(info);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		do_ss(info);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		do_pa(info);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		do_pb(info);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		do_ra(info);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		do_rb(info);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		do_rr(info);
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		do_rra(info);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		do_rrb(info);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		do_rrr(info);
	else
		ft_putstr_fd("Error\n", 2);
}

char	*get_instruction(char **line)
{
	*line = get_next_line(0);
	return (*line);
}

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

int	main(int argc, char **argv)
{
	t_info	info;
	char	*line;
	char	**arguments;

	if (argc == 1)
		return (0);
	if (argc >= 2)
	{
		arguments = handle_arguments(argc, argv, &info);
		if (!fill_tab(arguments, &info))
			return (0);
	}
	initialize_info(&info);
	fill_stack_a(&info);
	while (get_instruction(&line))
		do_instruction(line, &info);
	if (is_sort(&info))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&info, 'a');
	free_stack(&info, 'b');
	free(info.tab);
	return (0);
}
