NAME = lem-in

SRC = lem.c \
	ft_main_additions.c \
	ft_validation_p1.c \
	ft_validation_p2.c \
	ft_validation_p3.c \
	ft_record.c \
	ft_sets.c \
	ft_alloc.c

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
		make -C libft
		gcc -g -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME)

clean:
		make clean -C libft

fclean: clean
		make fclean -C libft
		rm -f $(NAME)

re: fclean all
