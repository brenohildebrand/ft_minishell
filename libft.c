/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:37:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/03 11:16:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0 || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = (unsigned char)c;
		index++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

t_fdtree	**_ft_fdtree(void)
{
	static t_fdtree	*root = NULL;
	
	return (&root);
}

int	_ft_fdtree_get_height(t_fdtree *fdtree)
{
	if (fdtree == NULL)
	{
		return (0);
	}
	else
	{
		return (fdtree->height);
	}
}

void	_ft_fdtree_update_height(t_fdtree *fdtree)
{
	int	lheight;
	int	rheight;

	lheight = _ft_fdtree_get_height(fdtree->ltree);
	rheight = _ft_fdtree_get_height(fdtree->rtree);
	if (lheight > rheight)
	{
		fdtree->height = 1 + lheight;
	}
	else
	{
		fdtree->height = 1 + rheight;
	}
}

void	_ft_fdtree_left_rotate(t_fdtree **fdtree)
{
	t_fdtree	*y;
	t_fdtree	*x;
	t_fdtree	*b;

	y = *fdtree;
	x = y->rtree;
	b = x->ltree;
	y->rtree = b;
	x->ltree = y;
	*fdtree = x;
	_ft_fdtree_update_height((*fdtree)->ltree);
	_ft_fdtree_update_height(*fdtree);
}

void	_ft_fdtree_right_rotate(t_fdtree **fdtree)
{
	t_fdtree	*y;
	t_fdtree	*x;
	t_fdtree	*b;

	y = *fdtree;
	x = y->ltree;
	b = x->rtree;
	y->ltree = b;
	x->rtree = y;
	*fdtree = x;
	_ft_fdtree_update_height((*fdtree)->rtree);
	_ft_fdtree_update_height(*fdtree);
}

void	_ft_fdtree_rebalance_left(t_fdtree **fdtree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = _ft_fdtree_get_height((*fdtree)->ltree->ltree);
	rgrandheight = _ft_fdtree_get_height((*fdtree)->ltree->rtree);
	if (lgrandheight >= rgrandheight)
	{
		_ft_fdtree_right_rotate(fdtree);
	}
	else
	{
		_ft_fdtree_left_rotate(&((*fdtree)->ltree));
		_ft_fdtree_right_rotate(fdtree);
	}
}

void	_ft_fdtree_rebalance_right(t_fdtree **fdtree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = _ft_fdtree_get_height((*fdtree)->rtree->ltree);
	rgrandheight = _ft_fdtree_get_height((*fdtree)->rtree->rtree);
	if (rgrandheight >= lgrandheight)
	{
		_ft_fdtree_left_rotate(fdtree);
	}
	else
	{
		_ft_fdtree_right_rotate(&((*fdtree)->rtree));
		_ft_fdtree_left_rotate(fdtree);
	}
}

void	_ft_fdtree_rebalance(t_fdtree **fdtree)
{
	int	lheight;
	int	rheight;

	if (*fdtree == NULL)
		return ;
	lheight = _ft_fdtree_get_height((*fdtree)->ltree);
	rheight = _ft_fdtree_get_height((*fdtree)->rtree);
	if (lheight - rheight > 1)
	{
		_ft_fdtree_rebalance_left(fdtree);
	}
	else if (rheight - lheight > 1)
	{
		_ft_fdtree_rebalance_right(fdtree);
	}
	_ft_fdtree_update_height(*fdtree);
}

t_fdtree	*_ft_fdtree_create(int fd)
{
	t_fdtree	*fdtree;

	fdtree = malloc(sizeof(t_fdtree));
	if (fdtree == NULL)
	{
		ft_putstr_fd("ft: error: malloc failed\n", STDERR_FILENO);
		ft_exit(1);
	}
	fdtree->fd = fd;
	fdtree->ltree = NULL;
	fdtree->rtree = NULL;
	fdtree->height = 1;
	return (fdtree);
}

void	_ft_fdtree_insert_recursively(t_fdtree **fdtree, int fd)
{
	if (*fdtree == NULL)
	{
		*fdtree = _ft_fdtree_create(fd);
	}
	else if (fd < (*fdtree)->fd)
	{
		_ft_fdtree_insert_recursively(&((*fdtree)->ltree), fd);
		_ft_fdtree_rebalance(fdtree);
	}
	else if (fd > (*fdtree)->fd)
	{
		_ft_fdtree_insert_recursively(&((*fdtree)->rtree), fd);
		_ft_fdtree_rebalance(fdtree);
	}
}

void	_ft_fdtree_insert(int fd)
{
	t_fdtree	**fdtree;

	fdtree = _ft_fdtree();
	_ft_fdtree_insert_recursively(fdtree, fd);
}

