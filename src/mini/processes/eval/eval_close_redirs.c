/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_close_redirs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:36:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:24:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	eval_close_redirs(t_mini mini)
{
	if (mini->eval->redirs[0])
		mini_assert(mini, close(mini->eval->redirs[0]) != -1, 0);
	if (mini->eval->redirs[1])
		mini_assert(mini, close(mini->eval->redirs[1]) != -1, 0);
}
