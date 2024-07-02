/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:02:47 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:29:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	cstring_remove(
	t_mini mini,
	t_cstring cstring,
	t_i32 start,
	t_i32 end
){
	t_i32			cstring_len;
	t_cstring		new_cstring;
	t_i32			new_cstring_len;
	t_i32			i;
	t_i32			j;

	cstring_len = cstring_get_length(cstring);
	new_cstring_len = cstring_len - (end - start + 1);
	new_cstring = mini_alloc(mini, new_cstring_len + 1);
	new_cstring[new_cstring_len] = '\0';
	i = 0;
	j = 0;
	while (i < cstring_len)
	{
		if (i < start || i > end)
		{
			new_cstring[j] = (cstring)[i];
			j++;
		}
		i++;
	}
	return (new_cstring);
}
