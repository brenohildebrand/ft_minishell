/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:24:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:56:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "contexts/mini.h"

typedef struct s_config_context	*t_config_context;
typedef t_config_context		*t_config;

struct s_config_context {
	t_cstring	prompt;
};

t_none	config_new(t_mini mini);
t_none	config_init(t_mini mini);

#endif