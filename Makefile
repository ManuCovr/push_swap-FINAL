# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 15:50:04 by mde-maga          #+#    #+#              #
#    Updated: 2024/07/30 22:12:33 by mde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME = push_swap
SRCS =  $(wildcard *.c)
OBJS = ${SRCS:.c=.o}
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf

# Source
SRCS = push.c \
								reverse.c \
								rotate.c \
								sort_stack.c \
								sort_three.c \
								swap.c \
								error.c \
								init_a_to_b.c \
								init_b_to_a.c \
								push_swap.c \
								split.c \
								stack_init.c \
								stack_utils.c \
								stack_utils2.c \
								stack_utils3.c

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "Compiled successfully!"

clean:
	@${RM} ${OBJS}
	@echo "Cleaned!"

fclean: clean
	@${RM} ${NAME}
	@echo "Fully cleaned!"

re: fclean all

.PHONY: all clean fclean re