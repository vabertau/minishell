NAME = minishell

CC = cc $(FLAGS) -g

FLAGS = -Wall -Werror -Wextra

FILENAMES = main.c get_input.c lexer.c nb_tokens.c

SRCS = $(addprefix srcs/, $(FILENAMES))

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lreadline -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
