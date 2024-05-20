/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_get_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:03:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 18:30:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	cstring_get_length(t_cstring message)
{
	t_i32	length;

	if (message == NULL)
	{
		return (0);
	}
	length = 0;
	while (message[length])
	{
		length += 1;
	}
	return (length);
}
