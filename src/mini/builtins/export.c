/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:05:19 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/30 22:55:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_i32	mini_eval_export(t_mini mini, t_i32 argc, t_i8 **argv)
// {
// 	t_i32	i;

// 	i = 0;
// 	if (!argv[1])
// 		mini_eval_env(mini, argc, argv);
// 	else
// 	{
// 		while (argv[i])
// 		{
// 			if (key_val(argv[i]) == 1)
// 			{
// 				ft_putstr("export: ");
// 				ft_putstr(argv[i]);
// 				ft_putstr(" not a valid identifier\n");
// 				return (1);
// 			}
// 			add_env_variable(&(mini)->shared->env, argv[i]);
// 			i++;
// 		}
// 	}
// 	return (0);
// }
