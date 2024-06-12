/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:16:51 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/12 19:03:37 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32   mini_eval_env(t_mini mini, t_i32 argc, t_i8 **argv)
{
    t_i32   i;

    (void) argv;
    (void) argc;
    i = 0;
    while ((mini)->eval->env[i])
    {
        ft_putstr((mini)->eval->env[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
