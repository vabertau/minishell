#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_data{
	char	*cmdline;
	int		nb_tokens;
}				t_data;

void	get_input(t_data *data);
void	lexer(t_data *data);
void	nb_tokens(t_data *data);
