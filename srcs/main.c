/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:44 by vabertau          #+#    #+#             */
/*   Updated: 2024/04/11 11:33:29 by vabertau         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)envp;
	get_input(&data);
	spaces_bet_tokens(&data);
	printf("cmdline = %s\n", data.cmdline);
}
