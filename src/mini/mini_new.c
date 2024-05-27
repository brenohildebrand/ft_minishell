/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 10:01:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	mini_new(void)
{
	t_mini	mini;

	mini = malloc(sizeof(struct s_mini));
	if (mini == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed.\n", 27);
		exit(1);
	}
	mini->mini_context = mini_context_new();
	mini->lexer_context = lexer_context_new(mini);
	return (mini);
}
