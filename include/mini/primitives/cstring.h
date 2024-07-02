/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:17:36 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 19:58:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTRING_H
# define CSTRING_H

# include "minishell.h"

typedef char				*t_cstring;
typedef char				**t_cstring_array;

typedef struct s_mini		*t_mini;

typedef struct s_string		*t_string;
struct						s_string;

t_none		cstring_to_stderr(t_cstring message);
t_none		cstring_to_stdout(t_cstring message);
t_i32		cstring_get_length(t_cstring message);
t_bool		cstring_is_not_empty(t_cstring cstring);
t_i32		cstring_compare(t_cstring a, t_cstring b);
t_cstring	cstring_copy(t_mini mini, t_cstring original);
t_cstring	cstring_dirname(t_mini mini, t_cstring path);
t_cstring	cstring_join(t_mini mini, t_cstring a, t_cstring b);
t_cstring	cstring_get_subcstring(
				t_mini mini,
				t_cstring cstring,
				t_i32 start,
				t_i32 end);
t_cstring	cstring_remove(
				t_mini mini,
				t_cstring cstring,
				t_i32 start,
				t_i32 end);
t_cstring	cstring_add(
				t_mini mini,
				t_cstring cstring,
				t_i32 start,
				t_cstring value);
t_cstring	*cstring_split(t_mini mini, t_cstring s, t_i8 c);
t_cstring	*cstring_array_copy(t_mini mini, t_cstring *arr);

#endif