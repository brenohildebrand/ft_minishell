/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_assert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:48:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/05 23:57:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_assert(t_mini mini, t_bool condition, t_u8 code)
{
	if (condition == FALSE)
	{
		write(STDERR_FILENO, "Error.\n", 8);		
		mini_quit(mini, code);
	}
}
