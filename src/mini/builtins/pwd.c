/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:24:24 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/14 19:43:18 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	mini_eval_pwd(t_mini mini, t_i32 argc, t_i8 **argv)
{
	t_i8 buffer[100];

	(void)mini;
	(void)argc;
	(void)argv;
	if (getcwd(buffer, 100))
	{
		ft_putstr(buffer);
		ft_putstr("\n");
		return (SUCCESS);
	}
	else
		return (FAILURE);
}
