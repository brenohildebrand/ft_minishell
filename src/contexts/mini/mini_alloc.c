/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:53:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/31 18:35:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_mem	mini_alloc(t_mini mini, t_u32 size)
{
	t_mem	mem;

	mem = malloc(size);
	if (mem == NULL)
	{
		cstring_to_stderr("Memory allocation failed.\n");
		mini->exit_status = 1;
		mini_quit(mini);
	}
	memtree_insert(&(mini->memtree), NULL, mem);
	return (mem);
}
