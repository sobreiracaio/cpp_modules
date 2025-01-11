# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 17:07:34 by crocha-s          #+#    #+#              #
#    Updated: 2025/01/11 18:57:30 by crocha-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = main.cpp Phonebook.cpp Contact.cpp
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