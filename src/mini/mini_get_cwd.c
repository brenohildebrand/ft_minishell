/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_get_cwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:55:08 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 23:11:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	mini_get_cwd(t_mini mini)
{
	t_cstring	cwd;
	t_u32		cwd_size;

	cwd_size = 1024;
	cwd = mini_alloc(mini, cwd_size);
	while (getcwd(cwd, cwd_size) == NULL)
	{
		cwd_size *= 2;
		mini_free(mini, cwd);
		cwd = mini_alloc(mini, cwd_size);
	}
	return (getcwd(cwd, cwd_size));
}
