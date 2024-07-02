/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:01:47 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 22:56:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	signals_create(t_mini mini)
{
	mini->signals = mini_alloc(mini, sizeof(struct s_signals_context));
	mini->signals->sigaction = mini_alloc(mini, sizeof(struct sigaction));
	mem_set(mini->signals->sigaction, 0, sizeof(struct sigaction));
	mini->signals->sigaction->sa_sigaction = signals_handler;
	mini->signals->sigaction->sa_flags = SA_SIGINFO;
	mini_assert(mini, sigaction(SIGINT, mini->signals->sigaction, NULL) != -1, MINI_ERROR);
	mini_assert(mini, sigaction(SIGQUIT, mini->signals->sigaction, NULL) != -1, MINI_ERROR);
	signal(SIGQUIT, SIG_IGN);
}
