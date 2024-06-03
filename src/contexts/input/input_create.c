/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:22:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 14:51:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	input_create(t_mini mini)
{
	mini->input = mini_alloc(mini, sizeof(struct s_input_context));
	mini->input->line = NULL;
	mini->input->prompt = NULL;
	mini->input->is_complete = FALSE;
}
