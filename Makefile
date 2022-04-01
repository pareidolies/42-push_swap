SRCS			=  main.c \
			   adjust_reception_stack.c \
			   find_most_reachable_number.c \
			   sort_b.c \
			   take_shortest_path.c \
			   framing_tools.c \
			   check_errors.c \
			   operations_tools.c \
			   do_swap.c \
			   do_push.c \
			   do_rotate.c \
			   do_reverse_rotate.c \
			   sorting_tools.c \
			   sort_big.c \
			   sort_small.c \
			   find_loop.c \
			   push_elements_to_b.c \

BONUS			= checker.c \
			  get_next_line.c \
			  check_errors.c \
			  checker_utils.c \
			  do_push.c \
			  do_reverse_rotate.c \
			  do_rotate.c \
			  do_swap.c \
			  operations_tools.c \

SRCS_DIR		= srcs/

BONUS_DIR		= srcs_bonus/

SRCS_PATH	 	= $(SRCS:%=$(SRCS_DIR)%)

SRCS_B_PATH 	= $(BONUS:%=$(BONUS_DIR)%)

OBJS		 	= $(SRCS_PATH:%.c=%.o)

OBJS_BONUS		= $(SRCS_B_PATH:%.c=%.o)

NAME		 	= push_swap

NAME_BONUS		= checker

PATH_LIBFT		= -C libft --no-print-directory

LIBRARY			= ./libft/libft.a

INCS			= includes

RM		 		= rm -f

CC				= cc -Wall -Wextra -Werror -fsanitize=address

all:			${NAME}

$(NAME):		${OBJS}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(SRCS_PATH) $(LIBRARY) -o $(NAME)

clean:
			${RM} ${OBJS} ${OBJS_BONUS}
			$(MAKE) clean $(PATH_LIBFT)

fclean:			clean
			${RM} ${NAME} ${NAME_BONUS}
			$(MAKE) fclean $(PATH_LIBFT)

re:			fclean ${NAME}

bonus:			${OBJS_BONUS}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(SRCS_B_PATH) $(LIBRARY) -o $(NAME_BONUS)

.PHONY:			all clean fclean re bonus
