/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:02:36 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 16:06:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H

# include "types.h"

typedef struct s_iterator	*t_iterator;

struct s_iterator {
	t_any	reference;
	void	(*advance)(t_any);
	void	(*retreat)(t_any);
	void	(*get_value)(t_any);
};

#endif