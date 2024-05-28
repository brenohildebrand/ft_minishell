/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_execution_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:40:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:47:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "llist.h"
#include "binary_tree.h"

t_binary_tree	build_execution_tree(t_minishell mini)
{
	t_binary_tree	execution_tree;
	
	execution_tree = new_binary_tree(mini, NULL);
	split_tokens_into_tree(mini);
	return (execution_tree);
}
