/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 21:16:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	ft_strlen(t_cstring cstr)
{
	t_i32	len;

	len = 0;
	while (cstr[len] != '\0')
	{
		len++;
	}
	return (len);
}

t_mini	print_to_stderr(t_cstring cstr)
{
	write(STDERR_FILENO, cstr, ft_strlen(cstr));
}

t_bool	memtree_is_empty(t_memtree_ptr memtree_ptr)
{
	return ((*memtree_ptr == NULL));

}

t_any	memtree_get_address(t_memtree_ptr memtree_ptr)
{
	return ((*memtree_ptr)->address);
}

t_memtree	memtree_get_ltree(t_memtree_ptr memtree_ptr)
{
	return ((*memtree_ptr)->ltree);
}

t_memtree	memtree_get_rtree(t_memtree_ptr memtree_ptr)
{
	return ((*memtree_ptr)->rtree);
}

t_i32	memtree_get_height(t_memtree memtree)
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

t_none	memtree_update_height(t_memtree memtree)
{
	t_i32	lheight;
	t_i32	rheight;

	if (memtree == NULL)
		return ;
	lheight = memtree_get_height(memtree->ltree);
	rheight = memtree_get_height(memtree->rtree);
	if (lheight > rheight)
	{
		memtree->height = 1 + lheight;
	}
	else
	{
		memtree->height = 1 + rheight;
	}
}

t_none	memtree_right_rotate(t_memtree_ptr memtree_ptr)
{
	t_memtree	y;
	t_memtree	x;
	t_memtree	b;

	y = *memtree_ptr;
	x = y->ltree;
	b = x->rtree;
	y->ltree = b;
	x->rtree = y;
	*memtree_ptr = x;
	memtree_update_height((*memtree_ptr)->rtree);
	memtree_update_height(*memtree_ptr);
}

t_none	memtree_left_rotate(t_memtree_ptr memtree_ptr)
{
	t_memtree	y;
	t_memtree	x;
	t_memtree	b;

	y = *memtree_ptr;
	x = y->rtree;
	b = x->ltree;
	y->rtree = b;
	x->ltree = y;
	*memtree_ptr = x;
	memtree_update_height((*memtree_ptr)->ltree);
	memtree_update_height(*memtree_ptr);
}

t_none	memtree_rebalance_left(t_memtree_ptr memtree_ptr)
{
	t_i32	lgrandheight;
	t_i32	rgrandheight;

	lgrandheight = memtree_get_height((*memtree_ptr)->ltree->ltree);
	rgrandheight = memtree_get_height((*memtree_ptr)->ltree->rtree);
	if (lgrandheight >= rgrandheight)
	{
		memtree_right_rotate(memtree_ptr);
	}
	else
	{
		memtree_left_rotate(&(*memtree_ptr)->ltree);
		memtree_right_rotate(memtree_ptr);
	}
}

t_none	memtree_rebalance_right(t_memtree_ptr memtree_ptr)
{
	t_i32	lgrandheight;
	t_i32	rgrandheight;

	lgrandheight = memtree_get_height((*memtree_ptr)->rtree->ltree);
	rgrandheight = memtree_get_height((*memtree_ptr)->rtree->rtree);
	if (rgrandheight >= lgrandheight)
	{
		memtree_left_rotate(memtree_ptr);
	}
	else
	{
		memtree_right_rotate(&(*memtree_ptr)->rtree);
		memtree_left_rotate(memtree_ptr);
	}
}

t_none	memtree_rebalance(t_memtree_ptr memtree_ptr)
{
	t_i32	lheight;
	t_i32	rheight;

	if (memtree_is_empty(memtree_ptr))
		return ;
	lheight = memtree_get_height(memtree_get_ltree(memtree_ptr));
	rheight = memtree_get_height(memtree_get_rtree(memtree_ptr));
	if (lheight - rheight > 1)
	{
		memtree_rebalance_left(memtree_ptr);
	}
	else if (rheight - lheight > 1)
	{
		memtree_rebalance_right(memtree_ptr);
	}
	memtree_update_height(*memtree_ptr);
}

t_any	memtree_switch(t_memtree_ptr memtree_ptr)
{
	t_memtree	min_root;
	t_any		min_address;

	if ((*memtree_ptr)->ltree == NULL)
	{
		min_root = *memtree_ptr;
		min_address = min_root->address;
		*memtree_ptr = min_root->rtree;
		free(min_root);
	}
	else
	{
		min_address = memtree_switch(&((*memtree_ptr)->ltree));
	}
	memtree_rebalance(memtree_ptr);
	return (min_address);
}

