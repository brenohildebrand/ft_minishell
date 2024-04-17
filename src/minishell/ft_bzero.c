/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:58:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/15 19:02:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *memory_address, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)(memory_address))[i] = (unsigned char)0;
		i++;
	}
}
