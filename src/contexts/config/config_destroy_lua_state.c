/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_destroy_lua_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:47:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	config_destroy_lua_state(t_mini mini)
{
	lua_close(mini->config->lua_state);
	mini->config->lua_state = NULL;
}
