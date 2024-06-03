/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_try_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:36:57 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 16:50:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_bool	lexer_try_operator(t_mini mini)
{
	t_bool	found;

	found = FALSE;
	found = found || lexer_try(mini, "<<");
	found = found || lexer_try(mini, ">>");
	found = found || lexer_try(mini, "<");
	found = found || lexer_try(mini, ">");
	found = found || lexer_try(mini, "|");
	found = found || lexer_try(mini, "||");
	found = found || lexer_try(mini, "&&");
	return (found);
}
