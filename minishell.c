/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/03 00:42:12 by bhildebr         ###   ########.fr       */
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

t_none	mini_free(t_mini mini, t_any address)
{
	if (address == NULL)
		return ;
	memtree_remove(mini, address);
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

t_cstring	i32_to_cstring(t_mini mini, t_i32 number)
{
	t_i64		number_copy;
	t_i32		length;
	t_cstring	cstring;

	number_copy = (t_i64)number;
	length = 0;
	while (number_copy)
	{
		number_copy /= 10;
		length++;
	}
	cstring = mini_alloc(mini, length + 1);
	cstring[length] = '\0';
	length--;
	number_copy = (t_i64)number;
	while (number_copy)
	{
		cstring[length] = (number_copy % 10) + '0';
		number_copy /= 10;
		length--;
	}
	return (cstring);
}

t_cstring	cstring_get_subcstring(
	t_mini mini,
	t_cstring cstring,
	t_i32 start,
	t_i32 end
){
	t_cstring	subcstring;
	t_i32		length;
	t_i32		i;

	length = end - start + 1;
	subcstring = mini_alloc(mini, length + 1);
	subcstring[length] = '\0';
	i = 0;
	while (i < length)
	{
		subcstring[i] = cstring[start + i];
		i++;
	}
	return (subcstring);
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

t_cstring	cstring_add(
	t_mini mini,
	t_cstring cstring,
	t_i32 start,
	t_cstring value
){
	t_cstring	new_cstring;
	t_i32		new_cstring_len;
	t_i32		value_len;
	t_i32		i;
	t_i32		j;

	value_len = cstring_get_length(value);
	new_cstring_len = cstring_get_length(cstring) + value_len;
	new_cstring = mini_alloc(mini, new_cstring_len + 1);
	new_cstring[new_cstring_len] = '\0';
	i = 0;
	j = 0;
	while (i < new_cstring_len)
	{
		if (i >= start && j < value_len)
		{
			new_cstring[i] = value[j];
			j++;	
		}
		else
		{
			new_cstring[i] = (cstring)[i - j];
		}
		i++;
	}
	return (new_cstring);
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

t_cstring	cstring_remove(
	t_mini mini,
	t_cstring cstring,
	t_i32 start,
	t_i32 end
){
	t_i32			cstring_len;
	t_cstring		new_cstring;
	t_i32			new_cstring_len;
	t_i32			i;
	t_i32			j;

	cstring_len = cstring_get_length(cstring);
	new_cstring_len = cstring_len - (end - start + 1);
	new_cstring = mini_alloc(mini, new_cstring_len + 1);
	new_cstring[new_cstring_len] = '\0';
	i = 0;
	j = 0;
	while (i < cstring_len)
	{
		if (i < start || i > end)
		{
			new_cstring[j] = (cstring)[i];
			j++;
		}
		i++;
	}
	return (new_cstring);
}

t_i32	cstring_compare(t_cstring a, t_cstring b)
{
	t_i32	i;

	i = 0;
	while (a[i] == b[i] && a[i] != '\0')
		i++;
	return (((t_u8)a[i]) - ((t_u8)b[i]));
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

t_none	automaton_table_create2(t_mini mini)
{
	mini->lexer->table[6][0] = 105;
	mini->lexer->table[6][1] = 105;
	mini->lexer->table[6][2] = 105;
	mini->lexer->table[6][3] = 105;
	mini->lexer->table[6][4] = 105;
	mini->lexer->table[6][5] = 105;
	mini->lexer->table[6][6] = 105;
	mini->lexer->table[6][7] = 105;
}

t_none	automaton_table_create1(t_mini mini)
{
	mini->lexer->table[3][0] = 103;
	mini->lexer->table[3][1] = 103;
	mini->lexer->table[3][2] = 104;
	mini->lexer->table[3][3] = 103;
	mini->lexer->table[3][4] = 103;
	mini->lexer->table[3][5] = 103;
	mini->lexer->table[3][6] = 103;
	mini->lexer->table[3][7] = 103;
	mini->lexer->table[4][0] = 4;
	mini->lexer->table[4][1] = 4;
	mini->lexer->table[4][2] = 4;
	mini->lexer->table[4][3] = 1;
	mini->lexer->table[4][4] = 4;
	mini->lexer->table[4][5] = 4;
	mini->lexer->table[4][6] = 4;
	mini->lexer->table[4][7] = 200;
	mini->lexer->table[5][0] = 5;
	mini->lexer->table[5][1] = 5;
	mini->lexer->table[5][2] = 5;
	mini->lexer->table[5][3] = 5;
	mini->lexer->table[5][4] = 1;
	mini->lexer->table[5][5] = 5;
	mini->lexer->table[5][6] = 5;
	mini->lexer->table[5][7] = 200;
	automaton_table_create2(mini);
}

t_none	automaton_table_create0(t_mini mini)
{
	mini->lexer->table[0][0] = 1;
	mini->lexer->table[0][1] = 2;
	mini->lexer->table[0][2] = 3;
	mini->lexer->table[0][3] = 4;
	mini->lexer->table[0][4] = 5;
	mini->lexer->table[0][5] = 6;
	mini->lexer->table[0][6] = 0;
	mini->lexer->table[0][7] = 108;
	mini->lexer->table[1][0] = 1;
	mini->lexer->table[1][1] = 100;
	mini->lexer->table[1][2] = 100;
	mini->lexer->table[1][3] = 4;
	mini->lexer->table[1][4] = 5;
	mini->lexer->table[1][5] = 100;
	mini->lexer->table[1][6] = 100;
	mini->lexer->table[1][7] = 100;
	mini->lexer->table[2][0] = 101;
	mini->lexer->table[2][1] = 102;
	mini->lexer->table[2][2] = 101;
	mini->lexer->table[2][3] = 101;
	mini->lexer->table[2][4] = 101;
	mini->lexer->table[2][5] = 101;
	mini->lexer->table[2][6] = 101;
	mini->lexer->table[2][7] = 101;
	automaton_table_create1(mini);
}

t_none	lexer_create(t_mini mini)
{
	mini->lexer = mini_alloc(mini, sizeof(struct s_lexer));
	mini->lexer->tokens = NULL;
	mini->lexer->cursor = NULL;
	mini->lexer->start = 0;
	mini->lexer->end = 0;
	mini->lexer->state = 0;
	automaton_table_create0(mini);
}

t_none	expansion_create(t_mini mini)
{
	mini->expansion = mini_alloc(mini, sizeof(struct s_expansion));
	mini->expansion->tokens = NULL;
	mini->expansion->is_in_single_quotes = FALSE;
	mini->expansion->is_in_double_quotes = FALSE;
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

t_none	mini_list_append(
	t_mini mini,
	t_mini_list *list,
	t_cstring token,
	t_i32 type
){
	t_mini_list	node;

	if (*list == NULL)
	{
		(*list) = mini_alloc(mini, sizeof(struct s_mini_list));
		(*list)->previous = NULL;
		(*list)->next = NULL;
		(*list)->token = token;
		(*list)->type = type;
	}
	else
	{
		node = (*list);
		while (node->next)
		{
			node = node->next;			
		}
		node->next = mini_alloc(mini, sizeof(struct s_mini_list));
		node->next->previous = node;
		node->next->next = NULL;
		node->next->token = token;
		node->next->type = type;
	}
}

t_i32	automaton_typefy(t_mini mini)
{
	if (mini->lexer->state == 100)
		return (WORD);
	else if (mini->lexer->state == 101)
		return (REDIR_OUT);
	else if (mini->lexer->state == 102)
		return (REDIR_APPEND);
	else if (mini->lexer->state == 103)
		return (REDIR_IN);
	else if (mini->lexer->state == 104)
		return (REDIR_HEREDOC);
	else if (mini->lexer->state == 105)
		return (PIPE);
	else if (mini->lexer->state == 106)
		return (DOUBLE_QUOTES);
	else if (mini->lexer->state == 107)
		return (SINGLE_QUOTES);
	else
	{
		write(STDERR_FILENO, "What the heck?!\n", 17);
		mini_quit(mini, 42);
	}
	return (0);
}

t_bool	should_consider_the_last_character(t_mini mini)
{
	if (mini->lexer->state == 102)
		return (TRUE);
	else if (mini->lexer->state == 104)
		return (TRUE);
	else if (mini->lexer->state == 106)
		return (TRUE);
	else if (mini->lexer->state == 107)
		return (TRUE);
	return (FALSE);
}

t_none	automaton_delimit_with_last_character(t_mini mini)
{
	t_cstring		token;
	t_i32			type;
	t_i32			len;
	t_i32			i;

	len = mini->lexer->end - mini->lexer->start + 1;
	token = mini_alloc(mini, len + 1);
	token[len] = '\0';
	i = 0;
	while (i < len)
	{
		token[i] = mini->lexer->cursor[mini->lexer->start + i];
		i++;
	}
	mini->lexer->end += 1;
	mini->lexer->start = mini->lexer->end;
	type = automaton_typefy(mini);
	mini_list_append(mini, &(mini->lexer->tokens), token, type);
	mini->lexer->state = 0;
}

t_none	automaton_regular_delimit(t_mini mini)
{
	t_cstring		token;
	t_i32			type;
	t_i32			len;
	t_i32			i;

	len = mini->lexer->end - mini->lexer->start;
	token = mini_alloc(mini, len + 1);
	token[len] = '\0';
	i = 0;
	while (i < len)
	{
		token[i] = mini->lexer->cursor[mini->lexer->start + i];
		i++;
	}
	mini->lexer->start = mini->lexer->end;
	type = automaton_typefy(mini);
	mini_list_append(mini, &(mini->lexer->tokens), token, type);
	mini->lexer->state = 0;
}

t_none	automaton_delimit(t_mini mini)
{
	if (mini->lexer->state == 108)
	{
		return ;
	}
	else if (mini->lexer->state == 200)
	{
		mini->shared->is_statement_complete = FALSE;
		return ;
	}
	else if (should_consider_the_last_character(mini))
	{
		automaton_delimit_with_last_character(mini);
	}
	else
	{
		automaton_regular_delimit(mini);
	}
}

t_bool	automaton_is_whitespace(t_mini mini)
{
	if (mini->lexer->state == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	automaton_is_end_of_statement(t_mini mini)
{
	if (mini->lexer->cursor[mini->lexer->start] == '\0')
		return (TRUE);
	return (FALSE);
}

t_bool	automaton_is_final_state(t_mini mini)
{
	if (mini->lexer->state >= 100)
		return (TRUE);
	return (FALSE);
}

t_none	automaton_next_state(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_i8			character;

	character = lexer->cursor[lexer->end];
	if (character == '>')
		lexer->state = lexer->table[lexer->state][1];
	else if (character == '<')
		lexer->state = lexer->table[lexer->state][2];
	else if (character == '"')
		lexer->state = lexer->table[lexer->state][3];
	else if (character == '\'')
		lexer->state = lexer->table[lexer->state][4];
	else if (character == '|')
		lexer->state = lexer->table[lexer->state][5];
	else if (character == ' ' || (character >= '\t' && character <= '\r'))
		lexer->state = lexer->table[lexer->state][6];
	else if (character == '\0')
		lexer->state = lexer->table[lexer->state][7];
	else
		lexer->state = lexer->table[lexer->state][0];
}

t_none	lexer_reset(t_mini mini)
{
	mini->lexer->cursor = NULL;
	mini->lexer->end = 0;
	mini->lexer->start = 0;
	mini->lexer->state = 0;
	if (mini->lexer->tokens)
		mini_list_clear(mini, &mini->lexer->tokens);
	mini->lexer->tokens = NULL;
}

t_none	mini_automaton(t_mini mini)
{
	lexer_reset(mini);
	mini->lexer->cursor = mini->reader->statement;
	while (42)
	{
		automaton_next_state(mini);
		if (automaton_is_final_state(mini))
		{
			automaton_delimit(mini);
			if (automaton_is_end_of_statement(mini))
				break ;	
		}
		else
		{
			mini->lexer->end++;
			if (automaton_is_whitespace(mini))
				mini->lexer->start++;
		}
	}
}

t_none	mini_list_print(t_mini mini)
{
	t_mini_list	list;

	list = mini->lexer->tokens;
	while (list)
	{
		printf("%s", list->token);
		if (list->next)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}

t_none	lexer_debug(t_mini mini)
{
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	mini_list_print(mini);
}

t_none	mini_tokenize(t_mini mini)
{
	mini_automaton(mini);
	lexer_debug(mini);
}

t_none	expansion_remove_quotes2(t_mini mini, t_mini_list node, t_i32 i)
{
	t_bool		is_in_double_quotes;
	t_cstring	dup;
	
	is_in_double_quotes = mini->expansion->is_in_double_quotes;
	if (!mini->expansion->is_in_single_quotes ||
		mini->expansion->is_in_double_quotes)
	{
		mini->expansion->is_in_double_quotes = !is_in_double_quotes;
		dup = node->token;
		node->token = cstring_remove(mini, node->token, i, i);
		mini_free(mini, dup);
	}
}

t_none	expansion_remove_quotes1(t_mini mini, t_mini_list node, t_i32 i)
{
	t_bool		is_in_single_quotes;
	t_cstring	dup;
	
	is_in_single_quotes = mini->expansion->is_in_single_quotes;
	if (mini->expansion->is_in_single_quotes ||
		!mini->expansion->is_in_double_quotes)
	{
		mini->expansion->is_in_single_quotes = !is_in_single_quotes;
		dup = node->token;
		node->token = cstring_remove(mini, node->token, i, i);
		mini_free(mini, dup);
	}
}

t_none	expansion_remove_quotes(t_mini mini)
{
	t_mini_list	node;
	t_i32		i;

	node = mini->lexer->tokens;
	while (node)
	{
		if (node->type == WORD)
		{
			i = 0;
			while (node->token[i])
			{
				if (node->token[i] == '\'')
				{
					expansion_remove_quotes1(mini, node, i);
				}
				if (node->token[i] == '"')
				{
					expansion_remove_quotes2(mini, node, i);
				}
				i++;
			}
		}
		node = node->next;
	}
}

t_cstring	get_env_key(t_mini mini, t_cstring env)
{
	t_i32	i;

	i = 0;
	while (env[i] != '=')
		i++;
	return (cstring_get_subcstring(mini, env, 0, i - 1));
}

t_cstring	get_env_value(t_mini mini, t_cstring env)
{
	t_i32	i;
	t_i32	j;

	i = 0;
	while (env[i] != '=')
		i++;
	j = i + 1;
	while (env[j])
		j++;
	return (cstring_get_subcstring(mini, env, i + 1, j - 1));
}

t_cstring	expansion_getenv(t_mini mini, t_cstring key)
{
	t_cstring	current_key;
	t_cstring	value;
	t_i32		i;

	i = 0;
	value = NULL;
	while (mini->shared->env[i])
	{
		current_key = get_env_key(mini, mini->shared->env[i]);
		if (cstring_compare(key, current_key) == 0)
			value = get_env_value(mini, mini->shared->env[i]);
		mini_free(mini, current_key);
		i++;
	}
	return (value);
}

t_i32	expansion_expand(t_mini mini, t_mini_list node, t_i32 start, t_i32 end)
{
	t_cstring	key;
	t_cstring	value;
	t_i32		value_length;
	t_cstring	new_token;

	if (start == end)
		return (start);
	else if (start == end - 1 && node->token[end] == '?')
		value = i32_to_cstring(mini, mini->shared->exit_code);
	else
	{
		key = cstring_get_subcstring(mini, node->token, start + 1, end);
		value = cstring_copy(mini, expansion_getenv(mini, key));
	}
	value_length = cstring_get_length(value);
	new_token = cstring_remove(mini, node->token, start, end);
	new_token = cstring_add(mini, new_token, start, value);
	mini_free(mini, node->token);
	node->token = new_token;
	mini_free(mini, key);
	mini_free(mini, value);
	return (start + value_length);
}

t_i32	expansion_find_end(t_cstring token, t_i32 start)
{
	t_i32	i;

	i = start;
	while (token[i])
	{
		if (token[i] == '>')
			return (i - 1);
		else if (token[i] == '<')
			return (i - 1);
		else if (token[i] == '"')
			return (i - 1);
		else if (token[i] == '\'')
			return (i - 1);
		else if (token[i] == '|')
			return (i - 1);
		else if (token[i] == ' ' || (token[i] >= '\t' && token[i] <= '\r'))
			return (i - 1);
		else if (token[i] == '\0')
			return (i - 1);
		else
			i++;
	}
	return (i - 1);
}

t_none	expand_debug(t_mini mini)
{
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	mini_list_print(mini);
}

t_none	mini_expand(t_mini mini)
{
	t_mini_list	node;
	t_i32		start;
	t_i32		end;
	
	node = mini->lexer->tokens;
	while (node)
	{
		if (node->type == WORD)
		{
			start = 0;
			while (node->token[start])
			{
				if (node->token[start] == '$')
				{
					end = expansion_find_end(node->token, start);
					start = expansion_expand(mini, node, start, end);
				}
				start++;
			}
		}
		node = node->next;
	}
	expansion_remove_quotes(mini);
	expand_debug(mini);
}

t_none	parser_print_syntax_error(t_mini mini)
{
	cstring_to_stderr("mini: syntax error near unexpected token '");
	cstring_to_stderr(mini->parser->unexpected_token);
	cstring_to_stderr("'\n");
}

t_i32	parser_get_token(t_mini mini)
{
	if (mini->parser->cursor)
		return (mini->parser->cursor->type);
	return (END);
}

t_none	parser_reset(t_mini mini)
{
	if (mini->parser->tree)
	{
		mini_pipe_tree_destroy(mini, mini->parser->tree);
	}
	mini->parser->tree = NULL;
	mini->parser->cursor = mini->lexer->tokens;
	mini->parser->found_heredoc = FALSE;
	mini->parser->could_be_completed = FALSE;
	if (mini->lexer->tokens)
		mini->parser->unexpected_token = mini->lexer->tokens->token;
	else
		mini->parser->unexpected_token = NULL;
}

t_none	mini_reset(t_mini mini)
{
	reader_reset(mini);
	lexer_reset(mini);
	expansion_reset(mini);
	parser_reset(mini);
	heredoc_reset(mini);
	eval_reset(mini);
	mini->shared->is_statement_complete = FALSE;
}

t_none	parser_debug(t_mini mini)
{
	printf("\033[94m[%s:%d]\n(command)\033[0m ", __func__, __LINE__);
	mini_pipe_tree_print(mini, mini->parser->tree);
}

t_none	mini_parse(t_mini mini)
{
	parser_reset(mini);
	if (parser_get_token(mini) == END)
		mini->parser->tree = NULL;
	else
	{
		mini->parser->tree = parse_pipe_sequence(mini);
		if (mini->parser->tree)
		{
			if (mini->parser->found_heredoc)
			{
				if (mini->shared->is_statement_complete == TRUE)
					mini->shared->is_heredoc_complete = FALSE;
			}
		}
		else if (mini->parser->could_be_completed)
			mini->shared->is_statement_complete = FALSE;
		else
		{
			parser_print_syntax_error(mini);
			mini_reset(mini);
		}
	}
	parser_debug(mini);
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
			mini_tokenize(mini);
			mini_expand(mini);
			mini_parse(mini);
		}
		// mini_handle_heredoc(mini);
		// mini_eval(mini);
		// mini_reset(mini);
	}
}
