/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_i32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:15:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:27:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	memstack_unload_i32(t_mini mini)
{
	t_i32	value;

	mini->shared->memstack->top -= sizeof(t_i32);
	if (mini->shared->memstack->top < mini->shared->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini, MEMSTACK_OVERFLOW_ERROR);
	}
	value = *((t_i32 *)(mini->shared->memstack->top));
	return (value);
}
