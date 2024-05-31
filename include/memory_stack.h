/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:04:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:49:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_STACK_H
# define MEMORY_STACK_H

# include "contexts/mini.h"

# define MEMORY_STACK_SIZE		1024

typedef struct s_memory_stack	*t_memory_stack;
typedef t_memory_stack			t_memstack;

struct s_memory_stack {
	t_u8	*top;
	t_u8	*bottom;
};

t_none	memstack_create(t_mini mini);
t_none	memstack_destroy(t_mini mini);
t_none	memstack_load(t_mini mini, t_u8 value);
t_none	memstack_load_u8(t_mini mini, t_u8 value);
t_none	memstack_load_i8(t_mini mini, t_i8 value);
t_none	memstack_load_u32(t_mini mini, t_u32 value);
t_none	memstack_load_i32(t_mini mini, t_i32 value);
t_none	memstack_load_u64(t_mini mini, t_u64 value);
t_none	memstack_load_i64(t_mini mini, t_i64 value);
t_none	memstack_load_any(t_mini mini, t_any value);
t_u8	memstack_unload_u8(t_mini mini);
t_i8	memstack_unload_i8(t_mini mini);
t_u32	memstack_unload_u32(t_mini mini);
t_i32	memstack_unload_i32(t_mini mini);
t_u64	memstack_unload_u64(t_mini mini);
t_i64	memstack_unload_i64(t_mini mini);
t_any	memstack_unload_any(t_mini mini);

#endif