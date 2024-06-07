/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_pipe_sequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:38:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:21:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_tree	mini_parse_pipe_sequence(t_mini mini)
{
	(void)mini;
	return (NULL);
	// t_mini_tree	tree;
	// t_mini_tree	children[2];

	// children[0] = mini_parse_command_sequence(mini);
	// if (children[0] == NULL)
	// {
	// 	mini_parse_syntax_error();
	// }
	// if (mini->parser->cursor->type == PIPE)
	// {
	// 	children[1] = mini_parse_pipe_sequence(mini);
	// 	if (children[1] == NULL)
	// 	{
	// 		return children[0];
	// 	}
	// 	tree = mini_alloc(mini, sizeof(struct s_mini_tree));
	// 	// tree->size = 2;
	// 	tree->children = mini_alloc(mini, sizeof(struct s_mini_tree) * 2);
	// 	tree->children[0] = children[0];
	// 	tree->children[1] = children[1];
	// 	tree->evaluate = mini_eval_pipe;
	// 	return (tree);
	// }
	// else
	// {
	// 	return (children[0]);
	// }
	// return (NULL);
}
