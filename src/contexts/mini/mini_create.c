/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:34:38 by bhildebr         ###   ########.fr       */
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
	memstack_create(mini);
	config_create(mini);
	input_create(mini);
	lexer_create(mini);
	parser_create(mini);
	return (mini);
}
