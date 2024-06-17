/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:31:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:58:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "minishell.h"

typedef struct s_expansion_process	*t_expansion_process;
typedef t_expansion_process			t_expansion;

struct s_expansion_process {
	t_mini_list	tokens;
};

t_none		mini_expansion_create(t_mini mini);
t_none		mini_expansion_reset(t_mini mini);

t_none		mini_expansion_expand_word(t_mini mini, t_mini_list node);
t_none		mini_expansion_expand_dquotes(t_mini mini, t_mini_list node);
t_i32		mini_expansion_expand(
				t_mini mini,
				t_mini_list node,
				t_i32 start,
				t_i32 end);
t_cstring	mini_expansion_getenv(t_mini mini, t_cstring key);

#endif