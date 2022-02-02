# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 13:47:55 by fboumell          #+#    #+#              #
#    Updated: 2022/02/02 10:18:40 by fboumell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC	= clang

CFLAGS	= -Wall -Werror -Werror -g

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

RM	= rm -f

SRCS	= win_utils.c so_long.c read_map.c utils.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		check_map_struct.c check_map_compo.c initialize.c image.c moves.c

BONUS	= win_utils_bonus.c so_long_bonus.c read_map_bonus.c utils_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		check_map_struct_bonus.c check_map_compo_bonus.c initialize_bonus.c image_bonus.c moves_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

all	: ${NAME}

$(NAME) : $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -I mlx/libmlx_Linux.a ${OBJS} -o ${NAME} $(FL_MLX)

${NAME_BONUS} : ${OBJS_BONUS}
	make -s -C ./mlx
	${CC} ${CFLAGS} -I mlx/libmlx_Linux.a ${OBJS_BONUS} -o ${NAME_BONUS} $(FL_MLX)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Ibass -I mlx/libmlx_Linux.a -o $@ -c $<

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY	: clean fclean all re bonus