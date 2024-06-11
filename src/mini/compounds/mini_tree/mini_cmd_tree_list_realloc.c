/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cmd_tree_list_realloc.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:48:40 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 21:52:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_cmd_tree_list_realloc(
	t_mini mini,
	t_mini_cmd_tree_list list 
){
	t_mini_cmd_tree	*new_elements;
	t_i32			i;

	new_elements = mini_alloc(mini, 2 * list->size * sizeof(t_mini_cmd_tree));
	i = 0;
	while (i < list->length)
	{
		new_elements[i] = list->elements[i];
		i++;
	}
	mini_free(mini, list->elements);
	list->elements = new_elements;
	list->size *= 2;
}
