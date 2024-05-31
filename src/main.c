/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:47:51 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_i32	main(t_i32 argc, t_cstring_array argv)
{
	#ifdef ENABLE_DEBUGGER
		printf("Mini is running in \033[94mDEBUG\033[0m mode.\n");
	#endif
	t_mini	mini;

	mini = mini_create(argc, argv);
	printf("\n[STACK]\n");
	t_i64	value;

	memstack_load_i64(mini, 3812939);
	memstack_load_i32(mini, 218);
	value = memstack_unload_i32(mini);
	printf("\nvalue: %lld\n", value);
	value = memstack_unload_i64(mini);
	printf("\nvalue: %lld\n", value);
	

	// while (42)
	// {
	// 	mini_read(mini);
	// 	mini_evaluate(mini);
	// }
}
