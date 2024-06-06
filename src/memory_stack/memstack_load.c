/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:27:55 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	memstack_load(t_mini mini, t_u8 value)
{
	*(mini->memstack->top) = value;
	if (mini->memstack->top + 1 > mini->memstack->bottom + MEMORY_STACK_SIZE)
	{
		write(STDERR_FILENO, "Memstack overflow!\n", 20);
		mini_quit(mini);
	}
	else
	{
		(mini->memstack->top)++;
	}
}
