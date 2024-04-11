/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_bet_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:48:08 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/11 11:40:03 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	skip_sq(char *cmdline)
{
	int	i;

	i = 0;
	if (cmdline[i] != '\'')
		return (0);
	else
		i++;
	while (cmdline[i] && cmdline[i] != '\'')
		i++;
	return (i);
}

static int	fixed_cmdline_len(char *cmdline)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (cmdline[i])
	{
		i += skip_sq(&(cmdline[i]));
		if (cmdline[i] == '<' || cmdline[i] == '>' || cmdline[i] == '|')
		{
			if (i > 0 && cmdline[i - 1] != '<' &&  cmdline[i - 1] != '>' && cmdline[i - 1] != '|' && cmdline[i - 1] != ' ')
				ret++;
			if (cmdline[i + 1] != '<' &&  cmdline[i + 1] != '>' && cmdline[i + 1] != '|' && cmdline[i + 1] != ' ')
				ret++;
		}
		i++;
	}
	return (ret + ft_strlen(cmdline));
}

ft_strcpy_i(char *dest, char *src, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
}

void	ft_strcpy_adds(char *ret, char *cmdline)
{
	int	i;

	i = 0;
	while (cmdline[i])
	{
		i +=
	}
}

int	spaces_bet_tokens(t_data *data)
{
	char	*ret;

	ret = malloc(sizeof(char) * (fixed_cmdline_len(data->cmdline) + 1));
	//if (ret == NULL)
	//	exit_free(data, -1);
	ft_strcpy_adds(ret, data->cmdline);
	return (0);
}
