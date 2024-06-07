/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:19:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:22:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	memstack_create(t_mini mini)
{
	mini->shared->memstack = mini_alloc(mini, sizeof(struct s_memstack));
	mini->shared->memstack->bottom = mini_alloc(mini, MEMSTACK_SIZE);
	mini->shared->memstack->top = mini->shared->memstack->bottom;
}
