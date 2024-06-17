/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_close_redirs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:36:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 22:37:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval_close_redirs(t_mini mini)
{
	mini_assert(mini, close(mini->eval->redirs[0]) != -1, 0);
	mini_assert(mini, close(mini->eval->redirs[1]) != -1, 0);
}
