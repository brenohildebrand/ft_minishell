/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:33:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 19:52:25 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include "minishell.h"

typedef struct s_eval_process	*t_eval_process;
typedef t_eval_process			t_eval;

struct							s_eval_process
{
	t_cstring_array				env;
	t_mini_list					tokens;
};

t_none							mini_eval_create(t_mini mini);

t_i32							mini_eval_cd(t_mini mini, t_i32 argc,
									t_i8 **argv);
t_i32							mini_eval_env(t_mini mini, t_i32 argc,
									t_i8 **argv);
t_i32							mini_eval_echo(t_mini mini, t_i8 **argv);
t_i32							mini_eval_export(t_mini mini, t_i32 argc,
									t_i8 **argv);
t_i32							key_val(t_cstring argv);
t_i32							add_env_variable(t_i8 ***env,
									t_cstring variable_w_value);
t_i32							find_env_var_index(t_i8 **env,
									t_cstring var_name);
t_i32							mini_eval_exit(t_mini mini, t_i32 argc,
									t_i8 **argv);
t_i32							mini_eval_pwd(t_mini mini, t_i32 argc,
									t_i8 **argv);
t_i32							mini_eval_unset(t_mini mini, t_i32 argc,
									t_i8 **argv);
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