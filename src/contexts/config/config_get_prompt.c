/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_get_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:29:25 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 15:34:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	config_get_prompt(t_mini mini)
{
	const t_config		config = mini->config;

	lua_getglobal(config->lua_state, "prompt");
	mini_load_any(mini, (char *)lua_tolstring(lua_state, -1, NULL));
	cstring_copy(mini);
	config->prompt = mini_unload_any(mini);
	lua_pop(lua_state, 1);
}
