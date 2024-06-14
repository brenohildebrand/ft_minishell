/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:45:12 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/14 19:14:13 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	ft_strlen(t_cstring str)
{
	t_i32	len;

	while (str[len])
		len++;
	return (len);
}

t_none	ft_putstr(t_cstring str)
{
	t_i32	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

t_cstring	ft_strchr(t_cstring s, t_i32 c)
{
	t_u8	to_found;

	to_found = (t_u8)c;
	while (*s && *s != to_found)
		s++;
	if (*s == to_found)
		return ((t_cstring)s);
	else
		return (0);
}

t_cstring	ft_strnstr(const t_cstring big, const t_cstring little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*little == '\0')
		return ((t_cstring)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && i + j < len)
			{
				if (little[j + 1] == '\0')
					return ((t_cstring)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
