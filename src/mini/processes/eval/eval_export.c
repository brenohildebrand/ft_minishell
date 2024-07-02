/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:26:28 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 00:49:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	eval_export(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_i32	i;

	i = 0;
	if (argc == 1)
	{
		eval_env(mini, argc, argv, envp);		
	}
	else
	{
		while (argv[i])
		{
			if (key_val(argv[i]) == 1)
			{
				ft_putstr("export: ");
				ft_putstr(argv[i]);
				ft_putstr(" not a valid identifier\n");
				return (1);
			}
			add_env_variable(&(mini)->shared->env, argv[i]);
			i++;
		}
	}
	return (0);
}
