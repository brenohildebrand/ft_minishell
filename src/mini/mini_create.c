/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:12:18 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	mini_create(void)
{
	t_mini	mini;

	mini = malloc(sizeof(struct s_mini_context));
	mini_assert(mini, mini != NULL, MEMORY_ALLOCATION_ERROR);
	mini_shared_create(mini);
	mini_reader_create(mini);
	mini_lexer_create(mini);
	mini_expansion_create(mini);
	mini_parser_create(mini);
	mini_eval_create(mini);
	return (mini);
}
