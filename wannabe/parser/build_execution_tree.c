/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_execution_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:40:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 16:38:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "linked_list.h"
#include "binary_tree.h"

t_binary_tree	build_execution_tree(t_minishell mini)
{
	t_binary_tree	execution_tree;
	
	execution_tree = new_binary_tree(NULL);
	split_tokens_into_tree(mini);
	return (execution_tree);
}
