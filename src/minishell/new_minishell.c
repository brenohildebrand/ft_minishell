/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_minishell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 18:36:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	new_minishell(void)
{
	t_minishell		mini;

	mini = malloc(sizeof(struct s_minishell));
	if (mini == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed.\n", 27);
		exit(1);
	}
	mini->memtree = NULL;
	mini->line = NULL;
	mini->list = NULL;
	mini->tree = NULL;
	return (mini);
}
