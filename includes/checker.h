#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "push_swap.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
# endif

//checker.c
int	main(int argc, char **argv);
void    do_instruction(char *str, t_info *info);
char    *get_instruction(char **line);

//get_next_line.c
char		*get_next_line(int fd);
char     *ft_returnline(char **str);
void     ft_read(int fd, char *buf, char **str);

#endif
