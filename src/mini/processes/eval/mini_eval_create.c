/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_eval_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:30:13 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 20:54:22 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_eval_create(t_mini mini)
{
	mini->eval = mini_alloc(mini, sizeof(struct s_eval_process));
	// mini->eval->whatever = 0;
}
