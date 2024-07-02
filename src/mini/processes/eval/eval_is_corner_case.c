/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_is_corner_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:47:57 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 17:49:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	eval_is_corner_case(t_cstring name)
{
	if (cstring_compare(name, "cd") == 0)
	{
		return (TRUE);
	}
	else if (cstring_compare(name, "export") == 0)
	{
		return (TRUE);
	}
	else if (cstring_compare(name, "unset") == 0)
	{
		return (TRUE);
	}
	else if (cstring_compare(name, "exit") == 0)
	{
		return (TRUE);
	}
	return (FALSE);
}
