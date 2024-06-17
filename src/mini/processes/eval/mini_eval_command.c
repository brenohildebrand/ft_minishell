/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:24:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 22:36:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_none	close_and_free_whatever_is_needed(t_mini mini, t_i32 i)
{
	t_i32	len;
	t_i32	j;

	j = 0;
	len = mini->parser->tree->command_list->length;
	while (j < 2 * (len - 1))
	{
		if (i != 0 && j == 2 * (i - 1))
			continue ;
		if (i != len - 1 && j == (i * 2) + 1)
			continue ;
		close(mini->eval->pipes[j]);
		j++;
	}
}

static t_none	setup_new_signal_handlers(t_mini mini)
{
	(void)mini;
}

t_none	mini_eval_command(t_mini mini, t_i32 i)
{
	t_i32			pid;
	t_i32_array		pipes;
	t_mini_cmd_tree	command;
	t_i32			status;

	command = mini->parser->tree->command_list->elements[i];
	pipes = mini->eval->pipes;
	pid = fork();
	mini_assert(mini, pid != -1, 0);
	if (pid == 0)
	{
		close_and_free_whatever_is_needed(mini, i);
		setup_new_signal_handlers(mini);
		if (i != 0)
			mini_assert(mini, dup2(pipes[2 * (i - 1)], STDIN_FILENO), 0);
		if (i != mini->parser->tree->command_list->length - 1)
			mini_assert(mini, dup2(pipes[(i * 2) + 1], STDOUT_FILENO), 0);
		mini_eval_redirs(mini, command, i);
		mini_eval_words(mini, command, i);
		mini_eval_close_redirs(mini);
	}
	else
	{
		mini_assert(mini, wait(&status) != -1, 0);
		mini_eval_update_exit_code(mini, status);
	}
}
