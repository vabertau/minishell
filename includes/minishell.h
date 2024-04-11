#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../libftprintf/ft_printf.h"

typedef struct s_data{
	char	*cmdline;
	int		nb_tokens;
	int		nb_sq;
	int		nb_dq;
}				t_data;


// ====== READLINE ======

void	get_input(t_data *data);

// ====== LEXER ======

void	lexer(t_data *data);
void	nb_tokens(t_data *data);
int		spaces_bet_tokens(t_data *data);
