/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:01:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 14:40:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_quit(t_mini mini)
{
	const t_i32	exit_status = mini->exit_status;

	memtree_destroy(mini->memtree);
	free(mini);
	exit(exit_status);
}
