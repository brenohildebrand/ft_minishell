/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory_tree_height.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:09:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 20:10:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

int	get_memory_tree_height(t_memory_tree memory_tree)
{
	if (memory_tree == NULL)
	{
		return (0);
	}
	else
	{
		return (memory_tree->height);
	}
}
