/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:43:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 22:43:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_list_destroy(t_mini mini, t_mini_list *list)
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
