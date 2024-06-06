/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:19:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	memstack_create(t_mini mini)
{
	mini->memstack = mini_alloc(mini, sizeof(struct s_memory_stack));
	mini->memstack->bottom = mini_alloc(mini, MEMORY_STACK_SIZE);
	mini->memstack->top = mini->memstack->bottom;
}
