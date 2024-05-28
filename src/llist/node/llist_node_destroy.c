/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_node_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:27:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 11:30:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// This function assumes the value is going to be a token.
t_none	llist_node_destroy(t_mini mini, t_llist_node node)
{
	t_token	token;

	if (node->value)
	{
		token = (t_token)node->value;
		mini_free(mini, token->value);
		mini_free(mini, token);
	}
	mini_free(mini, node);
}
