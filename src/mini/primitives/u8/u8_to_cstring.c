/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u8_to_cstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:55:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 22:58:26 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	u8_to_cstring(t_mini mini, t_u8 value)
{
	t_i32		len;
	t_u8		value_copy;
	t_cstring	cstring;

	if (value == 0)
		return (cstring_copy(mini, "0"));
	len = 0;
	value_copy = value;
	while (value_copy)
	{
		value_copy /= 10;
		len++;
	}
	cstring = mini_alloc(mini, len + 1);
	cstring[len] = '\0';
	while (value)
	{
		len--;
		cstring[len] = (value % 10) - '0';
		value /= 10;
	}
	return (cstring);
}
