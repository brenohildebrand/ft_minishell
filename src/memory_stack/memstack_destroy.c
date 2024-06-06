/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:26:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	memstack_destroy(t_mini mini)
{
	mini_free(mini, mini->memstack->bottom);
	mini->memstack->bottom = NULL;
	mini->memstack->top = NULL;
	mini_free(mini, mini->memstack);
	mini->memstack = NULL;
}
