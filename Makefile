# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 13:47:55 by fboumell          #+#    #+#              #
#    Updated: 2022/01/31 11:50:35 by fboumell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC	= gcc

CFLAGS	= -Wall -Werror -Werror -g

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

RM	= rm -f

SRCS	= win_utils.c so_long.c read_map.c utils.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		check_map_struct.c check_map_compo.c initialize.c image.c moves.c\
		
OBJS = ${SRCS:.c=.o}

all	: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Ibass -I INCLUDES -o $@ -c $<

$(NAME): $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -I INCLUDES ${SRCS} -o ${NAME} $(FL_MLX)

clean :
	${RM} ${OBJS} ${OBJS_B}

fclean : clean
	${RM} ${NAME}

re : clean fclean

.PHONY	: clean fclean all re 