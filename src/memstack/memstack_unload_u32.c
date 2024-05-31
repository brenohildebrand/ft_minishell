/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:24:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:26:31 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_u32	memstack_unload_u32(t_mini mini)
{
	t_u32	value;

	mini->memstack->top -= sizeof(t_u32);
	value = *((t_u32 *)(mini->memstack->top));
	return (value);
}
