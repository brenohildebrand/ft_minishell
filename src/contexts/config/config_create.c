/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:04:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	config_create(t_mini mini)
{
	mini->config = mini_alloc(mini, sizeof(struct s_config_context));
	config_get_path(mini);
	config_create_lua_state(mini);
	config_get_prompt(mini);
	config_destroy_lua_state(mini);
}
