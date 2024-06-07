/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:20:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:20:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

# define LEXER_MODE_ORDINARY 1
# define LEXER_MODE_HEREDOC 2

typedef struct s_lexer_process	*t_lexer_process;
typedef t_lexer_process			t_lexer;

struct s_lexer_process {
	t_i32			mode;
	t_mini_list		tokens;
	t_cstring		cursor;
	t_i32			start;
	t_i32			end;
	t_i32			state;
	t_i32			table[7][8];
};

t_none	mini_lexer_create(t_mini mini);

t_none	mini_lexer_update_mode(t_mini mini);
t_none	mini_lexer_ordinary(t_mini mini);
t_none	mini_lexer_heredoc(t_mini mini);

t_none	mini_lexer_automaton(t_mini mini);
t_none	mini_lexer_automaton_init(t_mini mini);
t_none	mini_lexer_automaton_next_state(t_mini mini);
t_bool	mini_lexer_automaton_is_final_state(t_mini mini);
t_none	mini_lexer_automaton_delimit(t_mini mini);
t_i32	mini_lexer_automaton_typefy(t_mini mini);
t_bool	mini_lexer_automaton_is_end_of_statement(t_mini mini);
t_bool	mini_lexer_automaton_is_whitespace(t_mini mini);

#endif