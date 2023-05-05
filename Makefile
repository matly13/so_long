NAME = so_long

SRC = so_long.c

CC = gcc
FLAG = -Werror -Wextra - Wall -g

OBJS = $(SRC:.c=.o)

LIBFT = libft/
PRINTF = ft_printf/

LIBS = $(LIBFT)libft.a $(PRINTF)libftprintf.a

RM = rm -f

CC = gcc -Wall -Wextra -Werror -g

.c.o = ${CC} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C $(LIBFT)
	make -C $(PRINTF)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)
	${RM} $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)
	${RM} $(NAME) ${OBJB}

re: fclean all

.PHONY: all clean fclean re