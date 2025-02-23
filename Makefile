NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SRC = ft_atoi.c main.c push.c read_arg.c sawp_stack.c tools_list.c \
ft_listadd_back_stack.c rotate_list.c split.c utils.c algo.c index_stack.c sort.c \


OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re