/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:38:17 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 22:58:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	eval_builtin(
	t_mini mini,
	t_cstring name,
	t_i8 **argv,
	t_i8 **envp
){
	t_i32	exit_code;
	t_i32	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (cstring_compare(name, "cd") == 0)
		return ;	
	else if (cstring_compare(name, "echo") == 0)
		exit_code = eval_echo(mini, argc, argv, envp);
	else if (cstring_compare(name, "env") == 0)
		return ;
	else if (cstring_compare(name, "exit") == 0)
		return ;
	else if (cstring_compare(name, "export") == 0)
		return ;
	else if (cstring_compare(name, "pwd") == 0)
		return ;
	else if (cstring_compare(name, "unset") == 0)
		return ;
	else
		return ;
	mini->shared->exit_code = exit_code;
}
