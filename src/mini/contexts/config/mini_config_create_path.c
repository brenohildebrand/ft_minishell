/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_config_create_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:07:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 10:12:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_config_create_path(t_mini mini)
{
	t_cstring	dirname;
	t_cstring	basename;

	dirname = mini_cstring_dirname(mini, mini->shared->argv[0]);
	basename = cstring_copy(mini, "/config/mini.lua");
	mini->config->path = mini_cstring_join(mini, dirname, basename);
}
