/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:33:59 by bhildebr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/10 22:33:05 by bhildebr         ###   ########.fr       */
=======
/*   Updated: 2024/06/10 18:16:07 by eduardocoel      ###   ########.fr       */
>>>>>>> b6d6eb2 (just send this to see if i using the primitives the rightway)
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include "minishell.h"

typedef struct s_eval_process	*t_eval_process;
typedef t_eval_process			t_eval;

struct							s_eval_process
{
	t_cstring_array					env;
};

t_none							mini_eval_create(t_mini mini);

t_i32   mini_eval_cd(t_mini mini, t_i32 argc, t_cstring_array argv);
// t_i32	mini_eval_echo(t_mini mini, t_i32 argc, t_i8 **argv);
// t_i32	mini_eval_export(t_mini mini, t_i32 argc, t_i8 **argv);
// ...

// t_none	mini_eval_pipe_sequence(t_mini mini, t_mini_tree node);
// t_none	mini_eval_command_sequence(t_mini mini, t_mini_tree node);
// t_none	mini_eval_redir_sequence(t_mini mini, t_mini_tree node);

// or

// t_i32	mini_eval_pipe_sequence(t_mini mini, t_mini_tree node);
// t_i32	mini_eval_command_sequence(t_mini mini, t_mini_tree node);
// t_i32	mini_eval_redir_sequence(t_mini mini, t_mini_tree node);

// or whatever

#endif