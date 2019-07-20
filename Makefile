NAME = lem-in

SRC = lem.c
		
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