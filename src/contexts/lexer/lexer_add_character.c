/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:02:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 10:54:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_add_character(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->buffer_size == 0 || lexer->buffer_length + 2 > lexer->buffer_size)
	{
		mini->str = NULL;
		if (lexer->buffer_size == 0)
		{
			lexer->buffer_size = 16;
		}
		else
		{
			lexer->buffer_size *= 2;
		}
		mini->str = mini_alloc(mini, lexer->buffer_size);
		mini->i = 0;
		while (mini->i < lexer->buffer_length)
		{
			mini->str[mini->i] = lexer->buffer[mini->i];
			mini->i++;
		}
		mini->str[mini->i] = '\0';
		mini_free(mini, lexer->buffer);
		lexer->buffer = mini->str;
	}
	lexer->buffer[lexer->buffer_length] = lexer->cursor[0];	
	lexer->buffer_length += 1;
	lexer->buffer[lexer->buffer_length] = '\0';
	lexer->cursor += 1;
}
