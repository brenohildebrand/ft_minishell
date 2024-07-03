/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:37:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/03 11:09:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define FT_MALLOC_ERROR 1

// memtree

typedef struct s_memtree	t_memtree;

typedef struct s_fdtree		t_fdtree;

struct s_memtree {
	t_memtree	*ltree;
	t_memtree	*rtree;
	void		*address;
	int			height;
};

struct s_fdtree {
	t_fdtree	*ltree;
	t_fdtree	*rtree;
	int			fd;
	int			height;
};

// fdtree

// memstack

// errors

// string

struct s_string {
	char	*buffer;
	int		length;
	ssize_t	size;
};

// linked list

// table (of anything)

// agents

// ft_manager();

/* libft.c */
void ft_putstr_fd(char *s, int fd);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
t_memtree **_ft_memtree(void);
int _ft_memtree_get_height(t_memtree *memtree);
void _ft_memtree_update_height(t_memtree *memtree);
void _ft_memtree_left_rotate(t_memtree **memtree);
void _ft_memtree_right_rotate(t_memtree **memtree);
void _ft_memtree_rebalance_left(t_memtree **memtree);
void _ft_memtree_rebalance_right(t_memtree **memtree);
void _ft_memtree_rebalance(t_memtree **memtree);
t_memtree *_ft_memtree_create(void *address);
void _ft_memtree_insert_recursively(t_memtree **memtree, void *address);
void _ft_memtree_insert(void *ptr);
void *_ft_memtree_remove_min(t_memtree **memtree);
void _ft_memtree_remove_current(t_memtree **memtree, void *address);
void _ft_memtree_remove_recursively(t_memtree **memtree, void *address);
void _ft_memtree_remove(void *ptr);
void _ft_memtree_destroy_recursively(t_memtree *memtree);
void _ft_memtree_destroy(void);
void *ft_malloc(ssize_t size);
void *ft_calloc(size_t nmemb, size_t size);
void ft_free(void *ptr);
void ft_exit(int status);

#endif