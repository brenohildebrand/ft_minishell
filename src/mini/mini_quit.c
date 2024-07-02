/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:01:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 15:49:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_quit(t_mini mini, t_i32 code)
{
	if (mini == NULL)
	{
		exit(code);
	}
	else
	{
		if (mini->shared == NULL)
		{
			free(mini);
			exit(code);
		}
		else
		{
			memstack_destroy(mini);
			fdtree_destroy(mini);
			memtree_destroy(mini);
			free(mini->shared);
			free(mini);
			exit(code);
		}
	}
}
