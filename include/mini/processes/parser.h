/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:51:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:29:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parser_process	*t_parser_process;
typedef t_parser_process		t_parser;

struct s_parser_process {
	t_mini_tree	tree;
};

t_none	mini_parser_create(t_mini mini);

#endif