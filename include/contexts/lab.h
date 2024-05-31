/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:36:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:14:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAB_H
# define LAB_H

# include "contexts/mini.h"

typedef struct s_lab_context	*t_lab_context;
typedef t_lab_context			t_lab;

struct s_lab_context {
	t_memstack	memstack;
};

t_none	lab_create(t_mini mini);
t_none	lab_destroy(t_mini mini);

#endif