/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:22:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 15:27:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"

t_i32	lexer(t_cstring line, t_linked_list list)
{
	t_i32		type;
	t_i32		length;
	t_cstring	value;

	if (line == NULL || check_open_syntax(line))
	{
		return (set_exit_status(SYNTAX_ERROR));		
	}
	while (*line)
	{
		length = 0;
		type = get_token_type(line);
		if (type == SPACES)
		{
			line++;
		}
		else
		{
			length = get_token_length(line, type);
			value = ft_substr(line, 0, length);
			push_to_token_list(list, new_token(type, length, value));
			line += length;
		}
	}
	return (SUCCESS);
}
