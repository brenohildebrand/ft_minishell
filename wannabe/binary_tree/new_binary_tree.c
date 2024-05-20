/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_binary_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:46:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 18:15:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "binary_tree.h"

t_binary_tree	new_binary_tree(t_minishell mini, t_binary_tree_node root)
{
	t_binary_tree	instance;

	instance = mini_alloc(mini, sizeof(struct s_binary_tree));
	instance->root = root;
	return (instance);
}
