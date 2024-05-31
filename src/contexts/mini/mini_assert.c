/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_assert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:48:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_assert(t_mini mini, t_bool condition, t_cstring message)
{
	if (condition == FALSE)
	{
		cstring_to_stderr(message);
		mini_quit(mini);
	}
}
