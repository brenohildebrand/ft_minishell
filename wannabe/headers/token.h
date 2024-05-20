/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:42:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:07:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "types.h"

typedef struct s_token	*t_token;

struct s_token {
	t_i32		type;
	t_cstring	value;
};

t_token	new_token(t_minishell mini, t_i32 type, t_cstring value);
void	destroy_token(t_minishell mini, t_token token);

#endif