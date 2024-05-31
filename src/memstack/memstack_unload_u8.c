/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:19:34 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 18:32:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	memstack_unload_u8(t_mini mini, t_u8 value)
{
	t_u8	value;

	value = *(--(mini->memstack->top));
	mini->memstack->top = '\0';
	return (value);
}
