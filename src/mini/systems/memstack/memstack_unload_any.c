/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_any.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:30:45 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:27:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_any	memstack_unload_any(t_mini mini)
{
	t_any	value;

	mini->shared->memstack->top -= sizeof(t_any);
	if (mini->shared->memstack->top < mini->shared->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini, MEMSTACK_OVERFLOW_ERROR);
	}
	value = *((t_any *)(mini->shared->memstack->top));
	return (value);
}
