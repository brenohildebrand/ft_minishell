/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:45 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:47:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "llist.h"
#include "token.h"

t_token	get_previous_token(t_llist_node current_node)
{
	t_llist_node	previous_node;

	previous_node = current_node->previous;
	if (previous_node)
	{
		return (previous_node->value);		
	}
	return (NULL);
}
