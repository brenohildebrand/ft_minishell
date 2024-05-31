/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_i32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:15:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:23:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_i32	memstack_unload_i32(t_mini mini)
{
	t_i32	value;

	mini->memstack->top -= sizeof(t_i32);
	value = *((t_i32 *)(mini->memstack->top));
	return (value);
}
