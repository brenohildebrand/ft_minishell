/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:53:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 18:29:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mem	mini_alloc(t_mini mini, t_u32 size)
{
	t_mem	mem;

	mem = malloc(size);
	mini_assert(mini, mem != NULL, "Memory allocation error.\n");
	memtree_insert(&(mini->memtree), NULL, mem);
	return (mem);
}
