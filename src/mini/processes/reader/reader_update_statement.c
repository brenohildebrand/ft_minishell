/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_update_statement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:27:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 18:21:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	reader_update_statement(t_mini mini)
{
	if (mini->reader->line)
	{
		if (mini->reader->statement)
			mini->reader->statement = cstring_join(mini, mini->reader->statement, "\n");
		mini->reader->statement = cstring_join(mini, mini->reader->statement, mini->reader->line);	
	}
}
