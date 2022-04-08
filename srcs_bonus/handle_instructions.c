/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:28:22 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 14:20:39 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/checker.h"

void	instruction_error(t_info *info)
{
	info->error = 1;
	ft_putstr_fd("Error\n", 2);
}

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
		instruction_error(info);
}

char	*get_instruction(char **line)
{
	*line = get_next_line(0);
	return (*line);
}

void	print_result(t_info *info)
{
	if (is_sort(info))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
