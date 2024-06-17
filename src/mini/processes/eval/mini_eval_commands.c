/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:19:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 22:35:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval_commands(t_mini mini)
{
	t_mini_cmd_tree_list	cmd_list;
	t_i32					i;

	mini_eval_create_pipes(mini);
	cmd_list = mini->parser->tree->command_list;
	i = 0;
	while (i < cmd_list->length)
	{
		mini_eval_command(mini, i);
		i++;
	}
	mini_eval_close_pipes(mini);
}
