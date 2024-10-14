# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 17:07:34 by wcorrea-          #+#    #+#              #
#    Updated: 2024/10/14 21:29:13 by crocha-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moarbrainz

SRC = main.cpp Zombie.cpp zombieHorde.cpp 
INCLUDE = -I . 

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

$(NAME):
		${CC} ${CPPFLAGS} ${INCLUDE} ${SRC} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${NAME}

re: clean all

.PHONY: all clean re