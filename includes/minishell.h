#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../libftprintf/ft_printf.h"

typedef struct s_token{
	int					i;
	char				*word;
	struct s_token		*next;
}				t_token;

typedef struct s_data{
	char	*cmdline;
	int		nb_tokens;
	int		nb_sq;
	int		nb_dq;
	t_token	*token;
}				t_data;

// ====== READLINE ======

void	get_input(t_data *data);

// ====== INIT_DATA ======

void	init_data(t_data *data);

// ====== LEXER ======

void	lexer(t_data *data);
void	nb_tokens(t_data *data);
int		spaces_bet_tokens(t_data *data);
int		skip_sq(char *cmdline);
int		skip_dq(char *cmdline);
void	malloc_tokens(t_data *data);
void	fill_tokens(t_data *data);

// ====== EXIT ======

void	exit_free(t_data *data, int exit_code);
void	free_bf_newprompt(t_data *data);
