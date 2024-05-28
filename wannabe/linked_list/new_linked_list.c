/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_llist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:36:41 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 16:55:28 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "llist.h"

t_llist	new_llist(
	t_minishell mini,
	t_llist_node head,
	t_llist_node tail
){
	t_llist	instance;

	instance = mini_alloc(mini, sizeof(struct s_llist));
	instance->head = head;
	instance->tail = tail;
	return (instance);
}
