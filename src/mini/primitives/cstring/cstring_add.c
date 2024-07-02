/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:33:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:29:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	cstring_add(
	t_mini mini,
	t_cstring cstring,
	t_i32 start,
	t_cstring value
){
	t_cstring	new_cstring;
	t_i32		new_cstring_len;
	t_i32		value_len;
	t_i32		i;
	t_i32		j;

	value_len = cstring_get_length(value);
	new_cstring_len = cstring_get_length(cstring) + value_len;
	new_cstring = mini_alloc(mini, new_cstring_len + 1);
	new_cstring[new_cstring_len] = '\0';
	i = 0;
	j = 0;
	while (i < new_cstring_len)
	{
		if (i >= start && j < value_len)
		{
			new_cstring[i] = value[j];
			j++;	
		}
		else
		{
			new_cstring[i] = (cstring)[i - j];
		}
		i++;
	}
	return (new_cstring);
}
