/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:37:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/04 18:12:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define FT_MALLOC_ERROR 1
# define FT_MEMSTACK_OVERFLOW_ERROR 2
# define FT_MEMSTACK_UNDERFLOW_ERROR 3

# define FT_MEMSTACK_SIZE 1024

typedef struct s_memtree	t_memtree;

typedef struct s_fdtree		t_fdtree;

typedef struct s_memstack	t_memstack;

typedef struct s_list		t_list;

typedef struct s_table			t_table;
typedef struct s_table_entry	t_table_entry;

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

struct s_memstack {
	unsigned char	buffer[FT_MEMSTACK_SIZE];
	unsigned char	*top;
};

struct s_list {
	void	*content;
	t_list	*next;
};

struct s_table {
	t_table_entry	*entries;
	int				length;
	int				size;
};

struct s_table_entry {
	void	*value;
	char	*key;
};

/* libft.c */
int *ft_intdup(int *src);
char *ft_strndup(const char *s, size_t n);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putendl_fd(char *s, int fd);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s);
void ft_striteri(char *s, void (*f)(unsigned int, char *));
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dst, const char *src, size_t size);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strrchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strtrim(char const *s1, char const *set);
int ft_tolower(int c);
int ft_toupper(int c);
void ft_putchar_fd(char c, int fd);
int ft_isprint(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_islower(int c);
int ft_isupper(int c);
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isspace(char c);
char *_ft_itoa_get_digits(int n, int number_of_characters);
int _ft_itoa_get_number_of_characters(int n);
char *ft_itoa(int n);
char *ft_itoa_base(int value, char *base);
int ft_atoi(const char *nptr);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
int _ft_split_get_number_of_words(char const *s, char c);
void _ft_split_get_words_logic(char const *s, char c, char ***words);
char **_ft_split_get_words(char const *s, char c, int number_of_words);
char **ft_split(char const *s, char c);
t_fdtree **_ft_fdtree(void);
int _ft_fdtree_get_height(t_fdtree *fdtree);
void _ft_fdtree_update_height(t_fdtree *fdtree);
void _ft_fdtree_left_rotate(t_fdtree **fdtree);
void _ft_fdtree_right_rotate(t_fdtree **fdtree);
void _ft_fdtree_rebalance_left(t_fdtree **fdtree);
void _ft_fdtree_rebalance_right(t_fdtree **fdtree);
void _ft_fdtree_rebalance(t_fdtree **fdtree);
t_fdtree *_ft_fdtree_create(int fd);
void _ft_fdtree_insert_recursively(t_fdtree **fdtree, int fd);
void _ft_fdtree_insert(int fd);
int _ft_fdtree_remove_min(t_fdtree **fdtree);
void _ft_fdtree_remove_current(t_fdtree **fdtree, int fd);
void _ft_fdtree_remove_recursively(t_fdtree **fdtree, int fd);
void _ft_fdtree_remove(int fd);
void _ft_fdtree_destroy_recursively(t_fdtree *fdtree);
void _ft_fdtree_destroy(void);
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
t_memstack *_ft_memstack(void);
void ft_load_unsigned_char(unsigned char c);
void ft_load_char(char c);
void ft_load_str(char *str);
void ft_load_int(int i);
void ft_load_ptr(void *ptr);
unsigned char ft_unload_unsigned_char(void);
char ft_unload_char(void);
char *ft_unload_str(void);
int ft_unload_int(void);
void *ft_unload_ptr(void);
void *ft_malloc(ssize_t size);
void *ft_calloc(size_t nmemb, size_t size);
void ft_free(void *ptr);
void ft_exit(int status);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list *ft_lstnew(void *content);
int ft_lstsize(t_list *lst);
t_table *ft_tblnew(void);
int _ft_tblhash(char *key);
void _ft_tblgrow(t_table *table);
void _ft_tblshrink(t_table *table);
int ft_strcmp(const char *s1, const char *s2);
void _ft_tblset_new_entry(t_table *table, int hash, char *key, void *value);
void _ft_tblset_existing_entry(t_table *table, int hash, char *key, void *value);
void ft_tblset(t_table *table, char *key, void *value);
void *ft_tblget(t_table *table, char *key);
void ft_tbldel(t_table *table);

#endif