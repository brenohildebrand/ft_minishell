/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_dirname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:25:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 14:33:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	cstring_dirname(t_mini mini, t_cstring path)
{
	const t_u32	path_length = cstring_get_length(path); 
	t_cstring	dirname;
	t_u32		dirname_length;
	t_u32		counter;

	counter = 0;
	while (path_length >= counter && path[path_length - counter] != '/')
		counter++;
	dirname_length = path_length - counter;
	if (dirname_length > 0)
	{
		dirname = mini_alloc(mini, dirname_length);
		dirname[dirname_length] = '\0';
		while (dirname_length--)
			dirname[dirname_length] = path[dirname_length];
	}
	else
	{
		dirname = NULL;
	}
	return (dirname);
}
