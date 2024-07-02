/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:17:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 13:52:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	eval_cd(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_cstring	path;

	(void)envp;
	path = NULL;
	if (argc > 2)
	{
		cstring_to_stderr("cd: too many arguments\n");
		return (1);
	}
	else if (argc == 1)
	{
		path = expansion_getenv(mini, "HOME");
		printf("HOME: %s\n", path);
		if (path == NULL)
		{
			write(1, "cd: HOME not set", 16);
			return (1);
		}
	}
	else
	{
		path = cstring_copy(mini, argv[1]);
	}
	if (chdir(path) != 0)
	{
		cstring_to_stderr("cd: ");
		cstring_to_stderr(strerror(errno));
		cstring_to_stderr("\n");
		free(path);
		return (1);
	}
	return (0);
}
