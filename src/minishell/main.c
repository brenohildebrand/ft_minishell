/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:27:02 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 12:31:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_minishell_state	minishell_state;

	minishell_state = create_minishell_state();
	// while (42)
	// {
	// 	prompt_and_wait_for_input(minishell_state);
	// }
	// see if it works then test minishell_allocate and minishell_deallocate
	minishell_deallocate(minishell_state, minishell_allocate(minishell_state, 120));
	destroy_minishell_state(minishell_state);
	return (0);
}