int	_ft_fdtree_remove_min(t_fdtree **fdtree)
{
	t_fdtree	*min_root;
	int			min_fd;

	if ((*fdtree)->ltree == NULL)
	{
		min_root = *fdtree;
		min_fd = min_root->fd;
		*fdtree = min_root->rtree;
		free(min_root);
	}
	else
	{
		min_fd = _ft_fdtree_remove_min(&((*fdtree)->ltree));
	}
	_ft_fdtree_rebalance(fdtree);
	return (min_fd);
}

void	_ft_fdtree_remove_current(t_fdtree **fdtree, int fd)
{
	t_fdtree	*old_root;

	if ((*fdtree)->rtree != NULL)
	{
		(*fdtree)->fd = _ft_fdtree_remove_min(&((*fdtree)->rtree));
		close(fd);
	}
	else
	{
		old_root = *fdtree;
		*fdtree = (*fdtree)->ltree;
		close(old_root->fd);
		free(old_root);
	}
}

void	_ft_fdtree_remove_recursively(t_fdtree **fdtree, int fd)
{
	if ((*fdtree) == NULL)
	{
		return ;
	}
	else if (fd == (*fdtree)->fd)
	{
		_ft_fdtree_remove_current(fdtree, fd);
	}
	else if (fd < (*fdtree)->fd)
	{
		_ft_fdtree_remove_recursively(&((*fdtree)->ltree), fd);
	}
	else if (fd > (*fdtree)->fd)
	{
		_ft_fdtree_remove_recursively(&((*fdtree)->rtree), fd);
	}
	_ft_fdtree_rebalance(fdtree);
}

void	_ft_fdtree_remove(int fd)
{
	t_fdtree	**fdtree;

	fdtree = _ft_fdtree();
	_ft_fdtree_remove_recursively(fdtree, fd);
}

void	_ft_fdtree_destroy_recursively(t_fdtree *fdtree)
{
	if (fdtree == NULL)
			return ;
	_ft_fdtree_destroy_recursively(fdtree->ltree);
	_ft_fdtree_destroy_recursively(fdtree->rtree);
	close(fdtree->fd);
	free(fdtree);
}

void	_ft_fdtree_destroy(void)
{
	t_fdtree	**fdtree;

	fdtree = _ft_fdtree();
	_ft_fdtree_destroy_recursively(*fdtree);
}

t_memtree	**_ft_memtree(void)
{
	static t_memtree	*root = NULL;
	
	return (&root);
}

int	_ft_memtree_get_height(t_memtree *memtree)
{
	if (memtree == NULL)
	{
		return (0);
	}
	else
	{
		return (memtree->height);
	}
}

void	_ft_memtree_update_height(t_memtree *memtree)
{
	int	lheight;
	int	rheight;

	lheight = _ft_memtree_get_height(memtree->ltree);
	rheight = _ft_memtree_get_height(memtree->rtree);
	if (lheight > rheight)
	{
		memtree->height = 1 + lheight;
	}
	else
	{
		memtree->height = 1 + rheight;
	}
}

void	_ft_memtree_left_rotate(t_memtree **memtree)
{
	t_memtree	*y;
	t_memtree	*x;
	t_memtree	*b;

	y = *memtree;
	x = y->rtree;
	b = x->ltree;
	y->rtree = b;
	x->ltree = y;
	*memtree = x;
	_ft_memtree_update_height((*memtree)->ltree);
	_ft_memtree_update_height(*memtree);
}

void	_ft_memtree_right_rotate(t_memtree **memtree)
{
	t_memtree	*y;
	t_memtree	*x;
	t_memtree	*b;

	y = *memtree;
	x = y->ltree;
	b = x->rtree;
	y->ltree = b;
	x->rtree = y;
	*memtree = x;
	_ft_memtree_update_height((*memtree)->rtree);
	_ft_memtree_update_height(*memtree);
}

void	_ft_memtree_rebalance_left(t_memtree **memtree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = _ft_memtree_get_height((*memtree)->ltree->ltree);
	rgrandheight = _ft_memtree_get_height((*memtree)->ltree->rtree);
	if (lgrandheight >= rgrandheight)
	{
		_ft_memtree_right_rotate(memtree);
	}
	else
	{
		_ft_memtree_left_rotate(&((*memtree)->ltree));
		_ft_memtree_right_rotate(memtree);
	}
}

void	_ft_memtree_rebalance_right(t_memtree **memtree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = _ft_memtree_get_height((*memtree)->rtree->ltree);
	rgrandheight = _ft_memtree_get_height((*memtree)->rtree->rtree);
	if (rgrandheight >= lgrandheight)
	{
		_ft_memtree_left_rotate(memtree);
	}
	else
	{
		_ft_memtree_right_rotate(&((*memtree)->rtree));
		_ft_memtree_left_rotate(memtree);
	}
}

