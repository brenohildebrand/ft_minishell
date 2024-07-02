/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32_to_cstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:04:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 23:00:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	i32_to_cstring(t_mini mini, t_i32 number)
{
	t_i64		number_copy;
	t_i32		length;
	t_cstring	cstring;

	number_copy = (t_i64)number;
	length = 0;
	while (number_copy)
	{
		number_copy /= 10;
		length++;
	}
	cstring = mini_alloc(mini, length + 1);
	cstring[length] = '\0';
	length--;
	number_copy = (t_i64)number;
	while (number_copy)
	{
		cstring[length] = (number_copy % 10) + '0';
		number_copy /= 10;
		length--;
	}
	return (cstring);
}
