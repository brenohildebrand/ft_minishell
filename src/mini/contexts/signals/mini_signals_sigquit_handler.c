/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_sigquit_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 22:38:14 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_sigquit_handler(t_mini mini)
{
	(void)mini;
	signal(SIGQUIT, SIG_IGN);
}
