/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_config_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:04:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:06:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_config_create(t_mini mini)
{
	mini->config = mini_alloc(mini, sizeof(struct s_config_context));
	mini_config_create_lua_state(mini);
	mini_config_create_path(mini);
	mini_config_create_prompt(mini);
	mini_config_destroy_lua_state(mini);
}
