/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:33:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 18:42:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_minishell(t_minishell mini)
{
	if (mini->line)
		free(mini->line);
	destroy_memory_tree(mini->memtree);
	free(mini);
}
