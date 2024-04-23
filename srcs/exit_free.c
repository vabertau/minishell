/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:02:38 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/23 18:24:06 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_token(t_token *token)
{
	t_token		*tmp;
	while (token != NULL)
	{
		tmp = token;
		token = token->next;
		if (tmp->word != NULL)
			free(tmp->word);
		free(tmp);
	}
}

void	free_bf_newprompt(t_data *data)
{
	if (data->cmdline != NULL)
		free(data->cmdline);
	free_token(data->token);
}

void	exit_free(t_data *data, int exit_code)
{
	if (data->cmdline != NULL)
		free(data->cmdline);
	free_token(data->token);
	exit(exit_code);
}
