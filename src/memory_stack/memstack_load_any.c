/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_load_any.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:30:43 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:19:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	memstack_load_any(t_mini mini, t_any value)
{
	t_u8	byte;
	t_u32	counter;

	counter = 0;
	while (counter < sizeof(t_any))
	{
		byte = ((t_u8 *)(&value))[counter];
		memstack_load(mini, byte);
		counter++;
	}
}
