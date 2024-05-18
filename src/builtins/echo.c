/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:26:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/17 11:19:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "utils.h"

// static t_i32	check_n_flag(t_cstring str)
// {
// 	if (*str == '-' && *(str + 1) == 'n')
// 	{
// 		str++;
// 		while (*str == 'n')
// 			str++;
// 		if (*str == '\0')
// 			return (1);
// 	}
// 	return (0);
// }

// static void	print_args(t_cstring *args, t_i32 has_n_flag)
// {
// 	while (*args)
// 	{
// 		ft_putstr_fd(*args, STDOUT_FILENO);
// 		if (*(args + 1))
// 			ft_putchar_fd(' ', STDOUT_FILENO);
// 		args++;
// 	}
// 	if (!has_n_flag)
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// }

// t_i32	execute_echo(t_token cmd)
// {
// 	t_cstring	*args;
// 	t_i32		has_n_flag;

// 	has_n_flag = 0;
// 	args = get_cmd_and_args(cmd);
// 	args++;
// 	while (*args && check_n_flag(*args))
// 	{
// 		has_n_flag = 1;
// 		args++;	
// 	}
// 	print_args(args, has_n_flag);
// 	return (SUCCESS);
// }
