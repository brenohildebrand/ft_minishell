/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cmd_tree_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:10:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 18:12:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_cmd_tree	mini_cmd_tree_create(t_mini mini)
{
	t_mini_cmd_tree	tree;

	tree = mini_alloc(mini, sizeof(struct s_mini_command_tree));
	tree->words = NULL;
	tree->redirs = NULL;
	return (tree);
}
