/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/03 11:07:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define N 100

int	main(void)
{
	// test ft_malloc and ft_free
	
	void	*ptr[N];
	
	for (int i = 0; i < N; i++)
	{
		ptr[i] = ft_malloc(i % 100);
	}
	for (int i = 0; i < N; i++)
	{
		ft_free(ptr[i]);
	}
	return (0);
}