/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:22:40 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:10:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "binary_tree.h"
#include "linked_list.h"

void	reset_minishell(t_minishell mini)
{
	if (mini->line)
	{
		free(mini->line);		
	}
	if (mini->list)
	{
		destroy_linked_list(mini, mini->list);
		mini->list = NULL;
	}
	// destroy_binary_tree(mini, mini->tree);
	// mini->tree = NULL;
}
