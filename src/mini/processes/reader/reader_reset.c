/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:25:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 18:26:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	reader_reset(t_mini mini)
{
	mini->reader->line = NULL;
	if (mini->reader->statement)
		mini_free(mini, mini->reader->statement);
	mini->reader->statement = NULL;
}
