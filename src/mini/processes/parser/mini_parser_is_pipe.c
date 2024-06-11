/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser_is_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:58:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 21:59:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	mini_parser_is_pipe(t_mini mini)
{
	if (mini_parser_get_token(mini) == PIPE)
		return (TRUE);
	return (FALSE);
}
