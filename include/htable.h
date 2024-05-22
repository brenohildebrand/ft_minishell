/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/22 11:20:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTABLE_H
# define HTABLE_H

# include "minishell.h"

typedef struct s_htable			*t_htable;
typedef struct s_htable_entry	*t_htable_entry;

struct s_htable {
	t_htable_entry	*entries;
};

struct s_htable_entry {
	t_cstring	key;
	t_any		value;
};

#endif