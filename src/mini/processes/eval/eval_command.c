/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:24:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 18:17:53 by bhildebr         ###   ########.fr       */
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
		{
			j++;
			continue ;
		}
		if (i != len - 1 && j == (i * 2) + 1)
		{
			j++;
			continue ;
		}
		close(mini->eval->pipes[j]);
		j++;
	}
}

static t_none	setup_new_signal_handlers(t_mini mini)
{
	(void)mini;
}

t_none	eval_in_the_same_process(t_mini mini, t_i32 i)
{
	t_mini_cmd_tree	command;

	command = mini->parser->tree->command_list->elements[i];
	eval_setup_pipes(mini, i);
	eval_redirs(mini, command, i);
	eval_corner_case();

}

t_none	eval_as_another_process(t_mini mini, t_i32 i)
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
		eval_redirs(mini, command, i);
		eval_words(mini, command);
	}
	else
	{
		mini_assert(mini, wait(&status) != -1, 0);
		eval_update_exit_code(mini, status);
	}
}

t_none	eval_command(t_mini mini, t_i32 i)
{
	t_mini_cmd_tree	command;
	t_cstring		command_name;

	command = mini->parser->tree->command_list->elements[i];
	command_name = command->words->token;
	if (eval_is_corner_case(command_name))
	{
		eval_in_the_same_process(mini, i);
	}
	else
	{
		eval_as_another_process(mini, i);
	}
}
//

t_none	eval_command(t_mini mini)
{
	if (is_builtin(mini))
	{
		eval_builtin();			
	}
	else
	{
		eval_executable();
	}
}

t_none	eval_builtin(t_mini mini)
{
	if (is_special_builtin(mini))
	{
		eval_special_builtin(mini);
	}
	else
	{
		eval_regular_builtin(mini);
	}
}
