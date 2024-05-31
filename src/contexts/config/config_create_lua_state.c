/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_create_lua_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:34:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:56:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	config_create_lua_state(t_mini mini)
{
	const t_config	config = mini->config;

	config->lua_state = luaL_newstate();
	mini_assert(mini, config->lua_state != NULL, "Failed to create Lua state\n");
	luaL_openlibs(config->lua_state);
	if (luaL_loadfile(config->lua_state, config->path) || lua_pcall(config->lua_state, 0, 0, 0))
	{
		cstring_to_stderr("Failed to load config file.\n");
		lua_close(config->lua_state);
		mini_quit(mini);
	}
}