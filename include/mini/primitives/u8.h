/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u8.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:43:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:31:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U8_H
# define U8_H

# include "minishell.h"

typedef unsigned char	t_u8;

typedef char				*t_cstring;
typedef char				**t_cstring_array;

typedef struct s_mini		*t_mini;

typedef struct s_string		*t_string;
struct						s_string;


t_cstring	u8_to_cstring(t_mini mini, t_u8 value);

#endif