/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:23:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 16:09:28 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

#ifdef ENABLE_DEBUGGER

t_none	mini_read(t_mini mini)
{
	const t_input	input = mini->input;
	
	mini->input->is_complete = TRUE;
	input_get_prompt(mini);
	if (input->line)
	{
		mini_free(mini, input->line);
	}
	input->line = readline(input->prompt);
	if (input->line)
	{
		memtree_insert(&(mini->memtree), NULL, input->line);
	}
	printf("\033[94m[%s:%d]\n(line)\033[0m %s\n", __func__, __LINE__, input->line);
	if (input->line == NULL)
	{
		cstring_to_stdout("\033[33mAn empty line with only EOF was entered. I'm quitting.\033[0m\n");
		mini->exit_status = 1;
		mini_quit(mini);
	}
}

#else

t_none	mini_read(t_mini mini)
{
	const t_input	input = mini->input;
	
	input_get_prompt(mini);
	if (input->line)
	{
		mini_free(mini, input->line);
	}
	input->line = readline(input->prompt);
	if (input->line)
	{
		memtree_insert(&(mini->memtree), NULL, input->line);
	}
	if (input->line == NULL)
	{
		cstring_to_stdout("\033[33mAn empty line with only EOF was entered. I'm quitting.\033[0m\n");
		mini->exit_status = 1;
		mini_quit(mini);
	}
}

#endif
