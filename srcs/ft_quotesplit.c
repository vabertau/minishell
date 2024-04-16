/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotesplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:28:26 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/16 16:50:54 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	int	nb_chains(char const *s, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			ret++;
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (ret);
}

/*
Starts with too big malloc (ft_strlen(cmdline) + 1 the biggest possible).
Copies 1 token, stopping at first ' ' that is not between quotes.
copy_bet_quotes functions copies character between quotes without the quotes SQ TO ADD ??
In the end resizing the malloc with ft_strdup and freeing tmp which is too big, too avoid unnecessary space use.
*/
static	char	*ft_substr_quotes(t_data *data, char const *s, int *i, char c)
{
	char	*ret;
	char	*tmp;
	int		j;

	j = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tmp)
		exit_free(data, -1);
	while (s[*i] && s[*i] != c)
	{
		if ((s[*i] == '\'') && ft_strchr(&(s[(*i) + 1]), '\''))
            copy_bet_sq(i, &j, s, tmp);
		else if ((s[*i] == '\"') && ft_strchr(&(s[(*i) + 1]), '\"'))
            copy_bet_dq(i, &j, s, tmp);
		else
		{
			tmp[j] = s[*i];
			(*i)++;
			j++;
		}
	}
	tmp[j] = '\0';
	ret = ft_strdup(tmp);
	return (free(tmp), ret);
}

static	int	first_nonc(char const *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

/* Similar to ft_split, but it will not split with c character when inside quotes. */
char	**ft_quotesplit(t_data *data, char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (nb_chains(s, c) + 1));
	if (!ret)
		return (NULL);//to mod
	while (s[i])
	{
		i = first_nonc(s, c, i);
		if (!(s[i]))
			break ;
		ret[j] = ft_substr_quotes(data, s, &i, ' ');
		if (!ret[j])
			exit_free(data, -1);
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

/*
#include <stdio.h>
*/
/* ================== test nb_chains ================= */
/*
int	main(void)
{
	printf("result = %i", nb_chains("test", 'a'));
}*/

/* =============== test ft_split =================== */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	test_ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	result = ft_split(s, c);
	if (result == NULL)
	{
		printf("ft_split returned NULL\n");
		return ;
	}
	i = 0;
	while (result[i] != NULL)
	{
		printf("result[%d] = \"%s\"\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result[i]);
	free(result);
}

int		main(void)
{
	test_ft_split("Hello,World!", ',');
	test_ft_split("split  ||this|for|me|||||!|", '|');
	test_ft_split("Hello,World!,How,Are,You?", '!');
	test_ft_split("Hello,World!,How,Are,You?", ' ');
	test_ft_split("Hello,World!,How,Are,You?", '\0');
	test_ft_split("", ',');
	test_ft_split(NULL, ',');
	return (0);
}*/
