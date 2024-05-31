/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_i64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:27:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:29:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_i64	memstack_unload_i64(t_mini mini)
{
	t_i64	value;

	mini->memstack->top -= sizeof(t_i64);
	value = *((t_i64 *)(mini->memstack->top));
	return (value);
}
