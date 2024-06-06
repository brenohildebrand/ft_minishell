/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:58:13 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 12:57:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "minishell.h"

# ifdef ENABLE_LUA 

typedef struct s_config_context	*t_config_context;
typedef t_config_context		t_config;

struct s_config_context {
	lua_State	lua_state;
	t_cstring	path;
	t_cstring	prompt;
	t_cstring	multiline_prompt;
};

t_none	mini_config_create(t_mini mini);
t_none	mini_config_create_lua_state(t_mini mini);
t_none	mini_config_create_path(t_mini mini);
t_none	mini_config_create_prompt(t_mini mini);
t_none	mini_config_create_multiline_prompt(t_mini mini);
t_none	mini_config_destroy_lua_state(t_mini mini);

# endif

#endif