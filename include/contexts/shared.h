/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:54:11 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/05 18:37:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "contexts/mini.h"

typedef struct s_shared_context	*t_shared_context;
typedef t_shared_context		t_shared;

struct s_shared_context {
	t_memtree	memtree;
	t_memstack	memstack;
	t_bool		is_statement_complete;
	t_i32		exit_status;
};

#endif