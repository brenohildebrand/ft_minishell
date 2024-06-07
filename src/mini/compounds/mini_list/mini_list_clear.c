/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:21:40 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:05:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_list_clear(t_mini mini, t_mini_list *list)
{
	t_mini_list	node;
	t_mini_list	next;

	node = (*list);
	while (node)
	{
		next = node->next;
		node->next = NULL;
		node->previous = NULL;
		mini_free(mini, node->token);
		mini_free(mini, node);
		node = next;
	}
	(*list) = NULL;
}
