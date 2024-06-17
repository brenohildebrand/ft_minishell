/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_i8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:33:41 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:52:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i8	memstack_unload_i8(t_mini mini)
{
	t_i8	value;

	mini->shared->memstack->top -= sizeof(t_i8);
	if (mini->shared->memstack->top < mini->shared->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini, MINI_ERROR);
	}
	value = *((t_i8 *)(mini->shared->memstack->top));
	return (value);
}
