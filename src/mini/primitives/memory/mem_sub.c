/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mem_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:42:02 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:30:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mem	mem_sub(t_mini mini, t_mem mem, t_i32 start, t_i32 end)
{
	t_i32	size;
	t_mem	sub;

	size = end - start + 1;
	sub = mini_alloc(mini, size);
	mem_copy_from_to(((t_u8 *)mem + start), sub, size);
	return (sub);		
}
