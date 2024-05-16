/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_linked_list_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:52:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 18:56:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"

t_linked_list_node	new_linked_list_node(
	t_minishell mini,
	t_linked_list_node previous,
	t_linked_list_node next,
	t_any value
){
	t_linked_list_node	instance;
	
	instance = mini_alloc(mini, sizeof(struct s_linked_list_node));
	instance->previous = previous;
	instance->next = next;
	instance->value = value;
	return (instance);
}
