# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 18:11:33 by greus-ro          #+#    #+#              #
#    Updated: 2024/02/07 20:22:32 by greus-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables..................................................

NAME=push_swap

CFLAGS=-Wall -Wextra -Werror -MMD -MP -g
#CFLAGS+= -g

LIBFT_DIR=./libft
LIBFT_INC_DIR=${LIBFT_DIR}/inc
LIBFT_LIB=${LIBFT_DIR}/libft.a

SRC_DIR=./src
BIN_DIR=.
OBJ_DIR=./obj

#SRC_FILES =	ft_actions.c \
			ft_primitives_px.c \
			ft_primitives_rrx.c \
			ft_primitives_rx.c \
			ft_primitives_sx.c \
			ft_push_swap.c \
			ft_stack.c \
			ft_stack2.c \
			ft_validations.c 

SRC_FILES =	ft_actions.c \
			ft_chunksort_utils.c 	\
			ft_chunksort_utils2.c 	\
			ft_chunksort.c	\
			ft_chunksort2.c	\
			ft_index.c	\
			ft_primitives_px.c \
			ft_primitives_rrx.c \
			ft_primitives_rx.c \
			ft_primitives_sx.c \
			ft_push_swap.c \
			ft_radixsort.c \
			ft_sort.c \
			ft_sort_size3.c \
			ft_sort_size5.c	\
			ft_sort_big_size.c	\
			ft_stack.c \
			ft_stack2.c \
			ft_validations.c 

#Rules.......................................................

OBJ_FILES = $(SRC_FILES:%.c=${OBJ_DIR}/%.o)
DEP_FILES = $(SRC_FILES:%.c=${OBJ_DIR}/%.d)

#Rules.......................................................

all: ${NAME}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${NAME} : ${LIBFT_LIB} ${OBJ_FILES}
	cc ${CFLAGS} -o $@ ${LIBFT_LIB} ${OBJ_FILES} 

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c Makefile
	cc ${CFLAGS} -I ${LIBFT_INC_DIR} -o $@ -c $<  

${LIBFT_LIB}:
	make -C ${LIBFT_DIR}

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.d

fclean: clean
	rm -f ${NAME}

re: fclean all

-include ${DEP_FILES}
#bonus:

.PHONY: all clean fclean re
