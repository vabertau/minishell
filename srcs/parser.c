/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:59:10 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/24 15:47:19 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void init_split_cmd(t_data *data)
{
	t_exec	*tmp_exec;
	int		i;

	i = 0;
	tmp_exec = data->exec;
	while (i < data->nb_cmd)
	{
		tmp_exec->split_cmd = NULL;
		tmp_exec = tmp_exec->next;
		i++;
	}
}

void init_exec(t_data *data)
{
	init_redir(data);
	init_split_cmd(data);
}

/*
Take the tokens and organize them in a structure containing all the elements necessary to execve
*/
void	parser(t_data *data)
{
	nb_cmd(data);
	malloc_exec(data);
	init_exec(data);
	fill_full_cmd(data);
	fill_split_cmd(data);
	fill_redir(data);
}
