/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_i8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:33:41 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 18:35:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_i8	memstack_unload_i8(t_mini mini)
{
	t_i8	value;

	value = *((t_i8 *)(--(mini->memstack->top)));
	return (value);
}
