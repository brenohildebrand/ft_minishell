/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:11:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/22 12:39:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_read(t_mini mini)
{
	while (!mini_check_flag(mini, MINI_FLAG_STATEMENT_COMPLETED))
	{
		mini_readline(mini);
		mini_tokenize(mini);
		mini_parse(mini);
	}
}
