/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_load_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:34:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 15:45:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

#ifdef LUA

t_none	mini_load_config(t_mini mini)
{
	t_lua_state	lua_state;
	t_cstring	root;
	t_cstring	path;

	root = cstring_dirname(mini, mini->mini_context->argv[0]);
	path = cstring_join(mini, root, cstring_copy(mini, "/config/mini.lua"));
	lua_state = luaL_newstate();
	
	config_context_init(mini, lua_state);
	lua_close(lua_state);
}

#else

t_none	mini_load_config(t_mini mini)
{
	(void)mini;
}

#endif