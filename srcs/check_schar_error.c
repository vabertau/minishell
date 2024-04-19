/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_schar_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:06:04 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/19 13:38:20 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_schar_error(t_data *data)
{
	int	i;
	char	*cmdline;

	i = 0;
	cmdline = data->cmdline;
	while (cmdline[i])
	{
		if (cmdline[i] == '\'')
			i += skip_sq(&(cmdline[i]));
		if (cmdline[i] == '\"')
			i += skip_dq(&(cmdline[i]));
		if (cmdline[i] == '|')
			if (cmdline[i + 1] == '|')
				parsing_error(data);
		if ((cmdline[i] == '<' && cmdline[i + 1] == '<' && (cmdline[i + 2] == '<' || cmdline[i + 2] == '>'))
			|| (cmdline[i] == '>' && cmdline[i + 1] == '>' && (cmdline[i + 2] == '>' || cmdline[i + 2] == '<'))
			|| (cmdline[i] == '>' && cmdline[i + 1] == '<')
			|| (cmdline[i] == '<' && cmdline[i + 1] == '>'))
				parsing_error(data);
		i++;
	}
}
