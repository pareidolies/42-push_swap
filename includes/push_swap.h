/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:29:47 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/08 14:15:21 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
	int				in_place;
}		t_stack;

typedef struct s_info
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*head;
	t_stack	*head_final;
	t_stack	*first_o;
	int		i;
	int		j;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		move;
	int		jump;
	int		tmp_move;
	int		size;
	int		tab_size;
	int		*tab;
	int		*sort_tab;
	int		*small_tab;
	int		biggest;
	int		smallest;
	int		middle;
	int		count;
	int		error;
}		t_info;

//main.c
int		main(int argc, char **argv);
char	**handle_arguments(int argc, char **argv, t_info *info);
int		fill_tab(char **arguments, t_info *info);
int		number_of_args(char **list);
void	initialize_info(t_info *info);

//framing_tools.c
void	fill_stack_a(t_info *info);
int		*sort_table(int *tab, t_info *info);
int		*create_table(t_info *info, int size);
int		lstsize_pushswap_2(t_stack *tmp, t_stack *first);
int		lstsize_pushswap(t_info *info, char stack_name);

//check_errors.c
int		check_duplicates(t_info *info);
int		check_limits(char *str);
int		check_integers(char *str);
int		is_space(char c);

//operations_tools.c
void	del_element_top(t_info *info, char stack_name);
void	add_element_top(int nbr, t_info *info, char stack_name);
void	add_element_bottom(int nbr, t_info *info, char stack_name);

//do_swap.c
void	do_sa(t_info *info);
void	do_sb(t_info *info);
void	do_ss(t_info *info);

//do_push.c
void	do_pa(t_info *info);
void	do_pb(t_info *info);

//do_rotate.c
void	do_ra(t_info *info);
void	do_rb(t_info *info);
void	do_rr(t_info *info);

//do_reverse_rotate.c
void	do_rra(t_info *info);
void	do_rrb(t_info *info);
void	do_rrr(t_info *info);

//sort_big.c
void	sort_big(t_info *info);
void	sort_big_investigation(t_info *info);
void	print_instructions(t_info *info);
void	print_one_instruction(int nbr);
void	finish_sorting_a(t_info *info);

//sort_b.c
void	sort_elements_in_b(t_info *info);
void	do_standard_operations(t_info *info);
void	do_joint_operations(t_info *info);
void	initialize_operations(t_info *info);

//find_loop.c
void	add_information_to_elements(t_info *info);
void	find_head(t_info *info);
int		count_of_in_place(t_stack *head, int i);
void	is_in_place(t_info *info);
void	add_index_to_stack(t_info *info);

//find_most_reachable_number.c
int		most_reachable_number(t_info *info);
int		analyze_path(t_info *info);
void	find_path_in_b_length(int nbr, t_info *info);
void	find_path_in_a_length(int nbr, t_info *info);

//take_shortest_path.c
int		is_extreme(int nbr, t_info *info);
void	take_shortest_path(int nbr, t_info *info, char stack_name);

//push_elements_to_b.c
void	push_elements_to_b(t_info *info);

//sorting_tools.c
int		find_index(int nbr, t_info *info, char stack_name);
int		find_smallest(t_info *info, char stack_name);
int		find_biggest(t_info *info, char stack_name);
int		is_sort(t_info *info);

//adjust_reception_stack.c
void	adjust_reception_stack_1(int nbr, t_info *info);
void	adjust_reception_stack_2(int j, int size, t_info *info);

//sort_small.c
void	sort_size_two(t_info *info);
void	sort_size_three(t_info *info, int *tab, int x);
int		comparison(int small_value, t_info *info);
void	sort_size_four_or_five(t_info *info);

//free.c
void	free_stack(t_info *info, char c);
void	free_all(t_info *info);

#endif
