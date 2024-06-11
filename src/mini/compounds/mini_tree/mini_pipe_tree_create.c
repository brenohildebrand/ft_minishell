/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe_tree_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:02:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 22:35:58 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_pipe_tree	mini_pipe_tree_create(t_mini mini)
{
	t_mini_pipe_tree	tree;

	tree = mini_alloc(mini, sizeof(struct s_mini_pipe_sequence_tree));
	tree->command_list = mini_cmd_tree_list_create(mini);
	return (tree);
}
