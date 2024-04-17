/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minishell_state.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:23:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/14 11:07:58 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell_state	create_minishell_state(void)
{
	t_minishell_state	minishell_state;

	minishell_state = allocate_minishell_state();
	initialize_minishell_state(minishell_state);
	return (minishell_state);
}
