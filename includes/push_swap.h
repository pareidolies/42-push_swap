#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	data;
	struct	s_stack *next;
	struct	s_stack *prev;
}		t_stack;

typedef struct s_info
{
	t_stack *first_a;
	t_stack *first_b;
	int	size;
	int	*tab;
	int	quarters[5];
	int	deciles[11];
	int	biggest;
	int	smallest;
}		t_info;

//main.c
int	main(int argc, char **argv);
void    display_stack(t_info *info);

//framing_tools.c
int     lstsize_pushswap(t_info *info, char stack_name);
void    create_table(t_info *info);
int     *sort_table(int *tab);

//check_errors.c
int	check_duplicates(int *tab);
int	check_limits(char *str);
int	check_integers(char *str);
int	is_space(char c);

//find_key_values.c
void	find_quarters(t_info *info);
void	find_deciles(t_info *info);

//operations_tools.c
void    add_element_bottom(int nbr, t_info *info, char stack_name);
void    add_element_top(int nbr, t_info *info, char stack_name);
void    del_element_top(t_info *info, char stack_name);

//do_swap.c
void    do_sa(t_info *info);
void    do_sb(t_info *info);
void    do_ss(t_info *info);

//do_push.c
void	do_pa(t_info *info);
void    do_pb(t_info *info);

//do_rotate.c
void    do_ra(t_info *info);
void    do_rb(t_info *info);
void    do_rr(t_info *info);

//do_reverse_rotate.c
void    do_rra(t_info *info);
void    do_rrb(t_info *info);
void    do_rrr(t_info *info);

//sorting_tools.c
int     find_index(int nbr, t_info *info, char stack_name);
int     find_smallest(t_info *info, char stack_name);
int     find_biggest(t_info *info, char stack_name);

//optimization_tools.c
void    do_upward_move(int nbr, t_info *info, char stack_name);
void    do_downward_move(int nbr, t_info *info, char stack_name);
void    take_shortest_path(int nbr, t_info *info, char stack_name);
int     most_reachable_number(t_info *info);
int     absolute_value(int nbr);

//sort_big.c
int     batch_in_progress(int batch_id, t_info *info);
int	is_in_batch_range(int nbr, int batch_id, t_info *info);
void    create_batch(int batch_id, t_info *info);
void    sort_batch(t_info *info);
void	finish_sorting_batch(int batch_id, t_info *info);
void	sort_big(t_info *info);

//sort_very_big.c
int	decile_batch_in_progress(int batch_id, t_info *info);
int	is_in_decile_batch_range(int nbr, int batch_id, t_info *info);
void	create_decile_batch(int batch_id, t_info *info);
void	sort_decile_batch(t_info *info);
void	finish_sorting_decile_batch(int batch_id, t_info *info);
void	sort_very_big(t_info *info);

#endif
