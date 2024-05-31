/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:19:34 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/31 17:21:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_u8	memstack_unload_u8(t_mini mini)
{
	t_u8	value;

	mini->memstack->top -= sizeof(t_u8);
	if (mini->memstack->top < mini->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini);
	}
	value = *((t_u8 *)(mini->memstack->top));
	return (value);
}
