/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree_get_height.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:09:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 20:10:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	memtree_get_height(t_memtree memtree)
{
	if (memtree == NULL)
	{
		return (0);
	}
	else
	{
		return (memtree->height);
	}
}
