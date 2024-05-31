/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:51:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:06:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "contexts/mini.h"

typedef struct s_parser_context	*t_parser_context;
typedef t_parser_context		t_context;

struct s_parser_context {
	t_i32	whatever;	
};

t_none	parser_create(t_mini mini);

#endif