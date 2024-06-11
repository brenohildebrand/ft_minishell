/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cmd_tree_list_create.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:30:19 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 23:15:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_cmd_tree_list	mini_cmd_tree_list_create(t_mini mini)
{
	t_mini_cmd_tree_list	list;

	list = mini_alloc(mini, 4 * sizeof(t_mini_cmd_tree));
	list->length = 0;
	list->size = 4;
	return (list);
}
