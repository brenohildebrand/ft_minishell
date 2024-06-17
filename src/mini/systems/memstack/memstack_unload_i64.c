/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_i64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:27:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:52:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i64	memstack_unload_i64(t_mini mini)
{
	t_i64	value;

	mini->shared->memstack->top -= sizeof(t_i64);
	if (mini->shared->memstack->top < mini->shared->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini, MINI_ERROR);
	}
	value = *((t_i64 *)(mini->shared->memstack->top));
	return (value);
}
