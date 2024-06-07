/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:29:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:26:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_u64	memstack_unload_u64(t_mini mini)
{
	t_u64	value;

	mini->shared->memstack->top -= sizeof(t_u64);
	if (mini->shared->memstack->top < mini->shared->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini, MEMSTACK_OVERFLOW_ERROR);
	}
	value = *((t_u64 *)(mini->shared->memstack->top));
	return (value);
}
