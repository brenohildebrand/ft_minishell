/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_context_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:04:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 15:05:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_config_context	config_context_new(t_mini mini)
{
	t_config_context	config_context;

	config_context = mini_alloc(mini, (sizeof(struct s_config_context)));
	config_context->prompt = NULL;
	return (config_context);
}
