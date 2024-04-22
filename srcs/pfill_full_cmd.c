/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfill_full_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:50:24 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/22 13:56:08 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fill_full_cmd(t_data *data)
{
	t_exec	*tmp_exec;
	t_token *tmp_token;
	int		i;

	i = 0;
	tmp_exec = data->exec;
	tmp_token = data->token;
	while (i < data->nb_cmd)
	{
		while (tmp_token && tmp_token->type != PIPE)
		{
			if (tmp_exec->full_cmd == NULL)
			{
				tmp_exec->full_cmd = ft_strdup(tmp_token->word);
				if (tmp_exec->full_cmd == NULL)
					exit_free(data, -1);
			}
			else
			{
				tmp_exec->full_cmd = ft_strjoin(tmp_exec->full_cmd, tmp_token->word);
				if (tmp_exec->full_cmd == NULL)
					exit_free(data, -1);
			}
			tmp_token = tmp_token->next;
		}
		if (tmp_token)
			tmp_token = tmp_token->next;
		tmp_exec = tmp_exec->next;
		i++;
	}
}
