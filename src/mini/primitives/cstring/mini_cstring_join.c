/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cstring_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:09:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/15 19:34:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cstring	mini_cstring_join(t_mini mini, t_cstring a, t_cstring b)
{
	const t_u32	a_length = cstring_get_length(a);
	const t_u32	b_length = cstring_get_length(b);
	const t_u32	c_length = a_length + b_length;
	t_cstring	c;
	t_u32		i;

	c = mini_alloc(mini, c_length + 1);
	i = 0;
	while (i < a_length)
	{
		c[i] = a[i];
		i++;
	}
	i = 0;
	while (i < b_length)
	{
		c[a_length + i] = b[i];
		i++;
	}
	c[c_length] = '\0';
	return (c);
}
