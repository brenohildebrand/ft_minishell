/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_automaton_is_whitespace.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:57:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:16:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	mini_lexer_automaton_is_whitespace(t_mini mini)
{
	if (mini->lexer->state == 0)
		return (TRUE);
	return (FALSE);
}
