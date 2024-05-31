/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_any.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:30:45 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:31:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_any	memstack_unload_any(t_mini mini)
{
	t_any	value;

	mini->memstack->top -= sizeof(t_any);
	value = *((t_any *)(mini->memstack->top));
	return (value);
}
