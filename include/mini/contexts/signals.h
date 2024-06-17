/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:59:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/15 18:31:51 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

typedef struct s_signals_context	*t_signals_context;
typedef t_signals_context			t_signals;
typedef struct sigaction			*t_sigaction;

struct s_signals_context {
	t_sigaction	sigaction;
};

t_none	mini_signals_create(t_mini mini);
t_none	mini_signals_handler(int sig, siginfo_t *info, void *context);
t_none	mini_signals_sigint_handler(t_mini mini, t_i32 sig);
t_none	mini_signals_sigquit_handler(t_mini mini);

#endif