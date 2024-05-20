/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 15:13:19 by bhildebr         ###   ########.fr       */
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
	mini->memtree = NULL;
	return (mini);
}
