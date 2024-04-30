/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:45 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 17:34:35 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"
#include "token.h"

t_token	get_previous_token(t_linked_list_node current_node)
{
	t_linked_list_node	previous_node;

	previous_node = current_node->previous;
	if (previous_node)
	{
		return (previous_node->value);		
	}
	return (NULL);
}
