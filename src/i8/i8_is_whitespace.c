/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i8_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:37:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 19:38:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_bool	i8_is_whitespace(t_i8 character)
{
	return (character == ' ' || (character >= '\t' && character <= '\r'));
}
