/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_final_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:47:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_bool	lexer_is_final_state(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->state >= 100)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
