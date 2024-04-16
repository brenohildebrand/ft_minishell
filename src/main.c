/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:27:02 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 16:10:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_minishell_state	minishell_state;

	minishell_state = create_minishell_state();
	while (42)
	{
		prompt_and_wait_for_input(minishell_state);
	}
	destroy_minishell_state(minishell_state);
	return (0);
}
