NAME = push_swap
NAME_BONUS = checker 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ft_atoi.c main.c push.c read_arg.c sawp_stack.c tools_list.c \
ft_listadd_back_stack.c rotate_list.c split.c utils.c algo.c index_stack.c sort.c \

BONUS = algo_Bonus.c ft_listadd_back_stack_Bonus.c get_next_line_utils.c rotate_list_Bonus.c sort_Bonus.c \
tools_list_Bonus.c ft_atoi_Bonus.c get_next_line.c main_Bonus.c push_Bonus.c read_arg_Bonus.c sawp_stack_Bonus.c \
split_Bonus.c utils_Bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
	@touch bonus

clean: 
	@$(RM) *.o

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS) bonus

re : fclean all

.PHONY: all clean fclean re