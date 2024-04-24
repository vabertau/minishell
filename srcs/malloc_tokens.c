/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:32:33 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/24 12:32:17 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	malloc_tokens(t_data *data)
{
	int		i;
	t_token	*tmp;

	i = 0;
	data->token = malloc(sizeof(t_token));
	if (!data->token)
		exit_free(data, -1);
	tmp = data->token;
	while (i < data->nb_tokens - 1)
	{
		//if (token == NULL)
		//	exit_free(data, -1);
		tmp->i = i; // rm in the end if not useful
		tmp->word = NULL;
		tmp->next = malloc(sizeof(t_token));
		tmp = tmp->next;
		i++;
	}
	tmp->i = i;
	tmp->word = NULL;
	//printf("tokens index= %i\n", token->i);
	tmp->next = NULL;
}
