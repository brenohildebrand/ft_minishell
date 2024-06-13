/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils_lib_ft_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:51:08 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/13 18:04:56 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	ft_isdigit(t_i32 c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_i32	ft_isalnum(t_i32 c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_cstring	ft_substr(t_cstring s, t_u32 start, t_i32 len)
{
	t_i32		i;
	t_i32		j;
	t_cstring	subs;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (i < len && start < ft_strlen(s) && s[start + i])
		i++;
	subs = malloc((i + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (j < i && start < ft_strlen(s))
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[j] = '\0';
	return (subs);
}

t_cstring	ft_strdup(const t_cstring s)
{
	t_i32 len;
	t_i32 i = 0;
	t_cstring copy;

	len = ft_strlen(s) + 1;
	copy = malloc((t_u32)len);
	if (copy != NULL)
	{
		while (s[i])
		{
			copy[i] == s[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}