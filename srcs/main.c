/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:44 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/16 16:45:52 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)envp;
	get_input(&data);
}
*/

//============ TEST NB_TOKENS ==============
/*
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)envp;
	get_input(&data);
	printf("nb tokens = %i\n", data.nb_tokens);
}
*/

// ============ TEST SPACES_BET_TOKENS ============

/*
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)envp;
	//while (1)
	//{
		get_input(&data);
		spaces_bet_tokens(&data);
		printf("cmdline = %s\n", data.cmdline);
	//}
	exit_free(&data, 0); //tmp
}
*/

// ============ TEST NB_TOKENS ===============
/*
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)envp;
	init_data(&data);
	while (1)
	{
		get_input(&data);
		spaces_bet_tokens(&data);
		nb_tokens(&data);
		printf("cmdline = %s\n", data.cmdline);
		printf("nb tokens = %i\n", data.nb_tokens);
	}
	exit_free(&data, 0); //tmp
}
*/

// ============ TEST FILL_TOKENS ================

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_data	tmp;

	(void)argc;
	(void)argv;
	(void)envp;
	//while (1)
	//{
		init_data(&data);
		get_input(&data);
		spaces_bet_tokens(&data);
		nb_tokens(&data);
		malloc_tokens(&data);
		if (data.token == NULL)
			printf("token = NULL");
		fill_tokens(&data);
		printf("cmdline = %s\n", data.cmdline);
		printf("nb tokens = %i\n", data.nb_tokens);
		tmp = data;
		while (tmp.token != NULL)
		{
			printf("word = %s\n", tmp.token->word);
			tmp.token = tmp.token->next;
		}
	//	free_bf_newprompt(&data);
	//}
	exit_free(&data, 0); //tmp
}

// ============ TEST FILL_TOKENS  LLDB ================
/*
int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_data	tmp;

	(void)argc;
	(void)argv;
	(void)envp;
	//while (1)
	//{
		init_data(&data);
		//get_input(&data);
		data.cmdline = ft_strdup("test \"hey test\"");
		spaces_bet_tokens(&data);
		nb_tokens(&data);
		malloc_tokens(&data);
		if (data.token == NULL)
			printf("token = NULL");
		fill_tokens(&data);
		printf("cmdline = %s\n", data.cmdline);
		printf("nb tokens = %i\n", data.nb_tokens);
		tmp = data;
		while (tmp.token != NULL)
		{
			printf("word = %s\n", tmp.token->word);
			tmp.token = tmp.token->next;
		}
	//	free_bf_newprompt(&data);
	//}
	exit_free(&data, 0); //tmp
}*/