/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tree_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:15:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 15:15:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_tree	mini_tree_create(t_mini mini)
{
	t_mini_tree	tree;

	tree = mini_alloc(mini, sizeof(struct s_mini_tree));
	
}