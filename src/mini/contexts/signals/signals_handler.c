/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:12:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 22:57:28 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	signals_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	if (sig == SIGINT)
		signals_sigint_handler(context, sig);
}
