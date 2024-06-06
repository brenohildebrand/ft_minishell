/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:32:41 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 15:10:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_free(t_mini mini, t_mem mem)
{
	if (mem == NULL)
		return ;
	memtree_remove(&(mini->memtree), mem);
}
