/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_llist_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:52:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 18:56:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "llist.h"

t_llist_node	new_llist_node(
	t_minishell mini,
	t_llist_node previous,
	t_llist_node next,
	t_any value
){
	t_llist_node	instance;
	
	instance = mini_alloc(mini, sizeof(struct s_llist_node));
	instance->previous = previous;
	instance->next = next;
	instance->value = value;
	return (instance);
}
