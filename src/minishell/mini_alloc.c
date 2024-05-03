/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:53:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/03 15:59:49 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "memory_tree.h"

void	*mini_alloc(t_minishell mini, t_u32 size)
{
	void	*address;

	address = malloc(size);
	if (address == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed.\n", 27);
		mini_quit(mini);
	}
	insert_in_memory_tree(mini->memtree, NULL, address);
	return (address);	
}
