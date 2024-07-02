/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_is_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:54:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:34:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	parser_is_word(t_mini mini)
{
	if (parser_get_token(mini) == WORD)
		return (TRUE);
	else if (parser_get_token(mini) == DOUBLE_QUOTES)
		return (TRUE);
	else if (parser_get_token(mini) == SINGLE_QUOTES)
		return (TRUE);
	return (FALSE);
}
