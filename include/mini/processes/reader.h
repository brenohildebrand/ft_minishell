/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:35:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:01:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include "minishell.h"

typedef struct s_reader_process	*t_reader_process;
typedef t_reader_process		t_reader;

struct s_reader_process {
	t_cstring	line;
	t_cstring	statement;
	t_cstring	prompt;
	t_cstring	multiline_prompt;
};

t_none	reader_create(t_mini mini);
t_none	reader_reset(t_mini mini);
t_none	reader_create_prompt(t_mini mini);
t_none	reader_create_multiline_prompt(t_mini mini);
t_none	reader_assume_statement_is_complete(t_mini mini);
t_none	reader_readline(t_mini mini);
t_none	reader_update_statement(t_mini mini);
t_none	reader_debug(t_mini mini);

#endif