void	_ft_memtree_rebalance(t_memtree **memtree)
{
	int	lheight;
	int	rheight;

	if (*memtree == NULL)
		return ;
	lheight = _ft_memtree_get_height((*memtree)->ltree);
	rheight = _ft_memtree_get_height((*memtree)->rtree);
	if (lheight - rheight > 1)
	{
		_ft_memtree_rebalance_left(memtree);
	}
	else if (rheight - lheight > 1)
	{
		_ft_memtree_rebalance_right(memtree);
	}
	_ft_memtree_update_height(*memtree);
}

t_memtree	*_ft_memtree_create(void *address)
{
	t_memtree	*memtree;

	memtree = malloc(sizeof(t_memtree));
	if (memtree == NULL)
	{
		ft_putstr_fd("ft: error: malloc failed\n", STDERR_FILENO);
		ft_exit(1);
	}
	memtree->address = address;
	memtree->ltree = NULL;
	memtree->rtree = NULL;
	memtree->height = 1;
	return (memtree);
}

void	_ft_memtree_insert_recursively(t_memtree **memtree, void *address)
{
	if (*memtree == NULL)
	{
		*memtree = _ft_memtree_create(address);
	}
	else if (address < (*memtree)->address)
	{
		_ft_memtree_insert_recursively(&((*memtree)->ltree), address);
		_ft_memtree_rebalance(memtree);
	}
	else if (address > (*memtree)->address)
	{
		_ft_memtree_insert_recursively(&((*memtree)->rtree), address);
		_ft_memtree_rebalance(memtree);
	}
}

void	_ft_memtree_insert(void *ptr)
{
	t_memtree	**memtree;

	memtree = _ft_memtree();
	_ft_memtree_insert_recursively(memtree, ptr);
}

void	*_ft_memtree_remove_min(t_memtree **memtree)
{
	t_memtree	*min_root;
	void		*min_address;

	if ((*memtree)->ltree == NULL)
	{
		min_root = *memtree;
		min_address = min_root->address;
		*memtree = min_root->rtree;
		free(min_root);
	}
	else
	{
		min_address = _ft_memtree_remove_min(&((*memtree)->ltree));
	}
	_ft_memtree_rebalance(memtree);
	return (min_address);
}

void	_ft_memtree_remove_current(t_memtree **memtree, void *address)
{
	t_memtree	*old_root;

	if ((*memtree)->rtree != NULL)
	{
		(*memtree)->address = _ft_memtree_remove_min(&((*memtree)->rtree));
		free(address);
	}
	else
	{
		old_root = *memtree;
		*memtree = (*memtree)->ltree;
		free(old_root->address);
		free(old_root);
	}
}

void	_ft_memtree_remove_recursively(t_memtree **memtree, void *address)
{
	if ((*memtree) == NULL)
	{
		return ;
	}
	else if (address == (*memtree)->address)
	{
		_ft_memtree_remove_current(memtree, address);
	}
	else if (address < (*memtree)->address)
	{
		_ft_memtree_remove_recursively(&((*memtree)->ltree), address);
	}
	else if (address > (*memtree)->address)
	{
		_ft_memtree_remove_recursively(&((*memtree)->rtree), address);
	}
	_ft_memtree_rebalance(memtree);
}

void	_ft_memtree_remove(void *ptr)
{
	t_memtree	**memtree;

	memtree = _ft_memtree();
	_ft_memtree_remove_recursively(memtree, ptr);
}

void	_ft_memtree_destroy_recursively(t_memtree *memtree)
{
	if (memtree == NULL)
			return ;
	_ft_memtree_destroy_recursively(memtree->ltree);
	_ft_memtree_destroy_recursively(memtree->rtree);
	free(memtree->address);
	free(memtree);
}

void	_ft_memtree_destroy(void)
{
	t_memtree	**memtree;

	memtree = _ft_memtree();
	_ft_memtree_destroy_recursively(*memtree);
}

void	*ft_malloc(ssize_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putstr_fd("ft: error: ft_malloc failed\n", STDERR_FILENO);
		ft_exit(FT_MALLOC_ERROR);
	}
	_ft_memtree_insert(ptr);
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total = nmemb * size;
	if (total > 2147483647 || (total / nmemb) != size)
	{
		return (NULL);
	}
	else
	{
		ptr = malloc(nmemb * size);
		if (ptr == NULL)
		{
			ft_putstr_fd("ft: error: ft_calloc failed\n", STDERR_FILENO);
			ft_exit(FT_MALLOC_ERROR);
		}
		ft_bzero(ptr, nmemb * size);
		_ft_memtree_insert(ptr);
		return (ptr);
	}
}

void	ft_free(void *ptr)
{
	_ft_memtree_remove(ptr);
}

void	ft_exit(int status)
{
	_ft_memtree_destroy();
	exit(status % 256);
}
