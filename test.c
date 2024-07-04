/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/04 16:00:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{	
	t_table	*table;
	char	*str;

	table = ft_tblnew();
	ft_tblset(table, "key1", "hello table");
	str = ft_strdup("key1");
	printf("key1: %s\n", (char *)ft_tblget(table, str));
	ft_tbldel(table);
	return (0);	
}
