/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:50:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:53:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval(t_mini mini)
{
	add_history(mini->reader->statement);
	if (mini->parser->tree)
	{	
		eval_pipe(mini);
	}
}
