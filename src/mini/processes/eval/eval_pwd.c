/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:18:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 23:06:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	eval_pwd(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_i8	*cwd;
	
	(void)argc;
	(void)argv;
	(void)envp;
	cwd = mini_get_cwd(mini);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
