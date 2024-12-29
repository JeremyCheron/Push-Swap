# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 15:12:51 by jcheron           #+#    #+#              #
#    Updated: 2024/12/29 10:37:40 by jcheron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM					=		/usr/bin/rm -f
ECHO				=		/usr/bin/echo

# ############################################################################ #
#                                                                              #
#                           Variables                                          #
#                                                                              #
# ############################################################################ #

NAME				:=		push_swap
CC					:=		gcc
CFLAGS				:=		-Wall -Werror -Wextra -I libft -g
RM					:=		rm -rf
LIBFT_PATH			:=		libft/
LIBFT				:=		libft/libft.a
# include	srcs.mk

SRCS =	src/push_swap/commands/push.c src/push_swap/commands/rev_rotate.c		\
		src/push_swap/commands/rotate.c src/push_swap/commands/swap.c			\
		src/push_swap/errors/handle_errors.c									\
		src/push_swap/init/init_a_to_b.c src/push_swap/init/init_b_to_a.c		\
		src/push_swap/init/split.c src/push_swap/init/stack_init.c			\
		src/push_swap/sorts/sort_stacks.c src/push_swap/sorts/sort_three.c	\
		src/push_swap/sorts/stack_utils.c src/push_swap/push_swap.c

OBJS				=		$(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re norminette

all:	$(NAME)

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re:		fclean all

norminette:
		@norminette $(SRC_DIR) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
		&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
		|| $(ECHO) -e '\033[1;32mNorminette OK!'
