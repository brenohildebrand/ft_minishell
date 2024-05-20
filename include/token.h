/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:29:23 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 20:29:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN

# include "minishell.h"

typedef struct s_token	*t_token;

struct s_token {
	t_cstring	token;
	t_u32		length;
	t_i32		type;	
};

#endif