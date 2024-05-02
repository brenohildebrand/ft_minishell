/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:00:55 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 18:05:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"
#include "token.h"

t_token	new_token(t_i32 type, t_cstring value)
{
	t_token	instance;

	instance = malloc_with_binary_tree(sizeof(struct s_token));
	instance->type = type;
	instance->value = value;
	return (instance);
}
