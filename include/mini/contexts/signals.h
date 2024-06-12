/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:59:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/12 14:10:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

typedef struct s_signals_context	*t_signals_context;
typedef t_signals_context			t_signals;
typedef struct s_sigaction			*t_sigaction;

struct s_signals_context {
	t_sigaction	sigaction;
};

t_none	mini_signals_create(t_mini mini);
t_none	mini_signals_handler(t_mini mini);

#endif