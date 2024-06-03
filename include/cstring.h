/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:17:36 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/31 21:29:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTRING_H
# define CSTRING_H

# include "contexts/mini.h"

typedef char					*t_cstring;
typedef char					**t_cstring_array;

typedef struct s_mini_context	*t_mini_context;
struct							s_mini_context;
typedef t_mini_context			t_mini;

typedef struct s_string			*t_string;
struct							s_string;

t_none		cstring_to_stderr(t_cstring message);
t_i32		cstring_get_length(t_cstring message);
t_cstring	cstring_copy(t_mini mini, t_cstring original);
t_cstring	cstring_join(t_mini mini, t_cstring a, t_cstring b);
t_none		cstring_to_stdout(t_cstring message);
t_bool		cstring_is_not_empty(t_cstring cstring);
t_cstring	cstring_dirname(t_mini mini, t_cstring path);
t_string	cstring_to_string(t_mini mini, t_cstring cstring);

#endif