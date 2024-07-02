/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:34:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:25:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	eval_executable(
	t_mini mini,
	t_cstring path,
	t_cstring_array argv,
	t_cstring_array envp
){
	t_i32	pid;
	t_i32	status;
	t_i32	signal;

	pid = fork();
	mini_assert(mini, pid != -1, MINI_ERROR);
	if (pid == 0)
	{
		execve(path, argv, envp);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			mini_quit(mini, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
		{
			signal = WTERMSIG(status);
			mini_quit(mini, 128 + signal); 
		}
	}
}
