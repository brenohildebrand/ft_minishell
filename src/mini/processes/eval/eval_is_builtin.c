/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_is_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:39:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:25:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	eval_is_builtin(t_mini mini, t_cstring name)
{
	(void)mini;
	if (cstring_compare(name, "cd") == 0)
		return (TRUE);	
	else if (cstring_compare(name, "echo") == 0)
		return (TRUE);
	else if (cstring_compare(name, "env") == 0)
		return (TRUE);
	else if (cstring_compare(name, "exit") == 0)
		return (TRUE);
	else if (cstring_compare(name, "export") == 0)
		return (TRUE);
	else if (cstring_compare(name, "pwd") == 0)
		return (TRUE);
	else if (cstring_compare(name, "unset") == 0)
		return (TRUE);
	else
		return (FALSE);
}
