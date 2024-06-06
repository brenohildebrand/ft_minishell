/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:30:22 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	lexer_expand(t_mini mini, t_cstring str)
{
	t_cstring	new_str;
	t_i32		length;

	length = cstring_get_length(str);
	if (length == 1)
	{
		if (str[0] == '?')
		{
			new_str = cstring_copy(mini, i32_to_cstring(mini, mini->exit_status));
		}
	}
	else
	{
		new_str = getenv(str);
	}
	return (new_str);
}