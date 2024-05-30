/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:05:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"
#include "parser.h"
#include "types.h"
#include "token.h"

t_i32	check_syntax(t_token current_token)
{
	(void)current_token;
	return (SUCCESS);
}

// t_i32	check_syntax(t_token current_token)
// {
// 	t_i32	type;

// 	type = current_token->type;
// 	if (type == AND || type == OR || type == PIPE)
// 		return (check_control_operator_rule(current_token));
// 	else if (type >= REDIR_APPEND && type <= REDIR_OUT)
// 		return (check_redirect_rule(current_token));
// 	else if (type == OPEN_PAREN || type == CLOSE_PAREN)
// 		return (check_parenthesis_rule(current_token));
// 	return (SUCCESS);
// }
