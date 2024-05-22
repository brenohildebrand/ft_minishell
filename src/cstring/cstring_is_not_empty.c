/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_is_not_empty.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:38:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/21 17:42:08 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	cstring_is_not_empty(t_cstring cstring)
{
	if (cstring == NULL || cstring[0] == '\0')
	{
		return (FALSE);
	}
	return (TRUE);
}
