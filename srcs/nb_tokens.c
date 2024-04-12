/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:42:01 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/12 14:09:20 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	skip_spaces(char *cmdline)
{
	int	i;

	i = 0;
	while (cmdline[i] && (cmdline[i] == ' '))
		i++;
	return (i);
}

static int	skip_ns(char *cmdline)
{
	int	i;

	i = 0;
	while (cmdline[i] && (cmdline[i] != ' '))
		i++;
	return (i);
}

/*counts the nb of tokens that are going to be filled afterwards. By spliting with spaces,
skipping quotes.
*/
void	nb_tokens(t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (data->cmdline[i])
	{
		i += skip_spaces(&(data->cmdline[i]));
		if (data->cmdline[i] && (data->cmdline[i] != ' '))
		{
			nb++;
			if (data->cmdline[i] == '\'')
				skip_sq(data->cmdline);
			if (data->cmdline[i] == '\"')
				skip_dq(data->cmdline);
			i += skip_ns(&(data->cmdline[i]));
		}
	}
	data->nb_tokens = nb;
}
