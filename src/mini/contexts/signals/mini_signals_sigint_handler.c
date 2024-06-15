/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_sigint_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 22:47:46 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_sigint_handler(t_mini mini, t_i32 sig)
{
	(void)mini;
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	mini_reset(mini);
}
