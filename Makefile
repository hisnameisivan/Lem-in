NAME = lem-in

SRC = ft_main_additions.c \
	ft_validation_p1.c \
	ft_validation_p2.c \
	ft_validation_p3.c \
	ft_record.c \
	ft_sets.c \
	ft_alloc.c \
	ft_free_1.c \
	ft_free_2.c \
	ft_print_result_1.c \
	ft_print_result_2.c \
	ft_bfs.c \
	ft_block_del.c \
	ft_add.c \
	ft_algo_1.c \
	ft_algo_2.c \
	ft_algo_3.c \
	ft_main.c \

OBJ = $(SRC:%.c=%.o)

INCLUDES = libft/libft.a

all: $(NAME)

$(OBJ): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ 

$(NAME): $(OBJ)
		make -C libft
		gcc -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME)

clean:
		make clean -C libft
		/bin/rm -f $(OBJ)

fclean: clean
		make fclean -C libft
		/bin/rm -f $(NAME)

re: fclean all
