/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:12:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/12 14:52:08 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	if (signal == SIGINT)
		mini_signals_sigint_handler(context);
	else if (signal == SIGQUIT)
		mini_signals_sigquit_handler(context);
}
