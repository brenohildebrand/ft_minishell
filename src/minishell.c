/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:24:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/12 15:00:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <readline/readline.h>

int	main(void)
{
	t_cstring	command_line;

	while (42)
	{
		command_line = readline(PROMPT);
		free(command_line);
	}
	return (0);
}
