/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:11:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 21:35:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_parse(t_mini mini)
{
	(void)mini;
	// mini->parser->tree = simple_command(mini);
	// simple command tries to build a tree for its grammar and that follows
	// if an error occur during the process print the error and abort the 
	// current statement and line, just reset everything
}

// t_mini_tree	parser_simple_command(t_mini mini)
// {
// 	t_mini_tree	tree;

// 	if (parser_simple_command())

// 	tree = try_command();
// 	if (tree)
// 		return (tree);
// 	tree = try_command();	
// 	return (tree);
// }

// t_none	mini_parse_expression()
// {
// 	t_tree	tree;

// 	if (next_token == '(')
// 	{
// 		new_plus();
// 		'2 + 3'	
// 	}
	

// 	// It's not necessarily a binary tree
// 	return (tree);
// }
