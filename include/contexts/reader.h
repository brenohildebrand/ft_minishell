/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:35:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/05 21:30:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include "contexts/mini.h"

typedef struct s_reader_context	*t_reader_context;
typedef t_reader_context		t_reader;

struct s_reader_context {
	t_cstring	line;
	t_cstring	prompt;
	t_bool		is_complete;
	t_bool		is_multiline;
};

t_none	reader_create(t_mini mini);
t_none	reader_get_prompt(t_mini mini);

#endif