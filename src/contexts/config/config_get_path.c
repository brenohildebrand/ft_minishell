/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_get_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:56:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:45:49 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	config_get_path(t_mini mini)
{
	t_cstring	root;
	
	root = cstring_dirname(mini, mini->argv[0]);
	mini->config->path = cstring_join(mini, root, cstring_copy(mini, "/config/mini.lua"));
}