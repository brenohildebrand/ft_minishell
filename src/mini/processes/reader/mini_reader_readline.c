/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reader_readline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:25:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 17:49:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_reader_readline(t_mini mini)
{
	if (mini->reader->statement == NULL)
		mini->reader->line = readline(mini->reader->prompt);
	else
		mini->reader->line = readline(mini->reader->multiline_prompt);
	if (mini->reader->line == NULL)
	{
		cstring_to_stdout("exit\n");
		mini_quit(mini, mini->shared->exit_code);
	}
}
