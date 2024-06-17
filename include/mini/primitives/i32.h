/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:44:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:57:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I32_H
# define I32_H


typedef struct s_mini	*t_mini;
typedef char			*t_cstring;

typedef int				t_i32;
typedef int				*t_i32_array;

t_cstring	mini_i32_to_cstring(t_mini mini, t_i32 number);

#endif