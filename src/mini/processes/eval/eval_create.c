/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:30:13 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:25:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	eval_create(t_mini mini)
{
	mini->eval = mini_alloc(mini, sizeof(struct s_eval_process));
	mini->eval->paths = NULL;
	mini->eval->pipes = NULL;
	mini->eval->redirs[0] = 0;
	mini->eval->redirs[1] = 0;
	mini->eval->tokens = NULL;
}
