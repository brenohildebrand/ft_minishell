/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:51:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 22:34:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parser_process	*t_parser_process;
typedef t_parser_process		t_parser;

struct s_parser_process {
	t_mini_pipe_tree	tree;
	t_mini_list			cursor;
	t_bool				found_heredoc;
	t_bool				could_be_completed;
	t_cstring			unexpected_token;
};

t_none				mini_parser_create(t_mini mini);
t_none				mini_parser_set_syntax_error(t_mini mini);
t_none				mini_parser_print_syntax_error(t_mini mini);

t_mini_pipe_tree	mini_parse_pipe_sequence(t_mini mini);
t_mini_cmd_tree		mini_parse_command(t_mini mini);

t_i32				mini_parser_get_token(t_mini mini);
t_none				mini_parser_next_token(t_mini mini);

t_bool				mini_parser_is_end(t_mini mini);
t_bool				mini_parser_is_pipe(t_mini mini);
t_bool				mini_parser_is_redir(t_mini mini);
t_bool				mini_parser_is_word(t_mini mini);

t_none				mini_parser_reset(t_mini mini);

#endif