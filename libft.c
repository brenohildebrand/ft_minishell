/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:37:12 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/13 00:17:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(int *src)
{
	int	*dest;

	dest = ft_calloc(1, sizeof(int));
	*dest = *src;
	return (dest);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = ft_calloc(n + 1, sizeof(char));
	i = 0;
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (fd < 0)
	{
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s == 0 || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (unsigned char)c)
			return ((char *)(s + index));
		index++;
	}
	if (s[index] == (unsigned char)c)
		return ((char *)(s + index));
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		index;
	char	*ptr;

	ptr = ft_malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ptr == ((void *)0))
		return (0);
	index = 0;
	while (s[index])
	{
		ptr[index] = s[index];
		index++;
	}
	ptr[index] = 0;
	return (ptr);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dest == (void *)0 && src == (void *)0)
		return ((void *)0);
	while (index < n)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)ft_malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_len;

	if (dst == 0 && src == 0)
		return (0);
	index = 0;
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + ft_strlen(src));
	while (src[index] && index < (size - dst_len - 1))
	{
		dst[index + dst_len] = src[index];
		index++;
	}
	dst[index + dst_len] = 0;
	return (dst_len + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size > 0)
	{
		index = 0;
		while (index < size - 1 && src[index])
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	while (index < n)
	{
		if ((unsigned char)(s1[index]) != (unsigned char)(s2[index]))
		{
			if ((unsigned char)(s1[index]) > (unsigned char)(s2[index]))
				return (1);
			else
				return (-1);
		}
		else
		{
			if ((unsigned char)(s1[index]) == 0 && \
				(unsigned char)(s2[index]) == 0)
				return (0);
			index++;
		}
	}
	return (0);
}

