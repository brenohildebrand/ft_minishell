/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:16:51 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/17 13:54:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32   mini_eval_env(t_mini mini, t_i32 argc, t_i8 **argv)
{
    t_i32   i;

    (void) argv;
    (void) argc;
    i = 0;
    while ((mini)->shared->env[i])
    {
        ft_putstr((mini)->shared->env[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
