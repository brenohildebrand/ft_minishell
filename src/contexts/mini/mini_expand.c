/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:57:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 16:14:49 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_expand(t_mini mini)
{
	(void)mini;
	// for each token
	// expand if it starts with $
	// or if it starts with " and contains a $inside
	// $? is the exit status

	// env variables, $? or empty
}
