/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/13 03:10:26 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// pure functions

// perfect function
int	sum(int a, int b)
{
	return (a + b);
}

// read user byte
int	read_byte(void)
{
	unsigned char	byte;
	
	read(0, &byte, 1);
	return (byte);
}

int	main(void)
{	
	unsigned char	byte;

	byte = read_byte();
	printf("%u\n", byte);
	return (0);	
}