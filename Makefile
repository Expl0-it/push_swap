NAME        := push_swap
CC        := cc
FLAGS    := -Wall -Wextra -Werror 
RM		    := rm -f

LIBFT_PATH := ./libft
LIBFT := ./libft/libft.a

SRCS        :=      src/stack_init.c \
                          src/init_list_utils.c \
                          src/tiny_sort.c \
                          src/db_linked_list_utils.c \
                          src/error_free.c \
                          src/advanced_motions.c \
                          src/push_swap.c \
                          src/stack_utils.c \
                          src/main.c \
                          src/reverse_rotate.c \
                          src/push.c \
                          src/rotate.c \
                          src/swap.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}



${NAME}:	${OBJS} ${LIBFT}
			${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBFT}

all:		${NAME}

bonus:		all

${LIBFT}:
			make -C ${LIBFT_PATH} all

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.SILENT:

.PHONY:		all clean fclean re
