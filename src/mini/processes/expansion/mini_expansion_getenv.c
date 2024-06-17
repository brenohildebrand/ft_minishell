/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expand_getenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:37:57 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:58:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cstring	get_env_key(t_mini mini, t_cstring env)
{
	t_i32	i;

	i = 0;
	while (env[i] != '=')
		i++;
	return (mini_cstring_get_subcstring(mini, env, 0, i - 1));
}

static t_cstring	get_env_value(t_mini mini, t_cstring env)
{
	t_i32	i;
	t_i32	j;

	i = 0;
	while (env[i] != '=')
		i++;
	j = i + 1;
	while (env[j])
		j++;
	return (mini_cstring_get_subcstring(mini, env, i + 1, j - 1));
}

t_cstring	mini_expansion_getenv(t_mini mini, t_cstring key)
{
	t_cstring	current_key;
	t_cstring	value;
	t_i32		i;

	i = 0;
	value = NULL;
	while (mini->shared->env[i])
	{
		current_key = get_env_key(mini, mini->shared->env[i]);
		if (cstring_compare(key, current_key) == 0)
			value = get_env_value(mini, mini->shared->env[i]);
		mini_free(mini, current_key);
		i++;
	}
	return (value);
}
