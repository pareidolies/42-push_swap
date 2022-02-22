SRCS			=  main.c \
			   framing_tools.c \
			   check_errors.c \
			   find_key_values.c \
			   operations_tools.c \
			   do_swap.c \
			   do_push.c \
			   do_rotate.c \
			   do_reverse_rotate.c \
			   sorting_tools.c \
			   optimization_tools.c \
			   sort_big.c \

BONUS			= checker.c \

SRCS_DIR		= srcs/

BONUS_DIR		= srcs_bonus/

SRCS_PATH	 	= $(SRCS:%=$(SRCS_DIR)%)

SRCS_B_PATH 		= $(BONUS:%=$(BONUS_DIR)%)

OBJS		 	= $(SRCS_PATH:%.c=%.o)

OBJS_BONUS		= $(SRCS_B_PATH:%.c=%.o)

NAME		 	= push_swap

PATH_LIBFT		= -C libft --no-print-directory

LIBRARY			= ./libft/libft.a

INCS			= includes

RM		 	= rm -f

CC			= cc -Wall -Wextra -Werror

all:			${NAME}

$(NAME):		${OBJS}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I $(INCS) $(SRCS_PATH) $(LIBRARY) -o $(NAME)

clean:
			${RM} ${OBJS} ${OBJS_BONUS}
			$(MAKE) clean $(PATH_LIBFT)

fclean:			clean
			${RM} ${NAME}
			$(MAKE) fclean $(PATH_LIBFT)

re:			fclean ${NAME}

bonus:			${OBJS_BONUS}
			$(MAKE) $(PATH_LIBFT)
			$(CC) -I include $(SRCS_B_PATH) $(LIBRARY) -o $(NAME)

.PHONY:			all clean fclean re bonus
