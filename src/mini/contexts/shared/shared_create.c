/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:13:28 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 13:42:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	shared_create(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	mini->shared = malloc(sizeof(struct s_shared_context));
	mini_assert(mini, mini->shared != NULL, MINI_ERROR);
	mini->shared->argc = argc;
	mini->shared->argv = argv;
	mini->shared->envp = envp;
	mini->shared->memtree = NULL;
	mini->shared->fdtree = NULL;
	memstack_create(mini);
	mini->shared->env = cstring_array_copy(mini, envp);
	mini->shared->exit_code = 0;
	mini->shared->is_statement_complete = FALSE;
	mini->shared->is_heredoc_complete = TRUE;
}
