#include "../libft/libft.h"
#include "../includes/checker.h"

void	do_instruction(char *str, t_info *info)
{
	size_t	len;

	len = ft_strlen(str);
	if (ft_strncmp(str, "sa\n", len) == 0)
		do_sa(info);
	else if (ft_strncmp(str, "sb\n", len) == 0)
		do_sb(info);
	else if (ft_strncmp(str, "ss\n", len) == 0)
		do_ss(info);
	else if (ft_strncmp(str, "pa\n", len) == 0)
		do_pa(info);
	else if (ft_strncmp(str, "pb\n", len) == 0)
		do_pb(info);
	else if (ft_strncmp(str, "ra\n", len) == 0)
		do_ra(info);
	else if (ft_strncmp(str, "rb\n", len) == 0)
		do_rb(info);
	else if (ft_strncmp(str, "rr\n", len) == 0)
		do_rr(info);
	else if (ft_strncmp(str, "rra\n", len) == 0)
		do_rra(info);
	else if (ft_strncmp(str, "rrb\n", len) == 0)
		do_rrb(info);
	else if (ft_strncmp(str, "rrr\n", len) == 0)
		do_rrr(info);
	else
		ft_putstr_fd("Error\n", 2);
}

char	*get_instruction(char **line)
{
	*line = get_next_line(0);
	return (*line);
}

int	main(int argc, char **argv)
{
	int	i;
	t_info	info;
	char	*line;

	initialize_info(&info);
	i = 1;
	info.tab = malloc(sizeof(int) * (argc - 1));
	//info.sort_tab = malloc(sizeof(int) * (argc - 1));
	if (argc <= 1)
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
		//info.sort_tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	info.size = argc - 1;
	//info.sort_tab = sort_table(info.sort_tab, &info);
	i = 0;
	if (!check_duplicates(&info))
	{
		ft_putstr_fd("Error\n", 2);
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
	//free_stack(&info, 'o');
	free(info.tab);
	return(0);
}
