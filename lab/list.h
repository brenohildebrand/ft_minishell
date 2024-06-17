/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:49:03 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:50:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list			*t_list;
typedef struct s_list_shared	*t_list_shared;

typedef struct s_type			*t_type;

typedef t_u64					t_size;

struct s_list {	
	t_any			content;
	t_size			size;
	t_size			length;
	t_size			dimension;
	t_type			*types;
	t_list_shared	shared;
	t_bool			is_homogeneous;
	t_bool			is_heterogeneous;
};

struct s_list_shared {
	t_type	type;
	t_none	(*destroy)(t_list);
	t_none	(*append)(t_list, t_any);
	t_none	(*push)(t_list, t_any);
};

struct s_type {
	t_string	name;
	t_size		size;
	t_none		(*destroy)(t_any);
};

t_list	list_create(t_u64 dimension);
t_none	list_destroy(t_list list);

t_none	list_append(t_list self, t_any content);
t_none	list_push(t_list self, t_any content);

t_any	i32(t_i32 new_value)
{
	static t_i32	value = 0;

	value = new_value;
	return (&value);
}

int main()
{
	t_list	my_list = list_create(sizeof(t_i32));

	list_append(my_list, number(42)); // right
	list_append(my_list, number_create(42)); // wrong
	// always copy never change data outside the scope of the
	// function itself
	my_list->shared->append(my_list, i32(42));
}

#endif