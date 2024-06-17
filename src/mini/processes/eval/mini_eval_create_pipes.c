/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_create_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:20:18 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:51:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval_create_pipes(t_mini mini)
{
	t_i32	i;
	t_i32	len;

	len = mini->parser->tree->command_list->length;
	mini->eval->pipes = mini_alloc(mini, sizeof(int) * (len - 1));
	i = 0;
	while (i < len - 1)
	{
		mini_assert(mini, pipe(mini->eval->pipes + 2 * i) != -1, MINI_ERROR);
		i++;
	}
}
