/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:23:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:04:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

t_none	mini_read(t_mini mini)
{
	if (mini->reader->line)
	{
		mini_free(mini, mini->reader->line);
	}
	if (mini->shared->is_statement_complete)
	{
		mini->reader->line = readline(mini->reader->prompt);
	}
	else
	{
		mini->reader->line = readline(mini->reader->multiline_prompt);
	}
	if (mini->reader->line)
	{
		memtree_insert(&(mini->shared->memtree), NULL, mini->reader->line);
	}
	else
	{
		cstring_to_stdout("\033[33mAn empty line with only EOF was entered. I'm quitting.\033[0m\n");
		mini_quit(mini, 42);
	}
	mini->shared->is_statement_complete = TRUE;
	printf("\033[94m[%s:%d]\n(line)\033[0m %s\n", __func__, __LINE__, mini->reader->line);
}

#else

#endif
