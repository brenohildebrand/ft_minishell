/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parenthesis_rule.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:19:53 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 17:30:08 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"
#include "token.h"
#include "linked_list.h"

t_i32	check_parenthesis_rule(t_linked_list_node current_node)
{
	t_token	current_token;
	t_token	next_token;
	t_token	previous_token;

	current_token = current_node->value;
	next_token = NULL;
	previous_token = NULL;
	if (current_node->next)
		next_token = current_node->next->value;
	if (current_node->previous)
		previous_token = current_node->previous->value;
	if (current_token->type == OPEN_PAREN)
	{
		if (previous_token != NULL && previous_token->type > OPEN_PAREN)
			return (syntax_error(current_node->value));
		if (next_token == NULL || next_token->type <= PIPE)
			return (syntax_error(current_node->value));
	}
	else if (current_token->type == CLOSE_PAREN)
	{
		if (previous_token == NULL || previous_token->type != WORD && previous_token->type != CLOSE_PAREN)
			return (syntax_error(current_node->value));
		if (next_token != NULL && next_token->type == WORD)
			return (syntax_error(current_node->value));
	}
	return (SUCCESS);
}