t_none	memtree_remove_current(t_memtree_ptr memtree_ptr, t_any address)
{
	t_memtree	old_root;

	if ((*memtree_ptr)->rtree == NULL)
	{
		old_root = *memtree_ptr;
		*memtree_ptr = (*memtree_ptr)->ltree;
		free(old_root->address);
		free(old_root);
	}
	else
	{
		(*memtree_ptr)->address = memtree_switch(&((*memtree_ptr)->rtree));
		free(address);
	}
}	

t_none	memtree_remove_recursively(t_memtree_ptr memtree_ptr, t_any address)
{
	if (memtree_is_empty(memtree_ptr))
	{
		return ;
	}
	else if (address == memtree_get_address(memtree_ptr))
	{
		memtree_remove_current(memtree_ptr, address);
	}
	else if (address < memtree_get_address(memtree_ptr))
	{
		memtree_remove_recursively(&((*memtree_ptr)->ltree), address);
	}
	else if (address > memtree_get_address(memtree_ptr))
	{
		memtree_remove_recursively(&((*memtree_ptr)->rtree), address);
	}
	memtree_rebalance(memtree_ptr);
}

t_none	memtree_remove(t_mini mini, t_any address)
{
	memtree_remove_recursively(&(mini->shared->memtree), address);
}

t_none	memtree_destroy_recursively(t_memtree memtree)
{
	if (memtree == NULL)
			return ;
	memtree_destroy_recursively(memtree->ltree);
	memtree_destroy_recursively(memtree->rtree);
	free(memtree->address);
	free(memtree);
}

t_none	memtree_destroy(t_mini mini)
{
	t_memtree	memtree;
	
	memtree = mini->shared->memtree;
	memtree_destroy_recursively(memtree);
}

t_none	mini_quit(t_mini mini, t_i32 exit_code)
{
	if (mini == NULL)
	{
		exit(exit_code);
	}
	else
	{
		if (mini->shared == NULL)
		{
			free(mini);
			exit(exit_code);
		}
		else
		{
			memtree_destroy(mini);
			free(mini->shared);
			free(mini);
			exit(exit_code);
		}
	}
}

t_none	memtree_create(t_mini mini, t_memtree_ptr memtree_ptr, t_any address)
{
	*memtree_ptr = malloc(sizeof(struct s_memtree));
	if (*memtree_ptr == NULL)
	{
		print_to_stderr("mini: failed to allocate memory\n");
		mini_quit(mini, MINI_ERROR);
	}
	(*memtree_ptr)->ltree = NULL;
	(*memtree_ptr)->rtree = NULL;
	(*memtree_ptr)->address = address;
	(*memtree_ptr)->height = 1;
}

t_none	memtree_insert_recursively(
	t_mini mini,
	t_memtree_ptr memtree_ptr,
	t_any address
){
	if (memtree_is_empty(memtree_ptr))
	{
		memtree_create(mini, memtree_ptr, address);
	}
	else if (address < memtree_get_address(memtree_ptr))
	{
		memtree_insert_recursively(mini, &((*memtree_ptr)->ltree), address);
		memtree_rebalance(memtree_ptr);
	}
	else if (address > memtree_get_address(memtree_ptr))
	{
		memtree_insert_recursively(mini, &((*memtree_ptr)->rtree), address);
		memtree_rebalance(memtree_ptr);
	}
}

t_none	memtree_insert(t_mini mini, t_any address)
{
	t_memtree_ptr	memtree_ptr;

	memtree_ptr = &(mini->shared->memtree);
	memtree_insert_recursively(mini, memtree_ptr, address);
}

t_any	mini_alloc(t_mini mini, t_i32 size)
{
	t_any	ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		print_to_stderr("mini: failed to allocate memory\n");
		exit(MINI_ERROR);
	}
	memtree_insert(mini, ptr);
	return (ptr);
}

t_none	cstring_to_stdout(t_cstring cstr)
{
	write(STDOUT_FILENO, cstr, ft_strlen(cstr));
}

t_i32	cstring_get_length(t_cstring message)
{
	t_i32	length;

	if (message == NULL)
	{
		return (0);
	}
	length = 0;
	while (message[length])
	{
		length += 1;
	}
	return (length);
}

t_cstring	cstring_join(t_mini mini, t_cstring a, t_cstring b)
{
	const t_u32	a_length = cstring_get_length(a);
	const t_u32	b_length = cstring_get_length(b);
	const t_u32	c_length = a_length + b_length;
	t_cstring	c;
	t_u32		i;

	c = mini_alloc(mini, c_length + 1);
	i = 0;
	while (i < a_length)
	{
		c[i] = a[i];
		i++;
	}
	i = 0;
	while (i < b_length)
	{
		c[a_length + i] = b[i];
		i++;
	}
	c[c_length] = '\0';
	return (c);
}

