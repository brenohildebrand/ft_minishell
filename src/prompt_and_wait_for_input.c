/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_and_wait_for_input.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:02:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 16:17:51 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void	prompt_and_wait_for_input(t_minishell_state minishell_state)
{
	minishell_state->command_line = readline(PROMPT);
	if (minishell_state->command_line == NULL)
	{
		destroy_minishell_state(minishell_state);
		exit(0);
	}
	if (minishell_state->command_line[0] != '\0')
	{
		add_history(minishell_state->command_line);
	}
}
