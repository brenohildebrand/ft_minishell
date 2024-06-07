/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:19:34 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:26:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_u8	memstack_unload_u8(t_mini mini)
{
	t_u8	value;

	mini->shared->memstack->top -= sizeof(t_u8);
	if (mini->shared->memstack->top < mini->shared->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini, MEMSTACK_OVERFLOW_ERROR);
	}
	value = *((t_u8 *)(mini->shared->memstack->top));
	return (value);
}
