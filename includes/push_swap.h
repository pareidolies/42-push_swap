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
	int	quarters[4];
	int	deciles[10];
}		t_info;

typedef enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
}		t_operation;

//main.c
int	main(int argc, char **argv);
void    display_stack(t_info *info);
void    add_element(int nbr, t_info *info);
void    add_element_bottom_a(int nbr, t_info *info);
void    add_element_top_a(int nbr, t_info *info);
void    add_element_bottom_b(int nbr, t_info *info);
void    add_element_top_b(int nbr, t_info *info);
void    del_element_top_a(t_info *info);
void    del_element_top_b(t_info *info);

//check_errors.c
int     check_duplicates(int *tab);
void     create_table(t_info *info);
int  lstsize_pushswap(t_info *info);
int     check_limits(char *str);
int     check_integers(char *str);
int     is_space(char c);

//find_key_values.c
int     *sort_table(int *tab);
void	find_quarters(t_info *info);
void	find_deciles(t_info *info);

//do_sa.c
void    do_sa(t_info *info);

//do_sb.c
void    do_sb(t_info *info);

//do_ss.c
void    do_ss(t_info *info);

//do_pa.c
void	do_pa(t_info *info);

//do_pb.c
void    do_pb(t_info *info);

//do_ra.c
void    do_ra(t_info *info);

//do_rb.c
void    do_rb(t_info *info);

//do_rr.c
void    do_rr(t_info *info);

//do_rra.c
void    do_rra(t_info *info);

//do_rrb.c
void    do_rrb(t_info *info);

//do_rrr.c
void    do_rrr(t_info *info);

//sort_tools.c
int     find_index(int nbr, t_info *info);
int     find_smallest(t_info *info);
int     find_biggest(t_info *info);
void    do_upward_move(int nbr, t_info *info);
void    do_downward_move(int nbr, t_info *info);
void    do_upward_move_biggest(int nbr, t_info *info);
void    do_upward_move_smallest(int nbr, t_info *info);
void    do_downward_move_biggest(int nbr, t_info *info);
void    do_downward_move_biggest(int nbr, t_info *info);

//sort_big.c
int     batch_in_progress(int batch_id, t_info *info);
void    create_batch(int batch_id, t_info *info);
void    sort_batch(t_info *info);

#endif
