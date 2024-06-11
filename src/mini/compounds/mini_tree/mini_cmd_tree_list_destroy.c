/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cmd_tree_list_destroy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:37:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 21:38:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_cmd_tree_list_destroy(
	t_mini mini,
	t_mini_cmd_tree_list list
){
	t_i32	i;

	i = 0;
	while (i < list->length)
	{
		mini_cmd_tree_destroy(mini, list->elements[i]);
		i++;
	}
	mini_free(mini, list->elements);
}
