/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:31:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:02:39 by bhildebr         ###   ########.fr       */
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

t_none		expansion_create(t_mini mini);
t_none		expansion_reset(t_mini mini);

t_none		expansion_expand_word(t_mini mini, t_mini_list node);
t_none		expansion_expand_dquotes(t_mini mini, t_mini_list node);
t_i32		expansion_expand(
				t_mini mini,
				t_mini_list node,
				t_i32 start,
				t_i32 end);
t_cstring	expansion_getenv(t_mini mini, t_cstring key);
t_none		expansion_remove_quotes(t_mini mini);

#endif