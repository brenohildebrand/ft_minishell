/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:03:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 11:05:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_llist	llist_new(t_mini mini)
{
	t_llist	llist;

	llist = mini_alloc(mini, sizeof(struct s_llist));
	llist->head = NULL;
	llist->tail = NULL;
	return (llist);
}
