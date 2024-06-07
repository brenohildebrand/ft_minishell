/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:24:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:26:45 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_u32	memstack_unload_u32(t_mini mini)
{
	t_u32	value;

	mini->shared->memstack->top -= sizeof(t_u32);
	if (mini->shared->memstack->top < mini->shared->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini, MEMSTACK_OVERFLOW_ERROR);
	}
	value = *((t_u32 *)(mini->shared->memstack->top));
	return (value);
}
