/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfill_split_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:04:19 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/22 20:15:50 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//BACK HERE
static void	malloc_split_cmd(t_data *data)
{
	t_exec	*tmp_exec;
	t_token	*tmp_token;
	t_token	*previous_token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_exec = data->exec;
	tmp_token = data->token;
	while (i < data->nb_tokens)
	{
		if (tmp_token->type == WORD &&)
			tmp_exec->split_cmd[j] = tmp_token->word;
		else if (tmp_token->type == PIPE)
		{
			tmp_exec->split_cmd = malloc(sizeof(char *) * (data->j + 1));
			if (!tmp_exec->split_cmd)
				exit_free(data, -1);
			j = 0;
			tmp_exec = tmp_exec->next;
		}
		tmp_token = tmp_token->next;
		i++;
		j++;
	}
}

void	fill_split_cmd(t_data *data)
{
	t_exec	*tmp;
	int		i;

	i = 0;
	tmp = data->exec;
	while (i < data->nb_cmd)
	{

	}
}
