/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/04 12:26:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{	
	t_table	*table;
	char	*str;

	table = ft_tblnew();
	// for (int i = 0; i < 100; i++)
	// {
	// 	char *key = ft_itoa(i);
	// 	char *value = ft_strdup("value");
	// 	ft_tblset(table, key, value);
	// }
	// for (int i = 0; i < 100; i++)
	// {
	// 	char *key = ft_itoa(i);
	// 	char *value = ft_tblget(table, key);
	// 	printf("key: %s, value: %s\n", key, value);
	// 	free(key);
	// 	free(value);
	// }
	ft_tblset(table, "key1", "value1");
	str = ft_strdup("key1");
	ft_tblset(table, str, "value2");
	ft_free(str);
	printf("key1: %s\n", (char *)ft_tblget(table, "key1"));
	ft_tbldel(table);
	return (0);	
}
