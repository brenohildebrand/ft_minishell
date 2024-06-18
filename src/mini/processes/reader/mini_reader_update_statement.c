/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reader_update_statement.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:27:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 19:43:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_reader_update_statement(t_mini mini)
{
	if (mini->reader->line)
	{
		if (mini->reader->statement)
			mini->reader->statement = mini_cstring_join(mini, mini->reader->statement, "\n");
		mini->reader->statement = mini_cstring_join(mini, mini->reader->statement, mini->reader->line);	
	}
}
