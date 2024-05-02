/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:36:41 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 16:40:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"

t_linked_list	new_linked_list(
	t_linked_list_node head,
	t_linked_list_node tail
){
	t_linked_list	instance;

	instance = malloc_with_binary_tree(sizeof(struct s_linked_list));
	instance->head = head;
	instance->tail = tail;
	return (instance);
}
