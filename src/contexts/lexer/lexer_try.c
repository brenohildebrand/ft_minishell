/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_try.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:46:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 18:36:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_bool	lexer_try(t_mini mini, t_cstring operator)
{
	const t_lexer	lexer = mini->lexer;

	mini->i = 0;
	while (mini->i < lexer->buffer_length)
	{
		if (operator[mini->i] == '\0')
			return (FALSE);
		if (lexer->buffer[mini->i] != operator[mini->i])
			return (FALSE);
		mini->i++;
	}
	if (lexer->cursor[0] != operator[mini->i])
		return (FALSE);
	return (TRUE);	
}
