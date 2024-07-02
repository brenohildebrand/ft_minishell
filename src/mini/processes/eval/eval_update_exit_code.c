/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_update_exit_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:23:24 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:25:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	eval_update_exit_code(t_mini mini, t_i32 status)
{
	t_i32	signal;

	if (WIFEXITED(status))
		mini->shared->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		if (signal == SIGINT)
			mini->shared->exit_code = 130;
	}
}
