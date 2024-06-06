/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expansion_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:26:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:27:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_expansion_create(t_mini mini)
{
	mini->expansion = mini_alloc(mini, sizeof(struct s_expansion_process));
	mini->expansion->tokens = NULL;
}
