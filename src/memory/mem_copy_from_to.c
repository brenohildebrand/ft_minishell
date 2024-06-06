/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy_from_to.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:24:43 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/05 21:49:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

void	mem_copy_from_to(t_mem from, t_mem to, t_i32 size)
{
	t_i32	i;
	
	i = 0;
	while (i < size)
	{
		((t_u8 *)to)[i] = ((t_u8 *)from)[i];
		i++;
	}
}
