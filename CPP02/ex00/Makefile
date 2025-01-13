# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 17:07:34 by crocha-s          #+#    #+#              #
#    Updated: 2025/01/12 15:02:51 by crocha-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRC = main.cpp Fixed.cpp

OBJS = ${SRC:.cpp=.o}

INCLUDE = -I .

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-pedantic

.cpp.o:
		${CC} ${CPPFLAGS} ${INCLUDE} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
		${CC} ${CPPFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: clean all

.PHONY: all clean re