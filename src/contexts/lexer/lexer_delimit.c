/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delimit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:20:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	should_consider_the_end_character(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->state == 102)
		return (TRUE);
	else if (lexer->state == 104)
		return (TRUE);
	else if (lexer->state == 106)
		return (TRUE);
	else if (lexer->state == 107)
		return (TRUE);
	return (FALSE);
}

static t_none	delimit_with_end(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_mini_token	mini_token;

	mini_token = mini_alloc(mini, sizeof(struct s_mini_token));
	mini_token->length = lexer->end - lexer->start + 1;
	mini_token->value = mini_alloc(mini, mini_token->length + 1);
	mini_token->value[mini_token->length] = '\0';
	mini->i = 0;
	while (mini->i < mini_token->length)
	{
		mini_token->value[mini->i] = lexer->cursor[lexer->start + mini->i];
		mini->i++;
	}
	lexer->end += 1;
	lexer->start = lexer->end;
	mini_token->type = lexer_classify(mini);
	linked_list_append(mini, lexer->tokens, mini_token);
	lexer->state = 0;
}

static t_none	delimit(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_mini_token	mini_token;

	mini_token = mini_alloc(mini, sizeof(struct s_mini_token));
	mini_token->length = lexer->end - lexer->start;
	mini_token->value = mini_alloc(mini, mini_token->length + 1);
	mini_token->value[mini_token->length] = '\0';
	mini->i = 0;
	while (mini->i < mini_token->length)
	{
		mini_token->value[mini->i] = lexer->cursor[lexer->start + mini->i];
		mini->i++;
	}
	lexer->start = lexer->end;
	mini_token->type = lexer_classify(mini);
	linked_list_append(mini, lexer->tokens, mini_token);
	lexer->state = 0;
}

t_none	lexer_delimit(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->state == 108)
	{
		return ;		
	}
	else if (lexer->state == 200)
	{
		mini->input->is_complete = FALSE;
		return ;
	}
	else if (should_consider_the_end_character(mini))
	{
		delimit_with_end(mini);
	}
	else
	{
		delimit(mini);
	}
}


// /**
//  * See '2.10.1 Shell Grammar Lexical Conventions' 
// */
// t_none	lexer_delimit(t_mini mini)
// {
// 	const t_lexer	lexer = mini->lexer;
// 	t_token			new_token;

// 	if (lexer->buffer_length == 0)
// 		return ;
// 	new_token = lexer_token_new(mini);
// 	new_token->length = lexer->buffer_length;
// 	mini->str = mini_alloc(mini, lexer->buffer_length + 1);
// 	mini->i = 0;
// 	while (mini->i < lexer->buffer_length + 1)
// 	{
// 		mini->str[mini->i] = lexer->buffer[mini->i];
// 		mini->i++;
// 	}
// 	mini_free(mini, lexer->buffer);
// 	lexer->buffer = NULL;
// 	lexer->buffer_length = 0;
// 	lexer->buffer_size = 0;
// 	new_token->value = mini->str;
// 	new_token->type = 0;
// 	linked_list_append(mini, lexer->tokens, new_token);
// }
