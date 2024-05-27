/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:23:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 14:34:35 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// setup signals and stuff
t_none	mini_setup(t_mini mini)
{
	mini_load_config(mini);
}
