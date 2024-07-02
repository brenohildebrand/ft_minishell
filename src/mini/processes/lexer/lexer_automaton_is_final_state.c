/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton_is_final_state.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:43:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:13:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	lexer_automaton_is_final_state(t_mini mini)
{
	if (mini->lexer->state >= 100)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
