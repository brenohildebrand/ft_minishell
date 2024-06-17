/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expansion_expand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:19:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:59:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	mini_expansion_expand(
	t_mini mini,
	t_mini_list node,
	t_i32 start,
	t_i32 end
){
	t_cstring	key;
	t_cstring	value;
	t_i32		value_length;
	t_cstring	new_token;

	if (start == end)
		return (start);
	else if (start == end - 1 && node->token[end] == '?')
		value = mini_i32_to_cstring(mini, mini->shared->exit_code);
	else
	{
		key = mini_cstring_get_subcstring(mini, node->token, start + 1, end);
		value = mini_cstring_copy(mini, mini_expansion_getenv(mini, key));
	}
	value_length = cstring_get_length(value);
	new_token = mini_cstring_remove(mini, node->token, start, end);
	new_token = mini_cstring_add(mini, new_token, start, value);
	mini_free(mini, node->token);
	node->token = new_token;
	mini_free(mini, key);
	mini_free(mini, value);
	return (start + value_length);
}
