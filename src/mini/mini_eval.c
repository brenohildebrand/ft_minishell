/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:50:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/07 01:19:49 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval(t_mini mini)
{
	(void)mini;
	add_history(mini->reader->statement);
	mini_free(mini, mini->reader->statement);
	mini->reader->statement = NULL;
	mini->shared->is_statement_complete = FALSE;
	// for each node in the tree call the children and executes itself
	// execute itself it should know if it's going to execute each children or
	// whatever
}
