/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_array_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:33:32 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 22:57:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	*cstring_array_copy(t_mini mini, t_cstring *arr)
{
	t_i32		len;
	t_cstring	*copy;

	len = 0;
	while (arr[len])
		len++;
	copy = mini_alloc(mini, (sizeof(t_cstring) * (len + 1)));
	copy[len] = '\0';
	while (len--)
	{
		copy[len] = cstring_copy(mini, arr[len]);
	}
	return (copy);
}
