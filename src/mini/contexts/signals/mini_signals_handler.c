/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:12:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 22:56:07 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	if (sig == SIGINT)
		mini_signals_sigint_handler(context, sig);
}
