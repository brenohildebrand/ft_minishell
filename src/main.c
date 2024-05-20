/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 17:31:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	main(void)
{
	#ifdef DEBUG
		printf("\033[94mMinishell is running in DEBUG mode.\033[0m\n");
	#endif
	t_mini	mini;

	mini = mini_new();
	while (42)
	{
		mini_read(mini);
		mini_evaluate(mini);
		mini_print(mini);
	}
}
