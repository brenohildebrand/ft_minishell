/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_close_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:22:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:24:56 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	eval_close_pipes(t_mini mini)
{
	t_i32	i;
	t_i32	len;

	len = mini->parser->tree->command_list->length;
	i = 0;
	while (i < 2 * (len - 1))
	{
		close(mini->eval->pipes[i]);
		i++;
	}
}
