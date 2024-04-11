/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_bet_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:48:08 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/11 14:33:37 by vabertau         ###   ########.fr       */
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

static int	skip_dq(char *cmdline)
{
	int	i;

	i = 0;
	if (cmdline[i] != '\"')
		return (0);
	else
		i++;
	while (cmdline[i] && cmdline[i] != '\"')
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
/*
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
}*/

char	*ft_strcpy_adds(char *cmdline)
{
	int	i;
	bool	sp_bf;
	char	*tmp;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (fixed_cmdline_len(cmdline) + 1));
	//if (ret == NULL)
	//	exit_free(data, -1);
	ft_strlcpy(ret, cmdline, ft_strlen(cmdline) + 1);
	while (ret[i])
	{
		i += skip_sq(&(ret[i]));
		i += skip_dq(&(ret[i]));
		if (ret[i] == '<' || ret[i] == '>' || ret[i] == '|')
		{
			tmp = ft_strdup(ret);
			if (i > 0 && ret[i - 1] != '<' && ret[i - 1] != '>' && ret[i - 1] != '|' && ret[i - 1] != ' ')
			{
				//if (tmp)
				//	exit_free(data, -1);
				ft_strlcpy(&(ret[i + 1]), &(tmp[i]), ft_strlen(&(ret[i])) + 1);
				//free(tmp);
				ret[i] = ' ';
				sp_bf = 1;
			}
			else
				sp_bf = 0;
			if (tmp[i + 1] != '<' &&  tmp[i + 1] != '>' && tmp[i + 1] != '|' && tmp[i + 1] != ' ')
			{
				if (sp_bf == 1)
				{
					ft_strlcpy(&(ret[i + 3]), &(tmp[i + 1]), ft_strlen(&tmp[i + 1]) + 1);
					ret[i + 2] = ' ';
				}
				else
				{
					ft_strlcpy(&(ret[i + 2]), &(tmp[i + 1]), ft_strlen(&(tmp[i + 1])) + 1);
					ret[i + 1] = ' ';
				}
			}
			free(tmp);
		}
		i++;
	}
	free (cmdline);
	return (ret);
}

int	spaces_bet_tokens(t_data *data)
{
	data->cmdline = ft_strcpy_adds(data->cmdline);
	return (0);
}
