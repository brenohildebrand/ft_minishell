/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:35:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:34:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	parser_get_token(t_mini mini)
{
	if (mini->parser->cursor)
		return (mini->parser->cursor->type);
	return (END);
}
