/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_next_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:46:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 17:46:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_i32	lexer_next_state(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_i8			character;

	character = lexer->cursor[lexer->index];
	if (character == ">")
		return (lexer->table[lexer->state][2]);
	else if (character == "<")
		return (lexer->table[lexer->state][3]);
	else if (character == "\"")
		return (lexer->table[lexer->state][3]);
	else if (character == "'")
		return (lexer->table[lexer->state][4]);
	else if (character == "|")
		return (lexer->table[lexer->state][5]);
	else if (character == " " || (character >= '\t' && character <= '\r'))
		return (lexer->table[lexer->state][6]);
	else if (character == "\0")
		return (lexer->table[lexer->state][7]);
	else
		return (lexer->table[lexer->state][0]);
}
