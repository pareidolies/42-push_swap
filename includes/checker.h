/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:29:41 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 14:14:35 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "push_swap.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4

//checker.c
int		main(int argc, char **argv);
void	free_info(t_info *info);
char	**handle_arguments(int argc, char **argv, t_info *info);
int		fill_tab(char **arguments, t_info *info);
int		number_of_args(char **list);

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_returnline(char **str);
void	ft_read(int fd, char *buf, char **str);

//lstsize_pushswap.c
int		lstsize_pushswap(t_info *info, char stack_name);
int		lstsize_pushswap_2(t_stack *tmp, t_stack *first);

//check_errors.c
int		is_space(char c);
int		check_integers(char *str);
int		check_limits(char *str);
int		check_duplicates(t_info *info);

//checker_utils.c
void	initialize_info(t_info *info);
void	fill_stack_a(t_info *info);
int		is_sort(t_info *info);
int		*create_table(t_info *info, int size);
void	free_stack(t_info *info, char c);

//handle_instructions.c
void	instruction_error(t_info *info);
void	do_instruction(char *str, t_info *info);
char	*get_instruction(char **line);
void	print_result(t_info *info);

//do_push.c
void	do_pa(t_info *info);
void	do_pb(t_info *info);

//do_reverse_rotate.c
void	do_rra(t_info *info);
void	do_rrb(t_info *info);
void	do_rrr(t_info *info);

//do_rotate.c
void	do_ra(t_info *info);
void	do_rb(t_info *info);
void	do_rr(t_info *info);

//do_swap.c
void	do_sa(t_info *info);
void	do_sb(t_info *info);
void	do_ss(t_info *info);

//operations_tools.c
void	add_element_bottom(int nbr, t_info *info, char stack_name);
void	add_element_top(int nbr, t_info *info, char stack_name);
void	del_element_top(t_info *info, char stack_name);

#endif
