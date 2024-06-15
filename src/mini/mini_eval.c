/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:50:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 23:54:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval(t_mini mini)
{
	add_history(mini->reader->statement);
	if (mini->parser->tree)
	{	
		mini_eval_pipe(mini);
	}
}
