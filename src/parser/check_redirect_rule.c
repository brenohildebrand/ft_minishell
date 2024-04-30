/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect_rule.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:16:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 17:30:58 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"
#include "types.h"
#include "token.h"

t_i32	check_redirect_rule(t_linked_list_node current_node)
{
	t_token	next_token;

	next_token = current_node->next;
	if (next_token == NULL || next_token->type != WORD)
		return (syntax_error(current_node->value));
	return (SUCCESS);
}
