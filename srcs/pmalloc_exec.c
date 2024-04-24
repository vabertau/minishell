/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmalloc_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:52:51 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/24 16:08:38 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
malloc t_exec strucuture with the nb_cmd calculated before, to fill it after
*/
void	malloc_exec(t_data *data)
{
	t_exec *tmp;
	int		i;

	i = 0;
	data->exec = malloc(sizeof(t_exec)); //CHECKED
	if (!data->exec)
		exit_free(data, -1);
	tmp = data->exec;
	tmp->full_cmd = NULL;
	tmp->split_cmd = NULL;
	while (i < data->nb_cmd - 1)
	{
		tmp->next = malloc(sizeof(t_exec)); // BAD PROTECTION
		//free(tmp->next);
		//tmp->next = NULL;
		if (!tmp->next)
			exit_free(data, -1);
		tmp->full_cmd = NULL;
		tmp->split_cmd = NULL;
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
}
