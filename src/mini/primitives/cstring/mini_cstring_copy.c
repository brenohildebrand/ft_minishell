/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cstring_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:05:43 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:07:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	mini_cstring_copy(t_mini mini, t_cstring original)
{
	const t_u32	original_length = cstring_get_length(original);
	t_u32		i;
	t_cstring	copy;

	copy = mini_alloc(mini, original_length + 1);
	i = 0;
	while (i < original_length)
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
