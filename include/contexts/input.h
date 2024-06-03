/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:35:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 14:51:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "contexts/mini.h"

typedef struct s_input_context	*t_input_context;
typedef t_input_context			t_input;

struct s_input_context {
	t_cstring	line;
	t_cstring	prompt;
	t_bool		is_complete;
};

t_none	input_create(t_mini mini);
t_none	input_get_prompt(t_mini mini);

#endif