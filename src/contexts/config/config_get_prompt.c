/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_get_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:29:25 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:57:45 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	config_get_prompt(t_mini mini)
{
	const t_config		config = mini->config;

	lua_getglobal(config->lua_state, "prompt");
	config->prompt = cstring_copy(mini, (char *)lua_tolstring(config->lua_state, -1, NULL));
	lua_pop(config->lua_state, 1);
}
