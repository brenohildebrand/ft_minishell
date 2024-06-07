/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_config_create_multiline_prompt.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:57:24 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:07:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_config_create_multiline_prompt(t_mini mini)
{
	t_cstring	lua_multiline_prompt;
	
	lua_getglobal(mini->config->lua_state, "multiline_prompt");
	if (!lua_isstring(mini->config->lua_state, -1))
	{
		lua_multiline_prompt = MULTILINE_PROMPT;
	}
	else
	{
		lua_multiline_prompt = (char *)lua_tolstring(mini->config->lua_state, -1, NULL);
	}
	mini->config->multiline_prompt = mini_cstring_copy(mini, lua_multiline_prompt);
	lua_pop(mini->config->lua_state, 1);
}
