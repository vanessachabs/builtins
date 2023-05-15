NAME =  builtins
CC	= cc
CFLAGS	= -Wall -Wextra -Werror 

SRCS	= main.c environ.c ft_split.c print_export.c export.c utils.c free.c
OBJECTS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJECTS)
		 $(CC) $(CFLAGS) -o $(NAME) $^
		 @printf "[\e[32mObjetos criados com SUCESSO✅\e[0m]\n"
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJECTS)
		@printf "[\e[33mObjetos removidos com SUCESSO✅\e[0m]\n"

fclean:	clean
		@rm -rf $(NAME)
		@printf "[\e[33mTodos os arquivos foram removidos com SUCESSO✅\e[0m]\n"

re: make fclean
	make all

.PHONY: all re clean fclean