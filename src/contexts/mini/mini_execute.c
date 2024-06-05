/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:50:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 21:25:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_execute(t_mini mini)
{
	(void)mini;
	mini->input->is_complete = FALSE;
	// for each node in the tree call the children and executes itself
	// execute itself it should know if it's going to execute each children or
	// whatever
}
