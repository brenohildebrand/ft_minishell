/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:33:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:04:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include "minishell.h"

typedef struct s_eval_process	*t_eval_process;
typedef t_eval_process			t_eval;

struct s_eval_process
{
	t_mini_list		tokens;
	t_cstring_array	paths;
	t_i32_array		pipes;
	t_i32			redirs[2];
};

t_none	eval_create(t_mini mini);
t_none	eval_reset(t_mini mini);

t_none	eval_pipe(t_mini mini);
t_none	eval_update_path(t_mini mini);
t_none	eval_create_pipes(t_mini mini);
t_none	eval_commands(t_mini mini);
t_none	eval_command(t_mini mini, t_i32 index);
t_none	eval_close_pipes(t_mini mini);
t_none	eval_close_redirs(t_mini mini);
t_none	eval_words(t_mini mini, t_mini_cmd_tree command, t_i32 i);
t_none	eval_redirs(t_mini mini, t_mini_cmd_tree command, t_i32 i);
t_none	eval_update_exit_code(t_mini mini, t_i32 status);

t_i32	eval_echo(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp);

t_i32	eval_cd(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	eval_env(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	eval_export(t_mini mini, t_i32 argc,t_i8 **argv);
t_i32	key_val(t_cstring argv);
t_i32	add_env_variable(t_i8 ***env, t_cstring variable_w_value);
t_i32	find_env_var_index(t_i8 **env, t_cstring var_name);
t_i32	eval_exit(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	eval_pwd(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	eval_unset(t_mini mini, t_i32 argc, t_i8 **argv);
t_none	eval_executable(
			t_mini mini,
			t_cstring path,
			t_cstring_array argv,
			t_cstring_array envp);
t_none	eval_builtin(
			t_mini mini,
			t_cstring name,
			t_i8 **argv,
			t_i8 **envp);
t_bool	eval_is_builtin(t_mini mini, t_cstring name);

#endif