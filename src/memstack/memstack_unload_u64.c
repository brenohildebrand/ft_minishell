/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:29:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:29:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_u64	memstack_unload_u64(t_mini mini)
{
	t_u64	value;

	mini->memstack->top -= sizeof(t_u64);
	value = *((t_u64 *)(mini->memstack->top));
	return (value);
}
