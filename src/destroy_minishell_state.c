/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_minishell_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:03:36 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 16:15:18 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

/*
	The command line should already be freed at this point.
*/
void	destroy_minishell_state(t_minishell_state minishell_state)
{
	// destroy_memory_tree(minishell_state->memory_tree);
	free(minishell_state);
}
