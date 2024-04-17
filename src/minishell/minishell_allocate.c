/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:37:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 12:27:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

void	*minishell_allocate(
	t_minishell_state minishell_state,
	unsigned int size
){
	void	*memory_address;

	memory_address = malloc(size);
	if (memory_address == NULL)
	{
		destroy_minishell_state(minishell_state);
	}
	ft_bzero(memory_address, size);
	insert_in_memory_tree(&minishell_state->memory_tree, NULL, memory_address);
	return (memory_address);
}
