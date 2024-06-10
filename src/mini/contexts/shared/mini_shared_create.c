/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shared_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:13:28 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:37:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_shared_create(t_mini mini, t_i32 argc, t_i8 **argv)
{
	mini->shared = malloc(sizeof(struct s_shared_context));
	mini_assert(mini, mini->shared != NULL, MEMORY_ALLOCATION_ERROR);
	mini->shared->argc = argc;
	mini->shared->argv = argv;
	mini->shared->memtree = NULL;
	mini->shared->memstack = NULL;
	mini->shared->exit_code = 0;
	mini->shared->is_statement_complete = FALSE;
	mini->shared->is_heredoc_complete = TRUE;
}