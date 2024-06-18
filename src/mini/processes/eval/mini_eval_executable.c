/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_executable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:34:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 20:38:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval_executable(
	t_mini mini,
	t_cstring path,
	t_cstring_array argv,
	t_cstring_array envp
){
	t_i32	pid;

	pid = fork();
	mini_assert(mini, pid != -1, MINI_ERROR);
	if (pid == 0)
	{
		execve(path, argv, envp);
	}
}
