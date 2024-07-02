/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree_get_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:34:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 22:48:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fdtree_get_height(t_fdtree fdtree)
{
	if (fdtree == NULL)
	{
		return (0);
	}
	else
	{
		return (fdtree->height);
	}
}
