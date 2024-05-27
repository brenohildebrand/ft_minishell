/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_load_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:34:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 15:09:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef LUA

t_none	mini_load_config(t_mini mini)
{
	t_lua_state	lua_state;
	t_cstring	root;
	t_cstring	path;

	root = cstring_dirname(mini, mini->mini_context->argv[0]);
	path = cstring_join(mini, root, cstring_copy(mini, "/config/mini.lua"));
	lua_state = luaL_newstate();
	mini_assert(mini, lua_state != NULL, "Failed to create Lua state\n");
	luaL_openlibs(lua_state);
	if (luaL_loadfile(lua_state, path) || lua_pcall(lua_state, 0, 0, 0))
	{
		cstring_to_stderr("Failed to load config file.\n");
		lua_close(lua_state);
		mini_quit(mini);
	}
	config_context_init(mini, lua_state);
	lua_close(lua_state);
}

#else

t_none	mini_load_config(t_mini mini)
{
	(void)mini;
}

#endif