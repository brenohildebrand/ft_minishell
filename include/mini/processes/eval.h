/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:33:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/15 00:05:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include "minishell.h"

typedef struct s_eval_process	*t_eval_process;
typedef t_eval_process			t_eval;

struct							s_eval_process
{
	t_cstring_array	env;
	t_mini_list		tokens;
};

t_none	mini_eval_create(t_mini mini);
t_none	mini_eval_reset(t_mini mini);

t_none	mini_eval_pipe(t_mini mini);
// t_none	mini_eval_update_path(t_mini mini);
// t_none	mini_eval_create_pipes(t_mini mini);
// t_none	mini_eval_commands(t_mini mini);
// t_none	mini_eval_command(t_mini mini, t_i32 index);
// t_none	mini_eval_close_pipes(t_mini mini);

t_i32	mini_eval_cd(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	mini_eval_env(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	mini_eval_echo(t_mini mini, t_i8 **argv);
t_i32	mini_eval_export(t_mini mini, t_i32 argc,t_i8 **argv);
t_i32	key_val(t_cstring argv);
t_i32	add_env_variable(t_i8 ***env, t_cstring variable_w_value);
t_i32	find_env_var_index(t_i8 **env, t_cstring var_name);
t_i32	mini_eval_exit(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	mini_eval_pwd(t_mini mini, t_i32 argc, t_i8 **argv);
t_i32	mini_eval_unset(t_mini mini, t_i32 argc, t_i8 **argv);

// open and close fd's based on redir
// while redirs
//   if found > 
// 	  if out_fd != 0
//      close(out_fd)
//    out_fd = open(filepath)
//  else if found >>
//    if out_fd != 0
//      close(out_fd)
//    out_fd = open(filepath) 
//  else if found <
//     if in_fd != 0
//       close(in_fd);
//    in_fd = open(filepath)
//    should_ignore_heredoc = TRUE;
//  else if found << 
//    if !should_ignore_heredoc
//      if in_fd:
//        close(in_fd)
//    in_fd = open(filepath) 
// find command based on path
// for each path in paths
//   if (access(path + filename, F_OK) == 0)
//     command = TRUE
// if command
//	fork()
//	if (pid == 0)
//    if (in_fd)
//      mini_assert(mini, dup2(in_fd, STDIN_FILENO) != -1)
//    if (out_fd)
//      mini_assert(mini, dup2(out_fd, STDOUT_FILENO) != -1)
//   close(in_fd)
//   close(out_fd)
//   setup argv
//   setup envp
//   mini_assert(mini, execve(argv[0], argv, envp) != -1, EXECVE_ERROR)
// close(in_fd)
// close(out_fd)
// 

#endif