/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_control_operator_rule.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:09:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:47:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "types.h"
#include "token.h"
#include "llist.h"

t_i32	check_control_operator_rule(t_llist_node current_node)
{
	t_token	previous_token;
	t_token	next_token;

	previous_token = get_previous_token(current_node);
	next_token = get_next_token(current_node);
	if (previous_token == NULL || previous_token->type <= PIPE)
		return (syntax_error(current_node->value));
	if (next_token == NULL || next_token->type <= PIPE)
		return (syntax_error(current_node->value));
	return (SUCCESS);
}
