/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:01:47 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/12 14:11:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_create(t_mini mini)
{
	mini->signals->sigaction = mini_alloc(mini, sizeof(struct sigaction));
	mem_set(mini->signals->sigaction, 0, sizeof(struct sigaction));
	mini->signals->sigaction->sa_handler = mini_signals_handler;
	sigemptyset(mini->signals->sigaction->sa_mask);
	mini->signals->sigaction->flags = 0;
	mini_assert(mini, sigaction(SIGINT, &sa, NULL) != -1, SIGNALS_ERROR);
	mini_assert(mini, sigaction(SIGQUIT, &sa, NULL) != -1, SIGNALS_ERROR);
}
