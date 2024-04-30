/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:34:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 17:41:31 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"
# include "linked_list.h"
# include "binary_tree.h"

t_i32	check_control_operator_rule(t_linked_list_node current_node);
t_i32	check_parenthesis_rule(t_linked_list_node current_node);
t_i32	check_redirect_rule(t_linked_list_node current_node);
t_i32	check_syntax(t_token current_token);

t_token	get_next_token(t_linked_list_node current_node);
t_token	get_previous_token(t_linked_list_node current_node);

t_i32	parser(t_linked_list tokens, t_binary_tree execution_tree);

#endif