/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:51:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 20:54:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	tokenizer(t_mini mini)
{
	// t_cstring	cursor;
	// t_list		list;
	// t_token		token;

	// if (mini->line == NULL || tokenizer_check_open_syntax(mini))
	// {
	// 	mini->exit_status = 2;
	// 	return ;
	// }
	// list = list_new(mini);
	// cursor = mini->line;
	// while (cursor)
	// {
	// 	token = tokenizer_new_token();
	// 	token->type = get_next_token_type(cursor);
	// 	if (token->type == SPACES)
	// 	{
	// 		cursor += 1;
	// 		mini_free(token);
	// 	}
	// 	else
	// 	{
	// 		token->token = cstring_substr(mini, cursor, 0, token->length);
	// 		token->length = cstring_get_length(token->token);
	// 		list_append(mini->list, token);
	// 		cursor += token->length;
	// 	}
	// }
	// #ifdef DEBUG
	// #endif
	(void)mini;
}
