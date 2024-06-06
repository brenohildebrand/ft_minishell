/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 21:36:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_mini	mini_create(t_i32 argc, t_cstring_array argv)
{
	t_mini	mini;

	mini = malloc(sizeof(struct s_mini_context));
	if (mini == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed.\n", 27);
		exit(1);
	}
	mini->argc = argc;
	mini->argv = argv;
	mini->memtree = NULL;
	mini->is_multiline = FALSE;
	mini->is_statement_complete = FALSE;
	mini->exit_status = 0;
	memstack_create(mini);
	config_create(mini);
	input_create(mini);
	lexer_create(mini);
	parser_create(mini);
	return (mini);
}
