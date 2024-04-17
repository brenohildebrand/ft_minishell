/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_deallocate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:37:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 11:26:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_deallocate(
	t_minishell_state minishell_state,
	void *memory_address
){
	remove_from_memory_tree(&minishell_state->memory_tree, memory_address);
}
