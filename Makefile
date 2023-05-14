NAME = so_long

SRC = so_long.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CC = gcc
FLAG = -Werror -Wextra - Wall -g

OBJS = $(SRC:.c=.o)

LIBFT = libft/
PRINTF = ft_printf/
MINILIBX = mlx_linux/

LIBS = $(LIBFT)libft.a $(PRINTF)libftprintf.a 

RM = rm -f

CC = gcc -Wall -Wextra -Werror -g

.c.o = ${CC} -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C $(LIBFT)
	make -C $(PRINTF)
	make -C $(MINILIBX)
	$(CC) $(OBJS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)
	${RM} $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)
	make clean -C $(MINILIBX)
	${RM} $(NAME) ${OBJB}

re: fclean all

.PHONY: all clean fclean re