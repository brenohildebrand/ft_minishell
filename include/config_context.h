/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_context.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:58:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 15:13:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_CONTEXT_H
# define CONFIG_CONTEXT_H

#include "minishell.h"

typedef struct s_config_context	*t_config_context;

struct s_config_context {
	t_cstring	prompt;
};

t_config_context	config_context_new(t_mini mini);
t_none				config_context_init(t_mini mini, t_lua_state lua_state);

#endif