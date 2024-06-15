/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:23:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 22:05:55 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

t_none	mini_read(t_mini mini)
{
	if (mini->reader->statement == NULL)
		mini->reader->line = readline(mini->reader->prompt);
	else
		mini->reader->line = readline(mini->reader->multiline_prompt);
	if (mini->reader->line)
	{
		memtree_insert(&(mini->shared->memtree), NULL, mini->reader->line);
		mini->reader->statement = mini_cstring_join(mini, mini->reader->statement, mini->reader->line);
	}
	else
	{
		cstring_to_stdout("exit\n");
		mini_quit(mini, mini->shared->exit_code);
	}
	mini->shared->is_statement_complete = TRUE;
	printf("\033[94m[%s:%d]\n(statement)\033[0m %s\n", __func__, __LINE__, mini->reader->statement);
}

#else

#endif
