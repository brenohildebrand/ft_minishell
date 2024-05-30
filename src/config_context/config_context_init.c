/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_context_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:09:22 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	config_context_init(t_mini mini, t_lua_state lua_state)
{
	const t_config_context	context = mini->config_context;
	
	lua_getglobal(lua_state, "prompt");
	context->prompt = cstring_copy(mini, (char *)lua_tolstring(lua_state, -1, NULL));
	lua_pop(lua_state, 1);
}
