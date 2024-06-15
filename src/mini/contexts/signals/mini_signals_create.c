/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:01:47 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 22:54:33 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_create(t_mini mini)
{
	mini->signals = mini_alloc(mini, sizeof(struct s_signals_context));
	mini->signals->sigaction = mini_alloc(mini, sizeof(struct sigaction));
	mem_set(mini->signals->sigaction, 0, sizeof(struct sigaction));
	mini->signals->sigaction->sa_sigaction = mini_signals_handler;
	mini->signals->sigaction->sa_flags = SA_SIGINFO;
	mini_assert(mini, sigaction(SIGINT, mini->signals->sigaction, NULL) != -1, SIGNALS_ERROR);
	mini_assert(mini, sigaction(SIGQUIT, mini->signals->sigaction, NULL) != -1, SIGNALS_ERROR);
	signal(SIGQUIT, SIG_IGN);
}
