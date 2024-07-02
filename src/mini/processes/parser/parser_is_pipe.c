/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_is_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:58:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:34:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	parser_is_pipe(t_mini mini)
{
	if (parser_get_token(mini) == PIPE)
		return (TRUE);
	return (FALSE);
}
