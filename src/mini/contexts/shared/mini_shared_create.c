/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shared_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:13:28 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:15:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_shared_create(t_mini mini)
{
	mini->shared = mini_alloc(mini, sizeof(struct s_shared_context));
	mini->shared->memtree = NULL;
	mini->shared->memstack = NULL;
	mini->shared->exit_code = 0;
	mini->shared->is_statement_complete = FALSE;
}
