/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:45:12 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/06/12 18:25:47 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_i32	ft_strlen(t_cstring str)
{
	t_i32	len;

	while (str[len])
		len++;
	return (len);
}

t_cstring	ft_strdup(const t_cstring str)
{
	t_i32		str_size;
	t_i32		i;
	t_cstring	dup;

	i = 0;
	str_size = ft_strlen(str);
	dup = malloc(sizeof(t_cstring) * (str_size + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

t_none	ft_putstr(t_cstring str)
{
	t_i32	len;
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}