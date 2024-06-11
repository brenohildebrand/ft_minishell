/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cmd_tree_list_append.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:14:03 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 21:30:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_cmd_tree_list_append(
	t_mini mini,
	t_mini_cmd_tree_list list,
	t_mini_cmd_tree command
){
	if (list->length + 1 > list->size)
	{
		mini_cmd_tree_list_realloc(mini, list);
	}
	list->elements[list->length] = command;
	list->length++;
}
