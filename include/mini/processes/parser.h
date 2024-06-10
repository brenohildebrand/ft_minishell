/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:51:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 14:51:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parser_process	*t_parser_process;
typedef t_parser_process		t_parser;

struct s_parser_process {
	t_mini_tree	tree;
	t_mini_list	cursor;
	t_bool		found_heredoc;
	t_bool		could_be_completed;
	t_cstring	unexpected_token;
};

enum e_grammar_rule {
	PIPE_SEQUENCE,
	COMMAND,
	END,
};

t_none		mini_parser_create(t_mini mini);
t_none		mini_parser_set_syntax_error(t_mini mini);
t_none		mini_parser_print_syntax_error(t_mini mini);

t_mini_tree	mini_parse_pipe_sequence(t_mini mini);

t_i32		mini_parse_get_token(t_mini mini);
t_none		mini_parser_next_token(t_mini mini);

#endif