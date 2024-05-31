/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:11:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/31 18:39:18 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_read(t_mini mini)
{
	while (!mini->is_statement_complete)
	{
		mini_readline(mini);
		mini_tokenize(mini);
		mini_parse(mini);
	}
}
