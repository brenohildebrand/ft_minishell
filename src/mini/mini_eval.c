/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:50:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 01:23:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval(t_mini mini)
{
	if (mini->reader->statement[0] != '\0')
		add_history(mini->reader->statement);
	if (mini->parser->tree)
	{	
		eval_pipe(mini);
	}
}
