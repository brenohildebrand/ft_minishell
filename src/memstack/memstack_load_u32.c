/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_load_u32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:24:56 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:25:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	memstack_load_u32(t_mini mini, t_u32 value)
{
	t_u8	byte;
	t_i32	counter;

	counter = 0;
	while (counter < sizeof(t_u32))
	{
		byte = ((t_u8 *)(&value))[counter];
		memstack_load(mini, byte);
		counter++;
	}
}
