/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:30:13 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:31:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval_create(t_mini mini)
{
	mini->eval = mini_alloc(mini, sizeof(struct s_eval_process));
	mini->eval->tree = NULL;
}
