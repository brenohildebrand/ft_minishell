/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_automaton_delimit.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:45:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 15:54:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	should_consider_the_last_character(t_mini mini)
{
	if (mini->lexer->state == 102)
		return (TRUE);
	else if (mini->lexer->state == 104)
		return (TRUE);
	else if (mini->lexer->state == 106)
		return (TRUE);
	else if (mini->lexer->state == 107)
		return (TRUE);
	return (FALSE);
}

static t_none	delimit_with_last_character(t_mini mini)
{
	t_cstring		token;
	t_i32			type;
	t_i32			len;
	t_i32			i;

	len = lexer->end - lexer->start + 1;
	token = mini_alloc(mini, len + 1);
	token[len] = '\0';
	i = 0;
	while (i < len)
	{
		token[i] = mini->lexer->cursor[mini->lexer->start + i];
		i++;
	}
	mini->lexer->end += 1;
	mini->lexer->start = lexer->end;
	type = mini_lexer_automaton_typefy(mini);
	mini_list_append(mini, &(mini->lexer->tokens), token, type);
	mini->lexer->state = 0;
}

static t_none	delimit(t_mini mini)
{
	t_cstring		token;
	t_i32			type;
	t_i32			len;
	t_i32			i;

	len = mini->lexer->end - mini->lexer->start;
	token = mini_alloc(mini, len + 1);
	token[len] = '\0';
	i = 0;
	while (i < len)
	{
		token[i] = mini->lexer->cursor[mini->lexer->start + i];
		i++;
	}
	mini->lexer->start = mini->lexer->end;
	type = mini_lexer_automaton_typefy(mini);
	mini_list_append(mini, &(mini->lexer->tokens), token, type);
	mini->lexer->state = 0;
}

t_none	mini_lexer_automaton_delimit(t_mini mini)
{
	if (mini->lexer->state == 108)
	{
		return ;
	}
	else if (mini->lexer->state == 200)
	{
		mini->shared->is_statement_complete = FALSE;
		return ;
	}
	else if (should_consider_the_last_character(mini))
	{
		delimit_with_last_character(mini);
	}
	else
	{
		delimit(mini);
	}
}
