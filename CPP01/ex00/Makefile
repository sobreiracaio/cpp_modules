# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 17:07:34 by wcorrea-          #+#    #+#              #
#    Updated: 2025/01/10 15:18:53 by crocha-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainz

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
INCLUDE = -I . 

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-pedantic

$(NAME):
		${CC} ${CPPFLAGS} ${INCLUDE} ${SRC} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${NAME}

re: clean all

.PHONY: all clean re