# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 13:47:55 by fboumell          #+#    #+#              #
#    Updated: 2021/12/16 14:47:15 by fboumell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC	= gcc

CFLAGS	= -Wall -Werror -Werror

RM	= rm -f

#SRCS	=

#SRCS_B = 

OBJS = ${SRCS:.c=.o}

#OBJS_B = ${SRCS_B:.c=.o}

all	: ${NAME}

#$(NAME) : $(OBJS) ${OBJS_B}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean :
	${RM} ${OBJS} ${OBJS_B}

fclean : clean
	${RM} ${NAME}

re : clean fclean

.PHONY	: clean fclean all re #bonus