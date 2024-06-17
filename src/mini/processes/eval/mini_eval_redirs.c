/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_redirs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:01:28 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 22:31:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cstring	get_filepath_from_redir(t_mini mini, t_mini_list node)
{
	t_cstring	filepath;
	t_cstring	tmp;
	t_cstring	cwd;
	t_cstring	raw_filepath;

	raw_filepath = node->next->token;
	if (raw_filepath[0] == '/')
	{
		return (mini_cstring_copy(mini, raw_filepath));
	}
	else if (raw_filepath[0] == '.' && raw_filepath[1] == '/')
	{
		tmp = mini_cstring_remove(mini, raw_filepath, 0, 0);
		cwd = mini_get_cwd(mini);
		filepath = mini_cstring_join(mini, tmp, cwd);
		mini_free(mini, tmp);
		mini_free(mini, cwd);
	}
	else
	{
		cwd = mini_get_cwd(mini);
		tmp = mini_cstring_join(mini, cwd, "/");
		filepath = mini_cstring_join(mini, tmp, raw_filepath);
		mini_free(mini, tmp);
		mini_free(mini, cwd);
	}
	return (filepath);
}

static t_none	redirect_output(t_mini mini, t_mini_list node, t_i32 i)
{
	t_cstring	filepath;
	t_i32		fd;

	filepath = get_filepath_from_redir(mini, node);
	fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	mini_assert(mini, fd != -1, 0);
	if (mini->eval->redirs[1])
	{
		mini_assert(mini, dup2(fd, mini->eval->redirs[1]), 0);
		mini_assert(mini, close(mini->eval->redirs[1]) != -1, 0);
	}
	else
	{
		mini_assert(mini, dup2(fd, mini->eval->pipes[(i * 2) + 1]), 0);
		mini_assert(mini, close(mini->eval->pipes[(i * 2) + 1]) != -1, 0);
	}
}

static t_none	redirect_output_in_append_mode(t_mini mini, t_mini_list node, t_i32 i)
{
	t_cstring	filepath;
	t_i32		fd;

	filepath = get_filepath_from_redir(mini, node);
	fd = open(filepath, O_WRONLY | O_APPEND | O_TRUNC, 0644);
	mini_assert(mini, fd != -1, 0);
	if (mini->eval->redirs[1])
	{
		mini_assert(mini, dup2(fd, mini->eval->redirs[1]), 0);
		mini_assert(mini, close(mini->eval->redirs[1]) != -1, 0);
	}
	else
	{
		mini_assert(mini, dup2(fd, mini->eval->pipes[(i * 2) + 1]), 0);
		mini_assert(mini, close(mini->eval->pipes[(i * 2) + 1]) != -1, 0);
	}
}

static t_none	redirect_input(t_mini mini, t_mini_list node, t_i32 i)
{
	t_cstring	filepath;
	t_i32		fd;

	filepath = get_filepath_from_redir(mini, node);
	fd = open(filepath, O_RDONLY, 0644);
	mini_assert(mini, fd != -1, 0);
	if (mini->eval->redirs[0])
	{
		mini_assert(mini, dup2(fd, mini->eval->redirs[0]), 0);
		mini_assert(mini, close(mini->eval->redirs[0]) != -1, 0);;
	}
	else
	{
		mini_assert(mini, dup2(fd, mini->eval->pipes[2 * (i - 1)]), 0);
		mini_assert(mini, close(mini->eval->pipes[2 * (i - 1)]) != -1, 0);
	}
	mini->eval->redirs[0] = fd;
}

t_none	mini_eval_redirs(t_mini mini, t_mini_cmd_tree command, t_i32 i)
{
	t_mini_list	node;

	node = command->redirs;
	while (node)
	{
		if (cstring_compare(node->token, ">") == 0)
		{
			redirect_output(mini, node, i);
		}
		else if (cstring_compare(node->token, ">>") == 0)
		{
			redirect_output_in_append_mode(mini, node, i);
		}
		else if (cstring_compare(node->token, "<") == 0)
		{
			redirect_input(mini, node, i);	
		}
		else if (cstring_compare(node->token, "<<") == 0)
		{
			redirect_input(mini, node, i);	
		}
		node = node->next->next;
	}
}
