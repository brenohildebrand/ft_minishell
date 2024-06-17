/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:01:39 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 14:03:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cstring	get_executable_path(t_mini mini, t_cstring filename)
{
	t_cstring	basename;
	t_cstring	path;
	t_i32		i;

	i = 0;
	while (mini->eval->paths[i])
	{
		basename = mini_cstring_join(mini, mini->eval->paths[i], "/");
		path = mini_cstring_join(mini, basename, filename);
		if (access(path, F_OK) == 0)
			return (path);
		mini_free(mini, basename);
		mini_free(mini, path);
		i++;
	}
	return (NULL);
}

static t_cstring	*get_executable_argv(t_mini mini, t_mini_cmd_tree command)
{
	t_cstring	*argv;
	t_i32		len;
	t_mini_list	node;

	len = 0;
	node = command->words;
	while (node)
	{
		node = node->next;
		len++;
	}
	argv = mini_alloc(mini, len + 1);
	argv[len] = '\0';
	while (node)
	{
		len--;
		argv[len] = mini_cstring_copy(mini, node->token);
		node = node->next;
	}
	return (argv);
}

static t_cstring	*get_executable_envp(t_mini mini)
{
	return (mini_cstring_array_copy(mini, mini->shared->env));
}

t_none	mini_eval_words(t_mini mini, t_mini_cmd_tree command, t_i32 i)
{
	t_cstring	executable_name;
	t_cstring	executable_path;
	t_cstring	*executable_argv;
	t_cstring	*executable_envp;

	(void)i;
	executable_name = command->words->token;
	executable_path = get_executable_path(mini, executable_name);
	if (executable_path == NULL)
	{
		printf("mini: %s: command not found.\n", executable_name);
		mini_quit(mini, 127);
	}
	executable_argv = get_executable_argv(mini, command);
	executable_envp = get_executable_envp(mini);
	execve(executable_path, executable_argv, executable_envp);
	mini_free(mini, executable_path);
	mini_free(mini, executable_argv);
	mini_free(mini, executable_envp);
}
