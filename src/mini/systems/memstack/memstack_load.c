/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:27:55 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:52:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	memstack_load(t_mini mini, t_u8 value)
{
	*(mini->shared->memstack->top) = value;
	if (mini->shared->memstack->top + 1 > mini->shared->memstack->bottom + MEMSTACK_SIZE)
	{
		write(STDERR_FILENO, "Memstack overflow!\n", 20);
		mini_quit(mini, MINI_ERROR);
	}
	else
	{
		(mini->shared->memstack->top)++;
	}
}
