/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 12:54:45 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include "contexts/mini.h"

typedef struct s_hash_table			*t_hash_table;
typedef struct s_hash_table_entry	*t_hash_table_entry;
typedef t_hash_table				t_htable;
typedef t_hash_table_entry			t_htable_entry;

struct s_hash_table {
	t_hash_table_entry	*entries;
};

struct s_hash_table_entry {
	t_cstring	key;
	t_any		value;
};

#endif