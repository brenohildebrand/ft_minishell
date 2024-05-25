/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 19:07:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static t_bool	is_final_state(t_i32 state)
// {
// 	return (state >= 100); 
// }

// static t_none	go_to_next_state(t_i32 *p_state, t_cstring *p_cursor)
// {
// 	t_i32	(*transition_table)[8];
// 	t_i8	character;

// 	transition_table = mini_get_transition_table();
// 	character = (*p_cursor);
// 	if (character == ">")
// 	{
		
// 	} 
// }


// t_none	mini_tokenize(t_mini mini)
// {
// 	t_i32		state;
// 	t_cstring	cursor;

// 	state = 0;
// 	cursor = mini->line;
// 	while (cursor)
// 	{
// 		go_to_next_state(&state, &cursor);
// 		if (is_final_state(state))
// 		{
// 			token = token_new();
// 			mini_add_token(mini);
// 		}
// 	}
// 	if (mini_check_flag(mini, MINI_FLAG_STATEMENT_COMPLETED))
// 	{
// 		add_history(mini->statement);
// 		mini_free(mini, mini->statement);
// 		mini->statement = NULL;
// 	}
// 	#ifdef DEBUG
// 	#endif
// }


t_none	mini_tokenize(t_mini mini)
{
	t_tokenizer_context	context;

	context = tokenizer_context_new(mini, mini->line);
	while (context->completed == FALSE)
	{
		if (context->mode == TOKENIZER_MODE_ORDINARY)
		{
			ordinary_tokenizer(mini, context);
		}
		else if (context->mode == TOKENIZER_MODE_HEREDOC)
		{
			heredoc_tokenizer(mini, context);
		}
	}
	tokenizer_context_destroy(mini, context);
	#ifdef DEBUG
		t_list_node	node;
		t_token		token;

		if (mini->list->head)
		{
			node = mini->list->head;
			while (node->next)
			{
				token = (t_token)node->value;
				printf("{length: %s, type: %s, value: %s}\n", token->length, token->type, token->value);
				node = node->next;
			}
		}
	#endif
	mini_free(mini, mini->line);
}
