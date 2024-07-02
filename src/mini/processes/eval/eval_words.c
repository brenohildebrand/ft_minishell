/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:01:39 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 22:10:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cstring	get_executable_path(t_mini mini, t_cstring filename)
{
	t_cstring	basename;
	t_cstring	path;
	t_i32		i;

	i = 0;
	if (filename[0] == '.' && filename[1] == '/')
	{
		if (access(filename, F_OK) == 0)
			return (filename);
	}
	else
	{
		while (mini->eval->paths[i])
		{
			basename = cstring_join(mini, mini->eval->paths[i], "/");
			path = cstring_join(mini, basename, filename);
			if (access(path, F_OK) == 0)
				return (path);
			mini_free(mini, basename);
			mini_free(mini, path);
			i++;
		}	
	}
	return (NULL);
}

static t_cstring	*get_executable_argv(t_mini mini, t_mini_cmd_tree command)
{
	t_cstring	*argv;
	t_i32		i;
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
	i = 0;
	node = command->words;
	while (node)
	{
		argv[i] = cstring_copy(mini, node->token);
		i++;
		node = node->next;
	}
	return (argv);
}

static t_cstring	*get_executable_envp(t_mini mini)
{
	return (cstring_array_copy(mini, mini->shared->env));
}

t_none	eval_words(t_mini mini, t_mini_cmd_tree command, t_i32 i)
{
	t_cstring	executable_name;
	t_cstring	executable_path;
	t_cstring	*executable_argv;
	t_cstring	*executable_envp;

	(void)i;
	executable_name = command->words->token;
	if (!eval_is_builtin(mini, executable_name))	
	{	
		executable_path = get_executable_path(mini, executable_name);
		if (executable_path == NULL)
		{
			printf("mini: %s: command not found.\n", executable_name);
			mini_quit(mini, 127);
		}
	}
	executable_argv = get_executable_argv(mini, command);
	executable_envp = get_executable_envp(mini);
	printf("\033[94m[%s:%d]\n(argv)\033[0m ", __func__, __LINE__);
	t_i32	j = 0;
	while (executable_argv[j])
	{
		if (executable_argv[j + 1])
			printf("%s ", executable_argv[j]);
		else
			printf("%s", executable_argv[j]);
		j++;
	}
	printf("\n");
	if (eval_is_builtin(mini, executable_name))
		eval_builtin(mini, executable_name, executable_argv, executable_envp);
	else
		eval_executable(mini, executable_path, executable_argv, executable_envp);
	mini_free(mini, executable_path);
	mini_free(mini, executable_argv);
	mini_free(mini, executable_envp);
}
