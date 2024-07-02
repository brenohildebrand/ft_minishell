/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton_is_end_of_statement.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:54:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:45:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	lexer_automaton_is_end_of_statement(t_mini mini)
{
	if (mini->lexer->cursor[mini->lexer->start] == '\0')
		return (TRUE);
	return (FALSE);
}
