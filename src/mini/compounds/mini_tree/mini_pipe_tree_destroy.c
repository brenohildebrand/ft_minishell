/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe_tree_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:04:16 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 18:09:31 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_pipe_tree_destroy(t_mini mini, t_mini_pipe_tree tree)
{
	t_i32	i;

	i = 0;
	while (tree->commands[i])
	{
		mini_cmd_tree_destroy(tree->commands[i]);
		i++;
	}
	mini_free(mini, tree->commands);
	mini_free(mini, tree);
}
