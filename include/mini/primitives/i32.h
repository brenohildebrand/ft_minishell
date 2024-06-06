/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:44:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 21:04:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I32_H
# define I32_H

typedef char					*t_cstring;
typedef int						t_i32;
typedef struct s_mini_context	*t_mini_context;
struct 							s_mini_context;
typedef t_mini_context			t_mini;

t_cstring	i32_to_cstring(t_mini mini, t_i32 number);

#endif