char	*ft_strpbrk(char *s, char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				return (&s[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	little_index;

	if (little[0] == '\0')
		return ((char *)big);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	big_index = 0;
	little_index = 0;
	while (big_index < len)
	{
		if (big[big_index + little_index] == little[little_index])
		{
			while (big_index + little_index < len && little[little_index] != 0 \
					&& big[big_index + little_index] == little[little_index])
				little_index++;
			if (little[little_index] == 0)
				return ((char *)&big[big_index]);
			else
				little_index = 0;
		}
		big_index++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (unsigned char)(c))
			return ((char *)(s + index));
		index--;
	}
	return ((void *)0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)ft_malloc((len + 1) * sizeof(char));
	if (substr == ((void *)0))
		return ((void *)0);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_len = ft_strlen(s1);
	while ((s_len - 1) && ft_strchr(set, s1[s_len - 1]))
		s_len--;
	return (ft_substr(s1, 0, s_len));
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r'))
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

char	*_ft_itoa_get_digits(int n, int number_of_characters)
{
	int		i;
	char	*s;
	int		number_of_digits;

	s = ft_calloc(number_of_characters + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	s[number_of_characters] = '\0';
	if (n >= 0)
		number_of_digits = number_of_characters;
	else
	{
		s[0] = '-';
		n *= -1;
		number_of_digits = number_of_characters - 1;
	}
	i = 0;
	while (i < number_of_digits)
	{
		s[number_of_characters - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	return (s);
}

int	_ft_itoa_get_number_of_characters(int n)
{
	int	number_of_characters;

	number_of_characters = 1;
	if (n < 0)
	{
		number_of_characters++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		number_of_characters++;
	}
	return (number_of_characters);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		number_of_characters;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number_of_characters = _ft_itoa_get_number_of_characters(n);
	s = _ft_itoa_get_digits(n, number_of_characters);
	return (s);
}

static char	*_ft_itoa_base_handle_zero(char *base)
{
	char	*string;

	string = ft_calloc(1 + 1, sizeof(char));
	if (string == NULL)
		return (NULL);
	string[0] = base[0];
	string[1] = '\0';
	return (string);
}

static size_t	_ft_itoa_base_get_string_len(int value, char *base)
{
	long long int	llvalue;
	size_t			base_len;
	size_t			string_len;

	base_len = ft_strlen(base);
	string_len = 0;
	llvalue = value;
	while (llvalue > 0)
	{
		llvalue /= base_len;
		string_len++;
	}
	return (string_len);
}

char	*ft_itoa_base(int value, char *base)
{
	long long int	llvalue;
	char			*string;
	size_t			string_len;
	size_t			base_len;

	if (value == 0)
		return (_ft_itoa_base_handle_zero(base));
	base_len = ft_strlen(base);
	string_len = _ft_itoa_base_get_string_len(value, base);
	string = ft_calloc(string_len + 1, sizeof(char));
	if (string == NULL)
		return (NULL);
	string[string_len] = '\0';
	llvalue = value; 
	while (string_len--)
	{
		string[string_len] = base[llvalue % base_len];
		llvalue /= base_len;
	}
	return (string);
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	signal;
	int	nb;

	index = 0;
	while (ft_isspace(nptr[index]))
		index++;
	signal = 1;
	if (nptr[index] == '-')
		signal = -1;
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	nb = 0;
	while (ft_isdigit(nptr[index]))
	{
		nb *= 10;
		nb += nptr[index] - '0';
		index++;
	}
	return (nb * signal);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*src;
	size_t			character;

	index = 0;
	src = (unsigned char *)(s);
	character = (unsigned char)(c);
	while (index < n)
	{
		if (src[index] == character)
			return (&src[index]);
		index++;
	}
	return ((void *)0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	index = 0;
	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	while (index < n)
	{
		if (str1[index] != str2[index])
		{
			return ((int)(str1[index] - str2[index]));
		}
		index++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (dest == ((void *)0) && src == ((void *)0))
		return ((void *)0);
	index = 0;
	if (dest < src)
	{
		while (index < n)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	else
	{
		while (n--)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
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

int	_ft_split_get_number_of_words(char const *s, char c)
{
	int	i;
	int	number_of_words;

	i = 0;
	number_of_words = 0;
	while (1)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		number_of_words++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == '\0')
			break ;
	}
	return (number_of_words);
}

void	_ft_split_get_words_logic(char const *s, char c, char ***words)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	index_of_current_word;

	i = 0;
	index_of_current_word = 0;
	while (1)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i - 1;
		(*words)[index_of_current_word] = ft_substr(s, start, end - start + 1);
		index_of_current_word = index_of_current_word + 1;
		if (s[i] == '\0')
			break ;
	}
	(*words)[index_of_current_word] = 0;
}

char	**_ft_split_get_words(char const *s, char c, int number_of_words)
{
	char	**words;

	words = ft_calloc(number_of_words + 1, sizeof(char *));
	if (words == 0)
		return (0);
	_ft_split_get_words_logic(s, c, &words);
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		number_of_words;

	number_of_words = _ft_split_get_number_of_words(s, c);
	words = _ft_split_get_words(s, c, number_of_words);
	return (words);
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

t_memstack	*_ft_memstack(void)
{
	static t_memstack	memstack = {
		.top = memstack.buffer,
	};
		
	return (&memstack);
}

void	ft_load_unsigned_char(unsigned char c)
{
	t_memstack	*memstack;

	memstack = _ft_memstack();
	if (memstack->top + sizeof(unsigned char) > \
		memstack->buffer + FT_MEMSTACK_SIZE)
	{
		ft_putstr_fd("ft: error: ft_memstack overflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_OVERFLOW_ERROR);
	}
	memstack->top[0] = c;
	memstack->top += sizeof(unsigned char);
}

void	ft_load_char(char c)
{
	t_memstack	*memstack;

	memstack = _ft_memstack();
	if (memstack->top + sizeof(char) > \
		memstack->buffer + FT_MEMSTACK_SIZE)
	{
		ft_putstr_fd("ft: error: ft_memstack overflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_OVERFLOW_ERROR);
	}
	((char *)(memstack->top))[0] = c;
	memstack->top += sizeof(char);
}

void	ft_load_str(char *str)
{
	ft_load_ptr(str);
}

void	ft_load_int(int i)
{
	t_memstack	*memstack;

	memstack = _ft_memstack();
	if (memstack->top + sizeof(int) > \
		memstack->buffer + FT_MEMSTACK_SIZE)
	{
		ft_putstr_fd("ft: error: ft_memstack overflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_OVERFLOW_ERROR);
	}
	((int *)(memstack->top))[0] = i;
	memstack->top += sizeof(int);
}

void	ft_load_ptr(void *ptr)
{
	t_memstack	*memstack;

	memstack = _ft_memstack();
	if (memstack->top + sizeof(void *) > \
		memstack->buffer + FT_MEMSTACK_SIZE)
	{
		ft_putstr_fd("ft: error: ft_memstack overflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_OVERFLOW_ERROR);
	}
	((void **)(memstack->top))[0] = ptr;
	memstack->top += sizeof(void *);
}

unsigned char	ft_unload_unsigned_char(void)
{
	t_memstack		*memstack;
	unsigned char	c;

	memstack = _ft_memstack();
	if (memstack->top - sizeof(unsigned char) < memstack->buffer)
	{
		ft_putstr_fd("ft: error: ft_memstack underflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_UNDERFLOW_ERROR);
	}
	memstack->top -= sizeof(unsigned char);
	c = memstack->top[0];
	return (c);
}

char	ft_unload_char(void)
{
	t_memstack	*memstack;
	char		c;

	memstack = _ft_memstack();
	if (memstack->top - sizeof(char) < memstack->buffer)
	{
		ft_putstr_fd("ft: error: ft_memstack underflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_UNDERFLOW_ERROR);
	}
	memstack->top -= sizeof(char);
	c = ((char *)(memstack->top))[0];
	return (c);
}

char	*ft_unload_str(void)
{
	return ((char *)(ft_unload_ptr()));
}

int	ft_unload_int(void)
{
	t_memstack	*memstack;
	int			i;

	memstack = _ft_memstack();
	if (memstack->top - sizeof(int) < memstack->buffer)
	{
		ft_putstr_fd("ft: error: ft_memstack underflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_UNDERFLOW_ERROR);
	}
	memstack->top -= sizeof(int);
	i = ((int *)(memstack->top))[0];
	return (i);
}

void	*ft_unload_ptr(void)
{
	t_memstack	*memstack;
	void		*ptr;

	memstack = _ft_memstack();
	if (memstack->top - sizeof(void *) < memstack->buffer)
	{
		ft_putstr_fd("ft: error: ft_memstack underflow\n", STDERR_FILENO);
		ft_exit(FT_MEMSTACK_UNDERFLOW_ERROR);
	}
	memstack->top -= sizeof(void *);
	ptr = ((void **)(memstack->top))[0];
	return (ptr);
}

int	ft_open(const char *pathname, int flags, mode_t mode)
{
	int	fd;

	fd = open(pathname, flags, mode);
	if (fd == -1)
	{
		ft_putstr_fd("ft: error: ft_open failed\n", STDERR_FILENO);
		ft_exit(1);
	}
	_ft_fdtree_insert(fd);
	return (fd);
}

void	ft_close(int fd)
{
	_ft_fdtree_remove(fd);
}

int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("ft: error: ft_fork failed\n", STDERR_FILENO);
		ft_exit(1);
	}
	return (pid);
}

int	ft_pipe(int pipefd[2])
{
	int	ret;

	ret = pipe(pipefd);
	if (ret == -1)
	{
		ft_putstr_fd("ft: error: ft_pipe failed\n", STDERR_FILENO);
		ft_exit(1);
	}
	return (ret);
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
		ptr = ft_malloc(nmemb * size);
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_node;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		new_node = ft_lstlast(*lst);
		new_node->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			del((*lst)->content);
			 ft_free(*lst);
			*lst = temp;
		}
		*lst = 0;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	ft_free(lst);
}

void	ft_lstdel(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*new_lst;

	new_lst = lst;
	if (new_lst == NULL)
	{
		return (NULL);
	}
	while (new_lst->next)
	{
		new_lst = new_lst->next;
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*element;

	new_lst = NULL;
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst)
	{
		element = ft_lstnew((*f)(lst->content));
		if (!element)
		{
			if (new_lst == NULL)
			{
				return (NULL);
			}
			ft_lstclear(&element, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, element);
		lst = lst->next;
	}
	return (new_lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_ls;

	new_ls = ft_malloc(1 * sizeof(t_list));
	if (!new_ls)
	{
		return (NULL);
	}
	new_ls->content = content;
	new_ls->next = NULL;
	return (new_ls);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_table	*ft_tblnew(void)
{
	t_table	*table;

	table = ft_malloc(sizeof(t_table));
	table->size = 16;
	table->entries = ft_calloc(sizeof(t_table_entry), table->size);
	table->length = 0;
}

unsigned int	_ft_tblhash(char *key)
{
	unsigned int	hash;
	int				i;

	hash = 5381;
	i = 0;
	while (key[i])
	{
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return (hash);
}

void	_ft_tblgrow(t_table *table)
{
	t_table	*new_table;
	int		i;

	new_table = ft_malloc(sizeof(t_table));
	new_table->size = table->size * 2;
	new_table->entries = ft_calloc(sizeof(t_table_entry), new_table->size);
	new_table->length = 0;
	i = 0;
	while (i < table->size)
	{
		if (table->entries[i].key != NULL)
			ft_tblset(new_table, \
					  table->entries[i].key, \
					  table->entries[i].value);
		i++;
	}
	ft_free(table->entries);
	table->entries = new_table->entries;
	table->size = new_table->size;
	ft_free(new_table);
}

void	_ft_tblshrink(t_table *table)
{
	t_table	*new_table;
	int		i;

	new_table = ft_malloc(sizeof(t_table));
	new_table->size = table->size / 2;
	new_table->entries = ft_calloc(sizeof(t_table_entry), new_table->size);
	new_table->length = 0;
	i = 0;
	while (i < table->size)
	{
		if (table->entries[i].key != NULL)
			ft_tblset(new_table, \
					  table->entries[i].key, \
					  table->entries[i].value);
		i++;
	}
	ft_free(table->entries);
	table->entries = new_table->entries;
	table->size = new_table->size;
	ft_free(new_table);
}

char	*ft_strrep(char *str, char *substr, int start, int end)
{
	char	*new_str;
	int		new_len;
	int		i;
	int		j;

	new_len = ft_strlen(str) - (end - start) + ft_strlen(substr);
	new_str = ft_calloc(new_len + 1, sizeof(char));
	i = 0;
	while (i < start)
	{
		new_str[i] = str[i];
		i++;
	}
	j = 0;
	while (substr[j])
		new_str[i++] = substr[j++];
	j = end;
	while (str[j])
		new_str[i++] = str[j++];
	return (new_str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	_ft_tblset_new_entry(t_table *table, int hash, char *key, void *value)
{
	table->entries[hash].key = ft_strdup(key);
	table->entries[hash].value = value;
	table->length++;
	if (table->length >= table->size / 2)
		_ft_tblgrow(table);
}

void	_ft_tblset_existing_entry(t_table *table, int hash, char *key, void *value)
{
	table->entries[hash].value = value;
	if (value == NULL)
	{
		ft_free(table->entries[hash].key);
		table->entries[hash].key = NULL;
		table->length--;
		if (table->length <= table->size / 4)
			_ft_tblshrink(table);
	}
}

void	ft_tblset(t_table *table, char *key, void *value)
{
	unsigned int	hash;

	hash = _ft_tblhash(key) % table->size;
	while (42)
	{
		if (table->entries[hash].key == NULL)
			break ;
		if (ft_strcmp(table->entries[hash].key, key) == 0)
			break ;
		hash = (hash + 1) % table->size;
	}
	if (table->entries[hash].key == NULL)
		_ft_tblset_new_entry(table, hash, key, value);
	else if (ft_strcmp(table->entries[hash].key, key) == 0)
		_ft_tblset_existing_entry(table, hash, key, value);	
}

void	*ft_tblget(t_table *table, char *key)
{
	unsigned int	hash;

	hash = _ft_tblhash(key) % table->size;
	while (ft_strcmp(table->entries[hash].key, key) != 0)
		hash = (hash + 1) % table->size;
	return (table->entries[hash].value);
}

void	ft_tbldelone(t_table *tbl, char *key, void (*del)(void *))
{
	unsigned int	hash;

	hash = _ft_tblhash(key) % tbl->size;
	while (ft_strcmp(tbl->entries[hash].key, key) != 0)
		hash = (hash + 1) % tbl->size;
	ft_free(tbl->entries[hash].key);
	del(tbl->entries[hash].value);
	tbl->entries[hash].key = NULL;
	tbl->entries[hash].value = NULL;
	tbl->length--;
	if (tbl->length <= tbl->size / 4)
		_ft_tblshrink(tbl);
}

void	ft_tbldel(t_table *tbl, void (*del)(void *))
{
	int	i;

	i = 0;
	while (i < tbl->size)
	{
		if (tbl->entries[i].key != NULL)
		{
			ft_free(tbl->entries[i].key);
			del(tbl->entries[i].value);
		}
		i++;
	}
	ft_free(tbl->entries);
	ft_free(tbl);
}

void	ft_noop(void)
{
}