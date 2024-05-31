/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:03:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_linked_list	linked_list_new(t_mini mini)
{
	t_linked_list	linked_list;

	linked_list = mini_alloc(mini, sizeof(struct s_linked_list));
	linked_list->head = NULL;
	linked_list->tail = NULL;
	return (linked_list);
}
