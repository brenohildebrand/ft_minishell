/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser_is_pipe_sequence.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:56:56 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/08 00:57:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	mini_parser_is_pipe_sequence(t_mini mini)
{
	if (mini_parser_is_command(mini))
	{
		if (mini_parse_is_pipe(mini))
		{

		}
		else
		{
			
		}
	}
	else
	{
		return (FALSE);
	}
}
