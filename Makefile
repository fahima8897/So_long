# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 13:47:55 by fboumell          #+#    #+#              #
#    Updated: 2021/12/21 14:39:25 by fboumell         ###   ########.fr        #
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

#For object files, you could add the following rule 
#to your makefile, assuming that you have the mlx 
#source in a directory named mlx in the root of your project:
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

#$(NAME) : $(OBJS) ${OBJS_B}
#	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

#$(NAME): $(OBJS) $(OBJS_B)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#pour linker l'API macos interne necessaire faire la commade audessus
clean :
	${RM} ${OBJS} ${OBJS_B}

fclean : clean
	${RM} ${NAME}

re : clean fclean

.PHONY	: clean fclean all re #bonus