/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:22:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 16:10:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"

t_i32	lexer(t_minishell mini)
{
	t_i32		type;
	t_i32		length;
	t_cstring	value;

	if (mini->line == NULL || check_open_syntax(mini->line))
	{
		return (set_exit_status(SYNTAX_ERROR));
	}
	while (*(mini->line))
	{
		length = 0;
		type = get_token_type(mini->line);
		if (type == SPACES)
		{
			(mini->line)++;
		}
		else
		{
			length = get_token_length(mini->line, type);
			value = ft_substr(mini->line, 0, length);
			push_to_token_list(mini->list, new_token(mini, type, value));
			mini->line += length;
		}
	}
	return (SUCCESS);
}
