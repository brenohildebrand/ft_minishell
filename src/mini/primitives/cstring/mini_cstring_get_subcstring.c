/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_get_subcstring.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:53:37 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	mini_cstring_get_subcstring(
	t_mini mini,
	t_cstring cstring,
	t_i32 start,
	t_i32 end
){
	t_cstring	subcstring;
	t_i32		length;
	t_i32		i;

	length = end - start + 1;
	subcstring = mini_alloc(mini, length + 1);
	subcstring[length] = '\0';
	i = 0;
	while (i < length)
	{
		subcstring[i] = cstring[start + i];
		i++;
	}
	return (subcstring);
}
