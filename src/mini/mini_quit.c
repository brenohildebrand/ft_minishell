/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:01:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:32:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_quit(t_mini mini, t_u8 code)
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
			memtree_destroy(mini->shared->memtree);
			free(mini->shared);
			free(mini);
			exit(code);
		}
	}
}
