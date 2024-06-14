/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:32:26 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/14 18:12:10 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_builtin(t_mini mini)
{
	if (!ft_strcmp(mini->eval->tokens->token, "cd")
		|| !ft_strcmp(mini->eval->tokens->token, "echo")
		|| !ft_strcmp(mini->eval->tokens->token, "env")
		|| !ft_strcmp(mini->eval->tokens->token, "exit")
		|| !ft_strcmp(mini->eval->tokens->token, "export")
		|| !ft_strcmp(mini->eval->tokens->token, "pwd")
		|| !ft_strcmp(mini->eval->tokens->token, "unset"))
		return (TRUE);
	return (FALSE);
}

t_i32	mini_execute_builtin(t_mini mini, t_i32 argc, t_i8 **argv)
{
	if (!ft_strcmp(mini->eval->tokens->token, "cd"))
		return (mini_eval_cd(mini, argc, argv));
	if (!ft_strcmp(mini->eval->tokens->token, "echo"))
		return (mini_eval_echo(mini, argv));
	if (!ft_strcmp(mini->eval->tokens->token, "env"))
		return (mini_eval_env(mini, argc, argv));
	if (!ft_strcmp(mini->eval->tokens->token, "exit"))
		return (mini_eval_exit(mini, argc, argv));
	if (!ft_strcmp(mini->eval->tokens->token, "export"))
		return (mini_eval_export(mini, argc, argv));
	if (!ft_strcmp(mini->eval->tokens->token, "pwd"))
		return (mini_eval_pwd(mini, argc, argv));
	if (!ft_strcmp(mini->eval->tokens->token, "unset"))
		return (mini_eval_unset(mini, argc, argv));
	return (write(2, "Error with builtins", 24));
}
