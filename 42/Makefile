# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 18:11:33 by greus-ro          #+#    #+#              #
#    Updated: 2024/02/06 14:40:31 by greus-ro         ###   ########.fr        #
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
BIN_DIR=./bin
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


OBJ_FILES = $(SRC_FILES:%.c=${OBJ_DIR}/%.o)

#Rules.......................................................

all: ${BIN_DIR}/${NAME}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${BIN_DIR}/${NAME} : ${LIBFT_LIB} ${BIN_DIR} ${OBJ_DIR} ${OBJ_FILES}
#	cc ${CFLAGS} -o $@ ${LIBFT_LIB} ${OBJ_FILES} 
	cc ${CFLAGS} -o $@ ${OBJ_FILES} ${LIBFT_LIB}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c Makefile
	cc ${CFLAGS} -I ${LIBFT_INC_DIR} -o $@ -c $<  

${LIBFT_LIB}:
	make all -C ${LIBFT_DIR}

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.d

fclean: clean
	rm -f ${BIN_DIR}/*

re: fclean all

#bonus:

.PHONY: all clean fclean re
