/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_context.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:49:03 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 12:58:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_CONTEXT_H
# define MINI_CONTEXT_H

# include "minishell.h"

typedef struct s_mini_context	*t_mini_context;

struct s_mini_context {
	t_i32		argc;
	t_cstring	*argv;
	t_memtree	memtree;
	t_cstring	line;
	t_i32		bitmask;
	t_i32		exit_status;
};

t_mini_context	mini_context_new(void);
t_none			mini_context_init(t_mini mini, t_i32 argc, t_cstring *argv);

#endif