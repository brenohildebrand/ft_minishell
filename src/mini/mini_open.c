/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:19:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/24 11:22:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	mini_open(t_mini mini, const char *pathname, int flags, mode_t mode)
{
	t_i32	fd;

	fd = open(pathname, flags, mode);
	// fdtree_insert();
	mini_assert(mini, fd != -1, MINI_ERROR);
	return (fd);
}
