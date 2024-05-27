/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_context_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:52:00 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 09:58:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_context	mini_context_new(void)
{
	t_mini_context	mini_context;

	mini_context = malloc(sizeof(struct s_mini_context));
	if (mini_context == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed.\n", 27);
		exit(1);
	}
	mini_context->memtree = NULL;
	mini_context->line = NULL;
	mini_context->bitmask = 0;
	return (mini_context);
}
