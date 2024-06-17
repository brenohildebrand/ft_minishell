/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_update_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:42:56 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 21:54:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval_update_path(t_mini mini)
{
	t_i32		i;
	t_i32		j;
	t_i32		start;
	t_i32		end;
	t_cstring	path;
	
	i = 0;
	while (mini->shared->env[i])
	{
		j = 0;
		while (mini->shared->env[i][j] == "PATH="[j] && j < 5)
			j++;
		if (j == 5)
			break ;
		i++;
	}
	start = 5;
	end = start;
	while (mini->shared->env[i][end])
		end++;
	end -= 1;
	path = mini_cstring_get_subcstring(mini, mini->shared->env[i], start, end);
	mini->eval->paths = mini_cstring_split(mini, path, ':');
	mini_free(mini, path);
}
