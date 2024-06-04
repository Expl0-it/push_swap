# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 14:28:44 by mamichal          #+#    #+#              #
#    Updated: 2024/06/04 15:50:37 by mamichal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = push_swap_checker
ARCH = push_swap.a
CC = cc
FLAGS = -Wall -Wextra -Werror 
RM = rm -fr
INCLUDES = ./includes/push_swap.h
BONUS_INCLUDES = ./checker/checker.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = src/stack_init.c \
		src/init_list_utils.c \
		src/tiny_sort.c \
		src/db_linked_list_utils.c \
		src/error_free.c \
		src/advanced_motions.c \
		src/push_swap.c \
		src/stack_utils.c \
		src/reverse_rotate.c \
		src/push.c \
		src/rotate.c \
		src/swap.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = checker/checker.c \
				checker/get_next_line.h \
				checker/get_next_line.c \
				checker/get_next_line_utils.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -include $(INCLUDES)

${NAME}: ${ARCH} ${LIBFT}
	${CC} ${FLAGS} -o ${NAME} src/main.c ${ARCH} ${LIBFT} -include $(INCLUDES)

$(ARCH): $(OBJS)
	ar rcs $(ARCH) $(OBJS)

all: ${NAME}

bonus: $(NAME) $(BONUS_OBJS)
	${CC} ${FLAGS} -o ${NAME_BONUS} ${BONUS_OBJS} ${ARCH} ${LIBFT} -include $(INCLUDES) $(BONUS_INCLUDES)

${LIBFT}:
	make -C ${LIBFT_PATH} all

clean:
	@ ${RM} *.o */*.o */*/*.o
	@ ${RM} $(ARCH)
	echo Only Exec Left

fclean: clean
	@ ${RM} ${NAME} ${NAME_BONUS}
	echo All Clear

re: fclean all

.SILENT:

.PHONY: all clean fclean re
