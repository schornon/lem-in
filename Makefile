NAME = lem-in
SRC = ants_controller.c highwaytohell.c extend.c extend_2.c input_validator.c bfs.c create_graph.c fmrp.c fmrp_2.c ft_join_pf.c init.c lem_in.c lists.c parsing.c path_finder.c validate.c gnl/get_next_line.c
FTPRINTF = ./ft_printf/libftprintf.a
OBJ:= $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ft_printf/
	@gcc $(FLAGS) $(SRC) -o $(NAME) $(FTPRINTF)

%.o : %.c
	@gcc $(FLAGS) -c -o  $@ $<

clean:
	@make clean -C ft_printf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all
