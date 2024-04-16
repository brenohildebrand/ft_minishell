/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_minishell_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:12:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 16:18:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include <stdlib.h>

t_minishell_state	allocate_minishell_state(void)
{
	t_minishell_state	minishell_state;

	minishell_state = \
		(t_minishell_state)malloc(sizeof(struct s_minishell_state));
	if (minishell_state == NULL)
	{
		exit(1);
	}
	ft_bzero(minishell_state, sizeof(struct s_minishell_state));
	return (minishell_state);
}
