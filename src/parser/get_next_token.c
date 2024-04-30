/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:31:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 17:33:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"
#include "token.h"

t_token	get_next_token(t_linked_list_node current_node)
{
	t_linked_list_node	next_node;

	next_node = current_node->next;
	if (next_node)
	{
		return (next_node->value);		
	}
	return (NULL);
}
