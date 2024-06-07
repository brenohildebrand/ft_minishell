/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:53:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:00:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mem	mini_alloc(t_mini mini, t_u32 size)
{
	t_mem	mem;

	mem = malloc(size);
	if (mem == NULL)
	{
		cstring_to_stderr("Memory allocation failed.\n");
		mini_quit(mini, MEMORY_ALLOCATION_ERROR);
	}
	memtree_insert(&(mini->shared->memtree), NULL, mem);
	return (mem);
}
