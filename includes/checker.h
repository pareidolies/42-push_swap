/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:29:41 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/01 15:10:58 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int		main(int argc, char **argv);
void	do_instruction(char *str, t_info *info);
char	*get_instruction(char **line);

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_returnline(char **str);
void	ft_read(int fd, char *buf, char **str);

//lstsize_pushswap.c
int     lstsize_pushswap(t_info *info, char stack_name);
int     lstsize_pushswap_2(t_stack *tmp, t_stack *first);

#endif
