/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:05:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:15:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

typedef struct s_shared_context	*t_shared_context;
typedef t_shared_context		t_shared;

struct s_shared_context {
	t_memtree	memtree;
	t_memstack	memstack;
	t_u8		exit_code;
	t_bool		is_statement_complete;
};

t_none	mini_shared_create(t_mini mini);

#endif