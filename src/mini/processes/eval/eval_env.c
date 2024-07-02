/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:25:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 01:31:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	eval_env(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_i32   i;

    (void)argv;
    (void)argc;
	(void)envp;
    i = 0;
    while ((mini)->shared->env[i])
    {
        printf("%s\n", mini->shared->env[i]);
        i++;
    }
    return (0);
}
