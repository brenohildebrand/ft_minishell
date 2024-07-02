/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:48:36 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/19 20:25:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>

// Studying Dups
// int	main(void)
// {
// 	const char *path = "/tmp/narnia";
// 	int			fd;
// 	int			stdout_ref;
// 	int			pid;

// 	stdout_ref = dup(STDOUT_FILENO);
// 	printf("opening...\n");
// 	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (dup2(fd, STDOUT_FILENO) == -1)
// 	{
// 		exit(1);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		exit(1);
// 	}
// 	else if (pid == 0)
// 	{
// 		dprintf(STDOUT_FILENO, "to em narnia\n");
// 		if (dup2(stdout_ref, STDOUT_FILENO) == -1)
// 		{
// 			exit(1);
// 		}
// 		printf("closing...\n");
// 		close(fd);
// 	}
// 	else
// 	{
			
// 	}
// }

static void	do_some_long_process(void)
{
	sleep(30);
}

// Breaking open and close
int	main(void)
{
	int	fd;
	
	fd = open("/tmp/oh_my_bug", O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
	{
		printf("can't open\n");
		exit(1);
	}
	do_some_long_process();
	if (close(fd) == -1)
	{
		printf("can't :(\n");
		exit (1);
	}
	exit(0);
}
