/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:58:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/11 23:30:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_heredoc_read(t_mini mini)
{
	t_cstring	line;
	t_cstring	delimiter;

	delimiter = mini->heredoc->redirs->next->token;
	while (42)
	{
		line = readline(mini->reader->multiline_prompt);
		mini->heredoc->buffer = mini_cstring_join(mini, mini->heredoc->buffer, line);
		if (cstring_compare(line, delimiter) == 0)
		{
			break ;
		}
		
	}
}
