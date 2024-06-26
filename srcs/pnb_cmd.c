/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnb_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:40:54 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/19 14:08:00 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Sets the number of commands by counting pipes
*/
void	nb_cmd(t_data *data)
{
	int	i;
	int	ret;
	char	*cmdline;

	i = 0;
	ret = 1;
	cmdline = data->cmdline;
	while(cmdline[i])
	{
		if (cmdline[i] == '|')
			ret++;
		i++;
	}
	data->nb_cmd = ret;
}
