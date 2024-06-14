/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:55:05 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/13 21:27:12 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_i32	check_n(t_cstring argv)
{
	t_i32		i;
	t_cstring	flag_n;
	t_i32		nbr;

	nbr = 2;
	flag_n = "-n";
	i = 0;
	while ((argv[i] != '\0' || flag_n[i] != '\0') && nbr)
	{
		if (argv[i] != flag_n[i])
			return ((t_i8)argv[i] - (t_i8)flag_n[i]);
		nbr--;
		i++;
	}
	return (0);
}

t_i32	mini_eval_echo(t_mini mini, t_i8 **argv)
{
	int i;
	int n;

	(void)mini;
	i = 1;
	n = 0;
	if (argv[1] && check_n(argv))
	{
		n = 1;
		i++;
	}
	while (argv[i])
	{
		write(1, argv[i], 1);
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!n)
		write(1, "\n", 1);
	return (0);
}
