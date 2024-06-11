/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser_is_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:57:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 21:58:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	mini_parser_is_end(t_mini mini)
{
	if (mini_parser_get_token(mini) == END)
		return (TRUE);
	return (FALSE);
}
