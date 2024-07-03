/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/03 12:07:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{	
	ft_load_str("hello memstack!\n");
	ft_putstr_fd(ft_unload_str(), STDOUT_FILENO);
	return (0);	
}