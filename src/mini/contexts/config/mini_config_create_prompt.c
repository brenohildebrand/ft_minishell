/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_config_create_prompt.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:31:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:03:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_config_create_prompt(t_mini mini)
{
	t_cstring	lua_prompt;

	lua_getglobal(mini->config->lua_state, "prompt");
	if (!lua_isstring(mini->config->lua_state, -1))
	{
		lua_prompt = PROMPT;
	}
	else
	{
		lua_prompt = (char *)lua_tolstring(config->lua_state, -1, NULL);
	}
	mini->config->prompt = mini_cstring_copy(mini, lua_prompt);
	lua_pop(mini->config->lua_state, 1);
}
