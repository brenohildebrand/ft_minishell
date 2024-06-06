/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_config_create_lua_state.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:32:39 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 11:04:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	mini_lua_load_file(t_mini mini)
{
	if (luaL_loadfile(mini->config->lua_state, mini->config->path))
	{
		return (TRUE);
	}
	if (lua_pcall(mini->config->lua_state, 0, 0, 0))
	{
		return (TRUE);
	}
	return (FALSE);
}

t_none	mini_config_create_lua_state(t_mini mini)
{
	mini->config->lua_state = luaL_newstate();
	mini_assert(mini, mini->config->lua_state != NULL, MEMORY_ALLOCATION_ERROR);
	luaL_openlibs(mini->config->lua_state);
	if (mini_lua_load_file(mini))
	{
		lua_close(mini->config->lua_state);
		mini_assert(mini, false, LUA_ERROR);
	}
}
