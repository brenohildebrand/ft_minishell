/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:06:43 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:31:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "minishell.h"

typedef void		*t_memory;
typedef t_memory	t_mem;

t_none	mem_copy_from_to(t_mem from, t_mem to, t_i32 size);
t_none	mem_set(t_mem mem, t_u8 value, t_i32 size);
t_mem	mem_sub(t_mini mini, t_mem mem, t_i32 start, t_i32 end);

#endif