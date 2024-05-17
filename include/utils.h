/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:58:18 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 22:08:58 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"
# include <stdlib.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_cstring	get_subcstring(
	t_minishell mini, 
	t_cstring line, 
	t_i32 start, 
	t_i32 length
);

char		*mini_substr(char const *s, unsigned int start, size_t len);

#endif