t_cstring	cstring_copy(t_mini mini, t_cstring original)
{
	const t_u32	original_length = cstring_get_length(original);
	t_u32		i;
	t_cstring	copy;

	copy = mini_alloc(mini, original_length + 1);
	i = 0;
	while (i < original_length)
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

t_cstring	*cstring_array_copy(t_mini mini, t_cstring *arr)
{
	t_i32		len;
	t_cstring	*copy;

	len = 0;
	while (arr[len])
		len++;
	copy = mini_alloc(mini, (sizeof(t_cstring) * (len + 1)));
	copy[len] = '\0';
	while (len--)
	{
		copy[len] = cstring_copy(mini, arr[len]);
	}
	return (copy);
}

t_none	signals_create(t_mini mini)
{
	signal(SIGQUIT, SIG_IGN);
}

t_none	reader_create(t_mini mini)
{
	mini->reader = mini_alloc(mini, sizeof(struct s_reader));
	mini->reader->line = NULL;
	mini->reader->statement = NULL;
	mini->reader->prompt = PROMPT;
	mini->reader->multiline_prompt = MULTILINE_PROMPT;
}

t_none	lexer_create(t_mini mini)
{
	
}

t_none	expansion_create(t_mini mini)
{
	
}

t_none	parser_create(t_mini mini)
{
	
}

t_none	heredoc_create(t_mini mini)
{
	
}

t_none	eval_create(t_mini mini)
{
	
}

t_none	shared_create(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	mini->shared = malloc(sizeof(struct s_shared));
	if (mini->shared == NULL)
	{
		print_to_stderr("mini: failed to allocate memory\n");
		exit(MINI_ERROR);
	}
	mini->shared->argc = argc;
	mini->shared->argv = argv;
	mini->shared->envp = envp;
	mini->shared->memtree = NULL;
	mini->shared->fdtree = NULL;
	mini->shared->env = cstring_array_copy(mini, envp);
	mini->shared->exit_code = 0;
	mini->shared->is_statement_complete = FALSE;
	mini->shared->is_heredoc_complete = TRUE;
}

t_none	create_internal_structures(
	t_mini mini, 
	t_i32 argc, 
	t_i8 **argv, 
	t_i8 **envp
){
	shared_create(mini, argc, argv, envp);
	signals_create(mini);
	reader_create(mini);
	lexer_create(mini);
	expansion_create(mini);
	parser_create(mini);
	heredoc_create(mini);
	eval_create(mini);
}

t_mini	mini_create(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	mini = malloc(sizeof(struct s_mini));
	if (mini == NULL)
	{
		print_to_stderr("mini: failed to allocate memory\n");
		exit(MINI_ERROR);
	}
	create_internal_structures(mini, argc, argv, envp);
	return (mini);
}

t_none	mini_handle_eof(t_mini mini)
{
	if (mini->reader->line == NULL)
	{
		cstring_to_stdout("exit\n");
		mini_quit(mini, mini->shared->exit_code);
	}
}

t_none	reader_update_statement(t_mini mini)
{
	t_reader	reader;

	reader = mini->reader;

	if (mini->reader->line)
	{
		if (reader->statement)
			reader->statement = cstring_join(mini, reader->statement, "\n");
		reader->statement = cstring_join(mini, reader->statement, reader->line);	
	}
}

t_none	mini_readline(t_mini mini)
{
	if (mini->reader->statement == NULL)
	{
		mini->reader->line = readline(mini->reader->prompt);
	}
	else
	{
		mini->reader->line = readline(mini->reader->multiline_prompt);
	}
}

t_bool	mini_is_complete(t_mini mini)
{
	return (!mini->shared->is_statement_complete);
}

t_none	reader_assume_statement_is_complete(t_mini mini)
{
	mini->shared->is_statement_complete = TRUE;
}

t_none	reader_debug(t_mini mini)
{
	printf("\033[94m[%s:%d]\n(statement)\033[0m %s\n", \
	__func__, __LINE__, mini->reader->statement);
}

t_none	mini_read(t_mini mini)
{
	mini_readline(mini);
	mini_handle_eof(mini);
	reader_update_statement(mini);
	reader_assume_statement_is_complete(mini);
	reader_debug(mini);
}

t_i32	main(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	printf("This is MINI! I'm going to finish this!\n");
	mini = mini_create(argc, argv, envp);
	while (42)
	{
		while (mini_is_complete(mini))
		{
			mini_read(mini);
			// mini_tokenize(mini);
			// mini_expand(mini);
			// mini_parse(mini);
		}
		// mini_handle_heredoc(mini);
		// mini_eval(mini);
		// mini_reset(mini);
	}
}
