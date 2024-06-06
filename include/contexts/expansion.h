/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:31:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/05 16:33:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "contexts/mini.h"

typedef struct s_expansion_context	*t_expansion_context;
typedef t_expansion_context			t_expansion;

struct s_expansion_context {
	t_mini_list	tokens;
};

t_none	expansion_create(t_mini mini);

#endif