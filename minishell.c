/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 20:03:47 by bhildebr         ###   ########.fr       */
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

t_memtree	memtree_get_ltree(t_memtree_ptr memtree_ptr)
{
	return ((*memtree_ptr)->ltree);
}

t_memtree	memtree_get_rtree(t_memtree_ptr memtree_ptr)
{
	return ((*memtree_ptr)->rtree);
}

t_none	memtree_remove_recursively(t_memtree_ptr memtree_ptr, t_any address)
{
	t_memtree	old_root;

	if (memtree_is_empty(memtree_ptr))
		return ;
	else if (address == memtree_get_address(memtree_ptr))
	{
		if (memtree_get_rtree(memtree_ptr) != NULL)
		{
			// (*memtree_ptr)->address = memtree_remove_update(&())
			free(address);
		}
		else
		{
			old_root = *memtree_ptr;
			*memtree_ptr = (*memtree_ptr)->ltree;
			free(old_root->address);
			free(old_root);
		}
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

t_any	memtree_get_address(t_memtree_ptr memtree_ptr)
{
	return ((*memtree_ptr)->address);
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
	memtree_update_height(memtree_ptr);
}

t_none	memtree_create(t_mini mini, t_memtree_ptr memtree_ptr)
{
	*memtree_ptr = malloc(sizeof(struct s_memtree));
	if (*memtree_ptr == NULL)
	{
		print_to_stderr("mini: failed to allocate memory\n");
		mini_quit(mini, MINI_ERROR);
	}
	(*memtree_ptr)->ltree = NULL;
	(*memtree_ptr)->rtree = NULL;
	(*memtree_ptr)->address = NULL;
	(*memtree_ptr)->height = 1;
}

t_none	memtree_insert_recursively(
	t_mini mini,
	t_memtree_ptr memtree_ptr,
	t_any address
){
	if (memtree_is_empty(memtree_ptr))
	{
		memtree_create(mini, memtree_ptr);
	}
	else if (address < memtree_get_address(memtree_ptr))
	{
		memtree_insert_recursively(memtree_get_ltree(memtree_ptr), address);
		memtree_rebalance(memtree_ptr);
	}
	else if (address > memtree_get_address(memtree_ptr))
	{
		memtree_insert_recursively(memtree_get_rtree(memtree_ptr), address);
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
	shared_create(mini);
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

t_i32	main(t_i32 argc, t_i8 **argv, t_i8 **envp)
{
	t_mini	mini;

	printf("This is MINI! I'm going to finish this!\n");
	mini = mini_create(argc, argv, envp);
	// while (42)
	// {
	// 	while (mini_is_complete(mini))
	// 	{
	// 		mini_read(mini);
	// 		mini_tokenize(mini);
	// 		mini_expand(mini);
	// 		mini_parse(mini);
	// 	}
	// 	mini_handle_heredoc(mini);
	// 	mini_eval(mini);
	// 	mini_reset(mini);
	// }
}
